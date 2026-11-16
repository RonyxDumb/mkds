#pragma once

#include "types.h"
#include "thread_scheduler.h"
#include "wireless_link_control.h"

// A multiboot worker task: the link to the next task, an in-use flag and a priority; tasks are linked by priority.
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

// What g_GlobalAN points to: the OSThread, then the first and the last object of the list.
typedef struct WorkerQueue {
    /* 00 */ OSThread mThread;
    /* c0 */ WorkerTask *volatile mFirstTask;
    /* c4 */ WorkerTask mStopTask;
    /* d4 */ u8 mUnk_d4[0x10];
} WorkerQueue;

typedef struct WorkerQueue WorkerQueue;

void MBi_EndTaskThread(void *done);
void StructANN_SomeFn_from_thumb(WorkerTask *task, void *run, void *done, u32 priority);
u32 MBi_IsTaskBusy(WorkerTask *task);
void StructANN_Create_from_thumb(void *taskInfo);
u32 IsGlobalANSet_from_thumb(void);
void InitializeSetGlobalAN_from_thumb(WorkerQueue *workerQueue, u32 totalSize);
void MBi_TaskThread(void *argument);
u32 MB_FakeReadParentBssDesc(u32 entryIndex, WMBssDesc *scanBlock, u16 parentMaxSize, u16 childMaxSize, u32 ksFlag,
                             u32 flagTwo);

extern struct WorkerQueue *g_GlobalAN;
