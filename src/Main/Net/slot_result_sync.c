#include "Main/Net/slot_result_sync.h"

#include "Main/Race/results_by_mode.h"
#include "Main/System/heap.h"
#include "fs_file.h"
#include "Main/System/heap_call.h"
#include "Main/Net/slot_result_sync_halfword.h"
#include "Main/Net/slot_result_pending.h"
#include "Main/Net/participant_mask.h"
#include "data_00000000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "data_02180000.h"
#include "02/unk_02180500.h"
#include "code_02003be0.h"
#include "code_02004dc0.h"
#include "code_020176c0.h"
#include "frameheap.h"

SceneCallbacks gResultSceneCallbacks = {InitResultScene, UpdateResultScene, ReleaseResultScene, WriteResultSceneRegistersCallback, NULL, NULL, 0xa, 0xa, 0};

static inline void SetOverlayLoaderEntry(s32 entryIndex, s32 overlayId, u32 startAddress, u32 endAddress) {
    OverlayLoaderEntry *entry;

    entry = &gOverlayLoader->mEntries[entryIndex];
    entry->mOverlayId = overlayId;
    entry->mStart = startAddress;
    entry->mEnd = endAddress;
    if (entry->mStart < gOverlayLoader->mLowestStart) {
        gOverlayLoader->mLowestStart = entry->mStart;
    }
    if (entry->mEnd > gOverlayLoader->mHighestEnd) {
        gOverlayLoader->mHighestEnd = entry->mEnd;
    }
}

void StartSlotResultSync(SlotResultSyncState *syncState, s32 itemInfoIndex) {
    s32 syncFrames;

    syncState->mSendCount = 0;
    syncFrames = gWiFiRaceSync->mSyncFrames;
    syncState->mState = SLOT_RESULT_SYNC_STATE_SENDING;
    syncState->mItemInfoIndex = itemInfoIndex;
    syncState->mEndSyncFrame = syncFrames + SLOT_RESULT_SYNC_SEND_FRAMES;
    syncState->mPendingItemInfoIndex = SLOT_RESULT_SYNC_NO_ITEM;
}

// Steps the slot result sync of each participant once per call.
void UpdateSlotResultSyncs(void) {
    u8 participantIndex;
    SlotResultSyncState *syncState;
    s32 remainingFrames;
    SlotResultSyncHalfword *receivedHalfword;

    for (participantIndex = 0; participantIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participantIndex++) {
        if (IsInParticipantMask(participantIndex) != 0) {
            syncState = &gWiFiRaceSync->mEntries[participantIndex].mSlotResultSyncState;
            receivedHalfword = GetEntrySlotResultSyncHalfword(participantIndex, participantIndex);
            switch (syncState->mState) {
                case SLOT_RESULT_SYNC_STATE_IDLE:
                    if (receivedHalfword->mState == SLOT_RESULT_SYNC_STATE_SENDING) {
                        StartParticipantResultPending(participantIndex);
                        StartSlotResultSync(syncState, receivedHalfword->mItemInfoIndex);
                    }
                    break;
                case SLOT_RESULT_SYNC_STATE_SENDING:
                    remainingFrames = syncState->mEndSyncFrame - gWiFiRaceSync->mSyncFrames;
                    if ((s32) syncState->mSendCount < SLOT_RESULT_SYNC_MAX_SENDS) {
                        SetSendSlotResultSync(participantIndex, remainingFrames, syncState->mItemInfoIndex,
                                              SLOT_RESULT_SYNC_STATE_SENDING);
                        syncState->mSendCount = syncState->mSendCount + 1;
                    } else if (remainingFrames > SLOT_RESULT_SYNC_CLEAR_FRAMES) {
                        SetSendSlotResultSync(participantIndex, remainingFrames, syncState->mItemInfoIndex,
                                              SLOT_RESULT_SYNC_STATE_SENDING);
                    } else {
                        ClearSendSlotResultSync(participantIndex);
                        if (remainingFrames <= 0) {
                            syncState->mState = SLOT_RESULT_SYNC_STATE_COPY_TO_PENDING;
                        }
                    }
                    break;
                case SLOT_RESULT_SYNC_STATE_COPY_TO_PENDING:
                    CopySlotResultToPending(syncState);
                    break;
                case SLOT_RESULT_SYNC_STATE_WAIT_FOR_END:
                    if (receivedHalfword->mState != SLOT_RESULT_SYNC_STATE_SENDING) {
                        syncState->mState = SLOT_RESULT_SYNC_STATE_IDLE;
                    }
                    break;
            }
        }
    }
}

