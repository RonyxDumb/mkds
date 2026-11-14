#pragma once

#include "types.h"
#include "00/unk_021b4000.h"
#include "00/Lib/GameSpy/sb_queryengine.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"

typedef struct SbServerList SbServerList;
typedef struct SbServer SbServer;
typedef struct MatchingServerList MatchingServerList;

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

unsigned int ServerBrowserLimitUpdateA(MatchingServerList *matchingServerList, unsigned int async,
                                       unsigned int disconnectOnComplete, u8 *basicFields, unsigned int numBasicFields,
                                       unsigned int serverFilter, unsigned int maxServers);

u32 ServerBrowserGetMyPublicIPAddr(MatchingServerList *matchingServerList);
void ServerBrowserSortA(MatchingServerList *matchingServerList, unsigned int ascending, const char *sortField,
                        unsigned int compareKind);
u32 ServerBrowserCount(MatchingServerList *matchingServerList);
u32 ServerBrowserGetServer(MatchingServerList *matchingServerList, u32 index);
void ServerBrowserClear(struct MatchingServerList *matchingServerList);
void ServerBrowserHalt(struct MatchingServerList *matchingServerList);
s32 ServerBrowserThink(struct MatchingServerList *matchingServerList);
void ServerBrowserRemoveServer(struct MatchingServerList *matchingServerList, s32 server);
s32 ServerBrowserSendNatNegotiateCookieToServerA(MatchingServerList *matchingServerList, u32 ipText, s32 port,
                                                 u32 cookie);
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
