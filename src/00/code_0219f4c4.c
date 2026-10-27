#include "00/code_0219f4c4.h"

// non-matching: 0x7c bytes, original 0x80; 10 instructions differ; first at +0x8: original `ldr r0, [pc, #0x68]
// (->0x74)`, ours `ldr r7, [pc, #0x64] (->0x70)`
u32 func_ov000_0219f4c4(u32 *param_1, u32 param_2) {
    int *piVar1;
    u32 *puVar2;
    int iVar3;
    u32 uVar4;
    piVar1 = (int *) &data_ov000_021b566c;
    puVar2 = (u32 *) (*(int *) &data_ov000_021b566c);
    if ((*(unsigned char *) ((int) puVar2 + ((int) 0x0000019eu)) != '\0') &&
        (*(int *) ((int) puVar2 + ((int) 0x00000198u)) == 4)) {
        return 1;
    }
    uVar4 = 0;
    if (uVar4 < param_2) {
        do {
            iVar3 = func_ov000_0218eb9c((int *) ((int *) (u32) (*puVar2)), (u32) (*param_1));
            if (iVar3 == 0) {
                return 0;
            }
            puVar2 = (u32 *) *piVar1;
            if ((*(unsigned char *) ((int) puVar2 + ((int) 0x0000019eu)) != '\0') &&
                (*(int *) ((int) puVar2 + ((int) 0x00000198u)) == 1)) {
                return 1;
            }
            param_1 = param_1 + 1;
            uVar4 = uVar4 + 1;
        } while (uVar4 < param_2);
    }
    return 1;
}
