#include "00/code_0219a5e8.h"

s32 gti2ConnectionCompare(const Unk0219a5e8 *const *left, const Unk0219a5e8 *const *right) {
    const Unk0219a5e8 *leftConnection = *left;
    const Unk0219a5e8 *rightConnection = *right;
    if (leftConnection->mAddress != rightConnection->mAddress) {
        return leftConnection->mAddress - rightConnection->mAddress;
    }
    return (s16) (leftConnection->mPort - rightConnection->mPort);
}
