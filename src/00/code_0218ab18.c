#include "00/code_0218ab18.h"
#include "00/code_0218a9bc.h"
#include "00/code_0218acf4.h"
#include "00/code_0218ae68.h"
#include "00/code_0218aea4.h"
#include "00/code_021a4b84.h"
#include "code_02139f70.h"
#include "00/code_0218e2dc.h"

void SBQueryEngineUpdateServer(SBQueryEngine *engine, SbServer *server, s32 atFront, s32 updateKind) {
    u8 *statePtr;
    statePtr = &server->mUnk_14;
    server->mUnk_14 &= 0xc3;
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
        func_ov000_0218aec4(&engine->mPendingList, server);
    } else {
        func_ov000_0218aedc(&engine->mPendingList, server);
    }
}

void ParseSingleQR2Reply(SBQueryEngine *engine, SbServer *server, s8 *data, s32 length) {
    s32 keyIndex;
    s32 valueLength;
    if (data[0] == 0) {
        data += 5;
        length -= 5;
        if ((server->mUnk_14 & 4) != 0) {
            keyIndex = 0;
            if (engine->mNumServerKeys > 0) {
                do {
                    valueLength = func_ov000_0218d0c8(data, length);
                    if (valueLength < 0) {
                        break;
                    }
                    SbServerSetValue(server, gQr2RegisteredKeyList[engine->mServerKeys[keyIndex]], (const char *) data);
                    data += valueLength;
                    length -= valueLength;
                    keyIndex++;
                } while (keyIndex < engine->mNumServerKeys);
            }
            server->mUnk_14 |= 0x41;
        } else {
            func_ov000_0218b010(server, data, length);
            server->mUnk_14 |= 0x43;
        }
        server->mUnk_14 &= 0xf3;
        server->mPing = func_ov000_0218e8c4() - server->mPing;
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
    func_ov000_0218b148(server, data);
    if (isFinal != FALSE) {
        if ((server->mUnk_14 & 4) != 0) {
            server->mUnk_14 |= 0x41;
        } else {
            server->mUnk_14 |= 0x42;
        }
        server->mUnk_14 &= 0xf3;
        server->mPing = func_ov000_0218e8c4() - server->mPing;
        FIFORemove(&engine->mQueryList, server);
        engine->mListCallback(engine, 0, server, engine->mInstance);
    }
}
