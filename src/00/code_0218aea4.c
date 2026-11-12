#include "00/code_0218aea4.h"

#include "00/code_0218e2dc.h"
#include "00/sb_queryengine.h"
#include "00/types_0218b928.h"
#include "03/code_021bb03c.h" // SocketAddress
#include "00/code_0218d000.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_0218dd8c.h"
#include "code_0214177c.h"
#include "00/unk_021b4000.h"
#include "code_02133274.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_0218a000.h"
#include "00/code_0218c000.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218b000.h"
#include "03/code_021b94b8.h"
#include "00/code_021a4b84.h"
#include "string.h"
#include "00/code_0218a67c.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "00/code_02190000.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196594.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02192d64.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_021a3a18.h"
#include "00/code_0218a71c.h"
#include "code_021384cc.h"
#include "00/code_021919ac.h"
#include "code_021382a8.h"
#include "00/code_0218d488.h"
#include "00/code_021a6d5c.h"

s32 StrCaseKeyCompare(u32 *firstEntry, u32 *secondEntry) {
    char *firstValue;
    char *secondValue;
    s32 result;
    firstValue = SbServerGetValue((SbServer *) *firstEntry, gSortServerList->mSortKey, data_ov000_021b2260);
    secondValue = SbServerGetValue((SbServer *) *secondEntry, gSortServerList->mSortKey, data_ov000_021b2260);
    result = strcmp(firstValue, secondValue);
    if (gSortServerList->mSortAscending == 0) {
        result = -result;
    }
    return result;
}

s32 StrNoCaseKeyCompare(u32 *firstEntry, u32 *secondEntry) {
    char *firstValue;
    char *secondValue;
    s32 result;
    firstValue = SbServerGetValue((SbServer *) *firstEntry, gSortServerList->mSortKey, data_ov000_021b2260);
    secondValue = SbServerGetValue((SbServer *) *secondEntry, gSortServerList->mSortKey, data_ov000_021b2260);
    result = CompareStringsMapped(firstValue, secondValue);
    if (gSortServerList->mSortAscending == 0) {
        result = -result;
    }
    return result;
}

void SBServerListSort(SbServerList *serverList, s32 ascending, const char *sortField, u32 compareKind) {
    s32 (*comparator)(u32 *, u32 *);
    switch (compareKind) {
        case 0:
            comparator = IntKeyCompare;
            break;
        case 1:
            comparator = FloatKeyCompare;
            break;
        case 2:
            comparator = StrCaseKeyCompare;
            break;
        case 3:
            comparator = StrNoCaseKeyCompare;
            break;
        default:
            comparator = StrNoCaseKeyCompare;
            break;
    }
    serverList->mSortKey = sortField;
    serverList->mSortAscending = ascending;
    gSortServerList = serverList;
    DarraySort(serverList->mServers, (u32) comparator);
}

void SBServerListAppendServer(SbServerList *serverList, u32 server) {
    DarrayAppend(serverList->mServers, &server);
    serverList->mCallback(serverList, 0, server, serverList->mInstance);
}

int SBServerListFindServer(SbServerList *serverList, int server) {
    int count;
    int *element;
    int index;
    count = DarrayGetCount(serverList->mServers);
    index = 0;
    if (0 < count) {
        do {
            element = DarrayGetElement(serverList->mServers, index);
            if (server == *element) {
                return index;
            }
            index = index + 1;
        } while (index < count);
    }
    return -1;
}

int SBServerListFindServerByIP(SbServerList *serverList, int publicIp, int publicPort) {
    u32 candidate;
    int index;
    int comparedValue;
    u32 *entry;
    int count;
    count = DarrayGetCount(serverList->mServers);
    index = 0;
    if (0 < count) {
        do {
            entry = DarrayGetElement(serverList->mServers, index);
            candidate = *entry;
            comparedValue = SBServerGetPublicInetAddress(((u32 *) (u32) candidate));
            if ((publicIp == comparedValue) &&
                (comparedValue = SBServerGetPublicQueryPortNBO(candidate), publicPort == comparedValue)) {
                return index;
            }
            index = index + 1;
        } while (index < count);
    }
    return -1;
}

void AddServerToDeadlist(SbServerList *serverList, u32 server) {
    if (serverList->mDeadList == 0) {
        SBServerSetNext(server, 0);
    } else {
        SBServerSetNext(server, serverList->mDeadList);
    }
    serverList->mDeadList = server;
}

void SBServerListRemoveAt(SbServerList *serverList, s32 index) {
    u32 removedServer = *(u32 *) DarrayGetElement(serverList->mServers, index);
    serverList->mCallback(serverList, 2, removedServer, serverList->mInstance);
    DarrayRemove(serverList->mServers, index);
    AddServerToDeadlist(serverList, removedServer);
}

u32 SBServerListCount(SbServerList *serverList) {
    u32 count;
    u32 calleeAddress;
    calleeAddress = (u32) &DarrayGetCount;
    count = DarrayGetCount(serverList->mServers);
    return count;
}

u32 SBServerListNth(SbServerList *serverList, u32 index) {
    u32 *element;
    element = DarrayGetElement(serverList->mServers, index);
    return *element;
}

void SBFreeDeadList(SbServerList *serverList) {
    int deadServer;
    int nextServer;
    if (serverList->mDeadList != 0) {
        deadServer = serverList->mDeadList;
        while (deadServer != 0) {
            nextServer = SBServerGetNext(deadServer);
            SBServerFree(&deadServer);
            deadServer = nextServer;
        }
        serverList->mDeadList = 0;
    }
}

