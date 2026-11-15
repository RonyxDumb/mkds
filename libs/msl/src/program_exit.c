#pragma avoid_byte all

#include "program_exit.h"
#include "debugger_calls.h"
#include "file_write_flush.h"
#include "raise_signal.h"
#include "thread_mutex_types.h"
#include "Main/Net/wbt_os_thread_globals.h"
#include "thread_scheduler.h"
#include "mb_data.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "sound_stream_control.h"
#include "sound_archive_load.h"

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
