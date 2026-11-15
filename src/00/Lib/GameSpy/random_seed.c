#include "00/Lib/GameSpy/random_seed.h"

#include "00/Lib/GameSpy/socket_calls.h"

u32 gRandomNum = 1;

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
