#include "03/code_021c0ca8.h"

void func_ov003_021c0cf8(void) {
    func_ov003_021d197c(*(Unk021d1770 **) ((int) data_ov003_021da15c + 0x114));
    func_ov003_021d34e0((Unk021d34e0 *) (*(u32 *) ((int) data_ov003_021da15c + 0x118)),
                        func_ov003_021bfc80);
}

u8 func_ov003_021c0ce4(void) {
    return *(u8 *) ((int) data_ov003_021da15c + 0x11c);
}

void func_ov003_021c0cd0(u8 param_1) {
    *(u8 *) ((int) data_ov003_021da15c + 0x123) = param_1;
}

void func_ov003_021c0cbc(u8 param_1) {
    *(u8 *) ((int) data_ov003_021da15c + 0x124) = param_1;
}

u32 func_ov003_021c0ca8(void) {
    if ((int) data_ov003_021da15c != 0) {
        return 1;
    }
    return 0;
}
