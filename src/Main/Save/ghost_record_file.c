#include "Main/Save/ghost_record_file.h"
#include "Main/System/archive_slots.h"
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
