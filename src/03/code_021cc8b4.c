#include "03/code_021cc8b4.h"

BOOL UsbPAD_DetectFold(void) {
    s32 flags = (*(volatile u16 *) 0x027fffa8 & 0x8000) >> 15;
    if (flags != 0) {
        return 1;
    }
    return 0;
}
