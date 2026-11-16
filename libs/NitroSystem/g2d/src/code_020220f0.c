#include "code_020220f0.h"

u16 NNS_G2dGetAnimCtrlCurrentFrame(const Unk02022030 *pAnimCtrl) {
    return ((u32) pAnimCtrl->field0 - (u32) pAnimCtrl->field18->fieldC) / sizeof(Unk02021e40);
}
