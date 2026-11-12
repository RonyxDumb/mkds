#include "code_0200b1b0.h"
#include "mb_gameinfo.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

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
    MI_CpuCopy8(entry->mScanBuffer, ((u32 *) (u32) destination), 0xc0);
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

#pragma thumb off
