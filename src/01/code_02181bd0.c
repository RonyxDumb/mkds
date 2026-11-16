#include "01/code_02181bd0.h"

#include "01/code_02181000.h"
#include "01/code_02182000.h"
#include "01/code_02182f98.h"
#include "01/code_02183000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d8000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d7da8.h"
#include "code_0212bcac.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "ITCM/code_01ff8000.h"

Unk0219b250 *coin_sModel;

void coin_initForCollect(Coin *coin, Kart *kart) {
    coin->mTimer = 0x1e;
    coin->field0.mPos.x = kart->mPos.x;
    coin->field0.mPos.y = kart->mPos.y + 0xc000;
    coin->field0.mPos.z = kart->mPos.z;
    coin->field0.field10.y = 0x3000;
    coin->mState = 1;
    coin->mScaleFactor = 0x99a;
    coin->mModelAlpha = 0x1f;
    coin->field0.mFlags = coin->field0.mFlags | data_ov001_021a6574;
    coin->mEffect = ptcm_createEmitter(0x3f5, &coin->field0.mPos);
    coin->mEffectTimer = 0xd;
}

void coin_updateAnim(Coin *coin, s32 b) {
    coin->fieldA8 += b;
    if (coin->fieldA8 >= 5) {
        coin->fieldA8 -= 5;
        coin->mNsbtpFrameIndex += 1;
        if (coin->mNsbtpFrameIndex >= mobj_getModelNsbtpFrameCount(coin_sModel)) {
            coin->mNsbtpFrameIndex -= mobj_getModelNsbtpFrameCount(coin_sModel);
        }
    }
}

void coin_handleCollect(void) {
    Kart *kart;
    Coin *coin;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    coin = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(0x68));
    if (coin != NULL) {
        coin_initForCollect(coin, kart);
    }
}

void coin_handleLose(void) {
    Kart *kart;
    Coin *coin;
    RandomState64 *random;
    s32 angle;
    s32 speed;
    Unk0210b7a8 soundArg;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    coin = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(0x68));
    if (coin != NULL) {
        random = mobj_getRng1();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        angle = (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32);
        random = mobj_getRng1();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        speed = (u32) (((u64) (u32) (random->mValue >> 32) * 0x800) >> 32) + 0x800;
        coin->mState = 3;
        coin->mScaleFactor = 0x99a;
        coin->mModelAlpha = 0x10;
        coin->field0.mPos.x = kart->mPos.x;
        coin->field0.mPos.y = kart->mPos.y + 0x1a000;
        coin->field0.mPos.z = kart->mPos.z;
        coin->field0.field10.x = kart->mVelocity.x + (s32) (((s64) speed * FX_SinCosTable_[(angle >> 4) * 2]) >> 12);
        coin->field0.field10.y = kart->mVelocity.y + 0x4000;
        coin->field0.field10.z =
            kart->mVelocity.z + (s32) (((s64) speed * FX_SinCosTable_[(angle >> 4) * 2 + 1]) >> 12);
        coin->field0.mFlags &= ~1;
        soundArg.mSoundId = 0x1d9;
        soundArg.mPositionSource = NULL;
        soundArg.field8 = 2;
        soundArg.mDistanceSquared = mobj_calcXZCamDist(NULL);
        sub_210B7A8(&soundArg);
    }
}

void coin_handleSteal(void) {
    Kart *kart;
    Coin *coin;
    RandomState64 *random;
    s32 angle;
    s32 speed;
    u8 kartCount;
    Unk02188950 *targetObject;
    Unk0210b7a8 soundArg;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    coin = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(0x68));
    if (coin != NULL) {
        random = mobj_getRng1();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        angle = (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32);
        random = mobj_getRng1();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        speed = (u32) (((u64) (u32) (random->mValue >> 32) * 0x800) >> 32) + 0x800;
        coin->mState = 5;
        coin->mScaleFactor = 0x99a;
        coin->mModelAlpha = 0x10;
        coin->mTimer = 0x1e;
        targetObject = NULL;
        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
            kartCount = 0;
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                kartCount = func_ov001_02181b54();
            }
            targetObject = GetMissionRunMapObject(kartCount);
        }
        coin->mTargetPos = &targetObject->field0.mPos;
        coin->field0.mPos.x = kart->mPos.x;
        coin->field0.mPos.y = kart->mPos.y + 0x1a000;
        coin->field0.mPos.z = kart->mPos.z;
        coin->field0.field10.x = (((s64) speed * FX_SinCosTable_[(angle >> 4) * 2]) >> 12);
        coin->field0.field10.y = 0x4000;
        coin->field0.field10.z = (((s64) speed * FX_SinCosTable_[(angle >> 4) * 2 + 1]) >> 12);
        soundArg.mSoundId = 0x1d9;
        soundArg.mPositionSource = NULL;
        soundArg.field8 = 2;
        soundArg.mDistanceSquared = mobj_calcXZCamDist(NULL);
        sub_210B7A8(&soundArg);
    }
}

