#include "00/code_0218ed44.h"

s32 func_ov000_0218ed44(Unk0218f960 *object, s32 *output) {
    Unk0218f960_00 *state;
    if (object == 0 || object->mUnk_00 == 0) {
        return 2;
    }
    state = object->mUnk_00;
    if (state->mUnk_108 != 0) {
        *output = 0;
        return 0;
    }
    *output = state->mUnk_430;
    return 0;
}
