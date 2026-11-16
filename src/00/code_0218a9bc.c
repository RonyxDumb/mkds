#include "00/code_0218a9bc.h"
#include "00/code_0218ab14.h"
#include "00/code_0218ab18.h"
#include "00/code_0218aea4.h"
#include "00/GameSpy/nonport.h"
#include "00/code_021a3a18.h"

void func_ov000_0218aa14(Unk0218a9bc *p, s32 q) {
    s32 s;
    Unk0218aa14 v1;
    s32 a;
    s32 n;
    SbServer *e;
    s8 v2[0x800];
    a = 8;
    if (q != 0) {
        s = p->field24;
    } else {
        s = p->field20;
    }
    while (func_ov000_0218e668(s) != 0) {
        n = func_ov000_0218e438(s, v2, 0x7ff, 0, &v1, &a);
        if (n == -1) {
            break;
        }
        v2[n] = 0;
        for (e = p->field8.field0; e != NULL; e = e->field20) {
            if ((q != 0 && (e->field15 & 8) != 0 && e->field10 == v1.field4) ||
                (e->field0 == v1.field4 && (e->field4 == v1.field2 || q != 0)) ||
                (e->field0 == p->field28 && (e->field15 & 2) != 0 && e->field8 == v1.field4 &&
                 e->fieldC == v1.field2)) {
                if (q != 0) {
                    if (func_ov000_0218ab14(p, e, v2, n) != 0) {
                        break;
                    }
                } else {
                    if (p->field0 == 1) {
                        func_ov000_0218ab90(p, e, v2, n);
                    } else {
                        func_ov000_0218ab18(p, e, v2, n);
                    }
                    break;
                }
            }
        }
    }
}

void func_ov000_0218a9bc(Unk0218a9bc *p) {
    u32 a;
    SbServer *e;
    a = func_ov000_0218e8c4();
    e = p->field8.field0;
    while (e != NULL) {
        if (a <= e->mPing + 0x9c4) {
            break;
        }
        e->field15 |= 0x10;
        p->field8.field0->mPing = 0x9c4;
        p->field8.field0->field15 &= 0xd3;
        p->field44(p, 1, p->field8.field0, p->field48);
        func_ov000_0218aea4(&p->field8);
        e = p->field8.field0;
    }
}
