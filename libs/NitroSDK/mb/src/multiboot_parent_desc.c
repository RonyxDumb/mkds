#include "multiboot_parent_desc.h"
#include "multiboot_game_info_beacon.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"

#pragma thumb on

u32 MB_FakeGetParentBssDesc(u32 index, WMBssDesc *destination) {
    u32 savedInterrupts;
    MBGameInfoRecvList *entry;
    if (16 <= index) {
        return 0;
    }
    savedInterrupts = ((s64) Os_DisableIrq());
    entry = MB_GetGameInfoRecvList(index);
    if (entry == NULL) {
        Os_RestoreIrq(savedInterrupts);
        return 0;
    }
    Mem_CpuCopy8(&entry->mScanBuffer, destination, sizeof(WMBssDesc));
    Os_RestoreIrq(savedInterrupts);
    return 1;
}

#pragma thumb off
