#include "Main/Unknown/code_02030a20.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_02030a20(void) {
    s32 a;
    s32 r;

    a = 0x17;
    r = func_02025ebc(&(*(Unk02174e58 **) &data_02174e58)->mUnk_c0);
    if ((*(Unk02174e58 **) &data_02174e58)->mUnk_84 == 0 && (*(Unk02174e58 **) &data_02174e58)->mUnk_94 != 6) {
        a |= 8;
    }
    *(u32 *) 0x4001000 = (*(u32 *) 0x4001000 & 0xffffe0ff) | (a << 8);
    *(u32 *) 0x400101c = (-r << 16) & 0x1ff0000;
    if (r != 0) {
        *(u32 *) 0x4001000 = (*(u32 *) 0x4001000 & 0xffff1fff) | 0x2000;
        *(u16 *) 0x4001048 = (u32) ((*(u16 *) 0x4001048 & ~0x3f) | 0x1f) | 0x20;
        *(u16 *) 0x400104a = (u32) ((*(u16 *) 0x400104a & ~0x3f) | 7) | 0x20;
        *(u16 *) 0x4001040 = 0xff;
        *(u16 *) 0x4001044 = (r + 0xc0) & 0xff;
    } else {
        *(u32 *) 0x4001000 = *(u32 *) 0x4001000 & 0xffff1fff;
    }
}

#pragma thumb off