void SBServerListClear(SbServerList *serverList) {
    int count;
    u32 *element;
    int index;
    count = DarrayGetCount(serverList->mServers);
    index = 0;
    if (0 < count) {
        do {
            element = DarrayGetElement(serverList->mServers, index);
            AddServerToDeadlist(serverList, *element);
            index = index + 1;
        } while (index < count);
    }
    DarrayRemoveAll(serverList->mServers);
    SBFreeDeadList(serverList);
}

void SBAllocateServerList(u32 serverList) {
    u32 listAddress = ((serverList) + (0x0u));
    u32 serversArray = (u32) DarrayCreate(0x4u, 0x64u, 0x0u);
    u32 deadListOffset;
    *(u32 *) ((listAddress) + (4)) = serversArray;
    deadListOffset = 0x5d0u;
    *(u32 *) ((listAddress) + (0 + (deadListOffset))) = 0x0u;
}

void *SBRefStr(SbServerList *serverList, const char *text) {
    s32 refString[2];
    s32 *entry;
    refString[0] = (s32) text;
    entry = HashtableFind(SBRefStrHash(serverList), refString);
    if (entry != NULL) {
        entry[1] = entry[1] + 1;
        return (void *) entry[0];
    }
    refString[0] = (s32) goastrdup(text);
    refString[1] = 1;
    HashtableSet(SBRefStrHash(serverList), refString);
    return (void *) refString[0];
}

