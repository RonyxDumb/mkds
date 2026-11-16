#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020df85c.h" // MapObjectFlagsView

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ebef8.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02046be8.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02012b30.h"
#include "code_02010c84.h"
#include "code_020109c4.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020ec1ec.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec538.h"
#include "01/code_0218155c.h"

const Unk021594e4 data_021594e4 = {
    0, 0, (u32) &wbox_globalLogicInit, 0, (u32) &wbox_update, 0, 0, 0, 0, 0,
};

const Woodbox1DrawList data_0215950c = {
    0, 0, (u32) &wbox_loadModel, 0, (u32) &wbox_render, 0, 1, 0, 0, 0, 0,
};

const Unk02159538 wbox_sCollisionInfo = {
    (u32) &wbox_onDriverCollide,
    (u32) &wbox_onItemCollide,
    4,
    0xa000,
    0xa000,
    0xa000,
    0,
    1,
    1,
    0x168,
    0x169,
    0,
    0,
    0,
    0,
    0,
};

BOOL rdmo_onDriverCollide(Unk020e43a8 *mapObject, void *other, u8 *firstResponse) {
    if (*firstResponse != 1) {
        return FALSE;
    }
    rdmo_20EC6E4(mapObject, other);
    mapObject->mUnk_00.mStateMachine.mNextState = 1;
    mapObject->mUnk_00.mStateMachine.mNextStateRequested = 1;
    return TRUE;
}

BOOL rdmo_onItemCollide(Unk020e43a8 *mapObject, void *other, u8 *firstResponse) {
    if (*firstResponse != 1) {
        return FALSE;
    }
    rdmo_20EC538(mapObject, other);
    mapObject->mUnk_00.mStateMachine.mNextState = 1;
    mapObject->mUnk_00.mStateMachine.mNextStateRequested = 1;
    return TRUE;
}

Unk02159538 *wbox_setupCollision(void) {
    Unk02159538 *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = wbox_sCollisionInfo;
    return kindData;
}

Woodbox1DrawList *wbox_setupRenderPart(void) {
    Woodbox1DrawList *drawList;

    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    data_0217bbec = drawList;
    *drawList = data_0215950c;
    mobj_renderPartSetThisPointer(&data_0217bbec);
    return data_0217bbec;
}

Unk021594e4 *wbox_setupLogicPart(void) {
    Unk021594e4 *updateList;

    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    wbox_sLogicPart = updateList;
    *updateList = data_021594e4;
    mobj_logicPartSetThisPointer(&wbox_sLogicPart);
    return wbox_sLogicPart;
}

void wbox_render(void *a, Unk020e43a8 *woodbox, void *c, u32 maxAlpha) {
    u16 state;
    s32 t;
    Vec3 shadowPos;

    state = woodbox->mUnk_00.mStateMachine.mState;
    woodbox->mUnk_00.mMatrix.mUnk_00[3].x = woodbox->mUnk_00.mPos.x >> 4;
    woodbox->mUnk_00.mMatrix.mUnk_00[3].y = woodbox->mUnk_00.mPos.y >> 4;
    woodbox->mUnk_00.mMatrix.mUnk_00[3].z = woodbox->mUnk_00.mPos.z >> 4;
    model2_renderModel(wbox_sModel, &woodbox->mUnk_00.mMatrix, &woodbox->mUnk_00.mScale, maxAlpha);
    if (state == 0) {
        return;
    }
    t = ((s64) (0x5a000 - woodbox->mUnk_d0) * 0x2e) >> 12;
    shadowPos.x = woodbox->mUnk_00.mPos.x;
    shadowPos.z = woodbox->mUnk_00.mPos.z;
    shadowPos.y = woodbox->mUnk_0b4 - (s32) (((s64) woodbox->mUnk_0bc * woodbox->mUnk_cc) >> 12) -
                  (s32) (((s64) woodbox->mUnk_0c4 * woodbox->mUnk_d4) >> 12);
    VEC_MultAdd(-woodbox->mUnk_00.mExtent.x, (const Vec3 *) &woodbox->mUnk_0bc, &shadowPos, &shadowPos);
    oshd_setPosition((ShadowMatrix *) &woodbox->mUnk_114, &shadowPos);
    oshd_renderMat((ShadowMatrix *) &woodbox->mUnk_114, &t, 0, maxAlpha);
}

void wbox_update(u32 unused, u32 woodbox) {
    u32 stateMachineAddress;
    u32 woodboxAddress = woodbox;
    u32 value12;
    stateMachineAddress = (woodboxAddress) + (0x80u);
    sm_execute((void *) stateMachineAddress);
}

void wbox_state0Init(Unk020ec194 *woodbox) {
    Vec3 rotation;
    Vec3 *velocity;

    velocity = &woodbox->mUnk_010;
    velocity->x = 0;
    velocity->y = 0;
    velocity->z = 0;
    woodbox->mUnk_004 = woodbox->mUnk_0b0;
    qrtn_20D7A3C(&woodbox->mUnk_0bc, woodbox->mUnk_0c8, &rotation);
    qtrn_toMtx33(&woodbox->mUnk_028, &rotation);
}

