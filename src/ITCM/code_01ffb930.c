#include "ITCM/code_01ffb930.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02165000.h"

void ScaleKartForwardSpeed(Kart *kart) {
    if ((kart->mUnk_44 & 0x400) || kart->mState != KART_STATE_NORMAL) {
        kart->mForwardSpeed = (s64) kart->mForwardSpeed * kart->mPhysicalParam->mUnk_2c >> 12;
    }
    if (!(kart->mUnk_48 & 0x2000)) {
        return;
    }
    kart->mForwardSpeed = (s64) kart->mForwardSpeed * 0xe66 >> 12;
}

void ApplyKartGravity(Kart *p) {
    p->mVerticalSpeed = p->mVerticalSpeed + p->mGravity;
}

void ReduceKartSpeedByTurnRatio(s32 *a, Kart *p) {
    s32 b;
    u32 f;
    s32 c;

    if (p->mState != KART_STATE_NORMAL) {
        return;
    }
    f = p->mUnk_44;
    if (f & KART_44_DRIFTING) {
        return;
    }
    if (!(f & KART_44_ON_GROUND)) {
        return;
    }
    if (*a <= 0x3000) {
        return;
    }
    b = p->mTurnRatio;
    if (b <= 0) {
        b = -b;
    }
    c = (s64) *a * gSpeedReductionAtFullTurnRatio >> 12;
    *a -= (s32) ((s64) c * b >> 12);
}
