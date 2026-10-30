#include "00/code_0219c990.h"
#include "00/code_0219c384.h"

void func_ov000_0219c990(s32 a, s32 b) {
    if (data_ov000_021b565c != 0 && a != 0) {
        func_ov000_0219c384(a, b);
        if (data_ov000_021b565c->mUnk_18 != 0) {
            data_ov000_021b565c->mUnk_18(a, 0, data_ov000_021b565c->mUnk_1c);
        }
        func_ov000_0219c93c();
    }
}
