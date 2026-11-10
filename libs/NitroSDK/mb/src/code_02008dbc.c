#include "code_02008dbc.h"
#include "code_02008934.h"
#include "code_0214cfe4.h"

#pragma thumb on

void MBi_CheckTGID(u8 *newBlock, int entryIndex) {
    if (*OFFSET_PTR(u16, newBlock, 0x48) != mbrsp->mEntries[entryIndex].mUnk_508) {
        MB_DeleteRecvGameInfoWithoutBssdesc(entryIndex);
        MIi_CpuCopy16(newBlock, mbrsp->mEntries[entryIndex].mScanBuffer, 0xc0);
        MBi_LockScanTarget(entryIndex);
    }
}

#pragma thumb off
