#include "00/code_0218a130.h"
#include "00/code_02188ec0.h"
#include "00/code_02187484.h"
#include "00/code_02188000.h"
#include "00/code_021884d8.h"
#include "00/unk_021b4000.h"
#include "00/code_02189350.h"

u32 ConnectTestProcess(ACWORK *work) {
    Unk02189350 *hold;
    u32 error;

    hold = (Unk02189350 *) DWCi_AC_GetMemPtr(1);
    error = DWC_Netcheck_GetError();
    if (error != 0) {
        if (hold->mUnk_15 == DWCi_ConvConnectAPType(work->mUnk_d0d)) {
            hold->mUnk_10 = DWC_Netcheck_GetReturnCode();
        }
        DWC_Netcheck_Destroy();
        if (error != 0xb) {
            work->mUnk_444[work->mUnk_d13].mUnk_00 = 1;
            return 0xb;
        }
        return 0xf;
    }
    return 0xe;
}
