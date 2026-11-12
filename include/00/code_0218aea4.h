#pragma once

#include "types.h"

typedef struct SbServerList SbServerList;
typedef struct SbServer SbServer;
typedef struct SBServerFIFO SBServerFIFO;

typedef struct HashtableNameEntry {
    /* 00 */ const s8 *mName;
} HashtableNameEntry;

typedef struct SbServer SbServer;

typedef struct InvalidKeyNames {
    /* 0 */ const char *mNames[2];
} InvalidKeyNames;

typedef struct FullKeysScratch {
    /* 00 */ u8 mUnitCount[2];
    /* 02 */ char mTempKey[0x86];
} FullKeysScratch;

typedef struct SbServer SbServer;

typedef struct KeyLookup {
    /* 0 */ const char *mKey;
} KeyLookup;


double SbServerGetDouble(SbServer *server, const char *key, double defaultValue);
s32 SbServerGetInt(SbServer *server, const char *key, s32 defaultValue);
char *SbServerGetValue(SbServer *server, const char *key, char *defaultValue);
void SbServerSetInt(SbServer *server, const char *key, u32 value);
void SbServerSetValue(SbServer *server, const char *key, const char *value);

typedef struct SbServerList SbServerList;

typedef struct SbServer SbServer;
typedef struct MatchingServerList MatchingServerList;
typedef struct SbServerList SbServerList;

// Object SBSendMessageToServer builds.
typedef struct SendMessageRequest {
    /* 00 */ u16 mNetLength;
    /* 02 */ u8 mRequestLength[2];
    /* 04 */ u8 mRequestType;
    /* 05 */ u8 mRequestIp[4];
    /* 09 */ u8 mRequestPort[2];
    /* 0b */ u8 mUnk_0b[8];
} SendMessageRequest;

typedef struct SbServerList SbServerList;

typedef struct SbServerList SbServerList;

// Four bytes copied byte by byte (CopyUnalignedWord in code_0218cdd8.c); the target may be unaligned.
typedef struct UnalignedWord {
    /* 0 */ u8 mBytes[4];
} UnalignedWord;

typedef struct SbServerList SbServerList;


void SbServerListInit(SbServerList *slist, const char *targetName, const char *sourceName,
                      const char *queryFromKey, u32 queryFromVersion, s32 lanBrowse, UnkFunc *callback, void *instance);

unsigned int ServerBrowserLimitUpdateA(MatchingServerList *matchingServerList, unsigned int async,
                                       unsigned int disconnectOnComplete, u8 *basicFields, unsigned int numBasicFields,
                                       unsigned int serverFilter, unsigned int maxServers);

#include "00/unk_021b4000.h"
#include "00/sb_queryengine.h"

// Object of 0x638 bytes ServerBrowserNewA allocates. SBEngineCleanup passes 0x20 to closesocket and
// the addresses of 0x14 and 0x08 to FIFOClear.
typedef struct MatchingServerList {
    /* 000 */ SBQueryEngine mEngine;
    /* 04c */ SbServerList mList;
    /* 620 */ u32 mDisconnectFlag;
    /* 624 */ u32 mDontUpdate;
    /* 628 */ u32 mTriggerIp;
    /* 62c */ u16 mTriggerPort;
    /* 62e */ u8 mUnk_62e[2];
    /* 630 */ UnkFunc *mBrowserCallback;
    /* 634 */ u32 mBrowserInstance;
} MatchingServerList;

struct MatchingServerList;



extern InvalidKeyNames gInvalidKeys;
extern char gKeyIndexFormat[];
extern s8 data_ov000_021b21c4[];
extern char gPingKey[];
extern char gServerAssertText[];
extern char gSBServerFileName[];
extern char gIntValueFormat[];
extern s8 *gMytokPosition;

SbServer *FIFOGetFirst(SBServerFIFO *fifo);
void FIFOAddFront(SBServerFIFO *fifo, SbServer *server);
void FIFOAddRear(SBServerFIFO *fifo, SbServer *server);
BOOL SBIsNullServer(SbServer *server);
u8 SBServerGetState(SbServer *server);
void SBServerSetState(SbServer *server, u8 state);
void SBServerSetICMPIP(SbServer *server, u32 targetAddr);
void SBServerSetPrivateAddr(SbServer *server, u32 innerAddress, u16 innerPort);
void SBServerSetFlags(SbServer *server, s32 flags);
SbServer *SBAllocServer(SbServerList *serverList, u32 outerAddress, u16 outerPort);
u32 SBServerGetPing(SbServer *server);
s32 KeyValCompareKey(const char *const *first, const char *const *second);
u32 KeyValHashKey(HashtableNameEntry *entry, u32 modulus);
void KeyValFree(u32 *pair);
u32 ServerStringHash(const s8 *name, u32 modulus);
void SBServerParseQR2FullKeysSingle(SbServer *server, s8 *buf, s32 length);
void SBServerParseKeyVals(SbServer *server, s8 *buf);
s8 *mytok(s8 *text, s32 delimiter);
BOOL CheckValidKey(const char *key);
u32 SBServerGetNext(int server);
void SBServerSetNext(int server, u32 next);
u32 SBServerGetPrivateQueryPort(u32 server);
u32 SBServerGetPrivateInetAddress(int server);
BOOL SBServerHasPrivateAddress(int server);
u16 SBServerGetPublicQueryPortNBO(int server);
u32 SBServerGetPublicQueryPort(u32 server);
u32 SBServerGetPublicInetAddress(u32 *server);
void SBServerFree(int *serverPointer);
void SBRefStrHashCleanup(void *serverList);
struct Hashtable *SBRefStrHash(struct SbServerList *serverList);
void RefStringFree(u32 element);
s32 RefStringCompare(const char *const *first, const char *const *second);
u32 RefStringHash(HashtableNameEntry *entry, u32 modulus);
u32 ServerBrowserGetMyPublicIPAddr(MatchingServerList *matchingServerList);
void ServerBrowserSortA(MatchingServerList *matchingServerList, unsigned int ascending, const char *sortField,
                        unsigned int compareKind);
