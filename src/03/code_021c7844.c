#include "03/code_021c7844.h"

void func_ov003_021c795c(void) {
    int iVar1;
    iVar1 = func_ov003_021d2b04((u32) (1));
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021c7958(void) {
    return;
}

void func_ov003_021c7934(void) {
    int iVar1;
    iVar1 = func_ov003_021bf334();
    if (iVar1 == 0) {
        func_ov003_021cdc10((u32) (6));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c7914)))));
    }
    return;
}

void func_ov003_021c7914(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c78d8)))));
    return;
}

void func_ov003_021c78d8(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if (iVar1 == 0) {
        func_ov003_021bf344();
        func_ov003_021d1ee0((int) (3), (int) (1), (u32) (1), (u16) (8));
        func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x15), (u16) (8));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c7850)))));
    }
    return;
}

void func_ov003_021c7850(void) {
    int iVar1;
    int local_8[1];
    iVar1 = func_ov003_021d1f70((int) (1));
    if (((iVar1 == 0) && (iVar1 = func_ov003_021d1f70((int) (0)), iVar1 == 0)) &&
        (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)) {
        func_ov003_021d2168((int) (0));
        func_ov003_021bf410();
        func_ov003_021d272c((int) (1), (u32) (1));
        func_ov003_021d272c((int) (0), (u32) (0x15));
        func_ov003_021c20dc(0, local_8);
        if (local_8[0] != 0) {
            func_ov003_021c2120((u32) (2), (u32) (1));
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021cb294)))));
            return;
        }
        func_ov003_021c2120((u32) (2), (u32) (0));
        func_ov003_021c20f8((u32) (0), (u32) (0));
        func_ov003_021c7d30((u8) (0));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c965c)))));
    }
    return;
}

void func_ov003_021c7844(u32 param_1) {
    *((u32 *) ((u32) (&data_ov003_021da200))) = param_1;
    return;
}
