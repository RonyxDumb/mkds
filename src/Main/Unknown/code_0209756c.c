#include "Main/Unknown/code_0209756c.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_020109c4.h"
#include "code_020184e4.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

void flip_init(Flipper *flipper) {
    flipper->field0.mFlags = flipper->field0.mFlags | data_0215658c;
    mobj_setDirectionFromFloor(flipper);
}

u32 flip_onDriverCollide(Flipper *flipper, Kart *kart, void *b, u8 *c) {
    u32 v;
    BOOL t;
    s32 f;
    Vec3 offset;
    s32 s;
    Vec3 *e;

    v = *c;
    t = (flipper->mState == 2 || flipper->mState == 5) && flipper->fieldA0 > 0;
    if (t) {
        s = -0x19a;
    } else if ((flipper->mState == 3 || flipper->mState == 6) && flipper->fieldA0 < 0) {
        s = 0x19a;
    } else {
        s = 0;
    }
    if (s != 0) {
        if (flipper->fieldED4[kart->mIndex] != 0) {
            flipper->field0.field10.x = 0;
            flipper->field0.field10.y = 0;
            flipper->field0.field10.z = 0;
        } else {
            VEC_Subtract(&kart->mPos, &flipper->field0.mPos, &offset);
            f = VEC_Mag(&offset);
            e = &flipper->fieldA8[flipper->fieldEC0].field0[2];
            f = ((s64) f * s) >> 12;
            flipper->field0.field10.x = ((s64) e->x * f) >> 12;
            flipper->field0.field10.y = ((s64) e->y * f) >> 12;
            flipper->field0.field10.z = ((s64) e->z * f) >> 12;
            flipper->field0.mDistanceSquaredAndFlags = flipper->field0.mDistanceSquaredAndFlags | data_02156588;
            mobj_driverEmitSfx2(kart, 0x1d1);
        }
        if (flipper->fieldEC8 != 0) {
            return 0xe;
        }
        return 0xc;
    }
    flipper->field0.field10.x = 0;
    flipper->field0.field10.y = 0;
    flipper->field0.field10.z = 0;
    return v;
}

u32 flip_collide(Flipper *flipper, Vec3 *sphereCenter, s32 b, Vec3 *pushOut) {
    s32 r;

    flipper->fieldA0 = 0;
    if (col_collideSphereBox(
            sphereCenter, &flipper->field0.mPos, &flipper->fieldA8[flipper->fieldEC0].field0[0],
            &data_0215650c[flipper->mMirror], &data_0215653c[flipper->mMirror], b, NULL) != 0) {
        r = col_collideSphereBox(
            sphereCenter, &flipper->field0.mPos, &flipper->fieldA8[flipper->fieldEC0].field0[0],
            &data_02156554[flipper->mMirror], &data_021564dc[flipper->mMirror], b, pushOut);
        if (r == 4 || flipper->mState == 2) {
            flipper->fieldA0 = 1;
        } else if (flipper->mState == 3) {
            flipper->fieldA0 = -1;
        }
    } else {
        if (col_collideSphereBox(
                sphereCenter, &flipper->field0.mPos, &flipper->fieldA8[flipper->fieldEC0].field0[0],
                &data_021564c4[flipper->mMirror], &data_02156524[flipper->mMirror], b, NULL) != 0) {
            r = col_collideSphereBox(
                sphereCenter, &flipper->field0.mPos, &flipper->field648[flipper->fieldEC0].field0[0],
                &data_0215656c[flipper->mMirror], &data_021564f4[flipper->mMirror], b, pushOut);
            if (r == 4 || flipper->mState == 3) {
                flipper->fieldA0 = -1;
            } else if (flipper->mState == 2) {
                flipper->fieldA0 = 1;
            }
        } else {
            r = col_collideSphereCylinder(sphereCenter, &flipper->field0.mPos,
                                                  &flipper->fieldA8[flipper->fieldEC0].field0[0], 0x32000, 0x3c000, 0,
                                                  b, pushOut);
        }
    }
    return r != 0;
}

void flip_loadModel(void *a) {
    flip_sModel = mobj_loadModel(a, aFlipper_nsbmd);
    mobj_loadNsbtpAnim(flip_sModel, aFlipper_nsbtp);
    mobj_loadNsbtaAnim(flip_sModel, aFlipper_nsbta);
}

