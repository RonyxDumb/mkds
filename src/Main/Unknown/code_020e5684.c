#include "Main/Unknown/code_020e5684.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"

void func_020e57a0(Unk020e43a8 *p, Vec3 *param_2, s32 param_3, Vec3 *param_4) {
    Vec3 s;
    s32 y;

    y = p->mUnk_58.y;
    s.x = p->mUnk_58.x;
    s.y = y;
    s.z = 0;
    func_020eafc4(param_2, &p->mUnk_04, (s32 *) &p->mUnk_28, &p->mUnk_58, &s, param_3, param_4);
}

#pragma thumb on

void func_020e576c(void) {
    func_020ea588(&data_0217b820, (void *) func_020d21ec((u32) data_0216c260), 0);
    func_02084968(data_0217b820, 0x3f, 2, 0x294a);
}

void func_020e5684(Unk020e43a8 *p, Unk020e5684 *q) {
    p->mUnk_58.y = (s32) (((s64) p->mUnk_1c.x * 0x4b000) >> 12);
    func_02046be8((u32) &p->mUnk_80, (u32) data_0216c240, 4, (u32) p);
    func_020d720c((Vec3 *) &q->mUnk_0c, (u32 *) &p->mUnk_a0.mUnk_00);
    *(Unk020e5684_a0 *) &p->mUnk_a0.mUnk_0c.y = *(Unk020e5684_a0 *) &p->mUnk_a0.mUnk_00;
    *(s16 *) &p->mUnk_a0.mUnk_18.z = q->mUnk_2c;
    *((s16 *) &p->mUnk_a0.mUnk_18.z + 1) = q->mUnk_2a;
    p->mUnk_c4 = q->mUnk_2e;
    p->mUnk_c6 = (s16) ((q->mUnk_28 << 7) / 0x64);
    if (q->mUnk_30 != 0) {
        p->mUnk_c6 = -p->mUnk_c6;
    }
    p->mUnk_7e = 0;
    if (*(u16 *) &p->mUnk_a0.mUnk_18.z != 0) {
        p->mUnk_cc = 0x1000 / *(u16 *) &p->mUnk_a0.mUnk_18.z;
    } else {
        p->mUnk_cc = 0;
    }
    p->mUnk_c8 = 0;
    p->mUnk_90 = 0;
    p->mUnk_92 = 1;
    p->mUnk_02 |= data_021590b0;
}

#pragma thumb off
