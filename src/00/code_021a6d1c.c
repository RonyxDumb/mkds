#include "00/code_021a6d1c.h"

u32 func_ov000_021a6d40(void) {
    int iVar1;
    iVar1 = func_ov000_021a6b10();
    if (iVar1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_021a6d1c(const u8 *a, const u8 *b) {
    int i;

    i = 0;
    do {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    } while (i < 6);
    return 1;
}
