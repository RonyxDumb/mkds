#include "03/code_021cc97c.h"

void func_ov003_021cc9fc(void) {
    *(u8 *) ((int) data_ov003_021da25c + 0x604) = 1;
}

void func_ov003_021cc9c0(int param_1, int param_2, int param_3, int param_4) {
    int iVar2;
    int iVar1;
    iVar2 = (int) data_ov003_021da25c + 4 + param_2 * 2;
    iVar1 = 0;
    if (param_4 > 0) {
        do {
            func_0214cffc((const void *) param_1, (void *) iVar2, (u32) (param_3 << 1));
            iVar1 = iVar1 + 1;
            param_1 = param_1 + 0x40;
            iVar2 = iVar2 + 0x40;
        } while (iVar1 < param_4);
    }
}

void func_ov003_021cc97c(void) {
    if (*(u8 *) ((int) data_ov003_021da25c + 0x604) != 0) {
        func_0200ee74((const void *) ((int) data_ov003_021da25c + 4), (int) (((u32) 0x00000600u)));
        func_0214bc9c((const void *) ((int) data_ov003_021da25c + 4), (int) 0, (u32) (((u32) 0x00000600u)));
        *(u8 *) ((int) data_ov003_021da25c + 0x604) = 0;
    }
}
