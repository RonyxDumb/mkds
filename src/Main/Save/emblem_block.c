#include "Main/Save/emblem_block.h"
#include "Main/Menu/ghost_scene.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_buddy_record_block.h"
#include "Main/System/heap_call.h"
#include "Main/Course/course_map_sections.h"
#include "Main/MapObjects/shape_map_object_count.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_first_block.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Save/backup_emblem_block.h"
#include "Main/Save/buddy_record_from_player.h"
#include "Main/Net/wifi_session.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "card_rom_backup_access.h"
#include "fixed_vector_math.h"
#include "cpu_copy_fill.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

SceneCallbacks g_Scene_Ghost = {InitGhostSceneCallback,
                                          UpdateGhostSceneCallback,
                                          ReleaseGhostSceneCallback,
                                          WriteGhostSceneRegistersCallback,
                                          NULL,
                                          NULL,
                                          0xa,
                                          0xa,
                                          0};

#pragma opt_rebuildconditionals off

EmblemBlock *CreateEmblemBlock(void *heap) {
    EmblemBlock *emblemBlock = Mem_AllocateHeap(heap, sizeof(EmblemBlock));
    if (emblemBlock != NULL) {
        emblemBlock->mBlockIndex = -1;
    }
    return emblemBlock;
}

BOOL CopyEmblemFromBlock(EmblemBlock *emblemBlock, u8 buddyIndex, EmblemData *emblemData) {
    BuddyRecord buddyRecord;
    u8 blockIndex;
    u8 slotIndex;
    blockIndex = buddyIndex / 5;
    slotIndex = buddyIndex % 5;
    if (blockIndex != emblemBlock->mBlockIndex) {
        return FALSE;
    }
    Mem_CpuCopy8(&g_SaveDataHolder->mBuddyRecordBlock->mRecords[buddyIndex], &buddyRecord, sizeof(BuddyRecord));
    if (buddyRecord.mFilled == 0 || buddyRecord.mHasEmblem == 0) {
        return FALSE;
    }
    emblemData->mHasPixels = BIT_IS_SET(emblemBlock->mBlockData.mFilledBits, slotIndex);
    if (emblemData->mHasPixels != 0) {
        Mem_CpuCopy8(emblemBlock->mBlockData.mEmblems[slotIndex], emblemData,
                    sizeof(emblemBlock->mBlockData.mEmblems[slotIndex]));
    }
    return TRUE;
}

void SetupEmblemBlock(EmblemBlock *emblemBlock, u8 buddyIndex) {
    u8 blockIndex = buddyIndex / 5;
    if (IsBitArrayBitSet(blockIndex, g_SaveDataHolder->mFirstBlock->mEmblemBlockBits, 2) == 0) {
        emblemBlock->mBlockIndex = -1;
        return;
    }
    if (blockIndex == emblemBlock->mBlockIndex) {
        return;
    }
    ReadSaveChunk_NKFE_from_thumb(&emblemBlock->mBlockData, blockIndex);
    emblemBlock->mBlockIndex = blockIndex;
}

void GlobalATFunction_0(void) {
    u8 blockIndex;
    u16 playerIndex;
    PlayerRecord *playerEntry;
    u8 blockHasEmblem[12];
    s8 buddyIndexOfPlayer[8];
    EmblemBlockData *blockData;
    s32 firstBuddyIndex;
    s32 endBuddyIndex;
    u16 copyPlayerIndex;
    s32 ownIndex;
    BOOL blockCreated = FALSE;
    s32 buddyIndex;
    u8 slotIndex;
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        blockHasEmblem[blockIndex] = 0;
    }
    for (playerIndex = 0; playerIndex < 8; playerIndex++) {
        buddyIndexOfPlayer[playerIndex] = -1;
        if (g_GlobalZE->mConnectionMode == CONNECTION_MODE_CHILD) {
            ownIndex = g_GlobalZE->mOwnIndex;
        } else {
            ownIndex = 0;
        }
        if (playerIndex != (u16) ownIndex) {
            if ((g_GlobalZE->mGroupSendMask & (1 << g_GlobalZE->mParticipantIndexByPos[playerIndex])) == 0) {
                if (BIT_IS_SET(g_GlobalZE->mParticipantMask, playerIndex)) {
                    playerEntry = &g_GlobalZE->mPlayerRecords[playerIndex];
                    buddyIndex = SetBuddyRecordFromPlayer(playerEntry, 1);
                    if (buddyIndex != -1) {
                        if (playerEntry->mHasEmblem != 0) {
                            buddyIndexOfPlayer[playerIndex] = buddyIndex;
                            blockHasEmblem[buddyIndex / 5] = 1;
                        }
                    }
                }
            }
        }
    }
    WriteSaveDataSection_FriendList_from_thumb(g_SaveDataHolder->mBuddyRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        if (blockHasEmblem[blockIndex] != 0) {
            blockData = g_SaveDataHolder->mEmblemBlockData;
            if (IsBitArrayBitSet(blockIndex, g_SaveDataHolder->mFirstBlock->mEmblemBlockBits, 2) != 0) {
                ReadSaveChunk_NKFE_from_thumb(blockData, blockIndex);
                if (g_SaveDataIoManager->mBackupEnabled != 0) {
                    j_WaitForPendingCardOperation();
                }
            } else {
                Mem_CpuFill8(blockData, 0, sizeof(EmblemBlockData));
                MaybeSetPersonalGhostForCoursePresent_from_thumb(blockIndex, g_SaveDataHolder->mFirstBlock->mEmblemBlockBits, 2);
                blockCreated = TRUE;
            }
            firstBuddyIndex = blockIndex * 5;
            endBuddyIndex = (blockIndex + 1) * 5;
            for (copyPlayerIndex = 0; copyPlayerIndex < 8; copyPlayerIndex++) {
                buddyIndex = buddyIndexOfPlayer[copyPlayerIndex];
                if (buddyIndex >= firstBuddyIndex && buddyIndex < endBuddyIndex) {
                    slotIndex = buddyIndex % 5;
                    BIT_SET(blockData->mFilledBits, slotIndex);
                    Mem_CpuCopy8((u8 *) &g_GlobalZE->mPlayerRecords[copyPlayerIndex] + 0x14,
                                blockData->mEmblems[slotIndex], 0x200);
                }
            }
            WriteSaveChunk_NKFE_from_thumb(blockData, blockIndex);
            if (g_SaveDataIoManager->mBackupEnabled != 0) {
                j_WaitForPendingCardOperation();
            }
        }
    }
    if (blockCreated != FALSE) {
        WriteSaveDataSection_Header_from_thumb(g_SaveDataHolder->mFirstBlock);
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    ResetSaveDataHolderTaskPendingFlag_from_thumb();
}

