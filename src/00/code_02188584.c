#include "00/code_02188584.h"

u32 func_ov000_02188584(u32 param_1) {
    if ((param_1 & 1) != 0) {
        return (u32) data_ov000_021b4d10;
    }
    if ((param_1 & 2) != 0) {
        return *(u32 *) &data_ov000_021b4d04;
    }
    if ((param_1 & 4) != 0) {
        return *(u32 *) &data_ov000_021b4d08;
    }
    if ((param_1 & 8) != 0) {
        return *(u32 *) &data_ov000_021b4d0c;
    }
    if ((param_1 & 0x10) != 0) {
        return *(u32 *) &data_ov000_021b4d00;
    }
    return 0;
}