u32 ServerBrowserCount(MatchingServerList *matchingServerList);
u32 ServerBrowserGetServer(MatchingServerList *matchingServerList, u32 index);
void ServerBrowserClear(struct MatchingServerList *matchingServerList);
void ServerBrowserHalt(struct MatchingServerList *matchingServerList);
s32 ServerBrowserThink(struct MatchingServerList *matchingServerList);
void ServerBrowserRemoveServer(struct MatchingServerList *matchingServerList, s32 server);
s32 ServerBrowserSendNatNegotiateCookieToServerA(MatchingServerList *matchingServerList, u32 ipText, s32 port, u32 cookie);
s32 ServerBrowserSendMessageToServerA(MatchingServerList *matchingServerList, u32 ipText, s32 port, u8 *data,
                                      s32 dataLength);
s32 ServerBrowserBeginUpdate2(MatchingServerList *matchingServerList, s32 async, u32 disconnectOnComplete,
                              u8 *basicFields, s32 numBasicFields, const char *serverFilter, u32 updateOptions,
                              u32 maxServers);
void ServerBrowserFree(MatchingServerList *matchingServerList);
MatchingServerList *ServerBrowserNewA(const char *targetName, const char *sourceName,
                                      const char *queryFromKey, u32 queryFromVersion, u32 maxUpdates, u32 queryVersion,
                                      s32 lanBrowse, UnkFunc *callback, u32 instance);
void EngineCallback(void *engine, s32 reason, SbServer *server, MatchingServerList *matchingServerList);
void ListCallback(SbServerList *browserList, s32 reason, SbServer *server, MatchingServerList *matchingServerList);
s32 SBListThink(SbServerList *serverList);
s32 ProcessLanData(SbServerList *serverList);
s32 SBSendNatNegotiateCookieToServer(SbServerList *serverList, u32 publicIp, u16 port, u32 cookie);
s32 SBSendMessageToServer(SbServerList *serverList, u32 publicIp, u16 port, u8 *data, s32 dataLength);
s32 ProcessIncomingData(SbServerList *serverList);
s32 ProcessAdHocData(SbServerList *slist);
s32 ProcessPushServer(SbServerList *serverList, u8 *buffer, s32 length);
s32 ProcessDeleteServer(SbServerList *serverList, u8 *buffer, s32 length);
s32 ProcessMaploop(SbServerList *serverList, u8 *buffer, s32 length);
s32 ProcessPlayerSearch(SbServerList *serverList, u8 *buffer, s32 length);
s32 ProcessPushKeyList(SbServerList *serverList, u8 *buffer, s32 length);
s32 ProcessMainListData(SbServerList *serverList);
void SBSetLastListErrorPtr(SbServerList *serverList, char *errorText);
s32 IncomingListParseServer(SbServerList *serverList, u8 *buffer, s32 length);
s32 ParseServer(SbServerList *serverList, void *server, u8 *buffer, s32 length, s32 popularOnly);
void ParseServerIPPort(SbServerList *serverList, u8 *buffer, s32 length, u8 *ipOut, u16 *portOut);
BOOL AllKeysPresent(SbServerList *serverList, u8 *buffer, s32 length);
BOOL FullRulesPresent(u8 *buffer, s32 length);
s32 ServerSizeForFlags(u32 flags);
void InitCryptKey(SbServerList *serverList, s8 *serverBytes, s32 length);
void SBServerListCleanup(SbServerList *serverList);
void SBServerListDisconnect(SbServerList *serverList);
void FreeKeyList(SbServerList *serverList);
void FreePopularValues(SbServerList *serverList);
s32 SBServerListConnectAndQuery(SbServerList *serverList, const char *fieldList, const char *serverFilter, u32 options,
                                u32 maxServers);
s32 SendWithRetry(SbServerList *serverList, void *data, s32 length);
void SetupListChallenge(SbServerList *serverList);
void BufferAddData(u8 **buffer, const void *data, s32 dataLength, s32 *length);
void BufferAddInt(u8 **buffer, u32 value, s32 *length);
void BufferAddByte(u8 **buffer, u8 value, s32 *length);
void BufferAddNTS(u8 **buffer, const char *text, s32 *length);
s32 ServerListConnect(SbServerList *serverList);
u32 StringHash(const s8 *text, u32 modulus);
void ErrorDisconnect(SbServerList *serverList);
int NTSLengthSB(const void *buffer, int length);
void SBReleaseStr(SbServerList *serverList, u32 key);
void *SBRefStr(SbServerList *serverList, const char *key);
void SBAllocateServerList(unsigned int serverList);
void SBServerListClear(SbServerList *serverList);
void SBFreeDeadList(SbServerList *serverList);
u32 SBServerListNth(SbServerList *serverList, u32 index);
u32 SBServerListCount(SbServerList *serverList);
void SBServerListRemoveAt(SbServerList *serverList, s32 index);
void AddServerToDeadlist(SbServerList *serverList, u32 key);
int SBServerListFindServerByIP(SbServerList *serverList, int publicIp, int publicPort);
int SBServerListFindServer(SbServerList *serverList, int server);
void SBServerListAppendServer(SbServerList *serverList, u32 server);
void SBServerListSort(SbServerList *serverList, s32 ascending, const char *sortField, u32 compareKind);
s32 StrNoCaseKeyCompare(u32 *firstEntry, u32 *secondEntry);
s32 StrCaseKeyCompare(u32 *firstEntry, u32 *secondEntry);