void GlobalATFunction_1(void) {
    u8 blockIndex;
    u16 playerIndex;
    PlayerRecord *playerRecordData;
    u8 blockHasEmblem[12];
    s8 buddyIndexOfPlayer[4];
    EmblemBlockData *blockData;
    s32 firstBuddyIndex;
    s32 endBuddyIndex;
    u8 slotIndex;
    u16 copyPlayerIndex;
    u8 *filledBits;
    s32 buddyIndex;
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        blockHasEmblem[blockIndex] = 0;
    }
    for (playerIndex = 0; playerIndex < 4; playerIndex++) {
        buddyIndexOfPlayer[playerIndex] = -1;
        if (playerIndex != DWC_GetMyAID()) {
            playerRecordData = GetTKByIndex(playerIndex & 0xff);
            if (playerRecordData != NULL) {
                buddyIndex = SetBuddyRecordFromPlayer(playerRecordData, 0);
                if (buddyIndex != -1) {
                    if (playerRecordData->mHasEmblem != 0) {
                        buddyIndexOfPlayer[playerIndex] = buddyIndex;
                        blockHasEmblem[buddyIndex / 5] = 1;
                    }
                }
            }
        }
    }
    WriteSaveDataSection_FriendList_from_thumb(g_SaveDataHolder->mBuddyRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        if (blockHasEmblem[blockIndex] != 0) {
            blockData = g_SaveDataHolder->mEmblemBlockData;
            if (IsBitArrayBitSet(blockIndex, g_SaveDataHolder->mFirstBlock->mEmblemBlockBits, 2) != 0) {
                ReadSaveChunk_NKFE_from_thumb(blockData, blockIndex);
                if (g_SaveDataIoManager->mBackupEnabled != 0) {
                    j_WaitForPendingCardOperation();
                }
            } else {
                Mem_CpuFill8(blockData, 0, sizeof(EmblemBlockData));
                MaybeSetPersonalGhostForCoursePresent_from_thumb(blockIndex, g_SaveDataHolder->mFirstBlock->mEmblemBlockBits, 2);
            }
            firstBuddyIndex = blockIndex * 5;
            endBuddyIndex = (blockIndex + 1) * 5;
            filledBits = &blockData->mFilledBits;
            for (copyPlayerIndex = 0; copyPlayerIndex < 4; copyPlayerIndex++) {
                buddyIndex = buddyIndexOfPlayer[copyPlayerIndex];
                if (buddyIndex >= firstBuddyIndex && buddyIndex < endBuddyIndex) {
                    slotIndex = buddyIndex % 5;
                    *filledBits = *filledBits | (1 << slotIndex);
                    Mem_CpuCopy8(GetTKByIndex(copyPlayerIndex & 0xff)->mEmblem,
                                blockData->mEmblems[slotIndex], 0x200);
                }
            }
            WriteSaveChunk_NKFE_from_thumb(blockData, blockIndex);
            if (g_SaveDataIoManager->mBackupEnabled != 0) {
                j_WaitForPendingCardOperation();
            }
        }
    }
    ResetSaveDataHolderTaskPendingFlag_from_thumb();
}

static inline s32 EmblemGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