void flip_render(void *a, Flipper *flipper) {
    s32 v;
    MtxFx43 *matrix;
    ModelAnimation *s;

    v = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v, 1);
    matrix = &flipper->fieldA8[flipper->fieldEC0];
    matrix->field0[3].x = flipper->field0.mPos.x >> 4;
    matrix->field0[3].y = flipper->field0.mPos.y >> 4;
    matrix->field0[3].z = flipper->field0.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &flipper->field0.mScale, 3);
    mobj_setModelFlip(flip_sModel, flipper->mMirror, 0);
    s = flip_sModel->mAnimations[1];
    s->mFrameIndex = flipper->mNsbtpFrameIndex << 12;
    s->mAnmObjs[s->mCurrentIndex]->mFrame = s->mFrameIndex;
    s = flip_sModel->mAnimations[3];
    s->mFrameIndex = flipper->mNsbtaFrameIndex << 12;
    s->mAnmObjs[s->mCurrentIndex]->mFrame = s->mFrameIndex;
    mobj_renderModel(a, flip_sModel, flipper);
}

void flip_globalLogicInit(MapObjectList *mapObjectList) {
    s32 i;
    s32 j;
    s32 v1;
    s32 d;
    s32 k;
    u32 e;
    Flipper *flipper;
    MtxFx43 *q;
    s32 m2[9];
    s32 m1[9];

    if (mapObjectList == NULL) {
        return;
    }
    v1 = data_0215653c[0].x;
    for (i = 0; i < mapObjectList->mMapObjectCount && (flipper = mapObjectList->mMapObjects[i]) != NULL; i++) {
        switch (flipper->field0.mCourseMapRow->field28) {
            case 0:
                flipper->mMirror = 0;
                flipper->field0.mFlags &= ~0x400;
                flipper->field0.mAngle = 0x2000;
                flipper->mState1Timer = 0x1e;
                MTX_RotY33_(m2, data_02160fb4[0x74], data_02160fb4[0x75]);
                break;
            case 1:
                flipper->mMirror = 1;
                flipper->field0.mFlags |= data_02156584;
                flipper->field0.mAngle = 0x2000;
                flipper->mState1Timer = 0x1e;
                MTX_RotY33_(m2, data_0215d8b4[10], data_0215d8b4[11]);
                break;
        }
        flipper->fieldEC8 = 0;
        if (flipper->mMirror == 0) {
            e = flipper->field0.mAngle;
        } else {
            e = -flipper->field0.mAngle;
        }
        for (j = 0; j < 30; j++) {
            if (flipper->mMirror == 0) {
                d = 0x16c;
            } else {
                d = -0x16c;
            }
            e = e - d;
            k = (u16) e >> 4;
            MTX_RotY33_(m1, FX_SinCosTable_[k * 2], FX_SinCosTable_[k * 2 + 1]);
            q = &flipper->fieldA8[j];
            MTX_Concat33(m1, &flipper->field0.mMatrix.field0[0].x, &q->field0[0].x);
            MTX_Concat33(m2, &q->field0[0].x, &flipper->field648[j].field0[0].x);
            flipper->fieldBE8[j].x = flipper->field0.mPos.x >> 4;
            flipper->fieldBE8[j].y = flipper->field0.mPos.y >> 4;
            flipper->fieldBE8[j].z = flipper->field0.mPos.z >> 4;
            if (flipper->mMirror == 0) {
                k = (u16) (-e + FX_Atan2Idx(-2, -10)) >> 4;
                flipper->fieldD50[j].x =
                    (flipper->field0.mPos.x + (s32) (((s64) v1 * FX_SinCosTable_[k * 2 + 1]) >> 12)) >> 4;
                flipper->fieldD50[j].y = flipper->field0.mPos.y >> 4;
                flipper->fieldD50[j].z =
                    (flipper->field0.mPos.z + (s32) (((s64) v1 * FX_SinCosTable_[k * 2]) >> 12)) >> 4;
            } else {
                k = (u16) (-e - FX_Atan2Idx(-2, -10)) >> 4;
                flipper->fieldD50[j].x =
                    (flipper->field0.mPos.x - (s32) (((s64) v1 * FX_SinCosTable_[k * 2 + 1]) >> 12)) >> 4;
                flipper->fieldD50[j].y = flipper->field0.mPos.y >> 4;
                flipper->fieldD50[j].z =
                    (flipper->field0.mPos.z - (s32) (((s64) v1 * FX_SinCosTable_[k * 2]) >> 12)) >> 4;
            }
        }
    }
}

