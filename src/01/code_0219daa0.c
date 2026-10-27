#include "01/code_0219daa0.h"

void func_ov001_0219daa0(void) {
    int *piVar1;
    int iVar2;
    piVar1 = (int *) &data_ov001_021a9bfc;
    *(int *) ((*(int *) &data_ov001_021a9bfc) + 0x14) = *(int *) ((*(int *) &data_ov001_021a9bfc) + 0x14) + 1;
    iVar2 = *piVar1;
    if (10 <= *(int *) (iVar2 + 0x14)) {
        *(u32 *) (iVar2 + 4) = 5;
        *(u32 *) (*piVar1 + 0x14) = 0;
        func_021282c8();
        return;
    }
    if (5 <= *(int *) (iVar2 + 0x14)) {
        *(u32 *) (iVar2 + 0x24) = 1;
    }
    return;
}
