#include "Main/Unknown/code_02077eb4.h"
#include "code_020176c0.h"

#pragma thumb on

void func_02077eb4(void *param_1, u32 *param_2) {
    u32 uVar1;
    u32 uVar2;
    uVar1 = ((u32) func_02036bec((void *) param_1, (u32) (((u32) 0x0000f000u))));
    uVar2 = (u32) func_02017988((void *) ((void *) uVar1), (unsigned int) ((unsigned int) (((u32) 0x0000f000u))),
                          (unsigned int) ((unsigned int) 0));
    param_2[1] = uVar2;
    *param_2 = uVar1;
    param_2[4] = 0;
    param_2[3] = param_2[4];
    param_2[2] = param_2[3];
    param_2[7] = 0;
    param_2[6] = param_2[7];
    param_2[5] = param_2[6];
    param_2[10] = 0;
    param_2[9] = param_2[10];
    param_2[8] = param_2[9];
    param_2[0xb] = 0;
    *(u16 *) (param_2 + 0xc) = 0;
}

#pragma thumb off
