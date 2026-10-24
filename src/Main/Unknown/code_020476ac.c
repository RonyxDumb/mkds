#include "Main/Unknown/code_020476ac.h"

#pragma thumb on

void func_0204775c(void) {
    func_02047cf0((int) (6));
    func_02047b6c((u16) (0));
    func_02048050((int) (7), (int) (2));
    func_02047b6c((u16) (9));
    return;
}

void func_02047728(void) {
    int iVar1;
    func_02047cf0((int) (7));
    func_02047cf0((int) (8));
    func_02047b6c((u16) (0));
    iVar1 = func_0205e0a0();
    if (iVar1 == 2) {
        func_02048050((int) (3), (int) (2));
    }
    func_02047b6c((u16) (9));
    return;
}

void func_020476ec(void) {
    int iVar1;
    func_02047cf0((int) (0xd));
    func_02047b6c((u16) (0));
    iVar1 = func_0205e0a0();
    if (iVar1 == 2) {
        func_02048050((int) (5), (int) (2));
        func_02048050((int) (0xb), (int) (2));
        func_02048050((int) (0), (int) (2));
    }
    func_02047b6c((u16) (9));
    return;
}

void func_020476ac(void) {
    u32 uVar1;
    uVar1 = func_0205e0a0();
    func_02047cf0((int) (10));
    func_02047b6c((u16) (0));
    func_02048050((int) (1), (int) (uVar1));
    func_02048050((int) (5), (int) (uVar1));
    func_02048050((int) (0xe), (int) (uVar1));
    func_02048050((int) (0x10), (int) (uVar1));
    func_02047b6c((u16) (9));
    return;
}

#pragma thumb off
