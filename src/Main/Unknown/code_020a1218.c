#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a1218.h"

u16 func_020a1250(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b1fc;
    value1 = 0x70u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u16 *) ((value1) + (72));
    return (u16) value0;
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
    uVar1 = *(u32 *) &data_0217b1fc;
    *(short *) (uVar1 + 0x3a0) = *(unsigned short *) (uVar1 + 0x3a0) + param_1;
    return;
}
