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

char *gSBOverrideMasterServer;

s32 StrCaseKeyCompare(SBServer **firstEntry, SBServer **secondEntry) {
    char *firstValue;
    char *secondValue;
    s32 result;
    firstValue = SBServerGetStringValueA(*firstEntry, gSortServerList->mSortKey, "");
    secondValue = SBServerGetStringValueA(*secondEntry, gSortServerList->mSortKey, "");
    result = strcmp(firstValue, secondValue);
    if (gSortServerList->mSortAscending == 0) {
        result = -result;
    }
    return result;
}

s32 StrNoCaseKeyCompare(SBServer **firstEntry, SBServer **secondEntry) {
    char *firstValue;
    char *secondValue;
    s32 result;
    firstValue = SBServerGetStringValueA(*firstEntry, gSortServerList->mSortKey, "");
    secondValue = SBServerGetStringValueA(*secondEntry, gSortServerList->mSortKey, "");
    result = CompareStringsMapped(firstValue, secondValue);
    if (gSortServerList->mSortAscending == 0) {
        result = -result;
    }
    return result;
}

void SBServerListSort(SBServerList *serverList, s32 ascending, const char *sortKey, u32 compareKind) {
    s32 (*comparator)(SBServer **, SBServer **);
    switch (compareKind) {
        case SORT_COMPARE_INT:
            comparator = IntKeyCompare;
            break;
        case SORT_COMPARE_FLOAT:
            comparator = FloatKeyCompare;
            break;
        case SORT_COMPARE_STRING:
            comparator = StrCaseKeyCompare;
            break;
        case SORT_COMPARE_STRING_IGNORE_CASE:
            comparator = StrNoCaseKeyCompare;
            break;
        default:
            comparator = StrNoCaseKeyCompare;
            break;
    }
    serverList->mSortKey = sortKey;
    serverList->mSortAscending = ascending;
    gSortServerList = serverList;
    ArraySort(serverList->mServers, (u32) comparator);
}

void SBServerListAppendServer(SBServerList *serverList, SBServer *server) {
    ArrayAppend(serverList->mServers, &server);
    serverList->mCallback(serverList, SERVER_LIST_REASON_SERVER_ADDED, server, serverList->mInstance);
}

int SBServerListFindServer(SBServerList *serverList, SBServer *server) {
    int count;
    SBServer **element;
    int index;
    count = ArrayLength(serverList->mServers);
    index = 0;
    if (0 < count) {
        do {
            element = ArrayNth(serverList->mServers, index);
            if (server == *element) {
                return index;
            }
            index = index + 1;
        } while (index < count);
    }
    return -1;
}

int SBServerListFindServerByIP(SBServerList *serverList, int publicIp, int publicPort) {
    SBServer *candidate;
    int index;
    int comparedValue;
    SBServer **entry;
    int count;
    count = ArrayLength(serverList->mServers);
    index = 0;
    if (0 < count) {
        do {
            entry = ArrayNth(serverList->mServers, index);
            candidate = *entry;
            comparedValue = SBServerGetPublicInetAddress(candidate);
            if ((publicIp == comparedValue) &&
                (comparedValue = SBServerGetPublicQueryPortNBO(candidate), publicPort == comparedValue)) {
                return index;
            }
            index = index + 1;
        } while (index < count);
    }
    return -1;
}

void AddServerToDeadlist(SBServerList *serverList, SBServer *server) {
    if (serverList->mDeadList == NULL) {
        SBServerSetNext(server, NULL);
    } else {
        SBServerSetNext(server, serverList->mDeadList);
    }
    serverList->mDeadList = server;
}

void SBServerListRemoveAt(SBServerList *serverList, s32 index) {
    SBServer *removedServer = *(SBServer **) ArrayNth(serverList->mServers, index);
    serverList->mCallback(serverList, SERVER_LIST_REASON_SERVER_DELETED, removedServer, serverList->mInstance);
    ArrayDeleteAt(serverList->mServers, index);
    AddServerToDeadlist(serverList, removedServer);
}

s32 SBServerListCount(SBServerList *serverList) {
    return ArrayLength(serverList->mServers);
}

SBServer *SBServerListNth(SBServerList *serverList, u32 index) {
    SBServer **element;
    element = ArrayNth(serverList->mServers, index);
    return *element;
}

void SBFreeDeadList(SBServerList *serverList) {
    SBServer *deadServer;
    SBServer *nextServer;
    if (serverList->mDeadList != NULL) {
        deadServer = serverList->mDeadList;
        while (deadServer != NULL) {
            nextServer = SBServerGetNext(deadServer);
            SBServerFree(&deadServer);
            deadServer = nextServer;
        }
        serverList->mDeadList = NULL;
    }
}

void SBServerListClear(SBServerList *serverList) {
    int count;
    SBServer **element;
    int index;
    count = ArrayLength(serverList->mServers);
    index = 0;
    if (0 < count) {
        do {
            element = ArrayNth(serverList->mServers, index);
            AddServerToDeadlist(serverList, *element);
            index = index + 1;
        } while (index < count);
    }
    ArrayClear(serverList->mServers);
    SBFreeDeadList(serverList);
}

void SBAllocateServerList(SBServerList *serverList) {
    serverList->mServers = ArrayNew(0x4u, 0x64u, 0x0u);
    serverList->mDeadList = NULL;
}

void *SBRefStr(SBServerList *serverList, const char *text) {
    s32 refString[2];
    s32 *entry;
    refString[0] = (s32) text;
    entry = TableLookup(SBRefStrHash(serverList), refString);
    if (entry != NULL) {
        entry[1] = entry[1] + 1;
        return (void *) entry[0];
    }
    refString[0] = (s32) goastrdup(text);
    refString[1] = 1;
    TableEnter(SBRefStrHash(serverList), refString);
    return (void *) refString[0];
}

void SBReleaseStr(SBServerList *serverList, u32 text) {
    s32 refString[2];
    s32 *entry;
    refString[0] = text;
    entry = TableLookup(SBRefStrHash(serverList), refString);
    if (entry == NULL) {
        AssertionFailed("val != NULL", "sb_serverlist.c", NULL, 0xf4);
    }
    if (entry != NULL) {
        entry[1] = entry[1] - 1;
        if (entry[1] == 0) {
            TableRemove(SBRefStrHash(serverList), refString);
        }
    }
}

