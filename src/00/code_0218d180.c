#include "00/code_0218d180.h"

void func_ov000_0218d1a0(u32 param_1) {
    int iVar1;
    u32 *puVar2;
    int iVar3;
    iVar1 = func_ov000_0218dc44((u32 *) ((u32 *) (u32) (*(u32 *) (param_1 + 4))));
    iVar3 = 0;
    if (0 < iVar1) {
        do {
            puVar2 = (u32 *) func_ov000_0218dbf8((int *) ((int *) (u32) (*(u32 *) (param_1 + 4))), (int) (iVar3));
            func_ov000_0218d278((int) (param_1), (u32) (*puVar2));
            iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
    }
    func_ov000_0218d8b4((u32) (*(u32 *) (param_1 + 4)));
    func_ov000_0218d1dc((int) (param_1));
    return;
}

void func_ov000_0218d180(unsigned int p0) {
    unsigned int v1 = ((p0) + (0x0u));
    unsigned int v5 = func_ov000_0218dc94((unsigned int) (0x4u), (unsigned int) (0x64u), (unsigned int) (0x0u));
    unsigned int v8;
    *(unsigned int *) ((v1) + (4)) = (unsigned int) (v5);
    v8 = 0x5d0u;
    *(unsigned int *) ((v1) + (0 + (v8))) = (unsigned int) (0x0u);
}
