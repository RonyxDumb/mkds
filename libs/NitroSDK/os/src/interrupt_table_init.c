#include "interrupt_table_init.h"
#include "irq_wait_handler.h"

// Empties the queue of threads waiting for an interrupt.
void Os_InitializeIrqThreadQueue(void) {
    OSThreadQueue *queue;

    queue = &g_DTCM;
    queue->mTail = 0;
    queue->mHead = 0;
}