// With a chance given by the box, starts one item object that moves off with the given velocity.
void wbox_trySpawnItem(Woodbox1 *woodbox, Vec3 *velocity) {
    s32 spawnDistance;
    Vec3 direction;
    Vec3 sideDirection;
    RandomState64 *raceRandom;
    ItemObject *itemObject;
    s32 itemIndex;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        mrcnt_notifyMObjDamage(woodbox->mUnk_000.mKind);
    }
    woodbox->mUnk_000.mFlags |= data_021594d8;
    if (gRaceMultiConfig->mMode == 5) {
        return;
    }
    raceRandom = mobj_getSafeRng();
    raceRandom->mValue = raceRandom->mMultiplier * raceRandom->mValue + raceRandom->mIncrement;
    if (woodbox->mItemChancePercent <= (u16) (((u64) (u32) (raceRandom->mValue >> 32) * 100) >> 32)) {
        return;
    }
    if (woodbox->mItemRowHandle == 0) {
        return;
    }
    itemIndex = PickItem(0, woodbox->mItemRowHandle, 1, 1, 0, 0x12);
    itemObject =
        it_spawnItem(it_sItemConfigs[itemIndex].mObjectKind, 8, &woodbox->mUnk_000.mPos, &woodbox->mGroundUp);
    if (itemObject == NULL) {
        return;
    }
    if ((s64) velocity->x * velocity->x + (s64) velocity->y * velocity->y + (s64) velocity->z * velocity->z >= 16) {
        vec_normalize(velocity, &direction);
    }
    vec_crossProduct(&woodbox->mGroundUp, &direction, &sideDirection);
    raceRandom = mobj_getSafeRng();
    raceRandom->mValue = raceRandom->mMultiplier * raceRandom->mValue + raceRandom->mIncrement;
    spawnDistance =
        ((s64) (s32) ((u32) (((u64) (u32) (raceRandom->mValue >> 32) * 0x1800) >> 32) + 0x119a) << 12) >> 12;
    raceRandom = mobj_getSafeRng();
    raceRandom->mValue = raceRandom->mMultiplier * raceRandom->mValue + raceRandom->mIncrement;
    itemObject->mVelocity = *velocity;
    VEC_MultAdd(spawnDistance, &direction, &woodbox->mUnk_000.mPos, &itemObject->mPos);
    VEC_MultAdd(0, &sideDirection, &itemObject->mPos, &itemObject->mPos);
    itemObject->mScale.x = 0xcd;
    itemObject->mScale.y = 0xcd;
    itemObject->mScale.z = 0xcd;
    it_startThrowAnim(itemObject, 2, &woodbox->mUnk_000.mPos, velocity, &woodbox->mGroundUp);
}

void wbox_state1Init(MapObjectFlagsView *woodbox) {
    woodbox->mUnk_02 |= data_021594d8;
    woodbox->mUnk_02 |= data_021594dc;
    woodbox->mUnk_02 |= data_021594e0;
}

#pragma thumb off

