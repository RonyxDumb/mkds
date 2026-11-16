#include "Main/Net/slot_result_sync.h"

#include "Main/Race/results_by_mode.h"
#include "Main/System/heap.h"
#include "file_handle_setup.h"
#include "Main/System/heap_call.h"
#include "Main/Net/slot_result_sync_halfword.h"
#include "Main/Net/slot_result_pending.h"
#include "Main/Net/participant_mask.h"
#include "overlay_id_symbols.h"
#include "Main/System/backup_net_camera_work.h"
#include "overlay_section_symbols.h"
#include "02/overlay_heap_buffers.h"
#include "file_archive_access.h"
#include "overlay_rom_loader.h"
#include "expanded_heap_head.h"
#include "heap_frame_allocator.h"
#include "Main/Save/ghost_record_file.h"

SceneCallbacks g_Scene_Result = {
    Scene_Result_Initialize, Scene_Result_Update, Scene_Result_Finalize, Scene_Result_VBlank, NULL, NULL, 0xa, 0xa, 0};

static inline void SetOverlayLoaderEntry(s32 entryIndex, s32 overlayId, u32 startAddress, u32 endAddress) {
    OverlayLoaderEntry *entry;

    entry = &g_OverlayManager->mEntries[entryIndex];
    entry->mOverlayId = overlayId;
    entry->mStart = startAddress;
    entry->mEnd = endAddress;
    if (entry->mStart < g_OverlayManager->mLowestStart) {
        g_OverlayManager->mLowestStart = entry->mStart;
    }
    if (entry->mEnd > g_OverlayManager->mHighestEnd) {
        g_OverlayManager->mHighestEnd = entry->mEnd;
    }
}