void coin_steal(u32 amount) {
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        mrcnt_stealCoins(amount);
    }
}

void func_ov001_02182a3c(s32 a) {
    int i;
    s32 foundCount;
    CoinList *coinList;
    Coin *coin;
    RandomState64 *random;
    u16 angle;
    int tableIndex;

    foundCount = 0;
    coinList = mobj_getLogicPartForObjectId(0x68);
    driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            if (coin->mState == 7) {
                foundCount++;
                if (foundCount <= a) {
                    if (coin->mTargetPos == NULL) {
                        random = mobj_getRng1();
                        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
                        angle = ((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32;
                        coin->mScaleFactor = 0x1000;
                        coin->mModelAlpha = 0;
                        coin->mTargetPos =
                            (Vec3 *) ((gRaceMultiConfig->mMode == MODE_MISSION_RUN
                                           ? (u32) GetMissionRunMapObject(
                                                 gRaceMultiConfig->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0)
                                           : 0) +
                                      4);
                        coin->field0.mPos.x = coin->mTargetPos->x;
                        coin->field0.mPos.y = coin->mTargetPos->y;
                        coin->field0.mPos.z = coin->mTargetPos->z;
                        coin->field0.field10.x = 0;
                        coin->field0.field10.y = 0x4cd;
                        coin->field0.field10.z = 0;
                        tableIndex = (angle >> 4) * 2;
                        coin->fieldEC.x = ((s64) FX_SinCosTable_[tableIndex] * 0x14000) >> 12;
                        coin->fieldEC.y = -0xa000;
                        coin->fieldEC.z = ((s64) FX_SinCosTable_[tableIndex + 1] * 0x14000) >> 12;
                    }
                } else {
                    if (coin->mTargetPos != NULL) {
                        coin->mTargetPos = NULL;
                    }
                }
            }
        }
    }
}

void func_ov001_021829ac(s32 a) {
    CoinList *coinList;
    Coin *coin;
    s32 count;
    int i;

    count = 0;
    coinList = mobj_getLogicPartForObjectId(0x68);
    driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            if (coin->mState == 7) {
                if (coin->mTargetPos != NULL) {
                    coin->mTargetPos = NULL;
                }
                count++;
                if (count <= a) {
                    if ((coin->field0.mFlags & 0x100) == 0) {
                        mobj_setInvisible(&coin->field0);
                    }
                    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                        mrcnt_regainStolenCoins(1);
                    }
                }
            }
        }
    }
}

void func_ov001_021828f0(void) {
    int i;
    Coin *coin;
    CoinList *coinList;
    NNSSndSeqPlayer **sndHandleSlot;

    coinList = mobj_getLogicPartForObjectId(0x68);
    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            if (coin->mState == 0 && (coin->field0.mFlags & 0x100) == 0) {
                coin->field0.field10.y = 0x5000;
                coin->mModelAlpha = 0x32;
                coin->mState = 8;
                coin->field0.mFlags |= data_ov001_021a6574;
            }
        }
    }
    sndHandleSlot = GetSndHandleSlot(2);
    if ((data_0217c780 & 1) && SoundHandle_217D084.fieldC != 0) {
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x233);
    }
}

