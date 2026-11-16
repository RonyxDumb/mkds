#include "Main/Unknown/code_020da5f0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Course/WaterEfct.h"
#include "Main/Unknown/code_020da414.h"

#include "Main/Unknown/code_020da628.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ebef8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dab98.h"
#include "Main/Unknown/code_020dab9c.h"
#include "Main/Unknown/code_020dabfc.h"
#include "Main/Unknown/code_020dac00.h"
#include "Main/Unknown/code_020dac58.h"
#include "Main/Unknown/code_020dac74.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020dade8.h"
#include "Main/Unknown/code_020dadfc.h"
#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020daf0c.h"

void kuribo_routeIdleStateInit(Kuribo *kuribo) {
    kuribo->fieldC4 = 0x1000u;
    kuribo->fieldC8 = 0x0u;
}

void kuribo_routeIdleStateUpdate(Kuribo *kuribo) {
    if (kuribo->fieldF0 >= 0xa && (kuribo->fieldF0 < 0x14 || kuribo->fieldF0 >= 0x1e)) {
        pw_update(&kuribo->fieldCC);
    }
    pw_calcCurrentPointXYZ(&kuribo->fieldCC, &kuribo->field0.mPos);
    if (kuribo->fieldC4 == 0x1000 && kuribo->fieldC8 == 0) {
        return;
    }
    kuribo->fieldC8 += (s32) (((s64) (0x1000 - kuribo->fieldC4) * 0x200) >> 12);
    kuribo->fieldC8 = ((s64) kuribo->fieldC8 * 0xd99) >> 12;
    kuribo->fieldC4 += kuribo->fieldC8;
    if (kuribo->fieldC4 > 0xfd7 && kuribo->fieldC4 < 0x1029 && kuribo->fieldC8 > -0x29 && kuribo->fieldC8 < 0x29) {
        kuribo->fieldC4 = 0x1000;
        kuribo->fieldC8 = 0;
    }
}

void kuribo_groundRoamIdleStateInit(Kuribo *kuribo) {
    kuribo->fieldC4 = 0x1000u;
    kuribo->fieldC8 = 0x0u;
}

void kuribo_groundRoamIdleStateUpdate(Kuribo *kuribo) {
    u32 surfaceFlags;
    Vec3 probePos;
    Vec3 correction;
    Vec3 surfaceNormal;
    if (kuribo->fieldF0 < 0xa || (kuribo->fieldF0 >= 0x14 && kuribo->fieldF0 < 0x1e)) {
        if (kuribo->fieldF0 == 0 || kuribo->fieldF0 == 0x14) {
            kuribo->field102--;
            if (kuribo->field102 < 0) {
                kuribo->field102 = 3;
                kuribo->field104 = kuribo->field104 == 0;
            }
        }
    }
    kuribo->field0.field10.y -= 0x400;
    kuribo->field0.mPos.y += kuribo->field0.field10.y;
    probePos = kuribo->field0.mPos;
    probePos.y += 0xa000;
    if (col_collide(&probePos, NULL, 0, 0xa000, 8, -2, &correction, &surfaceNormal, NULL, &surfaceFlags, NULL, NULL,
                      NULL, NULL) != 0) {
        VEC_Add(&kuribo->field0.mPos, &correction, &kuribo->field0.mPos);
        kuribo->field0.field10.y = 0;
        if ((surfaceFlags & 0x1e34ef) != 0) {
            qrtn_fromForwardVec(&surfaceNormal, &kuribo->fieldB4);
            kuribo->field0.mFlags &= ~1;
        }
    }
    qrtn_slerp(&kuribo->fieldA4, &kuribo->fieldB4, &kuribo->fieldA4, kuribo->fieldF8);
    if (kuribo->fieldF8 > 0xb4) {
        kuribo->fieldF8 = 0xb4;
    }
}

