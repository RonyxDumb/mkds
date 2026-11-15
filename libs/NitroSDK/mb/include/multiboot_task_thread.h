#pragma once

#include "types.h"
#include "thread_scheduler.h"
#include "wireless_power_mp.h"

// 0x10-byte object MBi_SetTask links by the bits above bit 0 of its member 4, in increasing order.
typedef struct WorkerTask {
    /* 00 */ struct WorkerTask *mNext;
    /* 04 */ union {
        u32 mUnk_04;
        struct {
            u32 mInUse : 1;
            u32 mPriority : 31;
        };
    };
    /* 08 */ void *mRun;
    /* 0c */ void *mDone;
} WorkerTask;

// What gWorkerQueue points to: the OSThread, then the first and the last object of the list.
typedef struct WorkerQueue {
    /* 00 */ OSThread mThread;
    /* c0 */ WorkerTask *volatile mFirstTask;
    /* c4 */ WorkerTask mStopTask;
    /* d4 */ u8 mUnk_d4[0x10];
} WorkerQueue;

typedef struct WorkerQueue WorkerQueue;

void MBi_EndTaskThread(void *done);
void MBi_SetTask(WorkerTask *task, void *run, void *done, u32 priority);
u32 MBi_IsTaskBusy(WorkerTask *task);
void MBi_InitTaskInfo(void *taskInfo);
u32 MBi_IsTaskAvailable(void);
void MBi_InitTaskThread(WorkerQueue *workerQueue, u32 totalSize);
void MBi_TaskThread(void *argument);
u32 MB_FakeReadParentBssDesc(u32 entryIndex, WMBssDesc *scanBlock, u16 parentMaxSize, u16 childMaxSize, u32 ksFlag,
                             u32 flagTwo);

extern struct WorkerQueue *gWorkerQueue;
