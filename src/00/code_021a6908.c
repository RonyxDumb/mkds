#include "00/code_021a6908.h"
#include "Main/Unknown/code_01ff8000.h"

u32 func_ov000_021a6908(u8 *param_1) {
    if (*(int *) (param_1 + 8) == 0) {
        *(int *) (param_1 + 8) = (int) func_01ff8000;
        *(int *) (param_1 + 0xc) = *(int *) (param_1 + 0xc) + 1;
        return 1;
    }
    if (*(int *) (param_1 + 8) == (int) func_01ff8000) {
        *(int *) (param_1 + 0xc) = *(int *) (param_1 + 0xc) + 1;
        return 1;
    }
    return 0;
}
