#include "Main/Unknown/code_02028db8.h"

u16 func_02028dd4(void) {
    int uVar1;
    u32 uVar2;
    uVar2 = *(u32 *) (((u32) ((u32) (&data_0217aa00))));
    if ((*(u32 *) (uVar2)) == 2) {
        uVar1 = *(u16 *) (uVar2 + 0x432);
    } else {
        uVar1 = 0;
    }
    return uVar1;
}

unsigned int func_02028db8(unsigned int p0) {
    return ((unsigned int) *(
        const unsigned short
            *) ((unsigned char *) (unsigned int) ((
                    (((((unsigned int) *(
                          const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217aa00))) + 0))) +
                      (((p0) << 3)))) +
                    (0x1e00u))) +
                82));
}
