#include "03/code_021b7c30.h"

int func_ov003_021b7c30(s8 *param_1) {
    s8 cVar1;
    int iVar2;
    iVar2 = 0;
    cVar1 = *param_1;
    while (cVar1 != '\0') {
        iVar2 = iVar2 + 1;
        cVar1 = param_1[iVar2];
    }
    return iVar2;
}
