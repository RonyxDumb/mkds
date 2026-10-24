#include "Main/Unknown/code_021201e4.h"

// non-matching: 0x3c bytes, original 0x20; 9 instructions differ; first at +0x0: original `ldr r2, [pc, #0x14]
// (->0x58)`, ours `ldr r3, [pc, #0x30] (->0x38)`
int func_02120220(int param_1) {
    return (int) *(
        short *) (param_1 * 0x244 +
                  (*(u32 *) (((u32) (&data_0217d384)) & 0xfffffffc) >> (((u32) (&data_0217d384)) & 3) * 8 |
                   *(u32 *) (((u32) (&data_0217d384)) & 0xfffffffc) << (((u32) (&data_0217d384)) & 3) * -8 + 0x20) +
                  0x43e);
}

// non-matching: 0x4c bytes, original 0x20; 13 instructions differ; first at +0x0: original nothing, ours `stmdb sp!,
// {lr}`
void func_02120200(int param_1, u16 param_2) {
    *(u16 *) (param_1 * 0x244 +
              (*(u32 *) (((u32) (&data_0217d384)) & 0xfffffffc) >> (((u32) (&data_0217d384)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217d384)) & 0xfffffffc) << (((u32) (&data_0217d384)) & 3) * -8 + 0x20) +
              0x43e) = param_2;
    return;
}

// non-matching: 0x38 bytes, original 0x1c; 9 instructions differ; first at +0x0: original `ldr r2, [pc, #0x10]
// (->0x18)`, ours `ldr r3, [pc, #0x2c] (->0x34)`
u8 func_021201e4(int param_1) {
    return *(u8 *) (param_1 * 0x244 +
                    (*(u32 *) (((u32) (&data_0217d384)) & 0xfffffffc) >> (((u32) (&data_0217d384)) & 3) * 8 |
                     *(u32 *) (((u32) (&data_0217d384)) & 0xfffffffc) << (((u32) (&data_0217d384)) & 3) * -8 + 0x20) +
                    0x451);
}
