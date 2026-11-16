#include "Main/Unknown/code_02056284.h"
#include "Main/System/ArchiveFiles.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

GhostRecord *savd_loadStaffGhost(const char *path) {
    int result;
    result = arc_readFileToEnd(path, gSaveData->mGhostRecords[2], (0x00001000u));
    if (result != 0) {
        return gSaveData->mGhostRecords[2];
    }
    return NULL;
}

#pragma thumb off
