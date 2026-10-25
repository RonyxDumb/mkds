#include "01/code_02194690.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"

void func_ov001_02194a34(void) {
    data_ov001_021a9bd8->mUnk_64 = 1;
    data_ov001_021a9bd8->mUnk_68 = 0;
    func_ov001_02194d78();
}

void func_ov001_02194a20(void) {
    data_ov001_021a9bd8->mUnk_64 = 2;
    data_ov001_021a9bd8->mUnk_68 = 0;
}

void func_ov001_02194a0c(void) {
    data_ov001_021a9bd8->mUnk_64 = 3;
    data_ov001_021a9bd8->mUnk_68 = 0;
}

void func_ov001_021949d4(void) {
    data_ov001_021a9bd8->mUnk_64 = 4;
    data_ov001_021a9bd8->mUnk_68 = 0;
    switch (data_ov001_021a9bd8->mUnk_7c) {
        case 0:
            func_ov001_02194d48();
            break;
        case 1:
            func_ov001_02194d18();
            break;
    }
    func_ov001_02194d78();
}

void func_ov001_021949c0(void) {
    data_ov001_021a9bd8->mUnk_64 = 5;
    data_ov001_021a9bd8->mUnk_68 = 0;
}

void func_ov001_021949ac(void) {
    data_ov001_021a9bd8->mUnk_64 = 6;
    data_ov001_021a9bd8->mUnk_68 = 0;
}

void func_ov001_02194730(void *heap) {
    u32 acc = 0;
    s32 i;
    s32 rem;
    void *p;
    vu16 zero;

    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 1;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 1;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0x8800;
    *(vu16 *) 0x400100a = (*(vu16 *) 0x400100a & 0x43) | 0x1018;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0x5810;
    data_ov001_021a9bd8 = func_02036bec(heap, 0x94);
    data_ov001_021a9bd8->mUnk_5c = heap;
    data_ov001_021a9bd8->mUnk_60 = 0;
    data_ov001_021a9bd8->mUnk_78 = 0;
    data_ov001_021a9bd8->mUnk_7c = 0;
    data_ov001_021a9bd8->mUnk_88 = 0;
    data_ov001_021a9bd8->mUnk_8c = 0;
    for (i = 0; i < 2; i++) {
        (&data_ov001_021a9bd8->mUnk_80)[i] = 0;
    }
    func_ov001_021953d0();
    func_021172a8(heap);
    func_0211dfb4((u32) heap);
    p = func_02111318();
    func_020ae6d4(p, func_0211130c());
    func_02124ed0(heap, data_ov001_021a9bd8->mUnk_08, data_ov001_021a9bd8->mUnk_10, &data_ov001_021a9bd8->mUnk_50);
    func_02124ed0(heap, data_ov001_021a9bd8->mUnk_1c, data_ov001_021a9bd8->mUnk_24, &data_ov001_021a9bd8->mUnk_54);
    data_ov001_021a9bd8->mUnk_58 = func_02047a28("common.bmg");
    func_021243ac(heap, 0, data_ov001_021a9bd8->mUnk_10, 200, 16, 0, data_ov001_021a9bd8->mUnk_04,
                  data_ov001_021a9bd8->mUnk_08, data_ov001_021a9bd8->mUnk_50, 0x8000);
    rem = func_02148ca0();
    for (i = 0; i < 4; i++) {
        rem -= func_021243ac(heap, data_ov001_021a6614[i], data_ov001_021a9bd8->mUnk_24, data_ov001_021a661c[i],
                             data_ov001_021a6624[i], i, data_ov001_021a9bd8->mUnk_18, data_ov001_021a9bd8->mUnk_1c,
                             data_ov001_021a9bd8->mUnk_54, rem);
        rem -= func_021243ac(heap, data_ov001_021a662c[i], data_ov001_021a9bd8->mUnk_24, data_ov001_021a6664[i],
                             data_ov001_021a6634[i], i + 4, data_ov001_021a9bd8->mUnk_18, data_ov001_021a9bd8->mUnk_1c,
                             data_ov001_021a9bd8->mUnk_54, rem);
        rem -= func_021243ac(heap, data_ov001_021a663c[i], data_ov001_021a9bd8->mUnk_24, data_ov001_021a6644[i],
                             data_ov001_021a664c[i], i + 12, data_ov001_021a9bd8->mUnk_18, data_ov001_021a9bd8->mUnk_1c,
                             data_ov001_021a9bd8->mUnk_54, rem);
    }
    data_ov001_021a9bd8->mUnk_74 = 0;
    for (i = 0; i < 8; i++) {
        acc |= func_ov001_02194d04(i);
    }
    if (acc == 0) {
        data_ov001_021a9bd8->mUnk_74 = 16;
    }
    data_ov001_021a9bd8->mUnk_4c = func_02036bec(heap, 0x134);
    zero = 0;
    func_0214cfe4(zero, data_ov001_021a9bd8->mUnk_4c, 0x134);
    func_ov001_02194a50();
}

void func_ov001_021946d0(void) {
    u32 v;

    func_02117218();
    func_0211df38();
    data_ov001_021a9bd8 = 0;
    v = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    v &= ~0x11;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (v << 8);
    v = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    v &= ~0x8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (v << 8);
}

void func_ov001_02194690(void) {
    data_ov001_021a9bd8->mUnk_68++;
    data_ov001_021a9bd8->mUnk_6c = func_020ae4c0(1, -192, 0, data_ov001_021a9bd8->mUnk_68, 10);
    if (data_ov001_021a9bd8->mUnk_68 >= 10) {
        func_ov001_02194a34();
    }
}
