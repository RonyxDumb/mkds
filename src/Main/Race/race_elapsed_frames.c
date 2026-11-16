#include "Main/Race/race_elapsed_frames.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/init_after_startup.h"

s32 GetRaceElapsedFrames(void) {
    return ((u32) gRaceProgress->mHeader.mElapsedFrames);
}
