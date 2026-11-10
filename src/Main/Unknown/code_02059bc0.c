#include "Main/Unknown/code_02059bc0.h"

#include "Main/Unknown/code_0202a5a0.h"
#include "Main/Unknown/code_02036820.h"
#include "fs_file.h"
#include "Main/Unknown/code_0202a000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205a4e8.h"
#include "Main/Unknown/code_0205a534.h"
#include "Main/Unknown/code_0205a50c.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02180000.h"
#include "02/unk_02180500.h"
#include "code_02003be0.h"
#include "code_02004dc0.h"
#include "code_020176c0.h"
#include "frameheap.h"

static inline void func_0205a140_inline(s32 entryIndex, s32 overlayId, u32 startAddress, u32 endAddress) {
    OverlayLoaderEntry *entry;

    entry = &data_0217aa10->mEntries[entryIndex];
    entry->mOverlayId = overlayId;
    entry->mStart = startAddress;
    entry->mEnd = endAddress;
    if (entry->mStart < data_0217aa10->mLowestStart) {
        data_0217aa10->mLowestStart = entry->mStart;
    }
    if (entry->mEnd > data_0217aa10->mHighestEnd) {
        data_0217aa10->mHighestEnd = entry->mEnd;
    }
}

void StartSlotResultSync(SlotResultSyncState *syncState, s32 itemInfoIndex) {
    s32 syncFrames;

    syncState->mSendCount = 0;
    syncFrames = gWiFiRaceSync->mSyncFrames;
    syncState->mState = 2;
    syncState->mItemInfoIndex = itemInfoIndex;
    syncState->mEndSyncFrame = syncFrames + 0x78;
    syncState->mPendingItemInfoIndex = 0x13;
}

