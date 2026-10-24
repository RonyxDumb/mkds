#include "01/code_02193448.h"

void func_ov001_02193448(void) {
    int iVar1;
    iVar1 = func_ov001_02192e84();
    if ((iVar1 == -1) && (*(int *) (*((int *) ((u32) (&data_ov001_021a9bd4))) + 0x10) == 4)) {
        func_ov001_02192e78((u16) (0));
    }
    iVar1 = ((unsigned int) func_02125f54());
    if (iVar1 != 0) {
        func_02125ebc((unsigned int) (0x23));
        func_02125fc0();
        *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bd4))) + 0x10) = 4;
    }
    return;
}
