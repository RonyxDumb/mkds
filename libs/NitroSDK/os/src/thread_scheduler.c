#include "thread_scheduler.h"
#include "registers.h"

#include "Main/Net/block_transfer_and_thread_globals.h"
#include "multiboot_piece_buffers.h"
#include "reset_interrupts_halt.h"
#include "thread_mutex_types.h"
#include "alarm_timer.h"
#include "interrupt_control.h"
#include "thread_context_init.h"
#include "system_state_globals.h"
#include "overlay_id_symbols.h"
#include "system_stack_size.h"
#include "00/Lib/DWC/access_point_manager.h"
#include "thread_sync_and_console_info.h"

u32 g_Os_ThreadDtorSp;
void (*Os_Thread_OnThreadSwitch)(OSThread *, OSThread *);
u32 g_Os_ThreadInit;
u32 g_Os_ThreadRescheduleCount;
u32 g_CurrentThreadId;
OSThread **g_Os_CurrentThreadRef;
ThreadSystem g_Os_ThreadInfo;
OSThread g_Os_LauncherThread;
OSThread g_IdleThread;
u32 OSi_IdleThreadStack[0x32];

// Adds 1 to the thread id counter and returns the new value.
u32 Os_AllocateThreadId(void) {
    g_CurrentThreadId = g_CurrentThreadId + 1;
    return g_CurrentThreadId;
}

