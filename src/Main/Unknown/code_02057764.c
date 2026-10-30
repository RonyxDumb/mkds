#include "Main/Unknown/code_02057764.h"

#pragma thumb on

void func_020577b4(void *param_1) {
    u32 *puVar1;
    puVar1 = *(u32 **) ((*(int *) &data_021759d4) + 0x60);
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        func_0214d1fc((const void *) ((u16 *) (u32) (param_1)), (void *) (puVar1), (u32) (((u32) 0x00000c00u)));
        *puVar1 = ((u32) 0x4c464b4eu);
        func_0204b430((u32) (((u32) 0x00001f00u)), (u32) (((u32) 0x00032e00u)), (u32) ((u32) (u32) (puVar1)),
                      (u32) (((u32) 0x00000c00u)), (u32) (0), (u32) (0));
    }
    return;
}

void func_02057764(u32 param_1) {
    int *piVar1;
    piVar1 = (int *) &data_021759d4;
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        *(u32 *) ((*(int *) &data_021759d4) + 0x68) = param_1;
        *(u32 *) (*piVar1 + 0x5c) = 0xffffffff;
        func_0204b6cc((u32) (((u32) 0x00001f00u)), (u32) (((u32) 0x00032e00u)), (u32) (*(u32 *) (*piVar1 + 0x60)),
                      (u32) (((u32) 0x00000c00u)), (u32) &func_02057cfc, (u32) (((u32) 0x4c464b4eu)),
                      (u32) (0));
    }
    return;
}

#pragma thumb off
