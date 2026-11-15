#include "multiboot_parent_desc.h"
#include "mb_gameinfo.h"
#include "reset_interrupt_enable.h"
#include "cpu_copy_fill.h"

#pragma thumb on

u32 MB_FakeGetParentBssDesc(u32 index, WMBssDesc *destination) {
    u32 savedInterrupts;
    MBGameInfoRecvList *entry;
    if (16 <= index) {
        return 0;
    }
    savedInterrupts = ((s64) OS_DisableInterrupts());
    entry = MB_GetGameInfoRecvList(index);
    if (entry == NULL) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    MI_CpuCopy8(&entry->mScanBuffer, destination, sizeof(WMBssDesc));
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

#pragma thumb off