// Inserts thread into queue behind the threads of equal or lower OSThread.mPriority value, and does nothing when it is
// already in it.
void Os_ThreadQueue_Queue(OSThreadQueue *queue, OSThread *thread) {
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
OSThread *Os_ThreadQueue_Pop(OSThreadQueue *queue) {
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
OSMutex *Os_MutexQueue_Pop(OSMutexQueue *queue) {
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
void Os_InsertThread(OSThread *thread) {
    OSThread *current;
    OSThread *prev;
    OSThread *head;

    prev = 0;
    head = g_Os_ThreadInfo.mListHead;
    current = head;
    while (current != 0 && current->mPriority < thread->mPriority) {
        prev = current;
        current = current->mNext;
    }
    if (prev == 0) {
        thread->mNext = head;
        g_Os_ThreadInfo.mListHead = thread;
    } else {
        thread->mNext = prev->mNext;
        prev->mNext = thread;
    }
}

// Unlinks thread from the thread list.
void Os_PopThread(OSThread *thread) {
    OSThread *current;
    OSThread *prev;

    prev = 0;
    current = g_Os_ThreadInfo.mListHead;
    while (current != 0 && current != thread) {
        prev = current;
        current = current->mNext;
    }
    if (prev == 0) {
        g_Os_ThreadInfo.mListHead = thread->mNext;
    } else {
        prev->mNext = thread->mNext;
    }
}

// Sets up the thread system once: the NtrMain thread record and the idle thread.
void Os_InitializeThread(void) {
    s32 stackSize;
    u8 *stackTop;
    u8 *stackBottom;

    if (g_Os_ThreadInit != 0) {
        return;
    }
    g_Os_ThreadInit = 1;
    g_Os_CurrentThreadRef = &g_Os_ThreadInfo.mCurrentThread;
    g_Os_LauncherThread.mPriority = THREAD_PRIORITY_LAUNCHER;
    g_Os_LauncherThread.mId = 0;
    g_Os_LauncherThread.mState = THREAD_STATE_RUNNABLE;
    g_Os_LauncherThread.mNext = 0;
    g_Os_LauncherThread.mProfiler = 0;
    g_Os_ThreadInfo.mListHead = &g_Os_LauncherThread;
    g_Os_ThreadInfo.mCurrentThread = &g_Os_LauncherThread;
    stackSize = (s32) SDK_SYS_STACKSIZE;
    if (stackSize <= 0) {
        stackTop = (u8 *) 0x27e00e0 - stackSize;
    } else {
        stackTop = DTCM_THREAD_STACK_END - (u32) SDK_IRQ_STACKSIZE - stackSize;
    }
    stackBottom = DTCM_THREAD_STACK_END - (u32) SDK_IRQ_STACKSIZE;
    g_Os_LauncherThread.mStackBottom = stackBottom;
    g_Os_LauncherThread.mStackTop = stackTop;
    g_Os_LauncherThread.mStackWarningOffset = 0;
    *(u32 *) (stackBottom - 4) = STACK_CHECK_BOTTOM;
    *(u32 *) g_Os_LauncherThread.mStackTop = STACK_CHECK_TOP;
    g_Os_LauncherThread.mJoinQueue.mTail = 0;
    g_Os_LauncherThread.mJoinQueue.mHead = 0;
    g_Os_ThreadInfo.mIsNeedRescheduling = 0;
    g_Os_ThreadInfo.mIrqDepth = 0;
    *(ThreadSystem **) HW_THREADINFO_MAIN = &g_Os_ThreadInfo;
    Os_SetThreadSwitchCallback(0);
    Os_Thread_Create(&g_IdleThread, Os_IdleThreadMain, 0, (u8 *) &g_MemoryRegionsInit, 0xc8, 0x1f);
    g_IdleThread.mPriority = THREAD_PRIORITY_IDLE;
    g_IdleThread.mState = THREAD_STATE_RUNNABLE;
}

// Sets up thread to run func with arg on the given stack at priority prio, and links it into the thread list.
void Os_Thread_Create(OSThread *thread, void (*func)(void *), void *arg, u8 *stack, u32 stackSize, u32 prio) {
    u32 enabled;
    u32 id;
    u8 *stackTop;
    volatile u32 fill;

    enabled = Os_DisableIrq();
    id = Os_AllocateThreadId();
    thread->mPriority = prio;
    thread->mId = id;
    thread->mState = THREAD_STATE_PARKED;
    thread->mProfiler = 0;
    Os_InsertThread(thread);
    thread->mStackBottom = stack;
    stackTop = stack - stackSize;
    thread->mStackTop = stackTop;
    thread->mStackWarningOffset = 0;
    *(u32 *) (thread->mStackBottom - 4) = STACK_CHECK_BOTTOM;
    *(u32 *) thread->mStackTop = STACK_CHECK_TOP;
    thread->mJoinQueue.mTail = 0;
    thread->mJoinQueue.mHead = thread->mJoinQueue.mTail;
    Arm_Context_Create(thread, func, (u32) stack - 4);
    thread->mR0 = arg;
    thread->mLr = Os_Thread_Exit;
    fill = 0;
    MIi_CpuClear32(fill, stackTop + 4, stackSize - 8);
    Os_Thread_SetDestructor(thread, 0);
    thread->mQueue = 0;
    thread->mLinkNext = 0;
    thread->mLinkPrev = thread->mLinkNext;
    thread->mAlarmForSleep = 0;
    Os_RestoreIrq(enabled);
}

// Ends the current thread.
void Os_Thread_Exit(void) {
    Os_DisableIrq();
    Os_Thread_ExitImpl(g_Os_ThreadInfo.mCurrentThread, 0);
}

// When g_Os_ThreadDtorSp is set, restarts thread on that stack in Os_DisposeCurrentThread with arg; otherwise calls
// Os_DisposeCurrentThread.
void Os_Thread_ExitImpl(OSThread *thread, void *arg) {
    if (g_Os_ThreadDtorSp != 0) {
        Arm_Context_Create(thread, Os_DisposeCurrentThread, g_Os_ThreadDtorSp);
        thread->mR0 = arg;
        thread->mCpsr = thread->mCpsr | 0x80;
        thread->mState = THREAD_STATE_RUNNABLE;
        Arm_Context_Load(thread);
    } else {
        Os_DisposeCurrentThread(arg);
    }
}

// Runs and clears OSThread.mDestructor of the current thread with arg, then ends the thread.
void Os_DisposeCurrentThread(void *arg) {
    OSThread *current;
    OSThreadDestructor destructor;

    current = *g_Os_CurrentThreadRef;
    destructor = current->mDestructor;
    if (destructor != 0) {
        current->mDestructor = 0;
        destructor(arg);
        Os_DisableIrq();
    }
    Os_DisposeCurrentThreadImpl();
}

// Releases the mutexes of the current thread, unlists it, marks it terminated, wakes the threads joining it and
// switches away for good.
void Os_DisposeCurrentThreadImpl(void) {
    OSThread *current;

    current = *g_Os_CurrentThreadRef;
    Os_DisableScheduler();
    Os_UnlockAllMutexes(current);
    Os_PopThread(current);
    current->mState = THREAD_STATE_FINISHED;
    Os_Thread_WakeUp(&current->mJoinQueue);
    Os_EnableScheduler();
    Os_RescheduleThread();
    Os_Terminate();
}

// Ends thread: the current thread exits; any other one has its mutexes released and its sleep alarm cancelled, is
// unlisted and marked terminated, and the threads joining it wake up.
void OS_DestroyThread(OSThread *thread) {
    u32 enabled;

    enabled = Os_DisableIrq();
    if (g_Os_ThreadInfo.mCurrentThread == thread) {
        Os_DisposeCurrentThreadImpl();
    }
    Os_DisableScheduler();
    Os_UnlockAllMutexes(thread);
    Os_Thread_CancelAlarmForSleep(thread);
    Os_PopThread(thread);
    thread->mState = THREAD_STATE_FINISHED;
    Os_Thread_WakeUp(&thread->mJoinQueue);
    Os_EnableScheduler();
    Os_RestoreIrq(enabled);
    Os_RescheduleThread();
}

// Cancels OSThread.mAlarmForSleep when it is set.
void Os_Thread_CancelAlarmForSleep(OSThread *thread) {
    if (thread->mAlarmForSleep != 0) {
        Os_Alarm_Cancel(thread->mAlarmForSleep);
    }
}

// Sleeps until thread is finished.
void Os_Thread_Join(OSThread *thread) {
    u32 enabled;

    enabled = Os_DisableIrq();
    if (thread->mState != THREAD_STATE_FINISHED) {
        Os_Thread_Sleep(&thread->mJoinQueue);
    }
    Os_RestoreIrq(enabled);
}

// Returns whether OSThread.mState of thread is finished.
s32 Os_Thread_IsTerminated(OSThread *thread) {
    return thread->mState == THREAD_STATE_FINISHED;
}

// Puts the current thread to sleep, on queue when there is one, and switches to another thread.
void Os_Thread_Sleep(OSThreadQueue *queue) {
    u32 enabled;
    OSThread *current;

    enabled = Os_DisableIrq();
    current = *g_Os_CurrentThreadRef;
    if (queue != 0) {
        current->mQueue = queue;
        Os_ThreadQueue_Queue(queue, current);
    }
    current->mState = THREAD_STATE_PARKED;
    Os_RescheduleThread();
    Os_RestoreIrq(enabled);
}

// Makes every thread on queue ready and empties the queue.
void Os_Thread_WakeUp(OSThreadQueue *queue) {
    u32 enabled;
    OSThread *wokenThread;

    enabled = Os_DisableIrq();
    if (queue->mHead != 0) {
        while (queue->mHead != 0) {
            wokenThread = Os_ThreadQueue_Pop(queue);
            wokenThread->mState = THREAD_STATE_RUNNABLE;
            wokenThread->mQueue = 0;
            wokenThread->mLinkNext = 0;
            wokenThread->mLinkPrev = wokenThread->mLinkNext;
        }
        queue->mTail = 0;
        queue->mHead = queue->mTail;
        Os_RescheduleThread();
    }
    Os_RestoreIrq(enabled);
}

// Makes thread ready.
void Os_Thread_WakeUpDirect(OSThread *thread) {
    u32 enabled;

    enabled = Os_DisableIrq();
    thread->mState = THREAD_STATE_RUNNABLE;
    Os_RescheduleThread();
    Os_RestoreIrq(enabled);
}

// Returns the first ready thread of the thread list, or 0.
OSThread *Os_FindReadyThread(void) {
    OSThread *thread;

    thread = g_Os_ThreadInfo.mListHead;
    while (thread != 0 && thread->mState != THREAD_STATE_RUNNABLE) {
        thread = thread->mNext;
    }
    return thread;
}

// Switches to the first ready thread when that is not the current one. Inside an interrupt, or with the scheduler
// disabled, it only notes that a switch is due.
void Os_RescheduleThread(void) {
    ThreadSystem *system;
    OSThread *current;
    OSThread *next;

    system = &g_Os_ThreadInfo;
    if (g_Os_ThreadRescheduleCount != 0) {
        return;
    }
    if (system->mIrqDepth != 0 || Arm_GetProcessorMode() == 0x12) {
        system->mIsNeedRescheduling = 1;
        return;
    }
    current = *g_Os_CurrentThreadRef;
    next = Os_FindReadyThread();
    if (current == next) {
        return;
    }
    if (next == 0) {
        return;
    }
    if (current->mState != THREAD_STATE_FINISHED) {
        if (Arm_Context_Save(current) != 0) {
            return;
        }
    }
    if (Os_Thread_OnThreadSwitch != 0) {
        Os_Thread_OnThreadSwitch(current, next);
    }
    if (system->mSwitchCallback != 0) {
        system->mSwitchCallback(current, next);
    }
    g_Os_ThreadInfo.mCurrentThread = next;
    Arm_Context_Load(next);
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
    runningThread = g_Os_ThreadInfo.mCurrentThread;
    enabled = Os_DisableIrq();
    prev = 0;
    for (thread = g_Os_ThreadInfo.mListHead; thread != 0; thread = thread->mNext) {
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
        Os_RestoreIrq(enabled);
        return;
    }
    if (currentPrev == 0) {
        g_Os_ThreadInfo.mListHead = runningThread->mNext;
    } else {
        currentPrev->mNext = runningThread->mNext;
    }
    runningThread->mNext = lastEqual->mNext;
    lastEqual->mNext = runningThread;
    Os_RescheduleThread();
    Os_RestoreIrq(enabled);
}

// Gives thread the priority prio and relists it. Returns 0 for the idle thread and for a thread that is not listed.
s32 Os_Thread_SetPriority(OSThread *thread, u32 prio) {
    OSThread *current;
    OSThread *prev;
    u32 enabled;

    current = g_Os_ThreadInfo.mListHead;
    prev = 0;
    enabled = Os_DisableIrq();
    while (current != 0 && current != thread) {
        prev = current;
        current = current->mNext;
    }
    if (current == 0 || current == &g_IdleThread) {
        Os_RestoreIrq(enabled);
        return 0;
    }
    if (current->mPriority != prio) {
        if (prev == 0) {
            g_Os_ThreadInfo.mListHead = thread->mNext;
        } else {
            prev->mNext = thread->mNext;
        }
        thread->mPriority = prio;
        Os_InsertThread(thread);
        Os_RescheduleThread();
    }
    Os_RestoreIrq(enabled);
    return 1;
}

// Returns OSThread.mPriority of thread.
u32 Os_Thread_GetPriority(OSThread *thread) {
    return thread->mPriority;
}

// Sleeps the current thread for msec milliseconds: an alarm wakes it up again.
void Os_Sleep(u32 msec) {
    OSThread *thread;
    OSAlarm sleepAlarm;
    u32 enabled;

    Os_Alarm_Create(&sleepAlarm);
    thread = *g_Os_CurrentThreadRef;
    enabled = Os_DisableIrq();
    thread->mAlarmForSleep = &sleepAlarm;
    Os_Alarm_Set(&sleepAlarm, msec * 0x82ea >> 6, (void (*)(void *)) Os_SleepAlarmHandler, &thread);
    while (thread != 0) {
        Os_Thread_Sleep(0);
    }
    Os_RestoreIrq(enabled);
}

// Alarm callback of Os_Sleep: clears the thread pointer arg points to and the thread's OSThread.mAlarmForSleep, then
// makes the thread ready.
void Os_SleepAlarmHandler(OSThread **arg) {
    OSThread *thread;

    thread = *arg;
    *arg = 0;
    thread->mAlarmForSleep = 0;
    Os_Thread_WakeUpDirect(thread);
}

OSSwitchThreadCallback Os_SetThreadSwitchCallback(OSSwitchThreadCallback callback) {
    u32 enabled;
    OSSwitchThreadCallback previous;

    enabled = Os_DisableIrq();
    previous = g_Os_ThreadInfo.mSwitchCallback;
    g_Os_ThreadInfo.mSwitchCallback = callback;
    Os_RestoreIrq(enabled);
    return previous;
}

// Thread function of the idle thread: enables interrupts, then halts in an endless loop.
void Os_IdleThreadMain(void *arg) {
    Os_EnableIrq();
    for (;;) {
        Os_Halt();
    }
}

// Raises the scheduler disable count and returns its previous value.
u32 Os_DisableScheduler(void) {
    u32 enabled;
    u32 count;

    enabled = Os_DisableIrq();
    if (g_Os_ThreadRescheduleCount < 0xffffffff) {
        count = g_Os_ThreadRescheduleCount;
        g_Os_ThreadRescheduleCount = count + 1;
    }
    Os_RestoreIrq(enabled);
    return count;
}

// Lowers the scheduler disable count when it is not 0 and returns its previous value.
u32 Os_EnableScheduler(void) {
    u32 enabled;
    u32 count;

    enabled = Os_DisableIrq();
    count = 0;
    if (g_Os_ThreadRescheduleCount != 0) {
        count = g_Os_ThreadRescheduleCount;
        g_Os_ThreadRescheduleCount = count - 1;
    }
    Os_RestoreIrq(enabled);
    return count;
}

// Stores dtor in OSThread.mDestructor.
void Os_Thread_SetDestructor(OSThread *thread, OSThreadDestructor dtor) {
    thread->mDestructor = dtor;
}

// Returns whether Os_InitializeThread has run.
u32 OS_IsThreadAvailable(void) {
    return g_Os_ThreadInit;
}
