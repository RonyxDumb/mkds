#pragma avoid_byte all

#include "raise_signal.h"
#include "program_exit.h"
#include "thread_mutex_types.h"
#include "Main/Net/wbt_os_thread_globals.h"
#include "os_thread.h"
#include "mb_data.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "stream.h"
#include "sound_archive_load.h"

RaiseHandlerFunc gRaiseHandlers[7];

int raise(int signalNumber) {
    RaiseHandlerFunc handler;

    if (signalNumber < 1 || signalNumber > 7) {
        return -1;
    }
    if (OS_TryLockMutex((OSMutex *) gLockMutexes[7]) == 0) {
        gLockOwnerThreadIds[7] = OSi_ThreadInfo.mListHead->mId;
        gLockHoldCounts[7] = 1;
    } else if (gLockOwnerThreadIds[7] == OSi_ThreadInfo.mListHead->mId) {
        gLockHoldCounts[7]++;
    } else {
        OS_LockMutex((OSMutex *) gLockMutexes[7]);
        gLockOwnerThreadIds[7] = OSi_ThreadInfo.mListHead->mId;
        gLockHoldCounts[7] = 1;
    }
    handler = gRaiseHandlers[signalNumber - 1];
    if (handler != RAISE_HANDLER_IGNORE) {
        gRaiseHandlers[signalNumber - 1] = 0;
    }
    gLockHoldCounts[7]--;
    if (gLockHoldCounts[7] == 0) {
        OS_UnlockMutex((OSMutex *) gLockMutexes[7]);
    }
    if (handler == RAISE_HANDLER_IGNORE || (handler == 0 && signalNumber == 1)) {
        return 0;
    }
    if (handler == 0) {
        exit(0);
    }
    handler(signalNumber);
    return 0;
}
