#include "03/code_021c1648.h"

void func_ov003_021c1648(int param_1) {
    if (param_1 != *(s8 *) ((*(int *) &data_ov003_021da160) + 0x62)) {
        func_ov003_021c12cc((int) (param_1), (int) (1));
        func_ov003_021c12cc((int) ((int) *(s8 *) ((*(int *) &data_ov003_021da160) + 0x62)), (int) (0));
        *(s8 *) ((*(int *) &data_ov003_021da160) + 0x62) = (s8) param_1;
    }
    return;
}