void StartSlotResultSync(SlotResultSyncState *syncState, s32 itemInfoIndex) {
    s32 syncFrames;

    syncState->mSendCount = 0;
    syncFrames = g_GlobalAA->mSyncFrames;
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
            syncState = &g_GlobalAA->mEntries[participantIndex].mSlotResultSyncState;
            receivedHalfword = GetEntrySlotResultSyncHalfword(participantIndex, participantIndex);
            switch (syncState->mState) {
                case SLOT_RESULT_SYNC_STATE_IDLE:
                    if (receivedHalfword->mState == SLOT_RESULT_SYNC_STATE_SENDING) {
                        StartParticipantResultPending(participantIndex);
                        StartSlotResultSync(syncState, receivedHalfword->mItemInfoIndex);
                    }
                    break;
                case SLOT_RESULT_SYNC_STATE_SENDING:
                    remainingFrames = syncState->mEndSyncFrame - g_GlobalAA->mSyncFrames;
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

    entry = &g_GlobalAA->mEntries[participantIndex];
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
    if ((u16) (g_GlobalAA->mEntries[participantIndex].mState + 0xffff) <= 1) {
        isSyncing = TRUE;
    }
    if (isSyncing == FALSE) {
        itemInfoIndex = g_GlobalAA->mEntries[participantIndex].mItemInfoIndex;
    }
    return itemInfoIndex;
}

// Allocates the overlay record and fills the table of the three overlays and the address range they cover.
void InitializeOverlayManager(void *heap) {
    g_OverlayManager = Mem_AllocateHeap(heap, sizeof(*g_OverlayManager));
    g_OverlayManager->mLowestStart = -1;
    g_OverlayManager->mHighestEnd = 0;
    SetOverlayLoaderEntry(OVERLAY_SLOT_OV000, (s32) SDK_OVERLAY_OV000_ID, (u32) OV000_TEXT_START, (u32) OV000_BSS_END);
    SetOverlayLoaderEntry(OVERLAY_SLOT_OV001, (s32) SDK_OVERLAY_OV001_ID, (u32) OV001_TEXT_START, (u32) OV001_BSS_END);
    SetOverlayLoaderEntry(OVERLAY_SLOT_OV002, (s32) SDK_OVERLAY_OV002_ID, (u32) OV002_CTOR_START, (u32) OV002_BSS_END);
    g_OverlayManager->mFrmHeap = NULL;
    g_OverlayManager->mExpHeap = NULL;
}

// Creates the frame heap in a fixed 0x50000-byte buffer.
void CreateOverlayFrmHeap(void) {
    g_OverlayManager->mFrmHeap = Mem_Frame_Create(gOverlayFrmHeapBuffer, 0x50000, 0);
}

// Marks no overlay as current: index 4 is past the three table entries.
void ResetOverlayManager(void) {
    g_OverlayManager->mCurrentOverlay = OVERLAY_SLOT_NONE;
    g_OverlayManager->mLoadState = OVERLAY_LOAD_IDLE;
}

// Starts loading the overlay: nothing while a load runs; a loaded overlay is unloaded first.
void UpdateOverlayStatusWithKind(s32 overlay) {
    OverlayLoader *loader;
    s32 current;
    s32 state;

    loader = g_OverlayManager;
    current = loader->mCurrentOverlay;
    if (current == overlay) {
        return;
    }
    state = loader->mLoadState;
    switch (state) {
        case OVERLAY_LOAD_IDLE:
            Fs_OverlayInfo_Load(&loader->mInfo, 0, loader->mEntries[overlay].mOverlayId);
            Fs_File_Initialize(&g_OverlayManager->mFile);
            Fs_OverlayInfo_LoadImageAsync(&g_OverlayManager->mInfo, &g_OverlayManager->mFile);
            g_OverlayManager->mLoadState = OVERLAY_LOAD_READING;
            g_OverlayManager->mCurrentOverlay = overlay;
            break;
        case OVERLAY_LOAD_READING:
            break;
        case OVERLAY_LOAD_STARTED:
            switch (state) {
                case OVERLAY_LOAD_READING:
                case OVERLAY_LOAD_STARTED:
                    if (Fs_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        g_OverlayManager->mCurrentOverlay = OVERLAY_SLOT_NONE;
                        g_OverlayManager->mLoadState = OVERLAY_LOAD_IDLE;
                        if (g_OverlayManager->mExpHeap != NULL) {
                            Mem_Exp_Finalize(g_OverlayManager->mExpHeap);
                            g_OverlayManager->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            Fs_OverlayInfo_Load(&g_OverlayManager->mInfo, 0, g_OverlayManager->mEntries[overlay].mOverlayId);
            Fs_File_Initialize(&g_OverlayManager->mFile);
            Fs_OverlayInfo_LoadImageAsync(&g_OverlayManager->mInfo, &g_OverlayManager->mFile);
            g_OverlayManager->mLoadState = OVERLAY_LOAD_READING;
            g_OverlayManager->mCurrentOverlay = overlay;
            break;
        case OVERLAY_LOAD_UNUSED:
            switch (state) {
                case OVERLAY_LOAD_READING:
                case OVERLAY_LOAD_STARTED:
                    if (Fs_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        g_OverlayManager->mCurrentOverlay = OVERLAY_SLOT_NONE;
                        g_OverlayManager->mLoadState = OVERLAY_LOAD_IDLE;
                        if (g_OverlayManager->mExpHeap != NULL) {
                            Mem_Exp_Finalize(g_OverlayManager->mExpHeap);
                            g_OverlayManager->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            Fs_OverlayInfo_Load(&g_OverlayManager->mInfo, 0, g_OverlayManager->mEntries[overlay].mOverlayId);
            Fs_File_Initialize(&g_OverlayManager->mFile);
            Fs_OverlayInfo_LoadImageAsync(&g_OverlayManager->mInfo, &g_OverlayManager->mFile);
            g_OverlayManager->mLoadState = OVERLAY_LOAD_READING;
            g_OverlayManager->mCurrentOverlay = overlay;
            break;
    }
}

// Waits in a loop for the read to end, then starts the overlay and closes the file.
void WaitOverlayLoadedStarted(void) {
    BOOL finished;
    s32 loadState;

    do {
        finished = FALSE;
        loadState = g_OverlayManager->mLoadState;
        if (loadState == OVERLAY_LOAD_STARTED) {
            finished = TRUE;
        } else if (loadState == OVERLAY_LOAD_READING) {
            if (((g_OverlayManager->mFile.mStat & 1) ? 1 : 0) == 0) {
                Fs_OverlayInfo_Start(&g_OverlayManager->mInfo);
                Fs_File_Close(&g_OverlayManager->mFile);
                g_OverlayManager->mLoadState = OVERLAY_LOAD_STARTED;
                finished = TRUE;
            }
        }
    } while (finished == FALSE);
}

// Creates the expandable heap only while overlay 1 is the current one.
void CreateRegionHeapHandleForOverlay1(void) {
    if (g_OverlayManager->mCurrentOverlay != OVERLAY_SLOT_OV001) {
        return;
    }
    g_OverlayManager->mExpHeap = Mem_Exp_Create(g_Overlay3Region, 0x20800, 1);
}

void DisposeOverlayManagerHeap(void) {
    if (g_OverlayManager->mExpHeap == NULL) {
        return;
    }
    Mem_Exp_Finalize(g_OverlayManager->mExpHeap);
    g_OverlayManager->mExpHeap = NULL;
}

// Same finish as the wait loop without waiting: returns 1 when the overlay is loaded, else 0.
s32 TryFinishOverlayLoad(void) {
    enum { RESULT_NOT_LOADED } result;
    s32 state;
    OverlayLoader *loader;

    result = 0;
    loader = g_OverlayManager;
    state = loader->mLoadState;
    if (state == OVERLAY_LOAD_STARTED) {
        return 1;
    }
    if (state != OVERLAY_LOAD_READING) {
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
    Fs_OverlayInfo_Start(&loader->mInfo);
    Fs_File_Close(&g_OverlayManager->mFile);
    g_OverlayManager->mLoadState = OVERLAY_LOAD_STARTED;
    return 1;
}

void DisposeLoadedOverlay(void) {
    if (g_OverlayManager->mLoadState != OVERLAY_LOAD_READING && g_OverlayManager->mLoadState != OVERLAY_LOAD_STARTED) {
        return;
    }
    if (Fs_UnloadOverlay(0, g_OverlayManager->mEntries[g_OverlayManager->mCurrentOverlay].mOverlayId) == 0) {
        return;
    }
    g_OverlayManager->mCurrentOverlay = OVERLAY_SLOT_NONE;
    g_OverlayManager->mLoadState = OVERLAY_LOAD_IDLE;
    if (g_OverlayManager->mExpHeap != NULL) {
        Mem_Exp_Finalize(g_OverlayManager->mExpHeap);
        g_OverlayManager->mExpHeap = NULL;
    }
}

// 1 when the address lies between the lowest start and the highest end of the three overlays.
u32 IsAddressInOverlayRegion(struct MapObjectKindDescriptor *address) {
    u32 inRange;

    inRange = 0;
    if ((u32) address >= g_OverlayManager->mLowestStart) {
        if ((u32) address <= g_OverlayManager->mHighestEnd) {
            inRange = 1;
        }
    }
    return inRange;
}

void Scene_Result_Initialize(void) {
    InstanceStructN_from_thumb(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
}

void Scene_Result_Finalize(void) {
    u32 unusedValue;
    Scene_Result_FinalizeImpl_from_thumb();
}

void Scene_Result_VBlank(void) {
    u32 unusedValue;
    Scene_Result_VBlankImpl_from_thumb();
}

void Scene_Result_Update(SceneNumbers *sceneNumbers) {
    SceneNumbers *numbers = sceneNumbers;
    u32 unusedValue;
    Scene_Result_UpdateImpl_from_thumb(numbers);
}
