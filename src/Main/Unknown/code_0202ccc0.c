#include "Main/Unknown/code_0202ccc0.h"

#pragma thumb on

void func_0202ccc0(void) {
    s16 a = func_02025ebc((Unk02025ebc *) &data_02174e40->mUnk_0cc);
    int b;
    *(vu32 *) 0x4000010 = ((a << 16) & 0x1ff0000);
    b = -a;
    *(vu32 *) 0x400101c = ((b << 16) & 0x1ff0000);
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 1;
    if (a != 0) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffff1fff) | 0x2000;
        *(vu16 *) 0x4000048 = (u32) ((*(vu16 *) 0x4000048 & ~0x3f) | 0x1f) | 0x20;
        *(vu16 *) 0x400004a = (u32) ((*(vu16 *) 0x400004a & ~0x3f) | 0xe) | 0x20;
        *(vu16 *) 0x4000040 = 0xff;
        *(vu16 *) 0x4000044 = ((b << 8) & 0xff00) | 0xc0;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffff1fff) | 0x2000;
        *(vu16 *) 0x4001048 = (u32) ((*(vu16 *) 0x4001048 & ~0x3f) | 0x1f) | 0x20;
        *(vu16 *) 0x400104a = (u32) ((*(vu16 *) 0x400104a & ~0x3f) | 7) | 0x20;
        *(vu16 *) 0x4001040 = 0xff;
        *(vu16 *) 0x4001044 = (a + 0xc0) & 0xff;
    } else {
        *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
        *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & 0xffff1fff;
    }
}

#pragma thumb off
