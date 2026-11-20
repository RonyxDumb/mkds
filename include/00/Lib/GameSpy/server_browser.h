#pragma once

#include "types.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/server_query_engine.h"
#include "00/Lib/GameSpy/hash_table.h"

typedef struct SBServerList SBServerList;
typedef struct SBServer SBServer;
typedef struct MatchingServerList MatchingServerList;

typedef void (*ServerBrowserCallback)(MatchingServerList *list, s32 event, SBServer *server, u32 instance);

// The server browser object: its query engine, its server list and the callback it reports to.
typedef struct MatchingServerList {
    /* 000 */ SBQueryEngine mEngine;
    /* 04c */ SBServerList mList;
    /* 620 */ u32 mDisconnectFlag;
    /* 624 */ u32 mDontUpdate;
    /* 628 */ u32 mTriggerIp;
    /* 62c */ u16 mTriggerPort;
    /* 62e */ u8 mUnk_62e[2];
    /* 630 */ ServerBrowserCallback mBrowserCallback;
    /* 634 */ u32 mBrowserInstance;
} MatchingServerList;

struct MatchingServerList;

unsigned int ServerBrowserLimitUpdateA(MatchingServerList *matchingServerList, unsigned int async,
                                       unsigned int disconnectOnComplete, u8 *basicFields, unsigned int numBasicFields,
                                       const char *serverFilter, unsigned int maxServers);

u32 ServerBrowserGetMyPublicIPAddr(MatchingServerList *matchingServerList);
void ServerBrowserSortA(MatchingServerList *matchingServerList, unsigned int ascending, const char *sortField,
                        unsigned int compareKind);
s32 ServerBrowserCount(MatchingServerList *matchingServerList);
SBServer *ServerBrowserGetServer(MatchingServerList *matchingServerList, u32 index);
void ServerBrowserClear(struct MatchingServerList *matchingServerList);
void ServerBrowserHalt(struct MatchingServerList *matchingServerList);
s32 ServerBrowserThink(struct MatchingServerList *matchingServerList);
void ServerBrowserRemoveServer(struct MatchingServerList *matchingServerList, SBServer *server);
s32 ServerBrowserSendNatNegotiateCookieToServerA(MatchingServerList *matchingServerList, const char *ipText, s32 port,
                                                 u32 cookie);
s32 ServerBrowserSendMessageToServerA(MatchingServerList *matchingServerList, const char *ipText, s32 port, void *data,
                                      s32 dataLength);
s32 ServerBrowserBeginUpdate2(MatchingServerList *matchingServerList, s32 async, u32 disconnectOnComplete,
                              u8 *basicFields, s32 numBasicFields, const char *serverFilter, u32 updateOptions,
                              u32 maxServers);
void ServerBrowserFree(MatchingServerList *matchingServerList);
MatchingServerList *ServerBrowserNewA(const char *targetName, const char *sourceName, const char *queryFromKey,
                                      u32 queryFromVersion, u32 maxUpdates, u32 queryVersion, s32 lanBrowse,
                                      ServerBrowserCallback callback, u32 instance);
void EngineCallback(void *engine, s32 reason, SBServer *server, void *instance);
void ListCallback(SBServerList *browserList, s32 reason, SBServer *server, void *instance);
