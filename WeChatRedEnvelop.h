#pragma once
@protocol IAcctStorageMgrExt;
@protocol IAppMsgPathMgr;
@protocol IBrandAttrMgrExt;
@protocol IContactProfileMgrExt;
@protocol IMMLanguageMgrExt;
@protocol IMsgExtendOperation;
@protocol IStrangerContactMgrExt;
@protocol ISysNewXmlMsgExtendOperation;
@protocol MMDBRRepairerExt;
@protocol MessageObserverDelegate;
@protocol NSCoding;
@protocol NSCopying;
@protocol PBCoding;
@protocol PBMessageObserverDelegate;
@protocol RecoverCustomDataWorker;
@protocol WCDBCoding;
@protocol WCDBCorruptReportInterface;
@protocol WCDBHandleWrapProtocol;
@protocol WCDBHandlesPoolProtocol;
@protocol WCDBRestoreProtocol;
@protocol WCDataBaseEventDelegate;
@protocol WCRedEnvelopesNetworkHelperDelegate;
@class WCPayInfoItem;
@class EmoticonSharedItem;
@class AppTVItem;
@class AppProductItem;
@class EmotionDesignerSharedItem;
@class WAAppPackageInfo;
@class EmotionPageSharedItem;
@class AppInnerJumpItem;
@class WAAppMsgItem;
@class MallProductItem;
@class CardTicketItem;
@class MessageExpItem;
@class SnsObjItem;
@class iWatchAppMsgItem;
@class HardWareItem;
@class MMObject;
@class WCDBRWLock;
@class WCDataBase;
@class WCDataBaseTable;
@class WXPBGeneratedMessage;
@class MMTimer;
@class MMService;
@class WCDBHandlesPool;
@class WCDBCorruptReport;
@class WCDBHandleWrap;
@class GiftCardItem;
@class MMWCPushInfo;
@class WCRedEnvelopesLogicMgr;
@class ContactUpdateHelper;
@class WCRedEnvelopesNetworkHelper;
@class RecoverDataItem;
@class PushMailWrap;
@class FavLocationItem;
@class FavURLItem;
@class FavProductItem;
@class FavTVItem;
@class FavWeAppItem;
@class FavoritesItem;
@class MMAsset;
@class CContactDB;
@class CContactOPLog;
@class CMessageWrap;
@class CBaseContact;
@class SubscriptBrandInfo;
@class ChatRoomDetail;
@class CContact;
@class CQQContact;
@class WANewYearContactInfo;
@class NewContactDB;
@class VideoParamsInfo;
@class VideoParamsSource;
@class VideoUploadStatInfo;
@class ChatRoomData;
@class CContactMgr;
@class CMessageDB;
@class CMMDB;
@class ImageInfo;
@class UrlInfo;
@class ProtobufCGIWrap;
@class OpLogDB;
@class WCCanvasPageItem;
@class BaseRequest;
@class BaseResponse;
@class SKBuiltinBuffer_t;
@class SKBuiltinString_t;
@class AsyncBizSubscribeRequest;
@class AsyncBizSubscribeResponse;
@class HongBaoReq;
@class HongBaoRes;
@class FestivalHongBaoReq;
@class FestivalHongBaoRes;
@class NSError;
@class NSMutableDictionary;
@class NSURL;
@class NSTimer;
@class NSDate;
@class NSThread;
@class NSMutableArray;
@class NSData;
@class UIImage;
@class NSArray;
@class NSDictionary;
@class NSString;
@class NSObject;
typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown
struct WCDBConditionBase {
    _Bool _field1;
};
struct basic_string_;
struct vector_;
struct map_;
struct set_;

@interface MMObject : NSObject
{
}
@end

@protocol IAcctStorageMgrExt <NSObject>

@optional
- (void)onSyncBufferChanged:(NSData *)arg1 isMerged:(_Bool)arg2;
- (void)onSettingChange;
@end

@protocol IAppMsgPathMgr <NSObject>

@optional
+ (void)GetPathOfAppRemindAttach:(CMessageWrap *)arg1 retStrPath:(id *)arg2;
+ (void)GetPathOfAppThumb:(NSString *)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfMaskedAppThumb:(NSString *)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfAppDataTemp:(NSString *)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfAppDataTemp:(NSString *)arg1 LocalID:(unsigned int)arg2 AttachId:(NSString *)arg3 retStrPath:(id *)arg4;
+ (void)GetPathOfAppDataByUserName:(NSString *)arg1 andMessageWrap:(CMessageWrap *)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfAppDataByUserName:(NSString *)arg1 andMessageWrap:(CMessageWrap *)arg2 andAttachId:(NSString *)arg3 andAttachFileExt:(NSString *)arg4 retStrPath:(id *)arg5;
+ (void)GetPathOfAppData:(NSString *)arg1 LocalID:(unsigned int)arg2 FileExt:(NSString *)arg3 retStrPath:(id *)arg4;
+ (void)GetPathOfAppDir:(NSString *)arg1 retStrPath:(id *)arg2;
@end

@protocol IBrandAttrMgrExt

@optional
- (void)onBrandContactModified:(NSString *)arg1 withAttrChanged:(NSDictionary *)arg2;
@end

@protocol IContactProfileMgrExt

@optional
- (void)DidGetQQContactProfile:(CQQContact *)arg1 withImage:(_Bool)arg2;
@end

@protocol IMMLanguageMgrExt <NSObject>

@optional
- (void)onLanguageChange;
@end

@protocol IMsgExtendOperation <NSObject>
@property(retain, nonatomic) CMessageWrap *m_refMessageWrap;
- (id)copy;

@optional
- (NSString *)GetDisplaySessionContent;
- (NSString *)GetDisplayContent;
- (void)UpdateMassSendContent:(NSString *)arg1;
- (_Bool)genImageFromMMAssetAndNotify:(id)arg1;
- (_Bool)IsHDImg;
- (void)setImage:(UIImage *)arg1 withImageInfo:(ImageInfo *)arg2 isLongOriginImage:(_Bool)arg3;
- (void)setImage:(UIImage *)arg1 withData:(NSData *)arg2 withImageInfo:(ImageInfo *)arg3 isLongOriginImage:(_Bool)arg4;
- (void)setImage:(UIImage *)arg1 withData:(NSData *)arg2 isLongOriginImage:(_Bool)arg3;
- (void)setImage:(UIImage *)arg1 isLongOriginImage:(_Bool)arg2;
- (void)SetOriginal:(_Bool)arg1;
- (unsigned int)GetContentAttributeBitSetFlag;
- (_Bool)GetDownloadThumbStatus:(unsigned int *)arg1;
- (_Bool)isShowAppMessageBlockButton;
- (_Bool)isShowAppBottomButton;
- (unsigned int)GetPreviewType;
- (NSString *)getFileExt;
- (void)UpdateVideoStatus:(CMessageDB *)arg1;
- (void)SetPlaySounded:(_Bool)arg1;
- (_Bool)IsPlaySounded;
- (_Bool)IsRecording;
- (void)SetPlayed;
- (_Bool)IsDownloadEnded;
- (_Bool)IsUnPlayed;
- (_Bool)SaveMesVoice:(NSString *)arg1;
- (NSString *)GetDownloadThumbPath;
- (NSString *)GetThumbPath;
- (void)ChangeForBackup;
- (void)UpdateGameInfo:(NSString *)arg1;
- (NSString *)GetGameStatReportString;
- (NSString *)GetContent;
- (void)UpdateContent:(NSString *)arg1;
- (void)ChangeForDisplayAnyhow;
- (void)ChangeForDisplay;
@end

@protocol IStrangerContactMgrExt <NSObject>

@optional
- (void)onStrangerContactUpdateForbidden:(NSString *)arg1;
- (void)onStrangerContactUpdated:(NSString *)arg1 Contact:(CContact *)arg2;
- (void)onStrangerContactUpdated:(NSArray *)arg1;
@end

@protocol ISysNewXmlMsgExtendOperation <NSObject>

@optional
- (_Bool)isApproveToInviterScene;
- (_Bool)isApproveScene;
- (_Bool)isInviterScene;
- (_Bool)isWebviewScene;
- (_Bool)isInvitationScene;
- (_Bool)isQRCodeScene;
@end

@protocol MMDBRRepairerExt <NSObject>

@optional
- (void)willRepairDB:(unsigned int)arg1 needCatch:(_Bool *)arg2;
@end

@protocol MessageObserverDelegate
- (void)MessageReturn:(unsigned int)arg1 MessageInfo:(NSDictionary *)arg2 Event:(unsigned int)arg3;
@end


@protocol PBCoding <NSObject>
- (const map_ *)getValueTagIndexMap;
- (NSArray *)getValueTypeTable;
@end

@protocol PBMessageObserverDelegate
- (void)MessageReturn:(ProtobufCGIWrap *)arg1 Event:(unsigned int)arg2;
@end

@protocol RecoverCustomDataWorker
- (void)willCustomRecoverData:(RecoverDataItem *)arg1 path:(NSString *)arg2 needCatch:(_Bool *)arg3;
@end

@protocol WCDBCoding <PBCoding>
+ (id)dummyObject;
+ (const map_ *)getValueNameIndexMap;
+ (NSArray *)getValueTable;
@property(nonatomic) long long __rowID;

@optional
+ (NSDictionary *)getWCDBTableHelperDictionary;
+ (const map_ *)getFileValueTagIndexMap;
+ (NSArray *)getFileValueTypeTable;
+ (const map_ *)getPackedValueTagIndexMap;
+ (NSArray *)getPackedValueTypeTable;
+ (const basic_string_ *)getWCDBPrimaryColumnName;
+ (const struct WCDBIndexHelper *)getWCDBIndexArray;
+ (unsigned long long)getWCDBIndexArrayCount;
@end

@protocol WCDBCorruptReportInterface <NSObject>
- (void)ClearCorruptNum;
- (void)recordCorrupt:(int)arg1 tableName:(NSString *)arg2 opType:(unsigned int)arg3;

@optional
- (void)directReportCorrupt:(int)arg1 tableName:(NSString *)arg2 opType:(unsigned int)arg3;
@end

@protocol WCDBHandleWrapProtocol <NSObject>
- (void)handleWrapWillEnd:(WCDBHandleWrap *)arg1;
@end

@protocol WCDBHandlesPoolProtocol <NSObject>

@optional
- (void)onGenerateNewHandle:(struct sqlite3 *)arg1;
@end

@protocol WCDBRestoreProtocol
- (Class)classFromTableName:(NSString *)arg1;

@optional
- (void)onRepairProgressUpdate:(float)arg1;
@end

@protocol WCDataBaseEventDelegate <NSObject>

@optional
- (_Bool)onDatabaseCorrupt:(NSString *)arg1 errorCode:(int)arg2 opType:(unsigned int)arg3;
- (void)onGenerateNewHandle:(struct sqlite3 *)arg1;
- (void)onTransactionRollback;
@end

@protocol WCRedEnvelopesNetworkHelperDelegate <NSObject>
- (void)OnWCToAsyncBizSubscribeResponse:(AsyncBizSubscribeResponse *)arg1 Request:(AsyncBizSubscribeRequest *)arg2;
- (void)OnWCToBizHBCommonErrorResponse:(HongBaoRes *)arg1 Request:(HongBaoReq *)arg2;
- (void)OnWCToBizHBCommonSystemErrorResponse:(HongBaoRes *)arg1 Request:(HongBaoReq *)arg2;
- (void)OnWCToBizHBCommonResponse:(HongBaoRes *)arg1 Request:(HongBaoReq *)arg2;
- (void)OnWCToEnterpriseHBCommonErrorResponse:(FestivalHongBaoRes *)arg1 Request:(FestivalHongBaoReq *)arg2;
- (void)OnWCToEnterpriseHBCommonSystemErrorResponse:(FestivalHongBaoRes *)arg1 Request:(FestivalHongBaoReq *)arg2;
- (void)OnWCToEnterpriseHBCommonResponse:(FestivalHongBaoRes *)arg1 Request:(FestivalHongBaoReq *)arg2;
- (void)OnWCToHongbaoCommonErrorResponse:(HongBaoRes *)arg1 Request:(HongBaoReq *)arg2;
- (void)OnWCToHongbaoCommonSystemErrorResponse:(HongBaoRes *)arg1 Request:(HongBaoReq *)arg2;
- (void)OnWCToHongbaoCommonResponse:(HongBaoRes *)arg1 Request:(HongBaoReq *)arg2;
@end

@interface WCPayInfoItem : NSObject <PBCoding, NSCopying>
{
    unsigned int m_uiPaySubType;
    NSString *m_nsFeeDesc;
    NSString *m_nsTranscationID;
    unsigned int m_uiInvalidTime;
    unsigned int m_uiBeginTransferTime;
    NSString *m_nsTransferID;
    unsigned int m_uiEffectiveDate;
    unsigned int m_templateID;
    NSString *m_c2cUrl;
    NSString *m_c2cNativeUrl;
    NSString *m_c2cIconUrl;
    NSString *m_receiverTitle;
    NSString *m_receiverDesc;
    NSString *m_senderTitle;
    NSString *m_senderDesc;
    NSString *m_hintText;
    NSString *m_sceneText;
    NSString *m_total_fee;
    NSString *m_fee_type;
    unsigned int m_c2c_msg_subtype;
    NSString *m_nsPayMsgID;
    NSString *m_payMemo;
    NSString *m_nsImageID;
    NSString *m_nsImageAesKey;
    unsigned int m_uiImageLength;
    unsigned int m_sceneId;
    NSString *m_aaOrderBillNum;
    unsigned int m_aaNewAAType;
    NSString *m_aaLauncherTitle;
    NSString *m_aaNotinerTitle;
    NSString *m_aaReceiverTitle;
    NSString *m_aaReceiverList;
    NSString *m_aaPayerTitle;
    NSString *m_aaPayerList;
    NSString *m_aaLauncherUsername;
    int m_redEnvelopeType;
    long long m_redEnvelopeReceiveAmount;
}

