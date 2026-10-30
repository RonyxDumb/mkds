#include "Main/Unknown/code_02048284.h"

#pragma thumb on

void func_02048324(u32 param_1) {
    u32 uVar1;
    uVar1 = func_02048474();
    func_0200d9e0((char *) param_1, 0x80, (const char *) ((u32) &data_021650bc), uVar1, (u32) &data_021650d8);
}

void func_020482f0(u32 param_1, u8 *param_2, int param_3) {
    if (*param_2 != '\0') {
        func_0200d9e0((char *) param_1, 0x80, (const char *) ((u32) &data_021650a0), param_2,
                      ((unsigned int *) &data_02164d28)[param_3], (u32) &data_021650b4);
    }
}

void func_020482ac(int param_1, u8 *param_2, int param_3) {
    u32 uVar1;
    if (*param_2 != '\0') {
        uVar1 = func_02048474();
        func_0200d9e0((char *) param_1, 0x80, (const char *) ((u32) &data_02165080), param_2,
                      ((unsigned int *) &data_02164d28)[param_3], uVar1, (u32) &data_02165098);
    }
}

void func_02048284(u32 param_1, u32 param_2) {
    u32 uVar1;
    uVar1 = func_02048474();
    func_0200d9e0((char *) param_2, 0x80, (const char *) ((u32) &data_02165074), param_1, uVar1);
}

#pragma thumb off
