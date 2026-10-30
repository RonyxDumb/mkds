#include "Main/Unknown/code_02047780.h"

#pragma thumb on

void *func_02047780(const char *a) {
    void *r;
    s32 b;
    char c[0x80];
    u32 d;

    r = 0;
    b = func_0205e0a0();
    if (b == 1 || b == 3 || b == 0xc) {
        d = data_02164e04[10];
        if (a[0] == '/') {
            func_0200d9e0(c, 0x80, data_usa_02165008, d, a);
        } else {
            func_0200d9e0(c, 0x80, data_usa_02165010, d, a);
        }
        r = func_02048504(c, 8);
    } else {
        if (data_021759c8->mUnk_00[6].mUnk_68 != 0) {
            d = data_02164e04[6];
            if (a[0] == '/') {
                func_0200d9e0(c, 0x80, data_usa_02165018, d, a);
            } else {
                func_0200d9e0(c, 0x80, data_usa_02165020, d, a);
            }
            r = func_02048504(c, 8);
        }
        if (r == 0 && data_021759c8->mUnk_00[7].mUnk_68 != 0) {
            d = data_02164e04[7];
            if (a[0] == '/') {
                func_0200d9e0(c, 0x80, data_usa_02165028, d, a);
            } else {
                func_0200d9e0(c, 0x80, data_usa_02165030, d, a);
            }
            r = func_02048504(c, 8);
        }
        if (r == 0 && data_021759c8->mUnk_00[8].mUnk_68 != 0) {
            d = data_02164e04[8];
            if (a[0] == '/') {
                func_0200d9e0(c, 0x80, data_usa_02165038, d, a);
            } else {
                func_0200d9e0(c, 0x80, data_usa_02165040, d, a);
            }
            r = func_02048504(c, 8);
        }
    }
    return r;
}

#pragma thumb off
