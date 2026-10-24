#include "01/code_02188260.h"

// non-matching: 0x5c bytes, original 0x58; 17 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
u32 func_ov001_02188260(u32 param_1) {
    if (*(int *) (*((int *) ((u32) (&data_021759c0))) + 8) == 4) {
        func_ov001_021817e0();
    }
    *(int *) (param_1 + 0xac) = *(int *) (param_1 + 0xac) + 1;
    if (*(int *) (param_1 + 0xac) >= **(int **) (param_1 + 0xa0)) {
        *(int *) (param_1 + 0xac) = **(int **) (param_1 + 0xa0);
        if (*(int *) (*((int *) ((u32) (&data_021759c0))) + 8) == 4) {
            func_020a12b8();
        }
        return 1;
    }
    return 0;
}
