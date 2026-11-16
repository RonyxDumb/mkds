#include "00/Lib/NitroWiFi/oldest_access_point.h"

WCMApList *WcmGetOldestApList(void) {
    WCMWork *work;

    work = WCMi_GetSystemWork();
    if (work->mPbdBuffer != NULL && work->mNbdBuffer > 0xc) {
        return work->mPbdBuffer->mHead;
    }
    return NULL;
}
