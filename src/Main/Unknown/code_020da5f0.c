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
    kuribo->mUnk_c4 = 0x1000u;
    kuribo->mUnk_c8 = 0x0u;
}

void kuribo_routeIdleStateUpdate(Kuribo *kuribo) {
    if (kuribo->mUnk_f0 >= 0xa && (kuribo->mUnk_f0 < 0x14 || kuribo->mUnk_f0 >= 0x1e)) {
        pw_update(&kuribo->mUnk_cc);
    }
    pw_calcCurrentPointXYZ(&kuribo->mUnk_cc, &kuribo->mUnk_00.mPos);
    if (kuribo->mUnk_c4 == 0x1000 && kuribo->mUnk_c8 == 0) {
        return;
    }
    kuribo->mUnk_c8 += (s32) (((s64) (0x1000 - kuribo->mUnk_c4) * 0x200) >> 12);
    kuribo->mUnk_c8 = ((s64) kuribo->mUnk_c8 * 0xd99) >> 12;
    kuribo->mUnk_c4 += kuribo->mUnk_c8;
    if (kuribo->mUnk_c4 > 0xfd7 && kuribo->mUnk_c4 < 0x1029 && kuribo->mUnk_c8 > -0x29 && kuribo->mUnk_c8 < 0x29) {
        kuribo->mUnk_c4 = 0x1000;
        kuribo->mUnk_c8 = 0;
    }
}

void kuribo_groundRoamIdleStateInit(Kuribo *kuribo) {
    kuribo->mUnk_c4 = 0x1000u;
    kuribo->mUnk_c8 = 0x0u;
}

void kuribo_groundRoamIdleStateUpdate(Kuribo *kuribo) {
    u32 surfaceFlags;
    Vec3 probePos;
    Vec3 correction;
    Vec3 surfaceNormal;
    if (kuribo->mUnk_f0 < 0xa || (kuribo->mUnk_f0 >= 0x14 && kuribo->mUnk_f0 < 0x1e)) {
        if (kuribo->mUnk_f0 == 0 || kuribo->mUnk_f0 == 0x14) {
            kuribo->mUnk_102--;
            if (kuribo->mUnk_102 < 0) {
                kuribo->mUnk_102 = 3;
                kuribo->mUnk_104 = kuribo->mUnk_104 == 0;
            }
        }
    }
    kuribo->mUnk_00.mUnk_10.y -= 0x400;
    kuribo->mUnk_00.mPos.y += kuribo->mUnk_00.mUnk_10.y;
    probePos = kuribo->mUnk_00.mPos;
    probePos.y += 0xa000;
    if (col_collide(&probePos, NULL, 0, 0xa000, 8, -2, &correction, &surfaceNormal, NULL, &surfaceFlags, NULL, NULL,
                      NULL, NULL) != 0) {
        VEC_Add(&kuribo->mUnk_00.mPos, &correction, &kuribo->mUnk_00.mPos);
        kuribo->mUnk_00.mUnk_10.y = 0;
        if ((surfaceFlags & 0x1e34ef) != 0) {
            qrtn_fromForwardVec(&surfaceNormal, &kuribo->mUnk_b4);
            kuribo->mUnk_00.mFlags &= ~1;
        }
    }
    qrtn_slerp(&kuribo->mUnk_a4, &kuribo->mUnk_b4, &kuribo->mUnk_a4, kuribo->mUnk_f8);
    if (kuribo->mUnk_f8 > 0xb4) {
        kuribo->mUnk_f8 = 0xb4;
    }
}

void kuribo_hitGrowStateInit(Kuribo *kuribo) {
    kuribo->mUnk_00.mFlags = (((kuribo->mUnk_00.mFlags)) | ((kuribo_sSomeFlag)));
}

