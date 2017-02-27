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
	set<RQV*> bkey, bid;
	long m_seqidx;
protected:
	RQV* _find(set<RQV*> & which, const char * key)
	{
		RQV val(key);
		auto it = which.find(&val);
		return (it == which.end()) ? 0 : *it;
	}
	void clear_to()
	{
		int32_t tick = GetTickCount64b();
		for (auto it = bid.begin(); it != bid.end(); )
		{
			RQV * w = *it;
			if (w->tick + TIMEOUT < tick)
			{
				bkey.erase(w);
				it = bid.erase(it++);
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
