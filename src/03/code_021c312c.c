#include "03/code_021c312c.h"

void func_ov003_021c31fc(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c31b4)))));
    return;
}

void func_ov003_021c31b4(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if (iVar1 == 0) {
        func_ov003_021bf344();
        if (*((unsigned char *) ((u32) (&data_ov003_021da1a8))) == '\0') {
            func_ov003_021d1ee0((int) (3), (int) (1), (u32) (1), (u16) (8));
        }
        func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x15), (u16) (8));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c312c)))));
    }
    return;
}

// non-matching: 0x80 bytes, original 0x88; 20 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c312c(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (0));
    if ((iVar1 == 0) && (((*((unsigned char *) ((u32) (&data_ov003_021da1a8))) != '\0' ||
                           (iVar1 = func_ov003_021d1f70((int) (1)), iVar1 == 0)) &&
                          (iVar1 = func_ov003_021bf2f0(), iVar1 != 0)))) {
        func_ov003_021d2168((int) (0));
        if (*((unsigned char *) ((u32) (&data_ov003_021da1a8))) == '\0') {
            func_ov003_021bf410();
            func_ov003_021d272c((int) (1), (u32) (1));
        }
        func_ov003_021d272c((int) (0), (u32) (0x15));
        if (*((unsigned char *) ((u32) (&data_ov003_021da1a8))) == '\0') {
            func_ov003_021c2120((u32) (0), (u32) (1));
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c3dd4)))));
            return;
        }
        func_ov003_021c2120((u32) (0), (u32) (1));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c3598)))));
    }
    return;
}
