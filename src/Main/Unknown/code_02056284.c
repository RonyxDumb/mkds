#include "Main/Unknown/code_02056284.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

Unk0202ddd8 *LoadGhostRecordFile(const char *path) {
    int result;
    result = ReadWholeFile(path, data_0217aa08->mSlotGhostRecords[1], (0x00001000u));
    if (result != 0) {
        return data_0217aa08->mSlotGhostRecords[1];
    }
    return NULL;
}

#pragma thumb off
