#include "01/code_021987d4.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02128244.h"
#include "01/code_02192e78.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/code_0219e89c.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0212b000.h"

void func_ov001_02198ec0(void)
{
    Unk021a9be8 *p;
    s32 sel;
    s32 r5;
    s32 hasB;
    s32 hasA;
    s32 i;
    Unk02175628Index idx;
    u16 v;

    p = data_ov001_021a9be8;
    sel = p->mUnk_08;
    idx = UNK_02175628_INDEX_8;
    hasB = 0;
    r5 = -1;
    hasA = 0;
    v = data_02175628[idx].mUnk_4c;
    if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
        hasA = 1;
    }
    if (hasA == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
        hasB = 1;
    }
    if (hasB != 0) {
        r5 = func_0201ea84(p->mUnk_7c, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) != 0) {
        goto L1;
    } else {
        s32 c = 0;
        s32 d = 0;
        v = data_02175628[idx].mUnk_4c;
        if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
            d = 1;
        }
        if (d == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
            c = 1;
        }
        if (c != 0 && func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) != 0) {
        L1:
            data_ov001_021a9be8->mUnk_04 = 4;
            data_ov001_021a9be8->mUnk_34 = 0;
            for (i = 0; i < 2; i++) {
                data_ov001_021a9be8->mUnk_0c[i] = data_ov001_021a9be8->mUnk_14[i];
            }
            func_02128310(0);
            goto end;
        }
    }
    if (((u16) (data_02175628[idx].mUnk_00 & 1) != 0 && data_ov001_021a9be8->mUnk_08 == 2) || r5 == 2) {
        func_ov001_021993b8();
        if (data_ov001_021a9be8->mUnk_0c[1] == 0) {
            data_0217aa08->mUnk_00->mUnk_31 &= ~0x10;
        } else {
            data_0217aa08->mUnk_00->mUnk_31 |= 0x10;
        }
        func_02056d40();
        if (data_ov001_021a9be8->mUnk_08 == 2) {
            data_ov001_021a9be8->mUnk_38 = 0;
        }
        data_ov001_021a9be8->mUnk_04 = 3;
        data_ov001_021a9be8->mUnk_34 = 0;
        data_ov001_021a9be8->mUnk_08 = 2;
        data_ov001_021a9be8->mUnk_1c = 1;
        func_0212b7e8();
        func_02105ac0(5);
    } else if (r5 == 0) {
        data_ov001_021a9be8->mUnk_08 = 0;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        func_02105ac0(10);
    } else if (r5 == 1) {
        data_ov001_021a9be8->mUnk_08 = 1;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        func_02105ac0(1);
    } else if (func_020ae408(8, 0x40) != 0) {
        data_ov001_021a9be8->mUnk_08--;
        if (data_ov001_021a9be8->mUnk_08 < 0) {
            data_ov001_021a9be8->mUnk_08 = 2;
        }
        func_02105ac0(0);
    } else if (func_020ae408(8, 0x80) != 0
               || (data_ov001_021a9be8->mUnk_08 != 2 && (u16) (data_02175628[idx].mUnk_00 & 1) != 0)) {
        data_ov001_021a9be8->mUnk_08++;
        if (data_ov001_021a9be8->mUnk_08 > 2) {
            data_ov001_021a9be8->mUnk_08 = 0;
        }
        func_02105ac0(0);
    } else if (data_ov001_021a9be8->mUnk_08 != 2 && func_020ae408(8, 0x20) != 0) {
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]--;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][0] = 6;
        if (data_ov001_021a9be8->mUnk_08 == 0) {
            func_02105ac0(10);
        } else {
            func_02105ac0(1);
        }
    } else if (data_ov001_021a9be8->mUnk_08 != 2 && func_020ae408(8, 0x10) != 0) {
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        if (func_020ae408(8, 0x10) != 0) {
            data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][1] = 6;
        }
        if (data_ov001_021a9be8->mUnk_08 == 0) {
            func_02105ac0(10);
        } else {
            func_02105ac0(1);
        }
    } else if (r5 == 3) {
        data_ov001_021a9be8->mUnk_08 = 0;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]--;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][0] = 6;
        func_02105ac0(10);
    } else if (r5 == 4) {
        data_ov001_021a9be8->mUnk_08 = 0;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][1] = 6;
        func_02105ac0(10);
    } else if (r5 == 5) {
        data_ov001_021a9be8->mUnk_08 = 1;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]--;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][0] = 6;
        func_02105ac0(1);
    } else if (r5 == 6) {
        data_ov001_021a9be8->mUnk_08 = 1;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][1] = 6;
        func_02105ac0(1);
    }
end:
    if (data_ov001_021a9be8->mUnk_0c[0] < 0) {
        data_ov001_021a9be8->mUnk_0c[0] = 2;
    }
    if (data_ov001_021a9be8->mUnk_0c[0] > 2) {
        data_ov001_021a9be8->mUnk_0c[0] = 0;
    }
    if (data_ov001_021a9be8->mUnk_0c[1] < 0) {
        data_ov001_021a9be8->mUnk_0c[1] = 1;
    }
    if (data_ov001_021a9be8->mUnk_0c[1] > 1) {
        data_ov001_021a9be8->mUnk_0c[1] = 0;
    }
    if (data_ov001_021a9be8->mUnk_08 == 2 && sel != 2) {
        func_0212b7fc();
    }
    func_ov001_02199420();
}

