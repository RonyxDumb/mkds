#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/code_0210d000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0210e33c.h"
#include "code_0212d214.h"

void InitSoundHandlePool(SoundHandlePool *pool, void *entries, s32 count, s32 entrySize) {
    s32 handleIndex;
    u8 *entryAddress;

    pool->mEntries = entries;
    pool->mCount = count;
    pool->mNextIndex = 0;
    pool->mNextEntry = pool->mEntries;
    pool->mEntrySize = entrySize;
    entryAddress = pool->mNextEntry;
    for (handleIndex = 0; handleIndex < count; handleIndex++) {
        ((SoundHandleEntry *) entryAddress)->mAge = 0;
        NNS_SndHandleInit(&((SoundHandleEntry *) entryAddress)->mSeqPlayer);
        entryAddress += pool->mEntrySize;
    }
}

void IncrementSoundHandleAges(SoundHandlePool *pool) {
    s32 handleIndex;
    u8 *entryAddress;

    for (handleIndex = 0, entryAddress = pool->mEntries; handleIndex < pool->mCount; handleIndex++) {
        if (((SoundHandleEntry *) entryAddress)->mSeqPlayer != NULL) {
            ((SoundHandleEntry *) entryAddress)->mAge++;
        }
        entryAddress += pool->mEntrySize;
    }
}

void *TakeSoundHandleEntry(SoundHandlePool *pool) {
    s32 entryIndex;
    s32 oldestAge;
    s32 oldestIndex;
    u8 *entryAddress;
    s32 count;
    s32 startIndex;
    u8 *oldestEntry;

    {
        s32 takenIndex;
        u8 *takenEntry;

        startIndex = pool->mNextIndex;
        oldestAge = -1;
        count = pool->mCount;
        takenEntry = NULL;
        oldestIndex = -1;
        takenIndex = -1;
        oldestEntry = NULL;
        entryAddress = pool->mNextEntry;
        for (entryIndex = startIndex; entryIndex < count; entryIndex++) {
            if (((SoundHandleEntry *) entryAddress)->mSeqPlayer == NULL) {
                takenEntry = entryAddress;
            } else {
                if (oldestAge < ((SoundHandleEntry *) entryAddress)->mAge) {
                    oldestAge = ((SoundHandleEntry *) entryAddress)->mAge;
                    oldestIndex = entryIndex;
                    oldestEntry = entryAddress;
                }
                takenEntry = NULL;
            }
            if (takenEntry != NULL) {
                takenIndex = entryIndex;
                break;
            }
            entryAddress += pool->mEntrySize;
        }
        if (takenEntry == NULL) {
            entryAddress = pool->mEntries;
            for (entryIndex = 0; entryIndex < startIndex; entryIndex++) {
                if (((SoundHandleEntry *) entryAddress)->mSeqPlayer == NULL) {
                    takenEntry = entryAddress;
                } else {
                    takenEntry = NULL;
                    if (oldestAge < ((SoundHandleEntry *) entryAddress)->mAge) {
                        oldestAge = ((SoundHandleEntry *) entryAddress)->mAge;
                        oldestIndex = entryIndex;
                        oldestEntry = entryAddress;
                    }
                }
                if (takenEntry != NULL) {
                    takenIndex = entryIndex;
                    break;
                }
                entryAddress += pool->mEntrySize;
            }
        }
        if (takenEntry == NULL) {
            takenEntry = oldestEntry;
            takenIndex = oldestIndex;
            NNS_SndPlayerStopSeq(&((SoundHandleEntry *) oldestEntry)->mSeqPlayer, 0);
        }
        ((SoundHandleEntry *) takenEntry)->mAge = 0;
        NNS_SndHandleInit(&((SoundHandleEntry *) takenEntry)->mSeqPlayer);
        pool->mNextIndex = takenIndex;
        pool->mNextIndex = pool->mNextIndex + 1;
        pool->mNextEntry = takenEntry + pool->mEntrySize;
        if (pool->mNextIndex >= pool->mCount) {
            pool->mNextIndex = 0;
            pool->mNextEntry = pool->mEntries;
        }
        return takenEntry;
    }
}

