#include "os_thread.h"
#include "registers.h"

#include "Main/Net/data_0216f000.h"
#include "mb_data.h"
#include "code_0200fc8c.h"
#include "code_0200e77c.h"
#include "code_0200f790.h"
#include "code_0200c914.h"
#include "code_0200e688.h"
#include "data_02170000.h"
#include "data_00000000.h"
#include "data_00002000.h"
#include "00/Lib/DWC/code_02188720.h"
#include "code_0200e6ec.h"

u32 OSi_StackForDestructor;
void (*OSi_SystemCallbackInSwitchThread)(OSThread *, OSThread *);
u32 OSi_IsThreadInitialized;
u32 OSi_RescheduleCount;
u32 gThreadIdCount;
OSThread **OSi_CurrentThreadPtr;
ThreadSystem OSi_ThreadInfo;
OSThread OSi_LauncherThread;
OSThread OSi_IdleThread;
u32 OSi_IdleThreadStack[0x32];

// Adds 1 to the thread id counter and returns the new value.
u32 OSi_GetUnusedThreadId(void) {
    gThreadIdCount = gThreadIdCount + 1;
    return gThreadIdCount;
}

// Inserts thread into queue behind the threads of equal or lower OSThread.mPriority value, and does nothing when it is
// already in it.
void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread) {
    OSThread *next;
    OSThread *prev;

    next = queue->mHead;
    while (next != 0 && next->mPriority <= thread->mPriority) {
        if (next == thread) {
            return;
        }
        next = next->mLinkNext;
    }
    if (next == 0) {
        prev = queue->mTail;
        if (prev == 0) {
            queue->mHead = thread;
        } else {
            prev->mLinkNext = thread;
        }
        thread->mLinkPrev = prev;
        thread->mLinkNext = 0;
        queue->mTail = thread;
    } else {
        prev = next->mLinkPrev;
        if (prev == 0) {
            queue->mHead = thread;
        } else {
            prev->mLinkNext = thread;
        }
        thread->mLinkPrev = prev;
        thread->mLinkNext = next;
        next->mLinkPrev = thread;
    }
}

// Takes the first thread out of queue and returns it, or returns 0 when the queue is empty.
OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue) {
    OSThread *thread;
    OSThread *next;

    thread = queue->mHead;
    if (thread != 0) {
        next = thread->mLinkNext;
        queue->mHead = next;
        if (next != 0) {
            next->mLinkPrev = 0;
        } else {
            queue->mTail = 0;
            thread->mQueue = 0;
        }
    }
    return thread;
}

// Takes the first mutex out of queue and returns it, or returns 0 when the queue is empty.
OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue) {
    OSMutex *mutex;
    OSMutex *next;

    mutex = queue->mHead;
    if (mutex != 0) {
        next = mutex->mNext;
        queue->mHead = next;
        if (next != 0) {
            next->mPrev = 0;
        } else {
            queue->mTail = 0;
        }
    }
    return mutex;
}

// Links thread into the thread list in increasing OSThread.mPriority.
void OSi_InsertThreadToList(OSThread *thread) {
    OSThread *current;
    OSThread *prev;
    OSThread *head;

    prev = 0;
    head = OSi_ThreadInfo.mListHead;
    current = head;
    while (current != 0 && current->mPriority < thread->mPriority) {
        prev = current;
        current = current->mNext;
    }
    if (prev == 0) {
        thread->mNext = head;
        OSi_ThreadInfo.mListHead = thread;
    } else {
        thread->mNext = prev->mNext;
        prev->mNext = thread;
    }
}

// Unlinks thread from the thread list.
void OSi_RemoveThreadFromList(OSThread *thread) {
    OSThread *current;
    OSThread *prev;

    prev = 0;
    current = OSi_ThreadInfo.mListHead;
    while (current != 0 && current != thread) {
        prev = current;
        current = current->mNext;
    }
    if (prev == 0) {
        OSi_ThreadInfo.mListHead = thread->mNext;
    } else {
        prev->mNext = thread->mNext;
    }
}

