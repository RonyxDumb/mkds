#include "Main/Unknown/code_020dbf7c.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02146cbc.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dda38.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8648.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020dc428.h"
#include "Main/Unknown/code_020dc448.h"
#include "Main/Unknown/code_020dc5dc.h"

#pragma thumb off

static inline s64 func_020dc354_inline(const Vec3 *vector) {
    return (s64) vector->x * vector->x + (s64) vector->z * vector->z;
}

void wanwan_state5Update(Wanwan *wanwan) {
    wanwan->field0.field10.x = wanwan->field0.mPos.x;
    wanwan->field0.field10.z = wanwan->field0.mPos.z;
    pwex_update(&wanwan->mFollower);
    pw_calcCurrentPointXZ(&wanwan->mFollower.field0, &wanwan->field0.mPos);
    wanwan->field0.field10.x = wanwan->field0.mPos.x - wanwan->field0.field10.x;
    wanwan->field0.field10.z = wanwan->field0.mPos.z - wanwan->field0.field10.z;
    if (func_020dc354_inline(&wanwan->field0.field10) >= 0x10) {
        qrtn_fromYAngle(
            (u16) ((((s64) FX_Atan2(wanwan->field0.field10.x, wanwan->field0.field10.z) * 0x28be60db9391LL) +
                    0x80000000000LL) >>
                   44),
            &wanwan->fieldD4);
    }
    if (wanwan->field0.mStateMachine.mStateFrames < 0x40) {
        wanwan->fieldEC = wanwan->fieldEC + 0x1c;
    }
}