+ (void)initialize;
@property(nonatomic) long long m_redEnvelopeReceiveAmount; // @synthesize m_redEnvelopeReceiveAmount;
@property(nonatomic) int m_redEnvelopeType; // @synthesize m_redEnvelopeType;
@property(retain, nonatomic) NSString *m_aaLauncherUsername; // @synthesize m_aaLauncherUsername;
@property(retain, nonatomic) NSString *m_aaPayerList; // @synthesize m_aaPayerList;
@property(retain, nonatomic) NSString *m_aaPayerTitle; // @synthesize m_aaPayerTitle;
@property(retain, nonatomic) NSString *m_aaReceiverList; // @synthesize m_aaReceiverList;
@property(retain, nonatomic) NSString *m_aaReceiverTitle; // @synthesize m_aaReceiverTitle;
@property(retain, nonatomic) NSString *m_aaNotinerTitle; // @synthesize m_aaNotinerTitle;
@property(retain, nonatomic) NSString *m_aaLauncherTitle; // @synthesize m_aaLauncherTitle;
@property(nonatomic) unsigned int m_aaNewAAType; // @synthesize m_aaNewAAType;
@property(retain, nonatomic) NSString *m_aaOrderBillNum; // @synthesize m_aaOrderBillNum;
@property(nonatomic) unsigned int m_sceneId; // @synthesize m_sceneId;
@property(nonatomic) unsigned int m_uiImageLength; // @synthesize m_uiImageLength;
@property(retain, nonatomic) NSString *m_nsImageAesKey; // @synthesize m_nsImageAesKey;
@property(retain, nonatomic) NSString *m_nsImageID; // @synthesize m_nsImageID;
@property(retain, nonatomic) NSString *m_payMemo; // @synthesize m_payMemo;
@property(retain, nonatomic) NSString *m_nsPayMsgID; // @synthesize m_nsPayMsgID;
@property(nonatomic) unsigned int m_c2c_msg_subtype; // @synthesize m_c2c_msg_subtype;
@property(retain, nonatomic) NSString *m_c2cNativeUrl; // @synthesize m_c2cNativeUrl;
@property(retain, nonatomic) NSString *m_fee_type; // @synthesize m_fee_type;
@property(retain, nonatomic) NSString *m_total_fee; // @synthesize m_total_fee;
@property(retain, nonatomic) NSString *m_senderDesc; // @synthesize m_senderDesc;
@property(retain, nonatomic) NSString *m_receiverDesc; // @synthesize m_receiverDesc;
@property(retain, nonatomic) NSString *m_sceneText; // @synthesize m_sceneText;
@property(retain, nonatomic) NSString *m_hintText; // @synthesize m_hintText;
@property(retain, nonatomic) NSString *m_senderTitle; // @synthesize m_senderTitle;
@property(retain, nonatomic) NSString *m_receiverTitle; // @synthesize m_receiverTitle;
@property(retain, nonatomic) NSString *m_c2cIconUrl; // @synthesize m_c2cIconUrl;
@property(retain, nonatomic) NSString *m_c2cUrl; // @synthesize m_c2cUrl;
@property(nonatomic) unsigned int m_templateID; // @synthesize m_templateID;
@property(nonatomic) unsigned int m_uiEffectiveDate; // @synthesize m_uiEffectiveDate;
@property(nonatomic) unsigned int m_uiBeginTransferTime; // @synthesize m_uiBeginTransferTime;
@property(retain, nonatomic) NSString *m_nsTransferID; // @synthesize m_nsTransferID;
@property(nonatomic) unsigned int m_uiInvalidTime; // @synthesize m_uiInvalidTime;
@property(retain, nonatomic) NSString *m_nsTranscationID; // @synthesize m_nsTranscationID;
@property(retain, nonatomic) NSString *m_nsFeeDesc; // @synthesize m_nsFeeDesc;
@property(nonatomic) unsigned int m_uiPaySubType; // @synthesize m_uiPaySubType;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface EmoticonSharedItem : NSObject <PBCoding, NSCopying>
{
    unsigned int m_packType;
    NSString *m_productId;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *m_productId; // @synthesize m_productId;
@property(nonatomic) unsigned int m_packType; // @synthesize m_packType;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface AppTVItem : NSObject
{
    NSString *tvInfo;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *tvInfo; // @synthesize tvInfo;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)toXML;
- (void)dealloc;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

@end

@interface AppProductItem : NSObject <PBCoding, NSCopying>
{
    unsigned int type;
    NSString *productInfo;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *productInfo; // @synthesize productInfo;
@property(nonatomic) unsigned int type; // @synthesize type;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface EmotionDesignerSharedItem : NSObject
{
    unsigned int designerUin;
    NSString *oldRedirectUrl;
    NSString *designerName;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *designerName; // @synthesize designerName;
@property(retain, nonatomic) NSString *oldRedirectUrl; // @synthesize oldRedirectUrl;
@property(nonatomic) unsigned int designerUin; // @synthesize designerUin;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

@end

@interface WAAppPackageInfo : MMObject
{
    unsigned int _type;
    NSString *_md5;
}

@property(copy, nonatomic) NSString *md5; // @synthesize md5=_md5;
@property(nonatomic) unsigned int type; // @synthesize type=_type;
- (id)toXML;
- (_Bool)fromXMLStr:(id)arg1;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

@interface EmotionPageSharedItem : MMObject
{
    NSDictionary *_params;
}

@property(retain, nonatomic) NSDictionary *params; // @synthesize params=_params;
- (id)xmlToDictionary:(struct XmlReaderNode_t *)arg1;
- (id)dictionaryToXml:(id)arg1;
- (id)toXML;
- (_Bool)fromXMLStr:(id)arg1;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

@interface AppInnerJumpItem : MMObject <NSCopying, PBCoding>
{
    _Bool bEnableJump;
    NSString *nsJumpUrl;
    NSString *nsPushContent;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *nsPushContent; // @synthesize nsPushContent;
@property(retain, nonatomic) NSString *nsJumpUrl; // @synthesize nsJumpUrl;
@property(nonatomic) _Bool bEnableJump; // @synthesize bEnableJump;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface WAAppMsgItem : MMObject
{
    unsigned int _type;
    unsigned int _version;
    NSString *_username;
    NSString *_appid;
    NSString *_pagepath;
    NSString *_weappIconUrl;
    WAAppPackageInfo *_packInfo;
}

@property(retain, nonatomic) WAAppPackageInfo *packInfo; // @synthesize packInfo=_packInfo;
@property(retain, nonatomic) NSString *weappIconUrl; // @synthesize weappIconUrl=_weappIconUrl;
@property(nonatomic) unsigned int version; // @synthesize version=_version;
@property(nonatomic) unsigned int type; // @synthesize type=_type;
@property(retain, nonatomic) NSString *pagepath; // @synthesize pagepath=_pagepath;
@property(retain, nonatomic) NSString *appid; // @synthesize appid=_appid;
@property(retain, nonatomic) NSString *username; // @synthesize username=_username;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

@interface MallProductItem : NSObject <PBCoding, NSCopying>
{
    unsigned int type;
    NSString *mallProductInfo;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *mallProductInfo; // @synthesize mallProductInfo;
@property(nonatomic) unsigned int type; // @synthesize type;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface CardTicketItem : MMObject <PBCoding, NSCopying>
{
    NSString *fromUserName;
    unsigned int fromScene;
    unsigned int cardType;
    NSString *cardTypeName;
    NSString *cardId;
    NSString *color;
    NSString *brandName;
    NSString *cardExt;
    unsigned int cardShareFrom;
    _Bool isRecommend;
    NSString *recommendCardId;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *recommendCardId; // @synthesize recommendCardId;
@property(nonatomic) _Bool isRecommend; // @synthesize isRecommend;
@property(nonatomic) unsigned int cardShareFrom; // @synthesize cardShareFrom;
@property(retain, nonatomic) NSString *cardExt; // @synthesize cardExt;
@property(retain, nonatomic) NSString *brandName; // @synthesize brandName;
@property(retain, nonatomic) NSString *cardTypeName; // @synthesize cardTypeName;
@property(retain, nonatomic) NSString *color; // @synthesize color;
@property(retain, nonatomic) NSString *cardId; // @synthesize cardId;
@property(nonatomic) unsigned int cardType; // @synthesize cardType;
@property(nonatomic) unsigned int fromScene; // @synthesize fromScene;
@property(retain, nonatomic) NSString *fromUserName; // @synthesize fromUserName;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)init;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface MessageExpItem : MMObject <NSCopying>
{
    _Bool bNeedUpdateTitle;
    _Bool bNeedUpdateDesc;
    _Bool bAppMsgDefaultThumb;
    _Bool bNeedHiddenAppTail;
    unsigned int uiImageDownloadControlType;
    unsigned int uiSightDownloadControlType;
    NSString *nsExpIdStr;
    NSString *nsAppMsgTitle;
    NSString *nsAppMsgDesc;
}

+ (id)genExpXMLFromMessageWrap:(id)arg1;
@property(nonatomic) unsigned int uiSightDownloadControlType; // @synthesize uiSightDownloadControlType;
@property(nonatomic) unsigned int uiImageDownloadControlType; // @synthesize uiImageDownloadControlType;
@property(nonatomic) _Bool bNeedHiddenAppTail; // @synthesize bNeedHiddenAppTail;
@property(nonatomic) _Bool bAppMsgDefaultThumb; // @synthesize bAppMsgDefaultThumb;
@property(retain, nonatomic) NSString *nsAppMsgDesc; // @synthesize nsAppMsgDesc;
@property(nonatomic) _Bool bNeedUpdateDesc; // @synthesize bNeedUpdateDesc;
@property(retain, nonatomic) NSString *nsAppMsgTitle; // @synthesize nsAppMsgTitle;
@property(nonatomic) _Bool bNeedUpdateTitle; // @synthesize bNeedUpdateTitle;
@property(retain, nonatomic) NSString *nsExpIdStr; // @synthesize nsExpIdStr;
- (_Bool)isExpValid;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

@interface SnsObjItem : MMObject
{
    NSString *_tid;
    NSString *_userName;
}

@property(retain, nonatomic) NSString *userName; // @synthesize userName=_userName;
@property(retain, nonatomic) NSString *tid; // @synthesize tid=_tid;
- (void)dealloc;

@end

@interface iWatchAppMsgItem : MMObject
{
    SnsObjItem *_snsObj;
}

@property(retain, nonatomic) SnsObjItem *snsObj; // @synthesize snsObj=_snsObj;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (void)dealloc;

@end

@interface HardWareItem : MMObject <NSCopying>
{
    unsigned int uiHardWareShowType;
    NSString *nsRankID;
    NSString *nsRankTitle;
    NSString *nsRankDisplay;
    NSString *nsScoreTitle;
    NSString *nsScoreDisplay;
    NSString *nsTipDisplay;
    NSString *nsColor;
    NSString *nsHighLightColor;
    NSString *nsLineColor;
    NSString *nsHighLightLineColor;
    NSString *nsFontColor;
    NSString *nsChampionUsername;
    NSString *nsDisplayUserName;
    NSString *nsThumbUrl;
    NSString *nsNotifyTitle;
    unsigned int uiTimeStamp;
}

@property(retain, nonatomic) NSString *nsNotifyTitle; // @synthesize nsNotifyTitle;
@property(retain, nonatomic) NSString *nsThumbUrl; // @synthesize nsThumbUrl;
@property(retain, nonatomic) NSString *nsDisplayUserName; // @synthesize nsDisplayUserName;
@property(retain, nonatomic) NSString *nsChampionUsername; // @synthesize nsChampionUsername;
@property(retain, nonatomic) NSString *nsFontColor; // @synthesize nsFontColor;
@property(retain, nonatomic) NSString *nsHighLightLineColor; // @synthesize nsHighLightLineColor;
@property(retain, nonatomic) NSString *nsLineColor; // @synthesize nsLineColor;
@property(retain, nonatomic) NSString *nsHighLightColor; // @synthesize nsHighLightColor;
@property(retain, nonatomic) NSString *nsColor; // @synthesize nsColor;
@property(nonatomic) unsigned int uiTimeStamp; // @synthesize uiTimeStamp;
@property(retain, nonatomic) NSString *nsTipDisplay; // @synthesize nsTipDisplay;
@property(retain, nonatomic) NSString *nsScoreDisplay; // @synthesize nsScoreDisplay;
@property(retain, nonatomic) NSString *nsScoreTitle; // @synthesize nsScoreTitle;
@property(retain, nonatomic) NSString *nsRankDisplay; // @synthesize nsRankDisplay;
@property(retain, nonatomic) NSString *nsRankTitle; // @synthesize nsRankTitle;
@property(retain, nonatomic) NSString *nsRankID; // @synthesize nsRankID;
@property(nonatomic) unsigned int uiHardWareShowType; // @synthesize uiHardWareShowType;
- (_Bool)IsExpired;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end


@interface WCDBRWLock : NSObject
{
    NSCondition *m_locker;
}

- (void)dealloc;
- (void)unlock:(unsigned long long)arg1;
- (void)lock:(unsigned long long)arg1;
- (_Bool)tryLockRead;
- (id)init;

@end

@interface WCDataBase : NSObject <WCDBCorruptReportInterface, WCDBHandlesPoolProtocol>
{
    WCDBHandlesPool *m_handlesPool;
    NSData *m_dbEncryptKey;
    _Bool m_isMemoryOnly;
    NSString *m_nsDBPath;
    NSString *m_nsDBFilePath;
    NSString *m_nsDBName;
    unsigned int m_databaseID;
    _Bool _m_isInCheckpointProcess;
    _Bool _m_didCheckpointFailed;
    _Bool _m_autoEmptyingTrash;
    int _m_checkpointFailedCount;
    id <WCDataBaseEventDelegate> m_eventDelegate;
    WCDBCorruptReport *m_corruptReport;
}

+ (int)intValueForPragmaSetting:(id)arg1 forHandle:(struct sqlite3 *)arg2;
+ (_Bool)GetRowId:(long long *)arg1 fromObject:(id)arg2;
+ (id)extractOneObjectOfClass:(Class)arg1 fromColumn:(struct sqliterk_column *)arg2;
+ (id)dbPathsFrom:(id)arg1;
+ (_Bool)safeMoveDBFrom:(id)arg1 to:(id)arg2 error:(id *)arg3;
+ (void)initialize;
+ (void)setFileProtection:(id)arg1;
+ (_Bool)safeRenameDBFrom:(id)arg1 to:(id)arg2 error:(id *)arg3;
+ (_Bool)renameDBFrom:(id)arg1 to:(id)arg2 error:(id *)arg3;
+ (_Bool)deleteDB:(id)arg1;
+ (id)backupPathsFrom:(id)arg1;
@property _Bool m_autoEmptyingTrash; // @synthesize m_autoEmptyingTrash=_m_autoEmptyingTrash;
@property int m_checkpointFailedCount; // @synthesize m_checkpointFailedCount=_m_checkpointFailedCount;
@property _Bool m_didCheckpointFailed; // @synthesize m_didCheckpointFailed=_m_didCheckpointFailed;
@property _Bool m_isInCheckpointProcess; // @synthesize m_isInCheckpointProcess=_m_isInCheckpointProcess;
@property(retain, nonatomic) WCDBCorruptReport *m_corruptReport; // @synthesize m_corruptReport;
@property __weak id <WCDataBaseEventDelegate> m_eventDelegate; // @synthesize m_eventDelegate;
@property(readonly, nonatomic) NSString *m_nsDBFilePath; // @synthesize m_nsDBFilePath;
@property(readonly, nonatomic) NSString *m_nsDBPath; // @synthesize m_nsDBPath;
@property(readonly, nonatomic) _Bool m_isMemoryOnly; // @synthesize m_isMemoryOnly;
- (_Bool)pragmaSetting:(id)arg1 opID:(unsigned int)arg2 forHandle:(struct sqlite3 *)arg3;
- (id)stringValueForPragmaSetting:(id)arg1 opID:(unsigned int)arg2 forHandle:(struct sqlite3 *)arg3;
- (int)intValueForPragmaSetting:(id)arg1 opID:(unsigned int)arg2 forHandle:(struct sqlite3 *)arg3;
- (void)callEventTransactionRollback;
- (id)errorWithCode:(int)arg1 Description:(id)arg2;
- (void)ClearCorruptNum;
- (void)directReportCorrupt:(int)arg1 tableName:(id)arg2 opType:(unsigned int)arg3;
- (void)recordCorrupt:(int)arg1 tableName:(id)arg2 opType:(unsigned int)arg3;
- (_Bool)deleteObjectsFromTable:(id)arg1 where:(const struct WCDBConditionBase *)arg2;
- (_Bool)deleteObject:(id)arg1 fromTable:(id)arg2;
- (basic_string_)getConditionStringFromObj:(id)arg1;
- (_Bool)updateObject:(id)arg1 onProperties:(const vector_ *)arg2 ofTable:(id)arg3 where:(const struct WCDBConditionBase *)arg4;
- (_Bool)updateObject:(id)arg1 onProperties:(const vector_ *)arg2 ofTable:(id)arg3;
- (_Bool)updateProperty:(const struct WCDBConditionBase *)arg1 withValue:(id)arg2 ofClass:(Class)arg3 ofTable:(id)arg4 where:(const struct WCDBConditionBase *)arg5;
- (_Bool)insertOrUpdateObjects:(id)arg1 inToTable:(id)arg2 onConflict:(CDUnknownBlockType)arg3;
- (_Bool)insertOrUpdateObject:(id)arg1 inToTable:(id)arg2 onConflict:(CDUnknownBlockType)arg3;
- (_Bool)insertOrUpdateObjects:(id)arg1 inToTable:(id)arg2 error:(id *)arg3;
- (_Bool)insertObjects:(id)arg1 inToTable:(id)arg2 error:(id *)arg3 autoIncrement:(_Bool)arg4;
- (_Bool)insertObjects:(id)arg1 inToTable:(id)arg2 error:(id *)arg3 autoIncrement:(_Bool)arg4 transaction:(_Bool)arg5;
- (_Bool)insertOrUpdateObjects:(id)arg1 inToTable:(id)arg2;
- (_Bool)insertObject:(id)arg1 onProperties:(const vector_ *)arg2 inToTable:(id)arg3 autoIncrement:(_Bool)arg4;
- (_Bool)insertObject:(id)arg1 inToTable:(id)arg2 autoIncrement:(_Bool)arg3;
- (_Bool)insertOrUpdateObject:(id)arg1 onProperties:(const vector_ *)arg2 inToTable:(id)arg3;
- (_Bool)insertOrUpdateObject:(id)arg1 inToTable:(id)arg2;
- (_Bool)doInsertObjectWithBind:(id)arg1 onProperties:(const vector_ *)arg2 inToTable:(id)arg3 autoIncrement:(_Bool)arg4 isOrReplace:(_Bool)arg5;
- (void)autoIncrementPrimaryKey:(id)arg1 withValue:(long long)arg2;
- (void)bindBlobProperty:(const vector_ *)arg1 ofObject:(id)arg2 toSTMT:(struct sqlite3_stmt *)arg3;
- (void)bindBlobProperty:(id)arg1 toSTMT:(struct sqlite3_stmt *)arg2;
- (basic_string_)dumpProperty:(id)arg1 withObject:(id)arg2;
- (basic_string_)dumpProperty:(id)arg1 withValue:(id)arg2;
- (void)dumpObject:(id)arg1 onProperties:(const vector_ *)arg2 toNameString:(basic_string_ *)arg3 andValueString:(basic_string_ *)arg4 autoIncrement:(_Bool)arg5;
- (void)bindPropertys:(id)arg1 toSTMT:(struct sqlite3_stmt *)arg2 withSpecificProperty:(const set_ *)arg3 isAutoIncrement:(_Bool *)arg4;
- (void)generateInsertSQLString:(basic_string_ *)arg1 withSpecificProperty:(const set_ *)arg2 isReplaceOnConflict:(_Bool)arg3 cls:(Class)arg4 tableName:(id)arg5;
- (set_)dumpSpecificProperty:(const vector_ *)arg1;
- (_Bool)doInsertObjects:(id)arg1 onProperties:(const vector_ *)arg2 inToTable:(id)arg3 autoIncrement:(_Bool)arg4 isOrReplace:(_Bool)arg5 error:(id *)arg6;
- (_Bool)canItemAutoIncrement:(id)arg1;
- (void)fillCrossTableFromTableName:(basic_string_ *)arg1 queryInfo:(id)arg2;
- (id)itemFromObject:(id)arg1 columnName:(const basic_string_ *)arg2;
- (_Bool)fillCrossTableSelectProperty:(basic_string_ *)arg1 queryInfo:(id)arg2 columnInfo:(id)arg3;
- (_Bool)checkTableQueryInfo:(id)arg1;
- (id)getObjectsCrossTables:(id)arg1 where:(const struct WCDBConditionBase *)arg2 orderBy:(const struct WCDBConditionBase *)arg3 limit:(unsigned int)arg4 getError:(id *)arg5;
- (id)getSumProperty:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2 ofClass:(Class)arg3 fromTable:(id)arg4;
- (id)getMaxProperty:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2 ofClass:(Class)arg3 fromTable:(id)arg4;
- (id)getMaxProperty:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3;
- (id)getOnePropertyValue:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3 where:(const struct WCDBConditionBase *)arg4 orderBy:(const struct WCDBConditionBase *)arg5;
- (id)getPropertyWithDistinct:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3 where:(const struct WCDBConditionBase *)arg4;
- (id)getProperty:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3 where:(const struct WCDBConditionBase *)arg4 orderBy:(const struct WCDBConditionBase *)arg5 limit:(unsigned int)arg6;
- (id)getProperty:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3 where:(const struct WCDBConditionBase *)arg4 limit:(unsigned int)arg5;
- (id)getProperty:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3 where:(const struct WCDBConditionBase *)arg4;
- (id)getProperty:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3;
- (id)getOneProperty:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3 withQueryString:(const basic_string_ *)arg4;
- (id)getProperty:(const struct WCDBConditionBase *)arg1 ofClass:(Class)arg2 fromTable:(id)arg3 withQueryString:(const basic_string_ *)arg4;
- (unsigned int)getTablesCount;
- (unsigned int)getCountOfObjectsOfClass:(Class)arg1 fromTable:(id)arg2 withDistinctProperty:(const struct WCDBConditionBase *)arg3 where:(const struct WCDBConditionBase *)arg4;
- (unsigned int)getCountOfObjectsOfClass:(Class)arg1 fromTable:(id)arg2 where:(const struct WCDBConditionBase *)arg3;
- (id)getObjectsOfClass:(Class)arg1 fromTable:(id)arg2 onProperties:(const vector_ *)arg3 where:(const struct WCDBConditionBase *)arg4 orderBy:(const struct WCDBConditionBase *)arg5 limit:(unsigned int)arg6 getError:(id *)arg7;
- (id)getObjectsOfClass:(Class)arg1 fromTable:(id)arg2 onProperties:(const vector_ *)arg3 where:(const struct WCDBConditionBase *)arg4 orderBy:(const struct WCDBConditionBase *)arg5 limit:(unsigned int)arg6;
- (id)getObjectsOfClass:(Class)arg1 fromTable:(id)arg2 where:(const struct WCDBConditionBase *)arg3 orderBy:(const struct WCDBConditionBase *)arg4 limit:(unsigned int)arg5;
- (id)getObjectsOfClass:(Class)arg1 fromTable:(id)arg2 where:(const struct WCDBConditionBase *)arg3 limit:(unsigned int)arg4;
- (id)getObjectsOfClass:(Class)arg1 fromTable:(id)arg2 where:(const struct WCDBConditionBase *)arg3;
- (id)getAllObjectsOfClass:(Class)arg1 fromTable:(id)arg2;
- (id)getOneObjectOfClass:(Class)arg1 fromTable:(id)arg2 onProperties:(const vector_ *)arg3 where:(const struct WCDBConditionBase *)arg4 orderBy:(const struct WCDBConditionBase *)arg5;
- (id)getOneObjectOfClass:(Class)arg1 fromTable:(id)arg2 where:(const struct WCDBConditionBase *)arg3;
- (id)getLastObjectOfClass:(Class)arg1 fromTable:(id)arg2;
- (id)extractOneProperty:(id)arg1 fromSTMT:(struct sqlite3_stmt *)arg2 atIndex:(int)arg3;
- (_Bool)extractObjects:(id)arg1 columnInfo:(id)arg2 fromSTMT:(struct sqlite3_stmt *)arg3;
- (_Bool)excuteSQLNoRet:(const char *)arg1 errCodePrepare:(int *)arg2 errCodeStep:(int *)arg3;
- (_Bool)excuteSQLNoRet:(const char *)arg1;
- (_Bool)_rollbackTransaction:(id)arg1;
- (_Bool)_commitTransaction:(id)arg1;
- (_Bool)_commitTransaction:(id)arg1 error:(id *)arg2;
- (id)_beginTransaction;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1 stateDidChanged:(CDUnknownBlockType)arg2;
- (_Bool)createIndexOnTable:(id)arg1 withIndexArray:(const struct WCDBIndexHelper *)arg2 count:(unsigned long long)arg3;
- (_Bool)createIndexOnTable:(id)arg1 withDummyObj:(id)arg2;
- (void)alterTableIfNeeded:(id)arg1 withProperties:(id)arg2;
- (id)getColumnsFromSchema:(id)arg1;
- (id)getSchemaOfTable:(id)arg1;
- (_Bool)isTableExist:(id)arg1;
- (id)getAllTables;
- (void)autoEmptyTrashTable;
- (void)autoEmptyTrashTableWithDelay:(float)arg1;
- (void)emptyTrashTable;
- (id)getOneTrashTable;
- (id)getAllTrashTables;
- (_Bool)trashTablesOfNames:(id)arg1;
- (_Bool)trashTableOfName:(id)arg1;
- (_Bool)shouldUseTrashOpti;
- (_Bool)dropTableOfName:(id)arg1;
- (_Bool)createTableOfName:(id)arg1 withClass:(Class)arg2;
- (void)generateMultiPrimaryKey:(basic_string_ *)arg1 withClass:(Class)arg2;
- (void)generateTableAttribute:(basic_string_ *)arg1 withClass:(Class)arg2;
- (void)generateTablePrefix:(basic_string_ *)arg1 tableName:(id)arg2 withClass:(Class)arg3;
- (id)usingModule:(id)arg1;
- (id)multiPrimaryKey:(id)arg1;
- (_Bool)isVirtualTable:(id)arg1;
- (id)dicTableHelper:(Class)arg1;
- (id)getTable:(id)arg1 withClass:(Class)arg2;
- (id)extractOneObjectOfClass:(Class)arg1 fromColumn:(struct sqliterk_column *)arg2;
- (void)_forceCloseEnd;
- (void)_forceCloseBegin;
- (void)forceCloseAndPreventOtherThreadsInBlock:(CDUnknownBlockType)arg1;
- (void)forceClose;
- (void)closeAndPreventOtherThreadsInBlock:(CDUnknownBlockType)arg1;
- (_Bool)isOpen;
- (void)configDB:(struct sqlite3 *)arg1;
- (void)onCheckpoint:(int)arg1 withHandle:(struct sqlite3 *)arg2;
- (void)checkpoint;
- (int)checkpointHook:(struct sqlite3 *)arg1 zDb:(const char *)arg2 nFrame:(int)arg3;
- (_Bool)openDB;
- (void)onGenerateNewHandle:(struct sqlite3 *)arg1;
- (unsigned long long)fileSize;
- (id)infoPath;
- (id)dbPaths;
- (void)dealloc;
- (id)initWithPath:(id)arg1 withEncryptKey:(id)arg2;
- (id)initWithPath:(id)arg1 withEncryptKey:(id)arg2 databaseID:(unsigned int)arg3 eventDelegate:(id)arg4;
- (id)initWithPath:(id)arg1 withEncryptKey:(id)arg2 databaseID:(unsigned int)arg3;
- (_Bool)restoreFromSourceDB:(id)arg1 withDelegate:(id)arg2 error:(id *)arg3;
- (id)backupPaths;
- (void)clearBackup;
- (_Bool)backup;
- (id)getRestoreInfos;
- (id)accquireRestoreInfos;
- (id)accquireSortedBackupInfos;
- (_Bool)bindProperty:(id)arg1 toSTMT:(struct sqlite3_stmt *)arg2 forItem:(id)arg3 atIndex:(int)arg4;
- (void)extractOneObject:(id)arg1 fromItem:(id)arg2 index:(int)arg3 STMT:(struct sqlite3_stmt *)arg4;
- (id)extractOneObjectRepeatedOfClass:(Class)arg1 withColumnInfo:(id *)arg2 STMT:(struct sqlite3_stmt *)arg3;
- (id)extractOneObjectOfClass:(Class)arg1 fromSTMT:(struct sqlite3_stmt *)arg2;
- (void)handleEncryptKeyError;
- (_Bool)deleteOneObjectFromFile:(id)arg1;
- (_Bool)loadOneObjectFromFile:(id)arg1;
- (_Bool)saveOneObjectToFile:(id)arg1;
- (id)getPathWithRowID:(const long long *)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface WCDataBaseTable : NSObject
{
    WCDataBase *m_db;
    NSString *m_tableName;
    Class m_tableClass;
}

- (Class)tableClass;
- (id)database;
- (id)tableName;
- (_Bool)deleteObjectsWhere:(const struct WCDBConditionBase *)arg1;
- (_Bool)deleteObject:(id)arg1;
- (_Bool)updateObject:(id)arg1 onProperties:(const vector_ *)arg2 where:(const struct WCDBConditionBase *)arg3;
- (_Bool)updateObject:(id)arg1 onProperties:(const vector_ *)arg2;
- (_Bool)updateProperty:(const struct WCDBConditionBase *)arg1 withValue:(id)arg2 where:(const struct WCDBConditionBase *)arg3;
- (_Bool)insertOrUpdateObjects:(id)arg1 onConflict:(CDUnknownBlockType)arg2;
- (_Bool)insertOrUpdateObject:(id)arg1 onConflict:(CDUnknownBlockType)arg2;
- (_Bool)insertOrUpdateObjects:(id)arg1;
- (_Bool)insertOrUpdateObject:(id)arg1 onProperties:(const vector_ *)arg2;
- (_Bool)insertOrUpdateObject:(id)arg1;
- (_Bool)insertObject:(id)arg1 onProperties:(const vector_ *)arg2 autoIncrement:(_Bool)arg3;
- (_Bool)insertObject:(id)arg1 autoIncrement:(_Bool)arg2;
- (id)getSumProperty:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2;
- (id)getMaxProperty:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2;
- (id)getMaxProperty:(const struct WCDBConditionBase *)arg1;
- (id)getOnePropertyValue:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2 orderBy:(const struct WCDBConditionBase *)arg3;
- (id)getPropertyWithDistinct:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2;
- (id)getProperty:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2 orderBy:(const struct WCDBConditionBase *)arg3 limit:(unsigned int)arg4;
- (id)getProperty:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2 limit:(unsigned int)arg3;
- (id)getProperty:(const struct WCDBConditionBase *)arg1 where:(const struct WCDBConditionBase *)arg2;
- (id)getProperty:(const struct WCDBConditionBase *)arg1;
- (unsigned int)getCountOfDistinctProperty:(const struct WCDBConditionBase *)arg1 Where:(const struct WCDBConditionBase *)arg2;
- (unsigned int)getCountOfObjectsWhere:(const struct WCDBConditionBase *)arg1;
- (unsigned int)getCountOfObjects;
- (id)getObjectsWhere:(const struct WCDBConditionBase *)arg1 onProperties:(const vector_ *)arg2 orderBy:(const struct WCDBConditionBase *)arg3 limit:(unsigned int)arg4 getError:(id *)arg5;
- (id)getObjectsWhere:(const struct WCDBConditionBase *)arg1 onProperties:(const vector_ *)arg2 orderBy:(const struct WCDBConditionBase *)arg3 limit:(unsigned int)arg4;
- (id)getObjectsWhere:(const struct WCDBConditionBase *)arg1 orderBy:(const struct WCDBConditionBase *)arg2 limit:(unsigned int)arg3;
- (id)getObjectsWhere:(const struct WCDBConditionBase *)arg1 limit:(unsigned int)arg2;
- (id)getObjectsWhere:(const struct WCDBConditionBase *)arg1;
- (id)getAllObjects;
- (id)getOneObjectWhere:(const struct WCDBConditionBase *)arg1 onProperties:(const vector_ *)arg2 orderBy:(const struct WCDBConditionBase *)arg3;
- (id)getOneObjectWhere:(const struct WCDBConditionBase *)arg1;
- (id)getLastObject;
- (id)initWithDataBase:(id)arg1 tableName:(id)arg2 objectClass:(Class)arg3;

@end

@interface WXPBGeneratedMessage : NSObject
{
    int _has_bits_[3];
    int _serializedSize;
    struct PBClassInfo *_classInfo;
    id *_ivarValueDict;
}

+ (id)parseFromData:(id)arg1;
- (_Bool)hasProperty:(int)arg1;
- (unsigned int)continueFlag;
- (id)baseResponse;
- (void)setBaseRequest:(id)arg1;
- (void)writeValueToCodedOutputDataNoTag:(struct CodedOutputData *)arg1 value:(id)arg2 fieldType:(unsigned char)arg3;
- (void)writeValueToCodedOutputData:(struct CodedOutputData *)arg1 value:(id)arg2 fieldNumber:(int)arg3 fieldType:(unsigned char)arg4;
- (void)writeToCodedOutputData:(struct CodedOutputData *)arg1;
- (int)computeValueSizeNoTag:(id)arg1 fieldType:(unsigned char)arg2;
- (int)computeValueSize:(id)arg1 fieldNumber:(int)arg2 fieldType:(unsigned char)arg3;
- (int)serializedSize;
- (id)serializedData;
- (_Bool)isInitialized;
- (_Bool)isMessageInitialized:(id)arg1;
- (id)readValueFromCodedInputData:(struct CodedInputData *)arg1 fieldType:(unsigned char)arg2;
- (id)mergeFromCodedInputData:(struct CodedInputData *)arg1;
- (id)mergeFromData:(id)arg1;
- (id)valueAtIndex:(int)arg1;
- (void)setValue:(id)arg1 atIndex:(int)arg2;
- (int)indexOfPropertyWithSetter:(const char *)arg1;
- (int)indexOfPropertyWithGetter:(const char *)arg1;
- (void)dealloc;
- (id)init;

@end

@interface MMTimer : NSObject
{
    _Bool _paused;
    NSTimer *_m_timer;
    NSDate *_pauseStart;
    NSDate *_previousFireDate;
}

+ (id)startTimeCheckWithInterval:(double)arg1 target:(id)arg2 selector:(SEL)arg3;
+ (id)scheduledNoRetainTimerWithTimeInterval:(double)arg1 target:(id)arg2 selector:(SEL)arg3 userInfo:(id)arg4 repeats:(_Bool)arg5;
@property(retain, nonatomic) NSDate *previousFireDate; // @synthesize previousFireDate=_previousFireDate;
@property(retain, nonatomic) NSDate *pauseStart; // @synthesize pauseStart=_pauseStart;
@property(nonatomic) _Bool paused; // @synthesize paused=_paused;
@property(retain, nonatomic) NSTimer *m_timer; // @synthesize m_timer=_m_timer;
- (void)resumeTimer;
- (void)pauseTimer;
- (void)invalidate;
- (void)stopTimeCheck;
- (void)dealloc;

@end

@interface MMService : NSObject
{
    _Bool m_isServiceRemoved;
    _Bool m_isServicePersistent;
}

@property _Bool m_isServicePersistent; // @synthesize m_isServicePersistent;
@property _Bool m_isServiceRemoved; // @synthesize m_isServiceRemoved;

@end

@interface WCDBHandlesPool : NSObject <WCDBHandleWrapProtocol>
{
    WCDBRWLock *m_handleLock;
    NSRecursiveLock *m_poolLock;
    NSString *m_dbPath;
    NSString *m_dbFilePath;
    unsigned int m_dataBaseId;
    long long m_lastStaticticsTime;
    id <WCDBHandlesPoolProtocol> _m_delegate;
}

@property __weak id <WCDBHandlesPoolProtocol> m_delegate; // @synthesize m_delegate=_m_delegate;
@property(readonly, nonatomic) unsigned int m_dataBaseId; // @synthesize m_dataBaseId;
- (void)reportStaticticsMultiThread;
- (void)staticticsMultiThread:(id)arg1;
- (void)handleWrapWillEnd:(id)arg1;
- (void)forceCloseEnd;
- (void)forceCloseBegin;
- (void)forceCloseAndPreventOtherThreadsInBlock:(CDUnknownBlockType)arg1;
- (_Bool)isOpen;
- (struct WCDBScopedHandle)scopedHandle;
- (_Bool)generateHandle;
- (void)dealloc;
- (id)initWithPath:(id)arg1 filePath:(id)arg2 dataBaseId:(unsigned int)arg3 delegate:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface WCDBCorruptReport : NSObject
{
    _Bool m_hasDirectReport;
    unsigned int m_corruptNum;
}

@property _Bool m_hasDirectReport; // @synthesize m_hasDirectReport;
@property unsigned int m_corruptNum; // @synthesize m_corruptNum;
- (void)reportCorruptOnMainThread:(id)arg1;
- (void)ClearCorruptNumWithDBID:(unsigned int)arg1;
- (void)DirectReportCorruptWithDBID:(unsigned int)arg1 dbObject:(id)arg2 dbPath:(id)arg3 errorCode:(unsigned int)arg4 important:(_Bool)arg5;
- (void)RecordCorruptWithDBID:(unsigned int)arg1 dbObject:(id)arg2 dbPath:(id)arg3 errorCode:(unsigned int)arg4 important:(_Bool)arg5;

@end

@interface WCDBHandleWrap : NSObject
{
    NSThread *m_usedThread;
    struct sqlite3 *m_handle;
    id <WCDBHandleWrapProtocol> m_delegate;
    unsigned long long m_status;
    int m_threadedRetainCount;
    NSError *_error;
}

@property(retain, nonatomic) NSError *error; // @synthesize error=_error;
- (void)resetStatus;
- (void)updateStatus:(unsigned long long)arg1;
@property(readonly, nonatomic) unsigned long long status;
- (void)releaseAtCurrentThread;
- (void)retainAtCurrentThread;
- (void)reset;
@property(readonly, nonatomic) __weak NSThread *usedThread;
@property(readonly, nonatomic) struct sqlite3 *handle;
- (id)initWithHandle:(struct sqlite3 *)arg1 andDelegate:(id)arg2;

@end

@interface GiftCardItem : MMObject <PBCoding, NSCopying>
{
    unsigned int bizUin;
    NSString *orderId;
    NSString *_appName;
    NSString *_recvDigest;
    NSString *_sendDigest;
    NSString *_backgroundPicUrl;
    NSString *_titleColorStr;
    NSString *_descColorStr;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *descColorStr; // @synthesize descColorStr=_descColorStr;
@property(retain, nonatomic) NSString *titleColorStr; // @synthesize titleColorStr=_titleColorStr;
@property(retain, nonatomic) NSString *backgroundPicUrl; // @synthesize backgroundPicUrl=_backgroundPicUrl;
@property(retain, nonatomic) NSString *sendDigest; // @synthesize sendDigest=_sendDigest;
@property(retain, nonatomic) NSString *recvDigest; // @synthesize recvDigest=_recvDigest;
@property(retain, nonatomic) NSString *appName; // @synthesize appName=_appName;
@property(retain, nonatomic) NSString *orderId; // @synthesize orderId;
@property(nonatomic) unsigned int bizUin; // @synthesize bizUin;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)init;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface MMWCPushInfo : MMObject <WCDBCoding>
{
    _Bool finishDownload;
    unsigned int pushId;
    unsigned int subType;
    unsigned int networkType;
    unsigned int scene;
    unsigned int expireTime;
    NSString *appId;
    NSString *base;
    NSArray *resUrls;
    NSString *packageId;
    NSString *domain;
    NSString *bizId;
    long long m___rowID;
}

+ (id)parseCacheNode:(struct XmlReaderNode_t *)arg1;
+ (id)parseString:(const char *)arg1;
+ (unsigned int)parseSubType:(const char *)arg1;
+ (unsigned int)parseExpireTime:(const char *)arg1;
+ (unsigned int)parseNetType:(const char *)arg1;
+ (unsigned int)parseUInt32:(const char *)arg1;
+ (const basic_string_ *)getWCDBPrimaryColumnName;
+ (const struct WCDBIndexHelper *)getWCDBIndexArray;
+ (unsigned long long)getWCDBIndexArrayCount;
+ (const map_ *)getFileValueTagIndexMap;
+ (id)getFileValueTypeTable;
+ (const map_ *)getPackedValueTagIndexMap;
+ (id)getPackedValueTypeTable;
+ (const map_ *)getValueNameIndexMap;
+ (id)getValueTable;
+ (id)dummyObject;
@property(nonatomic) long long __rowID; // @synthesize __rowID=m___rowID;
@property(nonatomic) _Bool finishDownload; // @synthesize finishDownload;
@property(retain, nonatomic) NSString *bizId; // @synthesize bizId;
@property(retain, nonatomic) NSString *domain; // @synthesize domain;
@property(retain, nonatomic) NSString *packageId; // @synthesize packageId;
@property(retain, nonatomic) NSArray *resUrls; // @synthesize resUrls;
@property(retain, nonatomic) NSString *base; // @synthesize base;
@property(retain, nonatomic) NSString *appId; // @synthesize appId;
@property(nonatomic) unsigned int expireTime; // @synthesize expireTime;
@property(nonatomic) unsigned int scene; // @synthesize scene;
@property(nonatomic) unsigned int networkType; // @synthesize networkType;
@property(nonatomic) unsigned int subType; // @synthesize subType;
@property(nonatomic) unsigned int pushId; // @synthesize pushId;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface WCRedEnvelopesLogicMgr : MMService <WCRedEnvelopesNetworkHelperDelegate>
{
    WCRedEnvelopesNetworkHelper *m_networkHelper;
    ContactUpdateHelper *_m_senderNickNameHelper;
}

@property(retain, nonatomic) ContactUpdateHelper *m_senderNickNameHelper; // @synthesize m_senderNickNameHelper=_m_senderNickNameHelper;
- (void)AsyncBizSubcribeRequest:(id)arg1;
- (void)CheckAuthBizEnterpriseRedEnvelopesRequest:(id)arg1;
- (void)OpenBizEnterpriseRedEnvelopesRequest:(id)arg1;
- (void)ReceiveBizEnterpriseRedEnvelopesRequest:(id)arg1;
- (void)OpenEnterpriseRedEnvelopesRequest:(id)arg1 SendKey:(id)arg2 ShouldSubscribe:(_Bool)arg3;
- (void)ThanksForRedEnvelopesRequest:(id)arg1;
- (void)ClearserSendOrReceiveRedEnveloperListRequest:(id)arg1;
- (void)DeleteRedEnvelopesRecord:(id)arg1;
- (void)QueryUserSendOrReceiveRedEnveloperListRequest:(id)arg1;
- (void)QueryRedEnvelopesDetailRequest:(id)arg1;
- (void)OpenRedEnvelopesRequest:(id)arg1;
- (void)ReceiverQueryRedEnvelopesRequest:(id)arg1;
- (void)SendShareRedEnvelopesoRequest:(id)arg1;
- (void)GenYearRedEnvelopesPayRequest:(id)arg1;
- (void)GenH5RedEnvelopesPayRequest:(id)arg1;
- (void)GenRedEnvelopesPayRequest:(id)arg1;
- (void)QueryRedEnvelopesUserInfoNoCache:(id)arg1;
- (void)QueryRedEnvelopesUserInfo:(id)arg1;
- (void)GetEnterpriseHongbaoBizRequest:(id)arg1 CMDID:(unsigned int)arg2 SendKey:(id)arg3 OutputType:(unsigned int)arg4;
- (void)GetEnterpriseHongbaoBusinessRequest:(id)arg1 CMDID:(unsigned int)arg2 SendKey:(id)arg3 OutputType:(unsigned int)arg4 ShouldSubscribe:(_Bool)arg5;
- (void)GetYearHongbaoRequest:(id)arg1 CMDID:(unsigned int)arg2 OutputType:(unsigned int)arg3;
- (void)GetHongbaoBusinessRequest:(id)arg1 CMDID:(unsigned int)arg2 OutputType:(unsigned int)arg3;
- (void)OnWCToAsyncBizSubscribeResponse:(id)arg1 Request:(id)arg2;
- (void)OnWCToBizHBCommonResponse:(id)arg1 Request:(id)arg2;
- (void)OnWCToBizHBCommonSystemErrorResponse:(id)arg1 Request:(id)arg2;
- (void)OnWCToBizHBCommonErrorResponse:(id)arg1 Request:(id)arg2;
- (void)OnWCToEnterpriseHBCommonResponse:(id)arg1 Request:(id)arg2;
- (void)OnWCToEnterpriseHBCommonSystemErrorResponse:(id)arg1 Request:(id)arg2;
- (void)OnWCToEnterpriseHBCommonErrorResponse:(id)arg1 Request:(id)arg2;
- (void)addReceiveSystemMsgWithDic:(id)arg1;
- (void)OnWCToHongbaoCommonResponse:(id)arg1 Request:(id)arg2;
- (void)OnWCToHongbaoCommonErrorResponse:(id)arg1 Request:(id)arg2;
- (void)OnWCToHongbaoCommonSystemErrorResponse:(id)arg1 Request:(id)arg2;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface ContactUpdateHelper : NSObject <IStrangerContactMgrExt>
{
    NSString *_m_moduleName;
    NSString *_m_userName;
    CDUnknownBlockType _m_block;
}

@property(copy, nonatomic) CDUnknownBlockType m_block; // @synthesize m_block=_m_block;
@property(retain, nonatomic) NSString *m_userName; // @synthesize m_userName=_m_userName;
@property(retain, nonatomic) NSString *m_moduleName; // @synthesize m_moduleName=_m_moduleName;
- (void)onStrangerContactUpdateForbidden:(id)arg1;
- (void)onStrangerContactUpdated:(id)arg1 Contact:(id)arg2;
- (void)clearBlock;
- (void)updateStangerContact;
- (_Bool)strangerContactToBlock;
- (_Bool)normalContactToBlock;
- (void)startWithUserName:(id)arg1 onUpdate:(CDUnknownBlockType)arg2;
- (id)initWithModuleName:(id)arg1;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface WCRedEnvelopesNetworkHelper : MMObject <PBMessageObserverDelegate>
{
    id <WCRedEnvelopesNetworkHelperDelegate> m_delegate;
    NSMutableDictionary *m_dicCGIStartedTime;
}

+ (void)idkeyCmdReport:(unsigned int)arg1 keyName:(id)arg2 value:(unsigned int)arg3;
+ (void)idkeyCmdReport:(unsigned int)arg1 keyName:(id)arg2;
+ (void)initialize;
@property(nonatomic) __weak id <WCRedEnvelopesNetworkHelperDelegate> m_delegate; // @synthesize m_delegate;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)MessageReturnOnAsyncBizSubScribe:(id)arg1 Event:(unsigned int)arg2;
- (void)MessageReturnOnCommonBizHongbao:(id)arg1 Event:(unsigned int)arg2;
- (void)MessageReturnOnEnterpriseHongbao:(id)arg1 Event:(unsigned int)arg2;
- (void)MessageReturnOnHongbao:(id)arg1 Event:(unsigned int)arg2;
- (void)WCToAsyncBizSubcribeReq:(id)arg1;
- (void)WCToEnterpriseCommonBizReq:(id)arg1;
- (void)WCToEnterpriseHBBizReq:(id)arg1;
- (void)WCToYearHongbaoRequest:(id)arg1;
- (void)WCToHongbaoCommonRequest:(id)arg1;
- (void)dealloc;
- (id)init;

@end

@interface RecoverDataItem : NSObject
{
    unsigned int m_dataType;
    unsigned int m_operationType;
    NSString *m_nsDescription;
    NSString *m_nsPath;
}

@property(retain, nonatomic) NSString *m_nsPath; // @synthesize m_nsPath;
@property(nonatomic) unsigned int m_operationType; // @synthesize m_operationType;
@property(nonatomic) unsigned int m_dataType; // @synthesize m_dataType;
@property(retain, nonatomic) NSString *m_nsDescription; // @synthesize m_nsDescription;
- (id)description;
- (id)init;

@end

@interface PushMailWrap : NSObject <NSCopying>
{
    NSString *nsSender;
    NSString *nsSenderAddress;
    NSString *nsSubject;
    NSString *nsDigest;
    NSString *nsDate;
    NSString *nsWapLink;
    NSString *nsMailID;
    NSString *nsAccount;
    NSString *nsArgs;
    unsigned long long uiUin;
    _Bool bHasAttachment;
    NSMutableArray *arrToList;
    NSMutableArray *arrCCList;
}

@property(retain, nonatomic) NSMutableArray *arrCCList; // @synthesize arrCCList;
@property(retain, nonatomic) NSMutableArray *arrToList; // @synthesize arrToList;
@property(nonatomic) unsigned long long uiUin; // @synthesize uiUin;
@property(nonatomic) _Bool bHasAttachment; // @synthesize bHasAttachment;
@property(retain, nonatomic) NSString *nsArgs; // @synthesize nsArgs;
@property(retain, nonatomic) NSString *nsAccount; // @synthesize nsAccount;
@property(retain, nonatomic) NSString *nsMailID; // @synthesize nsMailID;
@property(retain, nonatomic) NSString *nsWapLink; // @synthesize nsWapLink;
@property(retain, nonatomic) NSString *nsDate; // @synthesize nsDate;
@property(retain, nonatomic) NSString *nsDigest; // @synthesize nsDigest;
@property(retain, nonatomic) NSString *nsSubject; // @synthesize nsSubject;
@property(retain, nonatomic) NSString *nsSenderAddress; // @synthesize nsSenderAddress;
@property(retain, nonatomic) NSString *nsSender; // @synthesize nsSender;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)init;

@end

@interface FavLocationItem : NSObject
{
    double _lng;
    double _lat;
    double _scale;
    NSString *_label;
    NSString *_poiname;
}

@property(retain, nonatomic) NSString *poiname; // @synthesize poiname=_poiname;
@property(retain, nonatomic) NSString *label; // @synthesize label=_label;
@property(nonatomic) double scale; // @synthesize scale=_scale;
@property(nonatomic) double lat; // @synthesize lat=_lat;
@property(nonatomic) double lng; // @synthesize lng=_lng;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)init;

@end

@interface FavURLItem : NSObject
{
    NSString *_title;
    NSString *_description;
    NSString *_cleanUrl;
    NSString *_thumbUrl;
    int _openCache;
    unsigned int _contentAttributeBitSetFlag;
    NSString *_canvasInfoXml;
}

@property(retain, nonatomic) NSString *canvasInfoXml; // @synthesize canvasInfoXml=_canvasInfoXml;
@property(nonatomic) unsigned int contentAttributeBitSetFlag; // @synthesize contentAttributeBitSetFlag=_contentAttributeBitSetFlag;
@property(nonatomic) int openCache; // @synthesize openCache=_openCache;
@property(retain, nonatomic) NSString *thumbUrl; // @synthesize thumbUrl=_thumbUrl;
@property(retain, nonatomic) NSString *cleanUrl; // @synthesize cleanUrl=_cleanUrl;
@property(retain, nonatomic) NSString *description; // @synthesize description=_description;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
- (void)setContentOriginal:(_Bool)arg1;
- (_Bool)isContentOriginal;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)init;

@end

@interface FavProductItem : NSObject
{
    NSString *_title;
    NSString *_description;
    NSString *_thumbUrl;
    NSString *_info;
    NSString *_sellerName;
    NSString *_productUrl;
}

@property(retain, nonatomic) NSString *productUrl; // @synthesize productUrl=_productUrl;
@property(retain, nonatomic) NSString *sellerName; // @synthesize sellerName=_sellerName;
@property(retain, nonatomic) NSString *info; // @synthesize info=_info;
@property(retain, nonatomic) NSString *thumbUrl; // @synthesize thumbUrl=_thumbUrl;
@property(retain, nonatomic) NSString *description; // @synthesize description=_description;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)init;

@end

@interface FavTVItem : NSObject
{
    NSString *_title;
    NSString *_description;
    NSString *_thumbUrl;
    NSString *_info;
}

@property(retain, nonatomic) NSString *info; // @synthesize info=_info;
@property(retain, nonatomic) NSString *thumbUrl; // @synthesize thumbUrl=_thumbUrl;
@property(retain, nonatomic) NSString *description; // @synthesize description=_description;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)init;

@end

@interface FavWeAppItem : NSObject
{
    NSString *_appUserName;
    NSString *_title;
    NSString *_desc;
    NSString *_thumbUrl;
    NSString *_pagePath;
    unsigned int _debugMode;
}

@property(nonatomic) unsigned int debugMode; // @synthesize debugMode=_debugMode;
@property(retain, nonatomic) NSString *pagePath; // @synthesize pagePath=_pagePath;
@property(retain, nonatomic) NSString *thumbUrl; // @synthesize thumbUrl=_thumbUrl;
@property(retain, nonatomic) NSString *desc; // @synthesize desc=_desc;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) NSString *appUserName; // @synthesize appUserName=_appUserName;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end

@interface FavoritesItem : NSObject <NSCoding>
{
    unsigned int _favId;
    int _type;
    int _status;
    unsigned int _updateSeq;
    unsigned int _localUpdateSeq;
    unsigned int _updateTime;
    int _sourceType;
    unsigned int _editTime;
    NSString *_title;
    NSString *_description;
    NSString *_link;
    unsigned int _ctrlFlag;
    NSString *_sourceId;
    NSString *_fromUsr;
    NSString *_toUsr;
    NSString *_realChatName;
    long long _n64MsgID;
    NSString *_eventId;
    NSString *_appId;
    unsigned int _srcCreateTime;
    NSString *_brandId;
    NSMutableArray *_dataList;
    unsigned int _totalDataSize;
    FavLocationItem *_locItem;
    FavURLItem *_urlItem;
    FavProductItem *_productItem;
    FavTVItem *_tvItem;
    NSString *_remark;
    unsigned int _remarkTime;
    FavWeAppItem *_weAppItem;
    NSMutableArray *_tagList;
    NSMutableArray *_recommendTagList;
    unsigned int m_uiFromScene;
    NSString *m_nsFavUsername;
    unsigned int m_preMsgIndex;
    int _localStatus;
    unsigned int _localId;
    int _countMd5Status;
    int _retryTimes;
    NSDate *_startUploadTime;
    double _cellHeight;
    unsigned long long _sightLegalityType;
    _Bool _isFromFavToChat;
    unsigned int _version;
    NSString *_deviceid;
}

+ (id)xmlOfStreamVideo:(id)arg1;
+ (void)parseStreamVideoNode:(struct XmlReaderNode_t *)arg1 dataField:(id)arg2;
+ (id)FavritesItemToXML:(id)arg1;
+ (id)replacePathPrefix:(id)arg1;
+ (id)parseTagXml:(struct XmlReaderNode_t *)arg1;
+ (_Bool)ParseItemXML:(id)arg1 ToItem:(id)arg2;
@property(nonatomic) _Bool isFromFavToChat; // @synthesize isFromFavToChat=_isFromFavToChat;
@property(retain, nonatomic) NSString *deviceid; // @synthesize deviceid=_deviceid;
@property(nonatomic) unsigned int version; // @synthesize version=_version;
@property(nonatomic) unsigned int m_preMsgIndex; // @synthesize m_preMsgIndex;
@property(retain, nonatomic) NSString *m_nsFavUsername; // @synthesize m_nsFavUsername;
@property(nonatomic) unsigned int m_uiFromScene; // @synthesize m_uiFromScene;
@property(nonatomic) double cellHeight; // @synthesize cellHeight=_cellHeight;
@property(retain, nonatomic) NSDate *startUploadTime; // @synthesize startUploadTime=_startUploadTime;
@property(nonatomic) int retryTimes; // @synthesize retryTimes=_retryTimes;
@property(nonatomic) int countMd5Status; // @synthesize countMd5Status=_countMd5Status;
@property(nonatomic) unsigned int localId; // @synthesize localId=_localId;
@property(nonatomic) int localStatus; // @synthesize localStatus=_localStatus;
@property(retain, nonatomic) NSArray *recommendTagList; // @synthesize recommendTagList=_recommendTagList;
@property(retain, nonatomic) NSArray *tagList; // @synthesize tagList=_tagList;
@property(nonatomic) unsigned int remarkTime; // @synthesize remarkTime=_remarkTime;
@property(retain, nonatomic) NSString *remark; // @synthesize remark=_remark;
@property(retain, nonatomic) FavWeAppItem *weAppItem; // @synthesize weAppItem=_weAppItem;
@property(retain, nonatomic) FavTVItem *tvItem; // @synthesize tvItem=_tvItem;
@property(retain, nonatomic) FavProductItem *productItem; // @synthesize productItem=_productItem;
@property(retain, nonatomic) FavURLItem *urlItem; // @synthesize urlItem=_urlItem;
@property(retain, nonatomic) FavLocationItem *locItem; // @synthesize locItem=_locItem;
@property(nonatomic) unsigned int totalDataSize; // @synthesize totalDataSize=_totalDataSize;
@property(retain, nonatomic) NSArray *dataList; // @synthesize dataList=_dataList;
@property(retain, nonatomic) NSString *brandId; // @synthesize brandId=_brandId;
@property(nonatomic) unsigned int srcCreateTime; // @synthesize srcCreateTime=_srcCreateTime;
@property(retain, nonatomic) NSString *appId; // @synthesize appId=_appId;
@property(retain, nonatomic) NSString *eventId; // @synthesize eventId=_eventId;
@property(nonatomic) long long n64MsgID; // @synthesize n64MsgID=_n64MsgID;
@property(retain, nonatomic) NSString *realChatName; // @synthesize realChatName=_realChatName;
@property(retain, nonatomic) NSString *toUsr; // @synthesize toUsr=_toUsr;
@property(retain, nonatomic) NSString *fromUsr; // @synthesize fromUsr=_fromUsr;
@property(retain, nonatomic) NSString *sourceId; // @synthesize sourceId=_sourceId;
@property(nonatomic) unsigned int ctrlFlag; // @synthesize ctrlFlag=_ctrlFlag;
@property(retain, nonatomic) NSString *link; // @synthesize link=_link;
@property(retain, nonatomic) NSString *description; // @synthesize description=_description;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
@property(nonatomic) unsigned int editTime; // @synthesize editTime=_editTime;
@property(nonatomic) int sourceType; // @synthesize sourceType=_sourceType;
@property(nonatomic) unsigned int localUpdateSeq; // @synthesize localUpdateSeq=_localUpdateSeq;
@property(nonatomic) unsigned int updateSeq; // @synthesize updateSeq=_updateSeq;
@property(nonatomic) int status; // @synthesize status=_status;
@property(nonatomic) unsigned int updateTime; // @synthesize updateTime=_updateTime;
@property(nonatomic) int type; // @synthesize type=_type;
@property(nonatomic) unsigned int favId; // @synthesize favId=_favId;
- (_Bool)containsIllegalData;
- (_Bool)needBatchGet;
- (_Bool)canBeForward;
- (_Bool)checkSightLegality;
- (id)canBeForwardWithMsg;
- (id)getFirstMediaData;
- (_Bool)isRecordItem;
- (id)getFavDataWrapByLocalDataID:(id)arg1;
- (id)getDataWraps;
- (_Bool)hasCDNData;
- (unsigned int)itemServerSize;
- (unsigned int)itemTotalSize;
- (_Bool)canAutoDownload;
- (_Bool)canAutoUpload;
- (void)changeToFavSearchItem:(id)arg1;
- (id)changeToFavSearchString;
- (_Bool)dataHasBeenCopyedToTarget;
- (void)addData:(id)arg1 Index:(int)arg2;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithAddFavItem:(id)arg1;
- (id)init;

@end

@interface MMAsset : MMObject <NSCopying>
{
    _Bool _m_isNeedOriginImage;
    _Bool _m_isFailedFromIcloud;
    _Bool _m_isLoadingFromIcloud;
    int _sourceForSNSUploadStat;
}

+ (_Bool)isAsset:(id)arg1 CreateWithInSecond:(double)arg2;
+ (struct CGSize)LongImageSizeWithTargetEdge:(double)arg1 originSize:(struct CGSize)arg2;
+ (id)decodeXmlString:(id)arg1;
@property(nonatomic) int sourceForSNSUploadStat; // @synthesize sourceForSNSUploadStat=_sourceForSNSUploadStat;
@property(nonatomic) _Bool m_isLoadingFromIcloud; // @synthesize m_isLoadingFromIcloud=_m_isLoadingFromIcloud;
@property(nonatomic) _Bool m_isFailedFromIcloud; // @synthesize m_isFailedFromIcloud=_m_isFailedFromIcloud;
@property(nonatomic) _Bool m_isNeedOriginImage; // @synthesize m_isNeedOriginImage=_m_isNeedOriginImage;
- (_Bool)getIsEdited;
- (id)getDrawLayerArray;
- (void)setEditedImage:(id)arg1 withDrawLayer:(id)arg2 withEdited:(_Bool)arg3;
- (void)asyncGetMetadata:(CDUnknownBlockType)arg1;
- (void)stopGetBigImageICloudActivity;
- (void)stopICloudActivity;
- (struct CGSize)getImageRatioSize;
- (id)getCreatedDate;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)asyncGetVideoFileSizeWithBlock:(CDUnknownBlockType)arg1;
- (void)asyncGetVideoAssetWithBlock:(CDUnknownBlockType)arg1;
- (id)getVideoUrl;
- (void)getVideoDurationForDisplayWithCompletion:(CDUnknownBlockType)arg1;
- (id)videoDuration;
- (_Bool)isTimeLapseVideo;
- (_Bool)isSlowMotionVideo;
- (_Bool)isVideo;
- (id)getOriginImageDataSize;
- (_Bool)isGif;
- (_Bool)isPicture;
- (id)encodeXmlString;
- (double)longitude;
- (double)latitude;
- (_Bool)hasLocation;
- (id)alAssetReferenceUrl;
- (id)assetUrl;
- (void)asyncGetAspectRatioThumbnailWithTargetSize:(struct CGSize)arg1 andResult:(CDUnknownBlockType)arg2;
- (void)asyncGetThumbnail:(CDUnknownBlockType)arg1;
- (id)getThumbnail;
- (id)getThumbImage;
- (void)getDisplayImageWithCompressConfig:(id)arg1 ResultBlock:(CDUnknownBlockType)arg2 ErrorBlock:(CDUnknownBlockType)arg3;
- (void)getBigImageWithCompressConfig:(id)arg1 ProcessBlock:(CDUnknownBlockType)arg2 ResultBlock:(CDUnknownBlockType)arg3 ErrorBlock:(CDUnknownBlockType)arg4;
- (id)initWithUrl:(id)arg1 IsNeedOrigin:(_Bool)arg2;

@end

@interface CContactDB : NSObject
{
    CMMDB *m_oMMDB;
}

- (_Bool)SetFriendMetaFlag:(unsigned int)arg1 ForUser:(id)arg2;
- (_Bool)SetLastUpdateTime:(unsigned int)arg1 ForUser:(id)arg2;
- (void)getContactQueryProperty:(vector_ *)arg1;
- (_Bool)isFriendExtTableExist:(id)arg1;
- (void)getFriendExtTableValue:(id)arg1 fromDBObject:(id)arg2;
- (void)getFriendTableValue:(id)arg1 fromDBObject:(id)arg2;
- (unsigned int)GetFriendMetaFlag:(id)arg1;
- (unsigned int)GetLastUpdateTimeOfUser:(id)arg1;
- (_Bool)updateContact:(id)arg1;
- (_Bool)deleteContact:(id)arg1;
- (_Bool)addContact:(id)arg1;
- (_Bool)getAllRemarkList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllUserName:(id)arg1;
- (_Bool)getAllContactNoExtInfoList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllContactList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getContactList:(id)arg1 listType:(unsigned int)arg2 limit:(unsigned int)arg3;
- (unsigned int)getContactCount;
- (void)getFriendAndExtTableValue:(id)arg1 fromDBContact:(id)arg2 DBContactExt:(id)arg3;
- (_Bool)loadContactExtInfo:(id)arg1;
- (id)getContact:(id)arg1;
- (_Bool)updateContactKeyExtInfo:(id)arg1;
- (_Bool)modifyFriendExtTable:(id)arg1;
- (_Bool)modifyFriendTable:(id)arg1;
- (_Bool)addFriendExtTable:(id)arg1;
- (_Bool)addFriendTable:(id)arg1;
- (void)saveUserImage:(id)arg1;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1 stateDidChanged:(CDUnknownBlockType)arg2;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1;
- (void)initDB:(id)arg1;
- (id)init;

@end

@interface CContactOPLog : NSObject
{
    NSMutableDictionary *m_dicSkipContacts;
}

+ (unsigned int)start_ModifyContact:(id)arg1;
+ (id)getModifyContactData:(id)arg1 addScene:(unsigned int)arg2 delScene:(unsigned int)arg3;
- (_Bool)add_ModifyNotifyStatus:(id)arg1 withStatus:(unsigned int)arg2 NeedSync:(_Bool)arg3;
- (_Bool)add_DeleteChatMsg:(id)arg1 sync:(_Bool)arg2;
- (_Bool)add_DeleteChatContact:(id)arg1 sync:(_Bool)arg2;
- (_Bool)add_ModifyContact:(id)arg1 delScene:(unsigned int)arg2 sync:(_Bool)arg3;
- (_Bool)add_ModifyContact:(id)arg1 addScene:(unsigned int)arg2 sync:(_Bool)arg3;
- (_Bool)add_ModifyContact:(id)arg1 sync:(_Bool)arg2;
- (_Bool)add_ModifyContact:(id)arg1 addScene:(unsigned int)arg2 delScene:(unsigned int)arg3 sync:(_Bool)arg4;
- (_Bool)isSkipContact:(id)arg1;
- (void)add_SkipContact:(id)arg1;
- (id)init;

@end

@interface CMessageWrap : MMObject <IAppMsgPathMgr, ISysNewXmlMsgExtendOperation, IMsgExtendOperation, NSCopying>
{
    _Bool m_bIsSplit;
    _Bool m_bNew;
    unsigned int m_uiMesLocalID;
    long long m_n64MesSvrID;
    NSString *m_nsFromUsr;
    NSString *m_nsToUsr;
    unsigned int m_uiMessageType;
    NSString *m_nsContent;
    unsigned int m_uiStatus;
    unsigned int m_uiImgStatus;
    unsigned int m_uiMsgFlag;
    unsigned int m_uiCreateTime;
    NSString *m_nsPushContent;
    NSString *m_nsMsgSource;
    NSString *m_nsRealChatUsr;
    NSData *m_dtThumbnail;
    unsigned int m_uiSendTime;
    unsigned int m_uiEmojiStatFlag;
    NSString *m_nsPattern;
    _Bool m_bForward;
    _Bool m_bCdnForward;
    unsigned int m_uiPercent;
    unsigned int m_uiDownloadStatus;
    id <IMsgExtendOperation> m_extendInfoWithMsgTypeForBiz;
    id <IMsgExtendOperation> m_extendInfoWithMsgType;
    id <IMsgExtendOperation> m_extendInfoWithFromUsr;
    NSString *m_nsLastDisplayContent;
    _Bool m_isTempSessionMsg;
    _Bool m_isEnterpriseMsg;
    unsigned int m_sequenceId;
    _Bool m_bIsFromBrandSession;
    _Bool m_bIsBrandSendMass;
    unsigned int m_uiBizChatVer;
    unsigned int _m_forwardType;
    NSString *m_nsKFWorkerOpenID;
    NSString *m_nsBizClientMsgID;
    NSString *m_nsBizChatId;
    NSString *m_nsAtUserList;
    unsigned long long watchMsgSourceType;
    NSString *m_nsDisplayName;
    NSMutableDictionary *_m_dicForwardParas;
}

+ (id)createMaskedThumbImageForMessageWrap:(id)arg1;
+ (id)GetCdnDownloadPathOfMsgThumb:(id)arg1;
+ (id)GetTempPathOfMesShortVideoWithMessageWrap:(id)arg1;
+ (id)GetPathOfMesVideoWithMessageWrap:(id)arg1;
+ (id)getMaskedVideoMsgImgThumb:(id)arg1;
+ (id)getMaskedMsgImgThumb:(id)arg1;
+ (id)getMsgImgThumb:(id)arg1;
+ (id)getPathOfVideoMsgImgThumb:(id)arg1;
+ (id)GetPathOfMaskedSquareMesImgThumbDir;
+ (id)GetPathOfMaskedSquareMesImgThumbDir:(id)arg1;
+ (id)GetPathOfSquareMesImgThumb:(id)arg1;
+ (id)getPathOfMaskedVideoMsgImgThumb:(id)arg1;
+ (id)getPathOfMaskedMsgImgThumb:(id)arg1;
+ (id)getPathOfMessageImageCache;
+ (id)getOldPathOfMessageImageCache;
+ (id)getPathOfMiddleImgForSender:(id)arg1;
+ (id)getPathOfMsgImgThumb:(id)arg1;
+ (id)getMsgMiddleImgData:(id)arg1;
+ (id)getMsgMiddleImg:(id)arg1;
+ (id)getMsgImgData:(id)arg1;
+ (id)getMsgImg:(id)arg1;
+ (id)getPathOfMsgImg:(id)arg1;
+ (id)getMsgHDImgData:(id)arg1;
+ (id)getJpgPathOfMsgImg:(id)arg1;
+ (_Bool)isVcodec2Img:(id)arg1;
+ (_Bool)MsgImgExist:(id)arg1;
+ (id)getJpgPathOfMsgHDImg:(id)arg1;
+ (_Bool)MsgHDImgExist:(id)arg1;
+ (id)getMsgHDImg:(id)arg1;
+ (id)getPathOfMsgVcodec2HDImg:(id)arg1;
+ (id)getPathOfMsgVcodec2Img:(id)arg1;
+ (id)getUserNameFromMsgWrap:(id)arg1;
+ (_Bool)isSenderFromMsgWrap:(id)arg1;
+ (_Bool)IsRecordMsg:(id)arg1;
+ (_Bool)SaveMesImg:(id)arg1 MsgWrap:(id)arg2;
+ (_Bool)SaveMsgThumbWithMsgWrap:(id)arg1;
+ (void)clearLocalMaskedThumbImage:(id)arg1;
+ (void)clearLocalImage:(id)arg1;
+ (id)FormMessageWrapFromAddMsg:(id)arg1;
+ (id)FormMessageWrapFromBuffer:(id)arg1;
+ (void)initialize;
+ (void)GetPathOfAppRemindAttach:(id)arg1 retStrPath:(id *)arg2;
+ (void)GetPathOfAppThumb:(id)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfMaskedAppThumb:(id)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfAppDataTemp:(id)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfAppDataTemp:(id)arg1 LocalID:(unsigned int)arg2 AttachId:(id)arg3 retStrPath:(id *)arg4;
+ (void)GetPathOfAppDataByUserName:(id)arg1 andMessageWrap:(id)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfAppDataByUserName:(id)arg1 andMessageWrap:(id)arg2 andAttachId:(id)arg3 andAttachFileExt:(id)arg4 retStrPath:(id *)arg5;
+ (void)GetPathOfAppData:(id)arg1 LocalID:(unsigned int)arg2 FileExt:(id)arg3 retStrPath:(id *)arg4;
+ (void)GetPathOfAppImgCacheDir:(id)arg1 retStrPath:(id *)arg2;
+ (void)GetPathOfAppDir:(id)arg1 retStrPath:(id *)arg2;
+ (id)getMessageListStatusImage:(unsigned int)arg1;
@property(retain, nonatomic) NSMutableDictionary *m_dicForwardParas; // @synthesize m_dicForwardParas=_m_dicForwardParas;
@property(nonatomic) unsigned int m_forwardType; // @synthesize m_forwardType=_m_forwardType;
@property(nonatomic) _Bool m_bIsBrandSendMass; // @synthesize m_bIsBrandSendMass;
@property(nonatomic) _Bool m_bIsFromBrandSession; // @synthesize m_bIsFromBrandSession;
@property(retain, nonatomic) NSString *m_nsDisplayName; // @synthesize m_nsDisplayName;
@property(nonatomic) unsigned int m_sequenceId; // @synthesize m_sequenceId;
@property(nonatomic) _Bool m_isEnterpriseMsg; // @synthesize m_isEnterpriseMsg;
@property(nonatomic) _Bool m_isTempSessionMsg; // @synthesize m_isTempSessionMsg;
@property(nonatomic) unsigned long long watchMsgSourceType; // @synthesize watchMsgSourceType;
@property(retain, nonatomic) NSString *m_nsAtUserList; // @synthesize m_nsAtUserList;
@property(nonatomic) unsigned int m_uiBizChatVer; // @synthesize m_uiBizChatVer;
@property(retain, nonatomic) NSString *m_nsBizChatId; // @synthesize m_nsBizChatId;
@property(retain, nonatomic) NSString *m_nsBizClientMsgID; // @synthesize m_nsBizClientMsgID;
@property(retain, nonatomic) NSString *m_nsKFWorkerOpenID; // @synthesize m_nsKFWorkerOpenID;
@property(nonatomic) unsigned int m_uiDownloadStatus; // @synthesize m_uiDownloadStatus;
@property(nonatomic) unsigned int m_uiPercent; // @synthesize m_uiPercent;
@property(retain, nonatomic) NSString *m_nsPattern; // @synthesize m_nsPattern;
@property(nonatomic) unsigned int m_uiEmojiStatFlag; // @synthesize m_uiEmojiStatFlag;
@property(nonatomic) unsigned int m_uiSendTime; // @synthesize m_uiSendTime;
@property(nonatomic) _Bool m_bNew; // @synthesize m_bNew;
@property(nonatomic) _Bool m_bIsSplit; // @synthesize m_bIsSplit;
@property(retain, nonatomic) NSData *m_dtThumbnail; // @synthesize m_dtThumbnail;
@property(nonatomic) _Bool m_bCdnForward; // @synthesize m_bCdnForward;
@property(nonatomic) _Bool m_bForward; // @synthesize m_bForward;
@property(retain, nonatomic) NSString *m_nsRealChatUsr; // @synthesize m_nsRealChatUsr;
@property(retain, nonatomic) id <IMsgExtendOperation> m_extendInfoWithFromUsr; // @synthesize m_extendInfoWithFromUsr;
@property(retain, nonatomic) id <IMsgExtendOperation> m_extendInfoWithMsgType; // @synthesize m_extendInfoWithMsgType;
@property(retain, nonatomic) id <IMsgExtendOperation> m_extendInfoWithMsgTypeForBiz; // @synthesize m_extendInfoWithMsgTypeForBiz;
@property(retain, nonatomic) NSString *m_nsMsgSource; // @synthesize m_nsMsgSource;
@property(retain, nonatomic) NSString *m_nsPushContent; // @synthesize m_nsPushContent;
@property(nonatomic) unsigned int m_uiCreateTime; // @synthesize m_uiCreateTime;
@property(nonatomic) unsigned int m_uiMsgFlag; // @synthesize m_uiMsgFlag;
@property(nonatomic) unsigned int m_uiImgStatus; // @synthesize m_uiImgStatus;
@property(nonatomic) unsigned int m_uiStatus; // @synthesize m_uiStatus;
@property(retain, nonatomic) NSString *m_nsContent; // @synthesize m_nsContent;
@property(nonatomic) unsigned int m_uiMessageType; // @synthesize m_uiMessageType;
@property(retain, nonatomic) NSString *m_nsToUsr; // @synthesize m_nsToUsr;
@property(retain, nonatomic) NSString *m_nsFromUsr; // @synthesize m_nsFromUsr;
@property(nonatomic) long long m_n64MesSvrID; // @synthesize m_n64MesSvrID;
@property(nonatomic) unsigned int m_uiMesLocalID; // @synthesize m_uiMesLocalID;
- (_Bool)isSentOK;
- (_Bool)IsNewInvitationApprove;
- (_Bool)IsNewInvitation;
- (_Bool)IsRoomAnnouncement;
- (_Bool)IsAtMe;
- (_Bool)isShowAppMessageBlockButton;
- (_Bool)isShowAppBottomButton;
- (id)keyDescription;
@property(readonly, copy) NSString *description;
- (id)getMsgExtBizId;
- (_Bool)IsNeedAddMsgBizExt;
- (_Bool)IsNeedChatExt;
- (void)genMiddleImg:(id)arg1 originImgData:(id)arg2 isSaveOK:(_Bool)arg3 delegate:(id)arg4;
- (_Bool)genImageFromMMAssetAndNotify:(id)arg1;
- (id)GetDisplayContent;
- (id)GetThumb;
- (id)GetMsgClientMsgID;
- (_Bool)IsSameMsgWithFullCheck:(id)arg1;
- (_Bool)IsSameMsg:(id)arg1;
- (_Bool)IsSendBySendMsg;
- (_Bool)IsAppMessage;
- (_Bool)IsPureVideoMsg;
- (_Bool)IsShortMovieMsg;
- (_Bool)IsVideoMsg;
- (_Bool)IsSimpleVideoMsg;
- (_Bool)IsImgMsg;
- (_Bool)IsTextMsg;
- (_Bool)IsChatRoomMessage;
- (_Bool)IsMassSendMessage;
- (_Bool)IsBottleMessage;
- (_Bool)IsQQMessage;
- (_Bool)IsSxMessage;
- (id)GetChatName;
- (void)AddTagToMsgSource:(id)arg1 value:(id)arg2;
- (void)UpdateMsgSource;
- (void)ChangeForDisplay;
- (void)ChangeForBackup;
- (void)fillMsgSourceFromContact:(id)arg1 isFromTempSession:(_Bool)arg2;
- (void)ChangeForMsgSource;
- (void)ChangeForChatRoom;
- (id)forwardingTargetForSelector:(SEL)arg1;
- (void)forwardInvocation:(id)arg1;
- (id)methodSignatureForSelector:(SEL)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithMsgType:(long long)arg1 nsFromUsr:(id)arg2;
- (id)initWithMsgType:(long long)arg1;
- (id)init;
- (id)wishingString;
- (_Bool)bIsAppUrlTypeWithCanvas;
- (id)nativeUrl;
- (int)yoType;
- (unsigned long long)yoCount;
- (id)getNodeBtnList;
- (long long)compareQQAscending:(id)arg1;
- (long long)compareSXAscending:(id)arg1;
- (long long)compareMessageAscending:(id)arg1;
- (long long)compareMessageLocalIDDescending:(id)arg1;
- (_Bool)canPlayVideo:(id)arg1;
- (_Bool)isAd;
- (id)GetCdnDownloadThumbPathOfVideo;
- (id)GetCdnDownloadPathOfVideo;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(retain, nonatomic) NSString *m_AttachedContent; // @dynamic m_AttachedContent;
@property(retain, nonatomic) NSString *m_aesKey; // @dynamic m_aesKey;
@property(retain, nonatomic) NSArray *m_arrCustomWrap; // @dynamic m_arrCustomWrap;
@property(retain, nonatomic) NSMutableArray *m_arrInviteeMembers; // @dynamic m_arrInviteeMembers;
@property(retain, nonatomic) NSMutableArray *m_arrMembers; // @dynamic m_arrMembers;
@property(retain, nonatomic) NSArray *m_arrReaderWaps; // @dynamic m_arrReaderWaps;
@property(retain, nonatomic) MMAsset *m_asset; // @dynamic m_asset;
@property(nonatomic) _Bool m_bAppAttachExistInSvr; // @dynamic m_bAppAttachExistInSvr;
@property(nonatomic) _Bool m_bHasApprove; // @dynamic m_bHasApprove;
@property(nonatomic) _Bool m_bIsForceUpdate; // @dynamic m_bIsForceUpdate;
@property(nonatomic) _Bool m_bNeedReloadSubView; // @dynamic m_bNeedReloadSubView;
@property(nonatomic) _Bool m_bNewApprove; // @dynamic m_bNewApprove;
@property(nonatomic) _Bool m_bNewInv; // @dynamic m_bNewInv;
@property(nonatomic) _Bool m_bShowRewardTips; // @dynamic m_bShowRewardTips;
@property(retain, nonatomic) NSString *m_cdnUrlString; // @dynamic m_cdnUrlString;
@property(retain, nonatomic) NSMutableDictionary *m_dicStatParas; // @dynamic m_dicStatParas;
@property(retain, nonatomic) NSData *m_dtImg; // @dynamic m_dtImg;
@property(retain, nonatomic) NSData *m_dtSenderMidImg; // @dynamic m_dtSenderMidImg;
@property(retain, nonatomic) NSData *m_dtVoice; // @dynamic m_dtVoice;
@property(nonatomic) unsigned int m_duration; // @dynamic m_duration;
@property(retain, nonatomic) NSString *m_encryptUrlString; // @dynamic m_encryptUrlString;
@property(nonatomic) double m_fLatitude; // @dynamic m_fLatitude;
@property(nonatomic) double m_fLongitude; // @dynamic m_fLongitude;
@property(retain, nonatomic) NSString *m_fromChatUserName; // @dynamic m_fromChatUserName;
@property(nonatomic) long long m_i64VoipKey; // @dynamic m_i64VoipKey;
@property(nonatomic) int m_iVoipRoomid; // @dynamic m_iVoipRoomid;
@property(retain, nonatomic) NSString *m_infoUrl; // @dynamic m_infoUrl;
@property(retain, nonatomic) NSString *m_inviterName; // @dynamic m_inviterName;
@property(nonatomic) _Bool m_isCanUpload; // @dynamic m_isCanUpload;
@property(readonly, nonatomic) _Bool m_isContentOriginal; // @dynamic m_isContentOriginal;
@property(nonatomic) _Bool m_isDirectSend; // @dynamic m_isDirectSend;
@property(nonatomic) _Bool m_isForNewYear; // @dynamic m_isForNewYear;
@property(nonatomic) _Bool m_isReaderForbidForward; // @dynamic m_isReaderForbidForward;
@property(nonatomic) double m_latitude; // @dynamic m_latitude;
@property(retain, nonatomic) NSString *m_locationLabel; // @dynamic m_locationLabel;
@property(nonatomic) double m_longitude; // @dynamic m_longitude;
@property(nonatomic) double m_mapScale; // @dynamic m_mapScale;
@property(retain, nonatomic) NSString *m_mapType; // @dynamic m_mapType;
@property(nonatomic) long long m_msgInnerType; // @dynamic m_msgInnerType;
@property(nonatomic) int m_nDownloadLimit; // @dynamic m_nDownloadLimit;
@property(retain, nonatomic) NSString *m_newXmlType; // @dynamic m_newXmlType;
@property(retain, nonatomic) NSString *m_nsAesKey; // @dynamic m_nsAesKey;
@property(retain, nonatomic) NSString *m_nsAppAction; // @dynamic m_nsAppAction;
@property(retain, nonatomic) NSString *m_nsAppAttachID; // @dynamic m_nsAppAttachID;
@property(retain, nonatomic) NSString *m_nsAppContent; // @dynamic m_nsAppContent;
@property(retain, nonatomic) NSString *m_nsAppExtInfo; // @dynamic m_nsAppExtInfo;
@property(retain, nonatomic) NSString *m_nsAppFileExt; // @dynamic m_nsAppFileExt;
@property(retain, nonatomic) NSString *m_nsAppID; // @dynamic m_nsAppID;
@property(retain, nonatomic) NSString *m_nsAppMediaDataUrl; // @dynamic m_nsAppMediaDataUrl;
@property(retain, nonatomic) NSString *m_nsAppMediaLowBandDataUrl; // @dynamic m_nsAppMediaLowBandDataUrl;
@property(retain, nonatomic) NSString *m_nsAppMediaLowUrl; // @dynamic m_nsAppMediaLowUrl;
@property(retain, nonatomic) NSString *m_nsAppMediaTagName; // @dynamic m_nsAppMediaTagName;
@property(retain, nonatomic) NSString *m_nsAppMediaUrl; // @dynamic m_nsAppMediaUrl;
@property(retain, nonatomic) NSString *m_nsAppMessageAction; // @dynamic m_nsAppMessageAction;
@property(retain, nonatomic) NSString *m_nsAppMessageExt; // @dynamic m_nsAppMessageExt;
@property(retain, nonatomic) NSString *m_nsAppName; // @dynamic m_nsAppName;
@property(retain, nonatomic) NSString *m_nsAutoDownloadControl; // @dynamic m_nsAutoDownloadControl;
@property(retain, nonatomic) NSString *m_nsDesc; // @dynamic m_nsDesc;
@property(retain, nonatomic) NSString *m_nsDesignerId; // @dynamic m_nsDesignerId;
@property(copy, nonatomic) NSString *m_nsEmoticonBelongToProductID; // @dynamic m_nsEmoticonBelongToProductID;
@property(retain, nonatomic) NSString *m_nsEmoticonMD5; // @dynamic m_nsEmoticonMD5;
@property(retain, nonatomic) NSString *m_nsFileParam; // @dynamic m_nsFileParam;
@property(retain, nonatomic) NSString *m_nsImgHDUrl; // @dynamic m_nsImgHDUrl;
@property(retain, nonatomic) NSString *m_nsImgMidUrl; // @dynamic m_nsImgMidUrl;
@property(retain, nonatomic) NSString *m_nsImgSrc; // @dynamic m_nsImgSrc;
@property(retain, nonatomic) NSString *m_nsInviteReason; // @dynamic m_nsInviteReason;
@property(retain, nonatomic) NSString *m_nsInviteTickets; // @dynamic m_nsInviteTickets;
@property(retain, nonatomic) NSString *m_nsJsAppId; // @dynamic m_nsJsAppId;
@property(retain, nonatomic) NSString *m_nsMsgAttachUrl; // @dynamic m_nsMsgAttachUrl;
@property(retain, nonatomic) NSString *m_nsMsgDataUrl; // @dynamic m_nsMsgDataUrl;
@property(retain, nonatomic) NSString *m_nsMsgMd5; // @dynamic m_nsMsgMd5;
@property(retain, nonatomic) NSString *m_nsMsgThumbAesKey; // @dynamic m_nsMsgThumbAesKey;
@property(retain, nonatomic) NSString *m_nsMsgThumbMd5; // @dynamic m_nsMsgThumbMd5;
@property(retain, nonatomic) NSString *m_nsMsgThumbUrl; // @dynamic m_nsMsgThumbUrl;
@property(retain, nonatomic) NSString *m_nsRemindAttachId; // @dynamic m_nsRemindAttachId;
@property(retain, nonatomic) NSString *m_nsShareOpenUrl; // @dynamic m_nsShareOpenUrl;
@property(retain, nonatomic) NSString *m_nsShareOriginUrl; // @dynamic m_nsShareOriginUrl;
@property(retain, nonatomic) NSString *m_nsSourceDisplayname; // @dynamic m_nsSourceDisplayname;
@property(retain, nonatomic) NSString *m_nsSourceUsername; // @dynamic m_nsSourceUsername;
@property(retain, nonatomic) NSString *m_nsStatExtStr; // @dynamic m_nsStatExtStr;
@property(retain, nonatomic) NSString *m_nsStreamVideoAdUxInfo; // @dynamic m_nsStreamVideoAdUxInfo;
@property(retain, nonatomic) NSString *m_nsStreamVideoPublishId; // @dynamic m_nsStreamVideoPublishId;
@property(retain, nonatomic) NSString *m_nsStreamVideoThumbUrl; // @dynamic m_nsStreamVideoThumbUrl;
@property(retain, nonatomic) NSString *m_nsStreamVideoTitle; // @dynamic m_nsStreamVideoTitle;
@property(retain, nonatomic) NSString *m_nsStreamVideoUrl; // @dynamic m_nsStreamVideoUrl;
@property(retain, nonatomic) NSString *m_nsStreamVideoWebUrl; // @dynamic m_nsStreamVideoWebUrl;
@property(retain, nonatomic) NSString *m_nsStreamVideoWording; // @dynamic m_nsStreamVideoWording;
@property(retain, nonatomic) NSString *m_nsTemplateId; // @dynamic m_nsTemplateId;
@property(retain, nonatomic) NSString *m_nsThumbImgUrl; // @dynamic m_nsThumbImgUrl;
@property(retain, nonatomic) NSString *m_nsThumbUrl; // @dynamic m_nsThumbUrl;
@property(retain, nonatomic) NSString *m_nsTitle; // @dynamic m_nsTitle;
@property(retain, nonatomic) AppInnerJumpItem *m_oAppInnerJumpItem; // @dynamic m_oAppInnerJumpItem;
@property(retain, nonatomic) AppProductItem *m_oAppProductItem; // @dynamic m_oAppProductItem;
@property(retain, nonatomic) AppTVItem *m_oAppTVItem; // @dynamic m_oAppTVItem;
@property(retain, nonatomic) WCCanvasPageItem *m_oCanvasPageItem; // @dynamic m_oCanvasPageItem;
@property(retain, nonatomic) CardTicketItem *m_oCardTicketItem; // @dynamic m_oCardTicketItem;
@property(retain, nonatomic) EmoticonSharedItem *m_oEmoticonSharedItem; // @dynamic m_oEmoticonSharedItem;
@property(retain, nonatomic) EmotionDesignerSharedItem *m_oEmotionDesignerSharedItem; // @dynamic m_oEmotionDesignerSharedItem;
@property(retain, nonatomic) EmotionPageSharedItem *m_oEmotionPageSharedItem; // @dynamic m_oEmotionPageSharedItem;
@property(retain, nonatomic) GiftCardItem *m_oGiftCardItem;
@property(retain, nonatomic) HardWareItem *m_oHardWareItem; // @dynamic m_oHardWareItem;
@property(retain, nonatomic) ImageInfo *m_oImageInfo; // @dynamic m_oImageInfo;
@property(retain, nonatomic) MallProductItem *m_oMallProductItem; // @dynamic m_oMallProductItem;
@property(retain, nonatomic) MessageExpItem *m_oMsgExpItem; // @dynamic m_oMsgExpItem;
@property(retain, nonatomic) PushMailWrap *m_oPushMailWrap; // @dynamic m_oPushMailWrap;
@property(retain, nonatomic) FavoritesItem *m_oRecordItem; // @dynamic m_oRecordItem;
@property(retain, nonatomic) VideoUploadStatInfo *m_oVideoUploadStatInfo; // @dynamic m_oVideoUploadStatInfo;
@property(retain, nonatomic) WAAppMsgItem *m_oWAAppItem; // @dynamic m_oWAAppItem;
@property(retain, nonatomic) WCPayInfoItem *m_oWCPayInfoItem; // @dynamic m_oWCPayInfoItem;
@property(retain, nonatomic) MMWCPushInfo *m_oWebcachePushInfo; // @dynamic m_oWebcachePushInfo;
@property(retain, nonatomic) iWatchAppMsgItem *m_oiWatchMsgItem; // @dynamic m_oiWatchMsgItem;
@property(retain, nonatomic) NSString *m_poiName; // @dynamic m_poiName;
@property(retain, nonatomic) NSString *m_qrCode; // @dynamic m_qrCode;
@property(retain, nonatomic) CMessageWrap *m_refMessageWrap; // @dynamic m_refMessageWrap;
@property(retain, nonatomic) NSString *m_scene; // @dynamic m_scene;
@property(retain, nonatomic) NSString *m_sessionShowContent; // @dynamic m_sessionShowContent;
@property(retain, nonatomic) NSString *m_showContent; // @dynamic m_showContent;
@property(nonatomic) unsigned int m_uiApiSDKVersion; // @dynamic m_uiApiSDKVersion;
@property(nonatomic) unsigned int m_uiAppContentAttributeBitSetFlag; // @dynamic m_uiAppContentAttributeBitSetFlag;
@property(nonatomic) unsigned int m_uiAppDataSize; // @dynamic m_uiAppDataSize;
@property(nonatomic) unsigned int m_uiAppExtShowType; // @dynamic m_uiAppExtShowType;
@property(nonatomic) unsigned int m_uiAppMsgInnerType; // @dynamic m_uiAppMsgInnerType;
@property(nonatomic) unsigned int m_uiAppVersion; // @dynamic m_uiAppVersion;
@property(nonatomic) unsigned int m_uiCameraType; // @dynamic m_uiCameraType;
@property(nonatomic) unsigned int m_uiDownloadPercent; // @dynamic m_uiDownloadPercent;
@property(nonatomic) unsigned int m_uiEmoticonHeight; // @dynamic m_uiEmoticonHeight;
@property(nonatomic) unsigned int m_uiEmoticonType; // @dynamic m_uiEmoticonType;
@property(nonatomic) unsigned int m_uiEmoticonWidth; // @dynamic m_uiEmoticonWidth;
@property(nonatomic) unsigned int m_uiEncryVer; // @dynamic m_uiEncryVer;
@property(nonatomic) unsigned int m_uiGameContent; // @dynamic m_uiGameContent;
@property(nonatomic) unsigned int m_uiGameType; // @dynamic m_uiGameType;
@property(nonatomic) unsigned int m_uiHDImgSize; // @dynamic m_uiHDImgSize;
@property(nonatomic) unsigned int m_uiMsgThumbHeight; // @dynamic m_uiMsgThumbHeight;
@property(nonatomic) unsigned int m_uiMsgThumbSize; // @dynamic m_uiMsgThumbSize;
@property(nonatomic) unsigned int m_uiMsgThumbWidth; // @dynamic m_uiMsgThumbWidth;
@property(nonatomic) unsigned int m_uiNormalImgSize; // @dynamic m_uiNormalImgSize;
@property(nonatomic) unsigned int m_uiOriginFormat; // @dynamic m_uiOriginFormat;
@property(nonatomic) unsigned int m_uiOriginMsgSvrId; // @dynamic m_uiOriginMsgSvrId;
@property(nonatomic) unsigned int m_uiRemindAttachTotalLen; // @dynamic m_uiRemindAttachTotalLen;
@property(nonatomic) unsigned int m_uiRemindFormat; // @dynamic m_uiRemindFormat;
@property(nonatomic) unsigned int m_uiRemindId; // @dynamic m_uiRemindId;
@property(nonatomic) unsigned int m_uiRemindTime; // @dynamic m_uiRemindTime;
@property(nonatomic) unsigned int m_uiScene; // @dynamic m_uiScene;
@property(nonatomic) unsigned int m_uiShowType; // @dynamic m_uiShowType;
@property(nonatomic) unsigned int m_uiSoundType; // @dynamic m_uiSoundType;
@property(nonatomic) unsigned int m_uiStreamVideoTime; // @dynamic m_uiStreamVideoTime;
@property(nonatomic) unsigned int m_uiUploadStatus; // @dynamic m_uiUploadStatus;
@property(nonatomic) unsigned int m_uiVideoLen; // @dynamic m_uiVideoLen;
@property(nonatomic) unsigned int m_uiVideoOffset; // @dynamic m_uiVideoOffset;
@property(nonatomic) unsigned int m_uiVideoSource; // @dynamic m_uiVideoSource;
@property(nonatomic) unsigned int m_uiVideoTime; // @dynamic m_uiVideoTime;
@property(nonatomic) unsigned int m_uiVoiceCancelFlag; // @dynamic m_uiVoiceCancelFlag;
@property(nonatomic) unsigned int m_uiVoiceEndFlag; // @dynamic m_uiVoiceEndFlag;
@property(nonatomic) unsigned int m_uiVoiceFormat; // @dynamic m_uiVoiceFormat;
@property(nonatomic) unsigned int m_uiVoiceForwardFlag; // @dynamic m_uiVoiceForwardFlag;
@property(nonatomic) unsigned int m_uiVoiceTime; // @dynamic m_uiVoiceTime;
@property(nonatomic) unsigned int m_uiVoipInviteType; // @dynamic m_uiVoipInviteType;
@property(nonatomic) unsigned int m_uiVoipRecvTime; // @dynamic m_uiVoipRecvTime;
@property(nonatomic) unsigned int m_uiVoipStatus; // @dynamic m_uiVoipStatus;
@property(nonatomic) unsigned int m_uiWeAppState; // @dynamic m_uiWeAppState;
@property(nonatomic) unsigned int m_uiWeAppVersion; // @dynamic m_uiWeAppVersion;
@property(retain, nonatomic) NSString *m_url; // @dynamic m_url;
@property(nonatomic) unsigned int m_wordingType; // @dynamic m_wordingType;
@property(readonly) Class superclass;

@end

@interface CBaseContact : NSObject <PBCoding, NSCoding>
{
    NSString *m_nsUsrName;
    NSString *m_nsEncodeUserName;
    NSString *m_nsAliasName;
    unsigned int m_uiConType;
    NSString *m_nsNickName;
    NSString *m_nsFullPY;
    NSString *m_nsShortPY;
    NSString *m_nsRemark;
    NSString *m_nsRemarkPYShort;
    NSString *m_nsRemarkPYFull;
    NSString *m_nsDisplayNamePY;
    unsigned int m_uiSex;
    unsigned int m_uiType;
    unsigned int m_uiChatState;
    NSData *m_dtUsrImg;
    NSString *m_nsImgStatus;
    NSString *m_nsHDImgStatus;
    NSString *m_nsHeadImgUrl;
    NSString *m_nsHeadHDImgUrl;
    NSString *m_nsHeadHDMd5;
    NSString *m_nsDraft;
    unsigned int m_uiDraftTime;
    NSString *m_nsAtUserList;
    unsigned int m_uiQQUin;
    NSString *m_nsQQNickName;
    NSString *m_nsQQRemark;
    NSString *m_nsMobileIdentify;
    NSString *m_nsGoogleContactName;
    NSString *m_nsGoogleContactNickName;
    unsigned int m_uiFriendScene;
    unsigned int m_uiImgKey;
    unsigned int m_uiExtKey;
    unsigned int m_uiImgKeyAtLastGet;
    unsigned int m_uiExtKeyAtLastGet;
    _Bool m_hasDetectPlugin;
    _Bool m_isPlugin;
    _Bool m_hasDetectSelf;
    _Bool m_isSelf;
    NSString *m_nsAntispamTicket;
    NSDictionary *_externalInfoJSONCache;
}

+ (void)initialize;
@property(retain, nonatomic) NSDictionary *externalInfoJSONCache; // @synthesize externalInfoJSONCache=_externalInfoJSONCache;
@property(retain, nonatomic) NSString *m_nsDisplayNamePY; // @synthesize m_nsDisplayNamePY;
@property(retain, nonatomic) NSString *m_nsAntispamTicket; // @synthesize m_nsAntispamTicket;
@property(retain, nonatomic) NSString *m_nsShortPY; // @synthesize m_nsShortPY;
@property(retain, nonatomic) NSString *m_nsAtUserList; // @synthesize m_nsAtUserList;
@property(nonatomic) unsigned int m_uiDraftTime; // @synthesize m_uiDraftTime;
@property(nonatomic) unsigned int m_uiFriendScene; // @synthesize m_uiFriendScene;
@property(retain, nonatomic) NSString *m_nsGoogleContactNickName; // @synthesize m_nsGoogleContactNickName;
@property(retain, nonatomic) NSString *m_nsGoogleContactName; // @synthesize m_nsGoogleContactName;
@property(retain, nonatomic) NSString *m_nsMobileIdentify; // @synthesize m_nsMobileIdentify;
@property(retain, nonatomic) NSString *m_nsQQRemark; // @synthesize m_nsQQRemark;
@property(retain, nonatomic) NSString *m_nsQQNickName; // @synthesize m_nsQQNickName;
@property(nonatomic) unsigned int m_uiQQUin; // @synthesize m_uiQQUin;
@property(nonatomic) unsigned int m_uiExtKeyAtLastGet; // @synthesize m_uiExtKeyAtLastGet;
@property(nonatomic) unsigned int m_uiImgKeyAtLastGet; // @synthesize m_uiImgKeyAtLastGet;
@property(nonatomic) unsigned int m_uiExtKey; // @synthesize m_uiExtKey;
@property(nonatomic) unsigned int m_uiImgKey; // @synthesize m_uiImgKey;
@property(retain, nonatomic) NSString *m_nsDraft; // @synthesize m_nsDraft;
@property(retain, nonatomic) NSString *m_nsHeadHDMd5; // @synthesize m_nsHeadHDMd5;
@property(retain, nonatomic) NSString *m_nsHeadHDImgUrl; // @synthesize m_nsHeadHDImgUrl;
@property(retain, nonatomic) NSString *m_nsHeadImgUrl; // @synthesize m_nsHeadImgUrl;
@property(retain, nonatomic) NSString *m_nsHDImgStatus; // @synthesize m_nsHDImgStatus;
@property(retain, nonatomic) NSString *m_nsImgStatus; // @synthesize m_nsImgStatus;
@property(retain, nonatomic) NSData *m_dtUsrImg; // @synthesize m_dtUsrImg;
@property(nonatomic) unsigned int m_uiChatState; // @synthesize m_uiChatState;
@property(nonatomic) unsigned int m_uiType; // @synthesize m_uiType;
@property(nonatomic) unsigned int m_uiSex; // @synthesize m_uiSex;
@property(retain, nonatomic) NSString *m_nsRemarkPYFull; // @synthesize m_nsRemarkPYFull;
@property(retain, nonatomic) NSString *m_nsRemarkPYShort; // @synthesize m_nsRemarkPYShort;
@property(retain, nonatomic) NSString *m_nsRemark; // @synthesize m_nsRemark;
@property(retain, nonatomic) NSString *m_nsFullPY; // @synthesize m_nsFullPY;
@property(nonatomic) unsigned int m_uiConType; // @synthesize m_uiConType;
@property(retain, nonatomic) NSString *m_nsAliasName; // @synthesize m_nsAliasName;
@property(retain, nonatomic) NSString *m_nsEncodeUserName; // @synthesize m_nsEncodeUserName;
@property(retain, nonatomic) NSString *m_nsUsrName; // @synthesize m_nsUsrName;
@property(readonly, nonatomic) _Bool m_isPlugin; // @synthesize m_isPlugin;
- (id)localizedStringForMale:(id)arg1 female:(id)arg2 andUnkownSex:(id)arg3;
- (int)getImageStatusCode;
- (_Bool)isHasGMail;
- (id)getQQDisplayName;
- (_Bool)isHasQQDisplayName;
- (_Bool)isHasQQ;
- (_Bool)isWeixinTeamContact;
- (_Bool)isSelf;
- (_Bool)hasContactDisplayUsrNameByCache;
- (_Bool)hasContactDisplayUsrName;
- (id)getContactDisplayUsrName;
- (id)getContactTalkRoomName;
- (id)getContactDisplayName;
- (void)setDisplayNamePY;
- (id)getRemark;
- (void)saveUserImage;
- (id)getContactHeadImage;
- (_Bool)isNeedGetHDImg;
- (_Bool)isHasHDImg;
- (_Bool)isNeedGetUsrImgWithoutCheckLocalFile;
- (_Bool)isNeedGetUsrImg;
- (_Bool)isEnterpriseContact;
- (_Bool)isWeSportContact;
- (_Bool)isChatStatusNotifyOpen;
- (_Bool)isMacHelper;
- (_Bool)isQQ;
- (_Bool)isQQMBlog;
- (_Bool)isTemplateMsgHolder;
- (_Bool)isFileHelper;
- (_Bool)isBrandSessionHolder;
- (_Bool)isGroupCard;
- (_Bool)isChatroom;
- (_Bool)isLbsroom;
- (_Bool)isWeixin;
- (_Bool)isMMContact;
- (_Bool)isFavour;
- (void)setSnsBlack:(_Bool)arg1;
- (_Bool)isSnsBlack;
- (void)setBlack:(_Bool)arg1;
- (_Bool)isBlack;
- (_Bool)isEqualToName:(id)arg1;
- (_Bool)isEqualToContact:(id)arg1;
- (id)getEncodeUserName;
- (_Bool)isValid;
- (void)setChatRoomTopic:(id)arg1;
- (id)chatRoomTopic;
- (long long)compare:(id)arg1;
@property(readonly, copy) NSString *description;
- (_Bool)copyFrom:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)init;
- (void)setRemarkWithoutEmojiChange:(id)arg1;
- (void)setNickNameWithoutEmojiChange:(id)arg1;
@property(retain, nonatomic) NSString *m_nsNickName; // @synthesize m_nsNickName;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) Class superclass;

@end

@interface SubscriptBrandInfo : NSObject <PBCoding, NSCoding>
{
    unsigned int m_brandListCount;
    unsigned int m_brandListVersion;
}

+ (void)initialize;
@property(nonatomic) unsigned int m_brandListVersion; // @synthesize m_brandListVersion;
@property(nonatomic) unsigned int m_brandListCount; // @synthesize m_brandListCount;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface ChatRoomDetail : NSObject <PBCoding, NSCoding>
{
    unsigned int m_uiChatRoomInfoVersion;
    unsigned int m_uiChatRoomInfoSvrVersion;
    NSString *m_nsChatRoomDesc;
    NSString *m_nsChatRoomDescModer;
    unsigned long long m_uiChatRoomDescTime;
    _Bool m_bChatRoomDescReaded;
    unsigned int m_uiChatRoomStatus;
    unsigned int m_uiLocalInfoVersion;
}

+ (void)initialize;
@property(nonatomic) unsigned int m_uiLocalInfoVersion; // @synthesize m_uiLocalInfoVersion;
@property(nonatomic) unsigned int m_uiChatRoomStatus; // @synthesize m_uiChatRoomStatus;
@property(nonatomic) _Bool m_bChatRoomDescReaded; // @synthesize m_bChatRoomDescReaded;
@property(nonatomic) unsigned long long m_uiChatRoomDescTime; // @synthesize m_uiChatRoomDescTime;
@property(retain, nonatomic) NSString *m_nsChatRoomDescModer; // @synthesize m_nsChatRoomDescModer;
@property(retain, nonatomic) NSString *m_nsChatRoomDesc; // @synthesize m_nsChatRoomDesc;
@property(nonatomic) unsigned int m_uiChatRoomInfoSvrVersion; // @synthesize m_uiChatRoomInfoSvrVersion;
@property(nonatomic) unsigned int m_uiChatRoomInfoVersion; // @synthesize m_uiChatRoomInfoVersion;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface CContact : CBaseContact <PBCoding, NSCoding>
{
    unsigned int m_uiChatRoomStatus;
    NSString *m_nsChatRoomMemList;
    unsigned int m_uiChatRoomAccessType;
    unsigned int m_uiChatRoomMaxCount;
    unsigned int m_uiChatRoomVersion;
    ChatRoomDetail *m_ChatRoomDetail;
    NSString *m_nsChatRoomData;
    ChatRoomData *m_ChatRoomData;
    NSString *m_nsCountry;
    NSString *m_nsProvince;
    NSString *m_nsCity;
    NSString *m_nsSignature;
    unsigned int m_uiCertificationFlag;
    NSString *m_nsCertificationInfo;
    NSString *m_nsOwner;
    NSString *m_nsFBNickName;
    NSString *m_nsFBID;
    unsigned int m_uiNeedUpdate;
    NSString *m_nsWCBGImgObjectID;
    int m_iWCFlag;
    NSString *m_pcWCBGImgID;
    NSString *m_nsExternalInfo;
    NSString *m_nsBrandSubscriptConfigUrl;
    unsigned int m_uiBrandSubscriptionSettings;
    SubscriptBrandInfo *m_subBrandInfo;
    NSString *m_nsBrandIconUrl;
    _Bool m_isExtInfoValid;
    NSDictionary *externalInfoJSONCache;
    _Bool m_isShowRedDot;
    NSString *m_nsMobileHash;
    NSString *m_nsMobileFullHash;
    NSString *m_nsLinkedInID;
    NSString *m_nsLinkedInName;
    NSString *m_nsLinkedInPublicUrl;
    unsigned int m_uiDeleteFlag;
    NSString *m_nsDescription;
    NSString *m_nsCardUrl;
    NSString *m_nsWorkID;
    NSString *m_nsLabelIDList;
    NSArray *m_arrPhoneItem;
    NSRecursiveLock *m_lockForChatRoomData;
    _Bool _m_bFromNewDB;
    unsigned int _m_uiLastUpdate;
    unsigned int _m_uiMetaFlag;
    unsigned int _m_uiDebugModeType;
    unsigned int _m_uiWxAppOpt;
    unsigned int _uiLastUpdateAppVersionInfoTime;
    NSString *m_nsWeiDianInfo;
    NSDictionary *_m_dicWeiDianInfo;
    NSString *_m_nsAppId;
    WANewYearContactInfo *_m_weAppNewYearContactInfo;
}

+ (_Bool)isHeadImgUpdated:(id)arg1 Local:(id)arg2;
+ (void)HandleChatMemUsrImg:(struct tagMMModChatRoomMember *)arg1 Contatct:(id)arg2 DocPath:(id)arg3;
+ (void)HandleUsrImgPB:(id)arg1 Contatct:(id)arg2 DocPath:(id)arg3;
+ (void)HandleUsrImg:(struct tagMMModContact *)arg1 Contatct:(id)arg2 DocPath:(id)arg3;
+ (id)genChatRoomName:(id)arg1 appendTail:(_Bool)arg2;
+ (id)genChatRoomName:(id)arg1;
+ (id)getChatRoomMemberWithoutMyself:(id)arg1;
+ (id)getChatRoomMember:(id)arg1;
+ (id)getChatRoomMemberUserName:(id)arg1;
+ (unsigned long long)getChatRoomMemberCount:(id)arg1;
+ (id)getMicroBlogUsrDisplayName:(id)arg1;
+ (id)parseContactKey:(id)arg1;
+ (id)SubscriptedBrandsFromString:(id)arg1;
+ (void)initialize;
+ (_Bool)isWeAppUserName:(id)arg1;
@property(retain, nonatomic) WANewYearContactInfo *m_weAppNewYearContactInfo; // @synthesize m_weAppNewYearContactInfo=_m_weAppNewYearContactInfo;
@property(nonatomic) unsigned int uiLastUpdateAppVersionInfoTime; // @synthesize uiLastUpdateAppVersionInfoTime=_uiLastUpdateAppVersionInfoTime;
@property(nonatomic) unsigned int m_uiWxAppOpt; // @synthesize m_uiWxAppOpt=_m_uiWxAppOpt;
@property(copy, nonatomic) NSString *m_nsAppId; // @synthesize m_nsAppId=_m_nsAppId;
@property(nonatomic) unsigned int m_uiDebugModeType; // @synthesize m_uiDebugModeType=_m_uiDebugModeType;
@property(nonatomic) unsigned int m_uiMetaFlag; // @synthesize m_uiMetaFlag=_m_uiMetaFlag;
@property(nonatomic) unsigned int m_uiLastUpdate; // @synthesize m_uiLastUpdate=_m_uiLastUpdate;
@property(nonatomic) _Bool m_bFromNewDB; // @synthesize m_bFromNewDB=_m_bFromNewDB;
@property(retain, nonatomic) NSString *m_nsWorkID; // @synthesize m_nsWorkID;
- (void)setExternalInfoJSONCache:(id)arg1;
- (id)externalInfoJSONCache;
@property(retain, nonatomic) NSString *m_nsWeiDianInfo; // @synthesize m_nsWeiDianInfo;
@property(retain, nonatomic) ChatRoomDetail *m_ChatRoomDetail; // @synthesize m_ChatRoomDetail;
@property(retain, nonatomic) NSArray *m_arrPhoneItem; // @synthesize m_arrPhoneItem;
@property(retain, nonatomic) NSString *m_nsLabelIDList; // @synthesize m_nsLabelIDList;
@property(retain, nonatomic) NSString *m_nsCardUrl; // @synthesize m_nsCardUrl;
@property(retain, nonatomic) NSString *m_nsDescription; // @synthesize m_nsDescription;
@property(nonatomic) unsigned int m_uiDeleteFlag; // @synthesize m_uiDeleteFlag;
@property(nonatomic) unsigned int m_uiChatRoomVersion; // @synthesize m_uiChatRoomVersion;
@property(nonatomic) unsigned int m_uiChatRoomMaxCount; // @synthesize m_uiChatRoomMaxCount;
@property(retain, nonatomic) NSString *m_nsLinkedInPublicUrl; // @synthesize m_nsLinkedInPublicUrl;
@property(retain, nonatomic) NSString *m_nsLinkedInName; // @synthesize m_nsLinkedInName;
@property(retain, nonatomic) NSString *m_nsLinkedInID; // @synthesize m_nsLinkedInID;
@property(retain, nonatomic) NSString *m_nsMobileFullHash; // @synthesize m_nsMobileFullHash;
@property(retain, nonatomic) NSString *m_nsMobileHash; // @synthesize m_nsMobileHash;
@property(nonatomic) _Bool m_isShowRedDot; // @synthesize m_isShowRedDot;
@property(nonatomic) unsigned int m_uiChatRoomAccessType; // @synthesize m_uiChatRoomAccessType;
@property(nonatomic) _Bool m_isExtInfoValid; // @synthesize m_isExtInfoValid;
@property(retain, nonatomic) NSString *m_nsBrandIconUrl; // @synthesize m_nsBrandIconUrl;
@property(retain, nonatomic) SubscriptBrandInfo *m_subBrandInfo; // @synthesize m_subBrandInfo;
@property(nonatomic) unsigned int m_uiBrandSubscriptionSettings; // @synthesize m_uiBrandSubscriptionSettings;
@property(retain, nonatomic) NSString *m_nsBrandSubscriptConfigUrl; // @synthesize m_nsBrandSubscriptConfigUrl;
@property(retain, nonatomic) NSString *m_nsExternalInfo; // @synthesize m_nsExternalInfo;
@property(retain, nonatomic) NSString *m_pcWCBGImgID; // @synthesize m_pcWCBGImgID;
@property(nonatomic) int m_iWCFlag; // @synthesize m_iWCFlag;
@property(retain, nonatomic) NSString *m_nsWCBGImgObjectID; // @synthesize m_nsWCBGImgObjectID;
@property(nonatomic) unsigned int m_uiNeedUpdate; // @synthesize m_uiNeedUpdate;
@property(retain, nonatomic) NSString *m_nsFBID; // @synthesize m_nsFBID;
@property(retain, nonatomic) NSString *m_nsFBNickName; // @synthesize m_nsFBNickName;
@property(retain, nonatomic) NSString *m_nsOwner; // @synthesize m_nsOwner;
@property(retain, nonatomic) NSString *m_nsCertificationInfo; // @synthesize m_nsCertificationInfo;
@property(nonatomic) unsigned int m_uiCertificationFlag; // @synthesize m_uiCertificationFlag;
@property(retain, nonatomic) NSString *m_nsSignature; // @synthesize m_nsSignature;
@property(retain, nonatomic) NSString *m_nsCity; // @synthesize m_nsCity;
@property(retain, nonatomic) NSString *m_nsProvince; // @synthesize m_nsProvince;
@property(retain, nonatomic) NSString *m_nsCountry; // @synthesize m_nsCountry;
@property(nonatomic) unsigned int m_uiChatRoomStatus; // @synthesize m_uiChatRoomStatus;
@property(retain, nonatomic) NSString *m_nsChatRoomMemList; // @synthesize m_nsChatRoomMemList;
- (_Bool)isWeAppNewYearContact;
- (_Bool)IsUserInChatRoom:(id)arg1;
- (id)getLabelIDList;
- (_Bool)isAccountDeleted;
@property(readonly, nonatomic) NSDictionary *m_dicWeiDianInfo; // @synthesize m_dicWeiDianInfo=_m_dicWeiDianInfo;
- (_Bool)isHasWeiDian;
- (_Bool)isShowLinkedIn;
- (_Bool)needShowUnreadCountOnSession;
- (void)setChatStatusNotifyOpen:(_Bool)arg1;
- (_Bool)isChatStatusNotifyOpen;
- (_Bool)isContactFrozen;
- (_Bool)isContactSessionTop;
- (_Bool)isChatroomNeedAccessVerify;
- (_Bool)isShowChatRoomDisplayName;
- (_Bool)isAdmin;
- (id)xmlForMessageWrapContent;
- (id)getChatRoomMembrGroupNickName:(id)arg1;
- (id)getChatRoomMemberNickName:(id)arg1;
- (id)getChatRoomMemberDisplayName:(id)arg1;
- (id)getNormalContactDisplayDesc;
- (long long)compareForFavourGroup:(id)arg1;
- (_Bool)isLocalizedContact;
- (_Bool)isHolderContact;
- (_Bool)isVerified;
- (_Bool)isIgnoreBrandContat;
- (_Bool)isVerifiedBrandContact;
- (_Bool)isBrandContact;
- (_Bool)IsAddFromShake;
- (_Bool)IsAddFromLbs;
- (_Bool)isMyContact;
- (void)tryLoadExtInfo;
@property(readonly, copy) NSString *description;
- (_Bool)copyPatialFieldFromContact:(id)arg1;
- (_Bool)copyFieldFromContact:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithModContact:(id)arg1;
- (id)initWithShareCardMsgWrapContent:(id)arg1;
- (id)initWithShareCardMsgWrap:(id)arg1;
- (void)genContactFromShareCardMsgWrapContent:(id)arg1;
- (_Bool)genContactFromShareCardMsgWrap:(id)arg1;
- (id)init;
- (_Bool)isHasMobile;
- (id)getMobileList;
- (_Bool)hasMatchHashPhone;
- (id)getMobileNumString;
- (id)getMobileDisplayName;
- (_Bool)isContactTypeShouldDelete;
- (id)getNewChatroomData;
@property(retain, nonatomic) ChatRoomData *m_ChatRoomData; // @synthesize m_ChatRoomData;
@property(retain, nonatomic) NSString *m_nsChatRoomData; // @synthesize m_nsChatRoomData;
- (void)setSignatureWithoutEmojiChange:(id)arg1;
- (void)setChatRoomDataWithoutEmojiChange:(id)arg1;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;
- (id)getWeAppProfileCategoryList;
- (long long)getWeAppBizWxaOpenFlag;
- (id)getWeAppProfileBindBrandList;
- (id)getBrandProfileBindWeAppList;
- (id)getWeAppInfo;
- (_Bool)hasWeAppVersionInfo;
- (_Bool)hasWeAppInfo;
- (_Bool)isBlockWeAppSessionMessage;
- (_Bool)isWeAppContact;
- (unsigned int)getCDNUrlLifeSpanSecond;
- (id)getCDNDownloadUrl;
- (id)getWeAppConfigList;
- (id)getVerisonMD5;
- (id)getAppBrandSologanImageURL;
- (id)getAppID;
- (id)getAppBrandInfo;
- (_Bool)hasAppBrandInfo;
- (id)getMainPageUrl;
- (_Bool)isOpenMainPage;
- (unsigned int)getFunctionFlag;
- (id)getSupportEmoticonLinkPrefix;
- (id)getConferenceVerifyButtonTitle;
- (id)getConferenceVerifyPromptTitle;
- (unsigned int)getConferenceContactExpireTime;
- (id)getBrandBusinessScope;
- (id)getBrandMerchantSecurityUrl;
- (id)getBrandMerchantSecurity;
- (id)getBrandEvaluateCount;
- (id)getBrandMerchantRatings;
- (id)brandUrls;
- (id)brandPrivileges;
- (id)getBrandRegisterSourceIntroUrl;
- (id)getBrandRegisterSourceBody;
- (_Bool)getIsTrademarkProtection;
- (id)getBrandVerifySubTitle;
- (id)getBrandVerifySourceIntroUrl;
- (id)getBrandVerifySourceDescription;
- (id)getBrandVerifySourceName;
- (unsigned int)getBrandVerifySourceType;
- (id)getBrandTrademarkName;
- (id)getBrandTrademarkUrl;
- (id)getCustomizeMenu;
- (id)bizMenuInfoFromContact;
- (long long)getInteractiveMode;
- (_Bool)isShowToolBarInMsg;
- (_Bool)isShowHeadImgInMsg;
- (long long)getScanQRCodeType;
- (long long)getReportLocationType;
- (long long)getAudioPlayType;
- (_Bool)isContactCanReceiveSpeexVoice;
- (_Bool)containKFWorkerInfo;
- (id)getSpecifyWorkerOpenID;
- (long long)getConnectorMsgType;
- (_Bool)canSupportMessageNotify;
- (_Bool)isHardDeviceHideSubtitle;
- (_Bool)isInternalMyDeviceBrand;
- (_Bool)isInternalSportBrand;
- (id)getNearFieldDesc;
- (_Bool)isSupportPublicWifi;
- (_Bool)isHardDeviceTestBrand;
- (_Bool)isHardDeviceBrand;
- (_Bool)isEnterpriseDisableBrand;
- (_Bool)isEnterpriseWebSubBrand;
- (_Bool)isEnterpriseChatSubBrand;
- (_Bool)isEnterpriseSubBrand;
- (id)getEnterpriseSubBrandChatExtUrl;
- (id)getEnterpriseSubBrandUrl;
- (unsigned int)getEnterpriseSubBrandChildType;
- (_Bool)isEnterpriseBrand;
- (_Bool)isEnterpriseMainBrand;
- (id)getEnterpriseBrandFrozenWording;
- (id)getEnterpriseMainBrandUserName;
- (int)getBrandContactType;
- (id)getExternalInfoDictionary;
- (void)updateWithBizAttrChanged:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) Class superclass;

@end

@interface CQQContact : CBaseContact
{
    unsigned int m_uiAge;
    unsigned int m_uiUin;
    NSString *m_nsSign;
    NSString *m_nsAddress;
    NSString *m_nsBirthday;
}

@property(retain, nonatomic) NSString *m_nsBirthday; // @synthesize m_nsBirthday;
@property(retain, nonatomic) NSString *m_nsAddress; // @synthesize m_nsAddress;
@property(retain, nonatomic, setter=setNsSignature:) NSString *m_nsSign; // @synthesize m_nsSign;
@property(nonatomic) unsigned int m_uiUin; // @synthesize m_uiUin;
@property(nonatomic) unsigned int m_uiAge; // @synthesize m_uiAge;
- (id)description;
- (_Bool)isMyQQ;
- (_Bool)copyFrom:(id)arg1;
- (id)init;

@end

@interface WANewYearContactInfo : NSObject
{
    unsigned int _resSubType;
    unsigned int _startTime;
    unsigned int _endTime;
    unsigned int _reportID;
    NSString *_scanMatchText;
    NSString *_errorURL;
}

@property(retain, nonatomic) NSString *errorURL; // @synthesize errorURL=_errorURL;
@property(nonatomic) unsigned int reportID; // @synthesize reportID=_reportID;
@property(nonatomic) unsigned int endTime; // @synthesize endTime=_endTime;
@property(nonatomic) unsigned int startTime; // @synthesize startTime=_startTime;
@property(nonatomic) unsigned int resSubType; // @synthesize resSubType=_resSubType;
@property(retain, nonatomic) NSString *scanMatchText; // @synthesize scanMatchText=_scanMatchText;
- (_Bool)isInValidTime;

@end

@interface NewContactDB : NSObject <MMDBRRepairerExt, WCDBRestoreProtocol, RecoverCustomDataWorker>
{
    WCDataBase *m_contactDB;
    MMTimer *m_backupTimer;
    WCDataBaseTable *_m_tableContact;
    WCDataBaseTable *_m_tableQQContact;
    WCDataBaseTable *_m_tableMassSendContact;
}

+ (id)contactDBPathWithDocDir:(id)arg1 userName:(id)arg2;
+ (unsigned int)imgStatusToEnum:(id)arg1;
+ (id)imgStatusToString:(unsigned long long)arg1;
@property(retain) WCDataBaseTable *m_tableMassSendContact; // @synthesize m_tableMassSendContact=_m_tableMassSendContact;
@property(retain) WCDataBaseTable *m_tableQQContact; // @synthesize m_tableQQContact=_m_tableQQContact;
@property(retain) WCDataBaseTable *m_tableContact; // @synthesize m_tableContact=_m_tableContact;
- (Class)classFromTableName:(id)arg1;
- (long long)restoreRequireSize;
- (void)resetInitMark;
- (void)restore;
- (id)m_database;
- (void)restartBackup;
- (void)stopBackup;
- (void)clearBackup;
- (void)backup;
- (void)setAutoBackup:(_Bool)arg1;
- (void)willCustomRecoverData:(id)arg1 path:(id)arg2 needCatch:(_Bool *)arg3;
- (void)willRepairDB:(unsigned int)arg1 needCatch:(_Bool *)arg2;
- (_Bool)ModifyNotifyStatus:(id)arg1 withStatus:(unsigned int)arg2;
- (_Bool)IsContactExist:(id)arg1;
- (unsigned int)getContactCount;
- (_Bool)updateContact:(id)arg1;
- (_Bool)deleteContact:(id)arg1;
- (_Bool)addContact:(id)arg1;
- (_Bool)addContact:(id)arg1 log:(_Bool)arg2;
- (id)genDBContactFrom:(id)arg1;
- (_Bool)getAllContactNoExtInfoList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllContactList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllRemarkList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllUserName:(id)arg1;
- (_Bool)loadContactExtInfo:(id)arg1;
- (id)getContact:(id)arg1;
- (void)getFriendExtTableValue:(id)arg1 fromDBObject:(id)arg2;
- (void)getFriendTableValue:(id)arg1 fromDBObject:(id)arg2;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1 stateDidChanged:(CDUnknownBlockType)arg2;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1;
- (void)initDBWithDocDir:(id)arg1 userName:(id)arg2;
- (void)dealloc;
- (id)init;
- (void)createContactTable;
- (id)internalCreateTable:(id)arg1 tableClass:(Class)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface VideoParamsInfo : NSObject
{
    unsigned int _fileSize;
    unsigned int _duration;
    unsigned int _videoBitrate;
    unsigned int _audioBitrate;
    unsigned int _audioChannel;
    unsigned int _fps;
    unsigned int _width;
    unsigned int _height;
}

@property(nonatomic) unsigned int height; // @synthesize height=_height;
@property(nonatomic) unsigned int width; // @synthesize width=_width;
@property(nonatomic) unsigned int fps; // @synthesize fps=_fps;
@property(nonatomic) unsigned int audioChannel; // @synthesize audioChannel=_audioChannel;
@property(nonatomic) unsigned int audioBitrate; // @synthesize audioBitrate=_audioBitrate;
@property(nonatomic) unsigned int videoBitrate; // @synthesize videoBitrate=_videoBitrate;
@property(nonatomic) unsigned int duration; // @synthesize duration=_duration;
@property(nonatomic) unsigned int fileSize; // @synthesize fileSize=_fileSize;

@end

@interface VideoParamsSource : NSObject
{
    NSURL *_videoURL;
    MMAsset *_videoMMAsset;
}

+ (id)videoParamsSourceFromMMAsset:(id)arg1;
+ (id)videoParamsSourceFromURL:(id)arg1;
@property(retain, nonatomic) MMAsset *videoMMAsset; // @synthesize videoMMAsset=_videoMMAsset;
@property(retain, nonatomic) NSURL *videoURL; // @synthesize videoURL=_videoURL;
- (id)genVideoParamsInfoFromAVAsset:(id)arg1;
- (id)genVideoParamsInfoFromMMAsset:(id)arg1;
- (id)genVideoParamsInfoFromURL:(id)arg1;
- (id)genVideoParamsInfo;

@end

@interface VideoUploadStatInfo : NSObject
{
    _Bool _sourceVideoContainsWXTag;
    unsigned int _uploadStartTime;
    unsigned int _cpStatus;
    unsigned int _sendScene;
    NSString *_toUsername;
    NSString *_fileId;
    NSString *_videoNewMd5;
    NSString *_msgSource;
    NSString *_snsCommitId;
    VideoParamsSource *_oriVideoParamsSource;
    VideoParamsSource *_cpVideoParamsSource;
    NSString *_cdnIp;
    NSString *_snsUrl;
    VideoParamsInfo *_srcVideoParams;
    VideoParamsInfo *_cpVideoParams;
}

@property(retain, nonatomic) VideoParamsInfo *cpVideoParams; // @synthesize cpVideoParams=_cpVideoParams;
@property(retain, nonatomic) VideoParamsInfo *srcVideoParams; // @synthesize srcVideoParams=_srcVideoParams;
@property(nonatomic) _Bool sourceVideoContainsWXTag; // @synthesize sourceVideoContainsWXTag=_sourceVideoContainsWXTag;
@property(retain, nonatomic) NSString *snsUrl; // @synthesize snsUrl=_snsUrl;
@property(retain, nonatomic) NSString *cdnIp; // @synthesize cdnIp=_cdnIp;
@property(nonatomic) unsigned int sendScene; // @synthesize sendScene=_sendScene;
@property(nonatomic) unsigned int cpStatus; // @synthesize cpStatus=_cpStatus;
@property(retain, nonatomic) VideoParamsSource *cpVideoParamsSource; // @synthesize cpVideoParamsSource=_cpVideoParamsSource;
@property(retain, nonatomic) VideoParamsSource *oriVideoParamsSource; // @synthesize oriVideoParamsSource=_oriVideoParamsSource;
@property(nonatomic) unsigned int uploadStartTime; // @synthesize uploadStartTime=_uploadStartTime;
@property(retain, nonatomic) NSString *snsCommitId; // @synthesize snsCommitId=_snsCommitId;
@property(retain, nonatomic) NSString *msgSource; // @synthesize msgSource=_msgSource;
@property(retain, nonatomic) NSString *videoNewMd5; // @synthesize videoNewMd5=_videoNewMd5;
@property(retain, nonatomic) NSString *fileId; // @synthesize fileId=_fileId;
@property(retain, nonatomic) NSString *toUsername; // @synthesize toUsername=_toUsername;
- (void)reportKV;
- (id)getBigVideoStatInfo;
- (void)mergeInfoFromSnsTaskInfo:(id)arg1;
- (void)mergeInfoFromTaskInfo:(id)arg1;
- (void)mergeInfoFromUploadTaskInfo:(id)arg1;
- (id)init;

@end

@interface ChatRoomData : NSObject
{
    NSMutableDictionary *m_dicData;
    unsigned int m_maxMemberCount;
    unsigned int m_chatRoomVersion;
    unsigned int m_uiLocalMemberVersion;
    _Bool isSimplify;
    NSRecursiveLock *_lock;
}

@property(nonatomic) _Bool isSimplify; // @synthesize isSimplify;
@property(nonatomic) unsigned int localMemberVersion; // @synthesize localMemberVersion=m_uiLocalMemberVersion;
@property(nonatomic) unsigned int chatRoomVersion; // @synthesize chatRoomVersion=m_chatRoomVersion;
@property(nonatomic) unsigned int maxMemberCount; // @synthesize maxMemberCount=m_maxMemberCount;
- (void)updateDicData:(struct XmlReaderNode_t *)arg1;
- (unsigned int)getXmlNodeIntValue:(struct XmlReaderNode_t *)arg1 forName:(const char *)arg2;
- (_Bool)isUndeliverCountOpen;
- (void)setUndeliverCountOpen:(_Bool)arg1;
- (_Bool)isShowDislayName;
- (void)setShowDislayName:(_Bool)arg1;
- (void)setInviterNameName:(id)arg1 forUserName:(id)arg2;
- (id)getInviterNameForUsername:(id)arg1;
- (id)getDislayNameForUserName:(id)arg1;
- (void)setDislayName:(id)arg1 forUserName:(id)arg2;
- (void)updateChatRoomData:(struct XmlReaderNode_t *)arg1;
- (id)getDataDescription;
- (id)getDataXml;
- (void)parseData:(id)arg1;
- (void)setDataForUserName:(id)arg1 key:(id)arg2 value:(id)arg3;
- (id)getDataForUserName:(id)arg1 key:(id)arg2;
- (void)mergeOldDetail:(id)arg1;
- (void)merge:(id)arg1;
- (id)initWithNewChatRoomData:(id)arg1;
- (id)initWithChatRoomData:(id)arg1;
- (id)init;

@end

@interface CContactMgr : MMService <MessageObserverDelegate, IContactProfileMgrExt, PBMessageObserverDelegate, IAcctStorageMgrExt, IMMLanguageMgrExt, IBrandAttrMgrExt>
{
    NSRecursiveLock *m_oLock;
    unsigned int m_uiLoadedType;
    CContactDB *m_oContactDB;
    NewContactDB *m_oNewContactDB;
    CContactOPLog *m_oContactOPLog;
    NSRecursiveLock *m_oMainControllerLock;
    NSMutableDictionary *m_dicRemark;
    NSMutableDictionary *m_dicLastAccessTime;
    NSMutableDictionary *m_dicContacts;
    NSMutableDictionary *m_dicEncodeContacts;
    NSMutableDictionary *m_mapLastGetTime;
    NSMutableDictionary *m_dicHardCodeUsers;
    unsigned int m_uiDBVersion;
    _Bool m_shouldContactDBMigration;
    _Bool m_bContactDBMigrationFinished;
    unsigned int m_uiMaxStrangerCache;
    _Bool m_bOpenStrangerCache;
}

- (id)getAllContactUserName;
- (id)getContactForSearchByName:(id)arg1;
- (_Bool)isOpenStrangerCache;
- (void)callModifyContactForCPState:(id)arg1;
- (_Bool)isHeadImgUpdated:(id)arg1 Local:(id)arg2;
- (void)onBrandContactModified:(id)arg1 withAttrChanged:(id)arg2;
- (_Bool)ChangeNotifyStatus:(id)arg1 withStatus:(_Bool)arg2 sync:(_Bool)arg3;
- (_Bool)ChangeNotifyStatusForChatRoom:(id)arg1 withStatus:(_Bool)arg2 sync:(_Bool)arg3;
- (void)main_onPushModifyContact:(id)arg1;
- (id)thread_onBatchModifyChatRoomMember:(id)arg1;
- (id)thread_onpushBatchModContact:(id)arg1;
- (void)main_onPushAddContact:(id)arg1;
- (void)main_onPushDeleteContact:(id)arg1;
- (void)setSelfContactUpdated;
- (id)getSelfContact;
- (_Bool)updateContactToCache:(id)arg1;
- (_Bool)shouldUpdateContact:(id)arg1;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)onGetContact:(id)arg1;
- (id)HandleMemContact:(id)arg1;
- (void)MainThread_ReloadMemContact:(id)arg1;
- (void)thread_ReloadMemConact:(id)arg1 ChatRoom:(id)arg2;
- (id)thread_HandleMemContact:(id)arg1;
- (void)MessageReturn:(unsigned int)arg1 MessageInfo:(id)arg2 Event:(unsigned int)arg3;
- (void)main_onPushBatchModContact:(id)arg1;
- (void)onLanguageChange;
- (void)onSettingChange;
- (void)onServiceClearData;
- (void)onServiceReloadData;
- (_Bool)onServiceMemoryWarning;
- (void)updateContactLocalData;
- (void)fixContactPluginOldData;
- (id)getGroupCardMemberList:(id)arg1;
- (_Bool)getContactsFromServer:(id)arg1 chatContact:(id)arg2 withScene:(int)arg3 withTicket:(id)arg4 usrData:(id)arg5;
- (_Bool)getInviteeContactsFromServer:(id)arg1 withTicket:(id)arg2;
- (_Bool)getContactsFromServer:(id)arg1;
- (_Bool)getContactsFromServer:(id)arg1 chatContact:(id)arg2;
- (_Bool)getContactsFromSvrForTempChat:(id)arg1;
- (_Bool)internalGetContactsFromSvr:(id)arg1 chatContact:(id)arg2 usrData:(id)arg3;
- (void)addToGetContactMap:(id)arg1;
- (_Bool)checkIfForbiddenGetContact:(id)arg1;
- (_Bool)syncAllSXContact;
- (void)tryLoadExtInfoForContact:(id)arg1;
- (void)reloadContact:(id)arg1;
- (_Bool)delayLoadAllContactInBackGround;
- (void)reportIDKey:(id)arg1 stranger:(id)arg2;
- (void)thread_saveContactImageStatus:(id)arg1 Status:(id)arg2 Image:(id)arg3 Url:(id)arg4;
- (void)reloadContactImageStatus:(id)arg1 Status:(id)arg2 Image:(id)arg3;
- (_Bool)setHDHeadUpdated:(id)arg1;
- (_Bool)setContact:(id)arg1 chatState:(unsigned int)arg2;
- (_Bool)setContact:(id)arg1 textTranslateOpen:(_Bool)arg2 sync:(_Bool)arg3;
- (_Bool)setLocalContactToUntopSession:(id)arg1;
- (_Bool)setContact:(id)arg1 sessionTop:(_Bool)arg2 sync:(_Bool)arg3;
- (_Bool)setContact:(id)arg1 notifyOpen:(_Bool)arg2 sync:(_Bool)arg3;
- (_Bool)setContact:(id)arg1 hideHashPhone:(_Bool)arg2 sync:(_Bool)arg3;
- (_Bool)setContact:(id)arg1 watchContact:(_Bool)arg2 sync:(_Bool)arg3;
- (_Bool)setContact:(id)arg1 favour:(_Bool)arg2 sync:(_Bool)arg3;
- (_Bool)setLocalContact:(id)arg1 notifyOpen:(_Bool)arg2;
- (_Bool)setContact:(id)arg1 typeBit:(unsigned int)arg2 set:(_Bool)arg3 sync:(_Bool)arg4;
- (_Bool)setContact:(id)arg1 typeBit:(unsigned int)arg2 set:(_Bool)arg3 sync:(_Bool)arg4 localSet:(_Bool)arg5;
- (_Bool)setNoBlack:(id)arg1 sync:(_Bool)arg2;
- (_Bool)setBlack:(id)arg1 sync:(_Bool)arg2;
- (_Bool)setNoBlack:(id)arg1;
- (_Bool)setBlack:(id)arg1;
- (_Bool)setBlack:(id)arg1 blackFlag:(_Bool)arg2 sync:(_Bool)arg3;
- (_Bool)setContact:(id)arg1 chatRoomAccessType:(unsigned int)arg2;
- (_Bool)setContact:(id)arg1 RoomDetail:(id)arg2;
- (_Bool)setContact:(id)arg1 chatRoomData:(id)arg2;
- (_Bool)setContact:(id)arg1 owner:(id)arg2;
- (_Bool)setContact:(id)arg1 snsBlack:(_Bool)arg2;
- (_Bool)setContact:(id)arg1 mobileIdentify:(id)arg2;
- (_Bool)setContact:(id)arg1 googleContactName:(id)arg2;
- (_Bool)setContact:(id)arg1 googleContactNickName:(id)arg2;
- (_Bool)clearDraftForContact:(id)arg1;
- (_Bool)setContact:(id)arg1 nickName:(id)arg2;
- (_Bool)setContact:(id)arg1 cardUrl:(id)arg2;
- (_Bool)setContact:(id)arg1 cardDesc:(id)arg2;
- (_Bool)setPhone:(id)arg1 Contact:(id)arg2;
- (_Bool)setContact:(id)arg1 remark:(id)arg2;
- (_Bool)setContact:(id)arg1 remark:(id)arg2 hideHashPhone:(_Bool)arg3;
- (void)modifyContactNickName:(id)arg1 nickName:(id)arg2 callMod:(_Bool)arg3;
- (_Bool)RemoveContactFromChatList:(id)arg1;
- (_Bool)deleteContact:(id)arg1 listType:(unsigned int)arg2 andScene:(unsigned int)arg3 sync:(_Bool)arg4 local:(_Bool)arg5;
- (_Bool)deleteContact:(id)arg1 listType:(unsigned int)arg2 andScene:(unsigned int)arg3 sync:(_Bool)arg4;
- (_Bool)deleteContact:(id)arg1 listType:(unsigned int)arg2 sync:(_Bool)arg3;
- (_Bool)deleteContact:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)deleteContactLocal:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)addFromMobileContact:(id)arg1;
- (_Bool)addFromQQContact:(id)arg1;
- (_Bool)addLocalContact:(id)arg1 listType:(unsigned int)arg2;
- (void)addContactInternal:(id)arg1;
- (_Bool)addContact:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)addContact:(id)arg1 listType:(unsigned int)arg2 opLog:(_Bool)arg3;
- (id)getAllBrandContacts;
- (id)getAllEnterpriseMainBrandContacts;
- (id)getContactList:(unsigned int)arg1 contactType:(unsigned int)arg2 needLoadExt:(_Bool)arg3;
- (id)getContactList:(unsigned int)arg1 contactType:(unsigned int)arg2;
- (_Bool)isBelongToMMContactInCache:(id)arg1;
- (_Bool)isInContactList:(id)arg1;
- (_Bool)isContactExistLocal:(id)arg1;
- (_Bool)isContactBlack:(id)arg1;
- (id)getContactByNameFromCache:(id)arg1;
- (id)getContactByNameFromDB:(id)arg1;
- (id)getContactByName:(id)arg1;
- (void)updateCache:(id)arg1;
- (void)initDB:(id)arg1 lock:(id)arg2;
- (void)updateNewDB:(id)arg1 NewUser:(_Bool)arg2;
- (_Bool)isUserNewDB;
- (void)onPushDeleteContact:(id)arg1;
- (void)onPushModifyContact:(id)arg1 updateImage:(_Bool)arg2;
- (void)handleLocalField:(id)arg1 oldContact:(id)arg2;
- (id)reloadContact:(id)arg1 mergeImage:(id)arg2;
- (void)callOnRemoveContactFromAddressBook:(id)arg1;
- (void)callOnModifyContactHeadImageExt:(id)arg1;
- (void)callOnDeleteExt:(id)arg1;
- (void)callOnModifyExt:(id)arg1;
- (void)internalDeleteContact:(id)arg1;
- (void)internalModifyContact:(id)arg1;
- (void)internalNewContact:(id)arg1;
- (void)mergeChatRoomData:(id)arg1 oldContact:(id)arg2;
- (void)handleWeChatTeamNickName:(id)arg1;
- (void)handleOfficalContactName:(id)arg1;
- (_Bool)isContactMatch:(id)arg1 listType:(unsigned int)arg2 contactType:(unsigned int)arg3;
- (int)interalReloadContacts:(unsigned int)arg1 needLoadExt:(_Bool)arg2;
- (_Bool)isHardCodeContact:(id)arg1;
- (void)addHardCodeContacts;
- (void)addAddHardcodeContact:(id)arg1 selector:(SEL)arg2;
- (id)generateOfficialContact:(id)arg1;
- (id)generatePluginContactNoListContact:(id)arg1;
- (id)generatePluginContact:(id)arg1;
- (id)generatePluginContact:(id)arg1 uiType:(unsigned int)arg2;
- (void)internalUpdateContactLocalDataWithUserName:(id)arg1;
- (void)refreshContactLocalData;
- (void)refreshPluginNickName:(_Bool)arg1;
- (void)addDictoryDataToCache:(id)arg1 listType:(unsigned int)arg2;
- (int)autoreloadContacts:(unsigned int)arg1 needLoadExt:(_Bool)arg2;
- (int)autoreloadContacts:(unsigned int)arg1;
- (id)addSelfContactToCache;
- (_Bool)isCacheAllLoaded;
- (void)dealloc;
- (void)removeListen;
- (void)initListen;
- (id)init;
- (_Bool)SetFriendMetaFlag:(unsigned int)arg1 ForUser:(id)arg2;
- (_Bool)SetLastUpdateTime:(unsigned int)arg1 ForUser:(id)arg2;
- (_Bool)ModifyNotifyStatus:(id)arg1 withStatus:(unsigned int)arg2;
- (_Bool)thread_onPushModifyContact:(id)arg1 isInit:(_Bool)arg2;
- (_Bool)thread_BatchModifyContact:(id)arg1;
- (id)addOrUpdateContactToDB:(id)arg1 listType:(unsigned int)arg2 add:(_Bool *)arg3 modify:(_Bool *)arg4;
- (_Bool)getAllRemarkList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllUserName:(id)arg1;
- (_Bool)getAllContactNoExtInfoList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllContactList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)migrationContacts:(unsigned int)arg1 first:(_Bool)arg2;
- (void)reportMigrationStat:(unsigned int)arg1 status:(unsigned int)arg2;
- (_Bool)splist_migrationContactList:(id)arg1;
- (void)setMigrationFinished;
- (_Bool)loadContactExtInfo:(id)arg1;
- (_Bool)updateContactToDb:(id)arg1;
- (_Bool)addContactToDb:(id)arg1;
- (_Bool)removeContactFromDB:(id)arg1;
- (id)getContactFromDB:(id)arg1;
- (void)removeContactFromDic:(id)arg1;
- (void)setContactToDic:(id)arg1 forKey:(id)arg2;
- (id)getContactFromDic:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface CMessageDB : NSObject
{
    CMMDB *m_oMMDB;
}