BOOL IsParticipantSlotResultSyncing(s32 participantIndex) {
    BOOL isSyncing;
    WiFiRaceSyncEntry *entry;

    entry = &gWiFiRaceSync->mEntries[participantIndex];
    isSyncing = FALSE;
    if ((u16) (entry->mState + 0xffff) <= 1) {
        isSyncing = TRUE;
    }
    return isSyncing;
}

s32 GetParticipantSlotResult(s32 participantIndex) {
    s32 itemInfoIndex;
    BOOL isSyncing;

    itemInfoIndex = SLOT_RESULT_SYNC_NO_ITEM;
    isSyncing = FALSE;
    if ((u16) (gWiFiRaceSync->mEntries[participantIndex].mState + 0xffff) <= 1) {
        isSyncing = TRUE;
    }
    if (isSyncing == FALSE) {
        itemInfoIndex = gWiFiRaceSync->mEntries[participantIndex].mItemInfoIndex;
    }
    return itemInfoIndex;
}

// Allocates the overlay record and fills the table of the three overlays and the address range they cover.
void InitOverlayTable(void *heap) {
    gOverlayLoader = HeapAlloc(heap, 0xb0);
    gOverlayLoader->mLowestStart = -1;
    gOverlayLoader->mHighestEnd = 0;
    SetOverlayLoaderEntry(0, (s32) SDK_OVERLAY_OV000_ID, (u32) OV000_TEXT_START, (u32) OV000_BSS_END);
    SetOverlayLoaderEntry(1, (s32) SDK_OVERLAY_OV001_ID, (u32) OV001_TEXT_START, (u32) OV001_BSS_END);
    SetOverlayLoaderEntry(2, (s32) SDK_OVERLAY_OV002_ID, (u32) OV002_CTOR_START, (u32) OV002_BSS_END);
    gOverlayLoader->mFrmHeap = NULL;
    gOverlayLoader->mExpHeap = NULL;
}

// Creates the frame heap in a fixed 0x50000-byte buffer.
void CreateOverlayFrmHeap(void) {
    gOverlayLoader->mFrmHeap = NNS_FndCreateFrmHeapEx(gOverlayFrmHeapBuffer, 0x50000, 0);
}

// Marks no overlay as current: index 4 is past the three table entries.
void ResetCurrentOverlay(void) {
    gOverlayLoader->mCurrentOverlay = 4;
    gOverlayLoader->mLoadState = 0;
}

