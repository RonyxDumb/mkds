#include "code_020071b4.h"
#include "code_02007478.h"
#include "code_020075f8.h"
#include "code_02007ec4.h"
#include "code_0200c0d8.h"
#include "mb_data.h"
#include "code_0214cfe4.h"

#pragma thumb on

u32 MBi_CommParentSendBlock(void) {
    ParentMessage message;
    MB_BlockInfo blockInfo;
    u8 v11;
    u8 segmentNum;
    MB_CommPWork *work;
    MB_CommPWork *childEntry;
    MBiCacheList *rangeTable;
    MBiCacheInfo *lowestRange;
    s32 i;
    MBiCacheInfo *range;
    u8 *sendBlock;
    u32 readOffset;
    DataRangeLoadJob *loadJob;
    MB_CommPWork *v12;
    MB_CommPWork *v13;
    v12 = mbc;
    if (v12->mEntryCount == 0) {
        return 21;
    }
    v11 = 0;
    do {
        work = mbc;
        work->mCurFileid = (work->mCurFileid + 1) % 16;
        v13 = (MB_CommPWork *) *(u32 *) &mbc;
        childEntry = OFFSET_PTR(MB_CommPWork, v13, v13->mCurFileid * 0x5d4);
        if (childEntry->mEntryUsed != 0 && childEntry->mPollbmp != 0) {
            break;
        }
        v11++;
    } while (v11 < 16);
    if (v11 == 16) {
        return 21;
    }
    MBi_calc_sendblock(v13->mCurFileid);
    work = mbc;
    childEntry = OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4);
    if (MBi_get_blockinfo(&blockInfo, work->mUnk_1d2c + work->mCurFileid * 0x5d4, childEntry->mCurrentb,
                          work->mUnk_1788 + work->mCurFileid * 0x5d4) == FALSE) {
        return 21;
    }
    message.mKind = 4;
    work = mbc;
    message.mUnk_02 = work->mCurFileid;
    message.mUnk_04 = (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mCurrentb;
    sendBlock = MBi_MakeParentSendBuffer((u8 *) &message, (u8 *) work);
    segmentNum = blockInfo.mSegmentNo;
    work = mbc;
    readOffset = blockInfo.mOffset -
               ((u32 *) (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mUnk_1d2c)[segmentNum] +
               (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mCardMapping[segmentNum];
    childEntry = OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4);
    rangeTable = childEntry->mCacheList;
    if (MBi_ReadFromCache(rangeTable, readOffset, sendBlock, blockInfo.mSize) == 0) {
        loadJob = (DataRangeLoadJob *) mbc->mCurTask;
        if (MBi_IsTaskBusy(&loadJob->mUnk_00) == 0) {
            if (rangeTable->mUnk_00 != 0) {
                range = rangeTable->mList;
                lowestRange = NULL;
                for (i = 0; i < 4; range++, i++) {
                    if (range->mState == 2) {
                        if (lowestRange == NULL || lowestRange->mSrc > range->mSrc) {
                            lowestRange = range;
                        }
                    }
                }
                if (lowestRange == NULL) {
                    OS_Terminate();
                }
                rangeTable->mUnk_00 = 0;
                lowestRange->mState = 1;
                lowestRange->mSrc = readOffset & ~0x1f;
                loadJob->mDataRange = lowestRange;
                loadJob->mDataRangeTable = rangeTable;
                MBi_SetTask(&loadJob->mUnk_00, (void *) MBi_ReloadCache, NULL, 4);
            }
        }
        return 21;
    }
    work = mbc;
    return MBi_BlockHeaderEnd(blockInfo.mSize + 6, (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mPollbmp,
                              (u32) work);
}

int MBi_CommParentSendData(void) {
    u16 childMasks[6];
    u16 i;
    int result;
    MB_CommPWork *work;
    childMasks[0] = 0;
    MIi_CpuClear16(childMasks[0], &childMasks[1], 10);
    i = 1;
    work = mbc;
    for (; i <= 15; i++) {
        switch (work->mPCommState[i - 1]) {
            case 2:
                childMasks[1] |= 1 << i;
                break;
            case 5:
                childMasks[2] |= 1 << i;
                break;
            case 4:
                childMasks[3] |= 1 << i;
                break;
            case 8:
                childMasks[4] |= 1 << i;
                break;
            case 11:
                childMasks[5] |= 1 << i;
                break;
        }
    }
    if (childMasks[4] != 0) {
        result = MBi_CommParentSendMsg(5, childMasks[4]);
    } else if (childMasks[1] != 0) {
        result = MBi_CommParentSendMsg(1, childMasks[1]);
    } else if (childMasks[5] != 0) {
        result = MBi_CommParentSendMsg(6, childMasks[5]);
    } else if (childMasks[3] != 0) {
        result = MBi_CommParentSendMsg(2, childMasks[3]);
    } else if (childMasks[2] != 0) {
        result = MBi_CommParentSendDLFileInfo();
    } else {
        result = MBi_CommParentSendBlock();
    }
    if (result == 21) {
        result = MBi_CommParentSendMsg(0, 0xffff);
    }
    return result;
}

#pragma thumb off
