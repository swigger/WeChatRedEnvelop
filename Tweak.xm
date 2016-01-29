#import "WeChatRedEnvelop.h"

%hook CMessageMgr
- (void)AsyncOnAddMsg:(NSString *)msg MsgWrap:(CMessageWrap *)wrap {
	%orig;
	
	switch(wrap.m_uiMessageType) {
	case 49: { // AppNode

		CContactMgr *contactManager = [[objc_getClass("MMServiceCenter") defaultCenter] getService:[objc_getClass("CContactMgr") class]];
		CContact *selfContact = [contactManager getSelfContact];

		BOOL isMesasgeFromMe = NO;
		if ([wrap.m_nsFromUsr isEqualToString:selfContact.m_nsUsrName]) {
			isMesasgeFromMe = YES;
		}

		if ([wrap.m_nsContent rangeOfString:@"wxpay://"].location != NSNotFound) { // 红包
			if ([wrap.m_nsFromUsr rangeOfString:@"@chatroom"].location != NSNotFound ||
				(isMesasgeFromMe && [wrap.m_nsToUsr rangeOfString:@"@chatroom"].location != NSNotFound)) { // 群组红包或群组里自己发的红包

				NSString *nativeUrl = [[wrap m_oWCPayInfoItem] m_c2cNativeUrl];
				nativeUrl = [nativeUrl substringFromIndex:[@"wxpay://c2cbizmessagehandler/hongbao/receivehongbao?" length]];

				NSDictionary *nativeUrlDict = [%c(WCBizUtil) dictionaryWithDecodedComponets:nativeUrl separator:@"&"];

				/** 构造参数 */
				NSMutableDictionary *params = [@{} mutableCopy];
				[params safeSetObject:nativeUrlDict[@"msgtype"] forKey:@"msgType"];
				[params safeSetObject:nativeUrlDict[@"sendid"] forKey:@"sendId"];
				[params safeSetObject:nativeUrlDict[@"channelid"] forKey:@"channelId"];
				[params safeSetObject:[selfContact getContactDisplayName] forKey:@"nickName"];
				[params safeSetObject:[selfContact m_nsHeadImgUrl] forKey:@"headImg"];
				[params safeSetObject:[[wrap m_oWCPayInfoItem] m_c2cNativeUrl] forKey:@"nativeUrl"];
				[params safeSetObject:wrap.m_nsFromUsr forKey:@"sessionUserName"];	

				WCRedEnvelopesLogicMgr *logicMgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:[objc_getClass("WCRedEnvelopesLogicMgr") class]];
				[logicMgr OpenRedEnvelopesRequest:params];
			}
		}	
		break;
	}
	default:
		break;
	}
	
}
%end
