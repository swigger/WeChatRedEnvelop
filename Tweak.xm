#import "WeChatRedEnvelop.h"
#import "Debug.h"
#import "info.h"
#include <sys/stat.h>

#define PL_PATH "/private/var/mobile/Library/Preferences/com.tencent.wcreopt.plist"

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
	BOOL isMesasgeFromMe = NO;
	if ([wrap.m_nsFromUsr isEqualToString:selfContact.m_nsUsrName]) {
		isMesasgeFromMe = YES;
	}
	if (isMesasgeFromMe)
	{
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
		nativeUrl = [nativeUrl substringFromIndex:[@"wxpay://c2cbizmessagehandler/hongbao/receivehongbao?" length]];
		NSDictionary *nativeUrlDict = [%c(WCBizUtil) dictionaryWithDecodedComponets:nativeUrl separator:@"&"];

		/** 构造参数 */
		NSMutableDictionary *params = [@{} mutableCopy];
		params[@"msgType"] = nativeUrlDict[@"msgtype"] ?: @"1";
		params[@"sendId"] = nativeUrlDict[@"sendid"] ?: @"";
		params[@"channelId"] = nativeUrlDict[@"channelid"] ?: @"1";
		params[@"nickName"] = [selfContact getContactDisplayName] ?: @"小锅";
		params[@"headImg"] = [selfContact m_nsHeadImgUrl] ?: @"";
		params[@"nativeUrl"] = [[wrap m_oWCPayInfoItem] m_c2cNativeUrl] ?: @"";
		params[@"sessionUserName"] = wrap.m_nsFromUsr ?: @"";

		MMServiceCenter * center = (MMServiceCenter*)[objc_getClass("MMServiceCenter") defaultCenter];
		WCRedEnvelopesLogicMgr *logicMgr = [center getService:[objc_getClass("WCRedEnvelopesLogicMgr") class]];
		sl_printf("%s 打开红包！！延时%lf秒", ssig, (double) delayTime);
		[logicMgr OpenRedEnvelopesRequest:params];
    });
}
%end


//" vim: filetype=logos