void kuribo_hitGrowStateInit(Kuribo *kuribo) {
    kuribo->field0.mFlags = (((kuribo->field0.mFlags)) | ((kuribo_sSomeFlag)));
}

void kuribo_hitGrowStateUpdate(Kuribo *kuribo) {
    kuribo->fieldC4 = ((s64) kuribo->fieldC4 * 0x1266) >> 12;
    if (kuribo->fieldC4 > 0x1800) {
        kuribo->field0.mStateMachine.mNextState = 3;
        kuribo->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u32 kuribo_hitShrinkStateInit(u32 value) {
    return value;
}

void kuribo_hitShrinkStateUpdate(Kuribo *kuribo) {
    kuribo->fieldC4 = ((s64) kuribo->fieldC4 * 0xd99) >> 12;
    if (kuribo->fieldC4 < 0x333) {
        kuribo->field0.mStateMachine.mNextState = 4;
        kuribo->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u32 kuribo_deadStateInit(u32 value) {
    return value;
}

void kuribo_deadStateUpdate(Kuribo *kuribo) {
    if (kuribo->fieldFC != 0) {
        if (kuribo->field0.mStateMachine.mStateFrames > 0x12c) {
            kuribo->field0.mStateMachine.mNextState = 5;
            kuribo->field0.mStateMachine.mNextStateRequested = 1;
        }
        return;
    }
    kuribo->field100--;
    if (kuribo->field100 == 0) {
        mobj_setInvisible(&kuribo->field0);
    }
}

void kuribo_reappearStateInit(Kuribo *kuribo) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;
    if ((kuribo->field0.mDistanceSquaredAndFlags & 4) == 0) {
        if (kuribo->field0.mFarDistanceSquared == gSfxParams[2].field20) {
            falloffIndex = 2;
        } else if (kuribo->field0.mFarDistanceSquared == gSfxParams[3].field20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x183;
        soundRequest.mPositionSource = &kuribo->field0.mPos;
        soundRequest.field8 = falloffIndex;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&kuribo->field0.mPos);
        func_0210b7a8(&soundRequest);
    }
    kuribo->field0.mFlags &= ~1;
    kuribo->fieldC8 = 0;
}

void kuribo_reappearStateUpdate(Kuribo *kuribo) {
    kuribo->fieldC8 += (s32) (((s64) (0x1000 - kuribo->fieldC4) * 0x200) >> 12);
    kuribo->fieldC8 = ((s64) kuribo->fieldC8 * 0xd99) >> 12;
    kuribo->fieldC4 += kuribo->fieldC8;
    if (kuribo->field0.mStateMachine.mStateFrames > 0x3c) {
        kuribo->field0.mStateMachine.mNextState = 0;
        kuribo->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void kuribo_handleShroomSpawn(Kuribo *kuribo, Vec3 *hitVector) {
    Vec3 launchDirection;
    ItemObject *itemObject;
    s32 d;
    if (kuribo->field0.mCourseMapRow == NULL || kuribo->field0.mCourseMapRow->field2C != 0) {
        return;
    }
    VEC_Subtract(&kuribo->fieldCC.mFromEntry->mPos, &kuribo->fieldCC.mToEntry->mPos, &launchDirection);
    if ((s64) launchDirection.x * launchDirection.x + (s64) launchDirection.y * launchDirection.y +
            (s64) launchDirection.z * launchDirection.z >=
        0x10) {
        vec_normalize(&launchDirection, &launchDirection);
    }
    {
        Vec3 t = {0, 0, 0};
        t.x = hitVector->x;
        t.z = hitVector->z;
        d = VEC_DotProduct(&launchDirection, &t);
        launchDirection.x = t.x - (s32) (((s64) launchDirection.x * d) >> 12);
        launchDirection.y = t.y - (s32) (((s64) launchDirection.y * d) >> 12);
        launchDirection.z = t.z - (s32) (((s64) launchDirection.z * d) >> 12);
    }
    if ((s64) launchDirection.x * launchDirection.x + (s64) launchDirection.y * launchDirection.y +
            (s64) launchDirection.z * launchDirection.z >=
        0x10) {
        vec_normalize(&launchDirection, &launchDirection);
    }
    itemObject = it_spawnItem(3, 8, &kuribo->field0.mPos, &kuribo_sUpVec);
    if (itemObject == NULL) {
        return;
    }
    itemObject->mScale.x = 0xcd;
    itemObject->mScale.y = 0xcd;
    itemObject->mScale.z = 0xcd;
    d = VEC_Mag(hitVector) + 0x5000;
    itemObject->mVelocity.x = ((s64) launchDirection.x * d) >> 12;
    itemObject->mVelocity.y = ((s64) launchDirection.y * d) >> 12;
    itemObject->mVelocity.z = ((s64) launchDirection.z * d) >> 12;
    itemObject->mVelocity.y += 0xf000;
    VEC_Add(&itemObject->mPos, &itemObject->mVelocity, &itemObject->mPos);
    it_startThrowAnim(itemObject, 0, &kuribo->field0.mPos, hitVector, &kuribo_sUpVec);
}

u32 kuribo_onDriverCollide(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (kuribo->fieldC4 == 0x1000) {
                if (kuribo->fieldC8 == 0) {
                    kuribo->fieldC8 = ((s64) kart->mVelocityLength * 0x52) >> 12;
                }
            }
            break;
        case 1:
            if (kuribo->field0.mStateMachine.mState == 0 || kuribo->field0.mStateMachine.mState == 5 ||
                kuribo->field0.mStateMachine.mState == 1) {
                kuribo->field0.mStateMachine.mNextState = 2;
                kuribo->field0.mStateMachine.mNextStateRequested = 1;
                mobj_driverEmitSfx2(&kart->mSoundSource, 0x185);
                mobj_tryDestroyByDriver(&kuribo->field0, kart);
                kuribo_handleShroomSpawn(kuribo, &kart->mVelocity);
                kuribo->field0.mFlags = kuribo->field0.mFlags | kuribo_sSomeFlag;
            }
            break;
    }
    return *c;
}

u32 kuribo_onItemCollide(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (kuribo->fieldC4 == 0x1000) {
                if (kuribo->fieldC8 == 0) {
                    kuribo->fieldC8 = 0x19a;
                }
            }
            break;
        case 1:
            if (kuribo->field0.mStateMachine.mState == 0 || kuribo->field0.mStateMachine.mState == 5 ||
                kuribo->field0.mStateMachine.mState == 1) {
                kuribo->field0.mStateMachine.mNextState = 2;
                kuribo->field0.mStateMachine.mNextStateRequested = 1;
                it_emitMissionParticles(kart);
                if (kart != NULL) {
                    kuribo_handleShroomSpawn(kuribo, &kart->mSignedTurnedForward);
                }
                kuribo->field0.mFlags = kuribo->field0.mFlags | kuribo_sSomeFlag;
            }
            break;
    }
    return *c;
}

void kuribo_resetRoaming(Kuribo *kuribo) {
    kuribo->fieldF8 = 0x1000;
    kuribo->fieldA4 = data_02158140;
    kuribo->fieldB4 = data_02158150;
    sm_gotoState(&kuribo->field0.mStateMachine, 1);
    kuribo->field0.field10.x = 0;
    kuribo->field0.field10.y = 0;
    kuribo->field0.field10.z = 0;
}

#pragma thumb on

void kuribo_loadModels(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = mobj_getMapObjFile(aKuribo_nsbmd);
    nsbtpFile = mobj_getMapObjFile(aKuribo_nsbtp);
    bbm_createFromNsbmd((NsbmdModel **) (((u32 *) &kuribo_sModel)), nsbmdFile, nsbtpFile, 0);
    bbm_setDefaultMatParams(kuribo_sModel);
}

#pragma thumb off
