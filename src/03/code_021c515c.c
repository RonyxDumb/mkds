#include "03/code_021c515c.h"
#include "03/code_021cef6c.h"
#include "03/code_021d2d14.h"

void func_ov003_021c5258(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70(1);
    if (iVar1 == 0) {
        func_ov003_021bf344();
        if (data_ov003_021da1dc == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c51bc);
    }
    return;
}

void func_ov003_021c51bc(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70(0);
    if ((iVar1 == 0) && (((data_ov003_021da1dc != 0 || (iVar1 = func_ov003_021d1f70(1), iVar1 == 0)) &&
                          (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)))) {
        func_ov003_021c1f84((int) (data_ov003_021da1dc != 0));
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da1dc == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da1dc == 0) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb7fc);
            return;
        }
        func_ov003_021c2120(0, 0);
        func_ov003_021c212c(func_ov003_021c56a4);
    }
    return;
}

void func_ov003_021c51a0(void) {
    func_ov003_021d2d14();
    func_ov003_021d3558(0);
    func_ov003_021c52f4();
    func_ov003_021c52d0();
    return;
}

void func_ov003_021c5178(void) {
    int iVar1;
    iVar1 = func_ov003_021cef80();
    if (iVar1 == 0) {
        func_ov003_021cdc10(6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021c515c);
    }
    return;
}

void func_ov003_021c515c(void) {
    int iVar1;
    iVar1 = func_ov003_021cef6c();
    if (iVar1 == 0) {
        func_ov003_021c212c(func_ov003_021c52a0);
    }
    return;
}
