#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

u32 func_02007148(u32 a, u32 b) {
    if (b <= a) {
        b = a;
    }
    return b;
}

// non-matching: same instructions, but the original multiplies by 0x5d4 first and then loads data_0216fdac (the literal
// table holds 0x5d4 before the address); ours loads the address first
void func_02007154(u32 a) {
    Unk0216fdac *v1;
    u16 v2;
    u16 v3;
    a = a * 0x5d4;
    v1 = (Unk0216fdac *) ((u8 *) *(Unk0216fdac **) &data_0216fdac + a);
    if (v1->mUnk_1d52 == 0) {
        return;
    }
    if (v1->mUnk_1d4c == 0) {
        return;
    }
    v2 = v1->mUnk_1d48;
    v3 = v1->mUnk_1d4a;
    if (v3 <= v2 && v2 <= v3 + 2) {
        v1->mUnk_1d48 = v2 + 1;
        return;
    }
    v1->mUnk_1d48 = v3;
}

#pragma thumb off
