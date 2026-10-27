#include "Main/Unknown/code_0205b0b4.h"

// non-matching: 0x5c bytes, original 0x40; 17 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours
// `stmdb sp!, {r4, r5, r6, lr}`
void func_0205b0b4(void) {
    if ((*(u16 *) ((*(u32 *) (((u32) (&data_0217aa14)) & 0xfffffffc) >> (((u32) (&data_0217aa14)) & 3) * 8 |
                    *(u32 *) (((u32) (&data_0217aa14)) & 0xfffffffc) << (((u32) (&data_0217aa14)) & 3) * -8 + 0x20) +
                   0x75c) &
         0x80) != 0) {
        func_0205b0f4();
    }
    func_02046b40(
        (void *) (*(u32 *) (((u32) (&data_0217aa14)) & 0xfffffffc) >> (((u32) (&data_0217aa14)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217aa14)) & 0xfffffffc) << (((u32) (&data_0217aa14)) & 3) * -8 + 0x20));
    return;
}
