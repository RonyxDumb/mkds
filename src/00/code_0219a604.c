#include "00/code_0219a604.h"

u32 func_ov000_0219a604(const Unk0219a604 *object, u32 modulus) {
    return (object->mValue->mUnk_00 * object->mValue->mUnk_04) % modulus;
}
