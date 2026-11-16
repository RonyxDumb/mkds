#include "multiboot_task_thread.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"
#include "multiboot_file_register.h"
#include "multiboot_parent_desc.h"

struct WorkerQueue *gWorkerQueue;

#pragma thumb on

u32 MB_FakeReadParentBssDesc(u32 entryIndex, WMBssDesc *scanBlock, u16 parentMaxSize, u16 childMaxSize, u32 ksFlag,
                             u32 flagTwo) {
    u32 csAttribute;
    u32 ksAttribute;
    if (MB_FakeGetParentBssDesc(entryIndex, scanBlock) == 0) {
        return 0;
    }
    scanBlock->mGameInfoLength = MULTIBOOT_BEACON_GAME_INFO_LENGTH;
    scanBlock->mGameInfo.mUserGameInfoLength = 0;
    scanBlock->mGameInfo.mParentMaxSize = parentMaxSize;
    scanBlock->mGameInfo.mChildMaxSize = childMaxSize;
    csAttribute = 0;
    if (flagTwo != 0) {
        csAttribute = WIRELESS_ATTRIBUTE_CS_FLAG;
    }
    if (ksFlag != 0) {
        ksAttribute = WIRELESS_ATTRIBUTE_KS_FLAG;
    } else {
        ksAttribute = 0;
    }
    scanBlock->mGameInfo.mAttribute = ksAttribute | csAttribute | WIRELESS_ATTRIBUTE_ENTRY;
    return 1;
}

void MBi_TaskThread(void *argument) {
    WorkerQueue *workerQueue;
    WorkerTask *task;
    u32 irqState;
    u32 nextPriority;
    u32 savedInterrupts;
    void (*doneFunction)(WorkerTask *);
    u32 currentPriority;
    u32 priorityWhenEmpty;
    workerQueue = argument;
    priorityWhenEmpty = 0;
    for (;;) {
        irqState = OS_DisableInterrupts();
        while (workerQueue->mFirstTask == NULL) {
            OS_SetThreadPriority(&workerQueue->mThread, priorityWhenEmpty);
            OS_SleepThread(NULL);
        }
        task = workerQueue->mFirstTask;
        workerQueue->mFirstTask = workerQueue->mFirstTask->mNext;
        OS_SetThreadPriority(&workerQueue->mThread, task->mPriority);
        OS_RestoreInterrupts(irqState);
        if (task->mRun != NULL) {
            ((void (*)(WorkerTask *)) task->mRun)(task);
        }
        savedInterrupts = OS_DisableInterrupts();
        doneFunction = (void (*)(WorkerTask *)) task->mDone;
        currentPriority = OS_GetThreadPriority(&workerQueue->mThread);
        if (workerQueue->mFirstTask == NULL) {
            nextPriority = priorityWhenEmpty;
        } else if (currentPriority < workerQueue->mFirstTask->mPriority) {
            nextPriority = workerQueue->mFirstTask->mPriority;
        } else {
            nextPriority = currentPriority;
        }
        if (nextPriority != currentPriority) {
            OS_SetThreadPriority(&workerQueue->mThread, nextPriority);
        }
        task->mNext = NULL;
        task->mInUse = 0;
        if (doneFunction != NULL) {
            doneFunction(task);
        }
        if (task == &workerQueue->mStopTask) {
            break;
        }
        OS_RestoreInterrupts(savedInterrupts);
    }
    OS_ExitThread();
}

void MBi_InitTaskThread(WorkerQueue *workerQueue, u32 totalSize) {
    u32 savedInterrupts;
    u32 stackSize;
    savedInterrupts = OS_DisableInterrupts();
    if (gWorkerQueue == NULL) {
        gWorkerQueue = workerQueue;
        MBi_InitTaskInfo(&workerQueue->mStopTask);
        workerQueue->mFirstTask = NULL;
        stackSize = (totalSize - sizeof(WorkerQueue)) & ~3;
        OS_CreateThread(&workerQueue->mThread, MBi_TaskThread, workerQueue, (u8 *) (workerQueue + 1) + stackSize,
                        stackSize, 0);
        OS_WakeupThreadDirect(&workerQueue->mThread);
    }
    OS_RestoreInterrupts(savedInterrupts);
}

u32 MBi_IsTaskAvailable(void) {
    if (gWorkerQueue != NULL) {
        return 1;
    }
    return 0;
}

void MBi_InitTaskInfo(void *taskInfo) {
    void *target = taskInfo;
    u32 fillValue;
    u32 byteCount;
    u32 unusedScratch;
    fillValue = 0u;
    byteCount = 32u;
    MI_CpuFill8(target, fillValue, byteCount);
}

u32 MBi_IsTaskBusy(WorkerTask *task) {
    if (task->mInUse != 0) {
        return 1;
    }
    return 0;
}

void MBi_SetTask(WorkerTask *task, void *run, void *done, u32 priority) {
    WorkerQueue *workerQueue;
    u32 threadPriority;
    u32 savedInterrupts;
    WorkerTask *previous;
    WorkerTask *next;
    workerQueue = gWorkerQueue;
    if (MBi_IsTaskAvailable() == 0) {
        OS_Terminate();
    }
    if (task->mInUse != 0) {
        OS_Terminate();
    }
    if (priority > 31) {
        threadPriority = OS_GetThreadPriority(&workerQueue->mThread);
        if (priority == 32) {
            if (threadPriority != 0) {
                priority = threadPriority - 1;
            } else {
                priority = 0;
            }
        } else if (priority == 33) {
            if (threadPriority < 31) {
                priority = threadPriority + 1;
            } else {
                priority = 31;
            }
        } else if (priority == 34) {
            priority = threadPriority;
        } else {
            priority = 31;
        }
    }
    savedInterrupts = OS_DisableInterrupts();
    task->mInUse = 1;
    task->mPriority = priority;
    task->mRun = run;
    task->mDone = done;
    if (workerQueue->mFirstTask == NULL) {
        if (task == &workerQueue->mStopTask) {
            gWorkerQueue = NULL;
        }
        workerQueue->mFirstTask = task;
        OS_WakeupThreadDirect(&workerQueue->mThread);
    } else {
        previous = workerQueue->mFirstTask;
        if (task == &workerQueue->mStopTask) {
            if (previous->mNext != NULL) {
                do {
                    previous = previous->mNext;
                } while (previous->mNext != NULL);
            }
            previous->mNext = task;
            gWorkerQueue = NULL;
        } else if (previous->mPriority > priority) {
            workerQueue->mFirstTask = task;
            task->mNext = previous;
        } else {
            while ((next = previous->mNext) != NULL && next->mPriority <= priority) {
                previous = next;
            }
            task->mNext = next;
            previous->mNext = task;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
}

void MBi_EndTaskThread(void *done) {
    u32 savedInterrupts;
    int workerActive;
    savedInterrupts = ((s64) OS_DisableInterrupts());
    workerActive = MBi_IsTaskAvailable();
    if (workerActive != 0) {
        MBi_SetTask(&gWorkerQueue->mStopTask, NULL, done, 0);
    }
    OS_RestoreInterrupts(savedInterrupts);
}

#pragma thumb off