int NTSLengthSB(const void *buffer, int length) {
    int position;
    const s8 *bytes = buffer;
    position = 0;
    if (0 < length) {
        do {
            if (bytes[position] == 0) {
                return position + 1;
            }
            position = position + 1;
        } while (position < length);
    }
    return -1;
}

static inline void CopyUnalignedWord(UnalignedWord *destination, UnalignedWord *source) {
    u8 *destinationBytes = (u8 *) destination;
    u8 *sourceBytes = (u8 *) source;
    destinationBytes[0] = sourceBytes[0];
    destinationBytes[1] = sourceBytes[1];
    destinationBytes[2] = sourceBytes[2];
    destinationBytes[3] = sourceBytes[3];
}

void SBServerListInit(SBServerList *slist, const char *queryForGameName, const char *queryFromGameName, const char *queryFromKey,
                      u32 queryFromVersion, s32 lanBrowse, SBListCallBackFn callback, void *instance) {
    if (slist == NULL) {
        AssertionFailed("slist != NULL", "sb_serverlist.c", NULL, 0x11c);
    }
    if (lanBrowse != 0 || gGsiAcResult == 1) {
        slist->mState = SERVER_LIST_STATE_NO_SOCKET;
        SBAllocateServerList(slist);
        SBRefStrHash(slist);
        strcpy(slist->mQueryForGameName, queryForGameName);
        strcpy(slist->mQueryFromGameName, queryFromGameName);
        strcpy(slist->mQueryFromKey, queryFromKey);
        slist->mCallback = callback;
        slist->mMaploopCallback = NULL;
        if (callback == NULL) {
            AssertionFailed("callback != NULL", "sb_serverlist.c", NULL, 0x132);
        }
        slist->mInstance = instance;
        slist->mSortKey = "";
        slist->mMyPublicIp = 0;
        slist->mSocket = -1;
        slist->mInBuffer = NULL;
        slist->mInBufferLength = 0;
        slist->mKeyList = NULL;
        slist->mExpectedElements = -1;
        slist->mNumPopularValues = 0;
        slist->mSrcIp = 0;
        slist->mFromGameVersion = queryFromVersion;
        SBSetLastListErrorPtr(slist, "");
        slist->mLanAdapterOverride = 0;
        srand(current_time());
        SocketStartUp();
    }
}

void ErrorDisconnect(SBServerList *serverList) {
    static const char *queryErrorPrefix = "Query Error: ";
    s32 length = serverList->mInBufferLength;
    const char *prefixForLength;
    const char *prefixForCompare;
    char *buffer;
    if (length > 0) {
        prefixForLength = queryErrorPrefix;
        if (length > strlen(prefixForLength)) {
            buffer = (char *) serverList->mInBuffer;
            prefixForCompare = queryErrorPrefix;
            if (strncmp(buffer, prefixForCompare, strlen(prefixForCompare)) == 0) {
                SBSetLastListErrorPtr(serverList, buffer + strlen(prefixForLength));
                serverList->mCallback(serverList, SERVER_LIST_REASON_QUERY_ERROR, gSBNullServer, serverList->mInstance);
            }
        }
    }
    serverList->mCallback(serverList, SERVER_LIST_REASON_DISCONNECTED, gSBNullServer, serverList->mInstance);
    SBServerListDisconnect(serverList);
}

u32 StringHash(const s8 *text, u32 modulus) {
    s32 character;
    u32 hash = 0;
    while ((character = *text) != 0) {
        if (character >= 0 && character < 0x80) {
            character = gLowerCaseMap[character];
        }
        hash *= 0x9ccf9319;
        hash += character;
        text++;
    }
    return hash % modulus;
}

s32 ServerListConnect(SBServerList *serverList) {
    SOCSockAddrIn masterAddress;
    char masterHost[0x80];
    u32 masterNumber;
    SOCHostEnt *hostEntry;
    masterNumber = StringHash((s8 *) serverList->mQueryForGameName, 0x14);
    if (gSBOverrideMasterServer != NULL) {
        strcpy(masterHost, gSBOverrideMasterServer);
    } else {
        sprintf(masterHost, "%s.ms%d.gs.nintendowifi.net", serverList->mQueryForGameName, masterNumber);
    }
    masterAddress.mFamily = SOCKET_FAMILY_IPV4;
    masterAddress.mPort = SB_MASTER_PORT_NETWORK_ORDER;
    masterAddress.mAddr = inet_addr(masterHost);
    if (masterAddress.mAddr == -1) {
        hostEntry = SOC_GetHostByName(masterHost);
        if (hostEntry == NULL) {
            return 2;
        }
        CopyUnalignedWord((UnalignedWord *) &masterAddress.mAddr, (UnalignedWord *) hostEntry->mAddrList[0]);
    }
    if (serverList->mSocket == -1) {
        serverList->mSocket = OpenNetSocket(2, 1, 0);
        if (serverList->mSocket == -1) {
            return 1;
        }
    }
    if (connect(serverList->mSocket, &masterAddress, 8) != 0) {
        closesocket(serverList->mSocket);
        serverList->mSocket = -1;
        return 3;
    }
    return 0;
}

void BufferAddNTS(u8 **buffer, const char *text, s32 *length) {
    u32 textLength;
    if (text == NULL) {
        text = "";
    }
    textLength = strlen(text) + 1;
    memcpy(*buffer, text, textLength);
    *length = *length + textLength;
    *buffer = *buffer + textLength;
}

void BufferAddByte(u8 **buffer, u8 value, s32 *length) {
    **buffer = value;
    *length = *length + 1;
    *buffer = *buffer + 1;
}

void BufferAddInt(u8 **buffer, u32 value, s32 *length) {
    u8 *bufferBytes = *buffer;
    u8 *valueBytes = (u8 *) &value;
    bufferBytes[0] = valueBytes[0];
    bufferBytes[1] = valueBytes[1];
    bufferBytes[2] = valueBytes[2];
    bufferBytes[3] = valueBytes[3];
    *length = *length + 4;
    *buffer = *buffer + 4;
}

void BufferAddData(u8 **buffer, const void *data, s32 dataLength, s32 *length) {
    memcpy(*buffer, data, dataLength);
    *length = *length + dataLength;
    *buffer = *buffer + dataLength;
}

