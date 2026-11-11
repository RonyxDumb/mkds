#include "ITCM/code_01ffb930.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02165000.h"

void ScaleKartForwardSpeed(Kart *kart) {
    if ((kart->mUnk_44 & 0x400) || kart->mState != KART_STATE_NORMAL) {
        kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, kart->mPhysicalParam->mForwardSpeedFactor);
    }
    if (!(kart->mUnk_48 & 0x2000)) {
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
    flags = kart->mUnk_44;
    if (flags & KART_44_DRIFTING) {
        return;
    }
    if (!(flags & KART_44_ON_GROUND)) {
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
