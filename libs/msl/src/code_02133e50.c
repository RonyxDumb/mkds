#pragma avoid_byte all

#include "code_02133e50.h"
#include "code_021423e4.h"
#include "code_02134890.h"
#include "code_02139e20.h"
#include "code_0200e77c.h"
#include "Main/Net/wbt_os_thread_globals.h"
#include "os_thread.h"
#include "mb_data.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "stream.h"
#include "code_0212d214.h"

void (*gExitTailCallback)(void);
int gExitFunctionCount;
void (*gExitCallback)(void);
void (*gExitFunctions[64])(void);
int gAborted;

void abort(void) {
    raise(1);
    gAborted = 1;
    exit(1);
}

void exit(int status) {
    if (gAborted == 0) {
        RunListNodeCallbacks();
        if (gExitCallback != 0) {
            gExitCallback();
            gExitCallback = 0;
        }
    }
    ExitTail(status);
}

void ExitTail(int status) {
    if (OS_TryLockMutex((OSMutex *) gLockMutexes[0]) == 0) {
        gLockOwnerThreadIds[0] = OSi_ThreadInfo.mListHead->mId;
        gLockHoldCounts[0] = 1;
    } else if (gLockOwnerThreadIds[0] == OSi_ThreadInfo.mListHead->mId) {
        gLockHoldCounts[0]++;
    } else {
        OS_LockMutex((OSMutex *) gLockMutexes[0]);
        gLockOwnerThreadIds[0] = OSi_ThreadInfo.mListHead->mId;
        gLockHoldCounts[0] = 1;
    }
    while (gExitFunctionCount > 0) {
        gExitFunctions[--gExitFunctionCount]();
    }
    if (--gLockHoldCounts[0] == 0) {
        OS_UnlockMutex((OSMutex *) gLockMutexes[0]);
    }
    if (gExitTailCallback != 0) {
        gExitTailCallback();
        gExitTailCallback = 0;
    }
    fflush(0);
    ExitViaSwi();
}
