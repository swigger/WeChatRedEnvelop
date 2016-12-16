@interface WCPayInfoItem: NSObject

@property(retain, nonatomic) NSString *m_c2cNativeUrl;

@end

@interface CMessageWrap : NSObject // 微信消息
@property(retain, nonatomic) NSString *m_nsRealChatUsr; // 群消息的发信人，具体是群里的哪个人
@property(retain, nonatomic) NSString *m_nsMsgSource; // @synthesize m_nsMsgSource;
@property(nonatomic) unsigned int m_uiCreateTime; // @synthesize m_uiCreateTime;
@property(nonatomic) unsigned int m_uiStatus; // @synthesize m_uiStatus;
@property(retain, nonatomic) NSString *m_nsContent; // @synthesize m_nsContent;
@property(nonatomic) unsigned int m_uiMessageType; // @synthesize m_uiMessageType;
@property(retain, nonatomic) NSString *m_nsToUsr; // @synthesize m_nsToUsr 收信人;
@property(retain, nonatomic) NSString *m_nsFromUsr; // @synthesize m_nsFromUsr 发信人，群或个人;
@property (nonatomic) long long m_n64MesSvrID;
@property(nonatomic) unsigned int m_uiMesLocalID; // @synthesize m_uiMesLocalID;
@property (retain, nonatomic) NSString *m_nsAppExtInfo;
@property(retain, nonatomic) NSString *m_nsAppID; // @dynamic m_nsAppID;
@property(retain, nonatomic) NSString *m_nsAppName; // @dynamic m_nsAppName;
@property(retain, nonatomic) NSString *m_nsDesc; // @dynamic m_nsDesc;
@property (retain, nonatomic) NSString *m_nsShareOpenUrl;
@property (retain, nonatomic) NSString *m_nsShareOriginUrl;
@property (retain, nonatomic) NSString *m_nsThumbUrl;
@property (retain, nonatomic) NSString *m_nsTitle;
@property(retain, nonatomic) WCPayInfoItem *m_oWCPayInfoItem; // @dynamic m_oWCPayInfoItem;
- (id)initWithMsgType:(long long)arg1;
@end

@interface WCRedEnvelopesControlData : NSObject
@property(retain, nonatomic) CMessageWrap *m_oSelectedMessageWrap;
@end

@interface MMServiceCenter : NSObject
+ (instancetype)defaultCenter;
- (id)getService:(Class)service;
@end


@interface WCRedEnvelopesLogicMgr: NSObject
- (void)OpenRedEnvelopesRequest:(id)params;
@end

@interface MMMsgLogicManager: NSObject
- (id)GetCurrentLogicController;
@end

@interface CContact: NSObject
@property(retain, nonatomic) NSString *m_nsUsrName;
@property(retain, nonatomic) NSString *m_nsHeadImgUrl;
@property(retain, nonatomic) NSString *m_nsNickName;


- (id)getContactDisplayName;
@end

@interface WCBizUtil : NSObject

+ (id)dictionaryWithDecodedComponets:(id)arg1 separator:(id)arg2;

@end

@interface CContactMgr : NSObject
- (id)getSelfContact;
- (id)getContactFromDB:(id)arg1;
- (id)getContactByName:(id)arg1;
@end

@interface NSMutableDictionary (SafeInsert)
- (void)safeSetObject:(id)arg1 forKey:(id)arg2;
@end

@interface MMUINavigationBar : UINavigationBar
- (void)setFrame:(struct CGRect)arg1;
@end

@interface MMUINavigationController : UINavigationController
@end

@interface MMUIViewController : UIViewController
@end

@interface SettingBaseViewController : MMUIViewController
@end

@interface SettingPluginsViewController : SettingBaseViewController
@end

@interface MMUIResponder : UIResponder
@end

@protocol ResourceMonitorDelegate <NSObject>
@end

@interface MicroMessengerAppDelegate : MMUIResponder <UIApplicationDelegate, UIAlertViewDelegate, ResourceMonitorDelegate>
@end
