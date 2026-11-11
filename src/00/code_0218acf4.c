#include "00/code_0218acf4.h"
#include "00/code_0218a9bc.h"
#include "00/code_0218ae5c.h"
#include "00/code_0218aea4.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"

void QEStartQuery(SBQueryEngine *engine, SbServer *server) {
    Unk0218aa14 address;
    u8 query[0x100];
    s32 queryLength;
    s32 i;
    FIFOAddRear(&engine->mQueryList, server);
    server->mPing = GetElapsedMilliseconds();
    address.mUnk_01 = 2;
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
            address.mUnk_04 = server->mPrivateIp;
            address.mUnk_02 = server->mPrivatePort;
        } else {
            address.mUnk_04 = server->mPublicIp;
            address.mUnk_02 = server->mPublicPort;
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
