#include "00/Lib/GameSpy/code_0218e2a4.h"

#include "00/Lib/GameSpy/code_0218e2dc.h"

s32 longrand(void) {
    gRandomNum = nextlongrand(gRandomNum);
    return gRandomNum;
}

void Util_RandSeed(u32 seed) {
    if (seed != 0) {
        seed &= 0x7fffffff;
    } else {
        seed = 1;
    }
    gRandomNum = seed;
}
