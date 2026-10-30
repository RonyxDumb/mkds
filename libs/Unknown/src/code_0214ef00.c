#include "code_0214ef00.h"
#include "code_0214f1b0.h"
#include "code_0214d5b8.h"

void func_0214f060(u32 a, u32 b, u32 c) {
    u16 x;
    u16 k;
    u32 n;

    if (c != 0) {
        if (data_02180414.mUnk_00 != 0) {
            data_02180414.mUnk_00 = 0;
        }
        if (data_02180414.mUnk_04 != 0) {
            void (*g)() = data_02180414.mUnk_04;
            data_02180414.mUnk_04 = 0;
            g(6, data_02180414.mUnk_08);
        }
    }
    x = b & 0xff;
    k = (b & 0x7f00) >> 8;
    switch (x) {
        case 0:
            n = 0;
            break;
        case 1:
            n = 4;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 5;
            break;
        case 4:
            n = 1;
            break;
        default:
            n = 6;
            break;
    }
    if (k == 0x51) {
        if (data_02180414.mUnk_10 != 0) {
            data_02180414.mUnk_10(n, data_02180414.mUnk_14);
        }
        return;
    }
    if (k == 0x40) {
        if (data_02180414.mUnk_18 != 0) {
            *data_02180414.mUnk_18 = *(u16 *) 0x27fff94;
        }
    }
    if (data_02180414.mUnk_00 != 0) {
        data_02180414.mUnk_00 = 0;
    }
    if (data_02180414.mUnk_04 != 0) {
        void (*f)() = data_02180414.mUnk_04;
        data_02180414.mUnk_04 = 0;
        f(n, data_02180414.mUnk_08);
    }
}

u32 func_0214ef34(u32 a, u32 b, u32 c, u32 d) {
    if (func_0214d6e8(9, d | 0x2004100, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (a >> 16) | 0x10000, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (a & 0xffff) | 0x20000, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (b >> 16) | 0x30000, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (b & 0xffff) | 0x40000, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (c >> 16) | 0x50000, 0) < 0) {
        return 0;
    }
    return func_0214d6e8(9, (c & 0xffff) | 0x1060000, 0) >= 0;
}

s32 func_0214ef00(void) {
    return func_0214d6e8(9, 0x3004200, 0) >= 0;
}