void func_ov001_021827f0(void) {
    int i;
    Coin *coin;
    CoinList *coinList;
    NNSSndSeqPlayer **sndHandleSlot;

    coinList = mobj_getLogicPartForObjectId(0x68);
    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            if (coin->mState == 9 && (coin->field0.mFlags & 0x100) == 0) {
                coin->field0.mPos.x = coin->field0.mCourseMapRow->field0.x;
                coin->field0.mPos.y = coin->field0.mCourseMapRow->field0.y + 0xa000;
                coin->field0.mPos.z = coin->field0.mCourseMapRow->field0.z;
                coin->field0.field10.x = 0;
                coin->field0.field10.y = 0x5000;
                coin->field0.field10.z = 0;
                coin->mBounceY = coin->field0.mCourseMapRow->field0.y + 0xe000;
                coin->mState = 2;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->field0.mFlags &= ~1;
            }
        }
    }
    sndHandleSlot = GetSndHandleSlot(2);
    if ((data_0217c780 & 1) && SoundHandle_217D084.fieldC != 0) {
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x232);
    }
}

void coin_init(void) {
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        mrcnt_setCoinCollectFunc(coin_handleCollect);
    }
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        mrcnt_setCoinLoseFunc(coin_handleLose);
    }
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        mrcnt_setCoinStealFunc(coin_handleSteal);
    }
}

u8 coin_onDriverCollide(Coin *coin, Kart *kart, u8 *e, u8 *f) {
    u8 a = *e;
    u8 b = *f;

    if (kart->field48 & 0x200) {
        return 0;
    }
    if (a == 1) {
        if (coin->mState != 3 && coin->mState != 5 && coin->mState != 6) {
            mobj_setInvisible(&coin->field0);
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mrcnt_collectCoins(1);
            }
        }
    }
    return b;
}

void coin_loadModel(Unk0219b478 *a) {
    coin_sModel = LoadMapObjectModelAnimated(a, aCoin_nsbmd);
    LoadMapObjectModelNsbtpAnimation(coin_sModel, aCoin_nsbtp);
    mobj_setModelPolygonIdAll(coin_sModel, 0x3f);
    mobj_setModelLightMask(coin_sModel, 2);
    model_setEmi(coin_sModel->mAnimatedModel, 0x294a);
    a->field1C = 1;
}

void coin_render(void *b, Coin *coin) {
    s32 a;
    Vec3 scale;
    u32 alpha;
    s32 scaleFactor;

    if (coin->mScaleFactor > 0 && coin->mModelAlpha != 0) {
        a = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, (&a), 1);
        NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&coin->field0.mPos), 0xc);
        scaleFactor = coin->mScaleFactor;
        if (scaleFactor != 0x1000) {
            scale.x = scaleFactor;
            scale.y = scaleFactor;
            scale.z = scaleFactor;
            NNS_G3dGeBufferOP_N(0x1b, (&scale), 3);
        }
        NNS_G3dGeBufferOP_N(0x1b, (&coin->field0.mScale), 3);
        mobj_setModelPolygonIdAll(coin_sModel, mobj_getCyclicPolygonId());
        alpha = coin->mModelAlpha;
        if (alpha >= 0x1f) {
            alpha = 0x1f;
        }
        mobj_setModelAlpha(coin_sModel, alpha);
        mobj_setModelNsbtpFrame(coin_sModel, coin->mNsbtpFrameIndex);
        mobj_bbModelApplyMaterial(b, coin_sModel);
        mobj_renderModel(b, coin_sModel, coin);
    }
}

void coin_globalLogicInit(CoinList *coinList) {
    int i;
    Coin *coin;
    s32 speed;

    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            coin->fieldD8 = coin->field0.mCourseMapRow->field0;
            coin->field0.mPos = coin->fieldD8;
            coin->field0.mPos.y = coin->field0.mPos.y + 0xe000;
            if (coin->field0.mCourseMapRow->field26 >= 0) {
                pw_initFromObject(&coin->mFollower, coin->field0.mCourseMapRow, 0);
                speed = (coin->field0.mCourseMapRow->field28 << 12) / 100;
                coin->mFollower.mSpeed = speed;
                coin->mFollower.mProgressStep =
                    ((s64) speed *
                     coin->mFollower.mPath->mSegments[coin->mFollower.mSegmentIndex].mInverseProgressLength) >>
                    12;
            } else {
                coin->mFollower.mGroupIndex = 0xffff;
            }
            coin->mScaleFactor = 0x1000;
            if (coin->field0.mCourseMapRow->field2A == 0) {
                coin->mModelAlpha = 0x1f;
            } else {
                coin->mModelAlpha = 0;
            }
        }
    }
}

void coin_globalLogicPreUpdate(void) {}

