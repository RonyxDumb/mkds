#pragma once

#include "types.h"
#include "code_02003024.h"
#include "code_0200fc8c.h"
#include "fs_file.h"
#include "code_02003be0.h"
#include "code_02007148.h"
#include "code_0200aeb4.h"
#include "code_02008908.h"

// Object MBi_SetTask runs MBi_ReloadCache on: the member at 0x10 is the entry of MBiCacheList that is read.
typedef struct DataRangeLoadJob {
    /* 00 */ WorkerTask mUnk_00;
    /* 10 */ MBiCacheInfo *mDataRange;
    /* 14 */ MBiCacheList *mDataRangeTable;
} DataRangeLoadJob;

extern u8 data_usa_02161784;

void MBi_ReloadCache(DataRangeLoadJob *job);
u32 MBi_CommParentSendDLFileInfo(void);
