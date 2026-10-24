#include "Main/Unknown/code_020f1104.h"

// non-matching: 0x5c bytes, original 0x30; 19 instructions differ; first at +0x0: original nothing, ours `stmdb sp!,
// {lr}`
void func_020f1150(int param_1, int param_2) {
    *(u32 *) (param_1 + 0x228) =
        param_2 * 0x210 +
        (*(u32 *) (((u32) (&data_027e00c8)) & 0xfffffffc) >> (((u32) (&data_027e00c8)) & 3) * 8 |
         *(u32 *) (((u32) (&data_027e00c8)) & 0xfffffffc) << (((u32) (&data_027e00c8)) & 3) * -8 + 0x20);
    *(u32 *) (param_1 + 0x22c) = 0;
    *(u32 *) (param_1 + 0x230) = 0;
    *(u32 *) (param_1 + 0x234) = 0;
    *(u32 *) (param_1 + 0x238) = 0;
    return;
}

// non-matching: 0x50 bytes, original 0x24; 16 instructions differ; first at +0x0: original nothing, ours `stmdb sp!,
// {lr}`
void func_020f112c(int param_1, int param_2) {
    *(u32 *) (param_1 + 0x228) =
        param_2 * 0x210 +
        (*(u32 *) (((u32) (&data_027e00c8)) & 0xfffffffc) >> (((u32) (&data_027e00c8)) & 3) * 8 |
         *(u32 *) (((u32) (&data_027e00c8)) & 0xfffffffc) << (((u32) (&data_027e00c8)) & 3) * -8 + 0x20);
    *(u32 *) (param_1 + 0x238) = 0;
    return;
}

void func_020f1104(int param_1) {
    func_02148504((u32) (param_1 + 0x22c), (u32) (param_1 + 0x5c), (int *) ((int *) (u32) (param_1 + 0x5c)));
    func_020f29e8((int) (param_1));
    return;
}