@property(retain, nonatomic) CMMDB *m_oMMDB; // @synthesize m_oMMDB;
- (void)setMessageUnreadCondition:(struct WCDBConditionBase *)arg1 from:(unsigned int)arg2;
- (id)getImageMsg:(id)arg1 beforeCreateTime:(unsigned int)arg2 limit:(unsigned int)arg3;
- (id)getImageMsg:(id)arg1 limit:(unsigned int)arg2;
- (void)setMessageUnreadCondition:(struct WCDBConditionBase *)arg1;
- (void)setMessageUnreadConditionIncludingNewXML:(struct WCDBConditionBase *)arg1;
- (void)fillDBMsg:(id)arg1 andProperty:(vector_ *)arg2 fromMsgWrap:(id)arg3 des:(unsigned int)arg4;
- (void)HandleMessage:(id)arg1 ChatName:(id)arg2 Des:(unsigned int)arg3;
- (id)GetLocalUsrName:(id)arg1;
- (unsigned int)GetUnReadCountInHello:(id)arg1;
- (unsigned int)GetCountInHello:(id)arg1;
- (unsigned int)GetSayHelloStatus:(id)arg1 LocalID:(unsigned int)arg2;
- (_Bool)SetSayHelloStatus:(id)arg1 LocalID:(unsigned int)arg2 Status:(unsigned int)arg3;
- (_Bool)ClearHelloUnRead:(id)arg1 HelloUser:(id)arg2;
- (void)DelHelloMsg:(id)arg1 HelloUser:(id)arg2;
- (id)GetHelloMsg:(id)arg1 HelloUser:(id)arg2 Limit:(unsigned int)arg3 OnlyTo:(_Bool)arg4;
- (id)GetHelloUsers:(id)arg1 Limit:(unsigned int)arg2 OnlyUnread:(_Bool)arg3;
- (id)GetHelloMsgForSyncRead:(id)arg1 Where:(const struct WCDBConditionBase *)arg2;
- (id)GetHelloMsg:(id)arg1 Where:(const struct WCDBConditionBase *)arg2 Order:(const struct WCDBConditionBase *)arg3 Limit:(unsigned int)arg4;
- (void)AddHelloMsg:(id)arg1 MsgWrap:(id)arg2 HelloUser:(id)arg3 OpCode:(unsigned int)arg4 DES:(unsigned int)arg5 checkCreateTime:(_Bool)arg6 status:(unsigned int)arg7;
- (unsigned int)GetImgOrVideoMsgCount:(id)arg1;
- (unsigned int)GetImgOrVideoMsgCount:(id)arg1 FromID:(unsigned int)arg2 CreateTime:(unsigned int)arg3;
- (id)GetImgOrVideoOrAppNextMsg:(id)arg1 FromID:(unsigned int)arg2 Limit:(unsigned int)arg3 CreateTime:(unsigned int)arg4;
- (id)GetImgOrVideoLastMsg:(id)arg1;
- (id)GetImgOrVideoOrAppLastMsg:(id)arg1 FromID:(unsigned int)arg2 Limit:(unsigned int)arg3 CreateTime:(unsigned int)arg4;
- (id)GetAppMsgList:(id)arg1 FromID:(unsigned int)arg2 CreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4 Where:(struct WCDBConditionBase)arg5;
- (id)GetAppMsgList:(id)arg1 FromID:(unsigned int)arg2 CreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4;
- (id)GetAppMsgList:(id)arg1 AfterID:(unsigned int)arg2 CreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4;
- (id)GetImgAndVideoMsgList:(id)arg1;
- (id)GetImgMsgList:(id)arg1;
- (id)GetMsgForFlowWall:(id)arg1 Where:(const struct WCDBConditionBase *)arg2 Order:(const struct WCDBConditionBase *)arg3 Limit:(unsigned int)arg4;
- (unsigned int)GetImgMsgCount:(id)arg1;
- (unsigned int)GetImgMsgCount:(id)arg1 FromID:(unsigned int)arg2 CreateTime:(unsigned int)arg3;
- (id)GetImgLastMsg:(id)arg1;
- (id)GetImgLastMsg:(id)arg1 FromID:(unsigned int)arg2 Limit:(unsigned int)arg3 CreateTime:(unsigned int)arg4;
- (id)GetImgNextMsg:(id)arg1 FromID:(unsigned int)arg2 Limit:(unsigned int)arg3 CreateTime:(unsigned int)arg4;
- (void)UpdatePimMsg:(id)arg1 LocalID:(unsigned int)arg2 Content:(id)arg3 CreateTime:(unsigned int)arg4;
- (void)UpdateVideoMessage:(id)arg1 MsgWrap:(id)arg2;
- (void)UpdateMessage:(id)arg1 MsgWrap:(id)arg2;
- (void)UpdateVoiceMessage:(id)arg1 MsgWrap:(id)arg2;
- (void)UpdateVoiceStatus:(id)arg1 LocalID:(unsigned int)arg2 DownloadStatus:(unsigned int)arg3;
- (id)getMessageWrapArray:(id)arg1 bizId:(id)arg2;
- (_Bool)addMessageToBizExtTable:(id)arg1;
- (_Bool)AddMessageToChatExt:(id)arg1 MsgWrap:(id)arg2;
- (unsigned int)GetMesCount:(id)arg1 MesType:(unsigned int)arg2;
- (unsigned int)GetAllMesCount:(id)arg1;
- (unsigned int)GetUnReadCount:(id)arg1 CreateTimeLargerThan:(unsigned int)arg2;
- (unsigned int)GetUnReadCount:(id)arg1;
- (unsigned int)GetTextMsgCount:(id)arg1 FromID:(unsigned int)arg2 ToID:(unsigned int)arg3;
- (_Bool)isMessageExist:(id)arg1 MsgSvrId:(long long)arg2;
- (void)DelAllMsgs:(id)arg1;
- (void)AutoEmptyTrashTable;
- (void)EmptyTrashTable;
- (void)DelMsg:(id)arg1 MsgList:(id)arg2 DelAll:(_Bool)arg3;
- (void)TransferMsgFromChatToDuplicate:(id)arg1;
- (void)ClearUnReadForSync:(id)arg1 CreateTime:(unsigned int)arg2;
- (_Bool)ClearUnRead:(id)arg1 FromID:(unsigned int)arg2 ToID:(unsigned int)arg3;
- (void)DropChatTable:(id)arg1;
- (void)ModVoipMsgStatus:(id)arg1 MsgWrap:(id)arg2;
- (void)ModMsgByBitSet:(id)arg1 MsgWrap:(id)arg2 BitSet:(unsigned int)arg3;
- (void)ModLocationMsg:(id)arg1 MsgWrap:(id)arg2;
- (void)ModMsg:(id)arg1 MsgWrap:(id)arg2;
- (_Bool)RemoveOldRevokeMessagesBefore:(unsigned int)arg1;
- (_Bool)InsertRevokeMessage:(id)arg1;
- (id)GetRevokeMessage:(long long)arg1;
- (id)GetFirstUnreadMsgIncludingNewXML:(id)arg1;
- (id)GetFirstUnreadMsg:(id)arg1;
- (id)GetLastMsgToUsr:(id)arg1;
- (id)GetLastMsgFromUsr:(id)arg1;
- (id)GetLastInsertMsg:(id)arg1;
- (id)GetLastMsg:(id)arg1;
- (id)GetTextMsg:(id)arg1 FromID:(unsigned int)arg2 Limit:(unsigned int)arg3;
- (id)GetTextMsg:(id)arg1 FromID:(unsigned int)arg2 ToID:(unsigned int)arg3;
- (id)GetMsg:(id)arg1 BizMsgClientID:(id)arg2;
- (id)GetMsg:(id)arg1 n64SvrID:(long long)arg2;
- (id)GetMsg:(id)arg1 LocalID:(unsigned int)arg2;
- (id)QueryMsgByCreateTime:(id)arg1 FromID:(unsigned int)arg2 FromCreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4 Where:(const struct WCDBConditionBase *)arg5;
- (id)GetDownMsgByCreateTime:(id)arg1 FromID:(unsigned int)arg2 FromCreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4 LeftCount:(unsigned int *)arg5;
- (id)GetMsgByCreateTime:(id)arg1 FromID:(unsigned int)arg2 FromCreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4 LeftCount:(unsigned int *)arg5 FromSequence:(unsigned int)arg6;
- (id)GetMsgByCreateTime:(id)arg1 FromID:(unsigned int)arg2 FromCreateTime:(unsigned int)arg3 Limit:(unsigned int)arg4 LeftCount:(unsigned int *)arg5;
- (id)GetDownMsg:(id)arg1 FromID:(unsigned int)arg2 Limit:(unsigned int)arg3;
- (id)GetMsg:(id)arg1 FromID:(unsigned int)arg2 Limit:(unsigned int)arg3;
- (id)GetMsgForSyncRead:(id)arg1 Where:(const struct WCDBConditionBase *)arg2;
- (id)GetMsg:(id)arg1 Where:(const struct WCDBConditionBase *)arg2 order:(const struct WCDBConditionBase *)arg3 Limit:(unsigned int)arg4;
- (const struct WCDBConditionBase *)orderOfAscCreateTimeAndMsgLocalId;
- (const struct WCDBConditionBase *)orderOfDescCreateTimeAndMsgLocalId;
- (void)AddBackupMsg:(id)arg1 MsgWrap:(id)arg2;
- (void)AddMsg:(id)arg1 MsgWrap:(id)arg2 withTimeFixed:(_Bool)arg3;
- (void)AddMsg:(id)arg1 MsgWrap:(id)arg2;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1 stateDidChanged:(CDUnknownBlockType)arg2;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1;
- (_Bool)rollbackTransaction:(id)arg1;
- (_Bool)commitTransaction:(id)arg1;
- (id)beginTransaction;
- (void)InitDB:(id)arg1;
- (id)init;

