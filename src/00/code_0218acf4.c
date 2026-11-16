#include "00/code_0218acf4.h"
#include "00/code_0218a9bc.h"
#include "00/code_0218ae5c.h"
#include "00/code_0218aea4.h"
#include "00/GameSpy/nonport.h"
#include "00/unk_021b4000.h"

void func_ov000_0218ad44(Unk0218a9bc *p, SbServer *e) {
    Unk0218aa14 a;
    u8 b[0x100];
    s32 c;
    s32 i;
    func_ov000_0218aedc(&p->field8, e);
    e->mPing = func_ov000_0218e8c4();
    a.field1 = 2;
    if ((e->field14 & 0x20) == 0) {
        if (p->field0 == 1) {
            b[0] = 0xfe;
            b[1] = 0xfd;
            b[2] = 0;
            __memcpy(&b[3], &e->mPing, 4);
            if ((e->field14 & 4) != 0) {
                b[7] = p->field40;
                for (i = 0; i < p->field40; i++) {
                    b[i + 8] = p->field2C[i];
                }
                b[p->field40 + 8] = 0;
                b[p->field40 + 9] = 0;
                c = p->field40 + 10;
            } else {
                b[7] = 0xff;
                b[8] = 0xff;
                b[9] = 0xff;
                c = 10;
            }
        } else if ((e->field14 & 4) != 0) {
            __memcpy(b, &"\\basic\\\\info\\", 13);
            c = 13;
        } else {
            __memcpy(b, &"\\status\\", 8);
            c = 8;
        }
        if (e->field0 == p->field28 && (e->field15 & 2) != 0) {
            a.field4 = e->field8;
            a.field2 = e->fieldC;
        } else {
            a.field4 = e->field0;
            a.field2 = e->field4;
        }
        func_ov000_0218e3e4(p->field20, b, c, 0, &a, 8);
    }
}

void func_ov000_0218acf4(Unk0218a9bc *p, s32 a, u32 b, s32 c, UnkFunc *f, void *g) {
    if (c == 0 && data_ov000_021b4d28 != 1) {
        return;
    }
    func_ov000_0218e8b8();
    p->field0 = b;
    p->field4 = a;
    p->field40 = 0;
    p->field44 = f;
    p->field48 = g;
    p->field28 = 0;
    p->field20 = func_ov000_0218e554(2, 2, 0);
    func_ov000_0218ae5c(&p->field14);
    func_ov000_0218ae5c(&p->field8);
}
