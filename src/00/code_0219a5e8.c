#include "00/code_0219a5e8.h"

s32 func_ov000_0219a5e8(const Unk0219a5e8 *const *left, const Unk0219a5e8 *const *right) {
    const Unk0219a5e8 *a = *left;
    const Unk0219a5e8 *b = *right;
    if (a->mUnk_00 != b->mUnk_00) {
        return a->mUnk_00 - b->mUnk_00;
    }
    return (s16) (a->mUnk_04 - b->mUnk_04);
}
