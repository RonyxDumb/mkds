#include "00/code_02181904.h"
#include "Main/Unknown/code_02125f54.h"

void func_ov000_02181940(void) {
    int iVar1;
    iVar1 = ((unsigned int) func_02125f54());
    if (iVar1 != 0) {
        func_02125fc0();
        return;
    }
    iVar1 = ((u32) func_02125f88());
    if (iVar1 != 0) {
        iVar1 = ((unsigned int) func_02125f60());
        if (iVar1 == 0) {
            func_0211fd28();
            *(u32 *) (*((int *) ((u32) (&data_ov000_021b4c6c))) + 4) = 7;
            return;
        }
        *(u32 *) (*((int *) ((u32) (&data_ov000_021b4c6c))) + 4) = 1;
    }
    return;
}

void func_ov000_02181904(void) {
    int iVar1;
    iVar1 = ((int) func_ov000_021806c4());
    if ((iVar1 == -1) && (*(int *) (*((int *) ((u32) (&data_ov000_021b4c6c))) + 0x10) == 10)) {
        func_ov000_021806b8((unsigned int) (0));
    }
    iVar1 = func_0211fd68();
    if (iVar1 != 1) {
        *(u32 *) (*((int *) ((u32) (&data_ov000_021b4c6c))) + 0x10) = 10;
    }
    return;
}
