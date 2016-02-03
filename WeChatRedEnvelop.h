@interface WCPayInfoItem: NSObject

@property(retain, nonatomic) NSString *m_c2cNativeUrl;

@end

@interface CMessageWrap : NSObject // 微信消息
@property (retain, nonatomic) WCPayInfoItem *m_oWCPayInfoItem;
@property (assign, nonatomic) NSUInteger m_uiMesLocalID;
@property (retain, nonatomic) NSString* m_nsFromUsr; // 发信人，可能是群或个人
@property (retain, nonatomic) NSString* m_nsToUsr; // 收信人
@property (assign, nonatomic) NSUInteger m_uiStatus;
@property (retain, nonatomic) NSString* m_nsContent; // 消息内容
@property (retain, nonatomic) NSString* m_nsRealChatUsr; // 群消息的发信人，具体是群里的哪个人
@property (nonatomic) NSUInteger m_uiMessageType;
@property (nonatomic) long long m_n64MesSvrID;
@property (nonatomic) NSUInteger m_uiCreateTime;
@property (retain, nonatomic) NSString *m_nsDesc;
@property (retain, nonatomic) NSString *m_nsAppExtInfo;
@property (nonatomic) NSUInteger m_uiAppDataSize;
@property (nonatomic) NSUInteger m_uiAppMsgInnerType;
@property (retain, nonatomic) NSString *m_nsShareOpenUrl;
@property (retain, nonatomic) NSString *m_nsShareOriginUrl;
@property (retain, nonatomic) NSString *m_nsJsAppId;
@property (retain, nonatomic) NSString *m_nsPrePublishId;
@property (retain, nonatomic) NSString *m_nsAppID;
@property (retain, nonatomic) NSString *m_nsAppName;
@property (retain, nonatomic) NSString *m_nsThumbUrl;
@property (retain, nonatomic) NSString *m_nsAppMediaUrl;
@property (retain, nonatomic) NSData *m_dtThumbnail;
@property (retain, nonatomic) NSString *m_nsTitle;
@property (retain, nonatomic) NSString *m_nsMsgSource;
- (instancetype)initWithMsgType:(int)msgType;
+ (UIImage *)getMsgImg:(CMessageWrap *)arg1;
+ (NSData *)getMsgImgData:(CMessageWrap *)arg1;
+ (NSString *)getPathOfMsgImg:(CMessageWrap *)arg1;
- (UIImage *)GetImg;
- (BOOL)IsImgMsg;
- (BOOL)IsAtMe;
+ (void)GetPathOfAppThumb:(NSString *)senderID LocalID:(NSUInteger)mesLocalID retStrPath:(NSString **)pathBuffer;
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

@interface CContactDB : NSObject
{
    NSObject *m_oMMDB;
}

- (_Bool)isFriendExtTableExist:(id)arg1;
- (void)getFriendExtTableValue:(id)arg1 fromDBObject:(id)arg2;
- (void)getFriendTableValue:(id)arg1 fromDBObject:(id)arg2;
- (_Bool)SetFriendMetaFlag:(unsigned int)arg1 ForUser:(id)arg2;
- (unsigned int)GetFriendMetaFlag:(id)arg1;
- (_Bool)SetLastUpdateTime:(unsigned int)arg1 ForUser:(id)arg2;
- (unsigned int)GetLastUpdateTimeOfUser:(id)arg1;
- (_Bool)ModifyNotifyStatus:(id)arg1 withStatus:(unsigned int)arg2;
- (_Bool)updateContact:(id)arg1 andImage:(_Bool)arg2;
- (_Bool)updateContact:(id)arg1;
- (_Bool)deleteContact:(id)arg1;
- (_Bool)addContact:(id)arg1;
- (_Bool)getAllContactNoExtInfoList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllContactList:(id)arg1 listType:(unsigned int)arg2;
- (void)getFriendAndExtTableValue:(id)arg1 fromDBContact:(id)arg2 DBContactExt:(id)arg3;
- (_Bool)loadContactExtInfo:(id)arg1;
- (id)getContact:(id)arg1;
- (_Bool)updateContactKeyExtInfo:(id)arg1;
- (_Bool)modifyFriendExtTable:(id)arg1;
- (_Bool)modifyFriendTable:(id)arg1;
- (_Bool)addFriendExtTable:(id)arg1;
- (_Bool)addFriendTable:(id)arg1;
- (void)saveUserImage:(id)arg1;
- (_Bool)RollbackTransaction;
- (_Bool)CommitTransaction;
- (_Bool)BeginTransaction;
- (id)DBContext;
- (void)initDB:(id)arg1;
- (id)init;

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
{
    unsigned int m_uiLoadedType;
    CContactDB *m_oContactDB;
    NSObject *m_oContactOPLog;
    NSRecursiveLock *m_oMainControllerLock;
    NSMutableDictionary *m_dicContacts;
    NSMutableDictionary *m_dicEncodeContacts;
    _Bool m_bDataNeedReload;
    NSMutableDictionary *m_mapLastGetTime;
    NSMutableDictionary *m_dicHardCodeUsers;
    unsigned int m_uiDBVersion;
    CContact *m_oSelfContact;
    _Bool m_bIsSelfContactUpdated;
}
- (id)getSelfContact;
- (id)getContact:(id)arg1 listType:(unsigned int)arg2 contactType:(unsigned int)arg3;
@end

@interface NSMutableDictionary (SafeInsert)
- (void)safeSetObject:(id)arg1 forKey:(id)arg2;
@end

unsigned int yb_delayTime = 0;
BOOL yb_shouldStart = YES;
long yb_cellNumber = 0;


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

