#include "00/code_0219a5e8.h"

s32 gti2ConnectionCompare(const Gt2Connection *const *left, const Gt2Connection *const *right) {
    const Gt2Connection *leftConnection = *left;
    const Gt2Connection *rightConnection = *right;
    if (leftConnection->mAddress != rightConnection->mAddress) {
        return leftConnection->mAddress - rightConnection->mAddress;
    }
    return (s16) (leftConnection->mPort - rightConnection->mPort);
}
