#include "Main/Unknown/code_0208c16c.h"
#include "Main/Unknown/code_020888b4.h"

u32 GetKartAiHeadingSwingAtRaceStart(KartAi *kartAi) {
    return kartAi->mRaceSpeedLimit.mHeadingSwingAtRaceStart;
}

u32 GetKartAiBoostsAtRaceStart(KartAi *kartAi) {
    return kartAi->mRaceSpeedLimit.mBoostsAtRaceStart;
}

u32 GetKartAiRaceStartBoostChoice(KartAi *kartAi) {
    return kartAi->mRaceSpeedLimit.mRaceStartBoostChoice;
}
