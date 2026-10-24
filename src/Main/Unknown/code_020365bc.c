#include "Main/Unknown/code_020365bc.h"

// non-matching: 0x30 bytes, original 0x34; 9 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours
// `stmdb sp!, {r4, lr}`
void func_020365bc(u32 param_1) {
    func_02036588((unsigned int) (((u32) (&data_02174e88))), (unsigned int) (param_1));
    func_020364f8((u32) (((u32) (&data_02174e88))), (u32) (0x0000beefu));
    return;
}