@end

@interface CMMDB : NSObject <WCDataBaseEventDelegate>
{
    NSRecursiveLock *m_lockMMDB;
    NSMutableSet *m_setMessageCreatedTable;
    NSMutableSet *m_setMessageExtCreatedTable;
    OpLogDB *m_oplogWcdb;
    MMTimer *m_backupTimer;
    _Bool m_checkCorruption;
    WCDataBase *m_db;
    NewContactDB *m_contactDB;
    WCDataBaseTable *m_tableContact;
    WCDataBaseTable *m_tableContactExt;
    WCDataBaseTable *m_tableContactMeta;
    WCDataBaseTable *m_tableQQContact;
    WCDataBaseTable *m_tableSendMsg;
    WCDataBaseTable *m_tableUploadVoice;
    WCDataBaseTable *m_tableDownloadVoice;
    WCDataBaseTable *m_tableRevokeMsg;
    WCDataBaseTable *m_tableEmoticon;
    WCDataBaseTable *m_tableEmoticonUpload;
    WCDataBaseTable *m_tableEmoticonDownload;
    WCDataBaseTable *m_tableEmoticonPackage;
    WCDataBaseTable *m_tableBottle;
    WCDataBaseTable *m_tableBottleContact;
    WCDataBaseTable *m_tableMassSendContact;
    WCDataBaseTable *_m_tableMessageBizExt;
}

