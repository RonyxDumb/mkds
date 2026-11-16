#include "Main/Unknown/code_0203f280.h"
#include "Main/Unknown/code_020f36d8.h"

u32 rstat_rconf_getRules(void) {
    return (gRaceMultiConfig->mRuleKind);
}

u16 rstat_getFirstPlaceDriverId(void) {
    return gRaceStatus->mKartAtRank[0];
}