void wbox_state1Update(Woodbox1 *woodbox) {
    if (woodbox->mUnk_000.mStateMachine.mStateFrames < 900) {
        return;
    }
    if (woodbox->mUnk_000.mCourseMapRow->mUnk_2c != 0) {
        return;
    }
    if (data_0217bbf0 == NULL) {
        data_0217bbf0 = woodbox;
        woodbox->mUnk_000.mStateMachine.mNextState = 2;
        woodbox->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

BOOL wbox_20EBC2C(Woodbox1 *woodbox) {
    Vec3 v;
    Vec3 *axis;
    s32 dot;
    s32 extent;

    v = woodbox->mUnk_000.mPos;
    axis = &woodbox->mUnk_000.mMatrix.mUnk_00[0];
    extent = woodbox->mUnk_000.mExtent.x;
    dot = vec_dotProduct(&woodbox->mGroundUp, axis);
    if (dot > 0) {
        VEC_MultAdd(-extent, axis, &v, &v);
    } else {
        VEC_MultAdd(extent, axis, &v, &v);
    }
    axis = &woodbox->mUnk_000.mMatrix.mUnk_00[1];
    extent = woodbox->mUnk_000.mExtent.x;
    dot = vec_dotProduct(&woodbox->mGroundUp, axis);
    if (dot > 0) {
        VEC_MultAdd(-extent, axis, &v, &v);
    } else {
        VEC_MultAdd(extent, axis, &v, &v);
    }
    axis = &woodbox->mUnk_000.mMatrix.mUnk_00[2];
    extent = woodbox->mUnk_000.mExtent.x;
    dot = vec_dotProduct(&woodbox->mGroundUp, axis);
    if (dot > 0) {
        VEC_MultAdd(-extent, axis, &v, &v);
    } else {
        VEC_MultAdd(extent, axis, &v, &v);
    }
    VEC_Subtract(&v, &woodbox->mBasePos, &v);
    v.y = v.y + woodbox->mUnk_000.mExtent.x;
    dot = -vec_dotProduct(&v, &woodbox->mGroundUp);
    if (dot > 0 && woodbox->mUnk_000.mUnk_10.y < 0) {
        woodbox->mPosOffset.y = woodbox->mPosOffset.y + dot;
        woodbox->mUnk_000.mUnk_10.y = ((s64) -woodbox->mUnk_000.mUnk_10.y * 0x400) >> 12;
        woodbox->mTiltOffsetPerFrame.x = ((s64) woodbox->mTiltOffset.x * -0x266) >> 12;
        woodbox->mTiltOffsetPerFrame.y = ((s64) woodbox->mTiltOffset.y * -0x266) >> 12;
        woodbox->mTiltOffsetPerFrame.z = ((s64) woodbox->mTiltOffset.z * -0x266) >> 12;
        woodbox->mUnk_000.mUnk_10.x = ((s64) woodbox->mTiltOffsetPerFrame.x * 0x9000) >> 12;
        woodbox->mUnk_000.mUnk_10.z = ((s64) woodbox->mTiltOffsetPerFrame.z * 0x9000) >> 12;
        return TRUE;
    }
    return FALSE;
}

void wbox_state2Init(Woodbox1 *woodbox) {
    Vec3 rotation;
    u32 frameCount;
    u16 headingOffset;

    frameCount = race_getFrameCounter();
    woodbox->mUnk_000.mFlags &= ~1;
    woodbox->mUnk_000.mFlags &= ~2;
    woodbox->mUnk_000.mFlags &= ~8;
    woodbox->mUnk_000.mAlpha = 1;
    woodbox->mTiltOffset = *((frameCount & 1) ? &woodbox->mUnk_0f4 : &woodbox->mUnk_100);
    if (frameCount & 2) {
        headingOffset = woodbox->mUnk_10c;
    } else {
        headingOffset = 0x10000 - woodbox->mHeadingAngleOffset;
    }
    woodbox->mHeadingAngleOffset = headingOffset;
    woodbox->mTiltOffsetPerFrame.x = 0;
    woodbox->mTiltOffsetPerFrame.y = 0;
    woodbox->mTiltOffsetPerFrame.z = 0;
    woodbox->mPosOffset.x = ((s64) woodbox->mTiltOffset.x * 0x14000) >> 12;
    woodbox->mPosOffset.y = 0x3c000;
    woodbox->mPosOffset.z = ((s64) woodbox->mTiltOffset.z * 0x14000) >> 12;
    woodbox->mUnk_000.mUnk_10.x = 0;
    woodbox->mUnk_000.mUnk_10.y = 0;
    woodbox->mUnk_000.mUnk_10.z = 0;
    VEC_Add(&woodbox->mGroundUp, &woodbox->mTiltOffset, &woodbox->mTiltedUp);
    woodbox->mMatrixHeadingAngle = woodbox->mHeadingAngle + woodbox->mHeadingAngleOffset;
    qrtn_20D7A3C(&woodbox->mTiltedUp, woodbox->mMatrixHeadingAngle, &rotation);
    qtrn_toMtx33(&woodbox->mUnk_000.mMatrix, &rotation);
}

void wbox_state2Update(Woodbox1 *woodbox) {
    if (wbox_20EBC2C(woodbox) != FALSE) {
        woodbox->mUnk_000.mStateMachine.mNextState = 3;
        woodbox->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
    woodbox->mUnk_000.mUnk_10.y -= 0x1ec;
    woodbox->mPosOffset.y = woodbox->mPosOffset.y + woodbox->mUnk_000.mUnk_10.y;
    VEC_Add(&woodbox->mBasePos, &woodbox->mPosOffset, &woodbox->mUnk_000.mPos);
}

void wbox_state3Update(Woodbox1 *woodbox) {
    Vec3 rotation;
    s32 headingOffset;

    wbox_20EBC2C(woodbox);
    woodbox->mPosOffset.x -= (s32) (((s64) woodbox->mPosOffset.x * 164) >> 12);
    woodbox->mPosOffset.z -= (s32) (((s64) woodbox->mPosOffset.z * 164) >> 12);
    VEC_Add(&woodbox->mTiltOffset, &woodbox->mTiltOffsetPerFrame, &woodbox->mTiltOffset);
    headingOffset = woodbox->mHeadingAngleOffset;
    if ((u32) headingOffset < 0x8000) {
        woodbox->mHeadingAngleOffset = headingOffset - (s32) (((s64) headingOffset * 246) >> 12);
    } else {
        woodbox->mHeadingAngleOffset = headingOffset + (s32) (((s64) (0x10000 - headingOffset) * 246) >> 12);
    }
    woodbox->mUnk_000.mUnk_10.y -= 655;
    VEC_Add(&woodbox->mPosOffset, &woodbox->mUnk_000.mUnk_10, &woodbox->mPosOffset);
    VEC_Add(&woodbox->mBasePos, &woodbox->mPosOffset, &woodbox->mUnk_000.mPos);
    VEC_Add(&woodbox->mGroundUp, &woodbox->mTiltOffset, &woodbox->mTiltedUp);
    if ((s64) woodbox->mTiltedUp.x * woodbox->mTiltedUp.x + (s64) woodbox->mTiltedUp.y * woodbox->mTiltedUp.y +
            (s64) woodbox->mTiltedUp.z * woodbox->mTiltedUp.z >=
        16) {
        vec_normalize(&woodbox->mTiltedUp, &woodbox->mTiltedUp);
    }
    woodbox->mMatrixHeadingAngle = woodbox->mHeadingAngle + woodbox->mHeadingAngleOffset;
    qrtn_20D7A3C(&woodbox->mTiltedUp, woodbox->mMatrixHeadingAngle, &rotation);
    qtrn_toMtx33(&woodbox->mUnk_000.mMatrix, &rotation);
    if (woodbox->mUnk_000.mStateMachine.mStateFrames >= 90) {
        data_0217bbf0 = NULL;
        woodbox->mUnk_000.mStateMachine.mNextState = 0;
        woodbox->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

u32 wbox_onDriverCollide(Woodbox1 *woodbox, Unk020eb498 *kart, u8 *firstResponse, u8 *response) {
    if (*firstResponse == 3) {
        if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
            if (kart->mUnk_29c == 1 || kart->mUnk_2a4 > 0x3000) {
                wbox_trySpawnItem(woodbox, &kart->mUnk_0a4);
                if (data_0217bbf0 == woodbox) {
                    data_0217bbf0 = NULL;
                }
                woodbox->mUnk_000.mStateMachine.mNextState = 1;
                woodbox->mUnk_000.mStateMachine.mNextStateRequested = 1;
                mobj_driverEmitSfx2(kart, 0x167);
                woodbox->mUnk_000.mDistanceSquaredAndFlags |= *(u32 *) data_021594d4;
                mobj_tryDestroyByDriver(&woodbox->mUnk_000, (Kart *) kart);
                if ((woodbox->mUnk_000.mDistanceSquaredAndFlags & 3) == 0) {
                    if (*response == 0) {
                        ptcm_208B498(0x31, &woodbox->mUnk_000.mPos, kart->mUnk_074, 0x1000);
                        ptcm_208B498(0x32, &woodbox->mUnk_000.mPos, kart->mUnk_074, 0x1000);
                    } else {
                        ptcm_createEmitter(0x31, &woodbox->mUnk_000.mPos);
                        ptcm_createEmitter(0x32, &woodbox->mUnk_000.mPos);
                    }
                }
            }
        }
    }
    return *response;
}

u32 wbox_onItemCollide(Woodbox1 *woodbox, Unk020eb498 *itemObject, u8 *firstResponse, u8 *response) {
    u32 firstResponseMinusOne;

    firstResponseMinusOne = *firstResponse - 1;
    if (firstResponseMinusOne <= 1) {
        wbox_trySpawnItem(woodbox, &itemObject->mUnk_05c);
        if (data_0217bbf0 == woodbox) {
            data_0217bbf0 = NULL;
        }
        woodbox->mUnk_000.mStateMachine.mNextState = 1;
        woodbox->mUnk_000.mStateMachine.mNextStateRequested = 1;
        if ((woodbox->mUnk_000.mDistanceSquaredAndFlags & 3) == 0) {
            ptcm_createEmitter(0x31, &woodbox->mUnk_000.mPos);
            ptcm_createEmitter(0x32, &woodbox->mUnk_000.mPos);
        }
    }
    return *response;
}

#pragma thumb on

void wbox_loadModel(void) {
    model2_createFromNsbmd((void **) &wbox_sModel, mobj_getMapObjFile(aWoodbox1_nsbmd), NULL);
    model_setPolyIdLightFlagsEmi(wbox_sModel, 0x3f, 2, 0x294a);
}

void wbox_globalLogicInit(void) {
    data_0217bbf0 = NULL;
}

void wbox_init(Woodbox1 *woodbox, Unk020eb498 *courseRow) {
    Vec3 rotation;
    s32 length;

    if (col_collide(&woodbox->mUnk_000.mPos, NULL, 0, 0xa000, 8, -2, NULL, &woodbox->mGroundUp, NULL, NULL, NULL,
                      NULL, NULL, NULL) == 0) {
        woodbox->mGroundUp = data_0216c3d8;
    }
    woodbox->mUnk_000.mPos.y = woodbox->mUnk_000.mPos.y + woodbox->mUnk_000.mExtent.x;
    woodbox->mBasePos = woodbox->mUnk_000.mPos;
    woodbox->mUnk_000.mUnk_10.x = 0;
    woodbox->mUnk_000.mUnk_10.y = 0;
    woodbox->mUnk_000.mUnk_10.z = 0;
    woodbox->mHeadingAngle = (((s64) courseRow->mUnk_010 * 0xB60B60B60BLL) + 0x80000000000LL) >> 44;
    qrtn_20D7A3C(&woodbox->mGroundUp, woodbox->mHeadingAngle, &rotation);
    qtrn_toMtx33(&woodbox->mUnk_000.mMatrix, &rotation);
    woodbox->mUnk_0f4.x = -woodbox->mGroundUp.x;
    woodbox->mUnk_0f4.y = 0;
    woodbox->mUnk_0f4.z = -woodbox->mGroundUp.z;
    if ((s64) woodbox->mUnk_0f4.x * woodbox->mUnk_0f4.x + (s64) woodbox->mUnk_0f4.y * woodbox->mUnk_0f4.y +
            (s64) woodbox->mUnk_0f4.z * woodbox->mUnk_0f4.z <
        16) {
        length = 0;
    } else {
        length = vec_normalize(&woodbox->mUnk_0f4, &woodbox->mUnk_0f4);
    }
    if (length == 0) {
        woodbox->mUnk_0f4.x = -woodbox->mUnk_000.mMatrix.mUnk_00[2].x;
        woodbox->mUnk_0f4.z = -woodbox->mUnk_000.mMatrix.mUnk_00[2].z;
    }
    vec_rotate(&woodbox->mUnk_0f4, 0x0aab, &woodbox->mUnk_100);
    vec_rotate(&woodbox->mUnk_0f4, 0xf555, &woodbox->mUnk_0f4);
    woodbox->mUnk_0f4.x = ((s64) woodbox->mUnk_0f4.x * 0x800) >> 12;
    woodbox->mUnk_0f4.y = ((s64) woodbox->mUnk_0f4.y * 0x800) >> 12;
    woodbox->mUnk_0f4.z = ((s64) woodbox->mUnk_0f4.z * 0x800) >> 12;
    woodbox->mUnk_100.x = ((s64) woodbox->mUnk_100.x * 0x800) >> 12;
    woodbox->mUnk_100.y = ((s64) woodbox->mUnk_100.y * 0x800) >> 12;
    woodbox->mUnk_100.z = ((s64) woodbox->mUnk_100.z * 0x800) >> 12;
    woodbox->mUnk_10c = 0x1555;
    woodbox->mItemRowHandle = courseRow->mUnk_028;
    woodbox->mItemChancePercent = courseRow->mUnk_02a;
    sm_init(&woodbox->mUnk_000.mStateMachine, (UnkFunc *const *) wbox_sStates, 4, woodbox);
    woodbox->mUnk_000.mStateMachine.mNextState = 0;
    woodbox->mUnk_000.mStateMachine.mNextStateRequested = 1;
    oshd_setParams(&woodbox->mUnk_114, &courseRow->mUnk_000, ((s64) woodbox->mUnk_000.mScale.x * 0x19000) >> 12,
                        13);
}

#pragma thumb off

void col_collidePointSphere(Vec3 *position, Vec3 *center, s32 radius, Vec3 *offset) {
    Vec3 direction;

    VEC_Subtract(position, center, offset);
    if ((s64) offset->x * offset->x + (s64) offset->y * offset->y + (s64) offset->z * offset->z >= 16) {
        vec_normalize(offset, &direction);
    }
    direction.x = ((s64) direction.x * radius) >> 12;
    direction.y = ((s64) direction.y * radius) >> 12;
    direction.z = ((s64) direction.z * radius) >> 12;
    VEC_Subtract(&direction, offset, offset);
}

void col_collidePointSpheroid(Vec3 *position, Vec3 *center, s32 radius, s32 halfHeight, Vec3 *offset) {
    Vec3 direction;
    s32 limit;

    offset->x = position->x - center->x;
    offset->y = 0;
    offset->z = position->z - center->z;
    if ((s64) offset->x * offset->x + (s64) offset->y * offset->y + (s64) offset->z * offset->z >= 16) {
        vec_normalize(offset, &direction);
    }
    offset->x = (s32) (((s64) direction.x * radius) >> 12) - offset->x;
    offset->z = (s32) (((s64) direction.z * radius) >> 12) - offset->z;
    offset->y = position->y - center->y;
    if (offset->y > 0) {
        offset->y = halfHeight - offset->y;
    } else {
        offset->y = -(halfHeight + offset->y);
    }
    if ((s64) offset->x * offset->x + (s64) offset->z * offset->z > (s64) offset->y * offset->y) {
        limit = offset->y;
        if (limit <= 0) {
            limit = -limit;
        }
        if (offset->x > limit) {
            offset->x = limit;
        } else if (offset->x < -limit) {
            offset->x = -limit;
        }
        if (offset->z > limit) {
            offset->z = limit;
        } else if (offset->z < -limit) {
            offset->z = -limit;
        }
    }
    offset->y = 0;
}

s32 col_collideSphereBox(Vec3 *sphereCenter, Vec3 *boxCenter, Vec3 *axes, Vec3 *halfSizesPositive,
                                 Vec3 *halfSizesNegative, s32 radius, Vec3 *pushOut) {
    Vec3 delta;
    s32 overlapY;
    Vec3 *axisY;
    s32 distanceX;
    s32 distanceY;
    s32 distanceZ;
    s32 overlapX;
    s32 overlapZ;
    Vec3 *axisZ;

    axisY = &axes[1];
    axisZ = &axes[2];
    VEC_Subtract(sphereCenter, boxCenter, &delta);
    distanceX = vec_dotProduct(&delta, axes);
    if (distanceX >= halfSizesPositive->x + radius || distanceX <= -(halfSizesNegative->x + radius)) {
        return 0;
    }
    if (distanceX > 0) {
        overlapX = (halfSizesPositive->x + radius) - distanceX;
    } else {
        overlapX = distanceX + (halfSizesNegative->x + radius);
    }
    distanceY = vec_dotProduct(&delta, axisY);
    if (distanceY >= halfSizesPositive->y + radius || distanceY <= -(halfSizesNegative->y + radius)) {
        return 0;
    }
    if (distanceY > 0) {
        overlapY = halfSizesPositive->y + radius;
        overlapY -= distanceY;
    } else {
        overlapY = distanceY + (halfSizesNegative->y + radius);
    }
    distanceZ = vec_dotProduct(&delta, axisZ);
    if (distanceZ >= halfSizesPositive->z + radius || distanceZ <= -(halfSizesNegative->z + radius)) {
        return 0;
    }
    if (distanceZ > 0) {
        overlapZ = (halfSizesPositive->z + radius) - distanceZ;
    } else {
        overlapZ = distanceZ + (halfSizesNegative->z + radius);
    }
    if (overlapZ < overlapX) {
        if (overlapY < overlapZ && distanceY > 0) {
            if (pushOut != NULL) {
                pushOut->x = ((s64) axisY->x * overlapY) >> 12;
                pushOut->y = ((s64) axisY->y * overlapY) >> 12;
                pushOut->z = ((s64) axisY->z * overlapY) >> 12;
            }
            return 1;
        }
        if (pushOut != NULL) {
            if (distanceZ <= 0) {
                overlapZ = -overlapZ;
            }
            pushOut->x = ((s64) axisZ->x * overlapZ) >> 12;
            pushOut->y = ((s64) axisZ->y * overlapZ) >> 12;
            pushOut->z = ((s64) axisZ->z * overlapZ) >> 12;
            pushOut->y = 0;
        }
        return 4;
    }
    if (overlapY < overlapX && distanceY > 0) {
        if (pushOut != NULL) {
            pushOut->x = ((s64) axisY->x * overlapY) >> 12;
            pushOut->y = ((s64) axisY->y * overlapY) >> 12;
            pushOut->z = ((s64) axisY->z * overlapY) >> 12;
        }
        return 1;
    }
    if (pushOut != NULL) {
        if (distanceX <= 0) {
            overlapX = -overlapX;
        }
        pushOut->x = ((s64) axes->x * overlapX) >> 12;
        pushOut->y = ((s64) axes->y * overlapX) >> 12;
        pushOut->z = ((s64) axes->z * overlapX) >> 12;
        pushOut->y = 0;
    }
    return 3;
}

s32 col_collideSphereCylinder(Vec3 *sphereCenter, Vec3 *cylinderCenter, Vec3 *axes, s32 cylinderRadius,
                                      s32 halfHeightPositive, s32 halfHeightNegative, s32 sphereRadius, Vec3 *pushOut) {
    Vec3 delta;
    Vec3 local;
    s32 overlapY;
    s32 horizontalDistance;
    s32 overlapRadial;
    Vec3 *axisY;
    Vec3 *axisZ;

    axisY = &axes[1];
    axisZ = &axes[2];

    VEC_Subtract(sphereCenter, cylinderCenter, &delta);
    local.y = vec_dotProduct(&delta, axisY);
    if (local.y >= halfHeightPositive + sphereRadius || local.y <= -(halfHeightNegative + sphereRadius)) {
        return 0;
    }
    if (local.y > 0) {
        overlapY = (halfHeightPositive + sphereRadius) - local.y;
    } else {
        overlapY = local.y + (halfHeightNegative + sphereRadius);
    }
    local.x = vec_dotProduct(&delta, axes);
    local.y = 0;
    local.z = vec_dotProduct(&delta, axisZ);
    horizontalDistance = VEC_Mag(&local);
    if (horizontalDistance >= cylinderRadius + sphereRadius) {
        return 0;
    }
    overlapRadial = (cylinderRadius + sphereRadius) - horizontalDistance;
    if (overlapY < overlapRadial && local.y > 0) {
        if (pushOut != NULL) {
            pushOut->x = ((s64) axisY->x * overlapY) >> 12;
            pushOut->y = ((s64) axisY->y * overlapY) >> 12;
            pushOut->z = ((s64) axisY->z * overlapY) >> 12;
        }
        return 1;
    }
    if (pushOut != NULL) {
        Vec3 w = {0};

        if ((s64) local.x * local.x + (s64) local.y * local.y + (s64) local.z * local.z >= 16) {
            vec_normalize(&local, &w);
        }
        w.x = ((s64) w.x * overlapRadial) >> 12;
        w.y = 0;
        w.z = ((s64) w.z * overlapRadial) >> 12;
        pushOut->x = (s32) (((s64) axes->x * w.x) >> 12) + (s32) (((s64) axisZ->x * w.z) >> 12);
        pushOut->y = (s32) (((s64) axes->y * w.x) >> 12) + (s32) (((s64) axisZ->y * w.z) >> 12);
        pushOut->z = (s32) (((s64) axes->z * w.x) >> 12) + (s32) (((s64) axisZ->z * w.z) >> 12);
    }
    return 2;
}

void func_020eacc0(Vec3 *direction, s32 blendFactor, Vec3 *target, Vec3 *result) {
    Vec3 scaled;
    s32 negatedDot;
    s32 blend;
    s32 remaining;
    s32 blendProduct;
    s32 directionScale;
    s32 extra;

    negatedDot = -vec_dotProduct(direction, target);
    blend = ((s64) (0x1000 - negatedDot) * blendFactor) >> 12;
    if (blend > 0x1000) {
        blend = 0x1000;
    }
    remaining = 0x1000 - blend;
    blendProduct = ((s64) blend * remaining) >> 12;
    extra = ((s64) (negatedDot + 0x1000) * (blendProduct >> 1)) >> 12;
    directionScale = remaining + extra;
    scaled.x = ((s64) direction->x * directionScale) >> 12;
    scaled.y = ((s64) direction->y * directionScale) >> 12;
    scaled.z = ((s64) direction->z * directionScale) >> 12;
    VEC_MultAdd(blend + extra, target, &scaled, result);
}

void func_020eac20(Vec3 *direction, s32 blendFactor) {
    s32 t;
    s32 n;
    s32 remaining;
    s32 blendProduct;
    s32 extra;
    s32 directionScale;

    n = -direction->y;
    t = ((s64) (0x1000 - n) * blendFactor) >> 12;
    if (t > 0x1000) {
        t = 0x1000;
    }
    remaining = 0x1000 - t;
    blendProduct = ((s64) t * remaining) >> 12;
    n += 0x1000;
    extra = ((s64) n * (blendProduct >> 1)) >> 12;
    directionScale = remaining + extra;
    t = t + extra;
    direction->x = ((s64) direction->x * directionScale) >> 12;
    direction->y = ((s64) direction->y * directionScale) >> 12;
    direction->z = ((s64) direction->z * directionScale) >> 12;
    direction->y += t;
}

void BounceVelocityOffSurface(Vec3 *velocity, Vec3 *surfaceNormal, s32 tangentScale, s32 bounceScale,
                              s32 minNormalSpeed, Vec3 *result) {
    Vec3 normal;
    Vec3 normalPart;
    s32 normalSpeed;
    s32 negatedBounce;
    s32 length;

    normal = *surfaceNormal;
    if (normal.y > 0) {
        normal.y = 0;
        length = 0;
        if ((s64) normal.x * normal.x + (s64) normal.y * normal.y + (s64) normal.z * normal.z >= 16) {
            length = vec_normalize(&normal, &normal);
        }
        if (length == 0) {
            *result = *velocity;
            return;
        }
    }
    normalSpeed = VEC_DotProduct(&normal, velocity);
    normalPart.x = ((s64) normal.x * normalSpeed) >> 12;
    normalPart.y = ((s64) normal.y * normalSpeed) >> 12;
    normalPart.z = ((s64) normal.z * normalSpeed) >> 12;
    result->x = velocity->x - normalPart.x;
    result->y = velocity->y - normalPart.y;
    result->z = velocity->z - normalPart.z;
    negatedBounce = -bounceScale;
    result->x = ((s64) result->x * tangentScale) >> 12;
    result->y = ((s64) result->y * tangentScale) >> 12;
    result->z = ((s64) result->z * tangentScale) >> 12;
    normalPart.x = ((s64) normalPart.x * negatedBounce) >> 12;
    normalPart.y = ((s64) normalPart.y * negatedBounce) >> 12;
    normalPart.z = ((s64) normalPart.z * negatedBounce) >> 12;
    if ((s64) normalPart.x * normalPart.x + (s64) normalPart.z * normalPart.z < (s64) minNormalSpeed * minNormalSpeed) {
        normalPart.x = ((s64) normal.x * minNormalSpeed) >> 12;
        normalPart.y = ((s64) normal.y * minNormalSpeed) >> 12;
        normalPart.z = ((s64) normal.z * minNormalSpeed) >> 12;
    }
    VEC_Add(&normalPart, result, result);
}

void func_020ea94c(Vec3 *velocity, Vec3 *surfaceNormal, s32 tangentScale, s32 bounceScale, s32 minNormalSpeed,
                   Vec3 *result) {
    Vec3 normal;
    s32 length;

    if (surfaceNormal->y <= 0) {
        normal = *surfaceNormal;
        length = 0;
        if ((s64) normal.x * normal.x + (s64) normal.y * normal.y + (s64) normal.z * normal.z >= 16) {
            length = vec_normalize(&normal, &normal);
        }
        if (length == 0) {
            *result = *velocity;
            return;
        }
        BounceVelocityOffSurface(velocity, &normal, tangentScale, bounceScale, minNormalSpeed, result);
    } else {
        BounceVelocityOffSurface(velocity, surfaceNormal, tangentScale, bounceScale, minNormalSpeed, result);
    }
}

void model2_renderModel(Nsbmd *model, void *matrix, void *scale, s32 maxAlpha) {
    void *resMdl;
    s32 modelAlpha;
    s32 polygonId;

    resMdl = model->mResMdl;
    modelAlpha = NNS_G3dMdlGetMdlAlpha(resMdl, 0);
    if (maxAlpha < modelAlpha) {
        polygonId = NNS_G3dMdlGetMdlPolygonID(resMdl, 0);
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, mobj_getCyclicPolygonId());
        NNS_G3dMdlSetMdlAlphaAll(resMdl, maxAlpha);
        model_drawTransformed(model, matrix, scale);
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, polygonId);
        NNS_G3dMdlSetMdlAlphaAll(resMdl, modelAlpha);
    } else {
        model_drawTransformed(model, matrix, scale);
    }
}

void model2_renderShadowModel(ShadowModel *shadow, void *matrix, Vec3 *scale, u32 maxAlpha) {
    u16 savedAlpha;

    savedAlpha = shadow->mAlpha;
    if (maxAlpha < savedAlpha) {
        shadow->mAlpha = maxAlpha;
        DrawShadowWithMatrix(shadow, matrix, scale);
        shadow->mAlpha = savedAlpha;
    } else {
        DrawShadowWithMatrix(shadow, matrix, scale);
    }
}

void func_020ea84c(void) {
    NNS_G3dGeBufferOP_N(0x29, &data_0217bbe8, 1);
}

void DrawNsbmdWithMaxAlpha(Nsbmd *model, s32 maxAlpha) {
    void *resMdl;
    s32 modelAlpha;
    s32 savedAlpha;

    resMdl = model->mResMdl;
    modelAlpha = NNS_G3dMdlGetMdlAlpha(resMdl, 0);
    data_0216c3d4 = modelAlpha;
    if (maxAlpha < modelAlpha) {
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, mobj_getCyclicPolygonId());
        NNS_G3dMdlSetMdlAlphaAll(resMdl, maxAlpha);
    }
    model_render(model);
    savedAlpha = data_0216c3d4;
    if (maxAlpha < savedAlpha) {
        NNS_G3dMdlSetMdlAlphaAll(resMdl, savedAlpha);
    }
    data_0216c3d4 = -1;
}

void DrawNsbmd1Mat1ShpWithMaxAlpha(Nsbmd *model, s32 maxAlpha) {
    void *resMdl;
    s32 modelAlpha;
    s32 savedAlpha;

    resMdl = model->mResMdl;
    modelAlpha = NNS_G3dMdlGetMdlAlpha(resMdl, 0);
    data_0216c3d4 = modelAlpha;
    if (maxAlpha < modelAlpha) {
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, mobj_getCyclicPolygonId());
        NNS_G3dMdlSetMdlAlphaAll(resMdl, maxAlpha);
    }
    NNS_G3dDraw1Mat1Shp(model->mResMdl, 0, 0, 1);
    savedAlpha = data_0216c3d4;
    if (maxAlpha < savedAlpha) {
        NNS_G3dMdlSetMdlAlphaAll(resMdl, savedAlpha);
    }
    data_0216c3d4 = -1;
}

