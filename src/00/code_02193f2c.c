#include "00/code_02193f2c.h"

Unk02193f2cNode *func_ov000_02193f2c(Unk0218f960 *object, u32 key) {
    Unk02193f2cNode *node = object->mUnk_00->mUnk_434;
    while (node != 0) {
        if (node->mUnk_0c == key && node->mUnk_00 == 0x69) {
            return node;
        }
        node = node->mNext;
    }
    return 0;
}
