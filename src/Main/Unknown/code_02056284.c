#include "Main/Unknown/code_02056284.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

SlotGhostRecord *LoadGhostRecordFile(const char *path) {
    int result;
    result = ReadWholeFile(path, gBackupBuffers->mSlotGhostRecords[1], (0x00001000u));
    if (result != 0) {
        return gBackupBuffers->mSlotGhostRecords[1];
    }
    return NULL;
}

#pragma thumb off
