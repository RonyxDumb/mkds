#include "Main/Unknown/code_0208c16c.h"
#include "Main/Unknown/code_020888b4.h"

u32 sub_208C180(KartAi *kartAi) {
    return kartAi->fieldE8.field28;
}

u32 GetKartAiBoostsAtRaceStart(KartAi *kartAi) {
    return kartAi->fieldE8.mBoostsAtRaceStart;
}

u32 GetKartAiRaceStartBoostChoice(KartAi *kartAi) {
    return kartAi->fieldE8.mRaceStartBoostChoice;
}
