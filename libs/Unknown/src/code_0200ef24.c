#include "code_0200ef24.h"
#include "code_0200c914.h"
#include "code_0200e77c.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_00002000.h"
#include "Main/Unknown/unk_02400000.h"

u32 func_0200f038(u32 i) {
    u32 a;
    s32 n;
    u32 c;

    switch (i) {
        case 0:
            return 0x23e0000;
        case 2:
            if (data_021701b8 == 0 || (func_0200e884() & 3) == 1) {
                return 0;
            }
            return 0x2700000;
        case 3:
            return 0x2000000;
        case 4:
            a = (u32) &data_027e0000;
            c = a + 0x3f80 - (u32) data_00000c00;
            n = (s32) data_00002800;
            if (n == 0) {
                return a < 0x27e00e0 ? 0x27e00e0 : a;
            }
            if (n < 0) {
                return 0x27e00e0 - n;
            }
            return c - n;
        case 5:
            return 0x27ff680;
        case 6:
            return 0x37f8000;
    }
    return 0;
}

u32 func_0200ef4c(u32 i) {
    switch (i) {
        case 0:
            return 0x21da300;
        case 2:
            if (data_021701b8 == 0 || (func_0200e884() & 3) == 1) {
                return 0;
            }
            return (u32) data_02400000;
        case 3:
            return 0x1ffffa0;
        case 4:
            return 0x27e00e0;
        case 5:
            return 0x27ff000;
        case 6:
            return 0x37f8000;
    }
    return 0;
}

void func_0200ef38(u32 i, u32 v) {
    ((vu32 *) 0x027ffdc4)[i] = v;
}

void func_0200ef24(u32 i, u32 v) {
    ((vu32 *) 0x027ffda0)[i] = v;
}
