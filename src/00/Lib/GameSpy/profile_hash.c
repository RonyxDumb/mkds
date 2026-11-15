#include "00/Lib/GameSpy/profile_hash.h"

s32 GpiHashProfile(const s32 *value, s32 divisor) {
    return *value % divisor;
}
