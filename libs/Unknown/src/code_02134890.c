#pragma avoid_byte all

#include "code_02134890.h"
#include "code_02134398.h"
#include "code_0213ee6c.h"
#include "code_0200e904.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"

double func_02134ae8(double a, int n) {
    int e;

    a = func_021400ec(a, &e);
    e += n;
    return func_021401ac(a, e);
}

int func_021349c4(Unk0213c94c *a) {
    if (a == 0) {
        return func_021343b0();
    }
    if (a->mUnk_0d != 0 || a->mUnk_04_7 == 0) {
        return -1;
    }
    if (a->mUnk_04_2 == 1) {
        return 0;
    }
    if (a->mUnk_08_0 >= 3) {
        a->mUnk_08_0 = 2;
    }
    if (a->mUnk_08_0 == 2) {
        a->mUnk_28 = 0;
    }
    if (a->mUnk_08_0 != 1) {
        a->mUnk_08_0 = 0;
        return 0;
    }
    if (func_0213446c(a, 0) != 0) {
        a->mUnk_0d = 1;
        a->mUnk_28 = 0;
        return -1;
    }
    a->mUnk_08_0 = 0;
    a->mUnk_18 = 0;
    a->mUnk_28 = 0;
    return 0;
}

u32 func_02134890(const u8 *a, u32 b, u32 c, Unk0213c94c *d) {
    int i;
    u8 *p;
    u32 r;

    if (d == &data_0216eb7c[1]) {
        i = 3;
    } else if (d == &data_0216eb7c[2]) {
        i = 4;
    } else {
        i = 5;
    }
    p = data_0217eadc[i];
    if (func_0200ec08(p) == 0) {
        data_0217ea94[i] = data_0216ff5c.mUnk_08->mUnk_6c;
        data_0217eab8[i] = 1;
    } else {
        u32 v;

        v = data_0217ea94[i];
        if (v == data_0216ff5c.mUnk_08->mUnk_6c) {
            data_0217eab8[i]++;
        } else {
            func_0200ed34(p);
            data_0217ea94[i] = data_0216ff5c.mUnk_08->mUnk_6c;
            data_0217eab8[i] = 1;
        }
    }
    r = func_02134540(a, b, c, d);
    if (--data_0217eab8[i] == 0) {
        func_0200ecc4(p);
    }
    return r;
}
