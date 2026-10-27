#include "Main/Unknown/code_021156d4.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_02116888.h"
#include "Main/Unknown/code_02116870.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02116244.h"
#include "Main/Unknown/code_0211621c.h"
#include "Main/Unknown/code_0211606c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02148ca0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_02115fd4(void) {
    s32 a;
    s32 b;
    s16 v;

    if (func_0211606c()) {
        if (data_0217d350->mUnk_7c == 7) {
            data_0217d350->mUnk_80 = data_0217d350->mUnk_74;
            func_021162cc();
        } else {
            a = data_0217d350->mUnk_08->mUnk_06;
            b = data_0217d350->mUnk_18->mUnk_06;
            v = func_02116d10(7 - data_0217d350->mUnk_7c, 0);
            data_0217d350->mUnk_64 = v;
            data_0217d350->mUnk_14[3].mUnk_06 = v;
            data_0217d350->mUnk_14[a].mUnk_06 = v;
            data_0217d350->mUnk_24[1].mUnk_06 = v;
            data_0217d350->mUnk_24[b].mUnk_06 = v;
        }
        data_0217d350->mUnk_7c--;
    } else {
        if (data_0217d350->mUnk_74 != 5 && data_0217d350->mUnk_74 != data_0217d350->mUnk_80) {
            data_0217d350->mUnk_7c = 7;
        }
    }
}

void func_02115e74(void) {
    s32 i;
    u16 n;

    i = 0;
    data_0217d350->mUnk_58 = 0;
    data_0217d350->mUnk_5c = 0;
    data_0217d350->mUnk_70 = ~0xbf;
    n = data_0217d350->mUnk_30->mUnk_06;
    data_0217d350->mUnk_3c[30].mUnk_04 = 0x100;
    data_0217d350->mUnk_3c[31].mUnk_04 = 0x100;
    data_0217d350->mUnk_3c[n + 5].mUnk_06 = ~0xbf;
    for (; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[n + data_0215c4b8[i]].mUnk_04 = 0x100;
    }
    func_021162cc();
    func_02126138((u32) func_020b3f7c(data_0217d350->mUnk_48, 4), (u32) func_020b3f7c(data_0217d350->mUnk_44, 6), 0, 1,
                  1, 1);
    for (i = 0; i < 2; i++) {
        data_0217d350->mUnk_3c[data_0215c4a8[i]].mUnk_00 = 0;
    }
}

void func_02115e60(void) {
    data_0217d350->mUnk_58 = 1;
    data_0217d350->mUnk_5c = 0;
}

void func_02115e44(void) {
    data_0217d350->mUnk_58 = 2;
    data_0217d350->mUnk_5c = 0;
    func_02125fc0();
}

void func_02115e20(void) {
    data_0217d350->mUnk_58 = 3;
    data_0217d350->mUnk_5c = 0;
    func_02128374();
    func_02116244();
}

void func_02115e0c(void) {
    data_0217d350->mUnk_58 = 4;
    data_0217d350->mUnk_5c = 0;
}

void func_02115df8(void) {
    data_0217d350->mUnk_58 = 5;
    data_0217d350->mUnk_5c = 0;
}

void func_02115dc0(void) {
    data_0217d350->mUnk_58 = 6;
    data_0217d350->mUnk_5c = 0;
    switch (data_0217d350->mUnk_78) {
        case 0:
            func_02116230();
            break;
        case 1:
            func_0211621c();
            break;
    }
    func_02116244();
}

void func_02115d90(void) {
    data_0217d350->mUnk_58 = 7;
    data_0217d350->mUnk_5c = 0;
    func_021282c8();
    func_0212ecc0(data_0217d068, 0, 5);
}

void func_02115d08(void) {
    u16 buf[0x10];
    u16 buf2[0x100];
    u16 v;

    data_0217d350->mUnk_58 = 8;
    data_0217d350->mUnk_5c = 0;
    v = func_02116870();
    func_02114298((u16) (v + data_0217d350->mUnk_74), buf, 0x20);
    func_0212513c(buf, func_020b3f7c(data_0217d350->mUnk_48, 5), buf2, 0x200);
    func_02125fd4((u32) buf2, (u32) func_020b3f7c(data_0217d350->mUnk_44, 0),
                  (u32) func_020b3f7c(data_0217d350->mUnk_44, 1), 1, 0, 1, 1, 1);
}

