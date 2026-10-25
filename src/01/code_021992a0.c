#include "01/code_021992a0.h"
#include "01/code_021987d4.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212b000.h"
#include "01/code_0219e89c.h"
#include "01/code_02192000.h"
#include "01/code_02199988.h"
#include "01/code_02199000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02108000.h"

void func_ov001_02199964(void)
{
    UnkFunc *tbl[4] = { func_ov001_02199f44, func_ov001_02199f38, func_ov001_021999a8, func_ov001_02199988 };
    func_ov001_02192eac(tbl);
}

void func_ov001_021997dc(void)
{
    s32 i;

    {
        s32 v0 = 0x8000;
        u8 a[2][2] = { { 0xdc, 0x10 }, { 0xf0, 0x50 } };
        s32 c[2] = { 0xb, 0xc };

        for (i = 0; i < 2; i++) {
            v0 -= func_021243ac(data_ov001_021a9be8->mUnk_50, data_ov001_021a6a24[i], data_ov001_021a9be8->mUnk_80, a[i][0], a[i][1], i, data_ov001_021a9be8->mUnk_5c, data_ov001_021a9be8->mUnk_74, data_ov001_021a9be8->mUnk_54, v0);
            func_0212426c(0, data_ov001_021a6a24[i], data_ov001_021a9be8->mUnk_80, func_020b3f7c(data_ov001_021a9be8->mUnk_88, c[i]), data_ov001_021a9be8->mUnk_74, data_ov001_021a9be8->mUnk_54);
        }
    }
    {
        s32 v2 = func_02148ca0();
        void *v1;
        u8 b[3][2] = { { 0x9b, 0x10 }, { 0xa0, 0x10 }, { 0x32, 0x10 } };
        s32 d[3] = { 0, 2, 4 };

        for (i = 0; i < 3; i++) {
            v1 = data_ov001_021a9be8->mUnk_88;
            if (i == 2) {
                v1 = data_ov001_021a9be8->mUnk_8c;
            }
            v2 -= func_021243ac(data_ov001_021a9be8->mUnk_50, data_ov001_021a6a34[i], data_ov001_021a9be8->mUnk_84, b[i][0], b[i][1], data_ov001_021a6a30[i], data_ov001_021a9be8->mUnk_60, data_ov001_021a9be8->mUnk_78, data_ov001_021a9be8->mUnk_58, v2);
            func_0212426c(1, data_ov001_021a6a34[i], data_ov001_021a9be8->mUnk_84, func_020b3f7c(v1, d[i]), data_ov001_021a9be8->mUnk_78, data_ov001_021a9be8->mUnk_58);
        }
    }
}

void func_ov001_02199640(void *param_1)
{
    s32 i;

    data_ov001_021a9be8 = func_02036bec(param_1, 0x90);
    data_ov001_021a9be8->mUnk_50 = param_1;
    data_ov001_021a9be8->mUnk_00 = 0;
    data_ov001_021a9be8->mUnk_04 = 0;
    data_ov001_021a9be8->mUnk_08 = 0;
    data_ov001_021a9be8->mUnk_20 = 0;
    data_ov001_021a9be8->mUnk_38 = 1;
    func_ov001_02199464();
    func_0212b928(param_1, data_ov001_021a9be8->mUnk_70, 3);
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov001_021a6a28[i], 1, data_ov001_021a9be8->mUnk_60, data_ov001_021a9be8->mUnk_78);
    }
    func_020ae6d4(func_ov001_0219e920(), func_ov001_0219e90c());
    func_02124ed0(param_1, data_ov001_021a9be8->mUnk_74, data_ov001_021a9be8->mUnk_80, &data_ov001_021a9be8->mUnk_54);
    func_02124ed0(param_1, data_ov001_021a9be8->mUnk_78, data_ov001_021a9be8->mUnk_84, &data_ov001_021a9be8->mUnk_58);
    data_ov001_021a9be8->mUnk_88 = func_0204799c(data_ov001_021a8644);
    data_ov001_021a9be8->mUnk_8c = func_02047a28(data_ov001_021a8650);
    func_ov001_021997dc();
    data_ov001_021a9be8->mUnk_24 = -140;
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            data_ov001_021a9be8->mUnk_26[i].mUnk_00 = 0;
            data_ov001_021a9be8->mUnk_26[i].mUnk_02 = 0x28;
        } else if (i == 1) {
            data_ov001_021a9be8->mUnk_26[i].mUnk_00 = 250;
            data_ov001_021a9be8->mUnk_26[i].mUnk_02 = 0;
        } else {
            data_ov001_021a9be8->mUnk_26[i].mUnk_00 = -250;
            data_ov001_021a9be8->mUnk_26[i].mUnk_02 = 0;
        }
    }
    func_ov001_02199374();
    if (data_0217aa08->mUnk_00->mUnk_31_4 == 0) {
        data_ov001_021a9be8->mUnk_0c[1] = 0;
    } else {
        data_ov001_021a9be8->mUnk_0c[1] = 1;
    }
    for (i = 0; i < 2; i++) {
        data_ov001_021a9be8->mUnk_14[i] = data_ov001_021a9be8->mUnk_0c[i];
    }
    func_ov001_02198bbc();
    func_ov001_02198b58();
    for (i = 0; i < 2; i++) {
        data_ov001_021a9be8->mUnk_40[i][0] = 0;
        data_ov001_021a9be8->mUnk_40[i][1] = 0;
    }
    data_ov001_021a9be8->mUnk_1c = 0;
    data_ov001_021a9be8->mUnk_3c = 1;
    func_021281c8(0xe);
}

