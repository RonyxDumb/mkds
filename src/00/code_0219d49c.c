#include "00/code_0219d49c.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"

int func_ov000_0219d49c(void) {
    Unk021b5664 *a = data_ov000_021b5664;
    if ((func_0200f5ac() - a->mUnk_0c) * 64 / 0x82ea >= 300) {
        a->mUnk_08 = a->mUnk_08 + 1;
        func_ov000_0218f268(data_ov000_021b5664->mUnk_04);
        data_ov000_021b5664->mUnk_0c = func_0200f5ac();
    }
    return 0;
}
