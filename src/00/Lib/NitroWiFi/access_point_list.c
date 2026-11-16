#include "00/Lib/NitroWiFi/access_point_list.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "00/Lib/NitroWiFi/oldest_access_point.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"
#include "unsigned_int_divide.h"
#include "thread_scheduler.h"
#include "startup_clear_and_decompress.h"

void WcmCpsifUnlockMutexInIRQ(OSMutex *mutex) {
    if (mutex->mHolder == (struct OSThread *) OS_IrqHandler) {
        mutex->mLockCount--;
        if (mutex->mLockCount == 0) {
            mutex->mHolder = NULL;
            OS_WakeupThread(&mutex->mQueue);
        }
    }
}

void WCM_ClearApList(void) {
    u32 enabled;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = WCMi_GetSystemWork();
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return;
    }
    if (work->mPbdBuffer != NULL && (s32) work->mNbdBuffer > 0) {
        MI_CpuFill8(work->mPbdBuffer, 0, work->mNbdBuffer);
    }
    OS_RestoreInterrupts(enabled);
}

u32 WCM_CountApList(void) {
    u32 enabled;
    u32 count;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = WCMi_GetSystemWork();
    count = 0;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return count;
    }
    if (work->mPbdBuffer != NULL && work->mNbdBuffer > 0xc) {
        count = work->mPbdBuffer->mCount;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

u32 WCM_LockApList(u32 lock) {
    u32 enabled;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = WCMi_GetSystemWork();
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (lock != 0) {
        lock = work->mApListLock != 0;
        work->mApListLock = 1;
    } else {
        lock = work->mApListLock != 0;
        work->mApListLock = 0;
    }
    OS_RestoreInterrupts(enabled);
    return lock;
}

u8 *WCM_PointApList(u16 index) {
    u32 enabled;
    WCMApList *apNode;

    enabled = OS_DisableInterrupts();
    if (WCMi_GetSystemWork() == NULL) {
        OS_RestoreInterrupts(enabled);
        return NULL;
    }
    apNode = WcmSearchIndexedApList(index);
    if (apNode == NULL) {
        OS_RestoreInterrupts(enabled);
        return NULL;
    }
    OS_RestoreInterrupts(enabled);
    return apNode->mData;
}

void WCMi_EntryApList(WMBssDesc *bssDesc, u16 linkLevel) {
    WCMWork *work;
    WCMApList *entry;

    work = WCMi_GetSystemWork();
    if (work != NULL && work->mApListLock == 0 && bssDesc->mGameInfoLength == 0) {
        entry = WcmSearchApList(bssDesc->mBssid);
        if (entry == NULL) {
            entry = WcmAllocApList();
        }
        if (entry == NULL && work->mNbdMode == 1) {
            entry = WcmGetOldestApList();
        }
        if (entry != NULL) {
            entry->mLinkLevel = linkLevel;
            MIi_CpuCopyFast(bssDesc, entry->mData, 0xc0);
            WcmAppendApList(entry);
        }
    }
}

WCMApList *WcmAllocApList(void) {
    WCMWork *work;
    WCMApListHeader *aplistHeader;
    WCMApList *apNode;
    u32 capacity;
    s32 index;

    work = WCMi_GetSystemWork();
    aplistHeader = work->mPbdBuffer;
    apNode = NULL;
    if (aplistHeader != NULL && work->mNbdBuffer > 0xc) {
        capacity = (work->mNbdBuffer - 0xc) / 0xd0;
        if (capacity != 0 && capacity > aplistHeader->mCount) {
            for (index = 0; index < capacity; index++) {
                apNode = &aplistHeader->mBlocks[(u32) index];
                if (apNode->mState == 0) {
                    break;
                }
            }
            if (index < capacity) {
                apNode->mState = 1;
                apNode->mIndex = aplistHeader->mCount;
                apNode->mNext = NULL;
                apNode->mPrevious = aplistHeader->mTail;
                aplistHeader->mTail = apNode;
                if (apNode->mPrevious != NULL) {
                    apNode->mPrevious->mNext = apNode;
                } else {
                    aplistHeader->mHead = apNode;
                }
                aplistHeader->mCount++;
            }
        }
    }
    return apNode;
}
