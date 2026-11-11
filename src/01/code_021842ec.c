#include "01/code_021842ec.h"
#include "01/unk_021a6000.h"

void StartDonketuWaterLandState(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 7, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mUnk_23c, donketu->mPrm->mUnk_240, NULL);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x412, 0);
    StartMapObjectSound(&donketu->mUnk_000, 0x242);
    StartCameraWobbleAtDistance(donketu->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mUnk_000.mFlags &= ~0x20;
}
