#include "01/code_0218ac04.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "01/code_02187000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187e78.h"
#include "01/code_02188000.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_0218ad68.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218a000.h"
#include "01/code_0218add0.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"

const u16 data_ov001_021a6594 = 0x20;

void func_ov001_0218acb4(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};

    IncrementEntryIndex(mapObject);
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field1C0, mapObject->mPrm->field1C4);
    func_ov001_02188c48(mapObject, mapObject->mPrm->field1D0, mapObject->mPrm->field1D4);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->field1C8, mapObject->mPrm->field1CC);
    SetVelocity(mapObject, &velocity);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field1D8, func_ov001_0218ad68);
    mapObject->mGravityEnabled = FALSE;
}

void func_ov001_0218ac04(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->field1B8;
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field1A8, mapObject->mPrm->field1AC);
    SetVelocity(mapObject, &velocity);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->field1B0, mapObject->mPrm->field1B4);
    SetCourseCollisionCallback(mapObject, func_ov001_0218ae60);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field1BC, func_ov001_0218acb4);
    mobj_emitSfxFromEmitter2(&mapObject->field0, 0x239);
    mapObject->field0.mFlags |= data_ov001_021a6594;
}
