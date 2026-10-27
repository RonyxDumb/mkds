#include "Main/Unknown/code_020d2d94.h"

#pragma thumb on

void func_020d2d94(void) {
    int iVar4;
    int *piVar3;
    u32 *puVar2;
    int *piVar1;
    piVar3 = (int *) ((*(int *) &data_0217b4f0) + 8);
    piVar1 = (int *) ((*(int *) &data_0217b4f0) + ((int) 0x00000134u));
    iVar4 = 0;
    do {
        if (*piVar3 != 0) {
            puVar2 = *(u32 **) (*piVar3 + 0x28);
            if (puVar2 != (u32 *) 0x0) {
                *puVar2 = 0;
            }
            *piVar3 = 0;
        }
        piVar3 = piVar3 + 1;
        iVar4 = iVar4 + 1;
    } while (iVar4 < 0x18);
    iVar4 = 0;
    do {
        if (*piVar1 != 0) {
            puVar2 = *(u32 **) (*piVar1 + 0x24);
            if (puVar2 != (u32 *) 0x0) {
                *puVar2 = 0;
            }
            *piVar1 = 0;
        }
        piVar1 = piVar1 + 1;
        iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
    return;
}

#pragma thumb off
