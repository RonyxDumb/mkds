#include "03/code_021c9c90.h"

u32 ExchangeEntryPAD_DetectFold(void) {
    if ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15) {
        return 1;
    }
    return 0;
}
