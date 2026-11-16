#pragma once

#include "types.h"

#include "thread_mutex_types.h"
#include "alarm_timer.h"

// Priorities of the two threads the system sets up itself.
enum {
    THREAD_PRIORITY_LAUNCHER = 0x10,
    THREAD_PRIORITY_IDLE = 0x20,
};

// Check words written at the two ends of a stack; a changed word means the stack overflowed.
#define STACK_CHECK_BOTTOM 0xfddb597d
#define STACK_CHECK_TOP 0x7bf9dd5b

// The thread control block. The threads are linked through OSThread.mNext from g_Os_ThreadInfo.mListHead in increasing
// OSThread.mPriority; Os_Thread_Create sets one up.
// Values of OSThread.mState: parked (not run until woken), runnable, finished.
enum {
    THREAD_STATE_PARKED,
    THREAD_STATE_RUNNABLE,
    THREAD_STATE_FINISHED,
};

typedef struct OSThread {
    /* 00 */ u32 mCpsr;
    /* 04 */ void *mR0;
    /* 08 */ u32 mR1;
    /* 0c */ u32 mR2;
    /* 10 */ u32 mR3;
    /* 14 */ u32 mR4;
    /* 18 */ u32 mR5;
    /* 1c */ u32 mR6;
    /* 20 */ u32 mR7;
    /* 24 */ u32 mR8;
    /* 28 */ u32 mR9;
    /* 2c */ u32 mR10;
    /* 30 */ u32 mR11;
    /* 34 */ u32 mR12;
    /* 38 */ u32 mSp;
    /* 3c */ void (*mLr)(void);
    /* 40 */ u32 mPcPlus4;
    /* 44 */ u32 mSpSvc;
    /* 48 */ u8 mCpContext[0x1c]; // its address goes to the functions called by Arm_Context_Save and Arm_Context_Load
    /* 64 */ u32 mState;
    /* 68 */ struct OSThread *mNext;
    // The id Os_AllocateThreadId gives (0 for the first thread); the game tests it against 0 and the C library code
    // keeps a copy of the first thread's value in g_SomeThreadId and compares it later.
    /* 6c */ u32 mId;
    /* 70 */ u32 mPriority;
    /* 74 */ u32 mProfiler;
    /* 78 */ OSThreadQueue *mQueue;
    /* 7c */ struct OSThread *mLinkPrev;
    /* 80 */ struct OSThread *mLinkNext;
    /* 84 */ OSMutex *mMutex; // set by Os_Mutex_Lock around its call to Os_Thread_Sleep
    /* 88 */ OSMutexQueue mMutexQueue;
    /* 90 */ u8 *mStackTop;
    /* 94 */ u8 *mStackBottom;
    /* 98 */ u32 mStackWarningOffset;
    /* 9c */ OSThreadQueue mJoinQueue;
    /* a4 */ void *mSpecific[3];
    // The alarm of the Os_Sleep call the thread is in, 0 otherwise; Os_Thread_Create and Os_SleepAlarmHandler set it
    // to 0, Os_Sleep sets it, Os_Thread_CancelAlarmForSleep cancels it.
    /* b0 */ OSAlarm *mAlarmForSleep;
    // What Os_Thread_SetDestructor stores; Os_DisposeCurrentThread clears it and calls it with the CheckZetaInvokeBeta argument.
    /* b4 */ void (*mDestructor)(void *);
    /* b8 */ u8 mPad[8];
} OSThread;

// The thread switch callback type.
typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);

// Object at g_Os_ThreadInfo; Os_InitializeThread stores the address of mCurrentThread in g_Os_CurrentThreadRef.
typedef struct ThreadSystem {
    /* 00 */ u16 mIsNeedRescheduling;
    /* 02 */ u16 mIrqDepth;
    /* 04 */ OSThread *mCurrentThread;
    /* 08 */ OSThread *mListHead;
    /* 0c */ OSSwitchThreadCallback mSwitchCallback;
} ThreadSystem;

typedef void (*OSThreadDestructor)(void *);

OSSwitchThreadCallback Os_SetThreadSwitchCallback(OSSwitchThreadCallback callback);

u32 OS_IsThreadAvailable(void);
// Stores dtor in OSThread.mDestructor.
void Os_Thread_SetDestructor(OSThread *thread, OSThreadDestructor dtor);
u32 Os_EnableScheduler(void);
u32 Os_DisableScheduler(void);
// Thread function of the idle thread: enables interrupts, then halts in an endless loop.
void Os_IdleThreadMain(void *arg);
// Alarm callback of Os_Sleep: wakes the thread that arg points to and clears OSThread.mAlarmForSleep.
void Os_SleepAlarmHandler(OSThread **arg);
// Sleeps the current thread for msec milliseconds with an alarm.
void Os_Sleep(u32 msec);
u32 Os_Thread_GetPriority(OSThread *thread);
s32 Os_Thread_SetPriority(OSThread *thread, u32 prio);
void OS_YieldThread(void);
void Os_RescheduleThread(void);
OSThread *Os_FindReadyThread(void);
void Os_Thread_WakeUpDirect(OSThread *thread);
void Os_Thread_WakeUp(OSThreadQueue *queue);
void Os_Thread_Sleep(OSThreadQueue *queue);
s32 Os_Thread_IsTerminated(OSThread *thread);
void Os_Thread_Join(OSThread *thread);
// Cancels OSThread.mAlarmForSleep when it is set; does not clear it.
void Os_Thread_CancelAlarmForSleep(OSThread *thread);
void OS_DestroyThread(OSThread *thread);
void Os_DisposeCurrentThreadImpl(void);
// Calls the thread's destructor with arg when it has one, then ends the current thread.
void Os_DisposeCurrentThread(void *arg);
// Ends thread, running Os_DisposeCurrentThread on a separate stack when g_Os_ThreadDtorSp is set.
void Os_Thread_ExitImpl(OSThread *thread, void *arg);
// Ends the current thread; Os_Thread_Create stores it as the return address of every new thread.
void Os_Thread_Exit(void);
void Os_Thread_Create(OSThread *thread, void (*func)(void *), void *arg, u8 *stack, u32 stackSize, u32 prio);
void Os_InitializeThread(void);
void Os_PopThread(OSThread *thread);
void Os_InsertThread(OSThread *thread);
OSMutex *Os_MutexQueue_Pop(OSMutexQueue *queue);
OSThread *Os_ThreadQueue_Pop(OSThreadQueue *queue);
void Os_ThreadQueue_Queue(OSThreadQueue *queue, OSThread *thread);
// Adds 1 to the thread id counter and returns the new value.
u32 Os_AllocateThreadId(void);
