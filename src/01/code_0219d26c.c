#include "01/code_0219d26c.h"

void func_ov001_0219d26c(void) {
    *(vu16 *)0x400000c = (u16)((*(vu16 *)0x400000c & 0x43) | 0x1e10);
    *(vu32 *)0x4000000 = (*(vu32 *)0x4000000 & ~0x1f00) | 0x1800;
    func_02036ab0(data_ov001_021a9bf8->mUnk_1030);
    data_ov001_021a9bf8 = 0;
}
