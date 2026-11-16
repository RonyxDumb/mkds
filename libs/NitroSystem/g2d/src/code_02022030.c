#include "code_02022030.h"

void NNS_G2dResetAnimCtrlState(Unk02022030 *pAnimCtrl) {
    if ((pAnimCtrl->field10 > 0) ^ pAnimCtrl->field4) {
        pAnimCtrl->field0 = &pAnimCtrl->field18->fieldC[pAnimCtrl->field18->field2];
    } else {
        pAnimCtrl->field0 = &pAnimCtrl->field18->fieldC[pAnimCtrl->field18->field0] - 1;
    }
    pAnimCtrl->fieldC = 0;
}

void NNS_G2dBindAnimCtrl(Unk02022030 *pAnimCtrl, Unk02021dc8 *pAnimSequence) {
    pAnimCtrl->field18 = pAnimSequence;
    NNS_G2dResetAnimCtrlState(pAnimCtrl);
}
