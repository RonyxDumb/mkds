#include "00/code_0218a1bc.h"
#include "00/code_021898dc.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "code_0200f5ac.h"

u32 GetIPAddress(ACWORK *work) {
    if (SOC_GetHostID() != 0) {
        CheckSetDNS(work);
        if (work->mSkipNetCheck == 1) {
            return 0xf;
        }
        return 0xd;
    }
    if ((OS_GetTick() - work->mTimeOut) * 64 / 0x1ff6210 >= 10) {
        work->mFindList[work->mConnectNo].mState = 1;
        return 0xb;
    }
    return 0xc;
}
