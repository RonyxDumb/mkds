#include "01/code_02185bb8.h"
#include "01/callees_0219b000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_02146000.h"

void *func_ov001_02185ef4(void) {
    return func_0209bf48(0, 0, 0);
}

void func_ov001_02185dd0(Unk02185bb8 *param_1) {
    s32 mtx[9];
    s32 r4;
    s32 r6;
    s16 saved;

    func_020d2450((int)param_1);
    param_1->mUnk_07e = (s32)(((s64)param_1->mUnk_09c->mUnk_10 * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
    func_02146d44(mtx, data_0215d4b4[(param_1->mUnk_07e >> 4) * 2], data_0215d4b4[(param_1->mUnk_07e >> 4) * 2 + 1]);
    func_02146dfc(mtx, param_1->mUnk_028, param_1->mUnk_028);
    r4 = (s32)(((s64)param_1->mUnk_01c.x * 0xA000LL) >> 12);
    r6 = (s32)(((s64)param_1->mUnk_01c.y * 0xF000LL) >> 12);
    saved = param_1->mUnk_09c->mUnk_28;
    param_1->mUnk_09c->mUnk_28 = 0x12;
    param_1->mUnk_0a0 = func_020d34d4(param_1, 0x66);
    param_1->mUnk_0a4 = func_020d34d4(param_1, 0x66);
    param_1->mUnk_09c->mUnk_28 = saved;
    func_02147fd8(-(param_1->mUnk_058 + r4), (const Vec3 *)param_1->mUnk_028, &param_1->mUnk_004, &param_1->mUnk_0a0->mUnk_004);
    func_02147fd8(param_1->mUnk_058 + r4, (const Vec3 *)param_1->mUnk_028, &param_1->mUnk_004, &param_1->mUnk_0a4->mUnk_004);
    func_020d2950(param_1->mUnk_0a0, r4);
    func_020d2950(param_1->mUnk_0a4, r4);
    func_020d2584(param_1->mUnk_0a0, r6);
    func_020d2584(param_1->mUnk_0a4, r6);
}

u32 func_ov001_02185d74(Unk02185bb8 *param_1, Unk02185d74 *param_2, u8 *param_3, u8 *param_4) {
    u32 a = *param_3;
    u32 b = *param_4;

    if ((param_2->mUnk_48 & 0x200) != 0 || (data_021759c0->mUnk_08 == 4 ? func_020a1084(param_2->mUnk_74) : 0) != 0) {
        return 0;
    }
    if (a == 1) {
        param_1->mUnk_002 |= data_ov001_021a6580;
        param_1->mUnk_0ac = 2;
    }
    return b;
}

void func_ov001_02185d1c(void *param_1) {
    data_ov001_021a9b9c = func_ov001_0219b478(param_1, "MissionGate.nsbmd");
    func_ov001_0219b2e8(data_ov001_021a9b9c, "MissionGate.nsbtp");
    func_ov001_0219b380(data_ov001_021a9b9c, "MissionGate.nsbma");
    func_0209b940(data_ov001_021a9b9c, 0x3f);
    func_0209ba08(data_ov001_021a9b9c, 2);
    func_020849a0(data_ov001_021a9b9c->mUnk_10, 0x294a);
}

void func_ov001_02185d18(void) {
}

void func_ov001_02185c4c(Unk02185c4c *param_1) {
    s32 i;
    Unk02185bb8 *e;

    if (param_1) {
        for (i = 0; i < param_1->mUnk_04 && (e = param_1->mUnk_00[i]) != 0; i++) {
            if (e->mUnk_09c->mUnk_28 != 0) {
                e->mUnk_002 |= data_ov001_021a6580;
                e->mUnk_0ac = 0;
            } else {
                e->mUnk_002 &= ~1;
                e->mUnk_0ac = 1;
            }
        }
    }
}

void func_ov001_02185ca0(void *param_1, Unk02185bb8 *param_2) {
    s32 buf;

    buf = 0x1e;
    func_01ff9048(0x14, (u32)&buf, 1);
    param_2->mUnk_04c.x = param_2->mUnk_004.x >> 4;
    param_2->mUnk_04c.y = param_2->mUnk_004.y >> 4;
    param_2->mUnk_04c.z = param_2->mUnk_004.z >> 4;
    func_01ff9048(0x19, (u32)param_2->mUnk_028, 0xc);
    func_01ff9048(0x1b, (u32)&param_2->mUnk_01c, 3);
    func_0209b688(data_ov001_021a9b9c, (u16)param_2->mUnk_09c->mUnk_28);
    func_0209b734(data_ov001_021a9b9c, param_2->mUnk_0a8);
    func_0209bb2c((u32)param_1, (int)data_ov001_021a9b9c, (int)param_2);
}

void func_ov001_02185bb8(void *param_1, Unk02185bb8 *param_2) {
    s32 pos;

    switch (param_2->mUnk_0ac) {
    case 0:
        pos = data_021759c0->mUnk_08 == 4 ? func_ov001_02181820() : 0;
        if (pos >= param_2->mUnk_09c->mUnk_28 - 1) {
            param_2->mUnk_002 &= ~1;
            param_2->mUnk_0ac = 1;
        }
        break;
    case 2:
        pos = func_0209b710(data_ov001_021a9b9c);
        param_2->mUnk_0a8++;
        if (param_2->mUnk_0a8 >= pos - 1) {
            param_2->mUnk_0a8 = func_0209b710(data_ov001_021a9b9c) - 1;
            param_2->mUnk_0ac = 1;
        }
        break;
    }
}
