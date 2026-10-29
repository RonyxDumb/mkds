#include "Main/Unknown/code_020574c8.h"

#pragma thumb on

void func_02057514(void) {
    *(u8 *) ((*(int *) &data_0217aa08) + 0x28) = 1;
    return;
}

void func_02057504(void) {
    *(u8 *) ((*(int *) &data_0217aa08) + 0x28) = 0;
    return;
}

void func_020574c8(void) {
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        func_02145d38();
    }
    func_02057ca4((void *) (*(u32 *) (*(u32 *) &data_0217aa08)));
    if (*(int *) ((*(int *) &data_021759d4) + 0xc) != 0) {
        func_02145d38();
    }
    func_02057504();
    return;
}

#pragma thumb off
