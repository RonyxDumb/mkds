#pragma once

#include "types.h"
#include "os_thread.h"

// 0x10-byte object CTRDGi_SetTask links by the bits above bit 0 of its member 4, in increasing order.
typedef struct WorkerTask {
    /* 00 */ struct WorkerTask *mNext;
    /* 04 */ union {
        u32 field4;
        struct {
            u32 mInUse : 1;
            u32 mPriority : 31;
        };
    };
    /* 08 */ void *mRun;
    /* 0c */ void *mDone;
} WorkerTask;

// What ctrdgi_task_work points to: the OSThread, then the first and the last object of the list.
typedef struct WorkerQueue {
    /* 00 */ OSThread mThread;
    /* b8 */ u8 fieldB8[8];
    /* c0 */ WorkerTask *volatile mFirstTask;
    /* c4 */ WorkerTask mStopTask;
} WorkerQueue;

typedef struct ScanBlock ScanBlock;
typedef struct WorkerQueue WorkerQueue;

void CTRDGi_EndTaskThread(void *done);
void CTRDGi_SetTask(WorkerTask *task, void *run, void *done, u32 priority);
u32 CTRDGi_IsTaskBusy(WorkerTask *task);
void CTRDGi_InitTaskInfo(void *arg0);
u32 CTRDGi_IsTaskAvailable(void);
void CTRDGi_InitTaskThread(WorkerQueue *workerQueue, u32 totalSize);
void RunWorkerTasks(void *argument);
u32 MB_FakeReadParentBssDesc(u32 entryIndex, ScanBlock *scanBlock, u16 c, u16 d, u32 e, u32 f);
