#include "01/code_02196e30.h"
#include "01/code_02195a6c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02125000.h"
#include "01/unk_021a6000.h"
#include "01/code_02193b1c.h"
#include "01/code_021972f4.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/unk_0216c000.h"

void func_ov001_021972b4(void) {
    data_ov001_021a9bdc->mUnk_6c++;
    if (data_ov001_021a9bdc->mUnk_6c >= 0x20) {
        data_ov001_021a9bdc->mUnk_6c = 0;
    }
    if (func_020600b4(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c]) == 0) {
        func_ov001_021972b4();
    }
}

void func_ov001_02197274(void) {
    data_ov001_021a9bdc->mUnk_6c--;
    if (data_ov001_021a9bdc->mUnk_6c < 0) {
        data_ov001_021a9bdc->mUnk_6c = 0x1f;
    }
    if (func_020600b4(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c]) == 0) {
        func_ov001_02197274();
    }
}

s32 func_ov001_02197210(void) {
    u8 buf[0x14];

    if (func_02060228(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], data_ov001_021a6828[0]) != 0) {
        if (func_0205fdb4(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], buf) != 0) {
            return 1;
        }
        func_0212ecc0(data_0217d068, 0, 0x16);
        return 0;
    }
    return 0;
}

void func_ov001_02197058(void) {
    s32 i;
    s32 j;
    u16 n;
    u16 m;

    data_ov001_021a9bdc->mUnk_54 = 0;
    data_ov001_021a9bdc->mUnk_58 = 0;
    data_ov001_021a9bdc->mUnk_5c = -192;
    data_ov001_021a9bdc->mUnk_60 = -256;
    data_ov001_021a9bdc->mUnk_64 = -192;
    data_ov001_021a9bdc->mUnk_68 = -256;
    n = data_ov001_021a9bdc->mUnk_08->mUnk_06;
    m = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_38[0].mUnk_06 = -192;
    data_ov001_021a9bdc->mUnk_38[0].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[1].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[2].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[3].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[4].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[5].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[6].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[n].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[n + 1].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[n + 2].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[n + 3].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_38[n + 4].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_3c[15].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_3c[16].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_3c[12].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_3c[14].mUnk_04 = 0x100;
    data_ov001_021a9bdc->mUnk_3c[m + 8].mUnk_04 = 0x100;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = 0x100;
        data_ov001_021a9bdc->mUnk_3c[m + data_ov001_021a67d4[i]].mUnk_04 = 0x100;
        data_ov001_021a9bdc->mUnk_3c[m + data_ov001_021a6810[i]].mUnk_04 = 0x100;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = 0x100;
        }
    }
    for (j = 0; j < 2; j++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67c4[j]].mUnk_00 = 0;
    }
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_00 = 0;
}

void func_ov001_0219703c(void) {
    data_ov001_021a9bdc->mUnk_54 = 1;
    data_ov001_021a9bdc->mUnk_58 = 0;
    func_ov001_021972f4();
}

void func_ov001_02197024(void) {
    data_ov001_021a9bdc->mUnk_54 = 2;
    data_ov001_021a9bdc->mUnk_58 = 0;
    data_ov001_021a9bdc->mUnk_74 = 0;
}

void func_ov001_02197010(void) {
    data_ov001_021a9bdc->mUnk_54 = 3;
    data_ov001_021a9bdc->mUnk_58 = 0;
}

void func_ov001_02196fd8(void) {
    data_ov001_021a9bdc->mUnk_54 = 4;
    data_ov001_021a9bdc->mUnk_58 = 0;
    switch (data_ov001_021a9bdc->mUnk_70) {
        case 0:
            func_ov001_021972b4();
            break;
        case 1:
            func_ov001_02197274();
            break;
    }
    func_ov001_021972f4();
}

void func_ov001_02196fc4(void) {
    data_ov001_021a9bdc->mUnk_54 = 5;
    data_ov001_021a9bdc->mUnk_58 = 0;
}

void func_ov001_02196fb0(void) {
    data_ov001_021a9bdc->mUnk_54 = 6;
    data_ov001_021a9bdc->mUnk_58 = 0;
}

void func_ov001_02196f80(void) {
    data_ov001_021a9bdc->mUnk_54 = 7;
    data_ov001_021a9bdc->mUnk_58 = 0;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_00 = 1;
    func_0212ecc0(data_0217d068, 0, 4);
}

void func_ov001_02196f64(void) {
    data_ov001_021a9bdc->mUnk_54 = 8;
    data_ov001_021a9bdc->mUnk_58 = 0;
    func_021282c8();
}

void func_ov001_02196ecc(void) {
    u16 buf[0x102];
    Unk021a9bdc *p;
    void *a;
    void *b;

    data_ov001_021a9bdc->mUnk_54 = 9;
    data_ov001_021a9bdc->mUnk_58 = 0;
    buf[0] = 0;
    func_0214cfe4(buf[0], &buf[1], 0x200);
    p = data_ov001_021a9bdc;
    a = func_020b3f7c(p->mUnk_44, data_ov001_021a6980[p->mUnk_6c]);
    func_0212513c(a, func_020b3f7c(p->mUnk_48, 10), &buf[1], 0x200);
    a = func_020b3f7c(data_ov001_021a9bdc->mUnk_40, 0);
    b = func_020b3f7c(data_ov001_021a9bdc->mUnk_40, 1);
    func_02125fd4((u32) &buf[1], (u32) a, (u32) b, 1, 0, 1, 1, 1);
}

void func_ov001_02196eb0(void) {
    data_ov001_021a9bdc->mUnk_54 = 10;
    data_ov001_021a9bdc->mUnk_58 = 0;
    func_02125ed0(0, 11);
}

void func_ov001_02196e88(void) {
    data_ov001_021a9bdc->mUnk_54 = 11;
    data_ov001_021a9bdc->mUnk_58 = 0;
    func_02125fc0();
    func_02125ed0(0, 5);
}

void func_ov001_02196e54(void) {
    data_ov001_021a9bdc->mUnk_54 = 12;
    data_ov001_021a9bdc->mUnk_58 = 0;
    func_02128374();
    func_ov001_021972f4();
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_00 = 0;
}

void func_ov001_02196e30(void) {
    data_ov001_021a9bdc->mUnk_54 = 13;
    data_ov001_021a9bdc->mUnk_58 = 0;
    func_0212ecc0(data_0217d068, 0, 6);
}
