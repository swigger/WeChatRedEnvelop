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
	char buf[3000] = {0};
	va_list vg;
	size_t len = sizeof(buf)-1;

	time_t t = time(0);
	struct tm ttt = * localtime(&t);
	int np = sprintf(buf, "[%02d:%02d:%02d] ", ttt.tm_hour, ttt.tm_min, ttt.tm_sec);

	va_start(vg, fmt);
	vsnprintf(buf+np, len-np, fmt, vg);
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

int soundAlert()
{
	static SystemSoundID sndid = 0;
	if (sndid == 0)
	{
		NSString * sndPath = [[NSBundle mainBundle] pathForResource:@"hongbao" ofType:@"mp3"];
		if (!sndPath) return -1;
		NSURL *pewPewURL = [NSURL fileURLWithPath:sndPath];
		OSStatus st = AudioServicesCreateSystemSoundID((__bridge CFURLRef)pewPewURL, &sndid);
		(void)st;
	}
	if (sndid)
		return AudioServicesPlaySystemSound(sndid), 0;
	return -2;
}

void uncaughtExceptionHandler(NSException *exception)
{
	NSLog(@"CRASH: %@", exception);
	NSLog(@"Stack Trace: %@", [exception callStackSymbols]);
}

void testall()
{
	static int w = 0;
	if (w == 0)
	{
		w = 1;
		const char * fn = "/var/hehe.out";
		int fid = open(fn, O_WRONLY|O_CREAT|O_TRUNC);
		sl_printf("open: %s: %d %s\n", fn, fid, strerror(errno));
		dup2(fid, 1);
		dup2(fid, 2);
		sl_printf("write: %d\n", write(fid, "hello\n", 6 ));
		NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
	}
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

