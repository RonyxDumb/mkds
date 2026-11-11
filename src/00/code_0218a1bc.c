#include "00/code_0218a1bc.h"
#include "00/code_021898dc.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "code_0200f5ac.h"

u32 GetIPAddress(ACWORK *work) {
    if (func_ov000_021a8ed4() != 0) {
        CheckSetDNS(work);
        if (work->mUnk_d0c_4 == 1) {
            return 0xf;
        }
        return 0xd;
    }
    if ((OS_GetTick() - work->mUnk_cb0) * 64 / 0x1ff6210 >= 10) {
        work->mUnk_444[work->mUnk_d13].mUnk_00 = 1;
        return 0xb;
    }
    return 0xc;
}
