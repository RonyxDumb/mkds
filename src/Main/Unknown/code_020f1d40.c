#include "Main/Unknown/code_020f1d40.h"

#pragma thumb on

u32 func_020f1d40(int param_1) {
    u32 uVar1;
    UnkWordFunc *pcVar2;
    pcVar2 = *(UnkWordFunc **) ((int) data_0217bc34 + param_1 * 0xa8 + 0x48);
    if (pcVar2 != (UnkWordFunc *) 0x0) {
        uVar1 = (*pcVar2)(0, 0, 1);
        return uVar1;
    }
    return 0;
}

#pragma thumb off
