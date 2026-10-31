#include "Main/Unknown/code_020ebef8.h"

#include "01/code_0218175c.h"
#include "code_02147cd8.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_020ec194(Unk020ec194 *param_1) {
    Vec3 v;
    Vec3 *p;

    p = &param_1->mUnk_010;
    p->x = 0;
    p->y = 0;
    p->z = 0;
    param_1->mUnk_004 = param_1->mUnk_0b0;
    func_020d7a3c(&param_1->mUnk_0bc, param_1->mUnk_0c8, &v);
    func_01ffccd0((int *) &param_1->mUnk_028, &v);
}

void func_020ebef8(Unk020ebef8 *param_1, Vec3 *param_2) {
    s32 n;
    Vec3 a;
    Vec3 b;
    Unk020f41c4_B *p;
    Unk020f41c4_A *q;
    s32 i;

    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_0218175c(param_1->mUnk_000.mUnk_00);
    }
    param_1->mUnk_000.mUnk_02 |= *(u16 *) data_021594d8;
    if (data_021759c0->mUnk_08 == 5) {
        return;
    }
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    if (param_1->mUnk_110 <= (u16) (((u64) (u32) (p->mUnk_00 >> 32) * 100) >> 32)) {
        return;
    }
    if (param_1->mUnk_10e == 0) {
        return;
    }
    i = func_020f8a04(0, param_1->mUnk_10e, 1, 1, 0, 0x12);
    q = func_020fa3d0(data_0217bc48[i].mUnk_08, 8, &param_1->mUnk_000.mUnk_04, &param_1->mUnk_0bc);
    if (q == 0) {
        return;
    }
    if ((s64) param_2->x * param_2->x + (s64) param_2->y * param_2->y + (s64) param_2->z * param_2->z >= 16) {
        func_02039860(param_2, &a);
    }
    func_020397a8(&param_1->mUnk_0bc, &a, &b);
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    n = (s32) (((s64) (s32) ((u32) (((u64) (u32) (p->mUnk_00 >> 32) * 0x1800) >> 32) + 0x119a) << 12) >> 12);
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    q->mUnk_5c = *param_2;
    func_02147fd8(n, &a, &param_1->mUnk_000.mUnk_04, &q->mUnk_50);
    func_02147fd8(0, &b, &q->mUnk_50, &q->mUnk_50);
    q->mUnk_68.x = 0xcd;
    q->mUnk_68.y = 0xcd;
    q->mUnk_68.z = 0xcd;
    func_020f6630(q, 2, &param_1->mUnk_000.mUnk_04, param_2, &param_1->mUnk_0bc);
}