void SetupListChallenge(SBServerList *serverList) {
    s32 earlierLessTrue;
    s32 earlierLessFalse;
    s32 firstBelowLimitTrue;
    s32 firstBelowLimitFalse;
    BOOL pairParityMask;
    s32 firstParityMask;
    s32 oddModeMask;
    s32 evenModeMask;
    s32 parityTerm;
    s32 modeBit;
    s32 index;
    serverList->mChallenge[0] = (s32) rand() % 0x5d + 0x21;
    modeBit = 0;
    index = 1;
    earlierLessFalse = 0;
    earlierLessTrue = 1;
    firstBelowLimitFalse = 0;
    firstBelowLimitTrue = 1;
    firstParityMask = 1;
    pairParityMask = TRUE;
    oddModeMask = 1;
    evenModeMask = 1;
    for (; index < 8; index++) {
        modeBit =
            ((serverList->mChallenge[0] & firstParityMask) ^
             (modeBit ^ (parityTerm = index, parityTerm = (s32) (parityTerm ^ serverList->mChallenge[index - 1]),
                         parityTerm &= pairParityMask, parityTerm))) ^
            ((serverList->mChallenge[0] < 0x4f) ? firstBelowLimitTrue : firstBelowLimitFalse) ^
            ((serverList->mChallenge[index - 1] < serverList->mChallenge[0]) ? earlierLessTrue : earlierLessFalse);
        serverList->mChallenge[index] = (s32) rand() % 0x5d + 0x21;
        if ((modeBit != 0 && (serverList->mChallenge[index] & oddModeMask) == 0) ||
            (modeBit == 0 && (serverList->mChallenge[index] & evenModeMask) == 1)) {
            serverList->mChallenge[index] += 1;
        }
    }
}

s32 SendWithRetry(SBServerList *serverList, void *data, s32 length) {
    s32 retriesLeft = 1;
    s32 sentLength;
    s32 error;
    do {
        retriesLeft--;
        sentLength = send(serverList->mSocket, data, length, 0);
        if (sentLength > 0) {
            break;
        }
        if (retriesLeft < 0) {
            break;
        }
        SBServerListDisconnect(serverList);
        error = SBServerListConnectAndQuery(serverList, NULL, NULL, 2, 0);
        if (error != 0) {
            ErrorDisconnect(serverList);
            return error;
        }
    } while (retriesLeft >= 0);
    if (sentLength <= 0) {
        return 3;
    }
    return 0;
}

s32 SBServerListConnectAndQuery(SBServerList *serverList, const char *fieldList, const char *serverFilter, u32 options,
                                u32 maxServers) {
    u8 request[0x300];
    u16 networkLength;
    s32 requestLength;
    u8 *requestCursor;
    u8 *requestStart;
    s32 error;
    if (serverList->mState != SERVER_LIST_STATE_NO_SOCKET) {
        AssertionFailed("slist->state == sl_disconnected", "sb_serverlist.c", NULL, 0x20a);
    }
    if (fieldList == NULL) {
        fieldList = "";
    }
    if (serverFilter == NULL) {
        serverFilter = "";
    }
    if (strlen(fieldList) > 0x100) {
        return 6;
    }
    if (strlen(serverFilter) > 0x100) {
        return 6;
    }
    error = ServerListConnect(serverList);
    if (error != 0) {
        return error;
    }
    serverList->mQueryOptions = options;
    SetupListChallenge(serverList);
    requestLength = 2;
    requestStart = request;
    requestCursor = requestStart + 2;
    BufferAddByte(&requestCursor, 0, &requestLength);
    BufferAddByte(&requestCursor, 1, &requestLength);
    BufferAddByte(&requestCursor, 3, &requestLength);
    BufferAddInt(&requestCursor, serverList->mFromGameVersion, &requestLength);
    BufferAddNTS(&requestCursor, serverList->mQueryForGameName, &requestLength);
    BufferAddNTS(&requestCursor, serverList->mQueryFromGameName, &requestLength);
    BufferAddData(&requestCursor, serverList->mChallenge, 8, &requestLength);
    BufferAddNTS(&requestCursor, serverFilter, &requestLength);
    BufferAddNTS(&requestCursor, fieldList, &requestLength);
    BufferAddInt(&requestCursor,
                 ((options << 24) & 0xff000000) |
                     (((options << 8) & 0xff0000) | (((options >> 24) & 0xff) | ((options >> 8) & 0xff00))),
                 &requestLength);
    if ((serverList->mQueryOptions & LIST_OPTION_SEND_SOURCE_IP) != 0) {
        BufferAddInt(&requestCursor, serverList->mSrcIp, &requestLength);
    }
    if ((serverList->mQueryOptions & LIST_OPTION_SEND_MAX_SERVERS) != 0) {
        BufferAddInt(&requestCursor, maxServers, &requestLength);
    }
    networkLength = (((u16) requestLength >> 8) & 0xff) | (((u16) requestLength << 8) & 0xff00);
    __memcpy(request, &networkLength, 2);
    if (send(serverList->mSocket, request, requestLength, 0) <= 0) {
        SBServerListDisconnect(serverList);
        return 3;
    }
    serverList->mState = SERVER_LIST_STATE_RECEIVING_LIST;
    serverList->mParseState = SERVER_LIST_PARSE_CIPHER_KEY;
    if (serverList->mInBuffer == NULL) {
        serverList->mInBuffer = DWCi_GsMalloc(0x1000);
        if (serverList->mInBuffer == NULL) {
            return 5;
        }
        serverList->mInBufferLength = 0;
    }
    return 0;
}

void FreePopularValues(SBServerList *serverList) {
    int valueIndex;
    for (valueIndex = 0; valueIndex < serverList->mNumPopularValues; valueIndex++) {
        SBReleaseStr(serverList, (u32) serverList->mPopularValues[valueIndex]);
    }
    serverList->mNumPopularValues = 0;
}

void FreeKeyList(SBServerList *serverList) {
    int keyIndex;
    if (serverList->mKeyList != NULL) {
        for (keyIndex = 0; keyIndex < ArrayLength(serverList->mKeyList); keyIndex++) {
            SBReleaseStr(serverList, *(u32 *) ArrayNth(serverList->mKeyList, keyIndex));
        }
        ArrayFree(serverList->mKeyList);
        serverList->mKeyList = NULL;
    }
}

