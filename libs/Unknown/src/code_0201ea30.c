#include "code_0201ea30.h"

void *func_0201ea30(Unk0201ea30 *a, s32 b) {
    u8 *p;
    s32 n;

    p = (u8 *) (a + 1);
    n = a->mUnk_06;
    if (b < 0 || b >= n) {
        return 0;
    }
    return p + b * 8;
}