void StartCopyOtherEmblems(s32 useConnection) {
    void (*copyFunction)(void);
    BOOL connectionReady;
    s32 connectionMode;
    if (useConnection != 0) {
        connectionReady = FALSE;
        connectionMode = EmblemGetConnectionMode();
        if (connectionMode != CONNECTION_MODE_NONE) {
            if (g_GlobalZE->mState != CONNECTION_STATE_ENDED) {
                connectionReady = TRUE;
            }
        }
        if (connectionReady == FALSE) {
            return;
        }
        copyFunction = GlobalATFunction_0;
    } else {
        connectionMode = CONNECTION_MODE_NONE;
        if (g_GlobalB != NULL) {
            if (g_GlobalB->mHeapCreated != FALSE) {
                connectionMode = CONNECTION_MODE_PARENT;
            }
        }
        if (connectionMode == CONNECTION_MODE_NONE) {
            return;
        }
        copyFunction = GlobalATFunction_1;
    }
    EnableMKDSSVSomeFlag_from_thumb();
    WorkerInsertTask(copyFunction);
    g_WorkerContext->mRunRequested = 1;
}

static inline u8 CopyBuddyRecordsAndCountFilled(void *recordOut) {
    u8 filledCount = 0;
    u8 recordIndex = 0;
    do {
        if (recordOut != 0) {
            Mem_CpuCopy8(&g_SaveDataHolder->mBuddyRecordBlock->mRecords[recordIndex], recordOut, sizeof(BuddyRecord));
        }
        if (g_SaveDataHolder->mBuddyRecordBlock->mRecords[recordIndex].mFilled != 0) {
            filledCount = filledCount + 1;
        }
        recordIndex = recordIndex + 1;
    } while (recordIndex < 60);
    return filledCount;
}

u8 CountEmblemEntries(void) {
    return CopyBuddyRecordsAndCountFilled(0);
}

#pragma thumb on

void InitGhostSceneCallback(void) {
    InitGhostScene(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
}

void ReleaseGhostSceneCallback(void) {
    ReleaseGhostScene();
}

void WriteGhostSceneRegistersCallback(void) {
    WriteGhostSceneRegisters();
}

void UpdateGhostSceneCallback(u32 sceneNumbers) {
    AdvanceGhostScene(sceneNumbers);
}

s32 RunGhostScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = g_Scene_Ghost;

    OnSceneLoop(sceneNumbers, &callbacks);
    return 0;
}

#pragma thumb off

static inline s32 EmblemFX_MulInline(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_ROUNDED(multiplicand, multiplier);
}

void SomethingMissionModeType5Areas(void *heap) {
    u16 shapeCount;
    u16 countIndex;
    u16 entryIndex;
    u16 shapeIndex;
    u16 entryCount;
    CourseMapShape *courseMapShape;
    ShapeMapObjectCount *entry;
    s32 extentX;
    s32 extentY;
    s32 squaredSum;
    s32 extentZ;
    shapeCount = g_GlobalPE->mShapeCount;
    entryCount = 0;
    g_GlobalAR = Mem_AllocateHeap(heap, 8);
    for (countIndex = 0; countIndex < shapeCount; countIndex++) {
        if (GetGlobalPENkmAREAByIndex_from_thumb(countIndex)->mKind == COURSE_MAP_SHAPE_KIND_MAP_OBJECT_COUNT) {
            entryCount = entryCount + 1;
        }
    }
    if (entryCount != 0) {
        g_GlobalAR->mEntries = Mem_AllocateHeap(heap, entryCount * 0xc);
    }
    entryIndex = 0;
    g_GlobalAR->mEntryCount = entryCount;
    for (shapeIndex = 0; shapeIndex < shapeCount; shapeIndex++) {
        courseMapShape = GetGlobalPENkmAREAByIndex_from_thumb(shapeIndex);
        if (courseMapShape->mKind == COURSE_MAP_SHAPE_KIND_MAP_OBJECT_COUNT) {
            entry = &g_GlobalAR->mEntries[entryIndex];
            entry->mShapeIndex = shapeIndex;
            extentX = 0;
            switch (courseMapShape->mShapeKind) {
                case 0:
                    extentX = EmblemFX_MulInline(Const204800(), courseMapShape->mScale.x);
                    extentY = EmblemFX_MulInline(Const409600(), courseMapShape->mScale.y) >> 1;
                    extentZ = EmblemFX_MulInline(Const204800(), courseMapShape->mScale.z);
                    squaredSum = EmblemFX_MulInline(extentX, extentX) + EmblemFX_MulInline(extentY, extentY);
                    extentZ = EmblemFX_MulInline(extentZ, extentZ);
                    extentX = FX_Sqrt(extentZ + squaredSum);
                    break;
                case 1:
                    extentX = EmblemFX_MulInline(Const204800_0(), courseMapShape->mScale.x);
                    break;
            }
            entry->mRadius = extentX;
            entry->mMapObjectCount = 0;
            entry->mIncreaseCount = 0;
            entryIndex = entryIndex + 1;
        }
    }
}