void func_020ea670(Nsbmd *model, s32 maxAlpha) {
    void *resMdl;
    u8 *modelData;
    s32 modelAlpha;
    s32 savedAlpha;

    resMdl = model->mResMdl;
    modelAlpha = NNS_G3dMdlGetMdlAlpha(resMdl, 0);
    data_0216c3d4 = modelAlpha;
    if (maxAlpha < modelAlpha) {
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, mobj_getCyclicPolygonId());
        NNS_G3dMdlSetMdlAlphaAll(resMdl, maxAlpha);
    }
    modelData = (u8 *) resMdl + ((Unk020ea670_08 *) resMdl)->mUnk_008;
    data_0217bbe8 =
        ((Unk020ea670_0c *) (modelData +
                             ((Unk020ea670_08 *) (modelData + ((Unk020ea670_0a *) modelData)->mUnk_00a))->mUnk_008))
            ->mUnk_00c;
    NNS_G3dRenderObjSetCallBack((NNSG3dRenderObj *) model, (NNSG3dSbcCallBackFunc) func_020ea84c, 0, 4, 3);
    model_render(model);
    savedAlpha = data_0216c3d4;
    if (maxAlpha < savedAlpha) {
        NNS_G3dMdlSetMdlAlphaAll(resMdl, savedAlpha);
    }
    data_0216c3d4 = -1;
}
