#pragma avoid_byte all

#include "code_02139e20.h"
#include "code_02133e50.h"
#include "code_0200e77c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"

int raise(int a) {
    Unk02139e20Func f;

    if (a < 1 || a > 7) {
        return -1;
    }
    if (OS_TryLockMutex((OSMutex *) g_AnotherMutex[7]) == 0) {
        g_SomeThreadId[7] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[7] = 1;
    } else if (g_SomeThreadId[7] == g_Os_ThreadInfo.mListHead->mId) {
        g_SomeCounter[7]++;
    } else {
        OS_LockMutex((OSMutex *) g_AnotherMutex[7]);
        g_SomeThreadId[7] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[7] = 1;
    }
    f = gRaiseHandlers[a - 1];
    if (f != (Unk02139e20Func) 1) {
        gRaiseHandlers[a - 1] = 0;
    }
    g_SomeCounter[7]--;
    if (g_SomeCounter[7] == 0) {
        OS_UnlockMutex((OSMutex *) g_AnotherMutex[7]);
    }
    if (f == (Unk02139e20Func) 1 || (f == 0 && a == 1)) {
        return 0;
    }
    if (f == 0) {
        exit(0);
    }
    f(a);
    return 0;
}
