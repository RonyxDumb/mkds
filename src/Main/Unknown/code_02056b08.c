#include "Main/Unknown/code_02056b08.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void savd_setNkgpEntry(int cup, int engineClass, TimeRecord *record) {
    savd_packNkgpEntry(&gSaveData->mGrandPrixRecordBlock->mRecords[engineClass][cup], record);
}

#pragma thumb off
