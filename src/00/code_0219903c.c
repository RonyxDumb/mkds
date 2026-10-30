#include "00/code_0219903c.h"
#include "00/code_02197000.h"
#include "00/code_02197ddc.h"
#include "00/code_02199f80.h"

int func_ov000_0219903c(Unk021981d0 *a, u32 b, int c, int *d) {
    if (func_ov000_02197e58((int) &a->mUnk_50) < c) {
        if (func_ov000_02199f80((u32) a) == 0) {
            return 0;
        }
        *d = 1;
        return 1;
    }
    if (func_ov000_021990f8(a, a->mUnk_64, c) == 0) {
        if (func_ov000_02199f80((u32) a) == 0) {
            return 0;
        }
        *d = 1;
        return 1;
    }
    func_ov000_02197d84((int *) &a->mUnk_50, (u32) data_ov000_021b3fa4, 2);
    func_ov000_02197e20((int *) &a->mUnk_50, b);
    func_ov000_02197ddc((int *) &a->mUnk_50, a->mUnk_64++);
    func_ov000_02197ddc((int *) &a->mUnk_50, a->mUnk_66);
    *d = 0;
    return 1;
}
