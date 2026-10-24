#include "00/code_021a71a4.h"

int func_ov000_021a71a4(int param_1, int *param_2, int param_3) {
    int iVar1;
    iVar1 = param_1;
    if (param_3 == 0) {
        iVar1 = 0;
    }
    param_2[1] = iVar1;
    *param_2 = param_3;
    iVar1 = func_ov000_021a8a54((int) (param_3));
    return param_1 + iVar1;
}
