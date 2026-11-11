#include "code_020222e0.h"

NNSG2dAnimDataSRT *NNS_G2dGetAnimCtrlCurrentElement(Unk02022030 *pAnimCtrl) {
    return (NNSG2dAnimDataSRT *) pAnimCtrl->mPCurrent->mPContent;
}
