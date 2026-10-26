#include "00/code_021a574c.h"

void func_ov000_021a5794(void) {
    func_ov000_021a6b54();
    func_ov000_021a57a8();
    return;
}

void func_ov000_021a574c(void) {
    int iVar1;
    if (*(unsigned char *) (*((int *) ((u32) (&data_ov000_021b5f50))) + ((u32) 0x0000226bu)) == '\0') {
        *(s8 *) (*((int *) ((u32) (&data_ov000_021b5f50))) + ((int) 0x0000226bu)) = '\x01';
        iVar1 = func_02143dd0(func_ov000_021a4bc4);
        if (iVar1 != 2) {
            func_ov000_021a57fc((int) (0xb));
            func_ov000_021a58a4((u32) (7), (u32) (0), (u32) (0), (u32) (((u32) 0x00000611u)));
        }
    }
    return;
}