+ (Class)getClassFromMessageTableName:(id)arg1;
+ (id)md5StringFromUserName:(id)arg1;
+ (id)helloMessageTableName:(id)arg1;
+ (id)messageExtTableName:(id)arg1;
+ (id)messageTableName:(id)arg1;
+ (id)dbPathWithDocDir:(id)arg1 userName:(id)arg2;
@property(retain) WCDataBaseTable *m_tableMessageBizExt; // @synthesize m_tableMessageBizExt=_m_tableMessageBizExt;
@property(retain, nonatomic) OpLogDB *m_oplogWcdb; // @synthesize m_oplogWcdb;
@property(retain) WCDataBaseTable *m_tableMassSendContact; // @synthesize m_tableMassSendContact;
@property(retain) WCDataBaseTable *m_tableBottleContact; // @synthesize m_tableBottleContact;
@property(retain) WCDataBaseTable *m_tableBottle; // @synthesize m_tableBottle;
@property(retain) WCDataBaseTable *m_tableEmoticonPackage; // @synthesize m_tableEmoticonPackage;
@property(retain) WCDataBaseTable *m_tableEmoticonDownload; // @synthesize m_tableEmoticonDownload;
@property(retain) WCDataBaseTable *m_tableEmoticonUpload; // @synthesize m_tableEmoticonUpload;
@property(retain) WCDataBaseTable *m_tableEmoticon; // @synthesize m_tableEmoticon;
@property(retain) WCDataBaseTable *m_tableRevokeMsg; // @synthesize m_tableRevokeMsg;
@property(retain) WCDataBaseTable *m_tableDownloadVoice; // @synthesize m_tableDownloadVoice;
@property(retain) WCDataBaseTable *m_tableUploadVoice; // @synthesize m_tableUploadVoice;
@property(retain) WCDataBaseTable *m_tableSendMsg; // @synthesize m_tableSendMsg;
@property(retain) WCDataBaseTable *m_tableQQContact; // @synthesize m_tableQQContact;
@property(retain) WCDataBaseTable *m_tableContactMeta; // @synthesize m_tableContactMeta;
@property(retain) WCDataBaseTable *m_tableContactExt; // @synthesize m_tableContactExt;
@property(retain) WCDataBaseTable *m_tableContact; // @synthesize m_tableContact;
@property(retain) NewContactDB *m_contactDB; // @synthesize m_contactDB;
@property(retain) WCDataBase *m_db; // @synthesize m_db;
- (_Bool)onDatabaseCorrupt:(id)arg1 errorCode:(int)arg2 opType:(unsigned int)arg3;
- (void)clearMessageExtCreatedTableCache;
- (void)removeMessageExtCreatedTableCache:(id)arg1;
- (void)addMessageExtCreatedTableCache:(id)arg1;
- (_Bool)isMessageExtTableCreated:(id)arg1;
- (void)clearMessageCreatedTableCache;
- (void)removeMessageCreatedTableCache:(id)arg1;
- (void)addMessageCreatedTableCache:(id)arg1;
- (_Bool)isMessageTableCreated:(id)arg1;
- (void)setupMessageCreatedTableCache;
- (void)CreateMessageBizExtTable;
- (id)GetHelloMessageTable:(id)arg1;
- (_Bool)CreateHelloMessageTable:(id)arg1;
- (void)emptyTrashTable;
- (void)autoEmptyTrashTable;
- (void)TrashMessageAndExtTables:(id)arg1;
- (void)TrashMessageAndExtTable:(id)arg1;
- (void)ClearMessageAndExtCreatedTableCache;
- (void)DropMessageExtTable:(id)arg1;
- (id)GetMessageExtTable:(id)arg1;
- (_Bool)CreateMessageExtTable:(id)arg1;
- (void)DropMessageTable:(id)arg1;
- (id)GetMessageTable:(id)arg1;
- (_Bool)CreateMessageTable:(id)arg1;
- (void)setupEmiticonPackageTable;
- (void)setupTables;
- (id)internalCreateTable:(id)arg1 tableClass:(Class)arg2;
- (void)createOtherTable;
- (void)createBottleTable;
- (void)createEmoticonTable;
- (void)createMessagesTable;
- (void)createContactTable;
- (void)createTables;
- (void)clearTables;
- (void)closeDBBeforeInit;
- (void)onGenerateNewHandle:(struct sqlite3 *)arg1;
- (void)onTransactionRollback;
- (void)DropEmoticonDownloadTable;
- (_Bool)IsEmoticonPackageTableExist;
- (_Bool)CreateEmoticonPackageTable;
- (id)dbPaths;
- (id)dbPath;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1 stateDidChanged:(CDUnknownBlockType)arg2;
- (_Bool)runTransaction:(CDUnknownBlockType)arg1;
- (_Bool)rollbackTransaction:(id)arg1;
- (_Bool)commitTransaction:(id)arg1;
- (id)beginTransaction;
- (void)CloseAndPreventOtherThreadsInBlock:(CDUnknownBlockType)arg1;
- (void)Close;
- (void)InitMMDB:(id)arg1 UsrName:(id)arg2 NewUser:(_Bool *)arg3;
- (void)dealloc;
- (id)init;
- (_Bool)DeleteMassSendContact:(id)arg1;
- (id)GetAllMassSendContact;
- (_Bool)DeleteBottle:(unsigned int)arg1;
- (id)GetAllBottle:(const vector_ *)arg1;
- (id)GetBottleByLocalID:(unsigned int)arg1 onProperty:(const vector_ *)arg2;
- (unsigned int)GetServerIDInBottleByLocalID:(unsigned int)arg1;
- (unsigned int)GetLocalIDInBottleByBottleID:(id)arg1;
- (_Bool)UpdateBottle:(id)arg1 onProperty:(const vector_ *)arg2 byLocalId:(unsigned int)arg3;
- (unsigned int)InsertBottle:(id)arg1 onProperty:(const vector_ *)arg2;
- (_Bool)DeleteBottleContact:(id)arg1;
- (unsigned int)GetCountOfBottleContact;
- (id)GetAllBottleContact:(const vector_ *)arg1;
- (id)GetBottleContact:(id)arg1 onProperty:(const vector_ *)arg2;
- (_Bool)UpdateBottleContact:(id)arg1 onProperty:(const vector_ *)arg2 byUserName:(id)arg3;
- (_Bool)InsertBottleContact:(id)arg1 onProperty:(const vector_ *)arg2;
- (void)dropUploadVoiceTable;
- (void)dropDownloadVoiceTable;
- (id)GetAllUploadVoice;
- (id)GetAllDownloadVoice;
- (_Bool)deleteMessageBizExtWithChatname:(id)arg1;
- (id)getMessageBizExtArrayOnProperty:(const vector_ *)arg1 where:(const struct WCDBConditionBase *)arg2;
- (_Bool)insertMessageBizExt:(id)arg1 onProperty:(const vector_ *)arg2;
- (_Bool)isMessageBizExtExistWithChatname:(id)arg1 localId:(unsigned int)arg2;
- (_Bool)DeleteMessageExtByChatName:(id)arg1 localId:(unsigned int)arg2;
- (_Bool)UpdateMessageExtFlag:(unsigned int)arg1 byChatName:(id)arg2 localId:(unsigned int)arg3;
- (_Bool)UpdateMessageExtSource:(id)arg1 byChatName:(id)arg2 localId:(unsigned int)arg3;
- (id)GetMsgExtInMessageExtWithTable:(id)arg1 chatName:(id)arg2 localId:(unsigned int)arg3;
- (id)GetMessageExtyChatName:(id)arg1 OnProperty:(const vector_ *)arg2 where:(const struct WCDBConditionBase *)arg3;
- (id)GetMsgSourceInMessageExtWithTable:(id)arg1 chatName:(id)arg2 localId:(unsigned int)arg3;
- (id)GetMsgSourceInMessageExt:(id)arg1 localId:(unsigned int)arg2;
- (_Bool)InsertMessageExt:(id)arg1 withChatName:(id)arg2 onProperty:(const vector_ *)arg3;
- (_Bool)IsMessageExtExistWithChatName:(id)arg1 localId:(unsigned int)arg2;
- (unsigned int)GetMaxMessageLocalIdByChatName:(id)arg1 where:(const struct WCDBConditionBase *)arg2;
- (unsigned int)GetMessageCountByChatName:(id)arg1 where:(const struct WCDBConditionBase *)arg2;
- (_Bool)DeleteMessageByChatName:(id)arg1 localId:(unsigned int)arg2;
- (_Bool)UpdateMessageStatus:(unsigned int)arg1 byChatName:(id)arg2 localId:(unsigned int)arg3;
- (_Bool)UpdateMessageByChatName:(id)arg1 localId:(unsigned int)arg2 withDBMessage:(id)arg3 OnProperty:(const vector_ *)arg4;
- (id)GetMessagesByChatName:(id)arg1 onProperty:(const vector_ *)arg2 where:(const struct WCDBConditionBase *)arg3 order:(const struct WCDBConditionBase *)arg4 limit:(unsigned int)arg5;
- (id)GetMessageByChatName:(id)arg1 OnProperty:(const vector_ *)arg2 where:(const struct WCDBConditionBase *)arg3;
- (unsigned int)GetMaxCreateTimeInMessage:(id)arg1;
- (unsigned int)InsertBackupMessage:(id)arg1 withChatName:(id)arg2 onProperty:(const vector_ *)arg3;
- (unsigned int)InsertMessage:(id)arg1 withChatName:(id)arg2 onProperty:(const vector_ *)arg3;
- (_Bool)IsMessageExistWithChatName:(id)arg1 localId:(unsigned int)arg2;
- (unsigned int)GetHelloMessageCountByChatName:(id)arg1 withDistinctProperty:(const struct WCDBConditionBase *)arg2 Where:(const struct WCDBConditionBase *)arg3;
- (_Bool)UpdateHelloMessage:(id)arg1 byChatName:(id)arg2 onProperty:(const vector_ *)arg3 where:(const struct WCDBConditionBase *)arg4;
- (_Bool)DeleteAllHelloMessageByChatName:(id)arg1 helloUser:(id)arg2;
- (id)GetHelloMessagesByChatName:(id)arg1 onProperty:(const vector_ *)arg2 where:(const struct WCDBConditionBase *)arg3 order:(const struct WCDBConditionBase *)arg4 limit:(unsigned int)arg5;
- (id)GetHelloMessageByChatName:(id)arg1 onProperty:(const vector_ *)arg2 where:(const struct WCDBConditionBase *)arg3 order:(const struct WCDBConditionBase *)arg4;
- (unsigned int)GetMaxCreateTimeInHelloMessage:(id)arg1;
- (unsigned int)InsertHelloMessage:(id)arg1 withChatName:(id)arg2 onProperty:(const vector_ *)arg3;
- (void)dropSendMesTable;
- (id)GetAllSendMessages;
- (_Bool)RemoveOldRevokeMessagesBefore:(unsigned int)arg1;
- (id)GetRevokeMsgBySvrId:(long long)arg1;
- (_Bool)InsertRevokeMessage:(id)arg1;
- (_Bool)DeleteQQContactByUserName:(id)arg1;
- (id)GetAllQQContactOnProperty:(const vector_ *)arg1;
- (id)GetQQContactByUserName:(id)arg1 withProperty:(const vector_ *)arg2;
- (void)fillEmoticonPackageQueryProperty:(vector_ *)arg1;
- (_Bool)IsEmoticonPackageDownloaded:(id)arg1;
- (_Bool)IsEmoticonPackagePurchased:(id)arg1;
- (_Bool)IsEmoticonPackageExistByPackageId:(id)arg1;
- (_Bool)DeleteAllEmotcionPackage;
- (_Bool)DeleteEmoticonPackageNotInIdList:(id)arg1;
- (_Bool)DeleteEmoticonPackageByPackageId:(id)arg1;
- (id)GetEmoticonPackageList;
- (id)GetEmoticonPackageListByPid:(id)arg1;
- (_Bool)UpdateDownloadStatusInEmoticonPackage:(unsigned int)arg1 byPackageId:(id)arg2;
- (_Bool)UpdatePayStatusInEmoticonPackage:(unsigned int)arg1 byPackageId:(id)arg2;
- (_Bool)InsertEmoticonPackageList:(id)arg1;
- (_Bool)InsertEmoticonPackageWithId:(id)arg1 name:(id)arg2 iconUrl:(id)arg3 payStatus:(unsigned int)arg4 downloadStatus:(unsigned int)arg5;
- (_Bool)DelAllEmoticon;
- (id)DeleteEmoticonByPackageId:(id)arg1 WithoutExtFlag:(unsigned int)arg2;
- (_Bool)DeleteEmoticonByMd5:(id)arg1;
- (_Bool)IsEmoticonExistByMd5:(id)arg1;
- (id)GetEmoticonsOnProperty:(const vector_ *)arg1 Where:(const struct WCDBConditionBase *)arg2 orderBy:(const struct WCDBConditionBase *)arg3 limit:(unsigned int)arg4;
- (id)GetAllEmoticon:(const vector_ *)arg1;
- (_Bool)UpdateExtFlagInEmoticon:(unsigned int)arg1 byMd5:(id)arg2 NeedOverWrite:(_Bool)arg3;
- (_Bool)UpdatePackageIdInEmoticon:(id)arg1 byMd5:(id)arg2;
- (_Bool)UpdateLastUsedTimeInEmoticon:(unsigned int)arg1 byMd5:(id)arg2;
- (_Bool)UpdateExtInfoInEmoticon:(id)arg1 byMd5:(id)arg2;
- (_Bool)UpdateEmoticon:(id)arg1 onProperty:(const vector_ *)arg2;
- (_Bool)InsertEmoticon:(id)arg1 onProperty:(const vector_ *)arg2;
- (unsigned int)GetCountOfEmoticonUploadByUserName:(id)arg1;
- (unsigned int)GetCountOfEmoticonUpload;
- (_Bool)DelAllEmoticonUpload;
- (_Bool)DelRowInEmoticonUpload:(id)arg1 LocalID:(unsigned int)arg2;
- (id)GetFirstEmoticonUploadOnProperty:(const vector_ *)arg1;
- (_Bool)InsertEmoticonUpload:(id)arg1 onProperty:(const vector_ *)arg2;
- (_Bool)IsEmoticonUploadExistByUserName:(id)arg1 localId:(unsigned int)arg2;
- (unsigned int)GetCountOfEmoticonDownload;
- (id)emoticonDownloadsOnProperty:(const vector_ *)arg1 afterCreateTime:(unsigned int)arg2;
- (_Bool)SetFriendMetaFlag:(unsigned int)arg1 ForUser:(id)arg2;
- (_Bool)SetLastUpdateTime:(unsigned int)arg1 ForUser:(id)arg2;
- (unsigned int)GetFriendMetaFlag:(id)arg1;
- (unsigned int)GetLastUpdateTimeOfUser:(id)arg1;
- (id)GetContactAndExtWithContactProperty:(const vector_ *)arg1 contactExtProperty:(const vector_ *)arg2 where:(const struct WCDBConditionBase *)arg3 getError:(id *)arg4 limit:(unsigned int)arg5;
- (unsigned int)getContactCount;
- (id)ContactExtTableName;
- (id)ContactTableName;
- (_Bool)DeleteContactExtByUserName:(id)arg1;
- (id)GetContactExtByUserName:(id)arg1 property:(const vector_ *)arg2;
- (_Bool)UpdateContactExt:(id)arg1 withProperty:(const vector_ *)arg2 byUserName:(id)arg3;
- (_Bool)InsertContactExt:(id)arg1 withProperty:(const vector_ *)arg2;
- (_Bool)IsContactExtExist:(id)arg1;
- (_Bool)IsContactExist:(id)arg1;
- (_Bool)DeleteContactByUserName:(id)arg1;
- (_Bool)getAllRemarkList:(id)arg1 listType:(unsigned int)arg2;
- (_Bool)getAllUserName:(id)arg1;
- (id)GetContactsWhere:(const struct WCDBConditionBase *)arg1 onProperty:(const vector_ *)arg2 getError:(id *)arg3;
- (id)GetContactByUserName:(id)arg1 property:(const vector_ *)arg2;
- (_Bool)UpdateExtentInContact:(id)arg1 byUserName:(id)arg2;
- (_Bool)UpdateContact:(id)arg1 withProperty:(const vector_ *)arg2 byUserName:(id)arg3;
- (_Bool)InsertContact:(id)arg1 withProperty:(const vector_ *)arg2;
- (id)getTableRepairMetas;
- (void)cleanOneTable:(id)arg1;
- (void)continueCleanUp;
- (_Bool)isCleanUpFinished;
- (_Bool)DeleteOplog:(unsigned int)arg1;
- (id)GetOplogsAfterOplogId:(unsigned int)arg1 limit:(unsigned int)arg2;
- (_Bool)InsertOplog:(id)arg1;
- (id)oplogDBDirWithDocDir:(id)arg1 userName:(id)arg2;
- (void)CloseOplogDB;
- (void)SetupOplogDBWithDocDir:(id)arg1 userName:(id)arg2;
- (void)setSequence:(int)arg1 forTableName:(id)arg2;
- (id)backupPaths;
- (void)restartBackup;
- (void)stopBackup;
- (void)clearBackup;
- (void)backup;
- (void)setAutoBackup:(_Bool)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface ImageInfo : NSObject <NSCopying>
{
    unsigned int m_uiImageSource;
    NSURL *m_nuImageSourceURL;
}

