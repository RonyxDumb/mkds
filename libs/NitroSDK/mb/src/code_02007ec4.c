#include "code_02007ec4.h"
#include "code_0200aeb4.h"
#include "code_02009928.h"
#include "code_020091fc.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

#pragma thumb on

u32 MB_RegisterFile(void *rangeTable, SegmentBuffer *source) {
    u32 entryIndex;
    u32 savedInterrupts;
    u32 entryOffset;
    MB_CommPWork *work;
    MBDownloadFileInfo *record;
    u8 i;
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
    for (i = 0; i < 0x10; i++) {
        if ((OFFSET_PTR(MB_CommPWork, work, i * 0x5d4))->mGameReg == rangeTable) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        if ((OFFSET_PTR(MB_CommPWork, work, i * 0x5d4))->mEntryUsed == 0) {
            entryIndex = i;
            break;
        }
    }
    if (i == 0x10) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    entryOffset = entryIndex * 0x5d4;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mGameReg = rangeTable;
    record = (MBDownloadFileInfo *) (mbc->mUnk_1788 + entryOffset);
    MBi_MakeDownloadFileInfo(record, source);
    MI_CpuCopy8((u8 *) rangeTable + 0x1c, record->mReserved, 0x20);
    if (MBi_MakeBlockInfoTable((MB_BlockInfoTable *) (mbc->mUnk_1d2c + entryOffset), record) == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    MBi_MakeGameInfo((GameInfoEntry *) (mbc->mUnk_1788 + 0xe4 + entryOffset), rangeTable, (const u8 *) &mbc->mUser);
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mUnk_1d21 = entryIndex;
    MB_AddGameInfo((GameInfoEntry *) (mbc->mUnk_1788 + 0xe4 + entryOffset));
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mUnk_1d1f = data_0216fc30++;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mGameinfoChildBmp = 1;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mSrcAdr = source;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mCacheList = &source->mUnk_1e8;
    (OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mCardMapping = source->mUnk_258;
    if ((OFFSET_PTR(MB_CommPWork, mbc, entryOffset))->mCacheList->mList[3].mState != 0) {
        if (MBi_IsTaskAvailable() == 0) {
            MBi_InitTaskInfo(mbc->mCurTask);
            MBi_InitTaskThread(&mbc->mUnk_74e0, 0x800);
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
    u32 *kinds;
    MbSegmentInfo *range;
    s32 i;
    nextAddress = 0x022c0000;
    headerTail = source->mUnk_160;
    record->mArm9EntryAddr = source->mUnk_024;
    record->mArm7EntryAddr = source->mUnk_034;
    range = record->mSeg;
    kinds = MBi_defaultLoadSegList;
    for (i = 0; i < 3; i++) {
        MBi_SetSegmentInfo(source, kinds, range, &nextAddress);
        range++;
        kinds++;
    }
    MI_CpuCopy8(headerTail, record->mAuthCode, 0x88);
}

void MBi_SetSegmentInfo(SegmentBuffer *source, u32 *kindWord, MbSegmentInfo *range, u32 *nextAddress) {
    u32 outOfBounds;
    u32 useNextAddress;
    u32 *pair;
    u32 end;
    switch (*kindWord) {
        case 0:
            pair = source->mUnk_028;
            if (source->mUnk_028[0] >= 0x02000000 && source->mUnk_028[0] < 0x022c0000 &&
                source->mUnk_028[0] + pair[1] <= 0x022c0000) {
                range->mSize = pair[1];
                range->mLoadAddr = pair[0];
                range->mRecvAddr = range->mLoadAddr;
                range->mTarget &= ~1;
                return;
            }
            OS_Terminate();
            return;
        case 1:
            outOfBounds = 0;
            useNextAddress = 0;
            pair = source->mUnk_038;
            end = source->mUnk_038[0] + pair[1];
            if (source->mUnk_038[0] >= 0x02000000 && source->mUnk_038[0] < 0x023fe800) {
                if (end > 0x02300000) {
                    if (end < 0x023fe800 && pair[1] <= 0x40000) {
                        useNextAddress = 1;
                    } else {
                        outOfBounds = 1;
                    }
                }
            } else if (source->mUnk_038[0] >= 0x037f8000 && source->mUnk_038[0] < 0x0380f000) {
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
        case 2:
            range->mSize = 0x160;
            range->mLoadAddr = 0x027ffe00;
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
    u8 i;
    MbSegmentInfo *range;
    u16 *chunkStarts;
    chunkStarts = chunkTable->mChunkStarts;
    offset = 0;
    if (record == NULL) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        chunkTable->mRangeOffsets[i] = offset;
        offset += record->mSeg[i].mSize;
    }
    chunkStarts[0] = 0;
    for (i = 0; i < 3; i++) {
        range = &record->mSeg[i];
        nextChunk = chunkStarts[i] + (u16) ((range->mSize + mbc->mBlockSizeMax - 1) / mbc->mBlockSizeMax);
        if (IsAbleToLoad(i, range->mLoadAddr, range->mSize) == 0) {
            return 0;
        }
        if (i < 2) {
            chunkStarts[i + 1] = nextChunk;
        } else {
            chunkTable->mChunkStarts[3] = nextChunk;
        }
    }
    return 1;
}

BOOL MBi_get_blockinfo(MB_BlockInfo *result, void *b, u16 chunk, void *d) {
    u32 offset;
    MBDownloadFileInfo *record;
    MbSegmentInfo *range;
    MB_BlockInfoTable *chunkTable;
    s8 i;
    chunkTable = b;
    record = d;
    if (chunk >= chunkTable->mChunkStarts[3]) {
        return FALSE;
    }
    for (i = 2; i >= 0; i--) {
        if (chunk >= chunkTable->mChunkStarts[i]) {
            break;
        }
    }
    if (i < 0) {
        return FALSE;
    }
    offset = (chunk - chunkTable->mChunkStarts[i]) * GetMbCommPWork()->mBlockSizeMax;
    range = &record->mSeg[i];
    result->mSize = range->mSize - offset;
    if (result->mSize > mbc->mBlockSizeMax) {
        result->mSize = mbc->mBlockSizeMax;
    }
    result->mOffset = offset + chunkTable->mRangeOffsets[i];
    result->mChildAddress = offset + range->mRecvAddr;
    result->mSegmentNo = i;
    return TRUE;
}

u32 MBi_IsAbleToRecv(u32 rangeIndex, u32 address, u32 size) {
    switch (MBi_defaultLoadSegList[rangeIndex]) {
        case 2:
            if (address >= 0x027ffe00 && address + size <= 0x027fff60) {
                return 1;
            }
            break;
        case 0:
            if (address >= 0x02000000 && address + size <= 0x022c0000) {
                return 1;
            }
            break;
        case 1:
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
        case 0:
        case 2:
            return MBi_IsAbleToRecv(rangeIndex, address, size);
        case 1:
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
    Unk027ffc40 *bootInfo = gBootInfo;
    MI_CpuCopy8(bootInfo->mUnk_00 == 2 ? bootInfo->mUnk_02 : NULL, bssDesc, 0x3c);
    bssDesc->mGameInfoLength = 0x10;
    bssDesc->mGameInfo.mGgid = bssDesc->mSsidHalfwords[0] | (bssDesc->mSsidHalfwords[1] << 16);
    bssDesc->mGameInfo.mTgid = bssDesc->mSsidHalfwords[2];
    bssDesc->mGameInfo.mUserGameInfoLength = 0;
    bssDesc->mGameInfo.mParentMaxSize = parentMaxSize;
    bssDesc->mGameInfo.mChildMaxSize = childMaxSize;
    csAttribute = 0;
    if (flagTwo != 0) {
        csAttribute = 8;
    }
    if (ksFlag != 0) {
        ksAttribute = 4;
    } else {
        ksAttribute = 0;
    }
    bssDesc->mGameInfo.mAttribute = ksAttribute | csAttribute | 1;
}

#pragma thumb off
