#include "Main/Unknown/code_02089ce4.h"
#include "Main/Unknown/code_020888b4.h"

void SetupBattleKartAiSpeedLimit(KartAiSpeedLimit *speedLimit, KartAi *kartAi) {
    speedLimit->mBaseSpeedLimit = kartAi->mKart->mPhysicalParam->mBaseSpeedLimit;
    speedLimit->mSpeedLimit = speedLimit->mBaseSpeedLimit;
    speedLimit->field8 = 0x5000;
    speedLimit->fieldC = FALSE;
    speedLimit->mTurnSpeedLimit = 0;
}
