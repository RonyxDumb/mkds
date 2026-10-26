#include "01/code_0218dde8.h"

void func_ov001_0218de14(u32 param_1, int param_2) {
    func_ov001_02186368((void *) (param_1), (Unk02188950 *) (param_2));
    if (*(int *) (param_2 + 0xa8) == 0) {
        func_ov001_021861f4((void *) (param_1), (Unk02188950 *) (param_2), (s32) (0));
        return;
    }
    func_ov001_021861f4((void *) (param_1), (Unk02188950 *) (param_2), (s32) (1));
    return;
}

void func_ov001_0218dde8(void) {
    unsigned int v6 = ((u32) (&func_ov001_02185fb0));
    unsigned int v7 = ((u32) (&func_ov001_02185f04));
    unsigned int v8 = ((u32) (&func_ov001_021860cc));
    unsigned int v10 =
        (unsigned int) func_ov001_0219b510((u32) ((unsigned int) (v6)), (u32) ((unsigned int) (v7)), (u32) ((unsigned int) (v8)), (u32) ((unsigned int) (0x2u)), (u16) ((unsigned int) (0x0u)), (u16) ((unsigned int) (0x0u)), (u16) ((unsigned int) (0x0u)));
}
