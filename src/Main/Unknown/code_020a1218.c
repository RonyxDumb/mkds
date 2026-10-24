#include "Main/Unknown/code_020a1218.h"

// non-matching: 0x38 bytes, original 0x1c; 9 instructions differ; first at +0x0: original `ldr r2, [pc, #0x10]
// (->0x50)`, ours `ldr r3, [pc, #0x2c] (->0x34)`
u16 func_020a1250(int param_1) {
    return *(u16 *) (param_1 * 0x70 +
                     (*(u32 *) (((u32) (&data_0217b1fc)) & 0xfffffffc) >> (((u32) (&data_0217b1fc)) & 3) * 8 |
                      *(u32 *) (((u32) (&data_0217b1fc)) & 0xfffffffc) << (((u32) (&data_0217b1fc)) & 3) * -8 + 0x20) +
                     0x48);
}

unsigned int func_020a1238(void) {
    return ((unsigned int) *(
        const unsigned short *) ((unsigned char *) (unsigned int) ((
                                     (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) ((
                                                                                   (u32) (&data_0217b1fc))) +
                                                                               0))) +
                                     (0x300u))) +
                                 160));
}

void func_020a1218(short param_1) {
    u32 uVar1;
    uVar1 = *(u32 *) (((u32) ((u32) (&data_0217b1fc))));
    *(short *) (uVar1 + 0x3a0) = *(unsigned short *) (uVar1 + 0x3a0) + param_1;
    return;
}
