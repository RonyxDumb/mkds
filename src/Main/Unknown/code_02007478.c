#include "Main/Unknown/code_02007478.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214d018.h"

#pragma thumb on

u32 MBi_CommParentSendDLFileInfo(void) {
    ParentMessage message;
    u8 requestCounts[16];
    u16 child;
    u32 candidateFile;
    u16 childMask;
    u8 fid;
    Unk0216fdac *work;
    u8 v8;
    u8 *sendBlock;
    childMask = 0;
    candidateFile = -1;
    MI_CpuFill8(requestCounts, 0, 16);
    child = 1;
    work = mbc;
    for (; child <= 15; child++) {
        if (work->mPCommState[child - 1] == 5) {
            requestCounts[work->mChildEntryIndex[child - 1]]++;
        }
    }
    fid = data_usa_02161784;
    v8 = 0;
    do {
        fid = (fid + 1) % 16;
        if ((OFFSET_PTR(Unk0216fdac, work, fid * 0x5d4))->mEntryUsed != 0 && requestCounts[fid] != 0) {
            candidateFile = (s8) fid;
            break;
        }
        v8++;
    } while (v8 < 16);
    if (candidateFile == -1) {
        return 21;
    }
    data_usa_02161784 = candidateFile;
    for (child = 1; child <= 15; child++) {
        if (work->mPCommState[child - 1] == 5 && candidateFile == work->mChildEntryIndex[child - 1]) {
            childMask |= 1 << child;
        }
    }
    message.mKind = 3;
    message.mUnk_02 = candidateFile;
    sendBlock = WriteParentMessage((u8 *) &message, (u8 *) work);
    if (sendBlock != NULL) {
        MI_CpuCopy8(mbc->mUnk_1788 + candidateFile * 0x5d4, sendBlock, 0xe4);
    }
    return FlushAndSendMPData(0xea, childMask, *(u32 *) &mbc);
}

void LoadDataRange(DataRangeLoadJob *job) {
    DataRange *range;
    DataRangeTable *table;
    FSFile file;
    u32 offset;
    range = job->mDataRange;
    table = job->mDataRangeTable;
    FS_InitFile(&file);
    offset = range->mOffset;
    if (FS_OpenFileDirect(&file, FS_FindArchive(table->mArchiveName, table->mUnk_14), offset, offset + range->mSize,
                          -1) != 0) {
        if (range->mSize == FS_ReadFile(&file, range->mData, range->mSize)) {
            range->mUnk_0c = 2;
        }
        FS_CloseFile(&file);
    }
    if (range->mUnk_0c != 2) {
        OS_Terminate();
    }
}

#pragma thumb off
