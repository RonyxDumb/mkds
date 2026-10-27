#include "03/code_021c04ec.h"

void func_ov003_021c04ec(int param_1) {
    if (param_1 != *(s8 *) ((*(int *) &data_ov003_021da15c) + ((int) 0x0000011fu))) {
        func_ov003_021c0050((int) (param_1), (int) (1));
        func_ov003_021c0050((int) ((int) *(s8 *) ((*(int *) &data_ov003_021da15c) + ((int) 0x0000011fu))), (int) (0));
        *(s8 *) ((*(int *) &data_ov003_021da15c) + ((int) 0x0000011fu)) = (s8) param_1;
    }
    return;
}
