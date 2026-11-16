#include "Main/Unknown/code_020566a8.h"
#include "Main/Save/GhostBits.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Save/BackupGhosts.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void savd_storeDownloadGhost(u32 index, int source) {
    int slotBit;
    GhostRecord *destination;
    destination = gSaveData->mGhostRecords[1];
    *(u32 *) (source + 8) = *(u32 *) (source + 8) & 0xfffffffe | 1;
    MI_CpuCopy8(((u16 *) (u32) source), ((u32 *) destination), (0x00001000u));
    savd_writeNkdg(index, destination);
    slotBit = savd_isDownloadGhostAvailable(index);
    if (slotBit == 0) {
        savd_setBit(index, gSaveData->mFirstBlock->mSlotGhostBits, 2);
        savd_writeNksyAsync();
    }
}

#pragma thumb off
