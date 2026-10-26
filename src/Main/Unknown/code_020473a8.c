#include "Main/Unknown/code_020473a8.h"

#pragma thumb on

void func_02047468(u32 param_1, u32 param_2) {
    u32 uVar1;
    u8 auStack_8c[128];
    uVar1 = func_02048440();
    func_0200d9e0((char *) auStack_8c, 0x80, (const char *) ((u32) ((u32) (&data_02164ffc))), param_1, uVar1);
    func_02047498((u32) ((u32) (u32) (auStack_8c)), (int) (param_2));
    return;
}

void func_020473e4(void) {
    func_0204f5e4();
    func_0201804c((u32) (*(u32 *) (*((int *) ((u32) (&data_021759c8))) + ((int) 0x00000a80u))), (u32) (3));
    func_02047498((u32) (((u32) ((u32) (&data_02164f48)))), (int) (0xb));
    func_02047498((u32) (((u32) ((u32) (&data_02164f64)))), (int) (0xc));
    func_02047498((u32) (((u32) ((u32) (&data_02164f80)))), (int) (0));
    func_02047468((u32) (((u32) ((u32) (&data_02164f98)))), (u32) (1));
    func_02047498((u32) (((u32) ((u32) (&data_02164fac)))), (int) (8));
    func_02047498((u32) (((u32) ((u32) (&data_02164fc0)))), (int) (9));
    func_02047468((u32) (((u32) ((u32) (&data_02164fd4)))), (u32) (10));
    func_02047498((u32) (((u32) ((u32) (&data_02164fe4)))), (int) (0xd));
    return;
}

void func_020473a8(void) {
    func_0204f5e4();
    func_0201804c((u32) (*(u32 *) (*((int *) ((u32) (&data_021759c8))) + ((int) 0x00000a80u))), (u32) (3));
    func_02047498((u32) (((u32) ((u32) (&data_02164f1c)))), (int) (0));
    func_02047468((u32) (((u32) ((u32) (&data_02164f34)))), (u32) (1));
    return;
}

#pragma thumb off
