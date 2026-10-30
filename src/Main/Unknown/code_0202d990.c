#include "Main/Unknown/code_0202d990.h"

#pragma thumb on

s32 func_0202d990(s32 a) {
    s32 i;
    s32 r;
    r = -1;
    for (i = 0; i < (s32) func_0202dd9c(); i++) {
        if (a == func_02061654((u8) data_02174e44->mUnk_894[i] * 0x230 + data_02174e44->mUnk_8c0)) {
            r = data_02174e44->mUnk_894[i];
            break;
        }
    }
    return r;
}

s32 func_0202d9fc(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (func_0206174c(data_02174e44->mUnk_8c0 + (u8) i * 0x230) == 0) {
            return i;
        }
    }
    return -1;
}

s32 func_0202da44(s32 a) {
    s32 i;
    s32 r;
    r = 0;
    for (i = 0; i < (s32) func_0202dd9c(); i++) {
        if (a == func_02061654((u8) data_02174e44->mUnk_894[i] * 0x230 + data_02174e44->mUnk_8c0)) {
            r = 1;
            break;
        }
    }
    return r;
}

void func_0202daa4(s32 a) {
    s32 x;
    if (func_0202dd80(a) == 0) {
        x = data_02174e44->mUnk_814[a];
        func_0205798c(x, (Unk0217aa08_14 *) func_0202ddec());
    } else {
        x = data_02174e44->mUnk_894[a - func_0202ddb0()];
        func_020578fc((u8) x, (Unk0217aa08_14 *) func_0202ddd8());
    }
}

// non-matching: second branch loads the member at 0x8c0 before the one at 0x80c, original loads 0x80c, subtracts, then loads 0x8c0 (constant word order differs, 4 words differ, size matches)
u32 func_0202db04(u32 a) {
    s32 i;
    u8 *p;
    if (func_0202dd80(a) == 0) {
        return func_0202e43c(data_02174e44->mUnk_814[a]);
    }
    i = a - data_02174e44->mUnk_80c;
    p = data_02174e44->mUnk_8c0;
    return func_02061654(p + (u8) data_02174e44->mUnk_894[i] * 0x230);
}

// non-matching: second branch loads the member at 0x8c0 before the one at 0x80c, original loads 0x80c, subtracts, then loads 0x8c0 (constant word order differs, 4 words differ, size matches)
u32 func_0202db68(u32 a) {
    s32 i;
    u32 e;
    u8 *p;
    s32 n;
    if (func_0202dd80(a) == 0) {
        e = func_0202e43c(data_02174e44->mUnk_814[a]);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        return func_02061678(p + n * 0x30);
    }
    i = a - data_02174e44->mUnk_80c;
    return func_02061678((u8) data_02174e44->mUnk_894[i] * 0x230 + data_02174e44->mUnk_8c0);
}

// non-matching: second branch loads the member at 0x8c0 before the one at 0x80c, original loads 0x80c, subtracts, then loads 0x8c0 (constant word order differs, 4 words differ, size matches)
u32 func_0202dbe8(u32 a) {
    s32 i;
    u32 e;
    u8 *p;
    s32 n;
    if (func_0202dd80(a) == 0) {
        e = func_0202e43c(data_02174e44->mUnk_814[a]);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        return func_0206169c(p + n * 0x30);
    }
    i = a - data_02174e44->mUnk_80c;
    return func_0206169c((u8) data_02174e44->mUnk_894[i] * 0x230 + data_02174e44->mUnk_8c0);
}

// non-matching: second branch loads the member at 0x8c0 before the one at 0x80c, original loads 0x80c, subtracts, then loads 0x8c0 (constant word order differs, 4 words differ, size matches)
void func_0202dc68(u32 a, void *b) {
    s32 i;
    u32 e;
    u8 *p;
    s32 n;
    if (func_0202dd80(a) == 0) {
        e = func_0202e43c(data_02174e44->mUnk_814[a]);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        func_020616c0(p + n * 0x30, b);
    } else {
        i = a - data_02174e44->mUnk_80c;
        func_020616c0((u8) data_02174e44->mUnk_894[i] * 0x230 + data_02174e44->mUnk_8c0, b);
    }
}

// non-matching: second branch loads the member at 0x8c0 before the one at 0x80c, original loads 0x80c, subtracts, then loads 0x8c0 (constant word order differs, 4 words differ, size matches)
void func_0202dcf4(u32 a, void *b) {
    s32 i;
    u32 e;
    u8 *p;
    s32 n;
    if (func_0202dd80(a) == 0) {
        e = func_0202e43c(data_02174e44->mUnk_814[a]);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        func_02061704(p + n * 0x30, b);
    } else {
        i = a - data_02174e44->mUnk_80c;
        func_02061704((u8) data_02174e44->mUnk_894[i] * 0x230 + data_02174e44->mUnk_8c0, b);
    }
}

// non-matching: ours branches with blt over `movs r0, #1`, original branches with bge over `movs r0, #0` (the two result moves are swapped, 3 words differ, size matches)
s32 func_0202dd80(s32 a) {
    return a < data_02174e44->mUnk_80c ? 0 : 1;
}

#pragma thumb off
