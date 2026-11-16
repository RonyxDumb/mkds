#include "Main/Unknown/code_020daf20.h"
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

#pragma thumb off

Unk020dbf2c *dossun_setupConfig(void) {
    Unk020dbf2c *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = data_0215828c;
    return kindData;
}

Unk020dbed0 *dossun_setupRenderPart(void) {
    Unk020dbed0 *drawList;
    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    dossun_sRenderPart = drawList;
    *drawList = data_02158260;
    mobj_renderPartSetThisPointer(&dossun_sRenderPart);
    return dossun_sRenderPart;
}

Unk020dbe74 *dossun_setupLogicPart(void) {
    Unk020dbe74 *updateList;
    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    dossun_sLogicPart = updateList;
    *updateList = data_02158238;
    mobj_logicPartSetThisPointer(&dossun_sLogicPart);
    return dossun_sLogicPart;
}

void dossun_render(void *unused0, Dossun *dossun, void *unused1, s32 maxAlpha) {
    MtxFx43 *drawMatrix;
    drawMatrix = &dossun->mUnk_00.mMatrix;
    if (dossun->mUnk_b4 != 0) {
        drawMatrix = &dossun_sRotMtx;
        MTX_RotY33_((s32 *) &dossun_sRotMtx, FX_SinCosTable_[((u16) dossun->mUnk_ba >> 4) * 2],
                    FX_SinCosTable_[((u16) dossun->mUnk_ba >> 4) * 2 + 1]);
        MTX_Concat33((const s32 *) &dossun_sRotMtx, (const s32 *) &dossun->mUnk_00.mMatrix,
                     (s32 *) &dossun_sRotMtx);
    }
    drawMatrix->mUnk_00[3].x = dossun->mUnk_00.mPos.x >> 4;
    drawMatrix->mUnk_00[3].y = dossun->mUnk_00.mPos.y >> 4;
    drawMatrix->mUnk_00[3].z = dossun->mUnk_00.mPos.z >> 4;
    model2_renderModel(dossun_sModel, drawMatrix, &dossun->mUnk_00.mScale, maxAlpha);
    model2_renderShadowModel(dossun_sShadowModel, drawMatrix, &dossun->mUnk_00.mScale, maxAlpha);
}

