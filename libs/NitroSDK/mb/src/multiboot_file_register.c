#include "multiboot_file_register.h"
#include "multiboot_task_thread.h"
#include "multiboot_communication.h"
#include "multiboot_game_entry.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"

const u32 MBi_defaultLoadSegList[3] = {MULTIBOOT_SEGMENT_HEADER_AREA, MULTIBOOT_SEGMENT_MAIN_RAM,
                                       MULTIBOOT_SEGMENT_SUB_RAM};
u8 gNextSeqNoFixed;

#pragma thumb on

u32 MB_RegisterFile(void *rangeTable, SegmentBuffer *source) {
    u32 entryIndex;
    u32 savedInterrupts;
    u32 entryOffset;
    MB_CommPWork *work;
    MBDownloadFileInfo *record;
    MBGameRegistry *registry;
    u8 slotIndex;
    entryIndex = 0xff;
    savedInterrupts = OS_DisableInterrupts();
    if (MBi_IsStarted() == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    work = mbc;
    if (work->mEntryCount + 1 > 0x10) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    for (slotIndex = 0; slotIndex < 0x10; slotIndex++) {
        if ((OFFSET_PTR(MB_CommPWork, work, slotIndex * 0x5d4))->mGameReg == rangeTable) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        if ((OFFSET_PTR(MB_CommPWork, work, slotIndex * 0x5d4))->mEntryUsed == 0) {
            entryIndex = slotIndex;
            break;
        }
    }
    if (slotIndex == 0x10) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    entryOffset = entryIndex * 0x5d4;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mGameReg = rangeTable;
    record = (MBDownloadFileInfo *) (mbc->mFileInfo + entryOffset);
    MBi_MakeDownloadFileInfo(record, source);
    registry = rangeTable;
    MI_CpuCopy8(registry->mUserParam, record->mReserved, sizeof(record->mReserved));
    if (MBi_MakeBlockInfoTable((MB_BlockInfoTable *) (mbc->mBlockInfoTable + entryOffset), record) == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    MBi_MakeGameInfo((GameInfoEntry *) (mbc->mFileInfo + 0xe4 + entryOffset), rangeTable, (const u8 *) &mbc->mUser);
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mFileNo = entryIndex;
    MB_AddGameInfo((GameInfoEntry *) (mbc->mFileInfo + 0xe4 + entryOffset));
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mSeqNoFixed = gNextSeqNoFixed++;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mGameinfoChildBmp = 1;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mSrcAdr = source;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mCacheList = &source->mCacheList;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mCardMapping = source->mCardMapping;
    if ((OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mCacheList->mList[3].mState != 0) {
        if (MBi_IsTaskAvailable() == 0) {
            MBi_InitTaskInfo(&mbc->mCurTask);
            MBi_InitTaskThread(&mbc->mTaskWork, 0x800);
        }
    }
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mEntryUsed = 1;
    mbc->mEntryCount++;
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

void MBi_MakeDownloadFileInfo(MBDownloadFileInfo *record, SegmentBuffer *source) {
    u32 nextAddress;
    u8 *headerTail;
    const u32 *kinds;
    MbSegmentInfo *range;
    s32 rangeIndex;
    nextAddress = 0x022c0000;
    headerTail = source->mAuthCode;
    record->mArm9EntryAddr = source->mMainEntryAddress;
    record->mArm7EntryAddr = source->mSubEntryAddress;
    range = record->mSeg;
    kinds = MBi_defaultLoadSegList;
    for (rangeIndex = 0; rangeIndex < 3; rangeIndex++) {
        MBi_SetSegmentInfo(source, kinds, range, &nextAddress);
        range++;
        kinds++;
    }
    MI_CpuCopy8(headerTail, record->mAuthCode, sizeof(record->mAuthCode));
}

void MBi_SetSegmentInfo(SegmentBuffer *source, const u32 *kindWord, MbSegmentInfo *range, u32 *nextAddress) {
    u32 outOfBounds;
    u32 useNextAddress;
    u32 *pair;
    u32 end;
    switch (*kindWord) {
        case MULTIBOOT_SEGMENT_MAIN_RAM:
            pair = source->mMainRamRange;
            if (source->mMainRamRange[0] >= 0x02000000 && source->mMainRamRange[0] < 0x022c0000 &&
                source->mMainRamRange[0] + pair[1] <= 0x022c0000) {
                range->mSize = pair[1];
                range->mLoadAddr = pair[0];
                range->mRecvAddr = range->mLoadAddr;
                range->mTarget &= ~1;
                return;
            }
            OS_Terminate();
            return;
        case MULTIBOOT_SEGMENT_SUB_RAM:
            outOfBounds = 0;
            useNextAddress = 0;
            pair = source->mSubRamRange;
            end = source->mSubRamRange[0] + pair[1];
            if (source->mSubRamRange[0] >= 0x02000000 && source->mSubRamRange[0] < 0x023fe800) {
                if (end > 0x02300000) {
                    if (end < 0x023fe800 && pair[1] <= 0x40000) {
                        useNextAddress = 1;
                    } else {
                        outOfBounds = 1;
                    }
                }
            } else if (source->mSubRamRange[0] >= 0x037f8000 && source->mSubRamRange[0] < 0x0380f000) {
                if (end <= 0x0380f000) {
                    useNextAddress = 1;
                } else {
                    outOfBounds = 1;
                }
            } else {
                outOfBounds = 1;
            }
            if (outOfBounds == 1) {
                OS_Terminate();
            }
            range->mSize = pair[1];
            range->mLoadAddr = pair[0];
            if (useNextAddress == 0) {
                range->mRecvAddr = range->mLoadAddr;
            } else {
                range->mRecvAddr = *nextAddress;
                *nextAddress = *nextAddress + range->mSize;
            }
            range->mTarget = (range->mTarget & ~1) | 1;
            return;
        case MULTIBOOT_SEGMENT_HEADER_AREA:
            range->mSize = MULTIBOOT_HEADER_AREA_SIZE;
            range->mLoadAddr = MULTIBOOT_HEADER_AREA_ADDRESS;
            range->mRecvAddr = range->mLoadAddr;
            range->mTarget &= ~1;
            return;
    }
}

static inline struct MB_CommPWork *GetMbCommPWork(void) {
    return mbc;
}

u32 MBi_MakeBlockInfoTable(MB_BlockInfoTable *chunkTable, MBDownloadFileInfo *record) {
    u32 offset;
    u16 nextChunk;
    u8 rangeIndex;
    MbSegmentInfo *range;
    u16 *chunkStarts;
    chunkStarts = chunkTable->mChunkStarts;
    offset = 0;
    if (record == NULL) {
        return 0;
    }
    for (rangeIndex = 0; rangeIndex < 3; rangeIndex++) {
        chunkTable->mRangeOffsets[rangeIndex] = offset;
        offset += record->mSeg[rangeIndex].mSize;
    }
    chunkStarts[0] = 0;
    for (rangeIndex = 0; rangeIndex < 3; rangeIndex++) {
        range = &record->mSeg[rangeIndex];
        nextChunk = chunkStarts[rangeIndex] + (u16) ((range->mSize + mbc->mBlockSizeMax - 1) / mbc->mBlockSizeMax);
        if (IsAbleToLoad(rangeIndex, range->mLoadAddr, range->mSize) == 0) {
            return 0;
        }
        if (rangeIndex < 2) {
            chunkStarts[rangeIndex + 1] = nextChunk;
        } else {
            chunkTable->mChunkStarts[3] = nextChunk;
        }
    }
    return 1;
}

BOOL MBi_get_blockinfo(MB_BlockInfo *result, void *chunkTableData, u16 chunk, void *recordData) {
    u32 offset;
    MBDownloadFileInfo *record;
    MbSegmentInfo *range;
    MB_BlockInfoTable *chunkTable;
    s8 rangeIndex;
    chunkTable = chunkTableData;
    record = recordData;
    if (chunk >= chunkTable->mChunkStarts[3]) {
        return FALSE;
    }
    for (rangeIndex = 2; rangeIndex >= 0; rangeIndex--) {
        if (chunk >= chunkTable->mChunkStarts[rangeIndex]) {
            break;
        }
    }
    if (rangeIndex < 0) {
        return FALSE;
    }
    offset = (chunk - chunkTable->mChunkStarts[rangeIndex]) * GetMbCommPWork()->mBlockSizeMax;
    range = &record->mSeg[rangeIndex];
    result->mSize = range->mSize - offset;
    if (result->mSize > mbc->mBlockSizeMax) {
        result->mSize = mbc->mBlockSizeMax;
    }
    result->mOffset = offset + chunkTable->mRangeOffsets[rangeIndex];
    result->mChildAddress = offset + range->mRecvAddr;
    result->mSegmentNo = rangeIndex;
    return TRUE;
}

u32 MBi_IsAbleToRecv(u32 rangeIndex, u32 address, u32 size) {
    switch (MBi_defaultLoadSegList[rangeIndex]) {
        case MULTIBOOT_SEGMENT_HEADER_AREA:
            if (address >= MULTIBOOT_HEADER_AREA_ADDRESS &&
                address + size <= MULTIBOOT_HEADER_AREA_ADDRESS + MULTIBOOT_HEADER_AREA_SIZE) {
                return 1;
            }
            break;
        case MULTIBOOT_SEGMENT_MAIN_RAM:
            if (address >= 0x02000000 && address + size <= 0x022c0000) {
                return 1;
            }
            break;
        case MULTIBOOT_SEGMENT_SUB_RAM:
            if (address >= 0x022c0000 && address + size <= 0x02300000) {
                return 1;
            }
            if (address >= 0x02000000 && address + size <= 0x02300000) {
                return 1;
            }
            break;
        default:
            return 0;
    }
    return 0;
}

u32 IsAbleToLoad(u32 rangeIndex, u32 address, u32 size) {
    u32 end;
    switch (MBi_defaultLoadSegList[rangeIndex]) {
        case MULTIBOOT_SEGMENT_MAIN_RAM:
        case MULTIBOOT_SEGMENT_HEADER_AREA:
            return MBi_IsAbleToRecv(rangeIndex, address, size);
        case MULTIBOOT_SEGMENT_SUB_RAM:
            if (address >= 0x02000000 && address < 0x023fe800) {
                end = address + size;
                if (address < 0x02300000 && end > 0x02300000) {
                    return 0;
                }
                if (end <= 0x02300000) {
                    return 1;
                }
                if (end < 0x023fe800 && size <= 0x40000) {
                    return 1;
                }
                return 0;
            }
            if (address >= 0x037f8000 && address < 0x0380f000) {
                if (address + size <= 0x0380f000) {
                    return 1;
                }
                return 0;
            }
            break;
        default:
            return 0;
    }
    return 0;
}

void MB_ReadMultiBootParentBssDesc(WMBssDesc *bssDesc, u16 parentMaxSize, u16 childMaxSize, u32 ksFlag, u32 flagTwo) {
    u32 csAttribute;
    u32 ksAttribute;
    BootInfo *bootInfo = gBootInfo;
    MI_CpuCopy8(bootInfo->mBootType == BOOT_TYPE_MULTIBOOT ? bootInfo->mParentBssDesc : NULL, bssDesc, 0x3c);
    bssDesc->mGameInfoLength = MULTIBOOT_BEACON_GAME_INFO_LENGTH;
    bssDesc->mGameInfo.mGgid = bssDesc->mSsidHalfwords[0] | (bssDesc->mSsidHalfwords[1] << 16);
    bssDesc->mGameInfo.mTgid = bssDesc->mSsidHalfwords[2];
    bssDesc->mGameInfo.mUserGameInfoLength = 0;
    bssDesc->mGameInfo.mParentMaxSize = parentMaxSize;
    bssDesc->mGameInfo.mChildMaxSize = childMaxSize;
    csAttribute = 0;
    if (flagTwo != 0) {
        csAttribute = WIRELESS_ATTRIBUTE_CS_FLAG;
    }
    if (ksFlag != 0) {
        ksAttribute = WIRELESS_ATTRIBUTE_KS_FLAG;
    } else {
        ksAttribute = 0;
    }
    bssDesc->mGameInfo.mAttribute = ksAttribute | csAttribute | WIRELESS_ATTRIBUTE_ENTRY;
}

#pragma thumb off