@property(retain, nonatomic) NSURL *m_nuImageSourceURL; // @synthesize m_nuImageSourceURL;
@property(nonatomic) unsigned int m_uiImageSource; // @synthesize m_uiImageSource;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;

@end

@interface UrlInfo : NSObject <NSCopying>
{
    NSString *m_nsRequestUrl;
    NSData *m_dtResponseData;
    NSString *m_nsRefer;
    _Bool m_bGetMethod;
    NSData *m_dtBodyData;
    NSDictionary *m_dicReq;
    NSDictionary *m_dicResp;
    _Bool m_bCdn;
    NSString *m_nsRequestUrlSuffix;
    unsigned int m_uiRecvTime;
    unsigned int m_uiRetCode;
    unsigned int m_uiDataSize;
    unsigned int m_uiDnsCostTime;
    unsigned int m_uiConnectCostTime;
    unsigned int m_uiSendCostTime;
    unsigned int m_uiWaitResponseCostTime;
    unsigned int m_uiReceiveCostTime;
    NSString *m_nsClientIP;
    NSString *m_nsServerIP;
    unsigned int m_uiDnsType;
    NSString *m_host;
    NSString *m_nsXErrno;
    NSMutableArray *m_aryReceiveData;
    NSString *m_fileMd5;
    _Bool m_bSupportValidateMd5;
    _Bool m_bContinueReceive;
    NSString *m_filePath;
    _Bool m_useDCIP;
    _Bool m_fromSns;
    _Bool m_useXorEncrypt;
    unsigned long long m_xorEncryKey;
    unsigned int m_uiXEncIdx;
    NSString *m_nsXEnc;
    NSString *m_nsXEncToken;
}

