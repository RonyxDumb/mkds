#include "Main/Unknown/code_02089d70.h"

void func_02089d70(int param_1) {
    u32 *puVar1;
    u32 *puVar2;
    puVar1 = ((u32 *) 0x0400046cu);
    *((u32 *) 0x040004a4u) = ((u32) 0x090000c0u) | (int) *(short *) (param_1 + 2) << 0x10;
    *puVar1 = 0x8c000;
    *puVar1 = 0x6e000;
    puVar2 = ((u32 *) 0x04000500u);
    *puVar1 = 0xa000;
    *puVar2 = 1;
    *((u32 *) 0x04000480u) = (u32) * (u16 *) (param_1 + 4);
    func_02089e10((int) (0));
    func_02089e10((int) (1));
    func_02089e10((int) (2));
    func_02089e10((int) (3));
    *((u32 *) 0x04000504u) = 0;
    return;
}
