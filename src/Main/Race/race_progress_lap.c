#include "Main/Race/race_progress_lap.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/System/init_after_startup.h"

u32 GetKartRaceProgress(u32 kartIndex) {
    return gRaceProgress->mKarts[kartIndex].mRaceProgress;
}

u32 GetKartLapProgress(u32 kartIndex) {
    return gRaceProgress->mKarts[kartIndex].mLapProgress;
}
