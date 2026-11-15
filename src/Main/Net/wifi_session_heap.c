#include "Main/Net/wifi_session_heap.h"
#include "Main/System/heap.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "reset_interrupt_enable.h"
#include "Main/Net/wifi_session.h"

// Allocator registered with the net layer; the first argument is unused; interrupts off.
void *WiFiSessionHeapAlloc(u32 unused, u32 size, s32 alignment) {
    u32 enabled;
    void *memory;

    enabled = OS_DisableInterrupts();
    memory = HeapAllocAligned(gWiFiSession->mHeap, size, alignment);
    OS_RestoreInterrupts(enabled);
    return memory;
}

void WiFiSessionHeapFree(u32 unused, void *memory, u32 unusedSize) {
    u32 enabled;

    if (memory == NULL) {
        return;
    }
    enabled = OS_DisableInterrupts();
    HeapFree(gWiFiSession->mHeap, memory);
    OS_RestoreInterrupts(enabled);
}
