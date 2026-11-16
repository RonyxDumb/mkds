#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_0202d000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_020431cc.h"
#include "Main/Save/GhostBits.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020576b8.h"
#include "Main/Unknown/code_02060c68.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219b580.h"
#include "code_021458c4.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"

#pragma opt_rebuildconditionals off

EmblemBlock *CreateEmblemBlock(void *heap) {
    EmblemBlock *emblemBlock = heap_alloc(heap, 0xb04);
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
    MI_CpuCopy8(&gSaveData->mBuddyRecordBlock->mRecords[buddyIndex], &buddyRecord, 0x24);
    if (buddyRecord.mFilled == 0 || buddyRecord.field22_2 == 0) {
        return FALSE;
    }
    emblemData->field200 = (emblemBlock->field4.mFilledBits & (1 << slotIndex)) != 0;
    if (emblemData->field200 != 0) {
        MI_CpuCopy8(emblemBlock->field4.mEmblems[slotIndex], emblemData, 0x200);
    }
    return TRUE;
}

void SetupEmblemBlock(EmblemBlock *emblemBlock, u8 buddyIndex) {
    u8 blockIndex = buddyIndex / 5;
    if (savd_isBitSet(blockIndex, &gSaveData->mFirstBlock->field2C[2], 2) == 0) {
        emblemBlock->mBlockIndex = -1;
        return;
    }
    if (blockIndex == emblemBlock->mBlockIndex) {
        return;
    }
    savd_readNkfe(&emblemBlock->field4, blockIndex);
    emblemBlock->mBlockIndex = blockIndex;
}

