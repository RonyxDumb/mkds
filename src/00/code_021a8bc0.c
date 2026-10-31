#include "00/code_021a8bc0.h"
#include "00/code_021a8bb0.h"
#include "code_0200d118.h"
#include "code_0214d018.h"

char *func_ov000_021a8bc0(s32 a, const void *b, char *c, u32 d) {
    u8 e[8];
    if (a != 2) {
        return 0;
    }
    if (d < 0x10) {
        return 0;
    }
    func_0214d1fc(b, e, 4);
    func_ov000_021a8bb0(*(u32 *) e, &e[4]);
    func_0200d9e0(c, 0x10, data_ov000_021b49e8, e[7], e[6], e[5], e[4]);
    return c;
}
