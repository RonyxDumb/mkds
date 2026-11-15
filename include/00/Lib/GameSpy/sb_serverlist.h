#pragma once

#include "types.h"
#include "00/Lib/wifi_library_globals.h"

typedef struct SbServerList SbServerList;
typedef struct SbServer SbServer;
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

// Four bytes copied byte by byte (CopyUnalignedWord in code_0218cdd8.c); the target may be unaligned.
typedef struct UnalignedWord {
    /* 0 */ u8 mBytes[4];
} UnalignedWord;

void SbServerListInit(SbServerList *slist, const char *targetName, const char *sourceName, const char *queryFromKey,
                      u32 queryFromVersion, s32 lanBrowse, SbServerListCallback callback, void *instance);

#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/sb_queryengine.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"
#include "00/Lib/GameSpy/sb_server.h"
#include "00/Lib/GameSpy/sb_serverbrowsing.h"

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
void SBAllocateServerList(SbServerList *serverList);
void SBServerListClear(SbServerList *serverList);
void SBFreeDeadList(SbServerList *serverList);
SbServer *SBServerListNth(SbServerList *serverList, u32 index);
s32 SBServerListCount(SbServerList *serverList);
void SBServerListRemoveAt(SbServerList *serverList, s32 index);
void AddServerToDeadlist(SbServerList *serverList, SbServer *server);
int SBServerListFindServerByIP(SbServerList *serverList, int publicIp, int publicPort);
int SBServerListFindServer(SbServerList *serverList, SbServer *server);
void SBServerListAppendServer(SbServerList *serverList, SbServer *server);
void SBServerListSort(SbServerList *serverList, s32 ascending, const char *sortField, u32 compareKind);
s32 StrNoCaseKeyCompare(SbServer **firstEntry, SbServer **secondEntry);
s32 StrCaseKeyCompare(SbServer **firstEntry, SbServer **secondEntry);

extern char *gSBOverrideMasterServer;
