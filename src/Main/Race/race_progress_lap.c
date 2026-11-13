#include "Main/Race/race_progress_lap.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/System/init_after_startup.h"

u32 GetKartRaceProgress(u32 arg0) {
    return gRaceProgress->mKarts[arg0].mRaceProgress;
}

u32 GetKartLapProgress(u32 arg0) {
    return gRaceProgress->mKarts[arg0].mLapProgress;
}
