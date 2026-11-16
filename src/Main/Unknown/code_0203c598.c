#include "Main/Unknown/code_0203c598.h"
#include "Main/Unknown/code_020f36d8.h"

s32 rstat_getFrameCounter(void) {
    return ((u32) gRaceStatus->field0[0].mElapsedFrames);
}
