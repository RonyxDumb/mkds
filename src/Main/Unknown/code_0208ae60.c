#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/unk_0217b000.h"

struct KartPhysicalParam *physp_getDriverKartPhysicalParams(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &physp_sPhysicalParams;
    value1 = 0x98u;
    value2 = *(const u32 *) ((value2) + (0));
    value2 = *(const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (struct KartPhysicalParam *) value0;
}

s32 *physp_getDriverCharPhysicalParams(u32 p0) {
    return (s32 *) (physp_sPhysicalParams->mCharParams + (p0 << 3));
}

s32 physp_getField8(void) {
    return (physp_sPhysicalParams->mFirstBaseSpeedLimit);
}
