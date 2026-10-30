#include "Main/Unknown/code_0200b200.h"

#pragma thumb on

// non-matching: 0x148 bytes, original 0x144; 51 lines differ; first: original `ldr r0, [pc, #288]`, ours `ldr r0,
// [pc, #292]`
void func_0200b200(void) {
    Unk0200c16c v1;
    Unk0200c12c v2;
    switch ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e) {
        case 5:
            v2.mUnk_00 = (*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f08;
            v2.mUnk_1a = 1;
            v2.mUnk_1c = (*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0c;
            func_0214d1fc((*(Unk0216fde8 **) &data_0216fde8)->mUnk_05c4, v2.mUnk_04, 0x16);
            v1.mUnk_00 = 7;
            *(u8 *) &v1.mUnk_02 = func_0200c12c((u8 *) &v1 + 3, &v2);
            if (func_0200c16c(&v1, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0) != 0) {
                func_0200bc78(8, 0xffff, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            }
            break;
        case 7:
            v1.mUnk_00 = 8;
            func_0200c16c(&v1, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            func_0200bc78(8, 0xffff, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            break;
        case 8:
            break;
        case 9:
            v1.mUnk_00 = 10;
            func_0200c16c(&v1, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            func_0200bc78(8, 0xffff, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            break;
        case 10:
            v1.mUnk_00 = 11;
            func_0200c16c(&v1, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            func_0200bc78(8, 0xffff, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            break;
        default:
            v1.mUnk_00 = 0;
            func_0200c16c(&v1, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            func_0200bc78(8, 0xffff, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04a0);
            break;
    }
}

void func_0200b344(Unk021425e8 *a) {
    Unk0200c0d8 v1;
    func_0200c0d8(&v1, a->mUnk_0c);
    switch (v1.mUnk_00) {
        case 1:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 2) {
                func_0200ba44(5, 0);
            }
            break;
        case 2:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 5) {
                func_0200ba44(6, 0);
            }
            break;
        case 6:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 5) {
                func_0200ba44(0xe, 0);
            }
            break;
        case 3:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 5) {
                func_0200ba44(7, 0);
            }
            break;
        case 4:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 7) {
                func_0200ba44(8, 0);
            }
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 8) {
                func_0200ba44(9, 0);
            }
            break;
        case 5:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 9) {
                func_0200ba44(10, 0);
            } else if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 10) {
                func_0200be00();
            }
            break;
    }
}

// non-matching: 0x1d0 bytes, original 0x1d4; 207 lines differ; first: original `bgt.n T`, ours `bhi.n T`
void func_0200b43c(u32 a, Unk021425e8 *b) {
    u16 v1;
    u16 v2;
    switch (a) {
        case 11:
            func_0200ba44(3, 0);
            break;
        case 6:
            func_0200ba44(2, (u32) b);
            func_0200bef8(*(Unk0216fde8 **) &data_0216fde8, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_0020);
            break;
        case 10:
            func_0200ba44(4, (u32) b);
            break;
        case 25:
            func_0200b200();
            break;
        case 9:
            func_0200b344(b);
            break;
        case 15:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0e == 10) {
                func_0200ba44(11, 0);
            } else {
                func_0200ba44(12, 0);
            }
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f04 != 0) {
                func_0200bab0();
            }
            break;
        case 0xff:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_05e0 != 0) {
                switch (b->mUnk_02) {
                    case 1:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                    case 9:
                        v1 = 9;
                        break;
                    default:
                        v1 = 8;
                        break;
                }
                (*(Unk0216fde8 **) &data_0216fde8)->mUnk_05e0(0x13, &v1);
            }
            break;
        case 0x100:
            if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_05e0 != 0) {
                switch (b->mUnk_00) {
                    case 0:
                    case 7:
                    case 8:
                    case 13:
                    case 14:
                    case 15:
                    case 17:
                    case 18:
                    case 21:
                    case 25:
                    case 29:
                        v2 = 9;
                        break;
                    default:
                        v2 = 8;
                        break;
                }
                (*(Unk0216fde8 **) &data_0216fde8)->mUnk_05e0(0x13, &v2);
            }
            break;
        case 0x29:
            break;
    }
}

u32 func_0200b610(void) {
    Unk0200b610 *v1;
    v1 = (Unk0200b610 *) func_02008934();
    if (v1 == 0) {
        return 0;
    }
    (*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f08 = v1->mUnk_4b8;
    (*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f0c = v1->mUnk_4b5;
    func_0200c0ac((u32) (*(Unk0216fde8 **) &data_0216fde8)->mUnk_05a0);
    func_0200c090((u32) func_0200b43c);
    func_0200ba44(1, 0);
    func_0214d1fc(v1->mUnk_4c0, (*(Unk0216fde8 **) &data_0216fde8)->mUnk_04c0, 0xc0);
    func_0200c008((*(Unk0216fde8 **) &data_0216fde8)->mUnk_04c0);
    return 1;
}

void func_0200b698(Unk021425e8 *a) {
    if (a->mUnk_02 != 0) {
        func_0200b820(0xb, a->mUnk_02);
        return;
    }
    (*(Unk0216fde8 **) &data_0216fde8)->mUnk_5efc = 0;
    if ((*(Unk0216fde8 **) &data_0216fde8)->mUnk_5f04 != 0) {
        func_0200bab0();
        return;
    }
    func_0200b850(3, 0, 0);
}

#pragma thumb off