// Starts loading the overlay: nothing while a load runs; a loaded overlay is unloaded first.
void StartLoadOverlay(s32 overlay) {
    OverlayLoader *loader;
    s32 current;
    s32 state;

    loader = gOverlayLoader;
    current = loader->mCurrentOverlay;
    if (current == overlay) {
        return;
    }
    state = loader->mLoadState;
    switch (state) {
        case 0:
            FS_LoadOverlayInfo(&loader->mInfo, 0, loader->mEntries[overlay].mOverlayId);
            FS_InitFile(&gOverlayLoader->mFile);
            FS_LoadOverlayImageAsync(&gOverlayLoader->mInfo, &gOverlayLoader->mFile);
            gOverlayLoader->mLoadState = 1;
            gOverlayLoader->mCurrentOverlay = overlay;
            break;
        case 1:
            break;
        case 2:
            switch (state) {
                case 1:
                case 2:
                    if (FS_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        gOverlayLoader->mCurrentOverlay = 4;
                        gOverlayLoader->mLoadState = 0;
                        if (gOverlayLoader->mExpHeap != NULL) {
                            NNS_FndDestroyExpHeap(gOverlayLoader->mExpHeap);
                            gOverlayLoader->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            FS_LoadOverlayInfo(&gOverlayLoader->mInfo, 0, gOverlayLoader->mEntries[overlay].mOverlayId);
            FS_InitFile(&gOverlayLoader->mFile);
            FS_LoadOverlayImageAsync(&gOverlayLoader->mInfo, &gOverlayLoader->mFile);
            gOverlayLoader->mLoadState = 1;
            gOverlayLoader->mCurrentOverlay = overlay;
            break;
        case 3:
            switch (state) {
                case 1:
                case 2:
                    if (FS_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        gOverlayLoader->mCurrentOverlay = 4;
                        gOverlayLoader->mLoadState = 0;
                        if (gOverlayLoader->mExpHeap != NULL) {
                            NNS_FndDestroyExpHeap(gOverlayLoader->mExpHeap);
                            gOverlayLoader->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            FS_LoadOverlayInfo(&gOverlayLoader->mInfo, 0, gOverlayLoader->mEntries[overlay].mOverlayId);
            FS_InitFile(&gOverlayLoader->mFile);
            FS_LoadOverlayImageAsync(&gOverlayLoader->mInfo, &gOverlayLoader->mFile);
            gOverlayLoader->mLoadState = 1;
            gOverlayLoader->mCurrentOverlay = overlay;
            break;
    }
}

// Waits in a loop for the read to end, then starts the overlay and closes the file.
void FinishOverlayLoad(void) {
    BOOL finished;
    s32 loadState;

    do {
        finished = FALSE;
        loadState = gOverlayLoader->mLoadState;
        if (loadState == 2) {
            finished = TRUE;
        } else if (loadState == 1) {
            if (((gOverlayLoader->mFile.mStat & 1) ? 1 : 0) == 0) {
                FS_StartOverlay(&gOverlayLoader->mInfo);
                FS_CloseFile(&gOverlayLoader->mFile);
                gOverlayLoader->mLoadState = 2;
                finished = TRUE;
            }
        }
    } while (finished == FALSE);
}

// Creates the expandable heap only while overlay 1 is the current one.
void CreateOverlayExpHeap(void) {
    if (gOverlayLoader->mCurrentOverlay != 1) {
        return;
    }
    gOverlayLoader->mExpHeap = NNS_FndCreateExpHeapEx(gOverlayExpHeapBuffer, 0x20800, 1);
}

void FreeOverlayExpHeap(void) {
    if (gOverlayLoader->mExpHeap == NULL) {
        return;
    }
    NNS_FndDestroyExpHeap(gOverlayLoader->mExpHeap);
    gOverlayLoader->mExpHeap = NULL;
}

// Same finish as the wait loop without waiting: returns 1 when the overlay is loaded, else 0.
s32 TryFinishOverlayLoad(void) {
    enum { K0 } result;
    s32 state;
    OverlayLoader *loader;

    result = 0;
    loader = gOverlayLoader;
    state = loader->mLoadState;
    if (state == 2) {
        return 1;
    }
    if (state != 1) {
        return result;
    }
    if (loader->mFile.mStat & 1) {
        state = 1;
    } else {
        state = result;
    }
    if (state != 0) {
        return result;
    }
    FS_StartOverlay(&loader->mInfo);
    FS_CloseFile(&gOverlayLoader->mFile);
    gOverlayLoader->mLoadState = 2;
    return 1;
}

void ReleaseCurrentOverlay(void) {
    if (gOverlayLoader->mLoadState != 1 && gOverlayLoader->mLoadState != 2) {
        return;
    }
    if (FS_UnloadOverlay(0, gOverlayLoader->mEntries[gOverlayLoader->mCurrentOverlay].mOverlayId) == 0) {
        return;
    }
    gOverlayLoader->mCurrentOverlay = 4;
    gOverlayLoader->mLoadState = 0;
    if (gOverlayLoader->mExpHeap != NULL) {
        NNS_FndDestroyExpHeap(gOverlayLoader->mExpHeap);
        gOverlayLoader->mExpHeap = NULL;
    }
}

// 1 when the address lies between the lowest start and the highest end of the three overlays.
u32 IsInOverlayRange(struct MapObjectKindDescriptor *address) {
    u32 inRange;

    inRange = 0;
    if ((u32) address >= gOverlayLoader->mLowestStart) {
        if ((u32) address <= gOverlayLoader->mHighestEnd) {
            inRange = 1;
        }
    }
    return inRange;
}

void InitResultScene(void) {
    InitResultsByMode(GetHeap(GetCurrentHeapCall()));
}

void ReleaseResultScene(void) {
    u32 unusedValue;
    ReleaseResultsByMode();
}

void WriteResultSceneRegistersCallback(void) {
    u32 unusedValue;
    WriteResultsByMode();
}

void UpdateResultScene(SceneNumbers *sceneNumbers) {
    SceneNumbers *numbers = sceneNumbers;
    u32 unusedValue;
    AdvanceResultsByMode(numbers);
}
