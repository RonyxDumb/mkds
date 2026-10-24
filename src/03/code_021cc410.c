#include "03/code_021cc410.h"

// non-matching: 0x50 bytes, original 0x54; 14 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021cc410(void) {
    int iVar1;
    iVar1 = func_ov003_021cef6c();
    if (iVar1 == 0) {
        if (*((unsigned char *) ((u32) (&data_ov003_021da258))) == '\x01') {
            func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021cc6a4)))));
            return;
        }
        func_ov003_021cdc10((u32) (0xb));
        func_ov003_021bf2e0();
        *((s8 *) ((u32) (&data_ov003_021da258))) = '\0';
        func_ov003_021ce834((u32) (((u32) ((u32) (&func_ov003_021cc4ec)))));
        func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021cc730)))));
    }
    return;
}
