#include "Main/Unknown/code_02111b40.h"

#pragma thumb on

void func_02111b40(void) {
    *(vu32 *) 0x4000010 = (-data_0217d348->mUnk_58 & 0x1ff) | ((-data_0217d348->mUnk_5c << 16) & 0x1ff0000);
    *(vu32 *) 0x4000014 = (-data_0217d348->mUnk_60 & 0x1ff) | ((-data_0217d348->mUnk_64 << 16) & 0x1ff0000);
    func_02111428();
}

#pragma thumb off
