#include "multiboot_task_thread.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"
#include "multiboot_file_register.h"
#include "multiboot_parent_desc.h"

struct WorkerQueue *g_GlobalAN;

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
        irqState = Os_DisableIrq();
        while (workerQueue->mFirstTask == NULL) {
            Os_Thread_SetPriority(&workerQueue->mThread, priorityWhenEmpty);
            Os_Thread_Sleep(NULL);
        }
        task = workerQueue->mFirstTask;
        workerQueue->mFirstTask = workerQueue->mFirstTask->mNext;
        Os_Thread_SetPriority(&workerQueue->mThread, task->mPriority);
        Os_RestoreIrq(irqState);
        if (task->mRun != NULL) {
            ((void (*)(WorkerTask *)) task->mRun)(task);
        }
        savedInterrupts = Os_DisableIrq();
        doneFunction = (void (*)(WorkerTask *)) task->mDone;
        currentPriority = Os_Thread_GetPriority(&workerQueue->mThread);
        if (workerQueue->mFirstTask == NULL) {
            nextPriority = priorityWhenEmpty;
        } else if (currentPriority < workerQueue->mFirstTask->mPriority) {
            nextPriority = workerQueue->mFirstTask->mPriority;
        } else {
            nextPriority = currentPriority;
        }
        if (nextPriority != currentPriority) {
            Os_Thread_SetPriority(&workerQueue->mThread, nextPriority);
        }
        task->mNext = NULL;
        task->mInUse = 0;
        if (doneFunction != NULL) {
            doneFunction(task);
        }
        if (task == &workerQueue->mStopTask) {
            break;
        }
        Os_RestoreIrq(savedInterrupts);
    }
    Os_Thread_Exit();
}

void InitializeSetGlobalAN_from_thumb(WorkerQueue *workerQueue, u32 totalSize) {
    u32 savedInterrupts;
    u32 stackSize;
    savedInterrupts = Os_DisableIrq();
    if (g_GlobalAN == NULL) {
        g_GlobalAN = workerQueue;
        StructANN_Create_from_thumb(&workerQueue->mStopTask);
        workerQueue->mFirstTask = NULL;
        stackSize = (totalSize - sizeof(WorkerQueue)) & ~3;
        Os_Thread_Create(&workerQueue->mThread, MBi_TaskThread, workerQueue, (u8 *) (workerQueue + 1) + stackSize,
                        stackSize, 0);
        Os_Thread_WakeUpDirect(&workerQueue->mThread);
    }
    Os_RestoreIrq(savedInterrupts);
}

#pragma thumb off

#pragma thumb on

u32 IsGlobalANSet_from_thumb(void) {
    if (g_GlobalAN != NULL) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void StructANN_Create_from_thumb(void *taskInfo) {
    void *target = taskInfo;
    u32 fillValue;
    u32 byteCount;
    u32 unusedScratch;
    fillValue = 0u;
    byteCount = 32u;
    Mem_CpuFill8(target, fillValue, byteCount);
}
#pragma thumb off

#pragma thumb on

u32 MBi_IsTaskBusy(WorkerTask *task) {
    if (task->mInUse != 0) {
        return 1;
    }
    return 0;
}

void StructANN_SomeFn_from_thumb(WorkerTask *task, void *run, void *done, u32 priority) {
    WorkerQueue *workerQueue;
    u32 threadPriority;
    u32 savedInterrupts;
    WorkerTask *previous;
    WorkerTask *next;
    workerQueue = g_GlobalAN;
    if (IsGlobalANSet_from_thumb() == 0) {
        Os_Terminate();
    }
    if (task->mInUse != 0) {
        Os_Terminate();
    }
    if (priority > 31) {
        threadPriority = Os_Thread_GetPriority(&workerQueue->mThread);
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
    savedInterrupts = Os_DisableIrq();
    task->mInUse = 1;
    task->mPriority = priority;
    task->mRun = run;
    task->mDone = done;
    if (workerQueue->mFirstTask == NULL) {
        if (task == &workerQueue->mStopTask) {
            g_GlobalAN = NULL;
        }
        workerQueue->mFirstTask = task;
        Os_Thread_WakeUpDirect(&workerQueue->mThread);
    } else {
        previous = workerQueue->mFirstTask;
        if (task == &workerQueue->mStopTask) {
            if (previous->mNext != NULL) {
                do {
                    previous = previous->mNext;
                } while (previous->mNext != NULL);
            }
            previous->mNext = task;
            g_GlobalAN = NULL;
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
    Os_RestoreIrq(savedInterrupts);
}

#pragma thumb off

#pragma thumb on

void MBi_EndTaskThread(void *done) {
    u32 savedInterrupts;
    int workerActive;
    savedInterrupts = ((s64) Os_DisableIrq());
    workerActive = IsGlobalANSet_from_thumb();
    if (workerActive != 0) {
        StructANN_SomeFn_from_thumb(&g_GlobalAN->mStopTask, NULL, done, 0);
    }
    Os_RestoreIrq(savedInterrupts);
}

#pragma thumb off