void SBServerListDisconnect(SBServerList *serverList) {
    if (serverList->mInBuffer != NULL) {
        DWCi_GsFree(serverList->mInBuffer);
    }
    serverList->mInBuffer = NULL;
    serverList->mInBufferLength = 0;
    if (serverList->mSocket != -1) {
        closesocket(serverList->mSocket);
    }
    serverList->mSocket = -1;
    serverList->mState = SERVER_LIST_STATE_NO_SOCKET;
    FreeKeyList(serverList);
    serverList->mExpectedElements = -1;
    FreePopularValues(serverList);
}

void SBServerListCleanup(SBServerList *serverList) {
    SBServerListDisconnect(serverList);
    SBServerListClear(serverList);
    SBRefStrHashCleanup(serverList);
    if (serverList->mServers != NULL) {
        ArrayFree(serverList->mServers);
    }
    serverList->mServers = NULL;
}

void InitCryptKey(SBServerList *serverList, s8 *serverBytes, s32 length) {
    s32 keyLength;
    s8 *secretKey;
    s32 index;
    s8 *unusedPointer;
    keyLength = strlen(serverList->mQueryFromKey);
    secretKey = (s8 *) serverList->mQueryFromKey;
    for (index = 0; index < length; index++) {
        s32 keyChar = secretKey[index % keyLength];
        s32 targetIndex = index * keyChar % 8;
        s32 sourceIndex = index % 8;
        serverList->mChallenge[targetIndex] =
            serverList->mChallenge[targetIndex] ^ (s8) (serverList->mChallenge[sourceIndex] ^ serverBytes[index]);
    }
    GOACryptInit(&serverList->mCryptKey, (const u8 *) serverList->mChallenge, 8);
}

s32 ServerSizeForFlags(u32 flags) {
    s32 size;
    size = 5;
    if ((flags & SERVER_FLAG_PRIVATE_IP) != 0) {
        size += 4;
    }
    if ((flags & SERVER_FLAG_ICMP_IP) != 0) {
        size += 4;
    }
    if ((flags & SERVER_FLAG_NOT_DEFAULT_PORT) != 0) {
        size += 2;
    }
    if ((flags & SERVER_FLAG_NOT_DEFAULT_PRIVATE_PORT) != 0) {
        size += 2;
    }
    return size;
}

BOOL FullRulesPresent(u8 *buffer, s32 length) {
    s32 stringLength;
    while (length > 0 && *(s8 *) buffer != 0) {
        stringLength = NTSLengthSB(buffer, length);
        if (stringLength < 0) {
            return FALSE;
        }
        buffer += stringLength;
        length -= stringLength;
        stringLength = NTSLengthSB(buffer, length);
        if (stringLength < 0) {
            return FALSE;
        }
        buffer += stringLength;
        length -= stringLength;
    }
    if (length == 0) {
        return FALSE;
    }
    return *(s8 *) buffer == 0;
}

BOOL AllKeysPresent(SBServerList *serverList, u8 *buffer, s32 length) {
    s32 keyCount;
    s32 keyIndex;
    s32 stringLength;
    s32 stringIndex;
    keyCount = ArrayLength(serverList->mKeyList);
    keyIndex = 0;
    if (keyCount > 0) {
        do {
            switch (((KeyInfo *) ArrayNth(serverList->mKeyList, keyIndex))->mKeyType) {
                case SERVER_KEY_STORED_AS_ONE_BYTE:
                    buffer += 1;
                    length -= 1;
                    break;
                case SERVER_KEY_STORED_AS_TWO_BYTES:
                    buffer += 2;
                    length -= 2;
                    break;
                case SERVER_KEY_STORED_AS_STRING:
                    if (length < 1) {
                        return FALSE;
                    }
                    stringIndex = buffer[0];
                    buffer += 1;
                    length -= 1;
                    if (stringIndex == 0xff) {
                        stringLength = NTSLengthSB(buffer, length);
                        if (stringLength == -1) {
                            return FALSE;
                        }
                        buffer += stringLength;
                        length -= stringLength;
                    }
                    break;
                default:
                    AssertionFailed("0", "sb_serverlist.c", NULL, 0x317);
                    return FALSE;
            }
            if (length < 0) {
                return FALSE;
            }
            keyIndex++;
        } while (keyIndex < keyCount);
    }
    return TRUE;
}

void ParseServerIPPort(SBServerList *serverList, u8 *buffer, s32 length, u8 *ipOut, u16 *portOut) {
    u8 flags;
    u8 *cursor;
    u8 *portBytes;
    if (length >= 5) {
        flags = buffer[0];
        cursor = buffer + 1;
        ipOut[0] = cursor[0];
        ipOut[1] = cursor[1];
        ipOut[2] = cursor[2];
        ipOut[3] = cursor[3];
        if ((flags & SERVER_FLAG_NOT_DEFAULT_PORT) != 0) {
            if (length - 5 < 2) {
                return;
            }
            portBytes = (u8 *) portOut;
            cursor = buffer + 5;
            portBytes[0] = cursor[0];
            portBytes[1] = cursor[1];
        } else {
            *portOut = serverList->mDefaultPort;
        }
    }
}

