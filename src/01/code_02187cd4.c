#include "01/code_02187cd4.h"
#include "01/code_02187d14.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"
#include "code_020109c4.h"

void SetNodePositionSource(Unk02188950 *mapObject, u32 matchValue) {
    MapObjectModel **nsbmdPointer;
    mapObject->mUnk_2e4 = matchValue;
    mapObject->mUnk_27c = 3;
    nsbmdPointer = &mapObject->mNsbmd;
    (*nsbmdPointer)->mAnimatedModel->mRenderObj.mPtrUser = mapObject;
    NNS_G3dRenderObjSetCallBack(&(*nsbmdPointer)->mAnimatedModel->mRenderObj, StoreNodePositionAndPlaceItemBomb, 0, 6,
                                (u8) 3);
}
