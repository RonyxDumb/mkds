#include "Main/Unknown/code_020071b4.h"
#include "Main/Unknown/code_02007478.h"
#include "Main/Unknown/code_020075f8.h"
#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214cfe4.h"

#pragma thumb on

u32 func_020072c0(void) {
    Unk020074d8_msg message;
    Unk020072c0_buf v2;
    u8 v11;
    u8 v14;
    Unk0216fdac *work;
    Unk0216fdac *childEntry;
    DataRangeTable *rangeTable;
    DataRange *lowestRange;
    s32 i;
    DataRange *range;
    u8 *v9;
    u32 v10;
    DataRangeLoadJob *loadJob;
    Unk0216fdac *v12;
    Unk0216fdac *v13;
    v12 = data_0216fdac;
    if (v12->mEntryCount == 0) {
        return 21;
    }
    v11 = 0;
    do {
        work = data_0216fdac;
        work->field1525 = (work->field1525 + 1) % 16;
        v13 = (Unk0216fdac *) *(u32 *) &data_0216fdac;
        childEntry = OFFSET_PTR(Unk0216fdac, v13, v13->field1525 * 0x5d4);
        if (childEntry->mEntryUsed != 0 && childEntry->field1D4C != 0) {
            break;
        }
        v11++;
    } while (v11 < 16);
    if (v11 == 16) {
        return 21;
    }
    func_02007154(v13->field1525);
    work = data_0216fdac;
    childEntry = OFFSET_PTR(Unk0216fdac, work, work->field1525 * 0x5d4);
    if (MBi_get_blockinfo(&v2, work->field1D2C + work->field1525 * 0x5d4, childEntry->field1D48,
                      work->field1788 + work->field1525 * 0x5d4) == FALSE) {
        return 21;
    }
    message.field0 = 4;
    work = data_0216fdac;
    message.field2 = work->field1525;
    message.field4 = (OFFSET_PTR(Unk0216fdac, work, work->field1525 * 0x5d4))->field1D48;
    v9 = WriteParentMessage((u8 *) &message, (u8 *) work);
    v14 = v2.fieldC;
    work = data_0216fdac;
    v10 = v2.field8 - ((u32 *) (OFFSET_PTR(Unk0216fdac, work, work->field1525 * 0x5d4))->field1D2C)[v14] +
          (OFFSET_PTR(Unk0216fdac, work, work->field1525 * 0x5d4))->field1D58[v14];
    childEntry = OFFSET_PTR(Unk0216fdac, work, work->field1525 * 0x5d4);
    rangeTable = childEntry->field1D54;
    if (CopyFromDataRanges(rangeTable, v10, v9, v2.field4) == 0) {
        loadJob = (DataRangeLoadJob *) data_0216fdac->field7CE0;
        if (CTRDGi_IsTaskBusy(&loadJob->field0) == 0) {
            if (rangeTable->field0 != 0) {
                range = rangeTable->field30;
                lowestRange = NULL;
                for (i = 0; i < 4; range++, i++) {
                    if (range->fieldC == 2) {
                        if (lowestRange == NULL || lowestRange->mOffset > range->mOffset) {
                            lowestRange = range;
                        }
                    }
                }
                if (lowestRange == NULL) {
                    OS_Terminate();
                }
                rangeTable->field0 = 0;
                lowestRange->fieldC = 1;
                lowestRange->mOffset = v10 & ~0x1f;
                loadJob->mDataRange = lowestRange;
                loadJob->mDataRangeTable = rangeTable;
                CTRDGi_SetTask(&loadJob->field0, (void *) LoadDataRange, NULL, 4);
            }
        }
        return 21;
    }
    work = data_0216fdac;
    return MBi_BlockHeaderEnd(v2.field4 + 6, (OFFSET_PTR(Unk0216fdac, work, work->field1525 * 0x5d4))->field1D4C,
                              (u32) work);
}

int func_020071b4(void) {
    u16 childMasks[6];
    u16 i;
    int result;
    Unk0216fdac *work;
    childMasks[0] = 0;
    MIi_CpuClear16(childMasks[0], &childMasks[1], 10);
    i = 1;
    work = data_0216fdac;
    for (; i <= 15; i++) {
        switch (work->field14E8[i - 1]) {
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
        result = func_020074d8();
    } else {
        result = func_020072c0();
    }
    if (result == 21) {
        result = SendParentMessage(0, 0xffff);
    }
    return result;
}

#pragma thumb off
