#include "code_021423e4.h"
#pragma avoid_byte all

#include "code_02133e50.h"
#include "code_02134890.h"
#include "code_02139e20.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_02142000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"

void abort(void) {
    raise(1);
    gAborted = 1;
    exit(1);
}

void exit(int a) {
    if (gAborted == 0) {
        RunListNodeCallbacks();
        if (g_BetaFunc != 0) {
            g_BetaFunc();
            g_BetaFunc = 0;
        }
    }
    ExitTail(a);
}

void ExitTail(int a) {
    if (OS_TryLockMutex((OSMutex *) g_AnotherMutex[0]) == 0) {
        g_SomeThreadId[0] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[0] = 1;
    } else if (g_SomeThreadId[0] == g_Os_ThreadInfo.mListHead->mId) {
        g_SomeCounter[0]++;
    } else {
        OS_LockMutex((OSMutex *) g_AnotherMutex[0]);
        g_SomeThreadId[0] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[0] = 1;
    }
    while (gExitFunctionCount > 0) {
        gExitFunctions[--gExitFunctionCount]();
    }
    if (--g_SomeCounter[0] == 0) {
        OS_UnlockMutex((OSMutex *) g_AnotherMutex[0]);
    }
    if (data_0217e984 != 0) {
        data_0217e984();
        data_0217e984 = 0;
    }
    fflush(0);
    sub_2142590();
}