// Steps the slot result sync of each participant once per call.
void UpdateSlotResultSyncs(void) {
    u8 participantIndex;
    SlotResultSyncState *syncState;
    s32 remainingFrames;
    Unk0217aa14_104_20 *receivedHalfword;

    for (participantIndex = 0; participantIndex < 4; participantIndex++) {
        if (IsInParticipantMask(participantIndex) != 0) {
            syncState = &gWiFiRaceSync->mEntries[participantIndex].mUnk_68_view;
            receivedHalfword = GetEntrySlotResultSyncHalfword(participantIndex, participantIndex);
            switch (syncState->mState) {
                case 0:
                    if (receivedHalfword->mState == 2) {
                        StartParticipantResultPending(participantIndex);
                        StartSlotResultSync(syncState, receivedHalfword->mItemInfoIndex);
                    }
                    break;
                case 2:
                    remainingFrames = syncState->mEndSyncFrame - gWiFiRaceSync->mSyncFrames;
                    if ((s32) syncState->mSendCount < 100) {
                        SetSendSlotResultSync(participantIndex, remainingFrames, syncState->mItemInfoIndex, 2);
                        syncState->mSendCount = syncState->mSendCount + 1;
                    } else if (remainingFrames > 20) {
                        SetSendSlotResultSync(participantIndex, remainingFrames, syncState->mItemInfoIndex, 2);
                    } else {
                        ClearSendSlotResultSync(participantIndex);
                        if (remainingFrames <= 0) {
                            syncState->mState = 3;
                        }
                    }
                    break;
                case 3:
                    CopySlotResultToPending(syncState);
                    break;
                case 4:
                    if (receivedHalfword->mState != 2) {
                        syncState->mState = 0;
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

    itemInfoIndex = 0x13;
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
    data_0217aa10 = HeapAlloc(heap, 0xb0);
    data_0217aa10->mLowestStart = -1;
    data_0217aa10->mHighestEnd = 0;
    func_0205a140_inline(0, (s32) SDK_OVERLAY_OV000_ID, (u32) OV000_TEXT_START, (u32) OV000_BSS_END);
    func_0205a140_inline(1, (s32) SDK_OVERLAY_OV001_ID, (u32) OV001_TEXT_START, (u32) OV001_BSS_END);
    func_0205a140_inline(2, (s32) SDK_OVERLAY_OV002_ID, (u32) OV002_CTOR_START, (u32) OV002_BSS_END);
    data_0217aa10->mFrmHeap = NULL;
    data_0217aa10->mExpHeap = NULL;
}

// Creates the frame heap in a fixed 0x50000-byte buffer.
void CreateOverlayFrmHeap(void) {
    data_0217aa10->mFrmHeap = NNS_FndCreateFrmHeapEx(data_ov002_02180500, 0x50000, 0);
}

// Marks no overlay as current: index 4 is past the three table entries.
void ResetCurrentOverlay(void) {
    data_0217aa10->mCurrentOverlay = 4;
    data_0217aa10->mLoadState = 0;
}

// Starts loading the overlay: nothing while a load runs; a loaded overlay is unloaded first.
void StartLoadOverlay(s32 overlay) {
    OverlayLoader *loader;
    s32 current;
    s32 state;

    loader = data_0217aa10;
    current = loader->mCurrentOverlay;
    if (current == overlay) {
        return;
    }
    state = loader->mLoadState;
    switch (state) {
        case 0:
            FS_LoadOverlayInfo(&loader->mInfo, 0, loader->mEntries[overlay].mOverlayId);
            FS_InitFile(&data_0217aa10->mFile);
            FS_LoadOverlayImageAsync(&data_0217aa10->mInfo, &data_0217aa10->mFile);
            data_0217aa10->mLoadState = 1;
            data_0217aa10->mCurrentOverlay = overlay;
            break;
        case 1:
            break;
        case 2:
            switch (state) {
                case 1:
                case 2:
                    if (FS_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        data_0217aa10->mCurrentOverlay = 4;
                        data_0217aa10->mLoadState = 0;
                        if (data_0217aa10->mExpHeap != NULL) {
                            NNS_FndDestroyExpHeap(data_0217aa10->mExpHeap);
                            data_0217aa10->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            FS_LoadOverlayInfo(&data_0217aa10->mInfo, 0, data_0217aa10->mEntries[overlay].mOverlayId);
            FS_InitFile(&data_0217aa10->mFile);
            FS_LoadOverlayImageAsync(&data_0217aa10->mInfo, &data_0217aa10->mFile);
            data_0217aa10->mLoadState = 1;
            data_0217aa10->mCurrentOverlay = overlay;
            break;
        case 3:
            switch (state) {
                case 1:
                case 2:
                    if (FS_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        data_0217aa10->mCurrentOverlay = 4;
                        data_0217aa10->mLoadState = 0;
                        if (data_0217aa10->mExpHeap != NULL) {
                            NNS_FndDestroyExpHeap(data_0217aa10->mExpHeap);
                            data_0217aa10->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            FS_LoadOverlayInfo(&data_0217aa10->mInfo, 0, data_0217aa10->mEntries[overlay].mOverlayId);
            FS_InitFile(&data_0217aa10->mFile);
            FS_LoadOverlayImageAsync(&data_0217aa10->mInfo, &data_0217aa10->mFile);
            data_0217aa10->mLoadState = 1;
            data_0217aa10->mCurrentOverlay = overlay;
            break;
    }
}

// Waits in a loop for the read to end, then starts the overlay and closes the file.
void FinishOverlayLoad(void) {
    BOOL finished;
    s32 loadState;

    do {
        finished = FALSE;
        loadState = data_0217aa10->mLoadState;
        if (loadState == 2) {
            finished = TRUE;
        } else if (loadState == 1) {
            if (((data_0217aa10->mFile.mStat & 1) ? 1 : 0) == 0) {
                FS_StartOverlay(&data_0217aa10->mInfo);
                FS_CloseFile(&data_0217aa10->mFile);
                data_0217aa10->mLoadState = 2;
                finished = TRUE;
            }
        }
    } while (finished == FALSE);
}

// Creates the expandable heap only while overlay 1 is the current one.
void CreateOverlayExpHeap(void) {
    if (data_0217aa10->mCurrentOverlay != 1) {
        return;
    }
    data_0217aa10->mExpHeap = NNS_FndCreateExpHeapEx(data_ov002_021a9c00, 0x20800, 1);
}

void FreeOverlayExpHeap(void) {
    if (data_0217aa10->mExpHeap == NULL) {
        return;
    }
    NNS_FndDestroyExpHeap(data_0217aa10->mExpHeap);
    data_0217aa10->mExpHeap = NULL;
}

// Same finish as the wait loop without waiting: returns 1 when the overlay is loaded, else 0.
s32 TryFinishOverlayLoad(void) {
    enum { K0 } r;
    s32 state;
    OverlayLoader *loader;

    r = 0;
    loader = data_0217aa10;
    state = loader->mLoadState;
    if (state == 2) {
        return 1;
    }
    if (state != 1) {
        return r;
    }
    if (loader->mFile.mStat & 1) {
        state = 1;
    } else {
        state = r;
    }
    if (state != 0) {
        return r;
    }
    FS_StartOverlay(&loader->mInfo);
    FS_CloseFile(&data_0217aa10->mFile);
    data_0217aa10->mLoadState = 2;
    return 1;
}

void ReleaseCurrentOverlay(void) {
    if (data_0217aa10->mLoadState != 1 && data_0217aa10->mLoadState != 2) {
        return;
    }
    if (FS_UnloadOverlay(0, data_0217aa10->mEntries[data_0217aa10->mCurrentOverlay].mOverlayId) == 0) {
        return;
    }
    data_0217aa10->mCurrentOverlay = 4;
    data_0217aa10->mLoadState = 0;
    if (data_0217aa10->mExpHeap != NULL) {
        NNS_FndDestroyExpHeap(data_0217aa10->mExpHeap);
        data_0217aa10->mExpHeap = NULL;
    }
}

// 1 when the address lies between the lowest start and the highest end of the three overlays.
u32 IsInOverlayRange(struct MapObjectKindDescriptor *address) {
    u32 inRange;

    inRange = 0;
    if ((u32) address >= data_0217aa10->mLowestStart) {
        if ((u32) address <= data_0217aa10->mHighestEnd) {
            inRange = 1;
        }
    }
    return inRange;
}

void InitResultScene(void) {
    InitResultsByMode(GetHeap(GetCurrentHeapCall()));
}

void ReleaseResultScene(void) {
    u32 value12;
    ReleaseResultsByMode();
}

void WriteResultSceneRegistersCallback(void) {
    u32 value12;
    WriteResultsByMode();
}

void UpdateResultScene(SceneNumbers *arg0) {
    SceneNumbers *value0 = arg0;
    u32 value12;
    AdvanceResultsByMode(value0);
}
