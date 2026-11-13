#include "Main/Kart/first_base_speed_limit.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"

struct KartPhysicalParam *GetKartPhysicalParam(u32 arg0) {
    return &gKartPhysicalParamTable->mKartParams[arg0];
}

s32 *GetCharPhysicalParam(u32 p0) {
    return &gKartPhysicalParamTable->mCharParams[p0 << 1];
}

s32 GetFirstBaseSpeedLimit(void) {
    return (gKartPhysicalParamTable->mFirstBaseSpeedLimit);
}
