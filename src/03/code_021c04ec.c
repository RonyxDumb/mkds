#include "03/code_021c04ec.h"

void func_ov003_021c04ec(int param_1) {
    if (param_1 != *(s8 *) ((int) data_ov003_021da15c + 0x11f)) {
        func_ov003_021c0050(param_1, 1);
        func_ov003_021c0050((int) ((int) *(s8 *) ((int) data_ov003_021da15c + 0x11f)), 0);
        *(s8 *) ((int) data_ov003_021da15c + 0x11f) = (s8) param_1;
    }
}