// Sets up the thread system once: the main thread record and the idle thread.
void OS_InitThread(void) {
    s32 stackSize;
    u8 *stackTop;
    u8 *stackBottom;

    if (OSi_IsThreadInitialized != 0) {
        return;
    }
    OSi_IsThreadInitialized = 1;
    OSi_CurrentThreadPtr = &OSi_ThreadInfo.mCurrentThread;
    OSi_LauncherThread.mPriority = 0x10;
    OSi_LauncherThread.mId = 0;
    OSi_LauncherThread.mState = 1;
    OSi_LauncherThread.mNext = 0;
    OSi_LauncherThread.mProfiler = 0;
    OSi_ThreadInfo.mListHead = &OSi_LauncherThread;
    OSi_ThreadInfo.mCurrentThread = &OSi_LauncherThread;
    stackSize = (s32) data_00002800;
    if (stackSize <= 0) {
        stackTop = (u8 *) 0x27e00e0 - stackSize;
    } else {
        stackTop = (u8 *) &OSi_IrqThreadQueue + 0x3f80 - (u32) data_00000c00 - stackSize;
    }
    stackBottom = (u8 *) &OSi_IrqThreadQueue + 0x3f80 - (u32) data_00000c00;
    OSi_LauncherThread.mStackBottom = stackBottom;
    OSi_LauncherThread.mStackTop = stackTop;
    OSi_LauncherThread.mStackWarningOffset = 0;
    *(u32 *) (stackBottom - 4) = 0xfddb597d;
    *(u32 *) OSi_LauncherThread.mStackTop = 0x7bf9dd5b;
    OSi_LauncherThread.mJoinQueue.mTail = 0;
    OSi_LauncherThread.mJoinQueue.mHead = 0;
    OSi_ThreadInfo.mIsNeedRescheduling = 0;
    OSi_ThreadInfo.mIrqDepth = 0;
    *(ThreadSystem **) HW_THREADINFO_MAIN = &OSi_ThreadInfo;
    OS_SetSwitchThreadCallback(0);
    OS_CreateThread(&OSi_IdleThread, OSi_IdleThreadProc, 0, (u8 *) &OSi_Initialized, 0xc8, 0x1f);
    OSi_IdleThread.mPriority = 0x20;
    OSi_IdleThread.mState = 1;
}

// Sets up thread to run func with arg on the given stack at priority prio, and links it into the thread list.
void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, u8 *stack, u32 stackSize, u32 prio) {
    u32 enabled;
    u32 id;
    u8 *stackTop;
    volatile u32 fill;

    enabled = OS_DisableInterrupts();
    id = OSi_GetUnusedThreadId();
    thread->mPriority = prio;
    thread->mId = id;
    thread->mState = 0;
    thread->mProfiler = 0;
    OSi_InsertThreadToList(thread);
    thread->mStackBottom = stack;
    stackTop = stack - stackSize;
    thread->mStackTop = stackTop;
    thread->mStackWarningOffset = 0;
    *(u32 *) (thread->mStackBottom - 4) = 0xfddb597d;
    *(u32 *) thread->mStackTop = 0x7bf9dd5b;
    thread->mJoinQueue.mTail = 0;
    thread->mJoinQueue.mHead = thread->mJoinQueue.mTail;
    ThreadInitContext(thread, func, (u32) stack - 4);
    thread->mR0 = arg;
    thread->mLr = OS_ExitThread;
    fill = 0;
    MIi_CpuClear32(fill, stackTop + 4, stackSize - 8);
    OS_SetThreadDestructor(thread, 0);
    thread->mQueue = 0;
    thread->mLinkNext = 0;
    thread->mLinkPrev = thread->mLinkNext;
    thread->mAlarmForSleep = 0;
    OS_RestoreInterrupts(enabled);
}

// Ends the current thread.
void OS_ExitThread(void) {
    OS_DisableInterrupts();
    OSi_ExitThread_ArgSpecified(OSi_ThreadInfo.mCurrentThread, 0);
}

// When OSi_StackForDestructor is set, restarts thread on that stack in OSi_ExitThread with arg; otherwise calls
// OSi_ExitThread.
void OSi_ExitThread_ArgSpecified(OSThread *thread, void *arg) {
    if (OSi_StackForDestructor != 0) {
        ThreadInitContext(thread, OSi_ExitThread, OSi_StackForDestructor);
        thread->mR0 = arg;
        thread->mCpsr = thread->mCpsr | 0x80;
        thread->mState = 1;
        OS_LoadContext(thread);
    } else {
        OSi_ExitThread(arg);
    }
}

// Runs and clears OSThread.mDestructor of the current thread with arg, then ends the thread.
void OSi_ExitThread(void *arg) {
    OSThread *current;
    OSThreadDestructor destructor;

    current = *OSi_CurrentThreadPtr;
    destructor = current->mDestructor;
    if (destructor != 0) {
        current->mDestructor = 0;
        destructor(arg);
        OS_DisableInterrupts();
    }
    OSi_ExitThread_Destroy();
}

// Releases the mutexes of the current thread, unlists it, marks it terminated, wakes the threads joining it and
// switches away for good.
void OSi_ExitThread_Destroy(void) {
    OSThread *current;

    current = *OSi_CurrentThreadPtr;
    OS_DisableScheduler();
    OSi_UnlockAllMutex(current);
    OSi_RemoveThreadFromList(current);
    current->mState = 2;
    OS_WakeupThread(&current->mJoinQueue);
    OS_EnableScheduler();
    OSi_RescheduleThread();
    OS_Terminate();
}

