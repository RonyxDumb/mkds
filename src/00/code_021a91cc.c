#include "00/code_021a91cc.h"

void func_ov000_021a91cc(s32 a) {
    s32 i;
    Unk021a91cc *b;
    i = 0;
    b = (Unk021a91cc *) data_ov000_021b61f4;
    for (; i < 4; i++) {
        if (b->mUnk_5a != 0 && a - b->mUnk_50 > 0xef) {
            b->mUnk_5a = 0;
        }
        b++;
    }
}
