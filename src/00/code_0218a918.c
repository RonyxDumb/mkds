#include "00/code_0218a918.h"
#include "00/code_0218a000.h"
#include "00/code_0218a9bc.h"
#include "00/code_0218acf4.h"
#include "00/code_0218aea4.h"
#include "00/code_0218ae68.h"

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