void flip_update(void *a, Flipper *flipper) {
    s32 i;
    s32 kartCount;
    RandomState64 *mapObjectRandom;
    u32 r;
    s32 w;

    flipper->fieldEBC = flipper->fieldEBC - (flipper->fieldEBC > 0);
    switch (flipper->mState) {
        case 0:
            flipper->fieldED0 = ptcm_createEmitter(0x5f, &flipper->field0.mPos);
            flipper->mState = 1;
            break;
        case 1:
            if (flipper->fieldEBC != 0) {
                flipper->mState = 4;
            } else {
                flipper->mState1Timer = flipper->mState1Timer - 1;
                if (flipper->mState1Timer <= 0) {
                    flipper->fieldEC0 = 0;
                    flipper->mState = 2;
                }
            }
            flipper->fieldEC8 = 0;
            break;
        case 2:
            flipper->field0.mAngle -= 0x16c;
            flipper->fieldEC0 = flipper->fieldEC0 + 1;
            if (flipper->fieldEC0 >= 0x1d) {
                flipper->fieldEC0 = 0x1d;
                flipper->mState = 3;
            }
            flipper->fieldEC8 = 1;
            break;
        case 3:
            flipper->field0.mAngle += 0x16c;
            if (flipper->fieldEC0 >= 0xf) {
                flipper->fieldEC8 = 1;
            } else {
                flipper->fieldEC8 = 0;
            }
            flipper->fieldEC0 = flipper->fieldEC0 - 1;
            if (flipper->fieldEC0 <= 0) {
                flipper->fieldEC0 = 0;
                mapObjectRandom = mobj_getRng1();
                mapObjectRandom->mValue =
                    (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                r = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 12) >> 32;
                flipper->mState1Timer = (u16) ((u16) r * 0x14);
                flipper->mState = 1;
            }
            break;
        case 4:
            if (flipper->fieldEBC <= 0) {
                flipper->fieldEC0 = 0;
                flipper->mState = 5;
            }
            flipper->fieldEC8 = 0;
            break;
        case 5:
            flipper->field0.mAngle -= 0x2d8;
            flipper->fieldEC0 = flipper->fieldEC0 + 2;
            if (flipper->fieldEC0 >= 0x1c) {
                flipper->fieldEC0 = 0x1c;
                flipper->mState = 6;
            }
            flipper->fieldEC8 = 1;
            break;
        case 6:
            flipper->field0.mAngle += 0x2d8;
            if (flipper->fieldEC0 >= 0xf) {
                flipper->fieldEC8 = 1;
            } else {
                flipper->fieldEC8 = 0;
            }
            flipper->fieldEC0 = flipper->fieldEC0 - 2;
            if (flipper->fieldEC0 <= 0) {
                flipper->fieldEC0 = 0;
                mapObjectRandom = mobj_getRng1();
                mapObjectRandom->mValue =
                    (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                r = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 12) >> 32;
                flipper->mState1Timer = (u16) ((u16) r * 0x14);
                flipper->mState = 1;
            }
            break;
    }
    if (flipper->fieldEC8 != 0 && (flipper->field0.mFlags & 0x12) == 0) {
        w = flipper->mNsbtpFrameIndex + 1;
        if (w >= mobj_getModelNsbtpFrameCount(flip_sModel)) {
            w = 1;
        }
        flipper->mNsbtpFrameIndex = w;
        w = flipper->mNsbtaFrameIndex + 1;
        if (w >= mobj_getModelNsbtaFrameCount(flip_sModel)) {
            w = 1;
        }
        flipper->mNsbtaFrameIndex = w;
        flipper->fieldED0->field24.field0_1 = 0;
        spa_setCylinderEmitterDirection(flipper->fieldED0, &flipper->fieldBE8[flipper->fieldEC0],
                                      &flipper->fieldD50[flipper->fieldEC0]);
    } else {
        flipper->mNsbtpFrameIndex = 0;
        flipper->mNsbtaFrameIndex = 0;
        flipper->fieldED0->field24.field0_1 = 1;
    }
    kartCount = gRaceMultiConfig->mKartCount;
    for (i = 0; i < kartCount; i++) {
        if (flipper->fieldED4[i] > 0) {
            flipper->fieldED4[i] = flipper->fieldED4[i] - 1;
        }
    }
}

void flip_setupConfig(void) {
    mobj_createConfigEx(flip_onDriverCollide, NULL, flip_collide, 0, 1, 0x1d0);
}

void *flip_setupRenderPart(void) {
    return mobj_createRenderPart3d(flip_loadModel, flip_render, NULL);
}

void *flip_setupLogicPart(void) {
    return mobj_createLogicPart(flip_globalLogicInit, flip_update, NULL);
}
