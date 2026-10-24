#include "00/code_0218b244.h"

u16 func_ov000_0218b25c(int param_1) {
    return *(u16 *) (param_1 + 4);
}

u32 func_ov000_0218b248(int param_1) {
    if ((*(u8 *) (param_1 + 0x15) & 2) == 2) {
        return 1;
    }
    return 0;
}

u32 func_ov000_0218b244(int param_1) {
    return *(u32 *) (param_1 + 8);
}
