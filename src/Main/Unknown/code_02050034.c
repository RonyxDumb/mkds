#include "Main/Unknown/code_02050034.h"

unsigned int func_02050064(unsigned int p0) {
    return ((unsigned int) *(
        const unsigned short
            *) ((unsigned char *) (unsigned int) ((
                    (((((unsigned int) *(
                          const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217aa00))) + 0))) +
                      (((p0) << 1)))) +
                    (0x1e00u))) +
                156));
}

// non-matching: 0x4c bytes, original 0x30; 9 instructions differ; first at +0x8: original `ldr r1, [pc, #0x1c]
// (->0x2c)`, ours `ldr r2, [pc, #0x38] (->0x48)`
void func_02050034(u8 param_1) {
    *(u8 *) ((*(u32 *) (((u32) (&data_0217aa00)) & 0xfffffffc) >> (((u32) (&data_0217aa00)) & 3) * 8 |
              *(u32 *) (((u32) (&data_0217aa00)) & 0xfffffffc) << (((u32) (&data_0217aa00)) & 3) * -8 + 0x20) +
             0x15f6) = param_1;
    func_02050080();
    func_02058b10();
    return;
}
