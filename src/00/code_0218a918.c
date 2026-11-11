#include "00/code_0218a918.h"
#include "00/code_0218a000.h"
#include "00/code_0218a9bc.h"
#include "00/code_0218acf4.h"
#include "00/code_0218aea4.h"
#include "00/code_0218ae68.h"

void QueueNextQueries(SBQueryEngine *engine) {
    SbServer *pendingServer;
    while ((engine->mQueryList.mCount < engine->mMaxUpdates && (0 < engine->mPendingList.mCount))) {
        pendingServer = func_ov000_0218aea4(&engine->mPendingList);
        QEStartQuery(engine, pendingServer);
    }
}

void SBQueryEngineThink(MatchingServerList *matchingServerList) {
    if (matchingServerList->mUnk_000.mQueryList.mCount != 0) {
        ProcessIncomingReplies(&matchingServerList->mUnk_000, 0);
        TimeoutOldQueries(&matchingServerList->mUnk_000);
        if (0 < matchingServerList->mUnk_000.mPendingList.mCount) {
            QueueNextQueries(&matchingServerList->mUnk_000);
        }
        if (matchingServerList->mUnk_000.mQueryList.mCount == 0) {
            matchingServerList->mUnk_000.mListCallback(matchingServerList, 2, 0,
                                                       matchingServerList->mUnk_000.mInstance);
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
    removed = FIFORemove(&matchingServerList->mUnk_000.mQueryList, server);
    if (removed == 0) {
        FIFORemove(&matchingServerList->mUnk_000.mPendingList, server);
    }
}
