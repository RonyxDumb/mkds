#include "00/Lib/GameSpy/sb_serverlist.h"

#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/sb_queryengine.h"
#include "00/types_0218b928.h"
#include "03/Net/exchange_essid.h" // SocketAddress
#include "00/code_0218d000.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"
#include "code_0214177c.h"
#include "00/unk_021b4000.h"
#include "code_02133274.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/code_0218a000.h"
#include "00/code_0218c000.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/code_0218b000.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/code_021a4b84.h"
#include "string.h"
#include "00/Lib/DWC/code_0218a67c.h"
#include "00/code_02196000.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02190000.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/code_02192d64.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_02194bb8.h"
#include "00/Lib/GameSpy/code_02193b88.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/Lib/GameSpy/code_0218a71c.h"
#include "code_021384cc.h"
#include "00/code_021919ac.h"
#include "code_021382a8.h"
#include "00/Lib/GameSpy/code_0218d488.h"
#include "00/Lib/NitroWiFi/socl_startup.h"

void ListCallback(SbServerList *browserList, s32 reason, SbServer *server, MatchingServerList *matchingServerList) {
    switch (reason) {
        case 0:
            matchingServerList->mBrowserCallback(matchingServerList, 0, server, matchingServerList->mBrowserInstance);
            if (((server->mStateFlags & 3) == 0 || (server->mStateFlags & 0x40) == 0) &&
                (server->mStateFlags & 0x2c) == 0 && matchingServerList->mDontUpdate == 0) {
                s32 queryType;
                if (server->mFlags & 1) {
                    if (matchingServerList->mList.mState == SERVER_LIST_STATE_LOCAL_SCAN ||
                        matchingServerList->mEngine.mNumServerKeys == 0) {
                        queryType = 1;
                    } else {
                        queryType = 0;
                    }
                } else {
                    queryType = 2;
                }
                SBQueryEngineUpdateServer(&matchingServerList->mEngine, server, 0, queryType);
            }
            break;
        case 1:
            if ((server->mStateFlags & 0x43) == 0) {
                matchingServerList->mBrowserCallback(matchingServerList, 2, server,
                                                     matchingServerList->mBrowserInstance);
            } else {
                matchingServerList->mBrowserCallback(matchingServerList, 1, server,
                                                     matchingServerList->mBrowserInstance);
            }
            break;
        case 2:
            if ((server->mStateFlags & 0x2c) != 0) {
                SBQueryEngineRemoveServerFromFIFOs(matchingServerList, server);
            }
            matchingServerList->mBrowserCallback(matchingServerList, 3, server, matchingServerList->mBrowserInstance);
            break;
        case 3:
            if (matchingServerList->mDisconnectFlag != 0) {
                SBServerListDisconnect(browserList);
            }
            if (DarrayGetCount(browserList->mServers) == 0 || matchingServerList->mEngine.mQueryList.mCount == 0) {
                matchingServerList->mBrowserCallback(matchingServerList, 4, 0, matchingServerList->mBrowserInstance);
            }
            break;
        case 5:
            matchingServerList->mBrowserCallback(matchingServerList, 5, 0, matchingServerList->mBrowserInstance);
            break;
        case 6:
            SBQueryEngineSetPublicIP(matchingServerList, matchingServerList->mList.mMyPublicIp);
            break;
    }
    if (server != NULL && server->mPublicIp == matchingServerList->mTriggerIp &&
        server->mPublicPort == matchingServerList->mTriggerPort) {
        matchingServerList->mTriggerIp = 0;
    }
}

void EngineCallback(void *engine, s32 reason, SbServer *server, MatchingServerList *matchingServerList) {
    switch (reason) {
        case 1:
            matchingServerList->mBrowserCallback(matchingServerList, 2, server, matchingServerList->mBrowserInstance);
            break;
        case 0:
            matchingServerList->mBrowserCallback(matchingServerList, 1, server, matchingServerList->mBrowserInstance);
            break;
        case 2:
            matchingServerList->mBrowserCallback(matchingServerList, 4, server, matchingServerList->mBrowserInstance);
            break;
    }
    if (server != NULL && server->mPublicIp == matchingServerList->mTriggerIp &&
        server->mPublicPort == matchingServerList->mTriggerPort) {
        matchingServerList->mTriggerIp = 0;
    }
}

MatchingServerList *ServerBrowserNewA(const char *targetName, const char *sourceName,
                                      const char *queryFromKey, u32 queryFromVersion, u32 maxUpdates, u32 queryVersion,
                                      s32 lanBrowse, UnkFunc *callback, u32 instance) {
    MatchingServerList *matchingServerList;
    if (lanBrowse == 0 && gGsiAcResult != 1) {
        return NULL;
    }
    matchingServerList = DWCi_GsMalloc(0x638);
    if (matchingServerList == NULL) {
        return NULL;
    }
    matchingServerList->mBrowserCallback = callback;
    matchingServerList->mBrowserInstance = instance;
    matchingServerList->mDontUpdate = 0;
    SbServerListInit(&matchingServerList->mList, targetName, sourceName, queryFromKey, queryFromVersion,
                     lanBrowse, ListCallback, matchingServerList);
    SBQueryEngineInit(&matchingServerList->mEngine, maxUpdates, queryVersion, lanBrowse, EngineCallback,
                      matchingServerList);
    return matchingServerList;
}

