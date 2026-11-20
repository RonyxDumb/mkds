#include "00/Lib/GameSpy/server_list.h"

#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/server_query_engine.h"
#include "00/Lib/GameSpy/server_key_info.h"
#include "03/Net/exchange_essid.h" // SocketAddress
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "decimal_digit_arith_string_compare.h"
#include "00/Lib/wifi_library_globals.h"
#include "unsigned_int_divide.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/query_key_register.h"
#include "string.h"
#include "00/Lib/DWC/shop_access_point_key.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "00/Lib/GameSpy/stream_cipher.h"
#include "scan_text_random.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "quick_sort.h"
#include "00/Lib/GameSpy/availability_check.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"

void ListCallback(SBServerList *browserList, s32 reason, SBServer *server, void *instance) {
    MatchingServerList *matchingServerList = instance;
    switch (reason) {
        case SERVER_LIST_REASON_SERVER_ADDED:
            matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_SERVER_ADDED, server,
                                                 matchingServerList->mBrowserInstance);
            if (((server->mStateFlags & (SERVER_STATE_HAS_BASIC_KEYS | SERVER_STATE_HAS_FULL_KEYS)) == 0 ||
                 (server->mStateFlags & SERVER_STATE_HAS_PING) == 0) &&
                (server->mStateFlags & (SERVER_STATE_BASIC_QUERY_PENDING | SERVER_STATE_FULL_QUERY_PENDING | SERVER_STATE_ICMP_QUERY_PENDING)) ==
                    0 &&
                matchingServerList->mDontUpdate == 0) {
                s32 queryType;
                if (server->mFlags & SERVER_FLAG_UDP_QUERY) {
                    if (matchingServerList->mList.mState == SERVER_LIST_STATE_LOCAL_SCAN ||
                        matchingServerList->mEngine.mNumServerKeys == 0) {
                        queryType = SERVER_UPDATE_KIND_FULL;
                    } else {
                        queryType = SERVER_UPDATE_KIND_BASIC;
                    }
                } else {
                    queryType = SERVER_UPDATE_KIND_ICMP;
                }
                SBQueryEngineUpdateServer(&matchingServerList->mEngine, server, 0, queryType);
            }
            break;
        case SERVER_LIST_REASON_SERVER_UPDATED:
            if ((server->mStateFlags & (SERVER_STATE_HAS_BASIC_KEYS | SERVER_STATE_HAS_FULL_KEYS | SERVER_STATE_HAS_PING)) == 0) {
                matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_SERVER_UPDATE_FAILED, server,
                                                     matchingServerList->mBrowserInstance);
            } else {
                matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_SERVER_UPDATED, server,
                                                     matchingServerList->mBrowserInstance);
            }
            break;
        case SERVER_LIST_REASON_SERVER_DELETED:
            if ((server->mStateFlags & (SERVER_STATE_BASIC_QUERY_PENDING | SERVER_STATE_FULL_QUERY_PENDING | SERVER_STATE_ICMP_QUERY_PENDING)) !=
                0) {
                SBQueryEngineRemoveServerFromFIFOs(matchingServerList, server);
            }
            matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_SERVER_DELETED, server,
                                                 matchingServerList->mBrowserInstance);
            break;
        case SERVER_LIST_REASON_LIST_FINISHED:
            if (matchingServerList->mDisconnectFlag != 0) {
                SBServerListDisconnect(browserList);
            }
            if (ArrayLength(browserList->mServers) == 0 || matchingServerList->mEngine.mQueryList.mCount == 0) {
                matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_UPDATE_COMPLETE, 0,
                                                     matchingServerList->mBrowserInstance);
            }
            break;
        case SERVER_LIST_REASON_QUERY_ERROR:
            matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_QUERY_ERROR, 0,
                                                 matchingServerList->mBrowserInstance);
            break;
        case SERVER_LIST_REASON_PUBLIC_IP_RECEIVED:
            SBQueryEngineSetPublicIP(matchingServerList, matchingServerList->mList.mMyPublicIp);
            break;
    }
    if (server != NULL && server->mPublicIp == matchingServerList->mTriggerIp &&
        server->mPublicPort == matchingServerList->mTriggerPort) {
        matchingServerList->mTriggerIp = 0;
    }
}

