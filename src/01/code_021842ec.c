#include "01/code_021842ec.h"
#include "01/unk_021a6000.h"

void func_ov001_021842ec(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 7, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->field23C, donketu->mPrm->field240, NULL);
    func_ov001_02188c90(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x412, 0);
    mobj_emitSfxFromEmitter2(&donketu->field0, 0x242);
    cam_tryImpactShakePlayerCamera(donketu->field0.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    SetKartCollisionCallback(donketu, func_ov001_02184874);
    donketu->field0.mFlags &= ~0x20;
}