s32 ParseServer(SBServerList *serverList, void *server, u8 *buffer, s32 length, s32 usePopularValues) {
    s32 keyCount;
    s32 startLength;
    s32 flags;
    s32 keyIndex;
    u16 shortValue;
    u16 privatePort;
    u32 ipAddress;
    s32 stringIndexOrLength;
    u8 *ruleKey;
    u8 *unusedPointer;
    u8 *valueBytes;
    KeyInfo *keyInfo;
    startLength = length;
    flags = buffer[0];
    SBServerSetFlags(server, flags);
    buffer += 5;
    length -= 5;
    if ((flags & SERVER_FLAG_NOT_DEFAULT_PORT) != 0) {
        buffer += 2;
        length -= 2;
    }
    if ((flags & SERVER_FLAG_PRIVATE_IP) != 0) {
        valueBytes = (u8 *) &ipAddress;
        valueBytes[0] = buffer[0];
        valueBytes[1] = buffer[1];
        valueBytes[2] = buffer[2];
        valueBytes[3] = buffer[3];
        buffer += 4;
        length -= 4;
    } else {
        ipAddress = 0;
    }
    if ((flags & SERVER_FLAG_NOT_DEFAULT_PRIVATE_PORT) != 0) {
        valueBytes = (u8 *) &privatePort;
        valueBytes[0] = buffer[0];
        valueBytes[1] = buffer[1];
        buffer += 2;
        length -= 2;
    } else {
        privatePort = serverList->mDefaultPort;
    }
    SBServerSetPrivateAddr(server, ipAddress, privatePort);
    if ((flags & SERVER_FLAG_ICMP_IP) != 0) {
        valueBytes = (u8 *) &ipAddress;
        valueBytes[0] = buffer[0];
        valueBytes[1] = buffer[1];
        valueBytes[2] = buffer[2];
        valueBytes[3] = buffer[3];
        buffer += 4;
        length -= 4;
        SBServerSetICMPIP(server, ipAddress);
    }
    if ((flags & SERVER_FLAG_HAS_KEY_VALUES) != 0) {
        keyCount = ArrayLength(serverList->mKeyList);
        keyIndex = 0;
        if (keyCount > 0) {
            do {
                keyInfo = ArrayNth(serverList->mKeyList, keyIndex);
                switch (keyInfo->mKeyType) {
                    case SERVER_KEY_STORED_AS_ONE_BYTE:
                        SBServerAddIntKeyValue(server, keyInfo->mKeyName, buffer[0]);
                        buffer += 1;
                        length -= 1;
                        break;
                    case SERVER_KEY_STORED_AS_TWO_BYTES:
                        valueBytes = (u8 *) &shortValue;
                        valueBytes[0] = buffer[0];
                        valueBytes[1] = buffer[1];
                        SBServerAddIntKeyValue(server, keyInfo->mKeyName,
                                       (u16) ((shortValue >> 8 & 0xff) | (shortValue << 8 & 0xff00)));
                        buffer += 2;
                        length -= 2;
                        break;
                    case SERVER_KEY_STORED_AS_STRING:
                        if (usePopularValues != 0) {
                            stringIndexOrLength = buffer[0];
                            buffer += 1;
                            length -= 1;
                        } else {
                            stringIndexOrLength = 0xff;
                        }
                        if (stringIndexOrLength == 0xff) {
                            SBServerAddKeyValue(server, keyInfo->mKeyName, (const char *) buffer);
                            stringIndexOrLength = strlen((const char *) buffer) + 1;
                            buffer += stringIndexOrLength;
                            length -= stringIndexOrLength;
                        } else {
                            SBServerAddKeyValue(server, keyInfo->mKeyName, serverList->mPopularValues[stringIndexOrLength]);
                        }
                        break;
                }
                keyIndex++;
            } while (keyIndex < keyCount);
        }
        SBServerSetState(server, SBServerGetState(server) | SERVER_STATE_HAS_BASIC_KEYS);
    }
    flags = flags & SERVER_FLAG_HAS_RULE_ENTRIES;
    if (flags != 0) {
        while ((s8) buffer[0] != 0 && length > 0) {
            ruleKey = buffer;
            stringIndexOrLength = strlen((const char *) buffer) + 1;
            buffer += stringIndexOrLength;
            length -= stringIndexOrLength;
            SBServerAddKeyValue(server, (const char *) ruleKey, (const char *) buffer);
            stringIndexOrLength = strlen((const char *) buffer) + 1;
            buffer += stringIndexOrLength;
            length -= stringIndexOrLength;
        }
        length -= 1;
        SBServerSetState(server, SBServerGetState(server) | SERVER_STATE_HAS_FULL_KEYS);
    }
    return startLength - length;
}

s32 IncomingListParseServer(SBServerList *serverList, u8 *buffer, s32 length) {
    s32 entrySize;
    s32 flags;
    SBServer *parsedServer;
    u16 netPort;
    u32 ipAddress;
    s32 parsedLength;
    if (length < 1) {
        return 0;
    }
    flags = buffer[0];
    entrySize = ServerSizeForFlags(flags);
    if (length < entrySize) {
        return 0;
    }
    if ((flags & SERVER_FLAG_HAS_KEY_VALUES) != 0) {
        if (AllKeysPresent(serverList, buffer + entrySize, length - entrySize) == FALSE) {
            return 0;
        }
    }
    flags = flags & SERVER_FLAG_HAS_RULE_ENTRIES;
    if (flags != 0) {
        if (FullRulesPresent(buffer + entrySize, length - entrySize) == FALSE) {
            return 0;
        }
    }
    if (memcmp(buffer + 1, "\xff\xff\xff\xff", 4) == 0) {
        return -1;
    }
    ParseServerIPPort(serverList, buffer, length, (u8 *) &ipAddress, &netPort);
    parsedServer = SBAllocServer(serverList, ipAddress, netPort);
    if (SBIsNullServer(parsedServer) != 0) {
        return -2;
    }
    parsedLength = ParseServer(serverList, parsedServer, buffer, length, 1);
    SBServerListAppendServer(serverList, parsedServer);
    return parsedLength;
}

void SBSetLastListErrorPtr(SBServerList *serverList, char *errorText) {
    serverList->mLastError = errorText;
}

