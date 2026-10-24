#include "00/code_021a8878.h"

// non-matching: 4 instructions differ; first at +0xc: original nothing, ours `ldr r1, [pc, #0x1c] (->0x2c)`
u32 func_ov000_021a8878(u32 param_1, u32 param_2) {
    u32 *puVar1;
    int iVar2;
    iVar2 = func_ov000_021a8830();
    puVar1 = ((u32 *) ((u32) (&data_ov000_021b63d8)));
    if (iVar2 == 0) {
        return 0xffffffd9;
    }
    *((u32 *) ((u32) (&data_ov000_021b63d8))) = param_1;
    puVar1[1] = param_2;
    return 0;
}
