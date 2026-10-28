#include "00/code_021a37dc.h"

void func_ov000_021a37dc(void) {
    int iVar1;
    if ((*(int *) &data_ov000_021b5df4) != 0) {
        iVar1 = func_ov000_02188720();
        while (iVar1 == 0) {
            func_0200dc3c((u32) (10));
            iVar1 = func_ov000_02188720();
        }
        *(int *) &data_ov000_021b5df4 = 0;
    }
    return;
}
