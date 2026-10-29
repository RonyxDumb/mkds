#include "Main/Unknown/code_0200aeec.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

// non-matching: the original reloads the member at 0xc0 of data_0216fde0's object at the start of the else arm (before
// comparing with the member at 0xc4); ours keeps the earlier load, so the code is 4 bytes shorter and the tail differs
void func_0200aeec(Unk0200aeec *a, void *b, void *c, u32 d) {
    Unk0200aeec_head *v1;
    u32 v2;
    u32 v3;
    Unk0200aeec *v4;
    Unk0200aeec *v5;
    v1 = *(Unk0200aeec_head **) &data_0216fde0;
    if (func_0200b018() == 0) {
        func_0200fd1c();
    }
    if (a->mUnk_04_0 != 0) {
        func_0200fd1c();
    }
    if (d > 31) {
        v2 = func_0200dcd8(&v1->mUnk_00);
        if (d == 32) {
            if (v2 != 0) {
                d = v2 - 1;
            } else {
                d = 0;
            }
        } else if (d == 33) {
            if (v2 < 31) {
                d = v2 + 1;
            } else {
                d = 31;
            }
        } else if (d == 34) {
            d = v2;
        } else {
            d = 31;
        }
    }
    v3 = func_0200fca0();
    a->mUnk_04_0 = 1;
    a->mUnk_04_1 = d;
    a->mUnk_08 = b;
    a->mUnk_0c = c;
    if (v1->mUnk_c0 == 0) {
        if (a == &v1->mUnk_c4) {
            *(Unk0200aeec_head **) &data_0216fde0 = 0;
        }
        v1->mUnk_c0 = a;
        func_0200df68(&v1->mUnk_00);
    } else {
        v4 = v1->mUnk_c0;
        if (a == &v1->mUnk_c4) {
            if (v4->mUnk_00 != 0) {
                do {
                    v4 = v4->mUnk_00;
                } while (v4->mUnk_00 != 0);
            }
            v4->mUnk_00 = a;
            *(Unk0200aeec_head **) &data_0216fde0 = 0;
        } else if (v4->mUnk_04_1 > d) {
            v1->mUnk_c0 = a;
            a->mUnk_00 = v4;
        } else {
            for (;;) {
                v5 = v4->mUnk_00;
                if (v5 == 0) {
                    break;
                }
                if (v5->mUnk_04_1 > d) {
                    break;
                }
                v4 = v5;
            }
            a->mUnk_00 = v5;
            v4->mUnk_00 = a;
        }
    }
    func_0200fcb4(v3);
}

u32 func_0200aff8(Unk0200aeec *a) {
    if (a->mUnk_04_0 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
