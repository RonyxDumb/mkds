#pragma avoid_byte all

#include "code_02133da8.h"
#include "code_021423e4.h"

// non-matching: hand-written routine (the argument registers are pushed around the call)
u32 func_02133e04(u32 a, u32 b) {
    u32 *p;
    u32 v;

    a = (a & 0x1f) | ((a & 0x1f0000) >> 8);
    b = (b & 0x1f) | ((b & 0x1f0000) >> 8);
    p = func_02142578();
    v = *p;
    *p = (v & ~a) ^ b;
    return (v & 0x1f) | ((v & 0x1f00) << 8) | 0x40000000;
}

// non-matching: hand-written routine (the argument registers are pushed around the call)
u32 func_02133ddc(u32 a, u32 b) {
    u32 *p;
    u32 v;

    p = func_02142578();
    v = *p;
    *p = (v & ~a) ^ b;
    return v;
}

// non-matching: 0x3c bytes, original 0x34; 16 lines differ; first: original `bl T`, ours `sub sp, sp, #4`
void func_02133da8(void) {
    Unk0217ee98 *p;

    *func_02142578() = 0;
    p = func_02142584();
    p->mUnk_04 = 0;
    p->mUnk_08 = 0;
    p->mUnk_0c = 0;
    p->mUnk_10 = 0;
    p->mUnk_14 = 0;
}
