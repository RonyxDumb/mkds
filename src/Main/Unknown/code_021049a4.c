#include "Main/Unknown/code_021049a4.h"

#pragma thumb on

void func_021049a4(void) {
    int iVar6;
    int iVar5;
    int iVar4;
    int *piVar3;
    u32 uVar2;
    int iVar1;
    if (*(int *) ((*(int *) &data_0217bc48) + ((int) 0x000001dcu)) != 0) {
        iVar1 = (*(int *) &data_027e00cc) + ((int) 0x00000220u);
        piVar3 = *(int **) (iVar1 + 4);
        iVar6 = *(int *) (iVar1 + 8);
        iVar5 = 0;
        if (0 < iVar6) {
            do {
                iVar4 = *piVar3;
                uVar2 = func_0210543c();
                *(u32 *) (iVar4 + ((int) 0x00000134u)) = uVar2;
                *(int *) (*(int *) (iVar4 + ((int) 0x00000134u)) + 0xfc) = iVar4 + ((int) 0x0000013cu);
                piVar3 = piVar3 + 1;
                iVar5 = iVar5 + 1;
            } while (iVar5 < iVar6);
        }
        *(u32 *) (iVar1 + 0x40) = 1;
    }
    return;
}

#pragma thumb off
