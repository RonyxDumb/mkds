#include "Main/Race/kart_highest_lap.h"
#include "Main/Unknown/code_020f36d8.h"

u16 GetKartHighestLap(int kart) {
    return gRaceProgress->mKarts[kart].mHighestLap;
}