// Ends thread: the current thread exits; any other one has its mutexes released and its sleep alarm cancelled, is
// unlisted and marked terminated, and the threads joining it wake up.
void OS_DestroyThread(OSThread *thread) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (OSi_ThreadInfo.mCurrentThread == thread) {
        OSi_ExitThread_Destroy();
    }
    OS_DisableScheduler();
    OSi_UnlockAllMutex(thread);
    OSi_CancelThreadAlarmForSleep(thread);
    OSi_RemoveThreadFromList(thread);
    thread->mState = 2;
    OS_WakeupThread(&thread->mJoinQueue);
    OS_EnableScheduler();
    OS_RestoreInterrupts(enabled);
    OSi_RescheduleThread();
}

// Cancels OSThread.mAlarmForSleep when it is set.
void OSi_CancelThreadAlarmForSleep(OSThread *thread) {
    if (thread->mAlarmForSleep != 0) {
        OS_CancelAlarm(thread->mAlarmForSleep);
    }
}

// Sleeps until thread is terminated.
void OS_JoinThread(OSThread *thread) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (thread->mState != 2) {
        OS_SleepThread(&thread->mJoinQueue);
    }
    OS_RestoreInterrupts(enabled);
}

// Returns whether OSThread.mState of thread is terminated.
s32 OS_IsThreadTerminated(OSThread *thread) {
    return thread->mState == 2;
}

// Puts the current thread to sleep, on queue when there is one, and switches to another thread.
void OS_SleepThread(OSThreadQueue *queue) {
    u32 enabled;
    OSThread *current;

    enabled = OS_DisableInterrupts();
    current = *OSi_CurrentThreadPtr;
    if (queue != 0) {
        current->mQueue = queue;
        OSi_InsertLinkToQueue(queue, current);
    }
    current->mState = 0;
    OSi_RescheduleThread();
    OS_RestoreInterrupts(enabled);
}

// Makes every thread on queue ready and empties the queue.
void OS_WakeupThread(OSThreadQueue *queue) {
    u32 enabled;
    OSThread *wokenThread;

    enabled = OS_DisableInterrupts();
    if (queue->mHead != 0) {
        while (queue->mHead != 0) {
            wokenThread = OSi_RemoveLinkFromQueue(queue);
            wokenThread->mState = 1;
            wokenThread->mQueue = 0;
            wokenThread->mLinkNext = 0;
            wokenThread->mLinkPrev = wokenThread->mLinkNext;
        }
        queue->mTail = 0;
        queue->mHead = queue->mTail;
        OSi_RescheduleThread();
    }
    OS_RestoreInterrupts(enabled);
}

// Makes thread ready.
void OS_WakeupThreadDirect(OSThread *thread) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    thread->mState = 1;
    OSi_RescheduleThread();
    OS_RestoreInterrupts(enabled);
}

// Returns the first ready thread of the thread list, or 0.
OSThread *OS_SelectThread(void) {
    OSThread *thread;

    thread = OSi_ThreadInfo.mListHead;
    while (thread != 0 && thread->mState != 1) {
        thread = thread->mNext;
    }
    return thread;
}

// Switches to the first ready thread when that is not the current one. Inside an interrupt, or with the scheduler
// disabled, it only notes that a switch is due.
void OSi_RescheduleThread(void) {
    ThreadSystem *system;
    OSThread *current;
    OSThread *next;

    system = &OSi_ThreadInfo;
    if (OSi_RescheduleCount != 0) {
        return;
    }
    if (system->mIrqDepth != 0 || OS_GetProcMode() == 0x12) {
        system->mIsNeedRescheduling = 1;
        return;
    }
    current = *OSi_CurrentThreadPtr;
    next = OS_SelectThread();
    if (current == next) {
        return;
    }
    if (next == 0) {
        return;
    }
    if (current->mState != 2) {
        if (OS_SaveContext(current) != 0) {
            return;
        }
    }
    if (OSi_SystemCallbackInSwitchThread != 0) {
        OSi_SystemCallbackInSwitchThread(current, next);
    }
    if (system->mSwitchCallback != 0) {
        system->mSwitchCallback(current, next);
    }
    OSi_ThreadInfo.mCurrentThread = next;
    OS_LoadContext(next);
}

