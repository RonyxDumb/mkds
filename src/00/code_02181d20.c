#include "00/code_02181d20.h"

void func_ov000_02181d20(void) {
    int iVar1;
    iVar1 = ((u32) func_02128294());
    if (iVar1 != 0) {
        *(u32 *) ((*(int *) &data_ov000_021b4c6c) + 4) = 3;
        func_021281c8((u32) (0xf));
    }
    return;
}
