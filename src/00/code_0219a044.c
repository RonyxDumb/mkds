#include "00/code_0219a044.h"
#include "00/code_0218d000.h"
#include "00/code_0218dc44.h"
#include "00/code_02198000.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a3f4.h"

void func_ov000_0219a044(Unk02197e8c *a) {
    if (a->mUnk_18 == 0) {
        a->mUnk_18 = 1;
        func_ov000_021988e8((Unk02198394 *) a);
        if (func_ov000_02198448((Unk02198394 *) a) != 0) {
            func_ov000_0219a3f8((u32 *) a);
        }
    }
}

void func_ov000_0219a06c(Unk02197e8c *a) {
    s32 b;
    for (b = func_ov000_0218dc44(a->mUnk_10) - 1; b >= 0; b--) {
        func_ov000_0219a220(*(Unk02197fe8 **) func_ov000_0218dbf8(a->mUnk_10, b));
    }
}