void kuribo_hitGrowStateUpdate(Kuribo *kuribo) {
    kuribo->mUnk_c4 = ((s64) kuribo->mUnk_c4 * 0x1266) >> 12;
    if (kuribo->mUnk_c4 > 0x1800) {
        kuribo->mUnk_00.mStateMachine.mNextState = 3;
        kuribo->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 kuribo_hitShrinkStateInit(u32 value) {
    return value;
}

void kuribo_hitShrinkStateUpdate(Kuribo *kuribo) {
    kuribo->mUnk_c4 = ((s64) kuribo->mUnk_c4 * 0xd99) >> 12;
    if (kuribo->mUnk_c4 < 0x333) {
        kuribo->mUnk_00.mStateMachine.mNextState = 4;
        kuribo->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 kuribo_deadStateInit(u32 value) {
    return value;
}

void kuribo_deadStateUpdate(Kuribo *kuribo) {
    if (kuribo->mUnk_fc != 0) {
        if (kuribo->mUnk_00.mStateMachine.mStateFrames > 0x12c) {
            kuribo->mUnk_00.mStateMachine.mNextState = 5;
            kuribo->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
        return;
    }
    kuribo->mUnk_100--;
    if (kuribo->mUnk_100 == 0) {
        mobj_setInvisible(&kuribo->mUnk_00);
    }
}

void kuribo_reappearStateInit(Kuribo *kuribo) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;
    if ((kuribo->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
        if (kuribo->mUnk_00.mFarDistanceSquared == gSfxParams[2].mUnk_20) {
            falloffIndex = 2;
        } else if (kuribo->mUnk_00.mFarDistanceSquared == gSfxParams[3].mUnk_20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x183;
        soundRequest.mPositionSource = &kuribo->mUnk_00.mPos;
        soundRequest.mUnk_08 = falloffIndex;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&kuribo->mUnk_00.mPos);
        func_0210b7a8(&soundRequest);
    }
    kuribo->mUnk_00.mFlags &= ~1;
    kuribo->mUnk_c8 = 0;
}

void kuribo_reappearStateUpdate(Kuribo *kuribo) {
    kuribo->mUnk_c8 += (s32) (((s64) (0x1000 - kuribo->mUnk_c4) * 0x200) >> 12);
    kuribo->mUnk_c8 = ((s64) kuribo->mUnk_c8 * 0xd99) >> 12;
    kuribo->mUnk_c4 += kuribo->mUnk_c8;
    if (kuribo->mUnk_00.mStateMachine.mStateFrames > 0x3c) {
        kuribo->mUnk_00.mStateMachine.mNextState = 0;
        kuribo->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void kuribo_handleShroomSpawn(Kuribo *kuribo, Vec3 *hitVector) {
    Vec3 launchDirection;
    ItemObject *itemObject;
    s32 d;
    if (kuribo->mUnk_00.mCourseMapRow == NULL || kuribo->mUnk_00.mCourseMapRow->mUnk_2c != 0) {
        return;
    }
    VEC_Subtract(&kuribo->mUnk_cc.mFromEntry->mPos, &kuribo->mUnk_cc.mToEntry->mPos, &launchDirection);
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
    itemObject = it_spawnItem(3, 8, &kuribo->mUnk_00.mPos, &kuribo_sUpVec);
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
    it_startThrowAnim(itemObject, 0, &kuribo->mUnk_00.mPos, hitVector, &kuribo_sUpVec);
}

u32 kuribo_onDriverCollide(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (kuribo->mUnk_c4 == 0x1000) {
                if (kuribo->mUnk_c8 == 0) {
                    kuribo->mUnk_c8 = ((s64) kart->mVelocityLength * 0x52) >> 12;
                }
            }
            break;
        case 1:
            if (kuribo->mUnk_00.mStateMachine.mState == 0 || kuribo->mUnk_00.mStateMachine.mState == 5 ||
                kuribo->mUnk_00.mStateMachine.mState == 1) {
                kuribo->mUnk_00.mStateMachine.mNextState = 2;
                kuribo->mUnk_00.mStateMachine.mNextStateRequested = 1;
                mobj_driverEmitSfx2(&kart->mSoundSource, 0x185);
                mobj_tryDestroyByDriver(&kuribo->mUnk_00, kart);
                kuribo_handleShroomSpawn(kuribo, &kart->mVelocity);
                kuribo->mUnk_00.mFlags = kuribo->mUnk_00.mFlags | kuribo_sSomeFlag;
            }
            break;
    }
    return *c;
}

u32 kuribo_onItemCollide(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (kuribo->mUnk_c4 == 0x1000) {
                if (kuribo->mUnk_c8 == 0) {
                    kuribo->mUnk_c8 = 0x19a;
                }
            }
            break;
        case 1:
            if (kuribo->mUnk_00.mStateMachine.mState == 0 || kuribo->mUnk_00.mStateMachine.mState == 5 ||
                kuribo->mUnk_00.mStateMachine.mState == 1) {
                kuribo->mUnk_00.mStateMachine.mNextState = 2;
                kuribo->mUnk_00.mStateMachine.mNextStateRequested = 1;
                it_emitMissionParticles(kart);
                if (kart != NULL) {
                    kuribo_handleShroomSpawn(kuribo, &kart->mSignedTurnedForward);
                }
                kuribo->mUnk_00.mFlags = kuribo->mUnk_00.mFlags | kuribo_sSomeFlag;
            }
            break;
    }
    return *c;
}

void kuribo_resetRoaming(Kuribo *kuribo) {
    kuribo->mUnk_f8 = 0x1000;
    kuribo->mUnk_a4 = data_02158140;
    kuribo->mUnk_b4 = data_02158150;
    sm_gotoState(&kuribo->mUnk_00.mStateMachine, 1);
    kuribo->mUnk_00.mUnk_10.x = 0;
    kuribo->mUnk_00.mUnk_10.y = 0;
    kuribo->mUnk_00.mUnk_10.z = 0;
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
