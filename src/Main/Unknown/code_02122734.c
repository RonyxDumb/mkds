#include "Main/Unknown/code_02122734.h"

unsigned int func_02122778(unsigned int p0) {
    return ((unsigned int) *(
        const signed char
            *) ((unsigned char *) (unsigned int) ((
                    (((((unsigned int) *(
                          const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217d384))) + 0))) +
                      (p0))) +
                    (0x1f00u))) +
                78));
}

// non-matching: register allocation only, 8 instructions; first at +0x4: original `mov r3, #0x0`, ours `mov r2, #0x0`
int func_02122734(int param_1) {
    u32 uVar1;
    int iVar2;
    iVar2 = 0;
    uVar1 = *(u32 *) (((u32) ((u32) (&data_0217d384))));
    do {
        if (param_1 == *(s8 *) (uVar1 + 0x1f4e)) {
            return iVar2;
        }
        iVar2 = (iVar2 + 1) * 0x1000000 >> 0x18;
        uVar1 = uVar1 + 1;
    } while (iVar2 < 4);
    return -1;
}
