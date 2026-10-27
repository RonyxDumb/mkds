#include "03/code_021ca270.h"

void func_ov003_021ca39c(void) {
    int iVar1;
    iVar1 = func_ov003_021d2b04(2);
    if (iVar1 != 0) {
        func_ov003_021bf31c(0);
        return;
    }
    iVar1 = func_ov003_021ca54c();
    if (iVar1 != 0) {
        func_ov003_021bf31c(0);
    }
    return;
}

void func_ov003_021ca398(void) {
    return;
}

void func_ov003_021ca370(void) {
    int iVar1;
    iVar1 = func_ov003_021bf334();
    if (iVar1 == 0) {
        func_ov003_021cdbd0();
        func_ov003_021cdc10(7);
        func_ov003_021c212c(func_ov003_021ca350);
    }
    return;
}

void func_ov003_021ca350(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021ca300);
    return;
}

void func_ov003_021ca300(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70(1);
    if (iVar1 == 0) {
        if (data_ov003_021da224 == 0) {
            func_ov003_021bf344();
        }
        if (data_ov003_021da224 == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x14, 8);
        func_ov003_021c212c(func_ov003_021ca270);
    }
    return;
}

void func_ov003_021ca270(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70(0);
    if ((iVar1 == 0) && (((data_ov003_021da224 != 0 || (iVar1 = func_ov003_021d1f70(1), iVar1 == 0)) &&
                          (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)))) {
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da224 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da224 == 0) {
            func_ov003_021c29b8();
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb7fc);
            return;
        }
        func_ov003_021c2120(0, 0);
        func_ov003_021c212c(func_ov003_021c9c5c);
    }
    return;
}
