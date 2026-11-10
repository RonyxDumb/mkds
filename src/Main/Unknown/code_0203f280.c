#include "Main/Unknown/code_0203f280.h"
#include "Main/Unknown/code_020f36d8.h"

u32 RaceProgressGetCurrentRuleKind(void) {
    return (gRaceSetup->mRuleKind);
}

u16 GetLeadingKart(void) {
    return gRaceProgress->mKartAtRank[0];
}
