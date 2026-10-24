#include "03/code_021c515c.h"

void func_ov003_021c5258(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if (iVar1 == 0) {
        func_ov003_021bf344();
        if (*((unsigned char *) ((u32) (&data_ov003_021da1dc))) == '\0') {
            func_ov003_021d1ee0((int) (3), (int) (1), (u32) (1), (u16) (8));
        }
        func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x15), (u16) (8));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c51bc)))));
    }
    return;
}

// non-matching: 0x94 bytes, original 0x9c; 19 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c51bc(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (0));
    if ((iVar1 == 0) && (((*((unsigned char *) ((u32) (&data_ov003_021da1dc))) != '\0' ||
                           (iVar1 = func_ov003_021d1f70((int) (1)), iVar1 == 0)) &&
                          (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)))) {
        func_ov003_021c1f84((int) (*((unsigned char *) ((u32) (&data_ov003_021da1dc))) != '\0'));
        func_ov003_021beecc();
        func_ov003_021d2168((int) (0));
        if (*((unsigned char *) ((u32) (&data_ov003_021da1dc))) == '\0') {
            func_ov003_021bf410();
            func_ov003_021d272c((int) (1), (u32) (1));
        }
        func_ov003_021d272c((int) (0), (u32) (0x15));
        if (*((unsigned char *) ((u32) (&data_ov003_021da1dc))) == '\0') {
            func_ov003_021c2120((u32) (2), (u32) (1));
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021cb7fc)))));
            return;
        }
        func_ov003_021c2120((u32) (0), (u32) (0));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c56a4)))));
    }
    return;
}

void func_ov003_021c51a0(void) {
    func_ov003_021d2d14();
    func_ov003_021d3558((int) (0));
    func_ov003_021c52f4();
    func_ov003_021c52d0();
    return;
}

void func_ov003_021c5178(void) {
    int iVar1;
    iVar1 = func_ov003_021cef80();
    if (iVar1 == 0) {
        func_ov003_021cdc10((u32) (6));
        func_ov003_021cef90();
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c515c)))));
    }
    return;
}

void func_ov003_021c515c(void) {
    int iVar1;
    iVar1 = func_ov003_021cef6c();
    if (iVar1 == 0) {
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c52a0)))));
    }
    return;
}
