#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/unk_0217b000.h"

BOOL GetShowLapTime(void) {
    return (r2d_sStatus->mShowLapTime);
}

u32 GetShowLapTimeFrames(void) {
    return (r2d_sStatus->mShowLapTimeFrames);
}

u32 GetUseTimeDifference(void) {
    return (r2d_sStatus->mUseTimeDifference);
}
