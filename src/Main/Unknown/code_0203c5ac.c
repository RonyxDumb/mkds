#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_020f36d8.h"

u32 GetKartRaceProgress(u32 arg0) {
    return gRaceProgress->mKarts[arg0].mRaceProgress;
}

u32 GetKartLapProgress(u32 arg0) {
    return gRaceProgress->mKarts[arg0].mLapProgress;
}
