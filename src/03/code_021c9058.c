#include "03/code_021c9058.h"

// non-matching: 0x30 bytes, original 0x2c; 4 instructions differ; first at +0x10: original `ldr r0, [pc, #0x14]
// (->0x28)`, ours `ldr r0, [pc, #0x18] (->0x2c)`
void func_ov003_021c9058(u32 param_1) {
    int iVar1;
    iVar1 = func_ov003_021cdb6c();
    if (*(u8 *) (iVar1 + 0xf6) != param_1) {
        *(s8 *) (*((int *) ((u32) (&data_ov003_021da214))) + 0x43) = (s8) param_1;
        func_ov003_021cdb44((u8) ((unsigned int) (param_1)));
        func_ov003_021c8b94();
    }
    return;
}
