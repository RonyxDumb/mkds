#include "00/Lib/GameSpy/profile_hash.h"

s32 GpiHashProfile(const s32 *profile, s32 divisor) {
    return *profile % divisor;
}