void func_ov001_02198e94(void)
{
    data_ov001_021a9be8->mUnk_20++;
    if (data_ov001_021a9be8->mUnk_20 >= 10) {
        data_ov001_021a9be8->mUnk_04 = 4;
        data_ov001_021a9be8->mUnk_20 = 0;
    } else if (data_ov001_021a9be8->mUnk_20 >= 5) {
        data_ov001_021a9be8->mUnk_38 = 1;
    }
}

void func_ov001_02198d8c(void)
{
    s32 i;
    s32 j;
    s16 t;
    void *a;
    void *b;

    data_ov001_021a9be8->mUnk_24 = func_020ae4c0(1, 0, -0x8c, data_ov001_021a9be8->mUnk_20, 10);
    data_ov001_021a9be8->mUnk_20++;
    t = func_020ae4c0(1, 0, 250, data_ov001_021a9be8->mUnk_20, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            if (i == 1) {
                data_ov001_021a9be8->mUnk_26[i].mUnk_00 = -t;
            } else {
                data_ov001_021a9be8->mUnk_26[i].mUnk_00 = t;
            }
        }
    }
    data_ov001_021a9be8->mUnk_26[2].mUnk_02 = -func_02128244(data_ov001_021a9be8->mUnk_20);
    if (data_ov001_021a9be8->mUnk_20 >= 10) {
        if (data_ov001_021a9be8->mUnk_20 >= 10 && func_02128294() != 0) {
            data_ov001_021a9be8->mUnk_3c = 0;
            if (data_ov001_021a9be8->mUnk_1c != 0) {
                func_02125ebc(0x21);
                a = func_020b3f7c(data_ov001_021a9be8->mUnk_88, 0x10);
                b = func_020b3f7c(data_ov001_021a9be8->mUnk_8c, 4);
                func_02126230((u32) a, (u32) b);
                data_ov001_021a9be8->mUnk_04 = 5;
                data_ov001_021a9be8->mUnk_20 = 0;
                func_021282c8();
            } else {
                func_ov001_02192ea0(data_ov001_021a9be8->mUnk_34);
            }
        }
    }
}

void func_ov001_02198d20(void)
{
    s32 r;

    if (func_02125f54() != 0) {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                r = data_021759d4->mUnk_10;
            } else {
                r = 0;
            }
        } else {
            r = 1;
        }
        if (r == 0) {
            func_02125ebc(0x23);
            func_02125fc0();
            func_02128374();
        }
    }
    if (func_02125f88() != 0 && func_02128294() != 0) {
        func_ov001_02192ea0(data_ov001_021a9be8->mUnk_34);
    }
}

// non-matching: the first statements use other registers (the object pointer lands in r0 and the first count in r2
// instead of r2 and r1) and the address of data_ov001_021a6a20 is not loaded ahead of the 0x24 constant; the loops match.
void func_ov001_02198bbc(void)
{
    s32 i;
    s32 j;
    u16 a;
    u16 b;
    Unk021a9be8 *p;

    p = data_ov001_021a9be8;
    a = p->mUnk_74->mUnk_06;
    b = p->mUnk_78->mUnk_06;
    p->mUnk_54[data_ov001_021a6a20[0]].mUnk_06 = p->mUnk_24;
    for (i = 0; i < 2; i++) {
        (data_ov001_021a9be8->mUnk_54 + a)[data_ov001_021a6a24[i]].mUnk_06 = data_ov001_021a9be8->mUnk_24;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a5c[i][j]].mUnk_04 = data_ov001_021a9be8->mUnk_26[i].mUnk_00;
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a5c[i][j]].mUnk_06 = data_ov001_021a9be8->mUnk_26[i].mUnk_02;
        }
        (data_ov001_021a9be8->mUnk_58 + b)[data_ov001_021a6a34[i]].mUnk_04 = data_ov001_021a9be8->mUnk_26[i].mUnk_00;
        (data_ov001_021a9be8->mUnk_58 + b)[data_ov001_021a6a34[i]].mUnk_06 = data_ov001_021a9be8->mUnk_26[i].mUnk_02;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][j][0]].mUnk_04 -=
                func_020adc64(6 - data_ov001_021a9be8->mUnk_40[i][0]);
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][j][1]].mUnk_04 +=
                func_020adc64(6 - data_ov001_021a9be8->mUnk_40[i][1]);
        }
    }
}

void func_ov001_02198b58(void)
{
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a2c[i]; j++) {
            if (j == data_ov001_021a9be8->mUnk_0c[i]) {
                data_ov001_021a9be8->mUnk_58[data_ov001_021a6a38[i][j]].mUnk_00 = 1;
            } else {
                data_ov001_021a9be8->mUnk_58[data_ov001_021a6a38[i][j]].mUnk_00 = 0;
            }
        }
    }
}