// Moves the current thread behind the last thread of equal OSThread.mPriority in the thread list and reschedules.
void OS_YieldThread(void) {
    OSThread *runningThread;
    OSThread *currentPrev;
    OSThread *lastEqual;
    OSThread *thread;
    OSThread *prev;
    int count;
    u32 enabled;

    currentPrev = 0;
    lastEqual = 0;
    count = 0;
    runningThread = OSi_ThreadInfo.mCurrentThread;
    enabled = OS_DisableInterrupts();
    prev = 0;
    for (thread = OSi_ThreadInfo.mListHead; thread != 0; thread = thread->mNext) {
        if (thread == runningThread) {
            currentPrev = prev;
        }
        if (runningThread->mPriority == thread->mPriority) {
            lastEqual = thread;
            count++;
        }
        prev = thread;
    }
    if (count <= 1 || lastEqual == runningThread) {
        OS_RestoreInterrupts(enabled);
        return;
    }
    if (currentPrev == 0) {
        OSi_ThreadInfo.mListHead = runningThread->mNext;
    } else {
        currentPrev->mNext = runningThread->mNext;
    }
    runningThread->mNext = lastEqual->mNext;
    lastEqual->mNext = runningThread;
    OSi_RescheduleThread();
    OS_RestoreInterrupts(enabled);
}

// Gives thread the priority prio and relists it. Returns 0 for the idle thread and for a thread that is not listed.
s32 OS_SetThreadPriority(OSThread *thread, u32 prio) {
    OSThread *current;
    OSThread *prev;
    u32 enabled;

    current = OSi_ThreadInfo.mListHead;
    prev = 0;
    enabled = OS_DisableInterrupts();
    while (current != 0 && current != thread) {
        prev = current;
        current = current->mNext;
    }
    if (current == 0 || current == &OSi_IdleThread) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (current->mPriority != prio) {
        if (prev == 0) {
            OSi_ThreadInfo.mListHead = thread->mNext;
        } else {
            prev->mNext = thread->mNext;
        }
        thread->mPriority = prio;
        OSi_InsertThreadToList(thread);
        OSi_RescheduleThread();
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Returns OSThread.mPriority of thread.
u32 OS_GetThreadPriority(OSThread *thread) {
    return thread->mPriority;
}

// Sleeps the current thread for msec milliseconds: an alarm wakes it up again.
void OS_Sleep(u32 msec) {
    OSThread *thread;
    OSAlarm sleepAlarm;
    u32 enabled;

    OS_CreateAlarm(&sleepAlarm);
    thread = *OSi_CurrentThreadPtr;
    enabled = OS_DisableInterrupts();
    thread->mAlarmForSleep = &sleepAlarm;
    OS_SetAlarm(&sleepAlarm, msec * 0x82ea >> 6, (void (*)(void *)) OSi_SleepAlarmCallback, &thread);
    while (thread != 0) {
        OS_SleepThread(0);
    }
    OS_RestoreInterrupts(enabled);
}

// Alarm callback of OS_Sleep: clears the thread pointer arg points to and the thread's OSThread.mAlarmForSleep, then
// makes the thread ready.
void OSi_SleepAlarmCallback(OSThread **arg) {
    OSThread *thread;

    thread = *arg;
    *arg = 0;
    thread->mAlarmForSleep = 0;
    OS_WakeupThreadDirect(thread);
}

OSSwitchThreadCallback OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback) {
    u32 enabled;
    OSSwitchThreadCallback previous;

    enabled = OS_DisableInterrupts();
    previous = OSi_ThreadInfo.mSwitchCallback;
    OSi_ThreadInfo.mSwitchCallback = callback;
    OS_RestoreInterrupts(enabled);
    return previous;
}

// Thread function of the idle thread: enables interrupts, then halts in an endless loop.
void OSi_IdleThreadProc(void *arg) {
    OS_EnableInterrupts();
    for (;;) {
        OS_Halt();
    }
}

// Raises the scheduler disable count and returns its previous value.
u32 OS_DisableScheduler(void) {
    u32 enabled;
    u32 count;

    enabled = OS_DisableInterrupts();
    if (OSi_RescheduleCount < 0xffffffff) {
        count = OSi_RescheduleCount;
        OSi_RescheduleCount = count + 1;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

// Lowers the scheduler disable count when it is not 0 and returns its previous value.
u32 OS_EnableScheduler(void) {
    u32 enabled;
    u32 count;

    enabled = OS_DisableInterrupts();
    count = 0;
    if (OSi_RescheduleCount != 0) {
        count = OSi_RescheduleCount;
        OSi_RescheduleCount = count - 1;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

// Stores dtor in OSThread.mDestructor.
void OS_SetThreadDestructor(OSThread *thread, OSThreadDestructor dtor) {
    thread->mDestructor = dtor;
}

// Returns whether OS_InitThread has run.
u32 OS_IsThreadAvailable(void) {
    return OSi_IsThreadInitialized;
}
