#include "03/code_021c33e4.h"

void func_ov003_021c3490(void) {
    int iVar1;
    iVar1 = func_ov003_021d2b04((u32) (1));
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021c348c(void) {
    return;
}

void func_ov003_021c3468(void) {
    int iVar1;
    iVar1 = func_ov003_021bf334();
    if (iVar1 == 0) {
        func_ov003_021cdc10((u32) (6));
        func_ov003_021c212c(func_ov003_021c3448);
    }
    return;
}

void func_ov003_021c3448(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c3410);
    return;
}

void func_ov003_021c3410(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if (iVar1 == 0) {
        func_ov003_021d1ee0((int) (3), (int) (1), (u32) (0x3f), (u16) (0x40));
        func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x3f), (u16) (0x40));
        func_ov003_021c212c(func_ov003_021c33e4);
    }
    return;
}

void func_ov003_021c33e4(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if ((iVar1 == 0) && (iVar1 = func_ov003_021d1f70((int) (0)), iVar1 == 0)) {
        func_0200fd10((u32) (((u32) 0x01000000u)));
        func_0214fb54();
    }
    return;
}
