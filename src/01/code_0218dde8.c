#include "01/code_0218dde8.h"

void func_ov001_0218de14(u32 param_1, int param_2) {
    func_ov001_02186368();
    if (*(int *) (param_2 + 0xa8) == 0) {
        func_ov001_021861f4((u32) (param_1), (int) (param_2), (int) (0));
        return;
    }
    func_ov001_021861f4((u32) (param_1), (int) (param_2), (int) (1));
    return;
}

void func_ov001_0218dde8(void) {
    unsigned int v6 = ((u32) (&func_ov001_02185fb0));
    unsigned int v7 = ((u32) (&func_ov001_02185f04));
    unsigned int v8 = ((u32) (&func_ov001_021860cc));
    unsigned int v10 =
        func_ov001_0219b510((unsigned int) (v6), (unsigned int) (v7), (unsigned int) (v8), (unsigned int) (0x2u),
                            (unsigned int) (0x0u), (unsigned int) (0x0u), (unsigned int) (0x0u));
}
