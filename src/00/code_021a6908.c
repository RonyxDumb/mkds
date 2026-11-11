#include "00/code_021a6908.h"
#include "ITCM/code_01ff8000.h"

BOOL WcmCpsifTryLockMutexInIRQ(OSMutex *mutex) {
    if (mutex->mHolder == NULL) {
        mutex->mHolder = (struct OSThread *) OS_IrqHandler;
        mutex->mLockCount = mutex->mLockCount + 1;
        return 1;
    }
    if (mutex->mHolder == (struct OSThread *) OS_IrqHandler) {
        mutex->mLockCount = mutex->mLockCount + 1;
        return 1;
    }
    return 0;
}
