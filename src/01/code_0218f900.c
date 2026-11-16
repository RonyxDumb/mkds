#include "01/code_0218f900.h"
#include "01/code_02188cd8.h"

#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218f000.h"
#include "Main/Unknown/code_0209bef0.h"

u16 func_ov001_0218f9c0(Unk02188950 *a) {
    return a->fieldA8 == 2;
}

void func_ov001_0218f9a8(Unk02188950 *a) {
    a->field2D8 = 0;
    SetKartCollisionCallback(a, func_ov001_0218f9a8);
}

void func_ov001_0218f900(Unk02188950 *a) {
    StartAnimationNoEndCallback(a, a->mPrm->field198, a->mPrm->field19C);
    SetAlphaLimitTargetAndPerCall(a, a->mPrm->field1AC, a->mPrm->field1B0);
    SetSpeedAndClearTarget(a, 0);
    func_ov001_02188c90(a);
    StartEffectAtOffset(a, 0, 0, 0, 0x41b, 0);
    StartEffectAtOffset(a, 0, 0, 0, 0x41c, 0);
    StartEffectAtOffset(a, 0, 0, 0, 0x41d, 0);
    mobj_emitSfxFromEmitter2(&a->field0, 0x22e);
    a->field0.mFlags &= ~1;
}
