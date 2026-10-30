#include "Main/Unknown/code_02028010.h"

void func_02028010(u32 a) {
    *(vu16 *) 0x0400100e = (*(vu16 *) 0x0400100e & ~3) | a;
}

void func_0202802c(u32 a, u32 b) {
    *(vu32 *) 0x0400101c = (a & 0x1ff) | ((b << 16) & 0x1ff0000);
}
