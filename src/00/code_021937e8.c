#include "00/code_021937e8.h"

s32 func_ov000_021937e8(Unk0218f960 *object, Unk021937c0Node **output, u32 key) {
    Unk021937c0Node *node = object->mUnk_00->mUnk_424;
    while (node != 0) {
        if (node->mUnk_18 == key) {
            if (output != 0) {
                *output = node;
            }
            return 1;
        }
        node = node->mNext;
    }
    if (output != 0) {
        *output = 0;
    }
    return 0;
}
