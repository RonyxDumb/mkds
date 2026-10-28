#include "00/code_021937c0.h"

s32 func_ov000_021937c0(Unk0218f960 *object) {
    Unk021937c0Node *node = object->mUnk_00->mUnk_424;
    while (node != 0) {
        if (node->mUnk_08 != 0 && node->mUnk_00 != 3) {
            return 1;
        }
        node = node->mNext;
    }
    return 0;
}