void InitSoundRequestQueue(SoundRequestQueue *queue, s32 count, NNSSndHeap *heap) {
    s32 requestIndex;

    queue->mCapacity = count;
    queue->mRequests = NNS_SndHeapAlloc(heap, count << 4, NULL, NULL, 0);
    for (requestIndex = 0; requestIndex < queue->mCapacity; requestIndex++) {
        queue->mRequests[requestIndex].mSortKey = -1;
        queue->mRequests[requestIndex].mFunction = NULL;
        queue->mRequests[requestIndex].mFirstArgument = NULL;
        queue->mRequests[requestIndex].mSecondArgument = 0;
    }
}

void ResetSoundRequestQueue(SoundRequestQueue *queue) {
    s32 requestIndex;

    for (requestIndex = 0; requestIndex < queue->mCapacity; requestIndex++) {
        queue->mRequests[requestIndex].mSortKey = -1;
        queue->mRequests[requestIndex].mFunction = NULL;
        queue->mRequests[requestIndex].mFirstArgument = NULL;
        queue->mRequests[requestIndex].mSecondArgument = 0;
    }
}

// The standalone copy expands itself twice before it calls itself.
#pragma inline_depth(2)
static inline void InsertSoundRequest(SoundRequestQueue *queue, SoundRequest *request, s32 index) {
    SoundRequest displacedRequest;

    for (; index < queue->mCapacity; index++) {
        if (request->mSortKey < queue->mRequests[index].mSortKey) {
            displacedRequest = queue->mRequests[index];
            queue->mRequests[index] = *request;
            if (index + 1 < queue->mCapacity) {
                InsertSoundRequest(queue, &displacedRequest, index + 1);
            }
            return;
        }
    }
}

void AddSoundRequest(SoundRequestQueue *queue, int sortKey, void (*function)(void *, int), void *firstArgument,
                     int secondArgument) {
    SoundRequest request;

    request.mSortKey = sortKey;
    request.mFirstArgument = firstArgument;
    request.mSecondArgument = secondArgument;
    request.mFunction = function;
    InsertSoundRequest(queue, &request, 0);
}

void RunSoundRequests(SoundRequestQueue *queue) {
    s32 requestIndex;

    for (requestIndex = 0; requestIndex < queue->mCapacity; requestIndex++) {
        if (queue->mRequests[requestIndex].mFunction == NULL) {
            break;
        }
        queue->mRequests[requestIndex].mFunction(queue->mRequests[requestIndex].mFirstArgument,
                                                 queue->mRequests[requestIndex].mSecondArgument);
    }
    for (requestIndex = 0; requestIndex < queue->mCapacity; requestIndex++) {
        queue->mRequests[requestIndex].mSortKey = -1;
        queue->mRequests[requestIndex].mFunction = NULL;
        queue->mRequests[requestIndex].mFirstArgument = NULL;
        queue->mRequests[requestIndex].mSecondArgument = 0;
    }
}

u32 InitSoundSetPlayer(SoundSetPlayer *player, u32 seqId, u32 firstBankId, u32 secondBankId,
                       LoadedSoundSet *loadedSet) {
    SoundSet soundSet;

    soundSet.mSeqId = seqId;
    soundSet.mFirstBankId = firstBankId;
    soundSet.mSecondBankId = secondBankId;
    player->mSoundSet = soundSet;
    if (IsSoundSetLoaded(loadedSet, player->mSoundSet) == 0) {
        ReleaseSoundSet(loadedSet);
        LoadSoundSet(loadedSet, player->mSoundSet);
    }
    NNS_SndHandleInit(&player->mSeqPlayer);
    gCurrentSoundSetPlayer = player;
    player->mLoadedSet = loadedSet;
    return 1;
}

void StartSoundSetSeq(SoundSetPlayer *player, u32 volume) {
    StartSeqAtVolume(player->mSoundSet.mSeqId, volume, &player->mSeqPlayer);
}

void StopSoundSetSeq(SoundSetPlayer *player, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(&player->mSeqPlayer, fadeSteps);
}

void ReleaseSoundSetPlayer(SoundSetPlayer *player) {
    ReleaseSoundSet(player->mLoadedSet);
    gCurrentSoundSetPlayer = NULL;
}
