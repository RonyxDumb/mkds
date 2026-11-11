#include "Main/Unknown/code_0204f644.h"
#include "Main/Unknown/code_02036820.h"
#include "code_02003be0.h"
#include "fs_file.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void UncompressPendingFile(void) {
    s16 index = gConnectionWork->mNextLoadIndex - 1;
    u32 uncompressedSize = *gConnectionWork->mBlockEntries[index].mBuffer >> 8;
    void *destination = gConnectionWork->mBlockEntries[index].mUncompressedBuffer;
    if (destination == NULL) {
        destination = HeapAllocAligned(gConnectionWork->mBlockEntries[index].mHeap, uncompressedSize, 0x20);
        *gConnectionWork->mBlockEntries[index].mDataOutput = destination;
    }
    MI_UncompressLZ8(gConnectionWork->mBlockEntries[index].mBuffer, destination);
    gConnectionWork->mBlockEntries[index].mUncompressPending = 0;
}

// Staged: one step per call; returns TRUE when no queued file is left.
BOOL LoadPendingFiles(void) {
    u16 nextIndex = gConnectionWork->mNextLoadIndex;
    s16 previousIndex = nextIndex - 1;
    FSFile *file = &gConnectionWork->mFile;
    void *workOrPath;
    s32 size;
    u32 *buffer;
    if (((file->mStat & 1) ? 1 : 0) != 0) {
        return FALSE;
    }
    if (previousIndex >= 0 && gConnectionWork->mBlockEntries[previousIndex].mUncompressPending != 0) {
        if (gThreadFunctionQueue->mRunRequested != 0) {
            return FALSE;
        }
        QueueThreadFunction(UncompressPendingFile);
        gThreadFunctionQueue->mRunRequested = 1;
        return FALSE;
    }
    if (nextIndex >= 12 || gConnectionWork->mBlockEntries[nextIndex].mPath == 0) {
        return TRUE;
    }
    workOrPath = &gConnectionWork->mBlockEntries[nextIndex].mPath;
    if (((file->mStat & 0x10) ? 1 : 0) != 0) {
        FS_CloseFile(file);
    }
    FS_InitFile(file);
    if (FS_OpenFile(file, workOrPath) != 0) {
        workOrPath = gConnectionWork;
        size = file->mProp.p.mUnk_08 - file->mProp.p.mUnk_04;
        buffer = ((ConnectionWork *) workOrPath)->mBlockEntries[nextIndex].mBuffer;
        if (buffer == NULL) {
            buffer = HeapAllocAligned(gConnectionWork->mBlockEntries[nextIndex].mHeap, size, 0x20);
            *gConnectionWork->mBlockEntries[nextIndex].mDataOutput = buffer;
        }
        FS_ReadFileAsync(file, buffer, size);
        gConnectionWork->mNextLoadIndex++;
    }
    return FALSE;
}

#pragma thumb off
