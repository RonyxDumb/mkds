#include "Main/Kart/first_base_speed_limit.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Kart/kart_drift.h"

struct KartPhysicalParam *GetKartPhysicalParam(u32 arg0) {
    return &gKartPhysicalParamTable->mKartParams[arg0];
}

s32 *GetCharPhysicalParam(u32 p0) {
    return OFFSET_PTR(s32, gKartPhysicalParamTable->mCharParams, p0 << 3);
}

s32 GetFirstBaseSpeedLimit(void) {
    return (gKartPhysicalParamTable->mFirstBaseSpeedLimit);
}
