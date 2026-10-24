#include "00/code_021a6d1c.h"

u32 func_ov000_021a6d40(void) {
    int iVar1;
    iVar1 = func_ov000_021a6b10();
    if (iVar1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_021a6d1c(int param_1, int param_2) {
    int iVar1;
    iVar1 = 0;
    do {
        if (*(unsigned char *) (param_1 + iVar1) != *(unsigned char *) (param_2 + iVar1)) {
            return 0;
        }
        iVar1 = iVar1 + 1;
    } while (iVar1 < 6);
    return 1;
}
