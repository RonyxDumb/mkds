#include "code_020220b0.h"
#include "code_02022098.h"

void NNS_G2dInitAnimCtrl(Unk02022030 *pAnimCtrl) {
    NNS_G2dInitAnimCallBackFunctor(&pAnimCtrl->mCallbackFunctor);
    pAnimCtrl->field0 = 0;
    pAnimCtrl->field4 = 0;
    pAnimCtrl->field8 = 1;
    pAnimCtrl->fieldC = 0;
    pAnimCtrl->field10 = 0x1000;
    pAnimCtrl->field14 = 0;
    pAnimCtrl->field18 = 0;
}