void EngineCallback(void *engine, s32 reason, SBServer *server, void *instance) {
    MatchingServerList *matchingServerList = instance;
    switch (reason) {
        case QUERY_ENGINE_REASON_QUERY_TIMED_OUT:
            matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_SERVER_UPDATE_FAILED, server,
                                                 matchingServerList->mBrowserInstance);
            break;
        case QUERY_ENGINE_REASON_REPLY_PARSED:
            matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_SERVER_UPDATED, server,
                                                 matchingServerList->mBrowserInstance);
            break;
        case QUERY_ENGINE_REASON_QUERY_LIST_EMPTY:
            matchingServerList->mBrowserCallback(matchingServerList, BROWSER_REASON_UPDATE_COMPLETE, server,
                                                 matchingServerList->mBrowserInstance);
            break;
    }
    if (server != NULL && server->mPublicIp == matchingServerList->mTriggerIp &&
        server->mPublicPort == matchingServerList->mTriggerPort) {
        matchingServerList->mTriggerIp = 0;
    }
}

MatchingServerList *ServerBrowserNewA(const char *queryForGameName, const char *queryFromGameName, const char *queryFromKey,
                                      u32 queryFromVersion, u32 maxUpdates, u32 queryVersion, s32 lanBrowse,
                                      ServerBrowserCallback callback, u32 instance) {
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
    SBServerListInit(&matchingServerList->mList, queryForGameName, queryFromGameName, queryFromKey, queryFromVersion, lanBrowse,
                     ListCallback, matchingServerList);
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
                              u8 *basicFields, u32 numBasicFields, const char *serverFilter, u32 maxServers) {
    u32 fieldCount = numBasicFields;
    const char *filter = serverFilter;
    u32 limit = maxServers;
    u32 result = ServerBrowserBeginUpdate2(matchingServerList, async, disconnectOnComplete, basicFields, fieldCount,
                                           filter, 0x80u, limit);
    return result;
}

s32 ServerBrowserSendMessageToServerA(MatchingServerList *matchingServerList, const char *ipText, s32 port, void *data,
                                      s32 dataLength) {
    u32 publicIp = inet_addr(ipText);
    return SBSendMessageToServer(&matchingServerList->mList, publicIp, ((port >> 8) & 0xff) | ((port << 8) & 0xff00),
                                 data, dataLength);
}

s32 ServerBrowserSendNatNegotiateCookieToServerA(MatchingServerList *matchingServerList, const char *ipText, s32 port,
                                                 u32 cookie) {
    u32 publicIp = inet_addr(ipText);
    return SBSendNatNegotiateCookieToServer(&matchingServerList->mList, publicIp,
                                            ((port >> 8) & 0xff) | ((port << 8) & 0xff00), cookie);
}

void ServerBrowserRemoveServer(struct MatchingServerList *matchingServerList, SBServer *server) {
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

SBServer *ServerBrowserGetServer(MatchingServerList *matchingServerList, u32 index) {
    return SBServerListNth(&matchingServerList->mList, index);
}

s32 ServerBrowserCount(MatchingServerList *matchingServerList) {
    return SBServerListCount(&matchingServerList->mList);
}

void ServerBrowserSortA(MatchingServerList *matchingServerList, u32 ascending, const char *sortKey, u32 compareKind) {
    SBServerListSort(&matchingServerList->mList, ascending, sortKey, compareKind);
}

u32 ServerBrowserGetMyPublicIPAddr(MatchingServerList *matchingServerList) {
    return matchingServerList->mList.mMyPublicIp;
}
