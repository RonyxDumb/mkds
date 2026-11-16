#pragma avoid_byte all

#include "raise_signal.h"
#include "program_exit.h"
#include "thread_mutex_types.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "sound_stream_control.h"
#include "sound_archive_load.h"

RaiseHandlerFunc gRaiseHandlers[7];

int raise(int signalNumber) {
    RaiseHandlerFunc handler;

    if (signalNumber < 1 || signalNumber > 7) {
        return -1;
    }
    if (Os_Mutex_TryLock((OSMutex *) g_AnotherMutex[7]) == 0) {
        g_SomeThreadId[7] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[7] = 1;
    } else if (g_SomeThreadId[7] == g_Os_ThreadInfo.mListHead->mId) {
        g_SomeCounter[7]++;
    } else {
        Os_Mutex_Lock((OSMutex *) g_AnotherMutex[7]);
        g_SomeThreadId[7] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[7] = 1;
    }
    handler = gRaiseHandlers[signalNumber - 1];
    if (handler != RAISE_HANDLER_IGNORE) {
        gRaiseHandlers[signalNumber - 1] = 0;
    }
    g_SomeCounter[7]--;
    if (g_SomeCounter[7] == 0) {
        Os_Mutex_Unlock((OSMutex *) g_AnotherMutex[7]);
    }
    if (handler == RAISE_HANDLER_IGNORE || (handler == 0 && signalNumber == 1)) {
        return 0;
    }
    if (handler == 0) {
        CheckZetaInvokeBeta(0);
    }
    handler(signalNumber);
    return 0;
}
