#include "Main/Unknown/code_02091828.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"

u8 func_02091828(Unk020912a0 *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u8 r;
    r = *d;
    if (*c == 1) {
        a->mUnk_b8 = 0xf333;
        a->mUnk_bc = 0x8000;
        a->mUnk_b0 = 0;
        a->mUnk_b4 = 0;
        a->mUnk_00.mUnk_02 = a->mUnk_00.mUnk_02 | *(u16 *) &data_02156458;
        a->mUnk_c8 = 1;
        func_020d26f8(&a->mUnk_00, b);
    }
    return r;
}
