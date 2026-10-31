#include "Main/Unknown/code_020a69b4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020a6ae4(Unk020a5958 *p, Unk0206bcb0 *o, u8 *a, u8 *b) {
    u8 v1;
    u8 v2;
    s32 r;
    u16 c;
    s32 n;

    v1 = *a;
    v2 = *b;
    if (o->mUnk_180 != 0 || (o->mUnk_48 & 0x200) != 0 || func_020a1084(o->mUnk_74) != 0) {
        return 0;
    }
    if (v1 == 1) {
        if ((o->mUnk_4c & 0x400000) != 0) {
            return v2;
        }
        if (p->mUnk_c0 > 0) {
            return v2;
        }
        p->mUnk_00.mUnk_02 |= data_021567a0;
        p->mUnk_c0 = 0x19;
        p->mUnk_00.mUnk_04.x = o->mUnk_80.x;
        p->mUnk_00.mUnk_04.y = o->mUnk_80.y + func_020a23a0(o) + 0x7800;
        p->mUnk_00.mUnk_04.z = o->mUnk_80.z;
        p->mUnk_a0 = 0;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0x3000;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_a8 = 0;
        p->mUnk_e0 = 2;
        p->mUnk_c8 = o->mUnk_74;
        p->mUnk_ca = o->mUnk_74;
        func_020a10ac(o->mUnk_74, 1);
        func_020a10f0(o->mUnk_74, 1);
        r = o->mUnk_74 == data_021759c0->mUnk_62 ? 1 : 0;
        c = func_020a1180();
        n = func_020a1154(o->mUnk_74);
        func_0210b98c(p->mUnk_00.mUnk_94, func_02024974(0, r, c, n));
        p->mUnk_e4 = func_0208b7bc(0x7d, &p->mUnk_00.mUnk_04);
        p->mUnk_e8 = 0xe;
    }
    return v2;
}

void func_020a6aa8(void *a) {
    data_0217b224 = func_0209bc74(a, data_021678cc, data_021678dc);
    func_0209b940(data_0217b224, 0x3f);
}

void func_020a6a90(void *a) {
    func_0209bbd0(a, data_0217b224);
}

void func_020a69b4(void *a, Unk020a5958 *p) {
    s32 t;
    Vec3 s;
    s32 n;

    if (p->mUnk_a8 <= 0) {
        return;
    }
    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mUnk_04), 0xc);
    n = p->mUnk_a8;
    if (n != 0x1000) {
        s.x = n;
        s.y = n;
        s.z = n;
        func_01ff9048(0x1b, &s, 3);
    }
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    func_0209b7a0(data_0217b224, p->mUnk_b8, 0);
    func_0209b688(data_0217b224, (u16) p->mUnk_b0);
    func_0209bb2c(a, data_0217b224, p);
}
