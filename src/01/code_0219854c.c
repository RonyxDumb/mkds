#include "01/code_0219854c.h"
#include "01/unk_021a6000.h"

void func_ov001_02198768(void) {
    void *a;
    void *b;
    void *c;
    if (func_02036c5c() != 0) {
        data_ov001_021a9be4->mUnk_04 = 1;
        a = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 0xc);
        b = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 0);
        c = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 1);
        func_0212611c((void *) ((u32)a), (void *) ((u32)b), (void *) ((u32)c), (s32) (0));
    }
}

void func_ov001_021986e8(void) {
    void *a;
    void *b;
    void *c;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            data_ov001_021a9be4->mUnk_04 = 2;
            a = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 0xd);
            b = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 0);
            c = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 1);
            func_0212611c((void *) ((u32)a), (void *) ((u32)b), (void *) ((u32)c), (s32) (0));
        } else {
            data_ov001_021a9be4->mUnk_0e = 0xe;
        }
    }
}

void func_ov001_02198624(void) {
    void *a;
    void *b;
    void *c;
    u8 *d;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            d = data_021759d0->mUnk_2a;
            data_0217aa08->mUnk_00->mUnk_31_0 = 1;
            func_0214d168(data_0217aa08->mUnk_00->mUnk_0c, 0, 0x14);
            func_0214d1fc(d, data_0217aa08->mUnk_00->mUnk_0c, 0x14);
            func_02056d40();
            data_ov001_021a9be4->mUnk_04 = 3;
            a = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 0x13);
            b = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 0);
            c = func_020b3f7c(data_ov001_021a9be4->mUnk_14, 1);
            func_0212611c((void *) ((u32)a), (void *) ((u32)b), (void *) ((u32)c), (s32) (1));
        } else {
            data_ov001_021a9be4->mUnk_0e = 0xe;
        }
    }
}

void func_ov001_021985b0(void) {
    s32 v;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                v = data_021759d4->mUnk_10;
            } else {
                v = 0;
            }
        } else {
            v = 1;
        }
        if (v == 0) {
            if (func_02125f60() == 0) {
                data_ov001_021a9be4->mUnk_0e = 3;
            } else {
                data_ov001_021a9be4->mUnk_0e = 0;
            }
        }
    }
}

void func_ov001_02198554(void) {
    func_02125928();
    data_ov001_021a9be4->mUnk_00 = data_ov001_021a9be4->mUnk_04;
    switch (data_ov001_021a9be4->mUnk_00) {
    case 0:
        func_ov001_02198768();
        break;
    case 1:
        func_ov001_021986e8();
        break;
    case 2:
        func_ov001_02198624();
        break;
    case 3:
        func_ov001_021985b0();
        break;
    }
}

void func_ov001_0219854c(void) {
    func_021258f0();
}
