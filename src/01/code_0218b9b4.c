#include "01/code_0218b9b4.h"
#include "01/code_02188230.h"
#include "01/code_02188cd8.h"

#include "01/code_0218b298.h"
#include "01/code_0218b2dc.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02109000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020f9c6c.h"

const u16 data_ov001_021a65a8 = 0x20;

void func_ov001_0218bee4(Unk02188950 *mapObject) {
    Kart *kart;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(mapObject, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->field184, mapObject->mPrm->field188, func_ov001_0218bfc8);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->field18C, mapObject->mPrm->field188, 0);
    SetSpeedTargetAndPerCall(mapObject, 0, mapObject->mPrm->field144);
    func_ov001_02188a30(mapObject, 0, mapObject->mPrm->field154, mapObject->mPrm->field148, mapObject->mPrm->field14C);
    SetAnglePoint(mapObject, &kart->mPos);
    SetMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->field190, ThrowBombsAndKinoko);
}

void func_ov001_0218bde8(Unk02188950 *mapObject) {
    Kart *kart;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(mapObject, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field134, mapObject->mPrm->field138);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->field13C, mapObject->mPrm->field138, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->field140, mapObject->mPrm->field144);
    func_ov001_02188a30(mapObject, mapObject->mPrm->field150, mapObject->mPrm->field154, mapObject->mPrm->field148,
                        mapObject->mPrm->field14C);
    SetAnglePoint(mapObject, &kart->mPos);
    SetMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field158, func_ov001_0218bee4);
    mapObject->field138 = func_ov001_02187f7c(mapObject);
    func_ov001_0218c5fc(mapObject);
}

void func_ov001_0218bd80(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->field1F8, mapObject->mPrm->field1FC, NULL);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->field200, mapObject->mPrm->field1FC, 0);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->field0.mFlags &= ~0x20;
}

void func_ov001_0218bcc4(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->field1F4;
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field1E0, mapObject->mPrm->field1E4);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->field1E8, mapObject->mPrm->field1E4, 0);
    SetVelocity(mapObject, &velocity);
    func_ov001_02188c90(mapObject);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->field1EC, mapObject->mPrm->field1F0);
    SetCourseCollisionCallback(mapObject, func_ov001_0218bd80);
    mobj_emitSfxFromEmitter2(&mapObject->field0, 0x226);
    mapObject->field0.mFlags |= data_ov001_021a65a8;
}

void func_ov001_0218bc60(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->field1D4, mapObject->mPrm->field1D8, func_ov001_0218bcc4);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->field1DC, mapObject->mPrm->field1D8, 0);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void func_ov001_0218bbac(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field1B4, mapObject->mPrm->field1B8);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->field1BC, mapObject->mPrm->field1B8, 0);
    func_ov001_02188c48(mapObject, mapObject->mPrm->field1C8, mapObject->mPrm->field1CC);
    SetAnglePointAndMoveAnglePoint(mapObject, &mapObject->field0.mCourseMapRow->field0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->field1C0, mapObject->mPrm->field1C4);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field1D0, func_ov001_0218bc60);
    func_ov001_0218c5fc(mapObject);
}

int func_ov001_0218bb74(Unk02188950 *mapObject) {
    if (func_ov001_02188220(mapObject) == 1) {
        mobj_emitSfxFromEmitter(&mapObject->field0, 0x220);
    } else if (func_ov001_02188220(mapObject) == 2) {
        mobj_emitSfxFromEmitter(&mapObject->field0, 0x221);
    }
    return 0;
}

void func_ov001_0218ba48(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, func_ov001_0218bb74);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->fieldDC, mapObject->mPrm->fieldE0);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->fieldE4, mapObject->mPrm->fieldE0, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->fieldE8, mapObject->mPrm->fieldEC);
    func_ov001_02188c48(mapObject, mapObject->mPrm->fieldF0, mapObject->mPrm->fieldF4);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field100, func_ov001_0218c354);
    SetScaleTargetAndPerCall(mapObject, (mapObject->field0.mScale.x + mapObject->mPrm->fieldF8),
                             mapObject->mPrm->fieldFC);
    SetSpeedAndClearTarget(mapObject, 0);
    mobj_setModelNsbtpFrame(mapObject->mNsbmd, func_ov001_02188220(mapObject));
    if (func_ov001_02188220(mapObject) == 0) {
        SetDoubledCollisionAndShadowTargets(mapObject);
        StartEffectAtScaledOffset(mapObject, 0, 0x1800, 0, 0x419, 0);
    } else if (func_ov001_02188220(mapObject) == 1) {
        SetTripledCollisionAndShadowTargets(mapObject);
        StartEffectAtScaledOffset(mapObject, 0, 0x1800, 0, 0x41a, 0);
    }
}

void func_ov001_0218ba34(Unk02188950 *mapObject) {
    func_ov001_0218ba48(mapObject);
    func_ov001_02188230(mapObject);
}

void func_ov001_0218b9b4(Unk02188950 *mapObject) {
    Kart *kart;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field78, mapObject->mPrm->field7C);
    func_ov001_02188c48(mapObject, mapObject->mPrm->field20C, mapObject->mPrm->field210);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->field204, mapObject->mPrm->field208);
}
