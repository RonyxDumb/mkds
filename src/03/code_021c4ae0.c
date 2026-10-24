#include "03/code_021c4ae0.h"

// non-matching: 17 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4, r5, lr}`
void func_ov003_021c4ae0(void) {
    int iVar1;
    if (((*((unsigned char *) ((u32) (&data_ov003_021da1d0))) == '\0') &&
         (*((unsigned char *) ((u32) (&data_ov003_021da1d4))) != '\0')) ||
        (iVar1 = func_ov003_021c27e4(), iVar1 != 0)) {
        func_ov003_021d2168((int) (0));
        func_ov003_021d272c((int) (0), (u32) (0x15));
        if (*((unsigned char *) ((u32) (&data_ov003_021da1d4))) == '\0') {
            func_ov003_021bf410();
            func_ov003_021d272c((int) (1), (u32) (1));
        }
        func_ov003_021c2120((u32) (0), (u32) (1));
        if (*((unsigned char *) ((u32) (&data_ov003_021da1d0))) != '\0') {
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c4aa4)))));
            return;
        }
        if (*((unsigned char *) ((u32) (&data_ov003_021da1d4))) == '\0') {
            func_ov003_021d272c((int) (1), (u32) (1));
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c3dd4)))));
            return;
        }
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c4054)))));
    }
    return;
}
