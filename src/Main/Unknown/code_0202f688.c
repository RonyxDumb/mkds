#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_0202f688(void) {
    u32 v = 0x16;
    s32 y;

    if (data_02174e50->mUnk_4c != 4) {
        v |= 8;
    }
    *(vu32 *) 0x04001000 = (*(vu32 *) 0x04001000 & 0xffffe0ff) | (v << 8);
    *(vu32 *) 0x0400101c = (-data_02174e50->mUnk_90 << 16) & 0x1ff0000;
    if (data_02174e50->mUnk_90 != 0) {
        *(vu32 *) 0x04001000 = (*(vu32 *) 0x04001000 & 0xffff1fff) | 0x2000;
        *(vu16 *) 0x04001048 = (u32) ((*(vu16 *) 0x04001048 & ~0x3f) | 0x1f) | 0x20;
        *(vu16 *) 0x0400104a = (u32) ((*(vu16 *) 0x0400104a & ~0x3f) | 7) | 0x20;
        y = data_02174e50->mUnk_90 + 0xc0;
        *(vu16 *) 0x04001040 = 0xff;
        *(vu16 *) 0x04001044 = y & 0xff;
    } else {
        *(vu32 *) 0x04001000 = *(vu32 *) 0x04001000 & 0xffff1fff;
    }
}

#pragma thumb off
