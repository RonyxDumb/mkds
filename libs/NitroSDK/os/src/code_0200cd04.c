#include "code_0200cd04.h"
#include "os_irqHandler.h"

// Empties the queue of threads waiting for an interrupt.
void OS_InitIrqTable(void) {
    OSThreadQueue *queue;

    queue = &OSi_IrqThreadQueue;
    queue->mTail = 0;
    queue->mHead = 0;
}
