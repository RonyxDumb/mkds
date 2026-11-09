#include "Main/Unknown/code_020566a8.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteSlotGhostRecord(u32 index, SlotGhostRecord *source) {
    int slotBit;
    SlotGhostRecord *destination;
    destination = data_0217aa08->mSlotGhostRecords[0];
    source->mHead.mUnk_08 = source->mHead.mUnk_08 & 0xfffffffe | 1;
    MI_CpuCopy8(source, destination, (0x00001000u));
    WriteBackupSlotGhost(index, destination);
    slotBit = IsSlotGhostBitSet(index);
    if (slotBit == 0) {
        SetBitArrayBit(index, data_0217aa08->mFirstBlock->mSlotGhostBits, 2);
        StartWriteBackupFirstBlock();
    }
}

#pragma thumb off
