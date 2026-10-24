#include "Main/Unknown/code_02116844.h"

#pragma thumb on

u32 func_02116844(int param_1) {
    int iVar1;
    int iVar2;
    iVar1 = func_02116870();
    iVar2 = func_021143b4();
    if (iVar2 > iVar1 + param_1) {
        return 1;
    }
    return 0;
}

#pragma thumb off
