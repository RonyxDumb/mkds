#include "Main/Race/kart_finish_time.h"
#include "Main/Race/data_020f36d8.h"

u32 GetKartFinishTimeMs(u32 kart) {
    return gRaceProgress->mKarts[kart].mFinishTimeMs;
}
