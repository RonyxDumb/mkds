#pragma once

#include "types.h"

struct OSThread;

#define HW_CHECK_DEBUGGER_SW ((u16 *) 0x027ffc10)
#define HW_CHECK_DEBUGGER_BUF1 ((u16 *) 0x027ff814)
#define HW_CHECK_DEBUGGER_BUF2 ((u16 *) 0x027ffc14)

// Head and tail of a list of threads, linked through OSThread.mLinkNext and OSThread.mLinkPrev by Os_ThreadQueue_Queue
// and Os_ThreadQueue_Pop. Os_Thread_WakeUp and Os_Thread_Sleep take it.
typedef struct OSThreadQueue {
    /* 00 */ struct OSThread *mHead;
    /* 04 */ struct OSThread *mTail;
} OSThreadQueue;

// A mutex: its thread queue, the holder, the lock count and the links into the mutex queue of the holder thread.
typedef struct OSMutex {
    /* 00 */ OSThreadQueue mQueue;
    /* 08 */ struct OSThread *mHolder; // set by Os_Mutex_TryLock and Os_Mutex_Lock
    /* 0c */ u32 mLockCount; // raised by Os_Mutex_TryLock and Os_Mutex_Lock, lowered by Os_Mutex_Unlock
    /* 10 */ struct OSMutex *mNext;
    /* 14 */ struct OSMutex *mPrev;
} OSMutex;

// Head and tail of the mutexes a thread holds.
typedef struct OSMutexQueue {
    /* 00 */ OSMutex *mHead;
    /* 04 */ OSMutex *mTail;
} OSMutexQueue;

// Set up by Os_MessageQueue_Initialize. Os_MessageQueue_Send stores a word at mBuffer[(mHeadIndex + mCount) % mCapacity] and raises
// mCount; Os_ReceiveMessage reads mBuffer[mHeadIndex], advances mHeadIndex modulo mCapacity and lowers mCount. Each
// calls Os_Thread_Sleep on one of mFullWaiters and mEmptyWaiters and Os_Thread_WakeUp on the other.
typedef void *OSMessage;

typedef struct OSMessageQueue {
    /* 00 */ OSThreadQueue mFullWaiters;
    /* 08 */ OSThreadQueue mEmptyWaiters;
    /* 10 */ OSMessage *mBuffer;
    /* 14 */ s32 mCapacity;
    /* 18 */ s32 mHeadIndex;
    /* 1c */ s32 mCount;
} OSMessageQueue;

// Value Os_GetSystemFlags builds on its first call; 0xffffffff until then.
extern u32 g_DebugFlags;

u32 Os_ExistsSioConnection(void);
// Gets an id, then repeats under Os_DisableIrq until it has either seen that the holder of the lock word at
// 0x027fffe8 has bit 0x40 set or taken the lock: compares the words at 0x08000000 and 0x08000004 with 0x544e494e and
// 0x4f444e45 (the text NINTENDO) and returns 0x01000000 when both match, else 0x02000000. Releases the lock again when
// it took it.
u32 Os_GetDebugSystemFlags(void);
// On the first call builds the value from Os_GetDebugSystemFlags (bit 24 or bit 25), adds 0x10000000 when
// Os_IsEmulator is nonzero, else 0x40000000 when Os_ExistsSioConnection is nonzero, else 0x20000000 when bit 24 is
// set, else 0x80000000, ors in the halfword at 0x027ffffa and stores it in g_DebugFlags. Returns the stored value.
u32 Os_GetSystemFlags(void);
// Returns 0. Os_GetSystemFlags tests it first (nonzero adds 0x10000000); Sound_IsCommandAvailable reads the register at
// 0x04fff200 only when it is nonzero; InitializeGeneralObjects and InitializePrepareBackup_from_thumb skip work when it is nonzero.
u32 Os_IsEmulator(void);
BOOL OS_ReadMessage(OSMessageQueue *queue, OSMessage *message, s32 flags);
BOOL OS_JamMessage(OSMessageQueue *queue, OSMessage message, s32 flags);
BOOL Os_ReceiveMessage(OSMessageQueue *queue, OSMessage *message, s32 flags);
BOOL Os_MessageQueue_Send(OSMessageQueue *queue, OSMessage message, s32 flags);
void Os_MessageQueue_Initialize(OSMessageQueue *queue, OSMessage *messages, s32 count);
void Os_Mutex_DequeueThread(struct OSThread *thread, OSMutex *mutex);
void Os_Mutex_EnqueueThread(struct OSThread *thread, OSMutex *mutex);
BOOL Os_Mutex_TryLock(OSMutex *mutex);
void Os_UnlockAllMutexes(struct OSThread *thread);
void Os_Mutex_Unlock(OSMutex *mutex);
void Os_Mutex_Lock(OSMutex *mutex);
