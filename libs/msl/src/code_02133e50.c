#pragma avoid_byte all

#include "code_02133e50.h"
#include "code_021423e4.h"
#include "code_02134890.h"
#include "code_02139e20.h"
#include "code_0200e77c.h"
#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"
#include "Main/Net/data_0217e000.h"
#include "stream.h"
#include "code_0212d214.h"

void (*data_0217e984)(void);
int gExitFunctionCount;
void (*data_0217e988)(void);
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
        if (data_0217e988 != 0) {
            data_0217e988();
            data_0217e988 = 0;
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
    if (data_0217e984 != 0) {
        data_0217e984();
        data_0217e984 = 0;
    }
    fflush(0);
    ExitViaSwi();
}
