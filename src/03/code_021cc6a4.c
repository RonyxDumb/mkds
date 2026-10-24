#include "03/code_021cc6a4.h"

void func_ov003_021cc700(void) {
    int iVar1;
    iVar1 = func_ov003_021d2b04((u32) (2));
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
        return;
    }
    iVar1 = func_ov003_021cc8b4();
    if (iVar1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021cc6fc(void) {
    return;
}

// non-matching: 0x34 bytes, original 0x38; 12 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021cc6c4(void) {
    int iVar1;
    if ((*((unsigned char *) ((u32) (&data_ov003_021da258))) == '\0') && (iVar1 = func_ov003_021bf334(), iVar1 == 0)) {
        *((s8 *) ((u32) (&data_ov003_021da258))) = '\x02';
        func_ov003_021cdbd0();
        func_ov003_021cdc10((u32) (7));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021cc6a4)))));
    }
    return;
}

void func_ov003_021cc6a4(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021cc658)))));
    return;
}
