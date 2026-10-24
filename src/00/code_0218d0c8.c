#include "00/code_0218d0c8.h"

int func_ov000_0218d0c8(int param_1, int param_2) {
    int iVar1;
    iVar1 = 0;
    if (0 < param_2) {
        do {
            if (*(s8 *) (param_1 + iVar1) == '\0') {
                return iVar1 + 1;
            }
            iVar1 = iVar1 + 1;
        } while (iVar1 < param_2);
    }
    return -1;
}
