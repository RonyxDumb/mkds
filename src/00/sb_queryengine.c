#include "00/sb_queryengine.h"
#include "00/code_0218aea4.h"
#include "00/code_0218e2dc.h"
#include "03/code_021bb03c.h"
#include "00/unk_021b4000.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_021a4b84.h"
#include "code_02139f70.h"
#include "00/code_021a3a18.h"

BOOL FIFORemove(SBServerFIFO *fifo, SbServer *server) {
    SbServer *current;
    SbServer *previous;
    previous = NULL;
    current = fifo->mFirst;
    while (current != NULL) {
        if (current == server) {
            if (previous != NULL) {
                previous->mNext = current->mNext;
            }
            if (fifo->mFirst == current) {
                fifo->mFirst = current->mNext;
            }
            if (fifo->mLast == current) {
                fifo->mLast = previous;
            }
            fifo->mCount--;
            return 1;
        }
        previous = current;
        current = current->mNext;
    }
    return 0;
}

void FIFOClear(SBServerFIFO *fifo) {
    fifo->mLast = NULL;
    fifo->mFirst = fifo->mLast;
    fifo->mCount = 0;
}

void QEStartQuery(SBQueryEngine *engine, SbServer *server) {
    SocketAddress address;
    u8 query[0x100];
    s32 queryLength;
    s32 i;
    FIFOAddRear(&engine->mQueryList, server);
    server->mPing = GetElapsedMilliseconds();
    address.mFamily = 2;
    if ((server->mStateFlags & 0x20) == 0) {
        if (engine->mQueryVersion == 1) {
            query[0] = 0xfe;
            query[1] = 0xfd;
            query[2] = 0;
            __memcpy(&query[3], &server->mPing, 4);
            if ((server->mStateFlags & 4) != 0) {
                query[7] = engine->mNumServerKeys;
                for (i = 0; i < engine->mNumServerKeys; i++) {
                    query[i + 8] = engine->mServerKeys[i];
                }
                query[engine->mNumServerKeys + 8] = 0;
                query[engine->mNumServerKeys + 9] = 0;
                queryLength = engine->mNumServerKeys + 10;
            } else {
                query[7] = 0xff;
                query[8] = 0xff;
                query[9] = 0xff;
                queryLength = 10;
            }
        } else if ((server->mStateFlags & 4) != 0) {
            __memcpy(query, &gBasicGoaQuery, 13);
            queryLength = 13;
        } else {
            __memcpy(query, &gFullGoaQuery, 8);
            queryLength = 8;
        }
        if (server->mPublicIp == engine->mMyPublicIp && (server->mFlags & 2) != 0) {
            address.mAddress = server->mPrivateIp;
            address.mPort = server->mPrivatePort;
        } else {
            address.mAddress = server->mPublicIp;
            address.mPort = server->mPublicPort;
        }
        sendto(engine->mQuerySock, query, queryLength, 0, &address, 8);
    }
}

void SBQueryEngineInit(SBQueryEngine *engine, s32 updateLimit, u32 queryVersion, s32 lanBrowse, UnkFunc *callback,
                       void *instance) {
    if (lanBrowse == 0 && gGsiAcResult != 1) {
        return;
    }
    SocketStartUp();
    engine->mQueryVersion = queryVersion;
    engine->mMaxUpdates = updateLimit;
    engine->mNumServerKeys = 0;
    engine->mListCallback = callback;
    engine->mInstance = instance;
    engine->mMyPublicIp = 0;
    engine->mQuerySock = OpenNetSocket(2, 2, 0);
    FIFOClear(&engine->mPendingList);
    FIFOClear(&engine->mQueryList);
}

void SBQueryEngineSetPublicIP(MatchingServerList *matchingServerList, u32 publicIp) {
    matchingServerList->mEngine.mMyPublicIp = publicIp;
}

void SBEngineHaltUpdates(MatchingServerList *matchingServerList) {
    FIFOClear(&matchingServerList->mEngine.mPendingList);
    FIFOClear(&matchingServerList->mEngine.mQueryList);
}

void SBEngineCleanup(MatchingServerList *matchingServerList) {
    closesocket(matchingServerList->mEngine.mQuerySock);
    matchingServerList->mEngine.mQuerySock = 0xffffffff;
    FIFOClear(&matchingServerList->mEngine.mPendingList);
    FIFOClear(&matchingServerList->mEngine.mQueryList);
}

void SBQueryEngineUpdateServer(SBQueryEngine *engine, SbServer *server, s32 atFront, s32 updateKind) {
    u8 *statePtr;
    statePtr = &server->mStateFlags;
    server->mStateFlags &= 0xc3;
    if (updateKind == 0) {
        *statePtr |= 4;
    } else if (updateKind == 1) {
        *statePtr |= 8;
    } else if (updateKind == 2) {
        return;
    }
    if (engine->mQueryList.mCount < engine->mMaxUpdates) {
        QEStartQuery(engine, server);
        return;
    }
    if (atFront != 0) {
        FIFOAddFront(&engine->mPendingList, server);
    } else {
        FIFOAddRear(&engine->mPendingList, server);
    }
}