s32 ProcessMainListData(SBServerList *serverList) {
    u8 *data;
    s32 length;
    s32 cryptHeaderLength;
    s32 keyLength;
    s32 headerEnd;
    s32 consumed;
    KeyInfo keyInfo;
    u8 *fieldBytes;
    u8 *portBytes;
    data = serverList->mInBuffer;
    length = serverList->mInBufferLength;
    switch (serverList->mParseState) {
        case SERVER_LIST_PARSE_CIPHER_KEY:
            if (length < 1) {
                break;
            }
            cryptHeaderLength = (data[0] ^ 0xec) + 2;
            if (length < cryptHeaderLength) {
                break;
            }
            keyLength = data[cryptHeaderLength - 1] ^ 0xea;
            headerEnd = cryptHeaderLength + keyLength;
            if (length < headerEnd) {
                break;
            }
            InitCryptKey(serverList, (s8 *) (data + cryptHeaderLength), keyLength);
            serverList->mParseState = SERVER_LIST_PARSE_ADDRESS;
            data += headerEnd;
            length -= headerEnd;
            GOADecrypt(&serverList->mCryptKey, data, length);
        case SERVER_LIST_PARSE_ADDRESS:
            if (length < 6) {
                break;
            }
            fieldBytes = (u8 *) &serverList->mMyPublicIp;
            fieldBytes[0] = data[0];
            fieldBytes[1] = data[1];
            fieldBytes[2] = data[2];
            fieldBytes[3] = data[3];
            serverList->mCallback(serverList, SERVER_LIST_REASON_PUBLIC_IP_RECEIVED, gSBNullServer, serverList->mInstance);
            fieldBytes = (u8 *) &serverList->mDefaultPort;
            portBytes = data + 4;
            fieldBytes[0] = portBytes[0];
            fieldBytes[1] = portBytes[1];
            if (serverList->mDefaultPort == LIST_ERROR_PORT) {
                if (NTSLengthSB(data + 6, length - 6) == -1) {
                    break;
                }
                SBSetLastListErrorPtr(serverList, (char *) (data + 6));
                serverList->mCallback(serverList, SERVER_LIST_REASON_QUERY_ERROR, gSBNullServer, serverList->mInstance);
                if (serverList->mInBuffer == NULL) {
                    break;
                }
            }
            data += 6;
            length -= 6;
            if ((serverList->mQueryOptions & LIST_OPTION_SKIP_SERVER_TABLE) != 0 ||
                serverList->mDefaultPort == LIST_ERROR_PORT) {
                serverList->mParseState = SERVER_LIST_PARSE_DONE;
                serverList->mState = SERVER_LIST_STATE_AD_HOC;
                break;
            }
            serverList->mParseState = SERVER_LIST_PARSE_FIELD_NAMES;
            serverList->mExpectedElements = -1;
        case SERVER_LIST_PARSE_FIELD_NAMES:
            if (serverList->mExpectedElements == -1) {
                if (length < 1) {
                    break;
                }
                serverList->mExpectedElements = data[0];
                serverList->mKeyList = ArrayNew(8, serverList->mExpectedElements, NULL);
                if (serverList->mKeyList == NULL) {
                    return 5;
                }
                data += 1;
                length -= 1;
            }
            while (serverList->mExpectedElements > ArrayLength(serverList->mKeyList)) {
                if (length < 2) {
                    break;
                }
                consumed = NTSLengthSB(data + 1, length - 1);
                if (consumed == -1) {
                    break;
                }
                keyInfo.mKeyType = data[0];
                keyInfo.mKeyName = SBRefStr(serverList, (const char *) (data + 1));
                ArrayAppend(serverList->mKeyList, &keyInfo);
                consumed += 1;
                data += consumed;
                length -= consumed;
            }
            if (serverList->mExpectedElements > ArrayLength(serverList->mKeyList)) {
                break;
            }
            serverList->mParseState = SERVER_LIST_PARSE_POPULAR_VALUES;
            serverList->mExpectedElements = -1;
        case SERVER_LIST_PARSE_POPULAR_VALUES:
            if (serverList->mExpectedElements == -1) {
                if (length < 1) {
                    break;
                }
                serverList->mExpectedElements = data[0];
                serverList->mNumPopularValues = 0;
                data += 1;
                length -= 1;
            }
            while (serverList->mExpectedElements > serverList->mNumPopularValues) {
                consumed = NTSLengthSB(data, length);
                if (consumed == -1) {
                    break;
                }
                serverList->mPopularValues[serverList->mNumPopularValues++] = SBRefStr(serverList, (const char *) data);
                data += consumed;
                length -= consumed;
            }
            if (serverList->mExpectedElements > serverList->mNumPopularValues) {
                break;
            }
            serverList->mParseState = SERVER_LIST_PARSE_ENTRIES;
        case SERVER_LIST_PARSE_ENTRIES:
            if (length < 5) {
                break;
            }
            do {
                consumed = IncomingListParseServer(serverList, data, length);
                if (consumed == -2) {
                    return 5;
                }
                if (consumed == -1) {
                    length -= 5;
                    data += 5;
                    serverList->mParseState = SERVER_LIST_PARSE_DONE;
                    serverList->mState = SERVER_LIST_STATE_AD_HOC;
                    serverList->mCallback(serverList, SERVER_LIST_REASON_LIST_FINISHED, gSBNullServer, serverList->mInstance);
                    break;
                }
                data += consumed;
                length -= consumed;
                if (serverList->mInBuffer == NULL) {
                    consumed = 0;
                }
            } while (consumed != 0);
            break;
    }
    if (length < 0) {
        AssertionFailed("inlen >= 0", "sb_serverlist.c", NULL, 0x4af);
    }
    if (serverList->mInBuffer == NULL) {
        return 0;
    }
    if (length != 0) {
        memmove(serverList->mInBuffer, data, length);
    }
    serverList->mInBufferLength = length;
    return 0;
}

s32 ProcessPushKeyList(SBServerList *serverList, u8 *buffer, s32 length) {
    s32 keyCount;
    s32 keyIndex;
    s32 nameLength;
    KeyInfo keyInfo;
    keyCount = buffer[0];
    buffer += 1;
    length -= 1;
    if (serverList->mKeyList != NULL) {
        FreeKeyList(serverList);
    }
    serverList->mKeyList = ArrayNew(8, keyCount, NULL);
    if (serverList->mKeyList == NULL) {
        return 5;
    }
    keyIndex = 0;
    if (keyCount > 0) {
        do {
            if (length < 2) {
                return 4;
            }
            nameLength = NTSLengthSB(buffer + 1, length - 1);
            if (nameLength == -1) {
                return 4;
            }
            keyInfo.mKeyType = buffer[0];
            keyInfo.mKeyName = SBRefStr(serverList, (const char *) (buffer + 1));
            ArrayAppend(serverList->mKeyList, &keyInfo);
            nameLength += 1;
            buffer += nameLength;
            length -= nameLength;
            keyIndex++;
        } while (keyIndex < keyCount);
    }
    return 0;
}

