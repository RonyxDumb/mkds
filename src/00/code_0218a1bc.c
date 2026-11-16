#include "00/code_0218a1bc.h"
#include "00/code_021898dc.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "code_0200f5ac.h"

u32 func_ov000_0218a1bc(Unk02188ec0 *v1) {
    if (func_ov000_021a8ed4() != 0) {
        func_ov000_02189f64(v1);
        if (v1->fieldD0C_4 == 1) {
            return 0xf;
        }
        return 0xd;
    }
    if ((OS_GetTick() - v1->fieldCB0) * 64 / 0x1ff6210 >= 10) {
        v1->field444[v1->fieldD13].field0 = 1;
        return 0xb;
    }
    return 0xc;
}
