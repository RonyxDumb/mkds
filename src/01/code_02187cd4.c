#include "01/code_02187cd4.h"
#include "01/code_02187d14.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"
#include "code_020109c4.h"

void func_ov001_02187cd4(Unk02188950 *mapObject, u32 b) {
    Unk0219b250 **nsbmdPointer;
    mapObject->field2E4 = b;
    mapObject->field27C = 3;
    nsbmdPointer = &mapObject->mNsbmd;
    (*nsbmdPointer)->mAnimatedModel->mPtrUser = mapObject;
    NNS_G3dRenderObjSetCallBack((*nsbmdPointer)->mAnimatedModel, func_ov001_02187d14, 0, 6, (u8) 3);
}