void func_02115cec(void) {
    data_0217d350->mUnk_58 = 9;
    data_0217d350->mUnk_5c = 0;
    func_02125ed0(0, 0xb);
}

void func_02115cc4(void) {
    data_0217d350->mUnk_58 = 0xa;
    data_0217d350->mUnk_5c = 0;
    func_02125fc0();
    func_02125ed0(0, 5);
}

void func_02115ca0(void) {
    data_0217d350->mUnk_58 = 0xb;
    data_0217d350->mUnk_5c = 0;
    func_02128374();
    func_02116244();
}

void func_02115c8c(void) {
    data_0217d350->mUnk_58 = 0xc;
    data_0217d350->mUnk_5c = 0;
}

void func_02115728(void *a) {
    s32 v;
    u16 *p;
    s32 w;
    u16 n;
    u16 z;
    s32 j;
    s32 i;
    u32 p0;
    u32 p1;
    u32 p2;
    u32 p3;
    u32 p4;

    *(volatile u16 *) 0x400100e = (*(volatile u16 *) 0x400100e & ~3) | 1;
    *(volatile u16 *) 0x400100a = (*(volatile u16 *) 0x400100a & 0x43) | 0x1018;
    *(volatile u16 *) 0x400100e = (*(volatile u16 *) 0x400100e & 0x43) | 0x9810;
    data_0217d350 = func_02036bec(a, 0xa4);
    data_0217d350->mUnk_50 = a;
    data_0217d350->mUnk_54 = 3;
    data_0217d350->mUnk_76 = func_02111418();
    data_0217d350->mUnk_74 = func_02111408();
    data_0217d350->mUnk_78 = 0;
    data_0217d350->mUnk_7c = 0;
    data_0217d350->mUnk_80 = data_0217d350->mUnk_74;
    data_0217d350->mUnk_40 = 0;
    data_0217d350->mUnk_84 = 0;
    data_0217d350->mUnk_98 = 0;
    data_0217d350->mUnk_9c = 0;
    for (i = 0; i < 2; i++) {
        data_0217d350->mUnk_90[i] = 0;
    }
    func_02077a28(a);
    func_02116888();
    func_02124ed0(a, data_0217d350->mUnk_08, data_0217d350->mUnk_0c, &data_0217d350->mUnk_14);
    func_02124ed0(a, data_0217d350->mUnk_18, data_0217d350->mUnk_1c, &data_0217d350->mUnk_24);
    func_02124ed0(a, data_0217d350->mUnk_30, data_0217d350->mUnk_38, &data_0217d350->mUnk_3c);
    data_0217d350->mUnk_44 = func_02047a28(data_0216d4a4);
    data_0217d350->mUnk_48 = func_0204799c(data_0216d4b0);
    v = 0x8000;
    v -= func_021243ac(a, 0, data_0217d350->mUnk_0c, 0x8c, 0x10, 0, data_0217d350->mUnk_04, data_0217d350->mUnk_08,
                       data_0217d350->mUnk_14, v);
    v -= func_021243ac(a, 1, data_0217d350->mUnk_0c, 0xaa, 0xe, 1, data_0217d350->mUnk_04, data_0217d350->mUnk_08,
                       data_0217d350->mUnk_14, v);
    func_0212426c(0, 1, data_0217d350->mUnk_0c, func_020b3f7c(data_0217d350->mUnk_48, 0), data_0217d350->mUnk_08,
                  data_0217d350->mUnk_14);
    v -= func_021243ac(a, 0xb, data_0217d350->mUnk_0c, 0x96, 0xe, 2, data_0217d350->mUnk_04, data_0217d350->mUnk_08,
                       data_0217d350->mUnk_14, v);
    func_0212426c(0, 0xb, data_0217d350->mUnk_0c, func_020b3f7c(data_0217d350->mUnk_48, 1), data_0217d350->mUnk_08,
                  data_0217d350->mUnk_14);
    v -= func_021243ac(a, 0xc, data_0217d350->mUnk_0c, 0x46, 0x10, 3, data_0217d350->mUnk_04, data_0217d350->mUnk_08,
                       data_0217d350->mUnk_14, v);
    z = 4;
    n = data_0217d350->mUnk_08->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            v -= func_021243ac(a, data_0215c530[i][j], data_0217d350->mUnk_0c, data_0215c544[i][j], data_0215c558[i][j],
                               z, data_0217d350->mUnk_04, data_0217d350->mUnk_08, data_0217d350->mUnk_14, v);
            z = (u16) (n + data_0215c530[i][j]);
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_0215c530[0][i], data_0217d350->mUnk_0c,
                      func_020b3f7c(data_0217d350->mUnk_48, data_0215c4b0[i]), data_0217d350->mUnk_08,
                      data_0217d350->mUnk_14);
    }
    v -= func_021243ac(a, 0, data_0217d350->mUnk_1c, 0x8c, 0x10, 0, data_0217d350->mUnk_04, data_0217d350->mUnk_18,
                       data_0217d350->mUnk_24, v);
    v -= func_021243ac(a, 1, data_0217d350->mUnk_1c, 0x70, 0x10, 1, data_0217d350->mUnk_04, data_0217d350->mUnk_18,
                       data_0217d350->mUnk_24, v);
    func_0212426c(0, 1, data_0217d350->mUnk_1c, func_020b3f7c(data_0217d350->mUnk_48, 0xb), data_0217d350->mUnk_18,
                  data_0217d350->mUnk_24);
    v -= func_021243ac(a, 0xe, data_0217d350->mUnk_1c, 0xe0, 0x38, 2, data_0217d350->mUnk_04, data_0217d350->mUnk_18,
                       data_0217d350->mUnk_24, v);
    func_0212426c(0, 0xe, data_0217d350->mUnk_1c, func_020b3f7c(data_0217d350->mUnk_48, 0xc), data_0217d350->mUnk_18,
                  data_0217d350->mUnk_24);
    for (i = 0; i < 12; i++) {
        v -= func_021243ac(a, data_0215c584[i], data_0217d350->mUnk_1c, data_0215c59c[i], data_0215c56c[i], i + 3,
                           data_0217d350->mUnk_04, data_0217d350->mUnk_18, data_0217d350->mUnk_24, v);
    }
    w = func_02148ca0();
    for (i = 0, p = data_0215c50c; i < 5; i++) {
        w -= func_021243ac(a, data_0215c4b8[i], data_0217d350->mUnk_38, data_0215c4c4[i], data_0215c4dc[i], *p,
                           data_0217d350->mUnk_2c, data_0217d350->mUnk_30, data_0217d350->mUnk_3c, w);
        p++;
    }
    func_021243ac(a, 5, data_0217d350->mUnk_38, 0xfa, 0x10, 5, data_0217d350->mUnk_2c, data_0217d350->mUnk_30,
                  data_0217d350->mUnk_3c, w);
    func_0212426c(1, 5, data_0217d350->mUnk_38, func_020b3f7c(data_0217d350->mUnk_48, 2), data_0217d350->mUnk_30,
                  data_0217d350->mUnk_3c);
    p0 = 0;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    for (i = 0; i < 5; i++) {
        func_02124a98(data_0215c4e8[i], p0, data_0217d350->mUnk_2c, data_0217d350->mUnk_30);
        func_02124a98(data_0215c4f4[i], p1, data_0217d350->mUnk_2c, data_0217d350->mUnk_30);
        func_02124a98(data_0215c500[i], p2, data_0217d350->mUnk_2c, data_0217d350->mUnk_30);
        func_02124a98(data_0215c50c[i], p3, data_0217d350->mUnk_2c, data_0217d350->mUnk_30);
        func_02124140(data_0215c4b8[i], p4, data_0217d350->mUnk_38, data_0217d350->mUnk_3c, data_0217d350->mUnk_30);
    }
    func_02124140(5, 0, data_0217d350->mUnk_38, data_0217d350->mUnk_3c, data_0217d350->mUnk_30);
    data_0217d350->mUnk_88 = func_02036bec(a, 0x201);
    data_0217d350->mUnk_8c = func_02036bec(a, 0x200);
    func_02115e74();
}

void func_021156d4(void) {
    u32 v;

    func_021113fc(data_0217d350->mUnk_76);
    func_021113f0(data_0217d350->mUnk_74);
    data_0217d350 = 0;
    v = (*(volatile u32 *) 0x4001000 & 0x1f00) >> 8;
    v &= ~9;
    *(volatile u32 *) 0x4001000 = (*(volatile u32 *) 0x4001000 & 0xffffe0ff) | (v << 8);
}

#pragma thumb off
