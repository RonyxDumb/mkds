#include "Main/Unknown/code_020a683c.h"
#include "Main/Unknown/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020a697c(void) {
    s32 v;

    v = data_0217b220 + 1;
    if (v >= 3) {
        v = 0;
    }
    data_0217b220 = v;
}

void func_020a683c(void *a, Unk020a5958 *p, void *b, s32 c) {
    s32 t;
    s32 m[9];
    Vec3 s;
    Vec3 u;
    s32 n;
    s32 x;

    if (p->mUnk_a8 <= 0) {
        return;
    }
    if (p->mUnk_e0 == 2) {
        return;
    }
    if (p->mUnk_e0 == 3) {
        return;
    }
    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mUnk_04), 0xc);
    n = p->mUnk_a8;
    if (n < 0x1000) {
        s.x = n;
        s.y = n;
        s.z = n;
        func_01ff9048(0x1b, &s, 3);
    }
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    x = data_021567a4[data_0217b220] >> 4;
    func_02146d44(m, data_0215d4b4[x * 2 + 1], data_0215d4b4[x * 2]);
    func_01ff9048(0x1a, m, 9);
    u.x = 0x2000;
    u.y = 0x2000;
    u.z = 0x2000;
    func_01ff9048(0x1b, &u, 3);
    func_020e5348(8, c);
}
