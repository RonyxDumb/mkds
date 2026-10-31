#include "00/code_021a6908.h"

// non-matching: 1 instruction differ; first at +0x28: original `.word func_01ff8000`, ours `.word 0x1ff8000`
u32 func_ov000_021a6908(u8 *param_1) {
    if (*(int *) (param_1 + 8) == 0) {
        *(int *) (param_1 + 8) = 0x1ff8000;
        *(int *) (param_1 + 0xc) = *(int *) (param_1 + 0xc) + 1;
        return 1;
    }
    if (*(int *) (param_1 + 8) == 0x1ff8000) {
        *(int *) (param_1 + 0xc) = *(int *) (param_1 + 0xc) + 1;
        return 1;
    }
    return 0;
}
