#include "01/code_02187074.h"

int func_ov001_02187074(int param_1, int param_2, int param_3) {
    int iVar1;
    if (param_3 < param_1) {
        iVar1 = param_3 + param_2;
        if (param_3 + param_2 >= param_1) {
            iVar1 = param_1;
        }
        return iVar1;
    }
    if (param_3 > param_1) {
        iVar1 = param_3 - param_2;
        if (param_3 - param_2 <= param_1) {
            iVar1 = param_1;
        }
        return iVar1;
    }
    return param_3;
}