#pragma thumb on
void wanwan_loadModels(void) {
    model2_createFromNsbmd((void **) &wanwan_sModel, mobj_getMapObjFile("wanwan.nsbmd"), NULL);
    model2_createShadowFromNsbmd((void **) &wanwan_sShadowModel, mobj_getMapObjFile("rock_shadow.nsbmd"), 0x3f);
    model_setPolyIdLightFlagsEmi(wanwan_sModel, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void wanwan_initFixed(Wanwan *wanwan, CourseMapRow *row) {
    wanwan->mCenterPos = row->field0;
    wanwan->fieldF0 = ((s64) wanwan->field0.mScale.y * 0x1e000) >> 12;
    wanwan->fieldF4 = 0xf000 - wanwan->fieldF0;
    wanwan->fieldF8 = (row->field28 * 0x3000) >> 2;
    wanwan->field1DC = row->field2A << 12;
    wanwan->mMaxRadius = row->field28 << 12;
    wanwan->field1FC = wanwan->fieldF8 - (wanwan->fieldF0 << 1);
    wanwan->fieldFC = 0;
    wanwan->fieldB0 = 0;
    wanwan->mChainObject = (Unk020dc474_1d8 *) mobj_createSubObject(&wanwan->field0, 0x197);
    wanwan->fieldAC = wanwan->mCenterPos.y;
    wanwan->mCenterPos.y = wanwan->mCenterPos.y + wanwan->fieldF0;
    sm_init(&wanwan->field0.mStateMachine, wanwan_sStates, 6, wanwan);
    sm_gotoState(&wanwan->field0.mStateMachine, 0);
    wanwan->field200 = wanwan->field0.mMatrix.field0[2];
    wanwan_20DBF7C(wanwan);
    wanwan->field1FA = col_createColEntry(&wanwan->field0.mPos, wanwan->mMaxRadius, 0x400, wanwan);
    wanwan->field0.mFarDistanceSquared = gSfxParams[4].field20;
}
#pragma thumb off

#pragma thumb on
void wanwan_initMoving(Wanwan *wanwan, CourseMapRow *row) {
    wanwan->mCenterPos = row->field0;
    wanwan->fieldF0 = ((s64) wanwan->field0.mScale.y * 0x1e000) >> 12;
    wanwan->fieldF4 = 0xf000 - wanwan->fieldF0;
    wanwan->fieldFC = 1;
    wanwan->fieldB0 = row->field2A;
    wanwan->fieldAC = wanwan->mCenterPos.y;
    wanwan->mCenterPos.y = wanwan->mCenterPos.y + wanwan->fieldF0;
    sm_init(&wanwan->field0.mStateMachine, wanwan_sStates, 6, wanwan);
    sm_gotoState(&wanwan->field0.mStateMachine, 5);
    pwex_initFromObject(&wanwan->mFollower, row, data_02158908, row->field28);
    wanwan_20DBF7C(wanwan);
}
#pragma thumb off

#pragma thumb on
void wanwan_20DBF7C(Wanwan *wanwan) {
    wanwan->field0.mPos = wanwan->mCenterPos;
    wanwan->field0.field10.x = 0;
    wanwan->field0.field10.y = 0;
    wanwan->field0.field10.z = 0;
    wanwan->fieldC4 = data_0216beec;
    qrtn_fromYAngle(
        (u16) ((((s64) FX_Atan2(wanwan->field0.field10.x, wanwan->field0.field10.z) * 0x28be60db9391LL) +
                0x80000000000LL) >>
               44),
        &wanwan->fieldD4);
    qrtn_20D7938(&wanwan->fieldC4, &wanwan->fieldD4, &wanwan->fieldB4);
    qtrn_toMtx33(&wanwan->field0.mMatrix, &wanwan->fieldB4);
    wanwan->fieldE4 = 0;
    if (wanwan->fieldFC == 0) {
        ResetWanwanChainPoints((WanwanChainObject *) wanwan->mChainObject);
    }
    if (wanwan->fieldFC == 0) {
        wanwan->mCurvePoints[0] = &wanwan->mCurvePointValues[0];
        wanwan->mCurvePoints[1] = &wanwan->mCurvePointValues[1];
        wanwan->mCurvePoints[2] = &wanwan->mCurvePointValues[2];
        wanwan->mCurvePoints[3] = &wanwan->mCurvePointValues[3];
        if (gRaceMultiConfig->mRaceKind == RACE_KIND_START_GP) {
            VEC_MultAdd(0xf000, &wanwan->field200, &wanwan->field0.mPos, &wanwan->field0.mPos);
            wanwan->field0.field10.x = ((s64) wanwan->field200.x * 0x400) >> 12;
            wanwan->field0.field10.y = ((s64) wanwan->field200.y * 0x400) >> 12;
            wanwan->field0.field10.z = ((s64) wanwan->field200.z * 0x400) >> 12;
            qrtn_fromYAngle(
                (u16) ((((s64) FX_Atan2(wanwan->field0.field10.x, wanwan->field0.field10.z) * 0x28be60db9391LL) +
                        0x80000000000LL) >>
                       44),
                &wanwan->fieldD4);
            wanwan->field0.mStateMachine.mNextState = 4;
            wanwan->field0.mStateMachine.mNextStateRequested = 1;
        } else {
            wanwan->field0.mStateMachine.mNextState = 0;
            wanwan->field0.mStateMachine.mNextStateRequested = 1;
        }
    }
}
#pragma thumb off

Quaternion data_0216beec = {{0, 0, 0, 0x1000}};
Unk0210b7a8 data_0216bedc = {0x12d, NULL, 2, 0};
// Shared by kinds 0x196 and 0x1a5 (class Wanwan). Only kind 0x196 objects reach states 0, 1, 3 and 4;
// a kind 0x1a5 object starts in state 5 and moves between states 2 and 5.
// wanwan_state4Update is an empty (bx lr) handler, left unnamed.
UnkFunc *wanwan_sStates[] = {wanwan_state0Init, wanwan_state0Update, wanwan_state1Init, wanwan_state1Update,
                            wanwan_state2Init, wanwan_state2Update, wanwan_state3Init, wanwan_state3Update,
                            wanwan_state4Init, wanwan_state4Update,      wanwan_state5Init, wanwan_state5Update};
