#include "03/code_021c0680.h"

void func_ov003_021c06b0(void) {
    u32 uVar1;
    if (*(unsigned char *) ((*(int *) &data_ov003_021da15c) + ((int) 0x0000011du)) == '\x02') {
        uVar1 = 0;
    } else {
        uVar1 = 2;
    }
    func_ov003_021c00ec((int) (uVar1));
    func_ov003_021cdc10((u32) (1));
    return;
}

void func_ov003_021c0680(void) {
    func_ov003_021c00ec((int) (*(unsigned char *) ((*(int *) &data_ov003_021da15c) + ((int) 0x0000011du)) != '\x01'));
    func_ov003_021cdc10((u32) (1));
    return;
}
