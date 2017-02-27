#import "WeChatRedEnvelop.h"
#import "Debug.h"
#import "info.h"
#include <sys/stat.h>
#include <string>

#define PL_PATH "/private/var/mobile/Library/Preferences/com.tencent.wcreopt.plist"


static void * oc_rq = 0;

static void ocrq_set(NSString* skey, NSObject* svalue)
{
	CFTypeRef cobj = (__bridge CFTypeRef)svalue;
	if (cobj) CFRetain(cobj);
	if (!oc_rq) oc_rq = rq_create();
	rq_set(oc_rq, [skey UTF8String], (void*)cobj);
}

static Boolean ocrq_get(NSString* skey, NSObject** svalue)
{
	void * cobj = 0;
	if (!skey || !svalue || !oc_rq) return FALSE;
	rq_get(oc_rq, [skey UTF8String], &cobj);
	if (!cobj) return FALSE;
	*svalue = (__bridge NSObject*)cobj;
	return TRUE;
}

NSMutableDictionary * loadSettings()
{
	static int64_t timeid = -1;
	static NSMutableDictionary * oldinfo;
	struct stat st = {0};
	stat(PL_PATH, &st);

	if (timeid != st.st_mtimespec.tv_sec || oldinfo == 0)
	{
		NSMutableDictionary * dic = [[NSMutableDictionary alloc]initWithContentsOfFile:@PL_PATH];
		oldinfo = dic;
		timeid = st.st_mtimespec.tv_sec;
		return dic;
	}
	return oldinfo;
}


%hook WCRedEnvelopesLogicMgr
- (void)OnWCToHongbaoCommonResponse:(HongBaoRes *)arg1 Request:(HongBaoReq *)arg2
{
	%orig;

	// 非参数查询请求
	if (arg1.cgiCmdid != 3) return;

	NSString *string = [[NSString alloc] initWithData:arg1.retText.buffer encoding:NSUTF8StringEncoding];
	NSDictionary *dictionary = [string JSONDictionary];

	// 自己已经抢过
	if ([dictionary[@"receiveStatus"] integerValue] == 2)
		return;

	// 红包被抢完
	if ([dictionary[@"hbStatus"] integerValue] == 4)
		return;

	// 没有这个字段会被判定为使用外挂
	if (!dictionary[@"timingIdentifier"])
		return;

	NSString * xxkey;
	{
		NSData * dreq = [[arg2 reqText] buffer];
		std::string s = req_find((char*)[dreq bytes], [dreq length], "nativeUrl");
		std::string t = req_find(s.data(), s.length(), "sendid");
		xxkey = [NSString stringWithUTF8String:t.c_str()];
		sl_printf("==> xxkey is %s\n", t.c_str()); 
	}

	NSMutableDictionary * par_open = 0;
	ocrq_get(xxkey, &par_open);
	ocrq_set(xxkey, 0);
	if (par_open)
	{
		sl_printf("真的打开红包了\n");
		par_open[@"timingIdentifier"] = dictionary[@"timingIdentifier"];
		WCRedEnvelopesLogicMgr *logicMgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:[objc_getClass("WCRedEnvelopesLogicMgr") class]];
		[logicMgr OpenRedEnvelopesRequest:par_open];
	}
	else
	{
		sl_printf("未取到近期参数\n");
	}
}
%end

