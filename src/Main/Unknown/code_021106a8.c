#include "Main/Unknown/code_021106a8.h"

void func_021106a8(s32 param_1, s32 param_2) {
    u16 id;
    u32 mode;
    mode = 3;
    if (param_1 == 0xc) {
        if (param_2 == 0) {
            id = 0x47;
        } else {
            id = 0x48;
        }
        mode = 0;
    } else {
        id = param_2 + param_1 * 2;
    }
    func_0212ecc0(&data_0217d068, mode, id);
    if (data_0217d068 != 0) {
        func_02105b28(&data_0217d068, 100);
    }
    func_0212ecc0(&data_0217d068, 0, 4);
}
