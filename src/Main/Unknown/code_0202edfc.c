#include "Main/Unknown/code_0202edfc.h"

#pragma thumb on

unsigned int func_0202ee20(unsigned int p0, unsigned int p1) {
    return ((((unsigned int) *(
                const short
                    *) ((unsigned char *) (unsigned int) ((
                            (((unsigned int) *(
                                const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                                           const unsigned int *) ((unsigned char *) (unsigned int) ((
                                                                                      (u32) (&data_02174e48))) +
                                                                                  0))) +
                                                       8))) +
                            (((p1) << 6)))) +
                        0 + (0xeu)))) -
            (((unsigned int) *(
                const short
                    *) ((unsigned char *) (unsigned int) ((
                            (((unsigned int) *(
                                const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                                           const unsigned int *) ((unsigned char *) (unsigned int) ((
                                                                                      (u32) (&data_02174e48))) +
                                                                                  0))) +
                                                       8))) +
                            (((p0) << 6)))) +
                        0 + (0xeu)))));
}

u32 func_0202edfc(void) {
    u32 extraout_r1;
    extraout_r1 = (data_02174e48->mUnk_03c + data_02174e48->mUnk_044 + 1) % (7);
    return extraout_r1;
}

#pragma thumb off
