#pragma once

#include "types.h"
#include "00/Lib/wifi_library_globals.h"

typedef struct SBServerList SBServerList;
typedef struct SBServer SBServer;
typedef struct SBServerFIFO SBServerFIFO;
typedef struct MatchingServerList MatchingServerList;

// Object SBSendMessageToServer builds.
typedef struct SendMessageRequest {
    /* 00 */ u16 mNetLength;
    /* 02 */ u8 mRequestLength[2];
    /* 04 */ u8 mRequestType;
    /* 05 */ u8 mRequestIp[4];
    /* 09 */ u8 mRequestPort[2];
    /* 0b */ u8 mUnk_0b[8];
} SendMessageRequest;

// Four bytes copied one byte at a time by CopyUnalignedWord in server_list.c.
typedef struct UnalignedWord {
    /* 0 */ u8 mBytes[4];
} UnalignedWord;

void SBServerListInit(SBServerList *slist, const char *targetName, const char *sourceName, const char *queryFromKey,
                      u32 queryFromVersion, s32 lanBrowse, SBListCallBackFn callback, void *instance);

#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/server_query_engine.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/GameSpy/server_record.h"
#include "00/Lib/GameSpy/server_browser.h"

s32 SBListThink(SBServerList *serverList);
s32 ProcessLanData(SBServerList *serverList);
s32 SBSendNatNegotiateCookieToServer(SBServerList *serverList, u32 publicIp, u16 port, u32 cookie);
s32 SBSendMessageToServer(SBServerList *serverList, u32 publicIp, u16 port, u8 *data, s32 dataLength);
s32 ProcessIncomingData(SBServerList *serverList);
s32 ProcessAdHocData(SBServerList *slist);
s32 ProcessPushServer(SBServerList *serverList, u8 *buffer, s32 length);
s32 ProcessDeleteServer(SBServerList *serverList, u8 *buffer, s32 length);
s32 ProcessMaploop(SBServerList *serverList, u8 *buffer, s32 length);
s32 ProcessPlayerSearch(SBServerList *serverList, u8 *buffer, s32 length);
s32 ProcessPushKeyList(SBServerList *serverList, u8 *buffer, s32 length);
s32 ProcessMainListData(SBServerList *serverList);
void SBSetLastListErrorPtr(SBServerList *serverList, char *errorText);
s32 IncomingListParseServer(SBServerList *serverList, u8 *buffer, s32 length);
s32 ParseServer(SBServerList *serverList, void *server, u8 *buffer, s32 length, s32 popularOnly);
void ParseServerIPPort(SBServerList *serverList, u8 *buffer, s32 length, u8 *ipOut, u16 *portOut);
BOOL AllKeysPresent(SBServerList *serverList, u8 *buffer, s32 length);
BOOL FullRulesPresent(u8 *buffer, s32 length);
s32 ServerSizeForFlags(u32 flags);
void InitCryptKey(SBServerList *serverList, s8 *serverBytes, s32 length);
void SBServerListCleanup(SBServerList *serverList);
void SBServerListDisconnect(SBServerList *serverList);
void FreeKeyList(SBServerList *serverList);
void FreePopularValues(SBServerList *serverList);
s32 SBServerListConnectAndQuery(SBServerList *serverList, const char *fieldList, const char *serverFilter, u32 options,
                                u32 maxServers);
s32 SendWithRetry(SBServerList *serverList, void *data, s32 length);
void SetupListChallenge(SBServerList *serverList);
void BufferAddData(u8 **buffer, const void *data, s32 dataLength, s32 *length);
void BufferAddInt(u8 **buffer, u32 value, s32 *length);
void BufferAddByte(u8 **buffer, u8 value, s32 *length);
void BufferAddNTS(u8 **buffer, const char *text, s32 *length);
s32 ServerListConnect(SBServerList *serverList);
u32 StringHash(const s8 *text, u32 modulus);
void ErrorDisconnect(SBServerList *serverList);
int NTSLengthSB(const void *buffer, int length);
void SBReleaseStr(SBServerList *serverList, u32 key);
void *SBRefStr(SBServerList *serverList, const char *key);
void SBAllocateServerList(SBServerList *serverList);
void SBServerListClear(SBServerList *serverList);
void SBFreeDeadList(SBServerList *serverList);
SBServer *SBServerListNth(SBServerList *serverList, u32 index);
s32 SBServerListCount(SBServerList *serverList);
void SBServerListRemoveAt(SBServerList *serverList, s32 index);
void AddServerToDeadlist(SBServerList *serverList, SBServer *server);
int SBServerListFindServerByIP(SBServerList *serverList, int publicIp, int publicPort);
int SBServerListFindServer(SBServerList *serverList, SBServer *server);
void SBServerListAppendServer(SBServerList *serverList, SBServer *server);
void SBServerListSort(SBServerList *serverList, s32 ascending, const char *sortField, u32 compareKind);
s32 StrNoCaseKeyCompare(SBServer **firstEntry, SBServer **secondEntry);
s32 StrCaseKeyCompare(SBServer **firstEntry, SBServer **secondEntry);

extern char *gSBOverrideMasterServer;
