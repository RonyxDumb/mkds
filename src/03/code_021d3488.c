#include "03/code_021d3488.h"

void func_ov003_021d3488(int param_1, int param_2) {
    if (*(unsigned char *) (param_2 + 0x11) != '\0') {
        func_ov003_021d2808((int *) (u32) (param_2 + 0xc));
    }
    func_ov003_021d2e90((unsigned int) ((int *) (u32) (param_2)));
    func_ov003_021d1d0c((u16 *) ((u16 *) (u32) (*(u32 *) (*((int *) ((u32) (&data_ov003_021da32c))) + param_1 * 0x3c))),
                        (u32) (param_2));
    return;
}