void dossun_update(void *unused, Dossun *dossun) {
    Unk0210b7a8 soundRequest;
    GroupFollower *follower;
    CourseMapGroupEntry *fromEntry;
    s32 n;
    s32 speed;
    s32 t;
    s32 sine;
    dossun->mEnteredState5 = FALSE;
    follower = &dossun->mFollower;
    if (dossun->mUnk_b4 != 0) {
        dossun->mUnk_ba += dossun->mUnk_b8;
        n = dossun->mUnk_b8;
        if (n > 0x3e8 || n < -0x3e8) {
            if (dossun->mState < 4) {
                dossun->mUnk_b8 = (n * 0xfa00) >> 16;
            } else {
                dossun->mUnk_b8 = (n * 0xf80c) >> 16;
            }
        } else if (dossun->mUnk_b4 == 2) {
            if (n * dossun->mUnk_ba <= 0) {
                return;
            }
            if (n * n <= dossun->mUnk_ba * dossun->mUnk_ba) {
                return;
            }
            dossun->mUnk_b8 = 0;
            dossun->mUnk_ba = dossun->mUnk_b8;
            dossun->mUnk_b4 = 0;
            dossun->mUnk_c0 = 0;
            dossun->mTimer = 0x1e;
            dossun->mState = 0;
            return;
        }
        if (dossun->mUnk_b4 != 1) {
            return;
        }
        speed = follower->mSpeed;
        if (dossun->mState < 4) {
            if (speed > 0x4000) {
                t = ((s64) speed * 0xf85) >> 12;
                follower->mSpeed = t;
                follower->mProgressStep =
                    ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            }
        } else {
            if (speed > 0x800) {
                t = ((s64) speed * 0xe66) >> 12;
                follower->mSpeed = t;
                follower->mProgressStep =
                    ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            }
        }
        if (pw_update(follower) != FALSE) {
            dossun->mUnk_00.mPos = follower->mFromEntry->mPos;
            dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
            if (follower->mForward != 0) {
                follower->mProgress = 0;
            } else {
                pw_reverse(follower);
                pw_20D8648(follower);
            }
            dossun->mUnk_b4 = 2;
            return;
        }
        pw_calcCurrentPointLinearXYZ(follower, &dossun->mUnk_00.mPos);
        dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
        return;
    }
    switch (dossun->mState) {
        case 0:
            dossun->mTimer--;
            if (dossun->mTimer >= 0) {
                return;
            }
            dossun->mState++;
            t = dossun->mUnk_f0 != 0 ? 0xc00 : 0x3000;
            follower->mSpeed = t;
            follower->mProgressStep =
                ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            return;
        case 1:
            if (dossun->mUnk_f0 != 0) {
                mobj_emitSfxFromEmitter(&dossun->mUnk_00, 0x18b);
            }
            break;
        case 2:
            dossun->mTimer--;
            if (dossun->mTimer < 0 && dossun->mUnk_c2 < 0x1555) {
                dossun->mState++;
                dossun->mUnk_a8 = -dossun->mUnk_100;
                return;
            }
            dossun->mUnk_c2 += 0x1555;
            dossun->mUnk_00.mPos.y = dossun->mUnk_ac;
            sine = FX_SinCosTable_[(dossun->mUnk_c2 >> 4) * 2];
            dossun->mUnk_00.mPos.y += (s32) (((s64) sine * dossun->mUnk_c4) >> 12);
            return;
        case 3:
            dossun->mUnk_a8 += dossun->mUnk_104;
            dossun->mUnk_00.mPos.y -= dossun->mUnk_a8;
            if (dossun->mUnk_00.mPos.y < dossun->mUnk_ac) {
                dossun->mState++;
            }
            return;
        case 4:
            if (dossun->mUnk_a8 < 0x14000) {
                dossun->mUnk_a8 += 0x1000;
                t = dossun->mUnk_a8;
                follower->mSpeed = t;
                follower->mProgressStep =
                    ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            }
            break;
        case 5:
            dossun->mTimer--;
            if (dossun->mTimer >= 0) {
                return;
            }
            dossun->mState++;
            t = dossun->mUnk_108;
            follower->mSpeed = t;
            follower->mProgressStep =
                ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            return;
        case 6:
            break;
    }
    if (pw_update(follower) != FALSE) {
        switch (follower->mFromEntry->mUnk_10) {
            case 0:
                n = 0;
                break;
            case 1:
                n = 2;
                break;
            case 2:
                n = 5;
                break;
            default:
                n = 0;
                break;
        }
        dossun->mState = n;
        if (dossun->mState == 2) {
            dossun->mUnk_ac = dossun->mUnk_00.mPos.y;
            dossun->mUnk_c2 = 0;
        }
        if (dossun->mState == 5) {
            fromEntry = follower->mFromEntry;
            if (mobj_isInaudible(&dossun->mUnk_00) == FALSE) {
                if (dossun->mUnk_00.mFarDistanceSquared == gSfxParams[2].mUnk_20) {
                    n = 2;
                } else if (dossun->mUnk_00.mFarDistanceSquared == gSfxParams[3].mUnk_20) {
                    n = 3;
                } else {
                    n = 4;
                }
                soundRequest.mSoundId = 0x166;
                soundRequest.mPositionSource = &dossun->mUnk_00.mPos;
                soundRequest.mUnk_08 = n;
                soundRequest.mDistanceSquared = mobj_calcXZCamDist(&dossun->mUnk_00.mPos);
                func_0210b7a8(&soundRequest);
            }
            cam_tryImpactShakePlayerCamera(dossun->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
            if ((dossun->mUnk_00.mDistanceSquaredAndFlags & 3) == 0) {
                ptcm_createEmitter(0x59, &fromEntry->mPos);
                ptcm_createEmitter(0x5a, &fromEntry->mPos);
            }
            dossun->mEnteredState5 = TRUE;
        }
        dossun->mTimer = follower->mFromEntry->mUnk_0e;
        if (dossun->mTimer != 0) {
            dossun->mUnk_00.mPos = follower->mPath->mSegments[follower->mSegmentIndex].mPoints[0];
            dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
            follower->mProgress = 0;
            return;
        }
    }
    pw_calcCurrentPointLinearXYZ(follower, &dossun->mUnk_00.mPos);
    dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
}

u32 dossun_onDriverCollide(Dossun *dossun, Kart *kart, u8 *b, u8 *c) {
    Vec3 kartOffset;
    Vec3 toNextEntry;
    Vec3 centerOffset;
    GroupFollower *follower;
    s32 speed;
    s64 m;
    s32 verticalOffset;
    s64 n;
    follower = &dossun->mFollower;
    if (*b == 1) {
        if ((dossun->mUnk_c0 & (1 << kart->mIndex)) == 0 || dossun->mUnk_bc + 0xf < race_getFrameCounter()) {
            VEC_Subtract(&kart->mCollisionCenter, &dossun->mUnk_00.mPos, &kartOffset);
            VEC_Subtract(&follower->mToEntry->mPos, &dossun->mUnk_00.mPos, &toNextEntry);
            toNextEntry.y += dossun->mHeightOffset;
            if (vec_dotProduct(&kartOffset, &toNextEntry) > 0) {
                pw_reverse(follower);
            }
            if (dossun->mState < 4) {
                speed = 0xa800;
            } else {
                speed = 0x8000;
            }
            speed = speed - (s32) (((s64) (0x1000 - dossun->mUnk_00.mScale.y) * 0x2000) >> 12);
            follower->mSpeed = speed;
            follower->mProgressStep =
                ((s64) speed * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            dossun->mUnk_b4 = 1;
            dossun->mUnk_b8 = 0x1b58;
            if ((s64) kartOffset.z * kart->mVelocity.x - (s64) kartOffset.x * kart->mVelocity.z < 0) {
                dossun->mUnk_b8 = -dossun->mUnk_b8;
            }
            mobj_tryDestroyByDriver(&dossun->mUnk_00, kart);
            dossun->mUnk_c0 |= 1 << kart->mIndex;
            dossun->mUnk_bc = race_getFrameCounter();
        }
    }
    if (dossun->mState == 4 || dossun->mEnteredState5 != FALSE) {
        VEC_Subtract(&kart->mCollisionCenter, &dossun->mUnk_00.mPos, &centerOffset);
        n = ((s64) centerOffset.x * centerOffset.x + (s64) centerOffset.z * centerOffset.z) * 5;
        verticalOffset = centerOffset.y;
        m = ((s64) verticalOffset * verticalOffset) << 2;
        if (verticalOffset < 0 && n < m) {
            return mobj_getDriverHitResponse(dossun->mUnk_00.mFlags & 0x800, kart->mItemEffect, 4, 4);
        }
    }
    return *c;
}

s32 dossun_getMapElevation(Dossun *dossun) {
    s32 progress;
    s32 state;
    progress = pw_getProgress(&dossun->mFollower);
    state = dossun->mState;
    if (state < 4) {
        if (dossun->mUnk_f0 != 0) {
            return 0;
        }
        return 0x1000;
    }
    switch (dossun->mUnk_b4) {
        case 0:
            switch (state) {
                case 4:
                    progress = 0x1000 - progress;
                    break;
                case 5:
                    progress = 0;
                    break;
                case 6:
                    break;
            }
            break;
        case 2:
            progress = 0x1000;
            break;
    }
    return progress;
}

#pragma thumb on
void dossun_initState(Dossun *dossun) {
    GroupFollower *follower;
    s32 state;
    follower = &dossun->mFollower;
    pw_init(follower, dossun->mStartEntryIndex, 1);
    pw_calcCurrentPointLinearXYZ(follower, &dossun->mUnk_00.mPos);
    dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
    switch (follower->mFromEntry->mUnk_10) {
        case 0:
            state = 0;
            break;
        case 1:
            state = 2;
            break;
        case 2:
            state = 5;
            break;
        default:
            state = 0;
            break;
    }
    dossun->mState = state;
    dossun->mTimer = follower->mFromEntry->mUnk_0e;
    dossun->mUnk_b4 = 0;
    dossun->mUnk_ba = 0;
    dossun->mUnk_b8 = dossun->mUnk_ba;
    dossun->mUnk_c0 = 0;
    dossun->mUnk_ac = dossun->mUnk_00.mPos.y;
    dossun->mEnteredState5 = FALSE;
}
#pragma thumb off

#pragma thumb on
void dossun_loadModels(void) {
    model2_createFromNsbmd((void **) &dossun_sModel, mobj_getMapObjFile("dossun.nsbmd"), NULL);
    model2_createShadowFromNsbmd((void **) &dossun_sShadowModel, mobj_getMapObjFile("dossun_shadow.nsbmd"), 0x3f);
    model_setPolyIdLightFlagsEmi(dossun_sModel, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void dossun_init(Dossun *dossun, CourseMapRow *row) {
    dossun->mUnk_f0 = row->mUnk_28;
    pw_initFromObject(&dossun->mFollower, row, dossun->mUnk_f0 != 0 ? 0xc00 : 0x3000);
    dossun->mStartEntryIndex = row->mUnk_2a;
    dossun->mUnk_f4 = ((s64) dossun->mUnk_00.mScale.x * 0x28000) >> 12;
    dossun->mHeightOffset = ((s64) dossun->mUnk_00.mScale.y * 0x2d000) >> 12;
    dossun->mUnk_fc = ((s64) dossun->mUnk_00.mScale.z * 0x1e000) >> 12;
    dossun->mUnk_100 = ((s64) dossun->mUnk_00.mScale.y * 0xf000) >> 12;
    dossun->mUnk_104 = ((s64) dossun->mUnk_00.mScale.y * 0x1000) >> 12;
    dossun->mUnk_108 = ((s64) dossun->mUnk_00.mScale.y * 0x2000) >> 12;
    dossun->mUnk_c4 = ((s64) dossun->mUnk_00.mScale.y * 0x3000) >> 12;
    dossun_initState(dossun);
    if (dossun->mUnk_f0 != 0) {
        mobj_initSoundEmitterForObjectSfxParam3(&dossun->mUnk_00);
    } else {
        dossun->mUnk_00.mFarDistanceSquared = gSfxParams[3].mUnk_20;
    }
}
#pragma thumb off

Unk020db268 *kuribo_setupConfig(void) {
    Unk020db268 *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = data_021581b8;
    return kindData;
}

Unk020db20c *kuribo_setupRenderPart(void) {
    Unk020db20c *drawList;
    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    kuribo_sRenderPart = drawList;
    *drawList = data_0215818c;
    mobj_renderPartSetThisPointer(&kuribo_sRenderPart);
    return kuribo_sRenderPart;
}

Unk020db1b0 *kuribo_setupLogicPart(void) {
    Unk020db1b0 *updateList;
    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    kuribo_sLogicPart = updateList;
    *updateList = data_02158164;
    mobj_logicPartSetThisPointer(&kuribo_sLogicPart);
    return kuribo_sLogicPart;
}

void kuribo_globalPreRender(void) {
    bbm_applyMaterial(kuribo_sModel);
}

void kuribo_render(void *unused0, Kuribo *kuribo, void *unused1, u16 d) {
    Vec3 scale;
    Quaternion orientation;
    u16 e;
    NsbmdModel *model;
    if (kuribo->mUnk_cc.mGroupIndex == 0xffff) {
        qrtn_20D7938(&kuribo->mUnk_a4, &gViewYawQuaternion, &orientation);
        qtrn_toMtx33(&kuribo->mUnk_00.mMatrix, &orientation);
    } else {
        bbm_20E6D34(GetGroupFollowerSegmentUp(&kuribo->mUnk_cc), &kuribo->mUnk_00.mMatrix);
    }
    scale.z = kuribo->mUnk_00.mScale.z;
    scale.y = ((s64) kuribo->mUnk_00.mScale.y * kuribo->mUnk_c4) >> 12;
    scale.x = ((s64) kuribo->mUnk_00.mScale.x * (((0x1000 - kuribo->mUnk_c4) >> 1) + 0x1000)) >> 12;
    kuribo->mUnk_00.mMatrix.mUnk_00[3].x = kuribo->mUnk_00.mPos.x >> 4;
    kuribo->mUnk_00.mMatrix.mUnk_00[3].y = kuribo->mUnk_00.mPos.y >> 4;
    kuribo->mUnk_00.mMatrix.mUnk_00[3].z = kuribo->mUnk_00.mPos.z >> 4;
    if (kuribo->mUnk_f0 < 0x14) {
        kuribo_sModel->mFrameIndex = kuribo->mUnk_f0;
    } else {
        scale.x = -scale.x;
        kuribo_sModel->mFrameIndex = kuribo->mUnk_f0 - 0x14;
    }
    e = kuribo->mUnk_100;
    model = kuribo_sModel;
    model->mUnk_14 &= ~0x1f0000;
    model->mUnk_14 |= e << 16;
    bbm_renderTransformedScaled(kuribo_sModel, &kuribo->mUnk_00.mMatrix, &scale, 0, d);
}

void kuribo_update(void *unused, Kuribo *kuribo) {
    Unk0210b7a8 soundRequest;
    RandomState64 *random;
    s32 falloffIndex;
    kuribo->mUnk_f0++;
    if (kuribo->mUnk_f0 == 0x14 || kuribo->mUnk_f0 == 0x28) {
        if ((kuribo->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
            if (kuribo->mUnk_00.mFarDistanceSquared == gSfxParams[2].mUnk_20) {
                falloffIndex = 2;
            } else if (kuribo->mUnk_00.mFarDistanceSquared == gSfxParams[3].mUnk_20) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            soundRequest.mSoundId = 0x182;
            soundRequest.mPositionSource = &kuribo->mUnk_00.mPos;
            soundRequest.mUnk_08 = falloffIndex;
            soundRequest.mDistanceSquared = mobj_calcXZCamDist(&kuribo->mUnk_00.mPos);
            func_0210b7a8(&soundRequest);
        }
    }
    if (kuribo->mUnk_f0 >= 0x28) {
        if (kuribo->mUnk_f4 != 0) {
            kuribo->mUnk_f0 = 0;
        } else {
            random = &gRaceStatus->mRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            kuribo->mUnk_f0 = ((u64) (u32) (random->mValue >> 32) * 0x28) >> 32;
            kuribo->mUnk_f4 = 1;
        }
    }
    sm_execute(&kuribo->mUnk_00.mStateMachine);
}