void ParseSingleQR2Reply(SBQueryEngine *engine, SbServer *server, s8 *data, s32 length) {
    s32 keyIndex;
    s32 valueLength;
    if (data[0] == 0) {
        data += 5;
        length -= 5;
        if ((server->mStateFlags & 4) != 0) {
            keyIndex = 0;
            if (engine->mNumServerKeys > 0) {
                do {
                    valueLength = NTSLengthSB(data, length);
                    if (valueLength < 0) {
                        break;
                    }
                    SbServerSetValue(server, gQr2RegisteredKeyList[engine->mServerKeys[keyIndex]], (const char *) data);
                    data += valueLength;
                    length -= valueLength;
                    keyIndex++;
                } while (keyIndex < engine->mNumServerKeys);
            }
            server->mStateFlags |= 0x41;
        } else {
            SBServerParseQR2FullKeysSingle(server, data, length);
            server->mStateFlags |= 0x43;
        }
        server->mStateFlags &= 0xf3;
        server->mPing = GetElapsedMilliseconds() - server->mPing;
        FIFORemove(&engine->mQueryList, server);
        engine->mListCallback(engine, 0, server, engine->mInstance);
    }
}

void ParseSingleGOAReply(SBQueryEngine *engine, SbServer *server, s8 *data, s32 length) {
    BOOL isFinal;
    if (strstr((const char *) data, gGoaFinalMarker) != NULL) {
        isFinal = TRUE;
    } else {
        isFinal = FALSE;
    }
    SBServerParseKeyVals(server, data);
    if (isFinal != FALSE) {
        if ((server->mStateFlags & 4) != 0) {
            server->mStateFlags |= 0x41;
        } else {
            server->mStateFlags |= 0x42;
        }
        server->mStateFlags &= 0xf3;
        server->mPing = GetElapsedMilliseconds() - server->mPing;
        FIFORemove(&engine->mQueryList, server);
        engine->mListCallback(engine, 0, server, engine->mInstance);
    }
}

BOOL ParseSingleICMPReply(SBQueryEngine *engine, SbServer *server, s8 *data, s32 length) {
    return 1;
}

void ProcessIncomingReplies(SBQueryEngine *engine, s32 probeSocket) {
    s32 recvSocket;
    SocketAddress address;
    s32 addressLength;
    s32 length;
    SbServer *queryEntry;
    s8 data[0x800];
    addressLength = 8;
    if (probeSocket != 0) {
        recvSocket = engine->mIcmpSock;
    } else {
        recvSocket = engine->mQuerySock;
    }
    while (CanReceiveOnSocket(recvSocket) != 0) {
        length = recvfrom(recvSocket, data, 0x7ff, 0, &address, &addressLength);
        if (length == -1) {
            break;
        }
        data[length] = 0;
        for (queryEntry = engine->mQueryList.mFirst; queryEntry != NULL; queryEntry = queryEntry->mNext) {
            if ((probeSocket != 0 && (queryEntry->mFlags & 8) != 0 && queryEntry->mIcmpIp == address.mAddress) ||
                (queryEntry->mPublicIp == address.mAddress && (queryEntry->mPublicPort == address.mPort || probeSocket != 0)) ||
                (queryEntry->mPublicIp == engine->mMyPublicIp && (queryEntry->mFlags & 2) != 0 &&
                 queryEntry->mPrivateIp == address.mAddress && queryEntry->mPrivatePort == address.mPort)) {
                if (probeSocket != 0) {
                    if (ParseSingleICMPReply(engine, queryEntry, data, length) != 0) {
                        break;
                    }
                } else {
                    if (engine->mQueryVersion == 1) {
                        ParseSingleQR2Reply(engine, queryEntry, data, length);
                    } else {
                        ParseSingleGOAReply(engine, queryEntry, data, length);
                    }
                    break;
                }
            }
        }
    }
}

void TimeoutOldQueries(SBQueryEngine *engine) {
    u32 currentTime;
    SbServer *server;
    currentTime = GetElapsedMilliseconds();
    server = engine->mQueryList.mFirst;
    while (server != NULL) {
        if (currentTime <= server->mPing + 0x9c4) {
            break;
        }
        server->mFlags |= 0x10;
        engine->mQueryList.mFirst->mPing = 0x9c4;
        engine->mQueryList.mFirst->mFlags &= 0xd3;
        engine->mListCallback(engine, 1, engine->mQueryList.mFirst, engine->mInstance);
        FIFOGetFirst(&engine->mQueryList);
        server = engine->mQueryList.mFirst;
    }
}

void QueueNextQueries(SBQueryEngine *engine) {
    SbServer *pendingServer;
    while ((engine->mQueryList.mCount < engine->mMaxUpdates && (0 < engine->mPendingList.mCount))) {
        pendingServer = FIFOGetFirst(&engine->mPendingList);
        QEStartQuery(engine, pendingServer);
    }
}

void SBQueryEngineThink(MatchingServerList *matchingServerList) {
    if (matchingServerList->mEngine.mQueryList.mCount != 0) {
        ProcessIncomingReplies(&matchingServerList->mEngine, 0);
        TimeoutOldQueries(&matchingServerList->mEngine);
        if (0 < matchingServerList->mEngine.mPendingList.mCount) {
            QueueNextQueries(&matchingServerList->mEngine);
        }
        if (matchingServerList->mEngine.mQueryList.mCount == 0) {
            matchingServerList->mEngine.mListCallback(matchingServerList, 2, 0, matchingServerList->mEngine.mInstance);
        }
    }
}

void SBQueryEngineAddQueryKey(SBQueryEngine *engine, u8 keyId) {
    int keyCount;
    keyCount = engine->mNumServerKeys;
    if (keyCount < 0x14) {
        engine->mNumServerKeys = keyCount + 1;
        engine->mServerKeys[keyCount] = keyId;
    }
}

void SBQueryEngineRemoveServerFromFIFOs(MatchingServerList *matchingServerList, SbServer *server) {
    int removed;
    removed = FIFORemove(&matchingServerList->mEngine.mQueryList, server);
    if (removed == 0) {
        FIFORemove(&matchingServerList->mEngine.mPendingList, server);
    }
}
