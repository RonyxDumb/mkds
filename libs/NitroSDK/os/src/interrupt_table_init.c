#include "interrupt_table_init.h"
#include "os_irqHandler.h"

// Empties the queue of threads waiting for an interrupt.
void OS_InitIrqTable(void) {
    OSThreadQueue *queue;

    queue = &OSi_IrqThreadQueue;
    queue->mTail = 0;
    queue->mHead = 0;
}
