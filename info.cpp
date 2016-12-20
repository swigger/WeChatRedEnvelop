#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <stdint.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#include <mach-o/dyld.h>
#include <string>

#include "info.h"
#include "Debug.h"

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
