#include "00/code_0218d430.h"

// non-matching: 0x54 bytes, original 0x58; 17 lines differ; first: original `push {r4, r5, lr}`, ours `push {r4, r5,
// r6, lr}`
int func_ov000_0218d430(u32 *param_1, u32 *param_2) {
    u32 uVar1;
    u32 uVar2;
    int iVar3;
    uVar1 =
        func_ov000_0218b30c((int) (*param_1), (u32) (*(u32 *) ((*(int *) &data_ov000_021b4d24) + ((int) 0x00000498u))),
                            (u32) (((u32) &data_ov000_021b2260)));
    uVar2 =
        func_ov000_0218b30c((int) (*param_2), (u32) (*(u32 *) ((*(int *) &data_ov000_021b4d24) + ((int) 0x00000498u))),
                            (u32) (((u32) &data_ov000_021b2260)));
    iVar3 = func_0213a074((const u8 *) (uVar1), (const u8 *) (uVar2));
    if (*(int *) ((*(int *) &data_ov000_021b4d24) + ((int) 0x0000049cu)) == 0) {
        iVar3 = -iVar3;
    }
    return iVar3;
}
