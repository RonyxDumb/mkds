#include "memory_interface_init.h"
#include "dma_copy_fill_wait.h"
#include "wram_bank_select.h"

void Mem_Initialize(void) {
    Mem_SetWramcnt(3);
    Mem_DmaStop(0);
}
