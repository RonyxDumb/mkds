#include "03/code_021ca54c.h"

u32 func_ov003_021ca54c(void) {
    if ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15) {
        return 1;
    }
    return 0;
}
