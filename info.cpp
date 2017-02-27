#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <stdint.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#include <mach-o/dyld.h>
#include <string>
#include <set>
using std::set;

#include "info.h"
#include "Debug.h"
#include "xpruntime.h"

using std::string;

static bool filter_string(const char * info, const char * kwds)
{
	string onel;

	const char * p1, * p2, *p3;
	for (p1=kwds,p2=kwds; ; ++p1)
	{
		if (*p1=='\n' || *p1 == 0)
		{
			// [p2, p1)
			while (p2<p1 && isspace(*p2)) ++p2;
			if (p2 < p1)
			{
				for (p3=p1; p3>p2 && isspace(p3[-1]); --p3);
				if (p2 < p3)
				{
					onel.assign(p2, p3-p2);
					printf("%s\n", onel.c_str());
					if (strstr(info, onel.c_str())) return true;
				}
			}
			if (*p1==0) break;
			p2 = p1+1;
		}
	}

	return false;
}

int need_skip(const char * grpname, const char * kwds)
{
	return filter_string(grpname, kwds);
}

int dont_open(const char * content, const char * kwds)
{
	// <sendertitle><![CDATA[一切都是这样吧]]></sendertitle>
	const char * head = "<sendertitle><![CDATA[";
	const char * tail = "]]></sendertitle>";

	const char * ptr = strstr(content, head);
	if (ptr) ptr += strlen(head);
	if (ptr)
	{
		const char * ptre = strstr(ptr, tail);
		if (ptre)
		{
			string sc(ptr, ptre - ptr);
			return filter_string(sc.c_str(), kwds);
		}
	}
	return 0;
}

class CRecentQueue
{
	enum {TIMEOUT=60000};
	struct RQV{
		string skey;
		void * obj;
		int64_t tick;
		int64_t seq;
		RQV(const char * key):skey(key){}
	};
	struct order_by_key
	{
		bool operator ()(const RQV* a, const RQV*b)
		{
			return a->skey < b->skey;
		}
	};
	struct order_by_id
	{
		bool operator ()(const RQV* a, const RQV*b)
		{
			return a->seq < b->seq;
		}
	};
	set<RQV*, order_by_key> bkey;
	set<RQV*, order_by_id> bid;
	long m_seqidx;
protected:
	RQV* _find(set<RQV*, order_by_key> & which, const char * key)
	{
		RQV val(key);
		auto it = which.find(&val);
		return (it == which.end()) ? 0 : *it;
	}
	void clear_to()
	{
		int64_t tick = GetTickCount64b();
		for (auto it = bid.begin(); it != bid.end(); )
		{
			RQV * w = *it;
			if (w->tick + TIMEOUT < tick)
			{
				bkey.erase(w);
				it = bid.erase(it);
			}
			else
				break;
		}
	}

public:
	CRecentQueue()
	{
	}
	~CRecentQueue(){}
public:
	void get(const char * key, void ** v)
	{
		clear_to();
		RQV * r1 = _find(bkey, key);
		*v = r1 ? r1->obj : 0;
	}
	void set(const char * key, void * v)
	{
		clear_to();
		RQV * r1 = _find(bkey, key);
		if (r1)
		{
			if (v)
			{
				bid.erase(r1);
				r1->obj = v;
				r1->seq = ++m_seqidx;
				r1->tick = GetTickCount64b();
				bid.insert(r1);
			}
			else
			{
				bid.erase(r1);
				bkey.erase(r1);
				delete r1;
			}
		}
		else if (v)
		{
			//new add.
			RQV * prqv = new RQV(key);
			prqv->obj = v;
			prqv->seq = ++m_seqidx;
			prqv->tick = GetTickCount64b();
			bid.insert(prqv);
			bkey.insert(prqv);
		}
	}
};

void * rq_create()
{
	return new CRecentQueue();
}

void rq_set(void * rq, const char * key, void * obj)
{
	CRecentQueue * rq_ = (CRecentQueue*)rq;
	return rq_->set(key, obj);
}

void rq_get(void * rq, const char * key, void ** pobj)
{
	CRecentQueue * rq_ = (CRecentQueue*)rq;
	return rq_->get(key, pobj);
}

void rq_delete(void * rq)
{
	CRecentQueue * rq_ = (CRecentQueue*)rq;
	delete rq_;
}

static unsigned char hexval(char ch1)
{
	if (ch1>='a'&&ch1<='f') return ch1-'a'+10;
	if (ch1>='A'&&ch1<='F') return ch1-'A'+10;
	if (ch1>='0'&&ch1<='9') return ch1-'0';
	return 0xff;
}
static unsigned char hexchr(char ch1, char ch2)
{
	ch1 = hexval(ch1);
	ch2 = hexval(ch2);
	if (ch1=='\xff'||ch2=='\xff')
		return 0;
	return (ch1<<4)+ch2;
}
string decode_uri(const char * data, size_t dtlen)
{
	string od;
	if (dtlen == (size_t)-1) dtlen = strlen(data);
	od.reserve(dtlen);
	for (size_t i=0; i<dtlen; ++i)
	{
		char ch = data[i];
		if (ch == '%')
		{
			if (i+2<dtlen)
			{
				od += hexchr(data[i+1], data[i+2]);
				i+=2;
			}
			else
				return od;
		}
		else
			od += ch;
	}
	return od;
}

string req_find(const char * bytes, size_t len, const char * key0)
{
	const char * p = bytes, *ps=p, *peq=0;
	const char * pe = bytes+len;

	for (;p<=pe;++p)
	{
		if (p==pe || *p=='&')
		{
			if (peq)
			{
				string key = decode_uri(ps, peq-ps);
				string val = decode_uri(peq+1, p-peq-1);
				if (key==key0) return val;
			}
			ps = p+1;
			peq = 0;
		}
		else if (*p=='?')
		{
			ps = p+1;
			peq = 0;
		}
		else if (*p=='=' && !peq)
		{
			peq = p;
		}
	}
	return "";
}