void ServerBrowserFree(MatchingServerList *matchingServerList) {
    SBServerListCleanup(&matchingServerList->mList);
    SBEngineCleanup(matchingServerList);
    DWCi_GsFree(matchingServerList);
}

s32 ServerBrowserBeginUpdate2(MatchingServerList *matchingServerList, s32 async, u32 disconnectOnComplete,
                              u8 *basicFields, s32 numBasicFields, const char *serverFilter, u32 updateOptions,
                              u32 maxServers) {
    char keyNames[256] = {0};
    s32 listLength;
    s32 fieldIndex;
    s32 error;
    const char *keyName;
    listLength = 0;
    matchingServerList->mDisconnectFlag = disconnectOnComplete;
    matchingServerList->mEngine.mNumServerKeys = 0;
    for (fieldIndex = 0; fieldIndex < numBasicFields; fieldIndex++) {
        keyName = gQr2RegisteredKeyList[basicFields[fieldIndex]];
        if (listLength + (s32) strlen(keyName) + 1 >= 256) {
            break;
        }
        listLength += sprintf(keyNames + listLength, "\\%s", keyName);
        SBQueryEngineAddQueryKey(&matchingServerList->mEngine, basicFields[fieldIndex]);
    }
    error = SBServerListConnectAndQuery(&matchingServerList->mList, keyNames, serverFilter, updateOptions, maxServers);
    if (error == 0 && async == 0) {
        listLength = 10;
        while (matchingServerList->mList.mState == SERVER_LIST_STATE_RECEIVING_LIST ||
               (matchingServerList->mEngine.mQueryList.mCount > 0 && error == 0)) {
            msleep(listLength);
            error = ServerBrowserThink(matchingServerList);
        }
    }
    return error;
}

u32 ServerBrowserLimitUpdateA(MatchingServerList *matchingServerList, u32 async, u32 disconnectOnComplete,
                              u8 *basicFields, u32 numBasicFields, u32 serverFilter, u32 maxServers) {
    u32 fieldCount = numBasicFields;
    u32 filter = serverFilter;
    u32 limit = maxServers;
    u32 result = ServerBrowserBeginUpdate2(matchingServerList, async, disconnectOnComplete, basicFields, fieldCount,
                                           (const char *) filter, 0x80u, limit);
    return result;
}

s32 ServerBrowserSendMessageToServerA(MatchingServerList *matchingServerList, u32 ipText, s32 port, u8 *data,
                                      s32 dataLength) {
    u32 publicIp = inet_addr(ipText);
    return SBSendMessageToServer(&matchingServerList->mList, publicIp, ((port >> 8) & 0xff) | ((port << 8) & 0xff00),
                                 data, dataLength);
}

s32 ServerBrowserSendNatNegotiateCookieToServerA(MatchingServerList *matchingServerList, u32 ipText, s32 port,
                                                 u32 cookie) {
    u32 publicIp = inet_addr(ipText);
    return SBSendNatNegotiateCookieToServer(&matchingServerList->mList, publicIp,
                                            ((port >> 8) & 0xff) | ((port << 8) & 0xff00), cookie);
}

void ServerBrowserRemoveServer(struct MatchingServerList *matchingServerList, SbServer *server) {
    s32 serverIndex;
    serverIndex = SBServerListFindServer(&matchingServerList->mList, server);
    if (serverIndex != -1) {
        SBServerListRemoveAt(&matchingServerList->mList, serverIndex);
    }
}

s32 ServerBrowserThink(struct MatchingServerList *matchingServerList) {
    SBQueryEngineThink(matchingServerList);
    return SBListThink(&matchingServerList->mList);
}

void ServerBrowserHalt(struct MatchingServerList *matchingServerList) {
    SBServerListDisconnect(&matchingServerList->mList);
    SBEngineHaltUpdates(matchingServerList);
}

void ServerBrowserClear(struct MatchingServerList *matchingServerList) {
    ServerBrowserHalt(matchingServerList);
    SBServerListClear(&matchingServerList->mList);
}

SbServer *ServerBrowserGetServer(MatchingServerList *matchingServerList, u32 index) {
    return SBServerListNth(&matchingServerList->mList, index);
}

s32 ServerBrowserCount(MatchingServerList *matchingServerList) {
    return SBServerListCount(&matchingServerList->mList);
}

void ServerBrowserSortA(MatchingServerList *matchingServerList, u32 ascending, const char *sortField, u32 compareKind) {
    SBServerListSort(&matchingServerList->mList, ascending, sortField, compareKind);
}

u32 ServerBrowserGetMyPublicIPAddr(MatchingServerList *matchingServerList) {
    return matchingServerList->mList.mMyPublicIp;
}