void CopyOtherPlayerEmblemsToBlocks(void) {
    u8 blockIndex;
    u16 playerIndex;
    Unk0217aa00_45c *playerEntry;
    u8 blockHasEmblem[12];
    s8 buddyIndexOfPlayer[8];
    EmblemBlockData *blockData;
    s32 firstBuddyIndex;
    s32 endBuddyIndex;
    u16 k;
    s32 ownIndex;
    BOOL blockCreated = FALSE;
    s32 buddyIndex;
    u8 slotIndex;
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        blockHasEmblem[blockIndex] = 0;
    }
    for (playerIndex = 0; playerIndex < 8; playerIndex++) {
        buddyIndexOfPlayer[playerIndex] = -1;
        if (gStruct217AA00->field0 == 2) {
            ownIndex = gStruct217AA00->mOwnIndex;
        } else {
            ownIndex = 0;
        }
        if (playerIndex != (u16) ownIndex) {
            if ((gStruct217AA00->field457 & (1 << gStruct217AA00->field1E8C[playerIndex])) == 0) {
                if ((gStruct217AA00->mParticipantMask & (1 << playerIndex)) != 0) {
                    playerEntry = &gStruct217AA00->field45C[playerIndex];
                    buddyIndex = SetBuddyRecordFromPlayer(playerEntry, 1);
                    if (buddyIndex != -1) {
                        if (playerEntry->field214 != 0) {
                            buddyIndexOfPlayer[playerIndex] = buddyIndex;
                            blockHasEmblem[buddyIndex / 5] = 1;
                        }
                    }
                }
            }
        }
    }
    savd_writeNkfl(gSaveData->mBuddyRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        if (blockHasEmblem[blockIndex] != 0) {
            blockData = gSaveData->mEmblemBlockData;
            if (savd_isBitSet(blockIndex, &gSaveData->mFirstBlock->field2C[2], 2) != 0) {
                savd_readNkfe(blockData, blockIndex);
                if (gSaveCore->mBackupEnabled != 0) {
                    CARD_WaitBackupAsync();
                }
            } else {
                MI_CpuFill8(blockData, 0, 0xb00);
                savd_setBit(blockIndex, &gSaveData->mFirstBlock->field2C[2], 2);
                blockCreated = TRUE;
            }
            firstBuddyIndex = blockIndex * 5;
            endBuddyIndex = (blockIndex + 1) * 5;
            for (k = 0; k < 8; k++) {
                buddyIndex = buddyIndexOfPlayer[k];
                if (buddyIndex >= firstBuddyIndex && buddyIndex < endBuddyIndex) {
                    slotIndex = buddyIndex % 5;
                    blockData->mFilledBits |= 1 << slotIndex;
                    MI_CpuCopy8((u8 *) &gStruct217AA00->field45C[k] + 0x14, blockData->mEmblems[slotIndex], 0x200);
                }
            }
            savd_writeNkfe(blockData, blockIndex);
            if (gSaveCore->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    if (blockCreated != FALSE) {
        savd_writeNksy(gSaveData->mFirstBlock);
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    savd_endOperation();
}

void CopyWiFiOtherEmblemsToBlocks(void) {
    u8 blockIndex;
    u16 playerIndex;
    Unk0217aa00_45c *playerRecordData;
    u8 blockHasEmblem[12];
    s8 buddyIndexOfPlayer[4];
    EmblemBlockData *blockData;
    s32 firstBuddyIndex;
    s32 endBuddyIndex;
    u8 slotIndex;
    u16 k;
    u8 *filledBits;
    s32 buddyIndex;
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        blockHasEmblem[blockIndex] = 0;
    }
    for (playerIndex = 0; playerIndex < 4; playerIndex++) {
        buddyIndexOfPlayer[playerIndex] = -1;
        if (playerIndex != func_ov000_0219bb50()) {
            playerRecordData = GetWiFiSessionPlayerRecordData(playerIndex & 0xff);
            if (playerRecordData != NULL) {
                buddyIndex = SetBuddyRecordFromPlayer(playerRecordData, 0);
                if (buddyIndex != -1) {
                    if (playerRecordData->field214 != 0) {
                        buddyIndexOfPlayer[playerIndex] = buddyIndex;
                        blockHasEmblem[buddyIndex / 5] = 1;
                    }
                }
            }
        }
    }
    savd_writeNkfl(gSaveData->mBuddyRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        if (blockHasEmblem[blockIndex] != 0) {
            blockData = gSaveData->mEmblemBlockData;
            if (savd_isBitSet(blockIndex, &gSaveData->mFirstBlock->field2C[2], 2) != 0) {
                savd_readNkfe(blockData, blockIndex);
                if (gSaveCore->mBackupEnabled != 0) {
                    CARD_WaitBackupAsync();
                }
            } else {
                MI_CpuFill8(blockData, 0, 0xb00);
                savd_setBit(blockIndex, &gSaveData->mFirstBlock->field2C[2], 2);
            }
            firstBuddyIndex = blockIndex * 5;
            endBuddyIndex = (blockIndex + 1) * 5;
            filledBits = (u8 *) blockData + 4;
            for (k = 0; k < 4; k++) {
                buddyIndex = buddyIndexOfPlayer[k];
                if (buddyIndex >= firstBuddyIndex && buddyIndex < endBuddyIndex) {
                    slotIndex = buddyIndex % 5;
                    *filledBits = *filledBits | (1 << slotIndex);
                    MI_CpuCopy8((u8 *) GetWiFiSessionPlayerRecordData(k & 0xff) + 0x14, blockData->mEmblems[slotIndex],
                                0x200);
                }
            }
            savd_writeNkfe(blockData, blockIndex);
            if (gSaveCore->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    savd_endOperation();
}

static inline s32 func_0205e5c4_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

void StartCopyOtherEmblems(s32 useConnection) {
    void (*copyFunction)(void);
    BOOL connectionReady;
    s32 d;
    if (useConnection != 0) {
        connectionReady = FALSE;
        d = func_0205e5c4_inline();
        if (d != 0) {
            if (gStruct217AA00->field4 != 13) {
                connectionReady = TRUE;
            }
        }
        if (connectionReady == FALSE) {
            return;
        }
        copyFunction = CopyOtherPlayerEmblemsToBlocks;
    } else {
        d = 0;
        if (gStruct217D384 != NULL) {
            if (gStruct217D384->mHeapCreated != FALSE) {
                d = 1;
            }
        }
        if (d == 0) {
            return;
        }
        copyFunction = CopyWiFiOtherEmblemsToBlocks;
    }
    savd_beginOperation();
    bgwkr_enqueueTask(copyFunction);
    gBgWkrState->mRunRequested = 1;
}

static inline u8 func_0205e548_inline(void *recordOut) {
    u8 filledCount = 0;
    u8 recordIndex = 0;
    do {
        if (recordOut != 0) {
            MI_CpuCopy8(&gSaveData->mBuddyRecordBlock->mRecords[recordIndex], recordOut, 0x24);
        }
        if (gSaveData->mBuddyRecordBlock->mRecords[recordIndex].mFilled != 0) {
            filledCount = filledCount + 1;
        }
        recordIndex = recordIndex + 1;
    } while (recordIndex < 60);
    return filledCount;
}

u8 CountEmblemEntries(void) {
    return func_0205e548_inline(0);
}

#pragma thumb on

void ghostdef_create(void) {
    ghost_create(proc_getHeap(proc_getCurrent()));
}

void ghostdef_finish(void) {
    ghost_finish();
}

void ghostdef_vblank(void) {
    ghost_vblank();
}

void ghostdef_render(u32 sceneNumbers) {
    ghost_render(sceneNumbers);
}

s32 ghost_run(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = ghost_sceneDef;

    scene_runScene(sceneNumbers, &callbacks);
    return 0;
}

#pragma thumb off

static inline s32 func_0205e2cc_inline(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void area_initMissionRivalPassAreas(void *heap) {
    u16 shapeCount;
    u16 i;
    u16 entryIndex;
    u16 shapeIndex;
    u16 entryCount;
    CourseMapShape *courseMapShape;
    ShapeMapObjectCount *entry;
    s32 u;
    s32 v;
    s32 w;
    s32 y;
    shapeCount = gMapData->mShapeCount;
    entryCount = 0;
    area_sMissionRivalPassAreaStatus = heap_alloc(heap, 8);
    for (i = 0; i < shapeCount; i++) {
        if (mdat_getAreaEntryByIndex(i)->mKind == 5) {
            entryCount = entryCount + 1;
        }
    }
    if (entryCount != 0) {
        area_sMissionRivalPassAreaStatus->mEntries = heap_alloc(heap, entryCount * 0xc);
    }
    entryIndex = 0;
    area_sMissionRivalPassAreaStatus->mEntryCount = entryCount;
    for (shapeIndex = 0; shapeIndex < shapeCount; shapeIndex++) {
        courseMapShape = mdat_getAreaEntryByIndex(shapeIndex);
        if (courseMapShape->mKind == 5) {
            entry = &area_sMissionRivalPassAreaStatus->mEntries[entryIndex];
            entry->mShapeIndex = shapeIndex;
            u = 0;
            switch (courseMapShape->mShapeKind) {
                case 0:
                    u = func_0205e2cc_inline(mdat_getAreaBoxXZHalfScale(), courseMapShape->mScale.x);
                    v = func_0205e2cc_inline(mdat_getAreaBoxYScale(), courseMapShape->mScale.y) >> 1;
                    y = func_0205e2cc_inline(mdat_getAreaBoxXZHalfScale(), courseMapShape->mScale.z);
                    w = func_0205e2cc_inline(u, u) + func_0205e2cc_inline(v, v);
                    y = func_0205e2cc_inline(y, y);
                    u = FX_Sqrt(y + w);
                    break;
                case 1:
                    u = func_0205e2cc_inline(mdat_getAreaCylinderHalfScale(), courseMapShape->mScale.x);
                    break;
            }
            entry->mRadius = u;
            entry->mMapObjectCount = 0;
            entry->mIncreaseCount = 0;
            entryIndex = entryIndex + 1;
        }
    }
}