s32 ProcessPlayerSearch(SBServerList *serverList, u8 *buffer, s32 length) {
    s32 isLast;
    s32 resultIndex;
    s32 entryCount;
    s32 nameLength;
    s32 gameNameLength;
    u8 *name;
    u32 ipAddress;
    u16 netPort;
    u32 lastSeenTime;
    u8 *source;
    u8 *destination;
    if (length < 2) {
        return 4;
    }
    isLast = buffer[0];
    entryCount = buffer[1];
    buffer += 2;
    length -= 2;
    resultIndex = 0;
    if (entryCount > 0) {
        do {
            name = buffer;
            nameLength = NTSLengthSB(buffer, length);
            if (nameLength == -1) {
                return 4;
            }
            buffer += nameLength;
            length -= nameLength;
            if (length < 11) {
                return 4;
            }
            source = buffer;
            destination = (u8 *) &ipAddress;
            destination[0] = source[0];
            destination[1] = source[1];
            destination[2] = source[2];
            destination[3] = source[3];
            source = buffer + 4;
            destination = (u8 *) &netPort;
            destination[0] = source[0];
            destination[1] = source[1];
            source = buffer + 6;
            destination = (u8 *) &lastSeenTime;
            destination[0] = source[0];
            destination[1] = source[1];
            destination[2] = source[2];
            destination[3] = source[3];
            lastSeenTime =
                (lastSeenTime << 24 & 0xff000000) |
                ((lastSeenTime << 8 & 0xff0000) | ((lastSeenTime >> 24 & 0xff) | (lastSeenTime >> 8 & 0xff00)));
            buffer += 10;
            length -= 10;
            gameNameLength = NTSLengthSB(buffer, length);
            if (gameNameLength == -1) {
                return 4;
            }
            serverList->mPlayerSearchCallback(serverList, name, ipAddress, netPort, lastSeenTime, buffer,
                                              serverList->mInstance);
            buffer += gameNameLength;
            length -= gameNameLength;
            resultIndex++;
        } while (resultIndex < entryCount);
    }
    if (isLast != 0) {
        serverList->mPlayerSearchCallback(serverList, 0, 0, 0, 0, 0, serverList->mInstance);
    }
    return 0;
}

s32 ProcessMaploop(SBServerList *serverList, u8 *buffer, s32 length) {
    u32 maploopValue;
    u32 ipAddress;
    u16 netPort;
    SBServer *foundServer;
    s32 nameCount;
    s32 callResult;
    s32 mapIndex;
    u8 *mapNames[16];
    u8 *source;
    u8 *destination;
    u8 *unusedLocal;
    if (length < 11) {
        return 4;
    }
    source = buffer;
    destination = (u8 *) &ipAddress;
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
    destination = (u8 *) &netPort;
    source = buffer + 4;
    destination[0] = source[0];
    destination[1] = source[1];
    callResult = SBServerListFindServerByIP(serverList, ipAddress, netPort);
    if (callResult == -1) {
        return 0;
    }
    foundServer = SBServerListNth(serverList, callResult);
    destination = (u8 *) &maploopValue;
    source = buffer + 6;
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
    maploopValue = (maploopValue << 24 & 0xff000000) |
                   ((maploopValue << 8 & 0xff0000) | ((maploopValue >> 24 & 0xff) | (maploopValue >> 8 & 0xff00)));
    nameCount = buffer[10];
    buffer += 11;
    length -= 11;
    for (mapIndex = 0; mapIndex < nameCount && mapIndex < 16;) {
        if (length < 1) {
            break;
        }
        callResult = NTSLengthSB(buffer, length);
        if (callResult == -1) {
            return 4;
        }
        mapNames[mapIndex] = buffer;
        buffer += callResult;
        length -= callResult;
        mapIndex++;
    }
    if (serverList->mMaploopCallback == NULL) {
        return 0;
    }
    serverList->mMaploopCallback(serverList, foundServer, maploopValue, mapIndex, mapNames, serverList->mInstance);
    return 0;
}

s32 ProcessDeleteServer(SBServerList *serverList, u8 *buffer, s32 length) {
    u32 ipAddress;
    u16 netPort;
    s32 serverIndex;
    u8 *source;
    u8 *destination;
    if (length < 6) {
        return 4;
    }
    source = buffer;
    destination = (u8 *) &ipAddress;
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
    destination = (u8 *) &netPort;
    source = buffer + 4;
    destination[0] = source[0];
    destination[1] = source[1];
    serverIndex = SBServerListFindServerByIP(serverList, ipAddress, netPort);
    if (serverIndex != -1) {
        SBServerListRemoveAt(serverList, serverIndex);
        return 0;
    }
    return 0;
}

s32 ProcessPushServer(SBServerList *serverList, u8 *buffer, s32 length) {
    s32 serverIndex;
    SBServer *pushedServer;
    u16 netPort;
    u32 ipAddress;
    if (length < 5) {
        return 4;
    }
    ParseServerIPPort(serverList, buffer, length, (u8 *) &ipAddress, &netPort);
    serverIndex = SBServerListFindServerByIP(serverList, ipAddress, netPort);
    if (serverIndex == -1) {
        pushedServer = SBAllocServer(serverList, ipAddress, netPort);
        if (SBIsNullServer(pushedServer) != 0) {
            return 5;
        }
    } else {
        pushedServer = SBServerListNth(serverList, serverIndex);
    }
    if (ParseServer(serverList, pushedServer, buffer, length, 0) < 0) {
        return 4;
    }
    if (serverIndex == -1) {
        SBServerListAppendServer(serverList, pushedServer);
    }
    serverList->mCallback(serverList, SERVER_LIST_REASON_SERVER_UPDATED, pushedServer, serverList->mInstance);
    return 0;
}

