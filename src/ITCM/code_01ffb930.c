#include "ITCM/code_01ffb930.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02165000.h"

void ScaleKartForwardSpeed(Kart *kart) {
    if ((kart->mMotionFlags & KART_MOTION_COASTING) || kart->mState != KART_STATE_NORMAL) {
        kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, kart->mPhysicalParam->mForwardSpeedFactor);
    }
    if (!(kart->mDriveFlags & KART_DRIVE_SLOWING_STOP)) {
        return;
    }
    kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, 0xe66);
}

void ApplyKartGravity(Kart *kart) {
    kart->mVerticalSpeed = kart->mVerticalSpeed + kart->mGravity;
}

void ReduceKartSpeedByTurnRatio(s32 *speed, Kart *kart) {
    s32 turnRatio;
    u32 flags;
    s32 reduction;

    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    flags = kart->mMotionFlags;
    if (flags & KART_MOTION_DRIFTING) {
        return;
    }
    if (!(flags & KART_MOTION_ON_GROUND)) {
        return;
    }
    if (*speed <= 0x3000) {
        return;
    }
    turnRatio = kart->mTurnRatio;
    if (turnRatio <= 0) {
        turnRatio = -turnRatio;
    }
    reduction = MUL_FIXED12_NO_ROUND(*speed, gSpeedReductionAtFullTurnRatio);
    *speed -= MUL_FIXED12_NO_ROUND(reduction, turnRatio);
}
