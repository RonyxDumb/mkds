#include "00/code_021ad734.h"

// non-matching: 0x22 bytes, original 0x20; 2 instructions differ; first at +0xe: original `mov r1, r6`, ours `lsl r1,
// r6, #0x18`
int func_ov000_021ad734(u32 param_1, u32 param_2, int param_3, u32 param_4) {
    if (param_4 < param_2) {
        func_0214d168((void *) ((u32 *) (u32) (param_3)), (u8) (param_1), (u32) (param_2 - param_4));
        param_3 = param_3 + (param_2 - param_4);
    }
    return param_3;
}