@property(nonatomic) unsigned int m_uiXEncIdx; // @synthesize m_uiXEncIdx;
@property(retain, nonatomic) NSString *m_nsXEncToken; // @synthesize m_nsXEncToken;
@property(retain, nonatomic) NSString *m_nsXEnc; // @synthesize m_nsXEnc;
@property(nonatomic) unsigned long long m_xorEncryKey; // @synthesize m_xorEncryKey;
@property(retain, nonatomic) NSMutableArray *m_aryReceiveData; // @synthesize m_aryReceiveData;
@property(nonatomic) _Bool m_useXorEncrypt; // @synthesize m_useXorEncrypt;
@property(nonatomic) _Bool m_fromSns; // @synthesize m_fromSns;
@property(nonatomic) _Bool m_useDCIP; // @synthesize m_useDCIP;
@property(nonatomic) _Bool m_bSupportValidateMd5; // @synthesize m_bSupportValidateMd5;
@property(retain, nonatomic) NSString *m_fileMd5; // @synthesize m_fileMd5;
@property(retain, nonatomic) NSString *m_filePath; // @synthesize m_filePath;
@property(nonatomic) _Bool m_bContinueReceive; // @synthesize m_bContinueReceive;
@property(retain, nonatomic) NSString *m_nsXErrno; // @synthesize m_nsXErrno;
@property(retain, nonatomic) NSString *m_nsRequestUrlSuffix; // @synthesize m_nsRequestUrlSuffix;
@property(retain, nonatomic) NSString *m_host; // @synthesize m_host;
@property(nonatomic) unsigned int m_uiDnsType; // @synthesize m_uiDnsType;
@property(retain, nonatomic) NSString *m_nsServerIP; // @synthesize m_nsServerIP;
@property(retain, nonatomic) NSString *m_nsClientIP; // @synthesize m_nsClientIP;
@property(nonatomic) unsigned int m_uiReceiveCostTime; // @synthesize m_uiReceiveCostTime;
@property(nonatomic) unsigned int m_uiWaitResponseCostTime; // @synthesize m_uiWaitResponseCostTime;
@property(nonatomic) unsigned int m_uiSendCostTime; // @synthesize m_uiSendCostTime;
@property(nonatomic) unsigned int m_uiConnectCostTime; // @synthesize m_uiConnectCostTime;
@property(nonatomic) unsigned int m_uiDnsCostTime; // @synthesize m_uiDnsCostTime;
@property(nonatomic) unsigned int m_uiDataSize; // @synthesize m_uiDataSize;
@property(nonatomic) unsigned int m_uiRetCode; // @synthesize m_uiRetCode;
@property(nonatomic) unsigned int m_uiRecvTime; // @synthesize m_uiRecvTime;
@property(nonatomic) _Bool m_bCdn; // @synthesize m_bCdn;
@property(retain, nonatomic) NSDictionary *m_dicResp; // @synthesize m_dicResp;
@property(retain, nonatomic) NSDictionary *m_dicReq; // @synthesize m_dicReq;
@property(retain, nonatomic) NSData *m_dtBodyData; // @synthesize m_dtBodyData;
@property(nonatomic) _Bool m_bGetMethod; // @synthesize m_bGetMethod;
@property(retain, nonatomic) NSString *m_nsRefer; // @synthesize m_nsRefer;
@property(retain, nonatomic) NSData *m_dtResponseData; // @synthesize m_dtResponseData;
@property(retain, nonatomic) NSString *m_nsRequestUrl; // @synthesize m_nsRequestUrl;
- (id)GenStatStringWithDataType:(int)arg1;
- (id)GenStatString;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;