s32 ProcessAdHocData(SBServerList *slist) {
    s32 error;
    u16 messageLength;
    u8 *lengthBytes;
    u8 *inBuffer;
    error = 0;
    while (slist->mInBufferLength >= 3) {
        lengthBytes = (u8 *) &messageLength;
        inBuffer = slist->mInBuffer;
        lengthBytes[0] = inBuffer[0];
        lengthBytes[1] = inBuffer[1];
        messageLength = (messageLength >> 8 & 0xff) | (messageLength << 8 & 0xff00);
        if (messageLength > 0x1000) {
            error = 4;
            break;
        }
        if (slist->mInBufferLength < messageLength) {
            return 0;
        }
        switch ((s8) slist->mInBuffer[2]) {
            case LIST_MESSAGE_PUSH_KEY_LIST:
                error = ProcessPushKeyList(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
            case LIST_IN_ADD_SERVER:
                error = ProcessPushServer(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
            case LIST_MESSAGE_ECHO:
                if (send(slist->mSocket, slist->mInBuffer, messageLength, 0) <= 0) {
                    return 3;
                }
                break;
            case LIST_IN_REMOVE_SERVER:
                error = ProcessDeleteServer(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
            case LIST_IN_MAPLOOP:
                error = ProcessMaploop(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
            case LIST_MESSAGE_PLAYER_SEARCH:
                error = ProcessPlayerSearch(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
        }
        slist->mInBufferLength -= messageLength;
        if (slist->mInBufferLength < 0) {
            AssertionFailed("slist->inbufferlen >= 0", "sb_serverlist.c", NULL, 0x5b4);
        }
        if (slist->mInBufferLength != 0 && slist->mInBuffer != NULL) {
            memmove(slist->mInBuffer, slist->mInBuffer + messageLength, slist->mInBufferLength);
        }
        if (error != 0) {
            break;
        }
    }
    if (error != 0) {
        ErrorDisconnect(slist);
    }
    return error;
}

s32 ProcessIncomingData(SBServerList *serverList) {
    s32 oldLength;
    s32 received;
    s32 error;
    if (CanReceiveOnSocket(serverList->mSocket) == 0) {
        return 0;
    }
    oldLength = serverList->mInBufferLength;
    received = recv(serverList->mSocket, serverList->mInBuffer + oldLength, 0x1000 - oldLength, 0);
    if ((u32) (received + 1) <= 1) {
        ErrorDisconnect(serverList);
        return 3;
    }
    serverList->mInBufferLength += received;
    error = 0;
    if (serverList->mState == SERVER_LIST_STATE_AD_HOC || serverList->mParseState > SERVER_LIST_PARSE_CIPHER_KEY) {
        GOADecrypt(&serverList->mCryptKey, serverList->mInBuffer + oldLength, serverList->mInBufferLength - oldLength);
    }
    if (serverList->mState == SERVER_LIST_STATE_RECEIVING_LIST) {
        error = ProcessMainListData(serverList);
    }
    if (error != 0) {
        return error;
    }
    if (serverList->mState == SERVER_LIST_STATE_AD_HOC && serverList->mInBufferLength > 0) {
        return ProcessAdHocData(serverList);
    }
    return 0;
}

s32 SBSendMessageToServer(SBServerList *serverList, u32 publicIp, u16 port, u8 *data, s32 dataLength) {
    SendMessageRequest request;
    u16 messageLength;
    u8 *destination;
    u8 *source;
    s32 error;
    if (serverList->mState == SERVER_LIST_STATE_NO_SOCKET) {
        SBServerListConnectAndQuery(serverList, NULL, NULL, 2, 0);
    }
    if (serverList->mState == SERVER_LIST_STATE_NO_SOCKET) {
        return 3;
    }
    messageLength = dataLength + 9;
    request.mNetLength = (messageLength >> 8 & 0xff) | (messageLength << 8 & 0xff00);
    destination = request.mRequestLength;
    source = (u8 *) &request.mNetLength;
    destination[0] = source[0];
    destination[1] = source[1];
    request.mRequestType = LIST_REQUEST_RELAY_TO_SERVER;
    destination = request.mRequestIp;
    source = (u8 *) &publicIp;
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
    destination = request.mRequestPort;
    source = (u8 *) &port;
    destination[0] = source[0];
    destination[1] = source[1];
    error = SendWithRetry(serverList, request.mRequestLength, 9);
    if (error != 0) {
        return error;
    }
    if (send(serverList->mSocket, data, dataLength, 0) < 0) {
        return 3;
    }
    return 0;
}

s32 SBSendNatNegotiateCookieToServer(SBServerList *serverList, u32 publicIp, u16 port, u32 cookie) {
    u8 message[10];
    u8 *destination;
    u8 *source;
    message[0] = 0xfd;
    message[1] = 0xfc;
    message[2] = 0x1e;
    message[3] = 0x66;
    message[4] = 0x6a;
    message[5] = 0xb2;
    cookie =
        (cookie << 24 & 0xff000000) | ((cookie << 8 & 0xff0000) | ((cookie >> 24 & 0xff) | (cookie >> 8 & 0xff00)));
    destination = message + 6;
    source = (u8 *) &cookie;
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
    return SBSendMessageToServer(serverList, publicIp, port, message, 10);
}

s32 ProcessLanData(SBServerList *serverList) {
    SocketAddress sender;
    s32 senderLength;
    u8 datagram[0x5e0];
    SBServer *lanServer;
    senderLength = 8;
    while (CanReceiveOnSocket(serverList->mSocket) != 0) {
        if (recvfrom(serverList->mSocket, datagram, 0x5db, 0, &sender, &senderLength) != -1) {
            if (SBServerListFindServerByIP(serverList, sender.mAddress, sender.mPort) == -1) {
                lanServer = SBAllocServer(serverList, sender.mAddress, sender.mPort);
                if (SBIsNullServer(lanServer) != 0) {
                    return 5;
                }
                SBServerSetFlags(lanServer, SERVER_FLAG_UDP_QUERY | SERVER_FLAG_NOT_DEFAULT_PORT);
                SBServerListAppendServer(serverList, lanServer);
            }
        }
    }
    if (current_time() - serverList->mLanStartTime > LOCAL_SCAN_DURATION_MSEC) {
        closesocket(serverList->mSocket);
        serverList->mSocket = -1;
        serverList->mState = SERVER_LIST_STATE_NO_SOCKET;
        serverList->mCallback(serverList, SERVER_LIST_REASON_LIST_FINISHED, gSBNullServer, serverList->mInstance);
    }
    return 0;
}

s32 SBListThink(SBServerList *serverList) {
    SBFreeDeadList(serverList);
    switch (serverList->mState) {
        case SERVER_LIST_STATE_AD_HOC:
        case SERVER_LIST_STATE_RECEIVING_LIST:
            return ProcessIncomingData(serverList);
        case SERVER_LIST_STATE_LOCAL_SCAN:
            return ProcessLanData(serverList);
        case SERVER_LIST_STATE_NO_SOCKET:
        default:
            return 0;
    }
}
