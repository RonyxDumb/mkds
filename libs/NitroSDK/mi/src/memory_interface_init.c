#include "memory_interface_init.h"
#include "dma_copy_fill_wait.h"
#include "wram_bank_select.h"

void MI_Init(void) {
    MI_SetWramBank(3);
    MI_StopDma(0);
}
