#include "Main/Unknown/code_020fcb9c.h"

// non-matching: 0x48 bytes, original 0x1c; 13 instructions differ; first at +0x0: original nothing, ours `stmdb sp!,
// {lr}`
void func_020fcb9c(int param_1, int param_2) {
    *(u32 *) (param_1 + 0x228) =
        param_2 * 0x210 +
        (*(u32 *) (((u32) (&data_027e00c8)) & 0xfffffffc) >> (((u32) (&data_027e00c8)) & 3) * 8 |
         *(u32 *) (((u32) (&data_027e00c8)) & 0xfffffffc) << (((u32) (&data_027e00c8)) & 3) * -8 + 0x20);
    return;
}
