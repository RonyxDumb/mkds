#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/unk_0217b000.h"

struct KartPhysicalParam *GetKartPhysicalParam(u32 arg0) {
    return OFFSET_PTR(struct KartPhysicalParam, gKartPhysicalParamTable->mKartParams, arg0 * 0x98);
}

s32 *GetCharPhysicalParam(u32 p0) {
    return OFFSET_PTR(s32, gKartPhysicalParamTable->mCharParams, p0 << 3);
}

s32 GetFirstBaseSpeedLimit(void) {
    return (gKartPhysicalParamTable->mFirstBaseSpeedLimit);
}
