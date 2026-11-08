#include "Main/Unknown/code_0203c240.h"
#include "Main/Unknown/code_020f36d8.h"

u32 GetKartFinishTimeMs(u32 kart) {
    return gRaceProgress->mKarts[kart].mFinishTimeMs;
}
