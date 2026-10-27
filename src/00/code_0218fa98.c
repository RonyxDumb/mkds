#include "00/code_0218fa98.h"

s32 func_ov000_0218fa98(void *unused, Unk0218fa98 *object, s32 minimum) {
    if (object->mUnk_08 != 0 && *object->mUnk_08 > minimum) {
        --*object->mUnk_08;
    }
    return 1;
}