void SBReleaseStr(SbServerList *serverList, u32 text) {
    s32 refString[2];
    s32 *entry;
    refString[0] = text;
    entry = HashtableFind(SBRefStrHash(serverList), refString);
    if (entry == NULL) {
        AssertionFailed(gValAssertText, gSBServerListFileName, NULL, 0xf4);
    }
    if (entry != NULL) {
        entry[1] = entry[1] - 1;
        if (entry[1] == 0) {
            HashtableRemove(SBRefStrHash(serverList), refString);
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

void SbServerListInit(SbServerList *slist, const char *targetName, const char *sourceName,
                      const char *queryFromKey, u32 queryFromVersion, s32 lanBrowse, UnkFunc *callback,
                      void *instance) {
    if (slist == NULL) {
        AssertionFailed(gSlistAssertText, gSBServerListFileName, NULL, 0x11c);
    }
    if (lanBrowse != 0 || gGsiAcResult == 1) {
        slist->mState = 1;
        SBAllocateServerList((u32) slist);
        SBRefStrHash(slist);
        strcpy(slist->mQueryForGameName, targetName);
        strcpy(slist->mQueryFromGameName, sourceName);
        strcpy(slist->mQueryFromKey, queryFromKey);
        slist->mCallback = callback;
        slist->mMaploopCallback = NULL;
        if (callback == NULL) {
            AssertionFailed(gCallbackAssertText, gSBServerListFileName, NULL, 0x132);
        }
        slist->mInstance = instance;
        slist->mSortKey = data_ov000_021b2260;
        slist->mMyPublicIp = 0;
        slist->mSocket = -1;
        slist->mInBuffer = NULL;
        slist->mInBufferLength = 0;
        slist->mKeyList = NULL;
        slist->mExpectedElements = -1;
        slist->mNumPopularValues = 0;
        slist->mSrcIp = 0;
        slist->mFromGameVersion = queryFromVersion;
        SBSetLastListErrorPtr(slist, data_ov000_021b2260);
        slist->mLanAdapterOverride = 0;
        srand(GetElapsedMilliseconds());
        SocketStartUp();
    }
}

void ErrorDisconnect(SbServerList *serverList) {
    s32 length = serverList->mInBufferLength;
    const char *prefixForLength;
    const char *prefixForCompare;
    char *buffer;
    if (length > 0) {
        prefixForLength = gQueryErrorPrefix;
        if (length > strlen(prefixForLength)) {
            buffer = (char *) serverList->mInBuffer;
            prefixForCompare = gQueryErrorPrefix;
            if (strncmp(buffer, prefixForCompare, strlen(prefixForCompare)) == 0) {
                SBSetLastListErrorPtr(serverList, buffer + strlen(prefixForLength));
                serverList->mCallback(serverList, 5, gSBNullServer, serverList->mInstance);
            }
        }
    }
    serverList->mCallback(serverList, 4, gSBNullServer, serverList->mInstance);
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

s32 ServerListConnect(SbServerList *serverList) {
    SOCSockAddrIn masterAddress;
    char masterHost[0x80];
    u32 masterNumber;
    SOCHostEnt *hostEntry;
    masterNumber = StringHash((s8 *) serverList->mQueryForGameName, 0x14);
    if (gSBOverrideMasterServer != NULL) {
        strcpy(masterHost, gSBOverrideMasterServer);
    } else {
        sprintf(masterHost, gMasterHostFormat, serverList->mQueryForGameName, masterNumber);
    }
    masterAddress.mFamily = 2;
    masterAddress.mPort = 0xee70;
    masterAddress.mAddr = inet_addr((u32) masterHost);
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
        text = data_ov000_021b2260;
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

void SetupListChallenge(SbServerList *serverList) {
    s32 earlierLessTrue;
    s32 earlierLessFalse;
    s32 firstBelowLimitTrue;
    s32 firstBelowLimitFalse;
    BOOL pairParityMask;
    s32 firstParityMask;
    s32 oddModeMask;
    s32 evenModeMask;
    s32 parityTerm;
    s32 altMode;
    s32 index;
    serverList->mChallenge[0] = (s32) rand() % 0x5d + 0x21;
    altMode = 0;
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
        altMode =
            ((serverList->mChallenge[0] & firstParityMask) ^
             (altMode ^ (parityTerm = index, parityTerm = (s32) (parityTerm ^ serverList->mChallenge[index - 1]),
                         parityTerm &= pairParityMask, parityTerm))) ^
            ((serverList->mChallenge[0] < 0x4f) ? firstBelowLimitTrue : firstBelowLimitFalse) ^
            ((serverList->mChallenge[index - 1] < serverList->mChallenge[0]) ? earlierLessTrue : earlierLessFalse);
        serverList->mChallenge[index] = (s32) rand() % 0x5d + 0x21;
        if ((altMode != 0 && (serverList->mChallenge[index] & oddModeMask) == 0) ||
            (altMode == 0 && (serverList->mChallenge[index] & evenModeMask) == 1)) {
            serverList->mChallenge[index] += 1;
        }
    }
}

s32 SendWithRetry(SbServerList *serverList, void *data, s32 length) {
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

s32 SBServerListConnectAndQuery(SbServerList *serverList, const char *fieldList, const char *serverFilter, u32 options,
                                u32 maxServers) {
    u8 request[0x300];
    u16 networkLength;
    s32 requestLength;
    u8 *requestCursor;
    u8 *requestStart;
    s32 error;
    if (serverList->mState != 1) {
        AssertionFailed(gDisconnectedAssertText, gSBServerListFileName, NULL, 0x20a);
    }
    if (fieldList == NULL) {
        fieldList = data_ov000_021b2260;
    }
    if (serverFilter == NULL) {
        serverFilter = data_ov000_021b2260;
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
    if ((serverList->mQueryOptions & 8) != 0) {
        BufferAddInt(&requestCursor, serverList->mSrcIp, &requestLength);
    }
    if ((serverList->mQueryOptions & 0x80) != 0) {
        BufferAddInt(&requestCursor, maxServers, &requestLength);
    }
    networkLength = (((u16) requestLength >> 8) & 0xff) | (((u16) requestLength << 8) & 0xff00);
    __memcpy(request, &networkLength, 2);
    if (send(serverList->mSocket, request, requestLength, 0) <= 0) {
        SBServerListDisconnect(serverList);
        return 3;
    }
    serverList->mState = 3;
    serverList->mParseState = 0;
    if (serverList->mInBuffer == NULL) {
        serverList->mInBuffer = DWCi_GsMalloc(0x1000);
        if (serverList->mInBuffer == NULL) {
            return 5;
        }
        serverList->mInBufferLength = 0;
    }
    return 0;
}

void FreePopularValues(SbServerList *serverList) {
    int i;
    for (i = 0; i < serverList->mNumPopularValues; i++) {
        SBReleaseStr(serverList, (u32) serverList->mPopularValues[i]);
    }
    serverList->mNumPopularValues = 0;
}

void FreeKeyList(SbServerList *serverList) {
    int i;
    if (serverList->mKeyList != NULL) {
        for (i = 0; i < DarrayGetCount(serverList->mKeyList); i++) {
            SBReleaseStr(serverList, *(u32 *) DarrayGetElement(serverList->mKeyList, i));
        }
        DarrayDelete(serverList->mKeyList);
        serverList->mKeyList = NULL;
    }
}

void SBServerListDisconnect(SbServerList *serverList) {
    if (serverList->mInBuffer != NULL) {
        DWCi_GsFree(serverList->mInBuffer);
    }
    serverList->mInBuffer = NULL;
    serverList->mInBufferLength = 0;
    if (serverList->mSocket != -1) {
        closesocket(serverList->mSocket);
    }
    serverList->mSocket = -1;
    serverList->mState = 1;
    FreeKeyList(serverList);
    serverList->mExpectedElements = -1;
    FreePopularValues(serverList);
}

void SBServerListCleanup(SbServerList *serverList) {
    SBServerListDisconnect(serverList);
    SBServerListClear(serverList);
    SBRefStrHashCleanup(serverList);
    if (serverList->mServers != NULL) {
        DarrayDelete(serverList->mServers);
    }
    serverList->mServers = NULL;
}

void InitCryptKey(SbServerList *serverList, s8 *serverBytes, s32 length) {
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
    GOACryptInit((GOACryptState *) serverList->mCryptKey, (const u8 *) serverList->mChallenge, 8);
}

s32 ServerSizeForFlags(u32 flags) {
    s32 size;
    size = 5;
    if ((flags & 2) != 0) {
        size += 4;
    }
    if ((flags & 8) != 0) {
        size += 4;
    }
    if ((flags & 0x10) != 0) {
        size += 2;
    }
    if ((flags & 0x20) != 0) {
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

BOOL AllKeysPresent(SbServerList *serverList, u8 *buffer, s32 length) {
    s32 keyCount;
    s32 keyIndex;
    s32 stringLength;
    s32 stringIndex;
    keyCount = DarrayGetCount(serverList->mKeyList);
    keyIndex = 0;
    if (keyCount > 0) {
        do {
            switch (((KeyInfo *) DarrayGetElement(serverList->mKeyList, keyIndex))->mKeyType) {
                case 1:
                    buffer += 1;
                    length -= 1;
                    break;
                case 2:
                    buffer += 2;
                    length -= 2;
                    break;
                case 0:
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
                    AssertionFailed(gFalseAssertText, gSBServerListFileName, NULL, 0x317);
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

void ParseServerIPPort(SbServerList *serverList, u8 *buffer, s32 length, u8 *ipOut, u16 *portOut) {
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
        if ((flags & 0x10) != 0) {
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

s32 ParseServer(SbServerList *serverList, void *server, u8 *buffer, s32 length, s32 popularOnly) {
    s32 keyCount;
    s32 startLength;
    s32 flags;
    s32 keyIndex;
    u16 shortValue;
    u16 privatePort;
    u32 ipAddress;
    s32 stringValue;
    u8 *ruleKey;
    u8 *unusedPointer;
    u8 *valueBytes;
    KeyInfo *keyInfo;
    startLength = length;
    flags = buffer[0];
    SBServerSetFlags(server, flags);
    buffer += 5;
    length -= 5;
    if ((flags & 0x10) != 0) {
        buffer += 2;
        length -= 2;
    }
    if ((flags & 2) != 0) {
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
    if ((flags & 0x20) != 0) {
        valueBytes = (u8 *) &privatePort;
        valueBytes[0] = buffer[0];
        valueBytes[1] = buffer[1];
        buffer += 2;
        length -= 2;
    } else {
        privatePort = serverList->mDefaultPort;
    }
    SBServerSetPrivateAddr(server, ipAddress, privatePort);
    if ((flags & 8) != 0) {
        valueBytes = (u8 *) &ipAddress;
        valueBytes[0] = buffer[0];
        valueBytes[1] = buffer[1];
        valueBytes[2] = buffer[2];
        valueBytes[3] = buffer[3];
        buffer += 4;
        length -= 4;
        SBServerSetICMPIP(server, ipAddress);
    }
    if ((flags & 0x40) != 0) {
        keyCount = DarrayGetCount(serverList->mKeyList);
        keyIndex = 0;
        if (keyCount > 0) {
            do {
                keyInfo = DarrayGetElement(serverList->mKeyList, keyIndex);
                switch (keyInfo->mKeyType) {
                    case 1:
                        SbServerSetInt(server, keyInfo->mKeyName, buffer[0]);
                        buffer += 1;
                        length -= 1;
                        break;
                    case 2:
                        valueBytes = (u8 *) &shortValue;
                        valueBytes[0] = buffer[0];
                        valueBytes[1] = buffer[1];
                        SbServerSetInt(server, keyInfo->mKeyName,
                                       (u16) ((shortValue >> 8 & 0xff) | (shortValue << 8 & 0xff00)));
                        buffer += 2;
                        length -= 2;
                        break;
                    case 0:
                        if (popularOnly != 0) {
                            stringValue = buffer[0];
                            buffer += 1;
                            length -= 1;
                        } else {
                            stringValue = 0xff;
                        }
                        if (stringValue == 0xff) {
                            SbServerSetValue(server, keyInfo->mKeyName, (const char *) buffer);
                            stringValue = strlen((const char *) buffer) + 1;
                            buffer += stringValue;
                            length -= stringValue;
                        } else {
                            SbServerSetValue(server, keyInfo->mKeyName,
                                             serverList->mPopularValues[stringValue]);
                        }
                        break;
                }
                keyIndex++;
            } while (keyIndex < keyCount);
        }
        SBServerSetState(server, SBServerGetState(server) | 1);
    }
    flags = flags & 0x80;
    if (flags != 0) {
        while ((s8) buffer[0] != 0 && length > 0) {
            ruleKey = buffer;
            stringValue = strlen((const char *) buffer) + 1;
            buffer += stringValue;
            length -= stringValue;
            SbServerSetValue(server, (const char *) ruleKey, (const char *) buffer);
            stringValue = strlen((const char *) buffer) + 1;
            buffer += stringValue;
            length -= stringValue;
        }
        length -= 1;
        SBServerSetState(server, SBServerGetState(server) | 2);
    }
    return startLength - length;
}

s32 IncomingListParseServer(SbServerList *serverList, u8 *buffer, s32 length) {
    s32 entrySize;
    s32 flags;
    void *parsedServer;
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
    if ((flags & 0x40) != 0) {
        if (AllKeysPresent(serverList, buffer + entrySize, length - entrySize) == FALSE) {
            return 0;
        }
    }
    flags = flags & 0x80;
    if (flags != 0) {
        if (FullRulesPresent(buffer + entrySize, length - entrySize) == FALSE) {
            return 0;
        }
    }
    if (memcmp(buffer + 1, gLastServerMarker, 4) == 0) {
        return -1;
    }
    ParseServerIPPort(serverList, buffer, length, (u8 *) &ipAddress, &netPort);
    parsedServer = SBAllocServer(serverList, ipAddress, netPort);
    if (SBIsNullServer(parsedServer) != 0) {
        return -2;
    }
    parsedLength = ParseServer(serverList, parsedServer, buffer, length, 1);
    SBServerListAppendServer(serverList, (u32) parsedServer);
    return parsedLength;
}

void SBSetLastListErrorPtr(SbServerList *serverList, char *errorText) {
    serverList->mLastError = errorText;
}

s32 ProcessMainListData(SbServerList *serverList) {
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
        case 0:
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
            serverList->mParseState = 1;
            data += headerEnd;
            length -= headerEnd;
            GOADecrypt(serverList->mCryptKey, data, length);
        case 1:
            if (length < 6) {
                break;
            }
            fieldBytes = (u8 *) &serverList->mMyPublicIp;
            fieldBytes[0] = data[0];
            fieldBytes[1] = data[1];
            fieldBytes[2] = data[2];
            fieldBytes[3] = data[3];
            serverList->mCallback(serverList, 6, gSBNullServer, serverList->mInstance);
            fieldBytes = (u8 *) &serverList->mDefaultPort;
            portBytes = data + 4;
            fieldBytes[0] = portBytes[0];
            fieldBytes[1] = portBytes[1];
            if (serverList->mDefaultPort == 0xffff) {
                if (NTSLengthSB(data + 6, length - 6) == -1) {
                    break;
                }
                SBSetLastListErrorPtr(serverList, (char *) (data + 6));
                serverList->mCallback(serverList, 5, gSBNullServer, serverList->mInstance);
                if (serverList->mInBuffer == NULL) {
                    break;
                }
            }
            data += 6;
            length -= 6;
            if ((serverList->mQueryOptions & 2) != 0 || serverList->mDefaultPort == 0xffff) {
                serverList->mParseState = 5;
                serverList->mState = 2;
                break;
            }
            serverList->mParseState = 2;
            serverList->mExpectedElements = -1;
        case 2:
            if (serverList->mExpectedElements == -1) {
                if (length < 1) {
                    break;
                }
                serverList->mExpectedElements = data[0];
                serverList->mKeyList = DarrayCreate(8, serverList->mExpectedElements, NULL);
                if (serverList->mKeyList == NULL) {
                    return 5;
                }
                data += 1;
                length -= 1;
            }
            while (serverList->mExpectedElements > DarrayGetCount(serverList->mKeyList)) {
                if (length < 2) {
                    break;
                }
                consumed = NTSLengthSB(data + 1, length - 1);
                if (consumed == -1) {
                    break;
                }
                keyInfo.mKeyType = data[0];
                keyInfo.mKeyName = SBRefStr(serverList, (const char *) (data + 1));
                DarrayAppend(serverList->mKeyList, &keyInfo);
                consumed += 1;
                data += consumed;
                length -= consumed;
            }
            if (serverList->mExpectedElements > DarrayGetCount(serverList->mKeyList)) {
                break;
            }
            serverList->mParseState = 3;
            serverList->mExpectedElements = -1;
        case 3:
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
            serverList->mParseState = 4;
        case 4:
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
                    serverList->mParseState = 5;
                    serverList->mState = 2;
                    serverList->mCallback(serverList, 3, gSBNullServer, serverList->mInstance);
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
        AssertionFailed(gInLengthAssertText, gSBServerListFileName, NULL, 0x4af);
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

s32 ProcessPushKeyList(SbServerList *serverList, u8 *buffer, s32 length) {
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
    serverList->mKeyList = DarrayCreate(8, keyCount, NULL);
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
            DarrayAppend(serverList->mKeyList, &keyInfo);
            nameLength += 1;
            buffer += nameLength;
            length -= nameLength;
            keyIndex++;
        } while (keyIndex < keyCount);
    }
    return 0;
}

s32 ProcessPlayerSearch(SbServerList *serverList, u8 *buffer, s32 length) {
    s32 isLastPage;
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
    isLastPage = buffer[0];
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
    if (isLastPage != 0) {
        serverList->mPlayerSearchCallback(serverList, 0, 0, 0, 0, 0, serverList->mInstance);
    }
    return 0;
}

s32 ProcessMaploop(SbServerList *serverList, u8 *buffer, s32 length) {
    u32 rotationTime;
    u32 ipAddress;
    u16 netPort;
    u32 foundServer;
    s32 nameCount;
    s32 i;
    s32 mapIndex;
    u8 *mapNames[16];
    u8 *source;
    u8 *destination;
    u8 *l;
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
    i = SBServerListFindServerByIP(serverList, ipAddress, netPort);
    if (i == -1) {
        return 0;
    }
    foundServer = SBServerListNth(serverList, i);
    destination = (u8 *) &rotationTime;
    source = buffer + 6;
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
    rotationTime = (rotationTime << 24 & 0xff000000) |
                 ((rotationTime << 8 & 0xff0000) | ((rotationTime >> 24 & 0xff) | (rotationTime >> 8 & 0xff00)));
    nameCount = buffer[10];
    buffer += 11;
    length -= 11;
    for (mapIndex = 0; mapIndex < nameCount && mapIndex < 16;) {
        if (length < 1) {
            break;
        }
        i = NTSLengthSB(buffer, length);
        if (i == -1) {
            return 4;
        }
        mapNames[mapIndex] = buffer;
        buffer += i;
        length -= i;
        mapIndex++;
    }
    if (serverList->mMaploopCallback == NULL) {
        return 0;
    }
    serverList->mMaploopCallback(serverList, foundServer, rotationTime, mapIndex, mapNames, serverList->mInstance);
    return 0;
}

s32 ProcessDeleteServer(SbServerList *serverList, u8 *buffer, s32 length) {
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

s32 ProcessPushServer(SbServerList *serverList, u8 *buffer, s32 length) {
    s32 serverIndex;
    void *pushedServer;
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
        pushedServer = (void *) SBServerListNth(serverList, serverIndex);
    }
    if (ParseServer(serverList, pushedServer, buffer, length, 0) < 0) {
        return 4;
    }
    if (serverIndex == -1) {
        SBServerListAppendServer(serverList, (u32) pushedServer);
    }
    serverList->mCallback(serverList, 1, pushedServer, serverList->mInstance);
    return 0;
}

s32 ProcessAdHocData(SbServerList *slist) {
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
            case 1:
                error = ProcessPushKeyList(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
            case 2:
                error = ProcessPushServer(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
            case 3:
                if (send(slist->mSocket, slist->mInBuffer, messageLength, 0) <= 0) {
                    return 3;
                }
                break;
            case 4:
                error = ProcessDeleteServer(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
            case 5:
                error = ProcessMaploop(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
            case 6:
                error = ProcessPlayerSearch(slist, slist->mInBuffer + 3, messageLength - 3);
                break;
        }
        slist->mInBufferLength -= messageLength;
        if (slist->mInBufferLength < 0) {
            AssertionFailed(gInBufferLengthAssertText, gSBServerListFileName, NULL, 0x5b4);
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

s32 ProcessIncomingData(SbServerList *serverList) {
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
    if (serverList->mState == 2 || serverList->mParseState > 0) {
        GOADecrypt(serverList->mCryptKey, serverList->mInBuffer + oldLength, serverList->mInBufferLength - oldLength);
    }
    if (serverList->mState == 3) {
        error = ProcessMainListData(serverList);
    }
    if (error != 0) {
        return error;
    }
    if (serverList->mState == 2 && serverList->mInBufferLength > 0) {
        return ProcessAdHocData(serverList);
    }
    return 0;
}

s32 SBSendMessageToServer(SbServerList *serverList, u32 publicIp, u16 port, u8 *data, s32 dataLength) {
    SendMessageRequest request;
    u16 messageLength;
    u8 *destination;
    u8 *source;
    s32 error;
    if (serverList->mState == 1) {
        SBServerListConnectAndQuery(serverList, NULL, NULL, 2, 0);
    }
    if (serverList->mState == 1) {
        return 3;
    }
    messageLength = dataLength + 9;
    request.mNetLength = (messageLength >> 8 & 0xff) | (messageLength << 8 & 0xff00);
    destination = request.mRequestLength;
    source = (u8 *) &request.mNetLength;
    destination[0] = source[0];
    destination[1] = source[1];
    request.mRequestType = 2;
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

s32 SBSendNatNegotiateCookieToServer(SbServerList *serverList, u32 publicIp, u16 port, u32 cookie) {
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

s32 ProcessLanData(SbServerList *serverList) {
    SocketAddress sender;
    s32 senderLength;
    u8 datagram[0x5e0];
    void *lanServer;
    senderLength = 8;
    while (CanReceiveOnSocket(serverList->mSocket) != 0) {
        if (recvfrom(serverList->mSocket, datagram, 0x5db, 0, &sender, &senderLength) != -1) {
            if (SBServerListFindServerByIP(serverList, sender.mAddress, sender.mPort) == -1) {
                lanServer = SBAllocServer(serverList, sender.mAddress, sender.mPort);
                if (SBIsNullServer(lanServer) != 0) {
                    return 5;
                }
                SBServerSetFlags(lanServer, 0x11);
                SBServerListAppendServer(serverList, (u32) lanServer);
            }
        }
    }
    if (GetElapsedMilliseconds() - serverList->mLanStartTime > 0x7d0) {
        closesocket(serverList->mSocket);
        serverList->mSocket = -1;
        serverList->mState = 1;
        serverList->mCallback(serverList, 3, gSBNullServer, serverList->mInstance);
    }
    return 0;
}

s32 SBListThink(SbServerList *serverList) {
    SBFreeDeadList(serverList);
    switch (serverList->mState) {
        case 2:
        case 3:
            return ProcessIncomingData(serverList);
        case 0:
            return ProcessLanData(serverList);
        case 1:
        default:
            return 0;
    }
}

void ListCallback(SbServerList *browserList, s32 reason, SbServer *server, MatchingServerList *matchingServerList) {
    switch (reason) {
        case 0:
            matchingServerList->mBrowserCallback(matchingServerList, 0, server, matchingServerList->mBrowserInstance);
            if (((server->mStateFlags & 3) == 0 || (server->mStateFlags & 0x40) == 0) &&
                (server->mStateFlags & 0x2c) == 0 && matchingServerList->mDontUpdate == 0) {
                s32 queryType;
                if (server->mFlags & 1) {
                    if (matchingServerList->mList.mState == 0 || matchingServerList->mEngine.mNumServerKeys == 0) {
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
        listLength += sprintf(keyNames + listLength, gKeyListEntryFormat, keyName);
        SBQueryEngineAddQueryKey(&matchingServerList->mEngine, basicFields[fieldIndex]);
    }
    error = SBServerListConnectAndQuery(&matchingServerList->mList, keyNames, serverFilter, updateOptions, maxServers);
    if (error == 0 && async == 0) {
        listLength = 10;
        while (matchingServerList->mList.mState == 3 ||
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

s32 ServerBrowserSendNatNegotiateCookieToServerA(MatchingServerList *matchingServerList, u32 ipText, s32 port, u32 cookie) {
    u32 publicIp = inet_addr(ipText);
    return SBSendNatNegotiateCookieToServer(&matchingServerList->mList, publicIp,
                                            ((port >> 8) & 0xff) | ((port << 8) & 0xff00), cookie);
}

void ServerBrowserRemoveServer(struct MatchingServerList *matchingServerList, s32 server) {
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

u32 ServerBrowserGetServer(MatchingServerList *matchingServerList, u32 index) {
    u32 spareValue = (u32) matchingServerList;
    u32 indexCopy = index;
    u32 calleeAddress;
    spareValue = (spareValue) + 76u;
    calleeAddress = (u32) &SBServerListNth;
    spareValue = SBServerListNth((SbServerList *) spareValue, indexCopy);
    return spareValue;
}

u32 ServerBrowserCount(MatchingServerList *matchingServerList) {
    u32 spareValue = (u32) matchingServerList;
    u32 calleeAddress;
    spareValue = (spareValue) + 76u;
    calleeAddress = (u32) &SBServerListCount;
    spareValue = SBServerListCount((SbServerList *) spareValue);
    return spareValue;
}

void ServerBrowserSortA(MatchingServerList *matchingServerList, u32 ascending, const char *sortField, u32 compareKind) {
    SBServerListSort(&matchingServerList->mList, ascending, sortField, compareKind);
}

u32 ServerBrowserGetMyPublicIPAddr(MatchingServerList *matchingServerList) {
    return matchingServerList->mList.mMyPublicIp;
}

u32 RefStringHash(HashtableNameEntry *entry, u32 modulus) {
    return ServerStringHash(entry->mName, modulus);
}

s32 RefStringCompare(const char *const *first, const char *const *second) {
    return CompareStringsMapped(*first, *second);
}

void RefStringFree(u32 element) {
    u32 stringPointer = element;
    u32 value3;
    stringPointer = *(const u32 *) ((stringPointer) + 0u);
    DWCi_GsFree((void *) stringPointer);
}

struct Hashtable *SBRefStrHash(struct SbServerList *serverList) {
    if (gSBRefStrList == NULL) {
        gSBRefStrList = HashtableCreate(8, 100, 2, (s32(*)(void *, s32)) RefStringHash,
                                        (s32(*)(void *, void *)) RefStringCompare, (void (*)(void *)) RefStringFree);
    }
    return gSBRefStrList;
}

void SBRefStrHashCleanup(void *serverList) {
    int count;
    if ((gSBRefStrList != NULL) && (count = HashtableGetCount(gSBRefStrList), count == 0)) {
        HashtableDelete(gSBRefStrList);
        *(s32 *) &gSBRefStrList = 0;
    }
}

void SBServerFree(int *serverPointer) {
    int serverRecord;
    serverRecord = *serverPointer;
    HashtableDelete((s32 *) (*(u32 *) (serverRecord + 0x18)));
    *(u32 *) (serverRecord + 0x18) = 0;
    DWCi_GsFree((void *) serverRecord);
}

void SbServerSetValue(SbServer *server, const char *key, const char *value) {
    char *pair[2];
    pair[0] = SBRefStr(NULL, key);
    pair[1] = SBRefStr(NULL, value);
    HashtableSet(server->mKeyValues, pair);
}

void SbServerSetInt(SbServer *server, const char *key, u32 value) {
    char valueText[20];
    sprintf(valueText, gIntValueFormat, value);
    SbServerSetValue(server, key, valueText);
}

char *SbServerGetValue(SbServer *server, const char *key, char *defaultValue) {
    KeyLookup probe;
    u32 *entry;
    if (server == NULL) {
        AssertionFailed(gServerAssertText, gSBServerFileName, NULL, 0x97);
    }
    if (server == NULL) {
        return NULL;
    }
    probe.mKey = key;
    entry = HashtableFind(server->mKeyValues, &probe);
    if (entry != NULL) {
        defaultValue = (char *) entry[1];
    }
    return defaultValue;
}

s32 SbServerGetInt(SbServer *server, const char *key, s32 defaultValue) {
    char *text;
    s32 firstChar;
    if (strcmp(key, gPingKey) == 0) {
        return SBServerGetPing(server);
    }
    text = SbServerGetValue(server, key, NULL);
    if (text == NULL ||
        (firstChar = *text, !((firstChar < 0 || firstChar >= 0x80) ? 0 : (gCharClassFlags[firstChar] & 8)))) {
        return defaultValue;
    }
    return StrtolBase10(text);
}

double SbServerGetDouble(SbServer *server, const char *key, double defaultValue) {
    char *text;
    text = SbServerGetValue(server, key, NULL);
    if (text != NULL) {
        defaultValue = atof(text);
    }
    return defaultValue;
}

u32 SBServerGetPublicInetAddress(u32 *server) {
    return *server;
}

u32 SBServerGetPublicQueryPort(u32 server) {
    u32 value0 = server;
    u32 port;
    u32 swappedPort;
    port = *(const u16 *) ((value0) + 4u);
    swappedPort = ((s32) port >> 8);
    value0 = 255u;
    swappedPort = (swappedPort) & (value0);
    port = (port << 8);
    value0 = 0xff00u;
    port = (port) & (value0);
    swappedPort = (swappedPort) | (port);
    value0 = (swappedPort << 16);
    value0 = (value0 >> 16);
    return value0;
}

u16 SBServerGetPublicQueryPortNBO(int server) {
    return *(u16 *) (server + 4);
}

BOOL SBServerHasPrivateAddress(int server) {
    if ((*(u8 *) (server + 0x15) & 2) == 2) {
        return 1;
    }
    return 0;
}

u32 SBServerGetPrivateInetAddress(int server) {
    return *(u32 *) (server + 8);
}

u32 SBServerGetPrivateQueryPort(u32 server) {
    u32 value0 = server;
    u32 port;
    u32 swappedPort;
    port = *(const u16 *) ((value0) + 12u);
    swappedPort = ((s32) port >> 8);
    value0 = 255u;
    swappedPort = (swappedPort) & (value0);
    port = (port << 8);
    value0 = 0xff00u;
    port = (port) & (value0);
    swappedPort = (swappedPort) | (port);
    value0 = (swappedPort << 16);
    value0 = (value0 >> 16);
    return value0;
}

void SBServerSetNext(int server, u32 next) {
    *(u32 *) (server + 0x20) = next;
}

u32 SBServerGetNext(int server) {
    return *(u32 *) (server + 0x20);
}

BOOL CheckValidKey(const char *key) {
    InvalidKeyNames invalidKeys;
    u32 index;
    const char **invalidName;
    invalidKeys = gInvalidKeys;
    invalidName = invalidKeys.mNames;
    for (index = 0; index < 2; index++) {
        if (strcmp(key, *invalidName) == 0) {
            return 0;
        }
        invalidName++;
    }
    return 1;
}

s8 *mytok(s8 *text, s32 delimiter) {
    s8 *tokenStart;
    s8 *cursor;
    s32 character;
    if (text != NULL) {
        gMytokPosition = text;
    }
    tokenStart = gMytokPosition;
    while ((character = *(cursor = gMytokPosition)) != 0 && character != delimiter) {
        gMytokPosition++;
    }
    if (cursor == tokenStart) {
        tokenStart = NULL;
    }
    if (character != 0) {
        gMytokPosition++;
        *cursor = 0;
    }
    return tokenStart;
}

void SBServerParseKeyVals(SbServer *server, s8 *keyValues) {
    s8 *key;
    s8 *value;
    key = mytok(keyValues + 1, 0x5c);
    while (key != NULL) {
        value = mytok(NULL, 0x5c);
        if (value == NULL) {
            value = data_ov000_021b21c4;
        }
        if (CheckValidKey((const char *) key) != 0) {
            SbServerSetValue(server, (const char *) key, (const char *) value);
        }
        key = mytok(NULL, 0x5c);
    }
}

void SBServerParseQR2FullKeysSingle(SbServer *server, s8 *data, s32 length) {
    FullKeysScratch scratch;
    s8 *keyNames;
    s8 *key;
    s8 *value;
    s32 keyCount;
    s32 groupIndex;
    s32 unitIndex;
    s32 keyIndex;
    s32 valueLength;
    s32 stringLength;
    u16 unitCount;
    while (*data != 0) {
        stringLength = NTSLengthSB(data, length);
        if (stringLength < 0) {
            return;
        }
        key = data;
        data += stringLength;
        length -= stringLength;
        stringLength = NTSLengthSB(data, length);
        if (stringLength < 0) {
            return;
        }
        value = data;
        data += stringLength;
        length -= stringLength;
        SbServerSetValue(server, (const char *) key, (const char *) value);
    }
    data++;
    length--;
    for (groupIndex = 0; groupIndex < 2; groupIndex++) {
        if (length < 2) {
            return;
        }
        __memcpy(scratch.mUnitCount, data, 2);
        unitCount = *(u16 *) scratch.mUnitCount;
        *(u16 *) scratch.mUnitCount = ((unitCount >> 8) & 0xff) | ((unitCount << 8) & 0xff00);
        data += 2;
        length -= 2;
        keyNames = data;
        keyCount = 0;
        while (*data != 0) {
            stringLength = NTSLengthSB(data, length);
            if (stringLength < 0 || stringLength > 100) {
                return;
            }
            keyCount++;
            data += stringLength;
            length -= stringLength;
        }
        data++;
        length--;
        unitIndex = 0;
        while (unitIndex < *(u16 *) scratch.mUnitCount) {
            key = keyNames;
            keyIndex = 0;
            while (keyIndex < keyCount) {
                valueLength = NTSLengthSB(data, length);
                if (valueLength < 0) {
                    return;
                }
                sprintf(scratch.mTempKey, gKeyIndexFormat, key, unitIndex);
                SbServerSetValue(server, scratch.mTempKey, (const char *) data);
                data += valueLength;
                length -= valueLength;
                key += strlen((const char *) key) + 1;
                keyIndex++;
            }
            unitIndex++;
        }
    }
}

u32 ServerStringHash(const s8 *text, u32 modulus) {
    s32 character;
    u32 hash;
    hash = 0;
    character = *text;
    while (character != 0) {
        if (character >= 0 && character < 0x80) {
            character = gLowerCaseMap[character];
        }
        hash *= 0x9ccf9319;
        hash += character;
        text++;
        character = *text;
    }
    return hash % modulus;
}

void KeyValFree(u32 *pair) {
    SBReleaseStr(0, *pair);
    SBReleaseStr(0, pair[1]);
}

u32 KeyValHashKey(HashtableNameEntry *entry, u32 modulus) {
    return ServerStringHash(entry->mName, modulus);
}

s32 KeyValCompareKey(const char *const *first, const char *const *second) {
    return CompareStringsMapped(*first, *second);
}

u32 SBServerGetPing(SbServer *server) {
    return server->mPing;
}

SbServer *SBAllocServer(SbServerList *serverList, u32 outerAddress, u16 outerPort) {
    SbServer *newServer;
    newServer = DWCi_GsMalloc(0x24);
    if (newServer == NULL) {
        return NULL;
    }
    newServer->mKeyValues = HashtableCreate(8, 8, 4, (s32(*)(void *, s32)) KeyValHashKey,
                                         (s32(*)(void *, void *)) KeyValCompareKey, (void (*)(void *)) KeyValFree);
    if (newServer->mKeyValues == NULL) {
        DWCi_GsFree(newServer);
        return NULL;
    }
    newServer->mStateFlags = 0;
    newServer->mFlags = 0;
    newServer->mNext = NULL;
    newServer->mPing = 0;
    newServer->mIcmpIp = 0;
    newServer->mPublicIp = outerAddress;
    newServer->mPublicPort = outerPort;
    newServer->mPrivateIp = 0;
    newServer->mPrivatePort = 0;
    return newServer;
}

void SBServerSetFlags(SbServer *server, s32 flags) {
    server->mFlags = flags;
}

void SBServerSetPrivateAddr(SbServer *server, u32 innerAddress, u16 innerPort) {
    server->mPrivateIp = innerAddress;
    server->mPrivatePort = innerPort;
}

void SBServerSetICMPIP(SbServer *server, u32 targetAddr) {
    server->mIcmpIp = targetAddr;
}

void SBServerSetState(SbServer *server, u8 state) {
    server->mStateFlags = state;
}

u8 SBServerGetState(SbServer *server) {
    return server->mStateFlags;
}

BOOL SBIsNullServer(SbServer *server) {
    if (server == gSBNullServer) {
        return 1;
    }
    return 0;
}

void FIFOAddRear(SBServerFIFO *fifo, SbServer *server) {
    if (fifo->mLast != NULL) {
        fifo->mLast->mNext = server;
    }
    fifo->mLast = server;
    server->mNext = NULL;
    if (fifo->mFirst == NULL) {
        fifo->mFirst = server;
    }
    fifo->mCount = fifo->mCount + 1;
}

void FIFOAddFront(SBServerFIFO *fifo, SbServer *server) {
    server->mNext = fifo->mFirst;
    fifo->mFirst = server;
    if (fifo->mLast == NULL) {
        fifo->mLast = server;
    }
    fifo->mCount = fifo->mCount + 1;
}

SbServer *FIFOGetFirst(SBServerFIFO *fifo) {
    SbServer *server;
    server = fifo->mFirst;
    if (server != NULL) {
        fifo->mFirst = server->mNext;
        if (fifo->mFirst == NULL) {
            fifo->mLast = NULL;
        }
        fifo->mCount = fifo->mCount + -1;
    }
    return server;
}
