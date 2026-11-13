#include "Main/Save/emblem_block.h"
#include "Main/Menu/ghost_scene.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_buddy_record_block.h"
#include "Main/System/heap_call.h"
#include "Main/Course/code_02042064.h"
#include "Main/MapObjects/shape_map_object_count.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_first_block.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Save/backup_emblem_block.h"
#include "Main/Save/buddy_record_from_player.h"
#include "Main/Net/wifi_session.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "code_021458c4.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/MapObjects/data_0217a000.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Save/ghost_record_file.h"

SceneCallbacks gRunGhostSceneCallbacks = {InitGhostSceneCallback, UpdateGhostSceneCallback, ReleaseGhostSceneCallback, WriteGhostSceneRegistersCallback, NULL, NULL, 0xa, 0xa, 0};

#pragma opt_rebuildconditionals off

EmblemBlock *CreateEmblemBlock(void *heap) {
    EmblemBlock *emblemBlock = HeapAlloc(heap, 0xb04);
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
    MI_CpuCopy8(&gBackupBuffers->mBuddyRecordBlock->mRecords[buddyIndex], &buddyRecord, 0x24);
    if (buddyRecord.mFilled == 0 || buddyRecord.mHasEmblem == 0) {
        return FALSE;
    }
    emblemData->mHasPixels = (emblemBlock->mUnk_04.mFilledBits & (1 << slotIndex)) != 0;
    if (emblemData->mHasPixels != 0) {
        MI_CpuCopy8(emblemBlock->mUnk_04.mEmblems[slotIndex], emblemData, 0x200);
    }
    return TRUE;
}

void SetupEmblemBlock(EmblemBlock *emblemBlock, u8 buddyIndex) {
    u8 blockIndex = buddyIndex / 5;
    if (IsBitArrayBitSet(blockIndex, gBackupBuffers->mFirstBlock->mEmblemBlockBits, 2) == 0) {
        emblemBlock->mBlockIndex = -1;
        return;
    }
    if (blockIndex == emblemBlock->mBlockIndex) {
        return;
    }
    ReadBackupEmblemBlock(&emblemBlock->mUnk_04, blockIndex);
    emblemBlock->mBlockIndex = blockIndex;
}

