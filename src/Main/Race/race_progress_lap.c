#include "Main/Race/race_progress_lap.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/init_after_startup.h"

u32 GetSomeRacerValue(u32 kartIndex) {
    return g_GlobalMV->mKarts[kartIndex].mRaceProgress;
}

u32 GetKartLapProgress(u32 kartIndex) {
    return g_GlobalMV->mKarts[kartIndex].mLapProgress;
}
