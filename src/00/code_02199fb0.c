#include "00/code_02199fb0.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02197e8c.h"

u32 func_ov000_02199fb0(int param_1, u32 param_2, u32 param_3) {
    Unk02197fe8 *a = (Unk02197fe8 *) param_1;
    s32 b = a->mUnk_0c;
    if (b < 5) {
        if (a->mUnk_10 != 0) {
            func_ov000_02198514(a);
            if (func_ov000_021982f4(a, param_2, 0, 0) == 0) {
                return 0;
            }
        } else {
            if (b == 4) {
                a->mUnk_14 = 1;
            }
            func_ov000_02198514(a);
        }
    } else if (b != 7) {
        func_ov000_02198514(a);
        if (func_ov000_021981d0(a, (void *) param_3) == 0) {
            return 0;
        }
    }
    return 1;
}
