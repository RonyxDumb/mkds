#include "code_0202210c.h"
#include "code_020222ec.h"
#include "code_02134398.h"

static inline void CallbackFuncHandling_(const Unk02022030 *pAnimCtrl, u16 currentFrameIdx) {
    switch (pAnimCtrl->mCallbackFunctor.mType) {
        case 2:
            if (currentFrameIdx == pAnimCtrl->mCallbackFunctor.mFrameIdx) {
                pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, currentFrameIdx);
            }
            break;
        case 3:
            pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, currentFrameIdx);
            break;
    }
}

static inline u32 ShouldAnmCtrlMoveNext_(Unk02022030 *pAnimCtrl) {
    if (pAnimCtrl->field8 != 0 && pAnimCtrl->fieldC >= (((Unk02022188 *) pAnimCtrl->field0)->field4 << 12)) {
        return 1;
    }
    return 0;
}

u32 NNS_G2dTickAnimCtrl(Unk02022030 *pAnimCtrl, s32 frames) {
    u32 changedFrame;
    s32 atEdge;
    Unk02021e40 *next;
    u16 frameIdx;
    s32 *currentTime;

    changedFrame = 0;
    if (pAnimCtrl->field8 != 1) {
        return 0;
    }
    pAnimCtrl->fieldC += Abs(((s64) pAnimCtrl->field10 * frames + 0x800) >> 12);
    currentTime = &pAnimCtrl->fieldC;
    while (ShouldAnmCtrlMoveNext_(pAnimCtrl)) {
        changedFrame = 1;
        *currentTime = *currentTime - (((Unk02022188 *) pAnimCtrl->field0)->field4 << 12);
        if ((pAnimCtrl->field10 > 0) ^ pAnimCtrl->field4) {
            pAnimCtrl->field0++;
        } else {
            pAnimCtrl->field0--;
        }
        next = pAnimCtrl->field0;
        if ((pAnimCtrl->field10 > 0) ^ pAnimCtrl->field4) {
            atEdge = next >= &pAnimCtrl->field18->fieldC[pAnimCtrl->field18->field0];
        } else {
            atEdge = next <= &pAnimCtrl->field18->fieldC[pAnimCtrl->field18->field2] - 1;
        }
        if (atEdge) {
            SequenceEdgeHandle_(pAnimCtrl);
        }
        if (pAnimCtrl->mCallbackFunctor.mType != 0) {
            frameIdx = ((u32) pAnimCtrl->field0 - (u32) pAnimCtrl->field18->fieldC) >> 3;
            CallbackFuncHandling_(pAnimCtrl, frameIdx);
        }
    }
    return changedFrame;
}

u32 NNS_G2dSetAnimCtrlCurrentFrame(Unk02022030 *pAnimCtrl, u32 index) {
    u32 result;

    result = SetAnimCtrlCurrentFrameImpl_(pAnimCtrl, index);
    if (result != 0) {
        pAnimCtrl->fieldC = 0;
    }
    return result;
}
