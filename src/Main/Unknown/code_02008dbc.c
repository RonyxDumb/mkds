#include "Main/Unknown/code_02008dbc.h"

#pragma thumb on

void func_02008dbc(u8 *param_1, int param_2) {
    int iVar1;
    iVar1 = ((int) 0x00000590u) * param_2;
    if (*(unsigned short *) (param_1 + 0x48) !=
        *(unsigned short *) ((*(int *) &data_0216fc40) + iVar1 + ((int) 0x00000518u))) {
        func_0200895c((u32) (param_2));
        func_0214cffc((const void *) (param_1), (void *) ((*(int *) &data_0216fc40) + ((int) 0x000004d0u) + iVar1),
                      (u32) (0xc0));
        func_02008a4c((u32) (param_2));
    }
    return;
}

#pragma thumb off
