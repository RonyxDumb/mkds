#include "03/code_021c9d94.h"

void func_ov003_021c9eb0(void) {
    int iVar1;
    iVar1 = func_ov003_021d2b04((u32) (2));
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
        return;
    }
    iVar1 = func_ov003_021ca008();
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021c9eac(void) {
    return;
}

void func_ov003_021c9e84(void) {
    int iVar1;
    iVar1 = func_ov003_021bf334();
    if (iVar1 == 0) {
        func_ov003_021cdbd0();
        func_ov003_021cdc10((u32) (7));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c9e64)))));
    }
    return;
}

void func_ov003_021c9e64(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c9e1c)))));
    return;
}

void func_ov003_021c9e1c(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if (iVar1 == 0) {
        func_ov003_021bf344();
        if (*((unsigned char *) ((u32) (&data_ov003_021da21c))) == '\0') {
            func_ov003_021d1ee0((int) (3), (int) (1), (u32) (1), (u16) (8));
        }
        func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x15), (u16) (8));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c9d94)))));
    }
    return;
}

// non-matching: 0x80 bytes, original 0x88; 20 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c9d94(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (0));
    if ((iVar1 == 0) && (((*((unsigned char *) ((u32) (&data_ov003_021da21c))) != '\0' ||
                           (iVar1 = func_ov003_021d1f70((int) (1)), iVar1 == 0)) &&
                          (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)))) {
        func_ov003_021beecc();
        func_ov003_021d2168((int) (0));
        if (*((unsigned char *) ((u32) (&data_ov003_021da21c))) == '\0') {
            func_ov003_021bf410();
            func_ov003_021d272c((int) (1), (u32) (1));
        }
        func_ov003_021c29b8();
        if (*((unsigned char *) ((u32) (&data_ov003_021da21c))) == '\0') {
            func_ov003_021c2120((u32) (2), (u32) (1));
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021cb7fc)))));
            return;
        }
        func_ov003_021c2120((u32) (0), (u32) (0));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021ca194)))));
    }
    return;
}
