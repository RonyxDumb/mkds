#include "00/code_0218e368.h"

void func_ov000_0218e394(unsigned int p0, unsigned int p1, unsigned int p2) {
    unsigned int v2 = ((p1) + (0x0u));
    unsigned int v3 = ((p2) + (0x0u));
    unsigned int v4 = ((unsigned int) *(unsigned int *) ((v3) + (0)));
    unsigned int v6;
    unsigned int v7;
    unsigned int v10;
    unsigned int v11;
    *(unsigned char *) ((v2) + (0)) = (unsigned char) (v4);
    v6 = func_ov000_021a8f0c((unsigned int) (p0), (unsigned int) (p1));
    v7 = ((unsigned int) *(unsigned char *) ((v2) + (0)));
    *(unsigned int *) ((v3) + (0)) = (unsigned int) (v7);
    v10 = ~(0x0u);
    v11 = func_ov000_0218e56c((unsigned int) (v6), (unsigned int) (v10));
}

u32 func_ov000_0218e374(u32 param_1) {
    int iVar1;
    u32 local_8[1];
    iVar1 = func_ov000_021a8c1c((u32) (param_1), (u32 *) (local_8));
    if (iVar1 == 0) {
        return 0xffffffff;
    }
    return local_8[0];
}

u32 func_ov000_0218e368(void) {
    return *((u32 *) ((u32) (&data_ov000_021b4e08)));
}
