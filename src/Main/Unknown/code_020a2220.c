#include "Main/Unknown/code_020a2220.h"

// non-matching: 0x48 bytes, original 0x1c; 13 instructions differ; first at +0x0: original nothing, ours `stmdb sp!,
// {lr}`
void func_020a2220(int param_1, u32 param_2) {
    *(u32 *) (param_1 * 0x70 +
              (*(u32 *) (((u32) (&data_0217b1fc)) & 0xfffffffc) >> (((u32) (&data_0217b1fc)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217b1fc)) & 0xfffffffc) << (((u32) (&data_0217b1fc)) & 3) * -8 + 0x20) +
              0x6c) = param_2;
    return;
}
