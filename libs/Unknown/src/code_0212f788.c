#include "code_0212f788.h"

// Sets mUnk_00 to the current value of func_0212f7f8, mUnk_04 to b, mUnk_0c to c and clears mUnk_08.
void func_0212f834(Unk0212f7c8 *a, s32 b, s32 c) {
    a->mUnk_00 = func_0212f7f8(a);
    a->mUnk_04 = b;
    a->mUnk_0c = c;
    a->mUnk_08 = 0;
}

// Returns mUnk_00 + mUnk_08 * (mUnk_04 - mUnk_00) / mUnk_0c, or mUnk_04 once mUnk_08 reaches mUnk_0c.
s32 func_0212f7f8(Unk0212f7c8 *a) {
    s32 n;

    if (a->mUnk_08 >= a->mUnk_0c) {
        return a->mUnk_04;
    }
    n = a->mUnk_00;
    return n + a->mUnk_08 * (a->mUnk_04 - n) / a->mUnk_0c;
}

// Raises mUnk_08 while it is below mUnk_0c.
void func_0212f7e0(Unk0212f7c8 *a) {
    if (a->mUnk_08 < a->mUnk_0c) {
        a->mUnk_08++;
    }
}

// Returns whether mUnk_08 has reached mUnk_0c.
u32 func_0212f7c8(Unk0212f7c8 *a) {
    return a->mUnk_08 >= a->mUnk_0c;
}

// Returns the 12-byte record b of a, or 0 when b is out of range or the first word of the record is -1.
u32 *func_0212f788(Unk0212f788 *a, s32 b) {
    u32 *p;

    if (b < 0) {
        return 0;
    }
    if (b >= a->mUnk_1c) {
        return 0;
    }
    p = (u32 *) ((u8 *) a->mUnk_20 + b * 12);
    if (*p == -1) {
        return 0;
    }
    return p;
}
