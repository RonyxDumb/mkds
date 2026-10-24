#include "03/code_021c9a0c.h"

void func_ov003_021c9b38(void) {
    int iVar1;
    iVar1 = func_ov003_021d2b04((u32) (2));
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
        return;
    }
    iVar1 = func_ov003_021c9c90();
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021c9b34(void) {
    return;
}

void func_ov003_021c9b0c(void) {
    int iVar1;
    iVar1 = func_ov003_021bf334();
    if (iVar1 == 0) {
        func_ov003_021cdbd0();
        func_ov003_021cdc10((u32) (7));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c9aec)))));
    }
    return;
}

void func_ov003_021c9aec(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c9a9c)))));
    return;
}

// non-matching: 0x4c bytes, original 0x50; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c9a9c(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if (iVar1 == 0) {
        if (*((unsigned char *) ((u32) (&data_ov003_021da218))) == '\0') {
            func_ov003_021bf344();
        }
        if (*((unsigned char *) ((u32) (&data_ov003_021da218))) == '\0') {
            func_ov003_021d1ee0((int) (3), (int) (1), (u32) (1), (u16) (8));
        }
        func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x15), (u16) (8));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c9a0c)))));
    }
    return;
}

// non-matching: 0x88 bytes, original 0x90; 20 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c9a0c(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (0));
    if ((iVar1 == 0) && (((*((unsigned char *) ((u32) (&data_ov003_021da218))) != '\0' ||
                           (iVar1 = func_ov003_021d1f70((int) (1)), iVar1 == 0)) &&
                          (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)))) {
        func_ov003_021beecc();
        func_ov003_021d2168((int) (0));
        if (*((unsigned char *) ((u32) (&data_ov003_021da218))) == '\0') {
            func_ov003_021bf410();
            func_ov003_021d272c((int) (1), (u32) (1));
        }
        func_ov003_021d272c((int) (0), (u32) (0x15));
        if (*((unsigned char *) ((u32) (&data_ov003_021da218))) == '\0') {
            func_ov003_021c29b8();
            func_ov003_021c2120((u32) (2), (u32) (1));
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021cb7fc)))));
            return;
        }
        func_ov003_021c2120((u32) (0), (u32) (0));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c9fd4)))));
    }
    return;
}
