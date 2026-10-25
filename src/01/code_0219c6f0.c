#include "01/code_0219c6f0.h"
#include "01/unk_021a9000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "01/code_0219ca2c.h"
#include "01/code_0219cdb4.h"
#include "01/code_0219cdd4.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02128210.h"
#include "01/code_0219c000.h"

void func_ov001_0219c950(void) {
    s32 i;
    s32 j;

    data_ov001_021a9bf8->mUnk_0c++;
    if (data_ov001_021a9bf8->mUnk_0c > 10) {
        if ((data_ov001_021a9bf8->mUnk_2c != 0 && func_02128274() != 0) || (data_ov001_021a9bf8->mUnk_2c == 0 && func_02128294() != 0)) {
            data_ov001_021a9bf8->mUnk_24 = data_ov001_021a9bf8->mUnk_28;
            return;
        }
    }
    if (data_ov001_021a9bf8->mUnk_0c > 10) {
        data_ov001_021a9bf8->mUnk_0c = 10;
    }
    data_ov001_021a9bf8->mUnk_14 = func_020ae4c0(1, 0, 0xa0, data_ov001_021a9bf8->mUnk_0c, 10);
    data_ov001_021a9bf8->mUnk_18 = func_020ae4c0(1, 0, -0x100, data_ov001_021a9bf8->mUnk_0c, 10);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][j]].mUnk_04 = func_020ae4c0(1, 0, 0xdc, data_ov001_021a9bf8->mUnk_0c, 10);
        }
    }
}

void func_ov001_0219c8ec(void) {
    s32 i;
    s32 zero = 0;

    for (i = 0; i < 6; i++) {
        if (i == data_ov001_021a9bf8->mUnk_08 && data_ov001_021a9bf8->mUnk_20 != 0) {
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][1]].mUnk_00 = 1;
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][2]].mUnk_00 = 0;
        } else {
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][1]].mUnk_00 = zero;
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][2]].mUnk_00 = 1;
        }
    }
}

void func_ov001_0219c8c8(void) {
    if (data_ov001_021a9bf8->mUnk_10 > 0) {
        data_ov001_021a9bf8->mUnk_10--;
    }
    data_ov001_021a9bf8->mUnk_1c = data_ov001_021a6bd8[data_ov001_021a9bf8->mUnk_10];
}

s32 func_ov001_0219c80c(void) {
    s32 i;

    data_ov001_021a9bf8->mUnk_00 = data_ov001_021a9bf8->mUnk_04;
    switch (data_ov001_021a9bf8->mUnk_00) {
    case 0:
        func_ov001_0219cdd4();
        break;
    case 1:
        func_ov001_0219cdb4();
        break;
    case 2:
        func_ov001_0219cba0();
        break;
    case 3:
        func_ov001_0219caf4();
        break;
    case 4:
        func_ov001_0219ca94();
        break;
    case 5:
        func_ov001_0219ca2c();
        break;
    case 6:
        func_ov001_0219c950();
        break;
    }
    func_ov001_0219c8c8();
    func_ov001_0219c8ec();
    func_ov001_0219cec4();
    func_ov001_0219cf60();
    for (i = 0; i < 2; i++) {
        func_02124c30(data_ov001_021a9bf8->mUnk_1054[i], (&data_ov001_021a9bf8->mUnk_103c)[i], data_ov001_021a9bf8->mUnk_1064[i], (&data_ov001_021a9bf8->mUnk_1078)[i], data_ov001_021a9bf8->mUnk_1034[i]);
    }
    return data_ov001_021a9bf8->mUnk_24;
}

void func_ov001_0219c784(void) {
    *(vu32 *)0x4000000 = (*(vu32 *)0x4000000 & 0xffffe0ff) | 0x1c00;
    *(vu32 *)0x4001000 = (*(vu32 *)0x4001000 & 0xffffe0ff) | 0x1600;
    *(vu16 *)0x400000c = (*(vu16 *)0x400000c & ~3) | 1;
    *(vu16 *)0x4000050 = 0;
    func_0214a40c((u32 *)0x4001050, 0, 2, 6, 10);
    *(vu32 *)0x4000018 = ((data_ov001_021a9bf8->mUnk_14 - data_ov001_021a9bf8->mUnk_1c) << 16) & 0x1ff0000;
}

void func_ov001_0219c6f0(void) {
    void *p3 = 0;
    void *p4 = 0;
    void *p5 = 0;
    void *p0 = 0;
    void *p2 = 0;
    void *p1 = 0;

    func_020b496c(&p0, func_0204799c(data_ov001_021a87b8));
    func_020b4810(&p1, func_0204799c(data_ov001_021a8794));
    func_020b4a7c(&p2, func_0204799c(data_ov001_021a87a8));
    func_020b49f4(&p3, func_0204799c(data_ov001_021a87a4));
    func_020b48ec(&p4, func_0204799c(data_ov001_021a87b4));
    func_020b4a7c(&p5, func_0204799c(data_ov001_021a8798));
    func_0211732c();
}