void coin_update(void *a, Coin *coin) {
    s32 n;
    switch (coin->mState) {
        case 2:
            n = coin->mModelAlpha + 1;
            if (n >= 31) {
                n = 31;
            }
            coin->mModelAlpha = n;
            coin_updateAnim(coin, 1);
            coin->field0.field10.y -= 0x333;
            VEC_Add(&coin->field0.mPos, &coin->field0.field10, &coin->field0.mPos);
            if (coin->field0.mPos.y <= coin->mBounceY) {
                coin->field0.mPos.y = coin->mBounceY;
                if (coin->field0.field10.y <= 0) {
                    coin->field0.field10.y = ((s64) coin->field0.field10.y * -0x800) >> 12;
                    if (coin->field0.field10.y < 0x1000) {
                        coin->field0.field10.x = 0;
                        coin->field0.field10.y = 0;
                        coin->field0.field10.z = 0;
                        coin->mState = 0;
                    }
                    mobj_20D2600(0x1d8, &coin->field0.mPos, 2);
                }
            }
            break;
        case 0: {
            u16 radius;
            s32 i;
            BOOL found;
            Vec3 *kartPos;
            s32 dx;
            s32 dz;
            coin_updateAnim(coin, 1);
            if (coin->mFollower.mGroupIndex != 0xffff) {
                pw_update(&coin->mFollower);
                pw_20D8BF8_XYZ(&coin->mFollower, &coin->field0.mPos, &coin->field0.field10);
                coin->field0.mPos.y += 0xe000;
                coin->fieldD8 = coin->field0.mPos;
            } else {
                coin->field0.field10.x = 0;
                coin->field0.field10.y = 0;
                coin->field0.field10.z = 0;
            }
            if (coin->field0.mCourseMapRow->field2A != 0) {
                radius = coin->field0.mCourseMapRow->field2A;
                for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
                    kartPos = &driver_getById((u16) i)->mPos;
                    dx = kartPos->x - coin->field0.mPos.x;
                    dz = kartPos->z - coin->field0.mPos.z;
                    if ((s64) dx * dx + (s64) dz * dz < (s64) (radius << 12) * (radius << 12)) {
                        found = TRUE;
                        goto checked;
                    }
                }
                found = FALSE;
            checked:
                if (!found) {
                    goto skip;
                }
            }
            n = coin->mModelAlpha + 1;
            if (n >= 31) {
                n = 31;
            }
            coin->mModelAlpha = n;
            break;
        skip:
            coin->mModelAlpha = 0;
            break;
        }
        case 8:
            n = coin->mModelAlpha - 1;
            if (n <= 0) {
                n = 0;
            }
            coin->mModelAlpha = n;
            coin_updateAnim(coin, 4);
            coin->field0.mPos.y += coin->field0.field10.y;
            coin->field0.field10.y -= 0x333;
            if (coin->mModelAlpha == 0) {
                coin->mState = 9;
            }
            break;
        case 1: {
            Kart *kart;
            n = coin->mModelAlpha - 1;
            if (n <= 0) {
                n = 0;
            }
            coin->mModelAlpha = n;
            coin_updateAnim(coin, 4);
            kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
            coin->field0.mPos.x = kart->mPos.x;
            coin->field0.mPos.y += coin->field0.field10.y;
            coin->field0.mPos.z = kart->mPos.z;
            coin->field0.field10.y -= 0x333;
            if (coin->mTimer-- <= 0) {
                mobj_setInvisible(&coin->field0);
            } else if (coin->mTimer == 3) {
                rptc_2081F10(ptcm_createEmitter(0x3f4, &kart->mPos), kart->mIndex, 0x18);
            }
            if (coin->mEffect != NULL) {
                ptcm_setEmitterPosition(coin->mEffect, &coin->field0.mPos);
                if (coin->mEffectTimer-- < 0) {
                    ptcm_killEmitter(&coin->mEffect);
                }
            }
            break;
        }
        case 3: {
            u32 flags;
            Vec3 pos;
            Vec3 delta;
            Vec3 out1;
            Vec3 out2;
            n = coin->mModelAlpha + 1;
            if (n >= 31) {
                n = 31;
            }
            coin->mModelAlpha = n;
            if (coin->mScaleFactor < 0x1000) {
                coin->mScaleFactor += 0x29;
                if (coin->mScaleFactor > 0x1000) {
                    coin->mScaleFactor = 0x1000;
                }
            }
            coin_updateAnim(coin, 1);
            coin->field0.field10.y -= 0x333;
            VEC_Add(&coin->field0.mPos, &coin->field0.field10, &coin->field0.mPos);
            pos.x = coin->field0.mPos.x;
            pos.y = coin->field0.mExtent.x + (coin->field0.mPos.y - 0xe000);
            pos.z = coin->field0.mPos.z;
            if (mobj_collideAsItemDirect(&pos, &coin->field0.field10, coin->field0.mExtent.x,
                              coin->field0.mCollisionSlotIndex, 2, &delta) != 0) {
                VEC_Add(&coin->field0.mPos, &delta, &coin->field0.mPos);
                if ((s64) delta.x * delta.x + (s64) delta.y * delta.y + (s64) delta.z * delta.z >= 0x10) {
                    vec_normalize(&delta, &coin->field0.field10);
                }
                coin->field0.field10.x = ((s64) coin->field0.field10.x * 0x1400) >> 12;
                coin->field0.field10.y = ((s64) coin->field0.field10.y * 0x1400) >> 12;
                coin->field0.field10.z = ((s64) coin->field0.field10.z * 0x1400) >> 12;
            }
            if (col_collide(&pos, NULL, 0, coin->field0.mExtent.x, 1, coin->field0.mCollisionSlotIndex, &delta,
                              &out1, &out2, &flags, NULL, NULL, NULL, NULL) != 0) {
                VEC_Add(&coin->field0.mPos, &delta, &coin->field0.mPos);
                if (flags & 0x214300) {
                    BounceVelocityOffSurface(&coin->field0.field10, &out2, 0x1000, 0x1000, 0xc00,
                                             &coin->field0.field10);
                    if ((s64) coin->field0.field10.x * coin->field0.field10.x +
                            (s64) coin->field0.field10.y * coin->field0.field10.y +
                            (s64) coin->field0.field10.z * coin->field0.field10.z >=
                        0x10) {
                        vec_normalize(&coin->field0.field10, &coin->field0.field10);
                    }
                    coin->field0.field10.x = ((s64) coin->field0.field10.x * 0x1400) >> 12;
                    coin->field0.field10.y = ((s64) coin->field0.field10.y * 0x1400) >> 12;
                    coin->field0.field10.z = ((s64) coin->field0.field10.z * 0x1400) >> 12;
                }
                if ((flags & 0x1e34ef) && coin->field0.field10.y <= 0) {
                    coin->field0.field10.y = ((s64) coin->field0.field10.y * -0x800) >> 12;
                    if (coin->field0.field10.y < 0x1000) {
                        coin->field0.field10.x = 0;
                        coin->field0.field10.y = 0;
                        coin->field0.field10.z = 0;
                        coin->mState = 0;
                    }
                    mobj_20D2600(0x1d8, &coin->field0.mPos, 2);
                }
                if ((flags & 0x800) || coin->field0.mPos.y < 0) {
                    coin->mState = 4;
                }
            }
            coin->fieldD8.x = coin->field0.mPos.x;
            coin->fieldD8.z = coin->field0.mPos.z;
            break;
        }
        case 4:
            coin_updateAnim(coin, 1);
            coin->field0.field10.y -= 0x333;
            VEC_Add(&coin->field0.mPos, &coin->field0.field10, &coin->field0.mPos);
            n = coin->mModelAlpha - 1;
            if (n > 0) {
                coin->mModelAlpha = n;
                break;
            }
            if (coin->field0.mCourseMapRow->field2C != 0) {
                coin->mState = 7;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->field0.mFlags |= data_ov001_021a6574;
                if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                    mrcnt_updateStolenCoinCount(1);
                }
            } else {
                coin->field0.mPos.x = coin->field0.mCourseMapRow->field0.x;
                coin->field0.mPos.y = coin->field0.mCourseMapRow->field0.y + 0x64000;
                coin->field0.mPos.z = coin->field0.mCourseMapRow->field0.z;
                coin->field0.field10.x = 0;
                coin->field0.field10.y = 0;
                coin->field0.field10.z = 0;
                coin->mBounceY = coin->field0.mCourseMapRow->field0.y + 0xe000;
                coin->mState = 2;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->field0.mFlags &= ~1;
            }
            break;
        case 5:
            n = coin->mModelAlpha + 1;
            if (n >= 31) {
                n = 31;
            }
            coin->mModelAlpha = n;
            if (coin->mScaleFactor < 0x1000) {
                coin->mScaleFactor += 0x29;
                if (coin->mScaleFactor > 0x1000) {
                    coin->mScaleFactor = 0x1000;
                }
            }
            coin_updateAnim(coin, 1);
            coin->field0.field10.y -= 0x333;
            VEC_Add(&coin->field0.mPos, &coin->field0.field10, &coin->field0.mPos);
            if (coin->field0.field10.y <= 0) {
                coin->mState = 6;
            }
            break;
        case 6:
            if (coin->mScaleFactor < 0x1000) {
                coin->mScaleFactor += 0x29;
                if (coin->mScaleFactor > 0x1000) {
                    coin->mScaleFactor = 0x1000;
                }
            }
            coin_updateAnim(coin, 1);
            if (coin->field0.mPos.x < coin->mTargetPos->x) {
                coin->field0.field10.x += 0x400;
            } else if (coin->field0.mPos.x > coin->mTargetPos->x) {
                coin->field0.field10.x -= 0x400;
            }
            if (coin->field0.mPos.y < coin->mTargetPos->y) {
                coin->field0.field10.y += 0x400;
            } else if (coin->field0.mPos.y > coin->mTargetPos->y) {
                coin->field0.field10.y -= 0x400;
            }
            if (coin->field0.mPos.z < coin->mTargetPos->z) {
                coin->field0.field10.z += 0x400;
            } else if (coin->field0.mPos.z > coin->mTargetPos->z) {
                coin->field0.field10.z -= 0x400;
            }
            VEC_Add(&coin->field0.mPos, &coin->field0.field10, &coin->field0.mPos);
            if (coin->mTimer-- <= 0) {
                coin->mTimer = 0;
                n = coin->mModelAlpha - 1;
                if (n <= 0) {
                    n = 0;
                }
                coin->mModelAlpha = n;
                if (coin->mModelAlpha < 1) {
                    coin->mState = 7;
                    coin->mScaleFactor = 0x1000;
                    coin->mModelAlpha = 0;
                    coin->mTargetPos = NULL;
                    coin->field0.mFlags |= data_ov001_021a6574;
                }
            }
            break;
        case 7:
            if (coin->mTargetPos != NULL) {
                n = coin->mModelAlpha + 2;
                if (n >= 31) {
                    n = 31;
                }
                coin->mModelAlpha = n;
            } else {
                n = coin->mModelAlpha - 2;
                if (n <= 0) {
                    n = 0;
                }
                coin->mModelAlpha = n;
            }
            if (coin->mModelAlpha != 0 && coin->mTargetPos != NULL) {
                coin_updateAnim(coin, 1);
                coin->field0.field10.y -= 0x14;
                VEC_Add(&coin->fieldEC, &coin->field0.field10, &coin->fieldEC);
                VEC_Add(&coin->fieldEC, coin->mTargetPos, &coin->field0.mPos);
                if ((s64) ((const Vec3 *) &coin->fieldEC)->x * ((const Vec3 *) &coin->fieldEC)->x +
                        (s64) ((const Vec3 *) &coin->fieldEC)->z * ((const Vec3 *) &coin->fieldEC)->z >=
                    0x190000000LL) {
                    coin->field0.field10.x = ((s64) coin->fieldEC.x * -0x14) >> 12;
                    coin->field0.field10.z = ((s64) coin->fieldEC.z * -0x14) >> 12;
                }
                if (coin->fieldEC.y < -0xa000) {
                    coin->field0.field10.y = 0x4cd;
                }
            }
            break;
        case 9:
            break;
    }
}

void coin_setupCollision(void) {
    mobj_createConfig(&coin_onDriverCollide, NULL, NULL, 1, 1);
}

void *coin_setupRenderPart(void) {
    return mobj_createRenderPart3d(coin_loadModel, coin_render, NULL);
}

void *coin_setupShadowRenderPart(void) {
    return mobj_createRenderPart3d(coin_globalInitShadow, coin_renderShadow, coin_globalPreRenderShadow);
}

void *coin_setupLogicPart(void) {
    return mobj_createLogicPart(coin_globalLogicInit, coin_update, coin_globalLogicPreUpdate);
}