void func_ov001_021995f8(void)
{
    u32 v;

    func_ov001_02199374();
    func_ov001_02199420();
    v = (*(vu32 *) 0x04000000 & 0x1f00) >> 8;
    *(vu32 *) 0x04000000 = (*(vu32 *) 0x04000000 & 0xffffe0ff) | ((v & ~2) << 8);
    func_0212b91c();
    data_ov001_021a9be8 = 0;
}

void func_ov001_02199464(void)
{
    Unk020b4934 *a;
    Unk020b47d8 *b;
    Unk020b4a44 *c;

    func_020b4934(&a, func_0204799c(data_ov001_021a84ac));
    func_020b47d8(&b, func_0204799c(data_ov001_021a84c8));
    func_020b4a44(&c, func_0204799c(data_ov001_021a84e4));
    data_ov001_021a9be8->mUnk_74 = func_0204799c(data_ov001_021a8500);
    data_ov001_021a9be8->mUnk_78 = func_0204799c(data_ov001_021a851c);
    data_ov001_021a9be8->mUnk_7c = func_0204799c(data_ov001_021a8538);
    data_ov001_021a9be8->mUnk_80 = func_0204799c(data_ov001_021a8554);
    data_ov001_021a9be8->mUnk_84 = func_0204799c(data_ov001_021a8570);
    func_020b49bc(&data_ov001_021a9be8->mUnk_64, func_0204799c(data_ov001_021a858c));
    func_020b48b4(&data_ov001_021a9be8->mUnk_5c, func_0204799c(data_ov001_021a85ac));
    func_020b4a44(&data_ov001_021a9be8->mUnk_6c, func_0204799c(data_ov001_021a85cc));
    func_020b49bc(&data_ov001_021a9be8->mUnk_68, func_0204799c(data_ov001_021a85e8));
    func_020b48b4(&data_ov001_021a9be8->mUnk_60, func_0204799c(data_ov001_021a8608));
    func_020b4a44(&data_ov001_021a9be8->mUnk_70, func_0204799c(data_ov001_021a8628));
    func_02016468(5, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(9, 0, b->mUnk_0c, b->mUnk_08);
    func_02016468(0xf, 0x20, c->mUnk_0c + 0x10, 0x20);
    func_02016468(0x13, 0, data_ov001_021a9be8->mUnk_64->mUnk_14, data_ov001_021a9be8->mUnk_64->mUnk_10);
    func_02016468(0x23, 0, data_ov001_021a9be8->mUnk_68->mUnk_14, data_ov001_021a9be8->mUnk_68->mUnk_10);
    func_02016468(0xe, 0, data_ov001_021a9be8->mUnk_6c->mUnk_0c, data_ov001_021a9be8->mUnk_6c->mUnk_08);
    func_02016468(0x1e, 0, data_ov001_021a9be8->mUnk_70->mUnk_0c, data_ov001_021a9be8->mUnk_70->mUnk_08);
}

void func_ov001_02199420(void)
{
    switch (data_ov001_021a9be8->mUnk_0c[0]) {
    case 1:
        func_02108e94(0);
        break;
    case 0:
        func_02108e94(1);
        break;
    case 2:
        func_02108e94(2);
        break;
    }
}

void func_ov001_021993b8(void)
{
    switch (data_ov001_021a9be8->mUnk_0c[0]) {
    case 1:
        data_0217aa08->mUnk_00->mUnk_31_1 = 1;
        break;
    case 0:
        data_0217aa08->mUnk_00->mUnk_31_1 = 0;
        break;
    case 2:
        data_0217aa08->mUnk_00->mUnk_31_1 = 2;
        break;
    }
}

void func_ov001_02199374(void)
{
    switch (data_0217aa08->mUnk_00->mUnk_31_1) {
    case 1:
        data_ov001_021a9be8->mUnk_0c[0] = 1;
        break;
    case 0:
        data_ov001_021a9be8->mUnk_0c[0] = 0;
        break;
    case 2:
        data_ov001_021a9be8->mUnk_0c[0] = 2;
        break;
    }
}

void func_ov001_021992dc(void)
{
    s32 i;
    s32 j;
    s16 v;

    data_ov001_021a9be8->mUnk_20++;
    data_ov001_021a9be8->mUnk_24 = func_020ae4c0(1, -140, 0, data_ov001_021a9be8->mUnk_20, 10);
    v = func_020ae4c0(1, 250, 0, data_ov001_021a9be8->mUnk_20, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            if (i == 1) {
                data_ov001_021a9be8->mUnk_26[i].mUnk_00 = -v;
            } else {
                data_ov001_021a9be8->mUnk_26[i].mUnk_00 = v;
            }
        }
    }
    if (data_ov001_021a9be8->mUnk_20 >= 10) {
        data_ov001_021a9be8->mUnk_04 = 1;
        data_ov001_021a9be8->mUnk_20 = 0;
    }
}

void func_ov001_021992a0(void)
{
    data_ov001_021a9be8->mUnk_20++;
    data_ov001_021a9be8->mUnk_26[2].mUnk_02 = -func_0212825c(data_ov001_021a9be8->mUnk_20);
    if (data_ov001_021a9be8->mUnk_20 >= 10) {
        data_ov001_021a9be8->mUnk_04 = 2;
        data_ov001_021a9be8->mUnk_20 = 0;
    }
}
