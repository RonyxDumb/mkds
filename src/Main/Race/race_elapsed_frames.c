#include "Main/Race/race_elapsed_frames.h"
#include "Main/Race/data_020f36d8.h"

s32 GetRaceElapsedFrames(void) {
    return ((u32) gRaceProgress->mHeader.mElapsedFrames);
}
