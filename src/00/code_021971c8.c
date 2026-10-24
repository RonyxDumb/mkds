#include "00/code_021971c8.h"

int func_ov000_021971c8(int param_1, int param_2) {
    int iVar2;
    int iVar1;
    iVar1 = 0;
    iVar2 = 0;
    if (0 < param_2) {
        do {
            iVar1 = ((int) 0x9ccf9319u) * iVar1 + (int) *(s8 *) (param_1 + iVar2);
            iVar2 = iVar2 + 1;
        } while (iVar2 < param_2);
    }
    return iVar1;
}
