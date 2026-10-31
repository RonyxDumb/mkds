#include "Main/Unknown/code_020c4bb0.h"

u16 func_020c4bb0(void) {
    u16 *puVar1;
    int *piVar2;
    puVar1 = ((u16 *) 0x04000304u);
    piVar2 = (int *) ((u32) data_0217b3e8);
    *piVar2 = (*(u32 *) ((u32) piVar2)) + 1;
    return *puVar1;
}
