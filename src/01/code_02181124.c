#include "01/code_02181124.h"

unsigned int func_ov001_021811bc(void) {
    return ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                                        const unsigned int *) ((unsigned char *) (unsigned int) ((
                                                                                   (u32) (&data_ov001_021a9b88))) +
                                                                               0))) +
                                                    28));
}

unsigned int func_ov001_021811b8(void) {
    return 0x0u;
}

int func_ov001_02181198(void) {
    int iVar1;
    iVar1 = _s32_div_f(*(u32 *) (*((int *) ((u32) (&data_ov001_021a9b88))) + 4), 8);
    return iVar1 * iVar1;
}

unsigned int func_ov001_02181194(void) {
    return 0x0u;
}

unsigned int func_ov001_02181180(void) {
    return (
        (((((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                                        const unsigned int *) ((unsigned char *) (unsigned int) ((
                                                                                   (u32) (&data_ov001_021a9b88))) +
                                                                               0))) +
                                                    0))) *
          (((((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                                          const unsigned int *) ((unsigned char *) (unsigned int) ((
                                                                                     (u32) (&data_ov001_021a9b88))) +
                                                                                 0))) +
                                                      0))) +
            (0x0u))))) +
        (0x40u));
}

unsigned int func_ov001_02181174(void) {
    return ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                                        const unsigned int *) ((unsigned char *) (unsigned int) ((
                                                                                   (u32) (&data_ov001_021a9b88))) +
                                                                               0))) +
                                                    32));
}

// non-matching: 2 instructions differ; first at +0x6: original nothing, ours `ldr r7, [pc, #0x44] (->0x4c)`
u32 func_ov001_02181124(int param_1) {
    int *piVar1;
    int *piVar2;
    int iVar3;
    u32 local_18;
    piVar1 = ((int *) ((u32) (&data_ov001_021a9b88)));
    iVar3 = 0;
    local_18 = 0;
    piVar2 = (int *) *((int *) ((u32) (&data_ov001_021a9b88)));
    if (0 < *piVar2 * *piVar2) {
        do {
            if (*(unsigned char *) (piVar2[8] + iVar3) != *(unsigned char *) (param_1 + iVar3)) {
                local_18 = 1;
                func_ov001_021811c8();
                *(u8 *) (*(int *) (*piVar1 + 0x20) + iVar3) = *(u8 *) (param_1 + iVar3);
            }
            iVar3 = iVar3 + 1;
            piVar2 = (int *) *piVar1;
        } while (iVar3 < *piVar2 * *piVar2);
    }
    return local_18;
}