%hook CMessageMgr
- (void)AsyncOnAddMsg:(NSString *)msg MsgWrap:(CMessageWrap *)wrap {
	%orig;

	static char ssig[300];
	ssig[0] = 0;
	int msgType = wrap.m_uiMessageType;

	MMServiceCenter * center = (MMServiceCenter*)[objc_getClass("MMServiceCenter") defaultCenter];
	CContactMgr *contactManager = [center getService:[objc_getClass("CContactMgr") class]];
	CContact *selfContact = [contactManager getSelfContact];

	if (msgType != 49) return;

	if ([wrap.m_nsFromUsr isEqualToString:selfContact.m_nsUsrName]) {
		// 自己发的红包，就不需要机器人来抢了吧？？
		return;
	}
	if ([wrap.m_nsContent rangeOfString:@"wxpay://"].location == NSNotFound)
		return; //不是红包？？
	if ([wrap.m_nsFromUsr rangeOfString:@"@chatroom"].location == NSNotFound)
		return; //只抢群里的红包

	NSDictionary * ss =  loadSettings();
	NSObject * en = [ss objectForKey:@"enabled"];
	if (en && [(NSNumber*)en intValue] == 0)
	{
		sl_printf("设置了不抢红包\n");
		soundAlert();
		return;
	}

	{
		NSString * ctname = nil;
		NSString * sndername = nil;
		// 特定的群不抢。
		CContact * ct1= [contactManager getContactByName:wrap.m_nsRealChatUsr];
		if (ct1) sndername = [ct1 getContactDisplayName];
		CContact * ct = [contactManager getContactByName:wrap.m_nsFromUsr];
		if (ct) ctname = [ct getContactDisplayName];
		if (ctname || sndername)
		{
			snprintf(ssig, sizeof(ssig), "[%s/%s]", ctname ? [ctname UTF8String] : "",
											  sndername ? [sndername UTF8String] : "");
		}

		NSString * gnkwds = (NSString*)[ss objectForKey:@"groupname_kwds"];
		if (!gnkwds)gnkwds = @"";
		NSString * desckwds = (NSString*)[ss objectForKey:@"desc_kwds"];
		if (!desckwds)desckwds = @"专\n外挂";

		if (ctname)
		{
			if (need_skip([ctname UTF8String], [gnkwds UTF8String]))
			{
				sl_printf("%s 此群不抢了\n", ssig);
				soundAlert();
				return;
			}
		}
		// 特定的文字不抢。
		if (dont_open([wrap.m_nsContent UTF8String], [desckwds UTF8String]))
		{
			sl_printf("%s 此红包不抢了\n", ssig);
			soundAlert();
			return;
		}
	}

	float delayTime =  0.0;
	{
		//计算时间
		NSNumber * mindelay = [ss objectForKey:@"mindelay"];
		uint32_t a = mindelay ? [mindelay intValue] : 1;
		NSNumber * maxdelay = [ss objectForKey:@"maxdelay"];
		uint32_t b = maxdelay ? [maxdelay intValue] : 1;
		if (b<a)b=a;
		delayTime = arc4random_uniform(b-a+1)+a;
		if (a==b) delayTime = a;

		sl_printf("延时信息 [%d, %d]=>%f", a, b, delayTime);
	}

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayTime * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
		NSString *nativeUrl = [[wrap m_oWCPayInfoItem] m_c2cNativeUrl];
		std::string msgtype = req_find([nativeUrl UTF8String], -1, "msgtype");
		std::string sendid = req_find([nativeUrl UTF8String], -1, "sendid");
		std::string chanid = req_find([nativeUrl UTF8String], -1, "channelid");

		WCRedEnvelopesLogicMgr *logicMgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:[objc_getClass("WCRedEnvelopesLogicMgr") class]];
		sl_printf("%s 打开红包！延时%lf秒", ssig, (double) delayTime);

		CContactMgr *contactManager = [[objc_getClass("MMServiceCenter") defaultCenter] getService:[objc_getClass("CContactMgr") class]];
		CContact *selfContact = [contactManager getSelfContact];
		NSMutableDictionary *par_open = [[NSMutableDictionary alloc] init];
		par_open[@"msgType"] = [NSString stringWithUTF8String:msgtype.c_str()];
		par_open[@"sendId"] = [NSString stringWithUTF8String:sendid.c_str()];
		par_open[@"channelId"] = [NSString stringWithUTF8String:chanid.c_str()];
		par_open[@"nickName"] = [selfContact getContactDisplayName] ?: @"小锅";
		par_open[@"headImg"] = [selfContact m_nsHeadImgUrl] ?: @"";
		par_open[@"nativeUrl"] = [[wrap m_oWCPayInfoItem] m_c2cNativeUrl] ?: @"";
		par_open[@"sessionUserName"] = wrap.m_nsFromUsr ?: @"";

		NSString* xxkey = [NSString stringWithUTF8String:sendid.c_str()];
		sl_printf("setting xxkey is %s\n", [xxkey UTF8String]); 
		ocrq_set(xxkey, par_open);

		NSMutableDictionary *params = [[NSMutableDictionary alloc]init];
		params[@"agreeDuty"] = @"0";
		params[@"channelId"] = [NSString stringWithUTF8String:chanid.c_str()];
		params[@"inWay"] = @"0";
		params[@"msgType"] = [NSString stringWithUTF8String:msgtype.c_str()];
		params[@"nativeUrl"] = [[wrap m_oWCPayInfoItem] m_c2cNativeUrl] ?: @"";
		params[@"sendId"] = [NSString stringWithUTF8String:sendid.c_str()];
		[logicMgr ReceiverQueryRedEnvelopesRequest:params];
    });
}
%end


//" vim: filetype=logos
