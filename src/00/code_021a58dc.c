#include "00/code_021a58dc.h"
#include "code_02133048.h"

u16 func_ov000_021a58dc(u16 a) {
    s32 i;
    s32 j;
    u32 f;

    i = 0;
    j = a;
    f = data_ov000_021b5f50->mUnk_2264;
    do {
        if (f & (1 << (j % 13 + 1))) {
            break;
        }
        j++;
        i++;
    } while (i < 13);
    return (a + i) % 13 + 1;
}
