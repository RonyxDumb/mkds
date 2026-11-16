#include "Main/Unknown/code_020b19b4.h"
#include "Main/Unknown/unk_0217b000.h"

void GetRaceHudTimeDifference(s32 **a, TimeDigits **b) {
    *a = &r2d_sStatus->mTimeDifferenceSign;
    *b = &r2d_sStatus->mTimeDifferenceDigits;
}
