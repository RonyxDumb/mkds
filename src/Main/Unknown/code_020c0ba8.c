#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ae000.h"

s32 func_020c0c2c(Unk0217b498 **a, s32 b) {
    s32 t;
    void *q;
    void *p;
    s32 i;
    s32 n;

    t = 0;
    q = func_021000d0(b);
    p = func_02100138(b);
    if (b == 0x1ae || b == 0x1ab) {
        t = 1;
    }
    if (t != 0) {
        if (p == 0) {
            return 0;
        }
        n = func_021000c8(p);
        if (n == 0) {
            return 0;
        }
    } else {
        if (q == 0) {
            return 0;
        }
        n = func_02100094(q);
        if (n == 0) {
            return 0;
        }
    }
    *a = func_02036bec(func_020364e0(func_020364e8()), 0x14);
    if (t != 0) {
        (*a)->mUnk_00 = (Unk0217b498_00 **) func_0210008c(p);
    } else {
        (*a)->mUnk_00 = (Unk0217b498_00 **) func_02100084(q);
    }
    (*a)->mUnk_04 = 0;
    (*a)->mUnk_08 = n;
    (*a)->mUnk_0c = func_02036bec(func_020364e0(func_020364e8()), n * 8);
    for (i = 0; i < n; i++) {
        func_020b5fe4(&(*a)->mUnk_00[i]->mUnk_04, &(*a)->mUnk_0c[i]);
    }
    (*a)->mUnk_10 = func_020ae730(n * 2, 0x14);
    return 1;
}

s32 func_020c0ba8(Unk0217b498 **a, s32 b) {
    if (b == 0) {
        return 0;
    }
    *a = func_02036bec(func_020364e0(func_020364e8()), 0x14);
    (*a)->mUnk_04 = 0;
    (*a)->mUnk_08 = b;
    (*a)->mUnk_0c = func_02036bec(func_020364e0(func_020364e8()), b * 8);
    (*a)->mUnk_10 = func_020ae730(b, 0x14);
    return 1;
}
