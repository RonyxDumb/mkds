#include "00/code_0218b64c.h"

// non-matching: 23 instructions differ; first at +0x2: original `sub sp, #0x14`, ours `sub sp, #0x1c`
int func_ov000_0218b668(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, int param_7,
                        u32 param_8, u32 param_9) {
    int iVar1;
    if ((param_7 == 0) && (*((int *) ((u32) (&data_ov000_021b4d28))) != 1)) {
        return 0;
    }
    iVar1 = func_ov000_021a3690((u32) (((u32) 0x00000638u)));
    if (iVar1 == 0) {
        return 0;
    }
    *(u32 *) (iVar1 + ((int) 0x00000630u)) = param_8;
    *(u32 *) (iVar1 + ((int) 0x00000634u)) = param_9;
    *(u32 *) (iVar1 + ((int) 0x00000624u)) = 0;
    func_ov000_0218cfb8((u32 *) ((u32 *) (u32) (iVar1 + 0x4c)), (u32) (param_1), (u32) (param_2), (u32) (param_3),
                        (u32) (param_4), (int) (param_7), (int) (((u32) ((u32) (&func_ov000_0218b780)))),
                        (u32) (iVar1));
    func_ov000_0218acf4((u32 *) ((u32 *) (u32) (iVar1)), (u32) (param_5), (u32) (param_6), (int) (param_7),
                        (u32) (((u32) ((u32) (&func_ov000_0218b708)))), (u32) (iVar1));
    return iVar1;
}

void func_ov000_0218b64c(int param_1) {
    func_ov000_0218c958((int) (param_1 + 0x4c));
    func_ov000_0218acb0((int) (param_1));
    func_ov000_021a3668((u32) (param_1));
    return;
}
