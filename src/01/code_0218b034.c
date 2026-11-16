#include "01/code_0218b034.h"
#include "01/code_02185ef4.h"
#include "01/code_02187bfc.h"
#include "01/code_02187c4c.h"
#include "01/code_02187d14.h"
#include "01/code_02188218.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020fd264.h"

void ThrowStoredItemBomb(Unk02188950 *mapObject) {
    Vec3 velocity;

    if (IsItemBombStored(mapObject)) {
        velocity.x = (((s64) mapObject->mPrm->field134 * FX_SinCosTable_[((u16) mapObject->mMoveAngle >> 4) * 2]) >> 12);
        velocity.y = mapObject->mPrm->field138;
        velocity.z =
            (((s64) mapObject->mPrm->field134 * FX_SinCosTable_[((u16) mapObject->mMoveAngle >> 4) * 2 + 1]) >> 12);
        func_ov001_02187bfc(mapObject, &velocity, mapObject->mPrm->field13C);
    }
}

void func_ov001_0218b034(Unk02188950 *mapObject) {
    RandomState64 *rng;
    s32 angle;
    s32 i;
    s32 idx;
    Vec3 pos;

    rng = mobj_getRng1();
    rng->mValue = (s64) rng->mMultiplier * (s64) rng->mValue + rng->mIncrement;
    angle = (u16) (((rng->mValue >> 32) << 16) >> 32);
    for (i = 0; i < 3; i++) {
        Vec3 vel = {0, 0, 0};
        angle += 0x5555;
        if (func_ov001_02188220(mapObject) == 0) {
            idx = ((u16) angle >> 4) * 2;
            pos.x = mapObject->field0.mPos.x + (s32) (((s64) mapObject->mPrm->field14C * FX_SinCosTable_[idx]) >> 12);
            pos.y = mapObject->field0.mPos.y + mapObject->mPrm->field150;
            pos.z =
                mapObject->field0.mPos.z + (s32) (((s64) mapObject->mPrm->field14C * FX_SinCosTable_[idx + 1]) >> 12);
        } else {
            idx = ((u16) angle >> 4) * 2;
            pos.x = mapObject->field0.mPos.x + (s32) (((s64) mapObject->mPrm->field154 * FX_SinCosTable_[idx]) >> 12);
            pos.y = mapObject->field0.mPos.y + mapObject->mPrm->field158;
            pos.z =
                mapObject->field0.mPos.z + (s32) (((s64) mapObject->mPrm->field154 * FX_SinCosTable_[idx + 1]) >> 12);
        }
        if (i == 0) {
            ThrowItemBombFromPosition(itbomb_20FD428(), &pos, &vel, mapObject->mPrm->field15C);
        } else {
            ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &pos, &vel, mapObject->mPrm->field160);
        }
    }
    StartEffectAtRowHeight(mapObject, 0x2000, 0, 0x3ae, 0x410, 0);
    mobj_emitSfxFromEmitter2(&mapObject->field0, 0x236);
}
