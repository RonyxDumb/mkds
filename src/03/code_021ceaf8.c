#include "03/code_021ceaf8.h"

void func_ov003_021ceaf8(int param_1) {
    u32 local_10;
    int local_c;
    func_ov003_021d1770((int) (*(u32 *) (*(int *) &data_ov003_021da284)), (int) (0), &local_10, (u32 *) (&local_c));
    local_c = local_c + 0xc;
    func_ov003_021cec50();
    if (192 <= local_c) {
        if (*(unsigned char *) ((*(int *) &data_ov003_021da284) + 0x1e) != '\0') {
            func_ov003_021d34e0((int) (param_1), (u32) (((u32) &func_ov003_021ceab8)));
            return;
        }
        func_ov003_021d34e0((int) (param_1), (u32) (((u32) &func_ov003_021cea3c)));
    }
    return;
}