void func_ov001_02198a6c(void)
{
    s32 i;
    s32 k;

    for (i = 0; i < 3; i++) {
        if (i == data_ov001_021a9be8->mUnk_08 && data_ov001_021a9be8->mUnk_38 != 0) {
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a30[i]].mUnk_00 = 1;
            func_02124100(data_ov001_021a6a34[i], 14, data_ov001_021a9be8->mUnk_84, data_ov001_021a9be8->mUnk_58,
                          data_ov001_021a9be8->mUnk_78);
            for (k = 0; k < data_ov001_021a6a2c[i]; k++) {
                func_02124a20(data_ov001_021a6a38[i][k], 14, data_ov001_021a9be8->mUnk_60, data_ov001_021a9be8->mUnk_78);
            }
        } else {
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a30[i]].mUnk_00 = 0;
            func_02124100(data_ov001_021a6a34[i], 15, data_ov001_021a9be8->mUnk_84, data_ov001_021a9be8->mUnk_58,
                          data_ov001_021a9be8->mUnk_78);
            for (k = 0; k < data_ov001_021a6a2c[i]; k++) {
                func_02124a20(data_ov001_021a6a38[i][k], 15, data_ov001_021a9be8->mUnk_60, data_ov001_021a9be8->mUnk_78);
            }
        }
    }
}

void func_ov001_021989bc(void)
{
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
                for (j = 0; j < 2; j++) {
            if (i == data_ov001_021a9be8->mUnk_08) {
                if (data_ov001_021a9be8->mUnk_40[i][j] > 0) {
                    data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][0][j]].mUnk_00 = 1;
                    data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][1][j]].mUnk_00 = 1;
                    data_ov001_021a9be8->mUnk_40[i][j]--;
                } else {
                    data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][0][j]].mUnk_00 = 0;
                    data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][1][j]].mUnk_00 = 1;
                }
            } else {
                data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][0][j]].mUnk_00 = 0;
                data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][1][j]].mUnk_00 = 0;
            }
        }
    }
}

void func_ov001_02198918(void)
{
    Unk021a9be8 *p;

    data_ov001_021a9be8->mUnk_00 = data_ov001_021a9be8->mUnk_04;
    switch (data_ov001_021a9be8->mUnk_00) {
    case 0:
        func_ov001_021992dc();
        break;
    case 1:
        func_ov001_021992a0();
        break;
    case 2:
        func_ov001_02198ec0();
        break;
    case 3:
        func_ov001_02198e94();
        break;
    case 4:
        func_ov001_02198d8c();
        break;
    case 5:
        func_ov001_02198d20();
        break;
    }
    func_0212b80c();
    func_ov001_02198bbc();
    func_ov001_02198b58();
    func_ov001_02198a6c();
    func_ov001_021989bc();
    p = data_ov001_021a9be8;
    func_02124c30(p->mUnk_74, p->mUnk_5c, p->mUnk_80, func_ov001_0219e920(), p->mUnk_54);
    p = data_ov001_021a9be8;
    func_02124c30(p->mUnk_78, p->mUnk_60, p->mUnk_84, func_ov001_0219e90c(), p->mUnk_58);
}

void func_ov001_02198878(void)
{
    u32 plane;

    if (data_ov001_021a9be8->mUnk_3c != 0) {
        plane = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        plane |= 2;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (plane << 8);
    } else {
        plane = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        plane &= ~2;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (plane << 8);
    }
    func_0214a40c((u32 *) 0x4001050, 0, 2, 6, 10);
    *(vu32 *) 0x4000010 = (-data_ov001_021a9be8->mUnk_24 << 16) & 0x1ff0000;
    *(vu32 *) 0x4000014 = (-data_ov001_021a9be8->mUnk_24 << 16) & 0x1ff0000;
}

void func_ov001_02198854(void)
{
    UnkFunc *table[4] = { func_ov001_02199640, func_ov001_021995f8, func_ov001_02198918, func_ov001_02198878 };

    func_ov001_02192eac(table);
}

void func_ov001_021987d4(void *heap, s16 param_2)
{
    Unk02125de0Arg arg;

    data_ov001_021a9be4 = func_02036bec(heap, 0x18);
    data_ov001_021a9be4->mUnk_08 = heap;
    data_ov001_021a9be4->mUnk_10 = func_021250b0(heap);
    arg.mUnk_00 = 1;
    arg.mUnk_04 = func_020b403c(1);
    arg.mUnk_08 = 0;
    arg.mUnk_0c = 1;
    arg.mUnk_10 = 0;
    arg.mUnk_14 = 0;
    arg.mUnk_18 = 0;
    arg.mUnk_1c = 1;
    arg.mUnk_20 = 1;
    arg.mUnk_24 = 0;
    func_02125c2c();
    func_02125de0(heap, &arg);
    data_ov001_021a9be4->mUnk_0c = param_2;
    data_ov001_021a9be4->mUnk_0e = -1;
    data_ov001_021a9be4->mUnk_00 = 0;
    data_ov001_021a9be4->mUnk_04 = data_ov001_021a9be4->mUnk_00;
    data_ov001_021a9be4->mUnk_14 = func_02047a28("common.bmg");
}
