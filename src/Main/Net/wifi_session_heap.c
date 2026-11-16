#include "Main/Net/wifi_session_heap.h"
#include "Main/System/heap.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "reset_interrupts_halt.h"
#include "Main/Net/wifi_session.h"

// Allocator registered with the net layer; the first argument is unused; interrupts off.
void *WiFiSessionHeapAlloc(u32 unused, u32 size, s32 alignment) {
    u32 enabled;
    void *memory;

    enabled = Os_DisableIrq();
    memory = Mem_AllocateHeapAligned(g_GlobalB->mHeap, size, alignment);
    Os_RestoreIrq(enabled);
    return memory;
}

void WiFiSessionHeapFree(u32 unused, void *memory, u32 unusedSize) {
    u32 enabled;

    if (memory == NULL) {
        return;
    }
    enabled = Os_DisableIrq();
    Mem_FreeHeap(g_GlobalB->mHeap, memory);
    Os_RestoreIrq(enabled);
}
