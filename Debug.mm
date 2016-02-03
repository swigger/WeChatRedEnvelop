#include <objc/runtime.h>
#include <sys/socket.h>
#include <netinet/in.h>

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#include "Debug.h"

void send_log(const char * msg, int len)
{
	struct sockaddr_in si;
	memset(&si, 0, sizeof(si));
	si.sin_family = AF_INET;
	si.sin_addr.s_addr = 0x0100007f;
	si.sin_port = htons(5555);
	static int udps = -1;
	if (udps<0)
		udps = socket(AF_INET, SOCK_DGRAM, 0);
	if (len < 0) len = (int)strlen(msg);
	sendto(udps, msg, len, 0, (struct sockaddr *) &si, sizeof(si));
}

void send_multi_log(const char * p)
{
	const char * p1 = p;
	for (;;)
	{
		if (*p1 == 0 || *p1=='\n')
		{
			if (p1 > p)
				send_log(p, int(p1-p) );
			p = p1 + 1;
		}
		if (*p1 == 0) break;
		++ p1;
	}
}

void sl_printf(const char * fmt, ...)
{
	char buf[1000] = {0};
	va_list vg;
	va_start(vg, fmt);
	vsnprintf(buf, sizeof(buf)-1, fmt, vg);
	va_end(vg);
	send_log(buf);
}


void dump(const char * name, NSString * s)
{
	char msg[1000];
	if (!s)
		sprintf(msg, "%s is <nil>\n", name);
	else
		snprintf(msg, sizeof(msg)-2, "%s=%s\n", name, [s UTF8String]);
	send_log(msg);
}

void dumpi(const char * name, uint64_t code)
{
	char msg[1000];
	sprintf(msg, "%s is int:%llx\n", name, code);
	send_log(msg);
}

void soundAlert()
{
	static SystemSoundID sndid = 0;
	if (sndid == 0)
	{
		NSString * sndPath = [[NSBundle mainBundle] pathForResource:@"hongbao" ofType:@"mp3"];
		NSURL *pewPewURL = [NSURL fileURLWithPath:sndPath];
		OSStatus st = AudioServicesCreateSystemSoundID((__bridge CFURLRef)pewPewURL, &sndid);
		(void)st;
	}
	AudioServicesPlaySystemSound(sndid);
}


void dumpClassInfo(id object)
{
	Class clazz = [object class];
	u_int count;
	
	Ivar* ivars = class_copyIvarList(clazz, &count);
	NSMutableArray* ivarArray = [NSMutableArray arrayWithCapacity:count];
	for (int i = 0; i < count ; i++)
	{
		const char* ivarName = ivar_getName(ivars[i]);
		[ivarArray addObject:[NSString stringWithCString:ivarName encoding:NSUTF8StringEncoding]];
	}
	free(ivars);
	
	objc_property_t* properties = class_copyPropertyList(clazz, &count);
	NSMutableArray* propertyArray = [NSMutableArray arrayWithCapacity:count];
	for (int i = 0; i < count ; i++)
	{
		const char* propertyName = property_getName(properties[i]);
		[propertyArray addObject:[NSString  stringWithCString:propertyName encoding:NSUTF8StringEncoding]];
	}
	free(properties);
	
	Method* methods = class_copyMethodList(clazz, &count);
	NSMutableArray* methodArray = [NSMutableArray arrayWithCapacity:count];
	for (int i = 0; i < count ; i++)
	{
		SEL selector = method_getName(methods[i]);
		const char* methodName = sel_getName(selector);
		[methodArray addObject:[NSString  stringWithCString:methodName encoding:NSUTF8StringEncoding]];
	}
	free(methods);
	
	NSDictionary* classDump = [NSDictionary dictionaryWithObjectsAndKeys:
							   ivarArray, @"ivars",
							   propertyArray, @"properties",
							   methodArray, @"methods",
							   nil];
	
	const char * p = [[NSString stringWithFormat:@"%@", classDump] UTF8String];
	send_multi_log(p);
}

void dump_unknown(id obj)
{
	NSString * clsname = NSStringFromClass([obj class]);
	dump("obj.class", clsname);
	dumpClassInfo(obj);
}

