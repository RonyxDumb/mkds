#include "03/code_021c83b0.h"
#include "code_02147cd8.h"

int func_ov003_021c83cc(int param_1) {
    int iVar1;
    int iVar2;
    iVar1 = func_02147d30((u32) (*((u16 *) ((u32) (&data_ov003_021da210)))), (u32) (0x1d));
    iVar2 = 0;
    do {
        if (iVar1 == param_1) {
            return iVar2;
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 1;
    } while (iVar2 < 4);
    return -1;
}

int func_ov003_021c83b0(int param_1) {
    int iVar1;
    iVar1 = func_02147d30((u32) (*((u16 *) ((u32) (&data_ov003_021da210)))), (u32) (0x1d));
    return iVar1 + param_1;
}