@end

@interface ProtobufCGIWrap : NSObject <NSCopying>
{
    WXPBGeneratedMessage *m_pbRequest;
    Class m_pbRespClass;
    WXPBGeneratedMessage *m_pbResponse;
    unsigned int m_uiChannelType;
    unsigned int m_uiCgi;
    unsigned int m_uiScene;
    NSString *m_nsCgiName;
    NSString *m_nsUri;
    unsigned int m_uiRequestEncryptType;
    NSData *m_dtResponseDecryptKey;
    unsigned int m_uiMessage;
    Class m_eventHandlerClass;
    NSObject *m_oUserData;
    UrlInfo *m_oUrlInfo;
    _Bool m_bNotifyPartLen;
    unsigned int m_uiRetryCount;
    double m_douTimeout;
    int m_netwrokStrategy;
}

@property(nonatomic) int m_netwrokStrategy; // @synthesize m_netwrokStrategy;
@property(nonatomic) double m_douTimeout; // @synthesize m_douTimeout;
@property(nonatomic) unsigned int m_uiRetryCount; // @synthesize m_uiRetryCount;
@property(nonatomic) _Bool m_bNotifyPartLen; // @synthesize m_bNotifyPartLen;
@property(retain, nonatomic) UrlInfo *m_oUrlInfo; // @synthesize m_oUrlInfo;
@property(retain, nonatomic) NSObject *m_oUserData; // @synthesize m_oUserData;
@property(nonatomic) Class m_eventHandlerClass; // @synthesize m_eventHandlerClass;
@property(nonatomic) unsigned int m_uiMessage; // @synthesize m_uiMessage;
@property(retain, nonatomic) NSData *m_dtResponseDecryptKey; // @synthesize m_dtResponseDecryptKey;
@property(nonatomic) unsigned int m_uiRequestEncryptType; // @synthesize m_uiRequestEncryptType;
@property(nonatomic) unsigned int m_uiChannelType; // @synthesize m_uiChannelType;
@property(retain, nonatomic) NSString *m_nsUri; // @synthesize m_nsUri;
@property(retain, nonatomic) NSString *m_nsCgiName; // @synthesize m_nsCgiName;
@property(nonatomic) unsigned int m_uiScene; // @synthesize m_uiScene;
@property(nonatomic) unsigned int m_uiCgi; // @synthesize m_uiCgi;
@property(retain, nonatomic) WXPBGeneratedMessage *m_pbResponse; // @synthesize m_pbResponse;
@property(nonatomic) Class m_pbRespClass; // @synthesize m_pbRespClass;
@property(retain, nonatomic) WXPBGeneratedMessage *m_pbRequest; // @synthesize m_pbRequest;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;

@end

@interface OpLogDB : NSObject
{
    WCDataBase *m_db;
    WCDataBaseTable *m_table;
}

- (_Bool)DeleteOplogInDB:(unsigned int)arg1;
- (unsigned int)GetOpLogCount;
- (id)GetOplogsAfterOplogId:(unsigned int)arg1 limit:(unsigned int)arg2;
- (_Bool)InsertOplogInDB:(id)arg1;
- (void)CloseDB;
- (_Bool)ConfigWithDir:(id)arg1;
- (void)dealloc;

@end

@interface WCCanvasPageItem : NSObject <PBCoding, NSCopying>
{
    NSString *canvasPageXml;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *canvasPageXml; // @synthesize canvasPageXml;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (const map_ *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface BaseRequest : WXPBGeneratedMessage
{
}

+ (void)initialize;

// Remaining properties
@property(nonatomic) int clientVersion; // @dynamic clientVersion;
@property(retain, nonatomic) NSData *deviceId; // @dynamic deviceId;
@property(retain, nonatomic) NSData *deviceType; // @dynamic deviceType;
@property(nonatomic) unsigned int scene; // @dynamic scene;
@property(retain, nonatomic) NSData *sessionKey; // @dynamic sessionKey;
@property(nonatomic) unsigned int uin; // @dynamic uin;

@end

@interface BaseResponse : WXPBGeneratedMessage
{
}

+ (void)initialize;

// Remaining properties
@property(retain, nonatomic) SKBuiltinString_t *errMsg; // @dynamic errMsg;
@property(nonatomic) int ret; // @dynamic ret;

@end

@interface SKBuiltinBuffer_t : WXPBGeneratedMessage
{
}

+ (void)initialize;
+ (id)skBufferWithData:(id)arg1;

// Remaining properties
@property(retain, nonatomic) NSData *buffer; // @dynamic buffer;
@property(nonatomic) unsigned int iLen; // @dynamic iLen;

@end

@interface SKBuiltinString_t : WXPBGeneratedMessage
{
}

+ (void)initialize;
+ (id)skStringWithString:(id)arg1;

// Remaining properties
@property(retain, nonatomic) NSString *string; // @dynamic string;

@end

@interface AsyncBizSubscribeRequest : WXPBGeneratedMessage
{
}

+ (void)initialize;

// Remaining properties
@property(retain, nonatomic) NSString *bizUserName; // @dynamic bizUserName;

@end

@interface AsyncBizSubscribeResponse : WXPBGeneratedMessage
{
}

+ (void)initialize;

// Remaining properties
@property(retain, nonatomic) BaseResponse *baseResponse; // @dynamic baseResponse;

@end

@interface HongBaoReq : WXPBGeneratedMessage
{
}

+ (void)initialize;

// Remaining properties
@property(retain, nonatomic) BaseRequest *baseRequest; // @dynamic baseRequest;
@property(nonatomic) unsigned int cgiCmd; // @dynamic cgiCmd;
@property(nonatomic) unsigned int outPutType; // @dynamic outPutType;
@property(retain, nonatomic) SKBuiltinBuffer_t *reqText; // @dynamic reqText;

@end

@interface HongBaoRes : WXPBGeneratedMessage
{
}

+ (void)initialize;

// Remaining properties
@property(retain, nonatomic) BaseResponse *baseResponse; // @dynamic baseResponse;
@property(nonatomic) int cgiCmdid; // @dynamic cgiCmdid;
@property(retain, nonatomic) NSString *errorMsg; // @dynamic errorMsg;
@property(nonatomic) int errorType; // @dynamic errorType;
@property(retain, nonatomic) NSString *platMsg; // @dynamic platMsg;
@property(nonatomic) int platRet; // @dynamic platRet;
@property(retain, nonatomic) SKBuiltinBuffer_t *retText; // @dynamic retText;

@end

@interface FestivalHongBaoReq : WXPBGeneratedMessage
{
}

+ (void)initialize;

// Remaining properties
@property(retain, nonatomic) BaseRequest *baseRequest; // @dynamic baseRequest;
@property(nonatomic) unsigned int cgiCmd; // @dynamic cgiCmd;
@property(nonatomic) unsigned int outPutType; // @dynamic outPutType;
@property(retain, nonatomic) SKBuiltinBuffer_t *reqText; // @dynamic reqText;
@property(nonatomic) unsigned long long reqTime; // @dynamic reqTime;
@property(retain, nonatomic) NSData *sendKey; // @dynamic sendKey;
@property(nonatomic) unsigned int subscribe; // @dynamic subscribe;

@end

@interface FestivalHongBaoRes : WXPBGeneratedMessage
{
}

+ (void)initialize;

// Remaining properties
@property(retain, nonatomic) BaseResponse *baseResponse; // @dynamic baseResponse;
@property(nonatomic) int cgiCmdid; // @dynamic cgiCmdid;
@property(retain, nonatomic) NSString *errorMsg; // @dynamic errorMsg;
@property(nonatomic) int errorType; // @dynamic errorType;
@property(retain, nonatomic) NSString *platMsg; // @dynamic platMsg;
@property(nonatomic) int platRet; // @dynamic platRet;
@property(retain, nonatomic) SKBuiltinBuffer_t *retText; // @dynamic retText;

@end

@interface MMServiceCenter : NSObject
{
    NSMutableDictionary *m_dicService;
    NSRecursiveLock *m_lock;
}

- (void)callClearData;
- (void)callReloadData;
- (void)callServiceMemoryWarning;
- (void)callTerminate;
- (void)callEnterBackground;
- (void)callEnterForeground;
- (void)removeService:(Class)arg1;
- (id)getService:(Class)arg1;
- (void)dealloc;
- (id)init;

@end

@interface WCBizUtil : NSObject
{
}

+ (id)getActionLocation;
+ (void)reportLocationAlert:(int)arg1 type:(int)arg2;
+ (id)parseRealnameGuideInfo:(id)arg1 alertViewScene:(int)arg2;
+ (void)logRealnameAction:(int)arg1;
+ (id)getBankResource:(id)arg1;
+ (void)logBannerUserAction:(int)arg1 bannerType:(int)arg2;
+ (void)playCoinSound;
+ (void)bizReportBannerUserAction:(int)arg1 bannType:(int)arg2;
+ (id)GetWCBizMainWindow;
+ (void)SetWCBizMainWindow:(id)arg1;
+ (void)ClearWCBizMainWindow;
+ (id)getTempFullPathOfYearHBImageForSender:(id)arg1;
+ (id)getFullPathOfYearHBImageWithFileId:(id)arg1 userName:(id)arg2;
+ (id)imageWithColor:(id)arg1;
+ (unsigned int)convertTenpayCmdIdToNewCGI:(unsigned int)arg1 payScene:(unsigned int)arg2;
+ (id)convertCGIEnumToString:(unsigned int)arg1;
+ (void)logOfflinePayGetToken:(int)arg1;
+ (void)logUserAction:(int)arg1;
+ (_Bool)validateUrl:(id)arg1;
+ (void)logLoanMoneyAction:(int)arg1;
+ (void)logTransferAction:(int)arg1;
+ (id)feeSymbolFromType:(id)arg1;
+ (id)feeTextFromType:(id)arg1 fee:(long long)arg2;
+ (_Bool)isEmptyKey:(id)arg1 inDictionary:(id)arg2;
+ (_Bool)isDomesticOrderWithMulitOrderDetail:(id)arg1;
+ (_Bool)isDomesticUserWithCardUserFlag:(unsigned int)arg1;
+ (_Bool)isOverseasUserWithCardUserFlag:(unsigned int)arg1;
+ (_Bool)isDomesticCardWithCardBankTag:(unsigned int)arg1;
+ (_Bool)isOverseasCardWithCardBankTag:(unsigned int)arg1;
+ (unsigned int)differntCharactorCountCompareString:(id)arg1 WithOriginalString:(id)arg2;
+ (id)getAddressBookTelphoneNumberDictionary;
+ (id)validWCMallPhoneNumber:(id)arg1;
+ (id)dictionaryWithDecodedComponets:(id)arg1 separator:(id)arg2;
+ (id)stringWithFormEncodedComponentsAscending:(id)arg1 ascending:(_Bool)arg2 skipempty:(_Bool)arg3 separator:(id)arg4;
+ (id)getWCBizLoginTitle:(id)arg1 MaxWidth:(double)arg2;
+ (id)getWCBizAuthTitle:(id)arg1 MaxWidth:(double)arg2;
+ (id)getTitleViewWithTitle:(id)arg1 SubTitle:(id)arg2 LandscapeMode:(_Bool)arg3 MaxWidth:(double)arg4;
+ (id)getTitleViewWithTitle:(id)arg1 LandscapeMode:(_Bool)arg2 MaxWidth:(double)arg3;
+ (id)getWCBizLoginTitle:(id)arg1 LandscapeMode:(_Bool)arg2 MaxWidth:(double)arg3;
+ (id)getWCBizAuthTitle:(id)arg1 LandscapeMode:(_Bool)arg2 MaxWidth:(double)arg3;
+ (id)getSaveStyleBarItemTitle:(id)arg1 target:(id)arg2 sel:(SEL)arg3;
+ (id)getWCFacingReceiveSettingDataPath;
+ (id)getWCPayCgiResponseCachePathWith:(id)arg1;
+ (id)getWCPayDigitalCrtPath;
+ (id)getWCPayRealnameWordingPath;
+ (id)getWCPayBankResourcePath;
+ (id)getWCPayPayManagePath;
+ (id)getWCRedEnvelopesLastRadomHBSelctedCountPath;
+ (id)getWCRedEnvelopesUserInfoPath;
+ (id)getWCMallFunctionListPath;
+ (id)getWCPayServerDynamicWordingPath;
+ (id)getFiltedTruthName:(id)arg1;
+ (id)getCreditCardHadViewFilePath;
+ (id)getWCAddressStageDataFilePath;
+ (id)getWCMallShowedInActivityCellProductId;
+ (id)getWCMallShowedBannerId;
+ (id)getWCMallShowedProductId;
+ (id)getWCMallShowedRedCodePath;
+ (id)getWCMallShowedNewPath;
+ (id)getWCMallTicketsListPath;
+ (id)getWCMallLatestActivityTipsPath;
+ (id)getWCMallTelephoneDictionaryPath;
+ (id)getWCMallTelephoneListPath;
+ (id)getWCAddressYiXunFilePath;
+ (id)getWCAddressFilePath;
+ (id)getWCPayLoanEntryInfoPath;
+ (id)getWCPayTransferedUserListPath;
+ (id)getWCPayNoticeInfoPath;
+ (id)getWCPayBalancePath;
+ (id)getWCPaySwitchInfoPath;
+ (id)getWCPayUserInfoPath;
+ (id)getWCPayCreditCardShowedNewInfoPath;
+ (id)getWCPayOfflinePayShowedNewInfoPath;
+ (id)getWCPayOfflinePayQueryUsrerInfoPath;
+ (id)getWCPayOfflinePayQueryInfoPath;
+ (id)getWCPayOfflinePayUserUinPath;
+ (id)getWCPayOfflinePayFreezeInfoPath;
+ (id)getWCPayOfflinePayDeviceIDPath;
+ (id)getWCPayOfflinePayCrtPath;
+ (id)getWCPayAvalibleCardBinInfoPath;
+ (id)getWCPayAllScenePayCardListPath;
+ (id)getWCPayPayCardListPath;
+ (id)getWCPaySettingPath;
+ (id)getWCBizImgCachedPath:(id)arg1;
+ (_Bool)isBindCardInfoFull:(id)arg1;
+ (id)getHeaderTipView:(id)arg1;
+ (id)getHeaderErrorTipView:(id)arg1;
+ (double)getFooterTipViewHeight:(id)arg1;
+ (id)getFooterTipView:(id)arg1;
+ (id)getFooterErrorTipView:(id)arg1;
+ (id)getStringFromBindCardInfo:(id)arg1;
+ (id)getCardTypeName:(id)arg1;
+ (_Bool)IsWCGroupPayAppServiceInPlane:(id)arg1;
+ (_Bool)IsWCRedEnvelopesAppServiceInPlane:(id)arg1;
+ (_Bool)IsWCPayTransferAppServiceInPlane:(id)arg1;
+ (unsigned char)GetWCPayVersion;

@end

