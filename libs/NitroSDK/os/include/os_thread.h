#pragma once

#include "types.h"

#include "code_0200e77c.h"
#include "code_0200f790.h"

// The thread control block. The threads are linked through OSThread.mNext from OSi_ThreadInfo.mListHead in increasing
// OSThread.mPriority; OS_CreateThread sets one up.
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
    /* 48 */ u8 mCpContext[0x1c]; // its address goes to the functions called by OS_SaveContext and OS_LoadContext
    /* 64 */ u32 mState; // 0 waiting, 1 ready, 2 terminated
    /* 68 */ struct OSThread *mNext;
    // The id OSi_GetUnusedThreadId gives (0 for the first thread); the game tests it against 0 and the C library code
    // keeps a copy of the first thread's value in gLockOwnerThreadIds and compares it later.
    /* 6c */ u32 mId;
    /* 70 */ u32 mPriority;
    /* 74 */ u32 mProfiler;
    /* 78 */ OSThreadQueue *mQueue;
    /* 7c */ struct OSThread *mLinkPrev;
    /* 80 */ struct OSThread *mLinkNext;
    /* 84 */ OSMutex *mMutex; // set by OS_LockMutex around its call to OS_SleepThread
    /* 88 */ OSMutexQueue mMutexQueue;
    /* 90 */ u8 *mStackTop;
    /* 94 */ u8 *mStackBottom;
    /* 98 */ u32 mStackWarningOffset;
    /* 9c */ OSThreadQueue mJoinQueue;
    /* a4 */ void *mSpecific[3];
    // The alarm of the OS_Sleep call the thread is in, 0 otherwise; OS_CreateThread and OSi_SleepAlarmCallback set it
    // to 0, OS_Sleep sets it, OSi_CancelThreadAlarmForSleep cancels it.
    /* b0 */ OSAlarm *mAlarmForSleep;
    // What OS_SetThreadDestructor stores; OSi_ExitThread clears it and calls it with the exit argument.
    /* b4 */ void (*mDestructor)(void *);
    /* b8 */ u8 mPad[8];
} OSThread;

// The thread switch callback type.
typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);

// Object at OSi_ThreadInfo; OS_InitThread stores the address of mCurrentThread in OSi_CurrentThreadPtr.
typedef struct ThreadSystem {
    /* 00 */ u16 mIsNeedRescheduling;
    /* 02 */ u16 mIrqDepth;
    /* 04 */ OSThread *mCurrentThread;
    /* 08 */ OSThread *mListHead;
    /* 0c */ OSSwitchThreadCallback mSwitchCallback;
} ThreadSystem;

typedef void (*OSThreadDestructor)(void *);

OSSwitchThreadCallback OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback);

u32 OS_IsThreadAvailable(void);
// Stores dtor in OSThread.mDestructor.
void OS_SetThreadDestructor(OSThread *thread, OSThreadDestructor dtor);
u32 OS_EnableScheduler(void);
u32 OS_DisableScheduler(void);
// Thread function of the idle thread: enables interrupts, then halts in an endless loop.
void OSi_IdleThreadProc(void *arg);
// Alarm callback of OS_Sleep: wakes the thread that arg points to and clears OSThread.mAlarmForSleep.
void OSi_SleepAlarmCallback(OSThread **arg);
// Sleeps the current thread for msec milliseconds with an alarm.
void OS_Sleep(u32 msec);
u32 OS_GetThreadPriority(OSThread *thread);
s32 OS_SetThreadPriority(OSThread *thread, u32 prio);
void OS_YieldThread(void);
void OSi_RescheduleThread(void);
OSThread *OS_SelectThread(void);
void OS_WakeupThreadDirect(OSThread *thread);
void OS_WakeupThread(OSThreadQueue *queue);
void OS_SleepThread(OSThreadQueue *queue);
s32 OS_IsThreadTerminated(OSThread *thread);
void OS_JoinThread(OSThread *thread);
// Cancels OSThread.mAlarmForSleep when it is set; does not clear it.
void OSi_CancelThreadAlarmForSleep(OSThread *thread);
void OS_DestroyThread(OSThread *thread);
void OSi_ExitThread_Destroy(void);
// Calls the thread's destructor with arg when it has one, then ends the current thread.
void OSi_ExitThread(void *arg);
// Ends thread, running OSi_ExitThread on a separate stack when OSi_StackForDestructor is set.
void OSi_ExitThread_ArgSpecified(OSThread *thread, void *arg);
// Ends the current thread; OS_CreateThread stores it as the return address of every new thread.
void OS_ExitThread(void);
void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, u8 *stack, u32 stackSize, u32 prio);
void OS_InitThread(void);
void OSi_RemoveThreadFromList(OSThread *thread);
void OSi_InsertThreadToList(OSThread *thread);
OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue);
OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue);
void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread);
// Adds 1 to the thread id counter and returns the new value.
u32 OSi_GetUnusedThreadId(void);
