#include "Main/Unknown/code_02057a18.h"

#pragma thumb on

void func_02057c60(u32 param_1) {
    int *piVar1;
    piVar1 = (int *) &data_021759d4;
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        *(u32 *) ((*(int *) &data_021759d4) + 0x68) = param_1;
        func_0204b6cc((u32) (0), (u32) (((u32) 0x00030f00u)), (u32) (*(u32 *) (*piVar1 + 0x60)),
                      (u32) (((u32) 0x00000100u)), (u32) (((u32) &func_02057cfc)), (u32) (((u32) 0x59534b4eu)),
                      (u32) (1));
    }
    return;
}

void func_02057c14(u32 param_1) {
    u32 *puVar1;
    puVar1 = *(u32 **) ((*(int *) &data_021759d4) + 0x60);
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        func_0214d1fc((const void *) ((u16 *) (u32) (param_1)), (void *) (puVar1), (u32) (((u32) 0x00000300u)));
        *puVar1 = ((u32) 0x4d454b4eu);
        func_0204b430((u32) (((u32) 0x00000100u)), (u32) (((u32) 0x00031000u)), (u32) ((u32) (u32) (puVar1)),
                      (u32) (((u32) 0x00000300u)), (u32) (0), (u32) (0));
    }
    return;
}

void func_02057bcc(u32 param_1) {
    int *piVar1;
    piVar1 = (int *) &data_021759d4;
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        *(u32 *) ((*(int *) &data_021759d4) + 0x68) = param_1;
        func_0204b6cc((u32) (((u32) 0x00000100u)), (u32) (((u32) 0x00031000u)), (u32) (*(u32 *) (*piVar1 + 0x60)),
                      (u32) (((u32) 0x00000300u)), (u32) (((u32) &func_02057cfc)), (u32) (((u32) 0x4d454b4eu)),
                      (u32) (0));
    }
    return;
}

void func_02057b84(u32 param_1) {
    u32 *puVar1;
    puVar1 = *(u32 **) ((*(int *) &data_021759d4) + 0x60);
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        func_0214d1fc((const void *) ((u16 *) (u32) (param_1)), (void *) (puVar1), (u32) (((u32) 0x00000400u)));
        *puVar1 = ((u32) 0x50474b4eu);
        func_0204b430((u32) (((u32) 0x00000400u)), (u32) (((u32) 0x00031300u)), (u32) ((u32) (u32) (puVar1)),
                      (u32) (((u32) 0x00000400u)), (u32) (0), (u32) (0));
    }
    return;
}

void func_02057b40(u32 param_1) {
    int *piVar1;
    piVar1 = (int *) &data_021759d4;
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        *(u32 *) ((*(int *) &data_021759d4) + 0x68) = param_1;
        func_0204b6cc((u32) (((u32) 0x00000400u)), (u32) (((u32) 0x00031300u)), (u32) (*(u32 *) (*piVar1 + 0x60)),
                      (u32) (((u32) 0x00000400u)), (u32) (((u32) &func_02057cfc)), (u32) (((u32) 0x50474b4eu)),
                      (u32) (0));
    }
    return;
}

void func_02057af4(u32 param_1) {
    u32 *puVar1;
    puVar1 = *(u32 **) ((*(int *) &data_021759d4) + 0x60);
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        func_0214d1fc((const void *) ((u16 *) (u32) (param_1)), (void *) (puVar1), (u32) (((u32) 0x00001600u)));
        *puVar1 = ((u32) 0x41544b4eu);
        func_0204b430((u32) (((u32) 0x00000800u)), (u32) (((u32) 0x00031700u)), (u32) ((u32) (u32) (puVar1)),
                      (u32) (((u32) 0x00001600u)), (u32) (0), (u32) (0));
    }
    return;
}

void func_02057aac(u32 param_1) {
    int *piVar1;
    piVar1 = (int *) &data_021759d4;
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        *(u32 *) ((*(int *) &data_021759d4) + 0x68) = param_1;
        func_0204b6cc((u32) (((u32) 0x00000800u)), (u32) (((u32) 0x00031700u)), (u32) (*(u32 *) (*piVar1 + 0x60)),
                      (u32) (((u32) 0x00001600u)), (u32) (((u32) &func_02057cfc)), (u32) (((u32) 0x41544b4eu)),
                      (u32) (0));
    }
    return;
}

void func_02057a60(u32 param_1) {
    u32 *puVar1;
    puVar1 = *(u32 **) ((*(int *) &data_021759d4) + 0x60);
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        func_0214d1fc((const void *) ((u16 *) (u32) (param_1)), (void *) (puVar1), (u32) (((u32) 0x00000100u)));
        *puVar1 = ((u32) 0x524d4b4eu);
        func_0204b430((u32) (((u32) 0x00001e00u)), (u32) (((u32) 0x00032d00u)), (u32) ((u32) (u32) (puVar1)),
                      (u32) (((u32) 0x00000100u)), (u32) (0), (u32) (0));
    }
    return;
}

void func_02057a18(u32 param_1) {
    int *piVar1;
    piVar1 = (int *) &data_021759d4;
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        *(u32 *) ((*(int *) &data_021759d4) + 0x68) = param_1;
        func_0204b6cc((u32) (((u32) 0x00001e00u)), (u32) (((u32) 0x00032d00u)), (u32) (*(u32 *) (*piVar1 + 0x60)),
                      (u32) (((u32) 0x00000100u)), (u32) (((u32) &func_02057cfc)), (u32) (((u32) 0x524d4b4eu)),
                      (u32) (0));
    }
    return;
}

#pragma thumb off
