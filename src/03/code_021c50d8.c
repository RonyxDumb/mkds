#include "03/code_021c50d8.h"

u32 func_ov003_021c50d8(void) {
    if ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15) {
        return 1;
    }
    return 0;
}
