#include "00/code_0218a130.h"
#include "00/code_02188ec0.h"
#include "00/code_02187484.h"
#include "00/code_02188000.h"
#include "00/code_021884d8.h"
#include "00/unk_021b4000.h"
#include "00/code_02189350.h"

u32 func_ov000_0218a130(ACWORK *v1) {
    Unk02189350 *p;
    u32 s;

    p = (Unk02189350 *) DWCi_AC_GetMemPtr(1);
    s = DWC_Netcheck_GetError();
    if (s != 0) {
        if (p->mUnk_15 == DWCi_ConvConnectAPType(v1->mUnk_d0d)) {
            p->mUnk_10 = DWC_Netcheck_GetReturnCode();
        }
        DWC_Netcheck_Destroy();
        if (s != 0xb) {
            v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 1;
            return 0xb;
        }
        return 0xf;
    }
    return 0xe;
}
