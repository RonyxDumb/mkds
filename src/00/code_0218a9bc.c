#include "00/code_0218a9bc.h"
#include "00/code_0218ab14.h"
#include "00/code_0218ab18.h"
#include "00/code_0218aea4.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"

void ProcessIncomingReplies(SBQueryEngine *engine, s32 probeSocket) {
    s32 recvSocket;
    Unk0218aa14 address;
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
    while (func_ov000_0218e668(recvSocket) != 0) {
        length = func_ov000_0218e438(recvSocket, data, 0x7ff, 0, &address, &addressLength);
        if (length == -1) {
            break;
        }
        data[length] = 0;
        for (queryEntry = engine->mQueryList.mFirst; queryEntry != NULL; queryEntry = queryEntry->mUnk_20) {
            if ((probeSocket != 0 && (queryEntry->mUnk_15 & 8) != 0 && queryEntry->mUnk_10 == address.mUnk_04) ||
                (queryEntry->mUnk_00 == address.mUnk_04 && (queryEntry->mUnk_04 == address.mUnk_02 || probeSocket != 0)) ||
                (queryEntry->mUnk_00 == engine->mMyPublicIp && (queryEntry->mUnk_15 & 2) != 0 &&
                 queryEntry->mUnk_08 == address.mUnk_04 && queryEntry->mUnk_0c == address.mUnk_02)) {
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
    currentTime = func_ov000_0218e8c4();
    server = engine->mQueryList.mFirst;
    while (server != NULL) {
        if (currentTime <= server->mPing + 0x9c4) {
            break;
        }
        server->mUnk_15 |= 0x10;
        engine->mQueryList.mFirst->mPing = 0x9c4;
        engine->mQueryList.mFirst->mUnk_15 &= 0xd3;
        engine->mListCallback(engine, 1, engine->mQueryList.mFirst, engine->mInstance);
        func_ov000_0218aea4(&engine->mQueryList);
        server = engine->mQueryList.mFirst;
    }
}
