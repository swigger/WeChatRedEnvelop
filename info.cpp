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

int any_line_in_name(const char * fn, const char * thename)
{
	string name = _dyld_get_image_name(0);
	name.resize(name.rfind('/')+1);
	name += fn;

	FILE * fp = fopen(name.c_str(), "rb");
	if (!fp)
	{
		sl_printf("WARNING: cant open %s\n", name.c_str());
		return -1;
	}

	int r = 0;
	
	char line1[512];
	for (;;)
	{
		size_t sz = 0;
		char * line = fgetln(fp, &sz);
		if (!line) break;
		
		if (sz > 500) sz = 500;
		while (sz && isspace(*line))
			line ++;
		if (sz == 0) continue;
		if (*line == '#') continue;
		while (sz && isspace(line[sz-1]))
			-- sz;
		if (sz == 0) continue;
		
		memcpy(line1, line, sz);
		line1[sz] = 0;
		send_log(line1);
		if (strstr(thename, line1))
		{
			r = 1;
			break;
		}
	}
	fclose(fp);
	return r;
}

int need_skip(const char * grpname)
{
	return any_line_in_name("group.skip.txt", grpname) == 0 ? 0 : 1;
}

int dont_open(const char * content)
{
	//<sendertitle><![CDATA[一切都是这样吧]]></sendertitle>
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
			int f = any_line_in_name("hb.keyword.txt", sc.c_str());
			if (f>=0)
			{
				sl_printf("%s fail not open\n", sc.c_str());
				return f;
			}
			const char * kws[] = {"卧底", "潜水", "机器人", "外挂", "开挂",
				"自动抢", "专属", "美女", 0};
			for (int i=0; kws[i]; ++i)
			{
				if (strstr(sc.c_str(), kws[i]))
					return 1;
			}
			return 0;
		}
	}
	return 0;
}
