#include "01/code_0218f634.h"

#include "01/code_02181a68.h"
#include "01/code_02188000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218f000.h"

// non-matching: same instructions up to the 64-bit multiplies, then x/z and the sin/cos high words land in different
// registers and stack slots (the original keeps the high word of z in r7 and spills those of x, sin and cos; it is 4 bytes longer)
void func_ov001_0218f724(Unk02188950 *param_1) {
    Vec3 local_1;
    Vec3 local_2;
    u32 angle;
    s32 sin;
    s32 cos;
    s32 x;
    s32 z;
    func_021484d0(data_021759c0->mUnk_08 == 4 ? func_ov001_02181a94() : 0,
                  data_021759c0->mUnk_08 == 4 ? func_ov001_02181a88() : 0, &local_1);
    local_1.y = 0;
    angle = 0;
    if (data_021759c0->mUnk_08 == 4) {
        angle = func_ov001_02181a68();
    }
    angle = (data_021759c0->mUnk_08 == 4 ? func_ov001_02181a78() : 0) - angle;
    func_021484d0(&param_1->mUnk_004, data_021759c0->mUnk_08 == 4 ? func_ov001_02181a94() : 0, &local_2);
    cos = data_0215d4b4[((u16)angle >> 4) * 2 + 1];
    x = local_2.x;
    sin = data_0215d4b4[((u16)angle >> 4) * 2];
    z = local_2.z;
    local_1.x += (s32)((s64)x * cos >> 12) + (s32)((s64)z * sin >> 12) - x;
    local_1.z += (s32)((s64)z * cos >> 12) - (s32)((s64)x * sin >> 12) - z;
    func_ov001_02188950(param_1, &local_1);
}

void func_ov001_0218f6d8(Unk02188950 *param_1) {
    Vec3 local;
    func_021484d0(data_021759c0->mUnk_08 == 4 ? func_ov001_02181a94() : 0,
                  data_021759c0->mUnk_08 == 4 ? func_ov001_02181a88() : 0, &local);
    local.y = 0;
    func_ov001_02188950(param_1, &local);
}

s32 func_ov001_0218f688(Unk02188950 *param_1) {
    Unk0206bcb0 *obj = func_0207a974((u16)data_021759c0->mUnk_62);
    if ((obj->mUnk_48 & 0x200) == 0) {
        func_ov001_02188998(param_1, &obj->mUnk_80);
        func_ov001_02188d8c((Unk02188950 *) (param_1), (Vec3 *) (&obj->mUnk_80));
    }
    func_ov001_0218f6d8(param_1);
    return 0;
}

s32 func_ov001_0218f634(Unk02188950 *param_1) {
    Unk0206bcb0 *obj = func_0207a974((u16)data_021759c0->mUnk_62);
    if ((obj->mUnk_48 & 0x200) == 0) {
        func_ov001_02188998(param_1, &obj->mUnk_80);
        func_ov001_02188d8c((Unk02188950 *) (param_1), (Vec3 *) (&obj->mUnk_80));
    }
    func_ov001_0218f6d8(param_1);
    func_02061860();
    return 0;
}
