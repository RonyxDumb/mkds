#pragma avoid_byte all

#include "program_exit.h"
#include "swi_runtime_support.h"
#include "file_write_flush.h"
#include "raise_signal.h"
#include "thread_mutex_types.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "sound_stream_control.h"
#include "sound_archive_load.h"

void (*gExitTailCallback)(void);
int gExitFunctionCount;
void (*g_BetaFunc)(void);
void (*gExitFunctions[64])(void);
int g_ZetaValue;

void OnAssertionFailed(void) {
    raise(1);
    g_ZetaValue = 1;
    CheckZetaInvokeBeta(1);
}

void CheckZetaInvokeBeta(int status) {
    if (g_ZetaValue == 0) {
        RunListNodeCallbacks();
        if (g_BetaFunc != 0) {
            g_BetaFunc();
            g_BetaFunc = 0;
        }
    }
    ExitTail(status);
}

void ExitTail(int status) {
    if (Os_Mutex_TryLock((OSMutex *) g_AnotherMutex[0]) == 0) {
        g_SomeThreadId[0] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[0] = 1;
    } else if (g_SomeThreadId[0] == g_Os_ThreadInfo.mListHead->mId) {
        g_SomeCounter[0]++;
    } else {
        Os_Mutex_Lock((OSMutex *) g_AnotherMutex[0]);
        g_SomeThreadId[0] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[0] = 1;
    }
    while (gExitFunctionCount > 0) {
        gExitFunctions[--gExitFunctionCount]();
    }
    if (--g_SomeCounter[0] == 0) {
        Os_Mutex_Unlock((OSMutex *) g_AnotherMutex[0]);
    }
    if (gExitTailCallback != 0) {
        gExitTailCallback();
        gExitTailCallback = 0;
    }
    fflush(0);
    ExitViaSwi();
}
