#include "03/code_021c4dd4.h"

void func_ov003_021c4f80(void) {
    int iVar1;
    iVar1 = func_ov003_021d2b04((u32) (2));
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
        return;
    }
    iVar1 = func_ov003_021c50d8();
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021c4f7c(void) {
    return;
}

void func_ov003_021c4f54(void) {
    int iVar1;
    iVar1 = func_ov003_021bf334();
    if (iVar1 == 0) {
        func_ov003_021cdbd0();
        func_ov003_021cdc10((u32) (7));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c4f24)))));
    }
    return;
}

void func_ov003_021c4f24(void) {
    if (*((unsigned char *) ((u32) (&data_ov003_021da1d8))) == '\0') {
        func_ov003_021c2824();
    }
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c4ecc)))));
    return;
}

// non-matching: 0x54 bytes, original 0x58; 11 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c4ecc(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if ((iVar1 == 0) && ((*((unsigned char *) ((u32) (&data_ov003_021da1d8))) != '\0' ||
                          (iVar1 = func_ov003_021c27e4(), iVar1 != 0)))) {
        func_ov003_021bf344();
        if (*((unsigned char *) ((u32) (&data_ov003_021da1d8))) == '\0') {
            func_ov003_021d1ee0((int) (3), (int) (1), (u32) (1), (u16) (8));
        }
        func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x15), (u16) (8));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c4e14)))));
    }
    return;
}

// non-matching: 0xb0 bytes, original 0xb8; 23 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c4e14(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (0));
    if (((iVar1 == 0) && (((*((unsigned char *) ((u32) (&data_ov003_021da1d8))) != '\0' ||
                            (iVar1 = func_ov003_021d1f70((int) (1)), iVar1 == 0)) &&
                           (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)))) &&
        ((*((unsigned char *) ((u32) (&data_ov003_021da1d8))) != '\0' ||
          (iVar1 = func_ov003_021c27e4(), iVar1 != 0)))) {
        func_ov003_021beecc();
        func_ov003_021d2168((int) (0));
        if (*((unsigned char *) ((u32) (&data_ov003_021da1d8))) == '\0') {
            func_ov003_021bf410();
            func_ov003_021d272c((int) (1), (u32) (1));
        }
        func_ov003_021d272c((int) (0), (u32) (0x15));
        if (*((unsigned char *) ((u32) (&data_ov003_021da1d8))) == '\0') {
            func_ov003_021c2120((u32) (0), (u32) (1));
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c3dd4)))));
            return;
        }
        if (*((unsigned char *) ((u32) (&data_ov003_021da1d8))) == '\x02') {
            func_ov003_021c2120((u32) (0), (u32) (1));
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c4aa4)))));
            return;
        }
        func_ov003_021c2120((u32) (0), (u32) (1));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c4d3c)))));
    }
    return;
}

void func_ov003_021c4dd4(int param_1) {
    func_ov003_021cdbd0();
    if (param_1 == 0) {
        *((u8 *) ((u32) (&data_ov003_021da1d8))) = 1;
        func_ov003_021cdc10((u32) (0x10));
    } else {
        *((u8 *) ((u32) (&data_ov003_021da1d8))) = 2;
        func_ov003_021cdc10((u32) (0x12));
    }
    func_ov003_021c27d0((u32) (0));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c4f24)))));
    return;
}
