#include "Main/Unknown/code_020476ac.h"

#pragma thumb on

void func_0204775c(void) {
    func_02047cf0(6);
    func_02047b6c((u16) 0);
    func_02048050(7, 2);
    func_02047b6c((u16) 9);
}

void func_02047728(void) {
    int iVar1;
    func_02047cf0(7);
    func_02047cf0(8);
    func_02047b6c((u16) 0);
    iVar1 = func_0205e0a0();
    if (iVar1 == 2) {
        func_02048050(3, 2);
    }
    func_02047b6c((u16) 9);
}

void func_020476ec(void) {
    int iVar1;
    func_02047cf0(0xd);
    func_02047b6c((u16) 0);
    iVar1 = func_0205e0a0();
    if (iVar1 == 2) {
        func_02048050(5, 2);
        func_02048050(0xb, 2);
        func_02048050(0, 2);
    }
    func_02047b6c((u16) 9);
}

void func_020476ac(void) {
    u32 uVar1;
    uVar1 = func_0205e0a0();
    func_02047cf0(10);
    func_02047b6c((u16) 0);
    func_02048050(1, (int) uVar1);
    func_02048050(5, (int) uVar1);
    func_02048050(0xe, (int) uVar1);
    func_02048050(0x10, (int) uVar1);
    func_02047b6c((u16) 9);
}

#pragma thumb off
