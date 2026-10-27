#include "Main/Unknown/code_02100094.h"

s32 func_02100094(Unk02100094 *p) {
    s32 n = p->mUnk_04;

    while (n > 1 && *(u16 *) p->mUnk_00[n - 1] == 0x6f) {
        n--;
    }
    return n;
}