void CopyOtherPlayerEmblemsToBlocks(void) {
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
        if (gConnectionWork->mConnectionMode == 2) {
            ownIndex = gConnectionWork->mOwnIndex;
        } else {
            ownIndex = 0;
        }
        if (playerIndex != (u16) ownIndex) {
            if ((gConnectionWork->mGroupSendMask & (1 << gConnectionWork->mParticipantIndexByPos[playerIndex])) == 0) {
                if ((gConnectionWork->mParticipantMask & (1 << playerIndex)) != 0) {
                    playerEntry = &gConnectionWork->mPlayerRecords[playerIndex];
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
    WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        if (blockHasEmblem[blockIndex] != 0) {
            blockData = gBackupBuffers->mEmblemBlockData;
            if (IsBitArrayBitSet(blockIndex, gBackupBuffers->mFirstBlock->mEmblemBlockBits, 2) != 0) {
                ReadBackupEmblemBlock(blockData, blockIndex);
                if (gBackupAccess->mBackupEnabled != 0) {
                    CARD_WaitBackupAsync();
                }
            } else {
                MI_CpuFill8(blockData, 0, 0xb00);
                SetBitArrayBit(blockIndex, gBackupBuffers->mFirstBlock->mEmblemBlockBits, 2);
                blockCreated = TRUE;
            }
            firstBuddyIndex = blockIndex * 5;
            endBuddyIndex = (blockIndex + 1) * 5;
            for (copyPlayerIndex = 0; copyPlayerIndex < 8; copyPlayerIndex++) {
                buddyIndex = buddyIndexOfPlayer[copyPlayerIndex];
                if (buddyIndex >= firstBuddyIndex && buddyIndex < endBuddyIndex) {
                    slotIndex = buddyIndex % 5;
                    blockData->mFilledBits |= 1 << slotIndex;
                    MI_CpuCopy8((u8 *) &gConnectionWork->mPlayerRecords[copyPlayerIndex] + 0x14,
                                blockData->mEmblems[slotIndex], 0x200);
                }
            }
            WriteBackupEmblemBlock(blockData, blockIndex);
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    if (blockCreated != FALSE) {
        WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    ClearBackupBusy();
}

void CopyWiFiOtherEmblemsToBlocks(void) {
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
            playerRecordData = GetWiFiSessionPlayerRecordData(playerIndex & 0xff);
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
    WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        if (blockHasEmblem[blockIndex] != 0) {
            blockData = gBackupBuffers->mEmblemBlockData;
            if (IsBitArrayBitSet(blockIndex, gBackupBuffers->mFirstBlock->mEmblemBlockBits, 2) != 0) {
                ReadBackupEmblemBlock(blockData, blockIndex);
                if (gBackupAccess->mBackupEnabled != 0) {
                    CARD_WaitBackupAsync();
                }
            } else {
                MI_CpuFill8(blockData, 0, 0xb00);
                SetBitArrayBit(blockIndex, gBackupBuffers->mFirstBlock->mEmblemBlockBits, 2);
            }
            firstBuddyIndex = blockIndex * 5;
            endBuddyIndex = (blockIndex + 1) * 5;
            filledBits = (u8 *) blockData + 4;
            for (copyPlayerIndex = 0; copyPlayerIndex < 4; copyPlayerIndex++) {
                buddyIndex = buddyIndexOfPlayer[copyPlayerIndex];
                if (buddyIndex >= firstBuddyIndex && buddyIndex < endBuddyIndex) {
                    slotIndex = buddyIndex % 5;
                    *filledBits = *filledBits | (1 << slotIndex);
                    MI_CpuCopy8((u8 *) GetWiFiSessionPlayerRecordData(copyPlayerIndex & 0xff) + 0x14,
                                blockData->mEmblems[slotIndex], 0x200);
                }
            }
            WriteBackupEmblemBlock(blockData, blockIndex);
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    ClearBackupBusy();
}

static inline s32 EmblemGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

void StartCopyOtherEmblems(s32 useConnection) {
    void (*copyFunction)(void);
    BOOL connectionReady;
    s32 connectionMode;
    if (useConnection != 0) {
        connectionReady = FALSE;
        connectionMode = EmblemGetConnectionMode();
        if (connectionMode != 0) {
            if (gConnectionWork->mState != 13) {
                connectionReady = TRUE;
            }
        }
        if (connectionReady == FALSE) {
            return;
        }
        copyFunction = CopyOtherPlayerEmblemsToBlocks;
    } else {
        connectionMode = 0;
        if (gWiFiSession != NULL) {
            if (gWiFiSession->mHeapCreated != FALSE) {
                connectionMode = 1;
            }
        }
        if (connectionMode == 0) {
            return;
        }
        copyFunction = CopyWiFiOtherEmblemsToBlocks;
    }
    SetBackupBusy();
    QueueThreadFunction(copyFunction);
    gThreadFunctionQueue->mRunRequested = 1;
}

static inline u8 CopyBuddyRecordsAndCountFilled(void *recordOut) {
    u8 filledCount = 0;
    u8 recordIndex = 0;
    do {
        if (recordOut != 0) {
            MI_CpuCopy8(&gBackupBuffers->mBuddyRecordBlock->mRecords[recordIndex], recordOut, 0x24);
        }
        if (gBackupBuffers->mBuddyRecordBlock->mRecords[recordIndex].mFilled != 0) {
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
    InitGhostScene(GetHeap(GetCurrentHeapCall()));
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
    SceneCallbacks callbacks = gRunGhostSceneCallbacks;

    RunScene(sceneNumbers, &callbacks);
    return 0;
}

#pragma thumb off

static inline s32 EmblemFX_MulInline(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_ROUNDED(multiplicand, multiplier);
}

void CreateShapeMapObjectCountList(void *heap) {
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
    shapeCount = gCourseMap->mShapeCount;
    entryCount = 0;
    gShapeMapObjectCountList = HeapAlloc(heap, 8);
    for (countIndex = 0; countIndex < shapeCount; countIndex++) {
        if (GetCourseMapShape(countIndex)->mKind == COURSE_MAP_SHAPE_KIND_5) {
            entryCount = entryCount + 1;
        }
    }
    if (entryCount != 0) {
        gShapeMapObjectCountList->mEntries = HeapAlloc(heap, entryCount * 0xc);
    }
    entryIndex = 0;
    gShapeMapObjectCountList->mEntryCount = entryCount;
    for (shapeIndex = 0; shapeIndex < shapeCount; shapeIndex++) {
        courseMapShape = GetCourseMapShape(shapeIndex);
        if (courseMapShape->mKind == COURSE_MAP_SHAPE_KIND_5) {
            entry = &gShapeMapObjectCountList->mEntries[entryIndex];
            entry->mShapeIndex = shapeIndex;
            extentX = 0;
            switch (courseMapShape->mShapeKind) {
                case 0:
                    extentX = EmblemFX_MulInline(GetFixed12Of50(), courseMapShape->mScale.x);
                    extentY = EmblemFX_MulInline(GetFixed12Of100(), courseMapShape->mScale.y) >> 1;
                    extentZ = EmblemFX_MulInline(GetFixed12Of50(), courseMapShape->mScale.z);
                    squaredSum = EmblemFX_MulInline(extentX, extentX) + EmblemFX_MulInline(extentY, extentY);
                    extentZ = EmblemFX_MulInline(extentZ, extentZ);
                    extentX = FX_Sqrt(extentZ + squaredSum);
                    break;
                case 1:
                    extentX = EmblemFX_MulInline(ShapeMapObjectCountGetFixed12Of50(), courseMapShape->mScale.x);
                    break;
            }
            entry->mRadius = extentX;
            entry->mMapObjectCount = 0;
            entry->mIncreaseCount = 0;
            entryIndex = entryIndex + 1;
        }
    }
}
