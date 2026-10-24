#include "00/code_02198584.h"

u32 func_ov000_02198584(u32 param_1, u32 param_2) {
    int iVar1;
    iVar1 = func_ov000_021986ac();
    if (iVar1 == 0) {
        return 0;
    }
    iVar1 = func_ov000_021985ec((int) (param_1), (int) (param_2));
    if (iVar1 == 0) {
        return 0;
    }
    iVar1 = func_ov000_02198658((int) (param_1), (int) (param_2));
    if (iVar1 == 0) {
        return 0;
    }
    iVar1 = func_ov000_0219861c((int) (param_1), (int) (param_2));
    if (iVar1 != 0) {
        return 1;
    }
    return 0;
}
