#include "Main/Unknown/code_020b19b4.h"
#include "Main/Unknown/unk_0217b000.h"

void GetRaceHudTimeDifference(s32 **outSign, TimeDigits **outDigits) {
    *outSign = &gRaceHud->mTimeDifferenceSign;
    *outDigits = &gRaceHud->mTimeDifferenceDigits;
}
