#include "00/Lib/GameSpy/code_02194b9c.h"

u32 GpiCompareProfiles(u32 leftProfile, u32 rightProfile) {
    u32 leftAddress = (u32) leftProfile;
    u32 rightAddress = rightProfile;
    u32 leftId;
    u32 rightId;
    u32 difference;
    leftId = *(const u32 *) ((leftAddress) + 0u);
    rightId = *(const u32 *) ((rightAddress) + 0u);
    difference = (leftId) - (rightId);
    return difference;
}
