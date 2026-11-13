#include "Main/Race/kart_highest_lap.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/System/init_after_startup.h"

u16 GetKartHighestLap(int kart) {
    return gRaceProgress->mKarts[kart].mHighestLap;
}
