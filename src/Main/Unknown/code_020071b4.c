#include "Main/Unknown/code_020071b4.h"
#include "Main/Unknown/code_02007478.h"
#include "Main/Unknown/code_020075f8.h"
#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214cfe4.h"

#pragma thumb on

u32 MBi_CommParentSendBlock(void) {
    ParentMessage message;
    Unk020072c0_buf blockInfo;
    u8 v11;
    u8 segmentNum;
    Unk0216fdac *work;
    Unk0216fdac *childEntry;
    DataRangeTable *rangeTable;
    DataRange *lowestRange;
    s32 i;
    DataRange *range;
    u8 *sendBlock;
    u32 readOffset;
    DataRangeLoadJob *loadJob;
    Unk0216fdac *v12;
    Unk0216fdac *v13;
    v12 = mbc;
    if (v12->mEntryCount == 0) {
        return 21;
    }
    v11 = 0;
    do {
        work = mbc;
        work->mCurFileid = (work->mCurFileid + 1) % 16;
        v13 = (Unk0216fdac *) *(u32 *) &mbc;
        childEntry = OFFSET_PTR(Unk0216fdac, v13, v13->mCurFileid * 0x5d4);
        if (childEntry->mEntryUsed != 0 && childEntry->mPollbmp != 0) {
            break;
        }
        v11++;
    } while (v11 < 16);
    if (v11 == 16) {
        return 21;
    }
    func_02007154(v13->mCurFileid);
    work = mbc;
    childEntry = OFFSET_PTR(Unk0216fdac, work, work->mCurFileid * 0x5d4);
    if (func_0200806c(&blockInfo, work->mUnk_1d2c + work->mCurFileid * 0x5d4, childEntry->mCurrentb,
                      work->mUnk_1788 + work->mCurFileid * 0x5d4) == FALSE) {
        return 21;
    }
    message.mKind = 4;
    work = mbc;
    message.mUnk_02 = work->mCurFileid;
    message.mUnk_04 = (OFFSET_PTR(Unk0216fdac, work, work->mCurFileid * 0x5d4))->mCurrentb;
    sendBlock = WriteParentMessage((u8 *) &message, (u8 *) work);
    segmentNum = blockInfo.mSegmentNo;
    work = mbc;
    readOffset = blockInfo.mOffset -
               ((u32 *) (OFFSET_PTR(Unk0216fdac, work, work->mCurFileid * 0x5d4))->mUnk_1d2c)[segmentNum] +
               (OFFSET_PTR(Unk0216fdac, work, work->mCurFileid * 0x5d4))->mCardMapping[segmentNum];
    childEntry = OFFSET_PTR(Unk0216fdac, work, work->mCurFileid * 0x5d4);
    rangeTable = childEntry->mCacheList;
    if (CopyFromDataRanges(rangeTable, readOffset, sendBlock, blockInfo.mSize) == 0) {
        loadJob = (DataRangeLoadJob *) mbc->mCurTask;
        if (IsWorkerTaskInUse(&loadJob->mUnk_00) == 0) {
            if (rangeTable->mUnk_00 != 0) {
                range = rangeTable->mRanges;
                lowestRange = NULL;
                for (i = 0; i < 4; range++, i++) {
                    if (range->mUnk_0c == 2) {
                        if (lowestRange == NULL || lowestRange->mOffset > range->mOffset) {
                            lowestRange = range;
                        }
                    }
                }
                if (lowestRange == NULL) {
                    OS_Terminate();
                }
                rangeTable->mUnk_00 = 0;
                lowestRange->mUnk_0c = 1;
                lowestRange->mOffset = readOffset & ~0x1f;
                loadJob->mDataRange = lowestRange;
                loadJob->mDataRangeTable = rangeTable;
                QueueWorkerTask(&loadJob->mUnk_00, (void *) LoadDataRange, NULL, 4);
            }
        }
        return 21;
    }
    work = mbc;
    return FlushAndSendMPData(blockInfo.mSize + 6, (OFFSET_PTR(Unk0216fdac, work, work->mCurFileid * 0x5d4))->mPollbmp,
                              (u32) work);
}

int MBi_CommParentSendData(void) {
    u16 childMasks[6];
    u16 i;
    int result;
    Unk0216fdac *work;
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
        result = SendParentMessage(5, childMasks[4]);
    } else if (childMasks[1] != 0) {
        result = SendParentMessage(1, childMasks[1]);
    } else if (childMasks[5] != 0) {
        result = SendParentMessage(6, childMasks[5]);
    } else if (childMasks[3] != 0) {
        result = SendParentMessage(2, childMasks[3]);
    } else if (childMasks[2] != 0) {
        result = MBi_CommParentSendDLFileInfo();
    } else {
        result = MBi_CommParentSendBlock();
    }
    if (result == 21) {
        result = SendParentMessage(0, 0xffff);
    }
    return result;
}

#pragma thumb off
