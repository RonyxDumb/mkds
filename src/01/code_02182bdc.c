#include "01/code_02182bdc.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"

void func_ov001_02182eb8(Unk02181c3c *param_1, s32 param_2) {
    param_1->mUnk_0a8 += param_2;
    if (param_1->mUnk_0a8 >= 5) {
        param_1->mUnk_0a8 -= 5;
        param_1->mUnk_0a4 += 1;
        if (param_1->mUnk_0a4 >= func_0209b634(data_ov001_021a9b98)) {
            param_1->mUnk_0a4 -= func_0209b634(data_ov001_021a9b98);
        }
    }
}

void func_ov001_02182e84(void) {
    Unk0206bcb0 *c;
    Unk02181c3c *o;

    c = func_0207a974((u16) data_021759c0->mUnk_62);
    o = func_0209bbfc(func_02100138(0x68));
    if (o != 0) {
        func_ov001_02182f1c(o, c);
    }
}

void func_ov001_02182d30(void) {
    Unk0206bcb0 *c;
    Unk02181c3c *o;
    Unk020f41c4_B *rnd;
    s32 a;
    s32 b;
    Unk0210b7a8 arg;

    c = func_0207a974((u16) data_021759c0->mUnk_62);
    o = func_0209bbfc((Unk02181c3c_list *) (func_02100138((u32) (0x68))));
    if (o != 0) {
        rnd = func_020d22d0();
        rnd->mUnk_00 = (s64) rnd->mUnk_08 * (s64) rnd->mUnk_00 + rnd->mUnk_10;
        a = (u16) (((u64) (u32) (rnd->mUnk_00 >> 32) * 0x10000) >> 32);
        rnd = func_020d22d0();
        rnd->mUnk_00 = (s64) rnd->mUnk_08 * (s64) rnd->mUnk_00 + rnd->mUnk_10;
        b = (u32) (((u64) (u32) (rnd->mUnk_00 >> 32) * 0x800) >> 32) + 0x800;
        o->mUnk_0f8 = 3;
        o->mUnk_0b0 = 0x99a;
        o->mUnk_0a0 = 0x10;
        o->mUnk_000.mUnk_04.x = c->mUnk_80.x;
        o->mUnk_000.mUnk_04.y = c->mUnk_80.y + 0x1a000;
        o->mUnk_000.mUnk_04.z = c->mUnk_80.z;
        o->mUnk_000.mUnk_10.x = c->mUnk_a4.x + (s32) (((s64) b * data_0215d4b4[(a >> 4) * 2]) >> 12);
        o->mUnk_000.mUnk_10.y = c->mUnk_a4.y + 0x4000;
        o->mUnk_000.mUnk_10.z = c->mUnk_a4.z + (s32) (((s64) b * data_0215d4b4[(a >> 4) * 2 + 1]) >> 12);
        o->mUnk_000.mUnk_02 &= ~1;
        arg.mUnk_00 = 0x1d9;
        arg.mUnk_04 = 0;
        arg.mUnk_08 = 2;
        arg.mUnk_0c = func_020d4ef4(0);
        func_0210b7a8(&arg);
    }
}

void func_ov001_02182bdc(void) {
    Unk0206bcb0 *c;
    Unk02181c3c *o;
    Unk020f41c4_B *rnd;
    s32 a;
    s32 b;
    u8 n;
    Unk02188950 *v;
    Unk0210b7a8 arg;

    c = func_0207a974((u16) data_021759c0->mUnk_62);
    o = func_0209bbfc((Unk02181c3c_list *) (func_02100138((u32) (0x68))));
    if (o != 0) {
        rnd = func_020d22d0();
        rnd->mUnk_00 = (s64) rnd->mUnk_08 * (s64) rnd->mUnk_00 + rnd->mUnk_10;
        a = (u16) (((u64) (u32) (rnd->mUnk_00 >> 32) * 0x10000) >> 32);
        rnd = func_020d22d0();
        rnd->mUnk_00 = (s64) rnd->mUnk_08 * (s64) rnd->mUnk_00 + rnd->mUnk_10;
        b = (u32) (((u64) (u32) (rnd->mUnk_00 >> 32) * 0x800) >> 32) + 0x800;
        o->mUnk_0f8 = 5;
        o->mUnk_0b0 = 0x99a;
        o->mUnk_0a0 = 0x10;
        o->mUnk_0ac = 0x1e;
        v = 0;
        if (data_021759c0->mUnk_08 == 4) {
            n = 0;
            if (data_021759c0->mUnk_08 == 4) {
                n = func_ov001_02181b54();
            }
            v = func_ov001_02181b68(n);
        }
        o->mUnk_0e8 = &v->mUnk_000.mUnk_04;
        o->mUnk_000.mUnk_04.x = c->mUnk_80.x;
        o->mUnk_000.mUnk_04.y = c->mUnk_80.y + 0x1a000;
        o->mUnk_000.mUnk_04.z = c->mUnk_80.z;
        o->mUnk_000.mUnk_10.x = (s32) (((s64) b * data_0215d4b4[(a >> 4) * 2]) >> 12);
        o->mUnk_000.mUnk_10.y = 0x4000;
        o->mUnk_000.mUnk_10.z = (s32) (((s64) b * data_0215d4b4[(a >> 4) * 2 + 1]) >> 12);
        arg.mUnk_00 = 0x1d9;
        arg.mUnk_04 = 0;
        arg.mUnk_08 = 2;
        arg.mUnk_0c = func_020d4ef4(0);
        func_0210b7a8(&arg);
    }
}
