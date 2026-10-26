#include "code_0214a348.h"

void func_0214a348(u16 *p, s32 v) {
    u32 t;

    t = p[0];
    if (v < 0) {
        if ((t & 0xc0) == 0x80) {
            p[0] = (t & ~0xc0) | 0xc0;
        }
        p[2] = -v;
    } else {
        if ((t & 0xc0) == 0xc0) {
            p[0] = (t & ~0xc0) | 0x80;
        }
        p[2] = v;
    }
}
