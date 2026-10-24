#include "Main/Unknown/code_020cab74.h"

u32 func_020cab74(void) {
    return ((*(u32 *) (0x04001000u & 0xfffffffc) >> (0x04001000u & 3) * 8 | *(u32 *) (0x04001000u & 0xfffffffc)
                                                                                << (0x04001000u & 3) * -8 + 0x20) &
            0x1f00) >>
           8;
}
