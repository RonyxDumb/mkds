#include "01/code_02187c60.h"
#include "01/code_02187d14.h"
#include "01/code_0218d520.h"
#include "code_020109c4.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_02147000.h"

void SetNodePositionSourceAndBombOffset(Unk02188950 *mapObject, s32 matchValue, const Vec3 *offset) {
    mapObject->mUnk_2e4 = matchValue;
    mapObject->mUnk_2f4 = *offset;
    mapObject->mNsbmd->mAnimatedModel->mRenderObj.mPtrUser = mapObject;
    NNS_G3dRenderObjSetCallBack(&mapObject->mNsbmd->mAnimatedModel->mRenderObj, StoreNodePositionAndPlaceItemBomb, 0, 6,
                                3);
}

void ReleaseAndSetItemBomb(Unk02188950 *mapObject, void *itemBomb) {
    if (mapObject->mItemBomb != NULL) {
        ReleaseItemBomb(&mapObject->mItemBomb);
    }
    mapObject->mItemBomb = itemBomb;
}
