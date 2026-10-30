#include "code_02152a7c.h"
#include "code_02152ac8.h"

#pragma thumb on

void func_02152a7c(Unk02152490 *a, u32 b) {
    a->mUnk_04 = b;
}

void func_02152a80(Unk02152490 *a, u32 b, u32 c) {
    a->mUnk_04 = b;
    a->mUnk_08 = c;
}

void func_02152a88(Unk02152490 *a, u32 b) {
    a->mUnk_08 = b;
}

// non-matching: the original sets r3 to 0 first, then r1 = c, r2 = r3 (the zero argument taken from r3) and loads the
// constant 0x7ff into r3 afterwards; ours does r1 = c, movs r2, #0, ldr r3 (one instruction shorter, size 0x20 against
// 0x24 with the pad word)
void func_02152a8c(Unk02152490 *a, u32 b, u32 c) {
    func_02152ae0(&a->mUnk_00, c, 0, 0x7ff);
    a->mUnk_04 = b;
}

#pragma thumb off
