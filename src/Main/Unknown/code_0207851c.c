#include "Main/Unknown/code_0207851c.h"

#pragma thumb on

void func_0207851c(int param_1) {
    if ((*(int *) (*((int *) ((u32) (&data_0217ad08))) + ((int) 0x000001e0u)) != 0) &&
        (*(int *) (param_1 + 0xb4) != 0)) {
        func_02010458((Unk020101e8 *) *(u32 *) (*(int *) (param_1 + 0x14) + 4), (const u32 *) data_02155048);
        func_020101e8((Unk020101e8 *) *(u32 *) (*(int *) (param_1 + 0x14) + 4), (const u32 *) data_021550a8);
        func_0201050c((Unk020101e8 *) *(u32 *) (*(int *) (param_1 + 0x14) + 4),
                      (Unk02010294 *) *(u32 *) (param_1 + 0xb4), (const u32 *) data_02155048);
        func_02010294((Unk020101e8 *) *(u32 *) (*(int *) (param_1 + 0x14) + 4),
                      (Unk02010294 *) *(u32 *) (param_1 + 0xb4), (const u32 *) data_021550a8);
    }
    return;
}

#pragma thumb off
