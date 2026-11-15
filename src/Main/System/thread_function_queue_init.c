#include "Main/System/thread_function_queue_init.h"
#include "Main/System/heap.h"
#include "Main/System/thread_function_queue.h"
#include "Main/MapObjects/data_0217a000.h"
#include "os_thread.h"
#include "Main/Save/ghost_record_file.h"

void (*DequeueThreadFunction(ThreadFunctionQueue *queue))(void) {
    void (**lastFilledSlot)(void) = NULL;
    void (*callback)(void) = NULL;
    s32 filledCount = 0;
    s32 slot;
    u8 startSlot = queue->mNewestIndex;
    do {
        slot = startSlot - filledCount;
        if (slot < 0) {
            slot += 10;
        }
        if (queue->mFunctions[slot] == NULL) {
            break;
        }
        filledCount++;
        lastFilledSlot = &queue->mFunctions[slot];
    } while (filledCount < 10);
    if (lastFilledSlot != NULL) {
        callback = *lastFilledSlot;
        *lastFilledSlot = NULL;
    }
    return callback;
}

void InitThreadFunctionQueue(void *heap) {
    ThreadFunctionQueue *queue;
    s32 functionIndex;
    gThreadFunctionQueue = HeapAlloc(heap, 0xfc);
    gThreadFunctionQueue->mThreadStack = HeapAllocAligned(heap, 0x800, 0x20);
    OS_CreateThread(&gThreadFunctionQueue->mThread, RunQueuedThreadFunctions, NULL,
                    gThreadFunctionQueue->mThreadStack + 0x800, 0x800, 0x11);
    OS_WakeupThreadDirect(&gThreadFunctionQueue->mThread);
    gThreadFunctionQueue->mRunRequested = 0;
    queue = gThreadFunctionQueue;
    for (functionIndex = 0; functionIndex < 10; functionIndex++) {
        queue->mFunctions[functionIndex] = NULL;
    }
    queue->mNewestIndex = 0;
}
