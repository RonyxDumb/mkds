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

MapObjectModel *data_ov001_021a9b98;

void StartCoinRiseOverKart(Coin *coin, Kart *kart) {
    coin->mTimer = 0x1e;
    coin->mUnk_000.mPos.x = kart->mPos.x;
    coin->mUnk_000.mPos.y = kart->mPos.y + 0xc000;
    coin->mUnk_000.mPos.z = kart->mPos.z;
    coin->mUnk_000.mPosStep.y = 0x3000;
    coin->mState = 1;
    coin->mScaleFactor = 0x99a;
    coin->mModelAlpha = 0x1f;
    coin->mUnk_000.mFlags = coin->mUnk_000.mFlags | data_ov001_021a6574;
    coin->mEffect = StartEffect(0x3f5, &coin->mUnk_000.mPos);
    coin->mEffectTimer = 0xd;
}

void AdvanceCoinNsbtpFrame(Coin *coin, s32 counterAdd) {
    coin->mUnk_0a8 += counterAdd;
    if (coin->mUnk_0a8 >= 5) {
        coin->mUnk_0a8 -= 5;
        coin->mNsbtpFrameIndex += 1;
        if (coin->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(data_ov001_021a9b98)) {
            coin->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(data_ov001_021a9b98);
        }
    }
}

void StartCoinCountUp(void) {
    Kart *kart;
    Coin *coin;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(0x68));
    if (coin != NULL) {
        StartCoinRiseOverKart(coin, kart);
    }
}

void StartCoinDrop(void) {
    Kart *kart;
    Coin *coin;
    RandomState64 *random;
    s32 angle;
    s32 speed;
    SoundStartParams soundArg;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(0x68));
    if (coin != NULL) {
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        angle = (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32);
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        speed = (u32) (((u64) (u32) (random->mValue >> 32) * 0x800) >> 32) + 0x800;
        coin->mState = 3;
        coin->mScaleFactor = 0x99a;
        coin->mModelAlpha = 0x10;
        coin->mUnk_000.mPos.x = kart->mPos.x;
        coin->mUnk_000.mPos.y = kart->mPos.y + 0x1a000;
        coin->mUnk_000.mPos.z = kart->mPos.z;
        coin->mUnk_000.mPosStep.x = kart->mVelocity.x + MUL_FIXED12_NO_ROUND(speed, FX_SinIdx(angle));
        coin->mUnk_000.mPosStep.y = kart->mVelocity.y + 0x4000;
        coin->mUnk_000.mPosStep.z = kart->mVelocity.z + MUL_FIXED12_NO_ROUND(speed, FX_CosIdx(angle));
        coin->mUnk_000.mFlags &= ~1;
        soundArg.mSoundId = 0x1d9;
        soundArg.mPositionSource = NULL;
        soundArg.mFalloffIndex = 2;
        soundArg.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        StartSoundFromParams(&soundArg);
    }
}

void StartCoinBossTransfer(void) {
    Kart *kart;
    Coin *coin;
    RandomState64 *random;
    s32 angle;
    s32 speed;
    u8 kartCount;
    Unk02188950 *targetObject;
    SoundStartParams soundArg;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(0x68));
    if (coin != NULL) {
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        angle = (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32);
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        speed = (u32) (((u64) (u32) (random->mValue >> 32) * 0x800) >> 32) + 0x800;
        coin->mState = 5;
        coin->mScaleFactor = 0x99a;
        coin->mModelAlpha = 0x10;
        coin->mTimer = 0x1e;
        targetObject = NULL;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            kartCount = 0;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                kartCount = MissionRunGetCurrentKartCount();
            }
            targetObject = GetMissionRunMapObject(kartCount);
        }
        coin->mTargetPos = &targetObject->mUnk_000.mPos;
        coin->mUnk_000.mPos.x = kart->mPos.x;
        coin->mUnk_000.mPos.y = kart->mPos.y + 0x1a000;
        coin->mUnk_000.mPos.z = kart->mPos.z;
        coin->mUnk_000.mPosStep.x = MUL_FIXED12_NO_ROUND(speed, FX_SinIdx(angle));
        coin->mUnk_000.mPosStep.y = 0x4000;
        coin->mUnk_000.mPosStep.z = MUL_FIXED12_NO_ROUND(speed, FX_CosIdx(angle));
        soundArg.mSoundId = 0x1d9;
        soundArg.mPositionSource = NULL;
        soundArg.mFalloffIndex = 2;
        soundArg.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        StartSoundFromParams(&soundArg);
    }
}

void AddPendingBossTransferInMissionRun(u32 amount) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingBossTransfer(amount);
    }
}

void SetBossCoinShownCount(s32 shownCount) {
    int coinIndex;
    s32 foundCount;
    MapObjectList *coinList;
    Coin *coin;
    RandomState64 *random;
    u16 angle;

    foundCount = 0;
    coinList = FindMapObjectKindUpdateList(0x68);
    GetKart((u16) gRaceSetup->mEntryIndex);
    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            if (coin->mState == 7) {
                foundCount++;
                if (foundCount <= shownCount) {
                    if (coin->mTargetPos == NULL) {
                        random = GetMapObjectRandom();
                        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
                        angle = ((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32;
                        coin->mScaleFactor = 0x1000;
                        coin->mModelAlpha = 0;
                        coin->mTargetPos =
                            (Vec3 *) ((gRaceSetup->mMode == MODE_MISSION_RUN
                                           ? (u32) GetMissionRunMapObject(gRaceSetup->mMode == MODE_MISSION_RUN
                                                                              ? MissionRunGetCurrentKartCount()
                                                                              : 0)
                                           : 0) +
                                      4);
                        coin->mUnk_000.mPos.x = coin->mTargetPos->x;
                        coin->mUnk_000.mPos.y = coin->mTargetPos->y;
                        coin->mUnk_000.mPos.z = coin->mTargetPos->z;
                        coin->mUnk_000.mPosStep.x = 0;
                        coin->mUnk_000.mPosStep.y = 0x4cd;
                        coin->mUnk_000.mPosStep.z = 0;
                        coin->mUnk_0ec.x = MUL_FIXED12_NO_ROUND(SIN_OF_ANGLE(angle), 0x14000);
                        coin->mUnk_0ec.y = -0xa000;
                        coin->mUnk_0ec.z = MUL_FIXED12_NO_ROUND(COS_OF_ANGLE(angle), 0x14000);
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

void ParkBossCoins(s32 parkCount) {
    MapObjectList *coinList;
    Coin *coin;
    s32 count;
    int coinIndex;

    count = 0;
    coinList = FindMapObjectKindUpdateList(0x68);
    GetKart((u16) gRaceSetup->mEntryIndex);
    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            if (coin->mState == 7) {
                if (coin->mTargetPos != NULL) {
                    coin->mTargetPos = NULL;
                }
                count++;
                if (count <= parkCount) {
                    if ((coin->mUnk_000.mFlags & 0x100) == 0) {
                        ParkMapObject(&coin->mUnk_000);
                    }
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        AddMissionRunPendingCountUpFromBoss(1);
                    }
                }
            }
        }
    }
}

void StartCoinsFadeOut(void) {
    int coinIndex;
    Coin *coin;
    MapObjectList *coinList;
    NNSSndSeqPlayer **sndHandleSlot;

    coinList = FindMapObjectKindUpdateList(0x68);
    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            if (coin->mState == 0 && (coin->mUnk_000.mFlags & 0x100) == 0) {
                coin->mUnk_000.mPosStep.y = 0x5000;
                coin->mModelAlpha = 0x32;
                coin->mState = 8;
                coin->mUnk_000.mFlags |= data_ov001_021a6574;
            }
        }
    }
    sndHandleSlot = GetSndHandleSlot(2);
    if ((gRaceSoundKind & 1) && gSoundModeHolder.mSeqStartEnabled != 0) {
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x233);
    }
}

void StartCoinsFadeIn(void) {
    int coinIndex;
    Coin *coin;
    MapObjectList *coinList;
    NNSSndSeqPlayer **sndHandleSlot;

    coinList = FindMapObjectKindUpdateList(0x68);
    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            if (coin->mState == 9 && (coin->mUnk_000.mFlags & 0x100) == 0) {
                coin->mUnk_000.mPos.x = coin->mUnk_000.mCourseMapRow->mPosition.x;
                coin->mUnk_000.mPos.y = coin->mUnk_000.mCourseMapRow->mPosition.y + 0xa000;
                coin->mUnk_000.mPos.z = coin->mUnk_000.mCourseMapRow->mPosition.z;
                coin->mUnk_000.mPosStep.x = 0;
                coin->mUnk_000.mPosStep.y = 0x5000;
                coin->mUnk_000.mPosStep.z = 0;
                coin->mBounceY = coin->mUnk_000.mCourseMapRow->mPosition.y + 0xe000;
                coin->mState = 2;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->mUnk_000.mFlags &= ~1;
            }
        }
    }
    sndHandleSlot = GetSndHandleSlot(2);
    if ((gRaceSoundKind & 1) && gSoundModeHolder.mSeqStartEnabled != 0) {
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x232);
    }
}

void SetMissionRunCoinCallbacks(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        SetMissionRunCountUpCallback(StartCoinCountUp);
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        SetMissionRunDropCallback(StartCoinDrop);
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        SetMissionRunBossTransferCallback(StartCoinBossTransfer);
    }
}

u8 CollideKartWithCoin(Coin *coin, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    u8 firstResponse = *firstResponsePtr;
    u8 secondResponse = *secondResponsePtr;

    if (kart->mUnk_48 & KART_48_OBJECTS_SKIP) {
        return 0;
    }
    if (firstResponse == 1) {
        if (coin->mState != 3 && coin->mState != 5 && coin->mState != 6) {
            ParkMapObject(&coin->mUnk_000);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunPendingCountUp(1);
            }
        }
    }
    return secondResponse;
}

void LoadCoin(MapObjectList *drawList) {
    data_ov001_021a9b98 = LoadMapObjectModelAnimated(drawList, data_ov001_021a78c0);
    LoadMapObjectModelNsbtpAnimation(data_ov001_021a9b98, data_ov001_021a78cc);
    SetMapObjectModelPolygonId(data_ov001_021a9b98, 0x3f);
    SetMapObjectModelLightEnableFlag(data_ov001_021a9b98, 2);
    SetNsbmdEmiAll(data_ov001_021a9b98->mAnimatedModel, 0x294a);
    drawList->mSortByDistance = 1;
}

void DrawCoin(void *mapObjectList, Coin *coin) {
    s32 gxArgument;
    Vec3 scale;
    u32 alpha;
    s32 scaleFactor;

    if (coin->mScaleFactor > 0 && coin->mModelAlpha != 0) {
        gxArgument = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, (&gxArgument), 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coin->mUnk_000.mPos), 0xc);
        scaleFactor = coin->mScaleFactor;
        if (scaleFactor != 0x1000) {
            scale.x = scaleFactor;
            scale.y = scaleFactor;
            scale.z = scaleFactor;
            NNS_G3dGeBufferOP_N(0x1b, (&scale), 3);
        }
        NNS_G3dGeBufferOP_N(0x1b, (&coin->mUnk_000.mScale), 3);
        SetMapObjectModelPolygonId(data_ov001_021a9b98, AllocPolygonIdWrapping());
        alpha = coin->mModelAlpha;
        if (alpha >= 0x1f) {
            alpha = 0x1f;
        }
        SetMapObjectModelAlpha(data_ov001_021a9b98, alpha);
        SetMapObjectModelNsbtpFrameIndex(data_ov001_021a9b98, coin->mNsbtpFrameIndex);
        QueueMapObjectModelMaterial(mapObjectList, data_ov001_021a9b98);
        DrawMapObjectModel(mapObjectList, data_ov001_021a9b98, coin);
    }
}

void InitCoinObjects(MapObjectList *coinList) {
    int coinIndex;
    Coin *coin;
    s32 speed;

    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            coin->mUnk_0d8 = coin->mUnk_000.mCourseMapRow->mPosition;
            coin->mUnk_000.mPos = coin->mUnk_0d8;
            coin->mUnk_000.mPos.y = coin->mUnk_000.mPos.y + 0xe000;
            if (coin->mUnk_000.mCourseMapRow->mGroupIndex >= 0) {
                InitGroupFollower(&coin->mFollower, coin->mUnk_000.mCourseMapRow, 0);
                speed = (coin->mUnk_000.mCourseMapRow->mSettings[0] << 12) / 100;
                coin->mFollower.mSpeed = speed;
                coin->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                    speed, coin->mFollower.mPath->mSegments[coin->mFollower.mSegmentIndex].mInverseProgressLength);
            } else {
                coin->mFollower.mGroupIndex = 0xffff;
            }
            coin->mScaleFactor = 0x1000;
            if (coin->mUnk_000.mCourseMapRow->mSettings[1] == 0) {
                coin->mModelAlpha = 0x1f;
            } else {
                coin->mModelAlpha = 0;
            }
        }
    }
}

void CoinBeforeObjectsNop(void) {}

void UpdateCoin(void *mapObjectList, Coin *coin) {
    s32 newAlpha;
    switch (coin->mState) {
        case 2:
            newAlpha = coin->mModelAlpha + 1;
            if (newAlpha >= 31) {
                newAlpha = 31;
            }
            coin->mModelAlpha = newAlpha;
            AdvanceCoinNsbtpFrame(coin, 1);
            coin->mUnk_000.mPosStep.y -= 0x333;
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mPosStep, &coin->mUnk_000.mPos);
            if (coin->mUnk_000.mPos.y <= coin->mBounceY) {
                coin->mUnk_000.mPos.y = coin->mBounceY;
                if (coin->mUnk_000.mPosStep.y <= 0) {
                    coin->mUnk_000.mPosStep.y = MUL_FIXED12_NO_ROUND(coin->mUnk_000.mPosStep.y, -0x800);
                    if (coin->mUnk_000.mPosStep.y < 0x1000) {
                        coin->mUnk_000.mPosStep.x = 0;
                        coin->mUnk_000.mPosStep.y = 0;
                        coin->mUnk_000.mPosStep.z = 0;
                        coin->mState = 0;
                    }
                    StartSoundAtPositionIfNear(0x1d8, &coin->mUnk_000.mPos, 2);
                }
            }
            break;
        case 0: {
            u16 radius;
            s32 kartIndex;
            BOOL found;
            Vec3 *kartPos;
            s32 dx;
            s32 dz;
            AdvanceCoinNsbtpFrame(coin, 1);
            if (coin->mFollower.mGroupIndex != 0xffff) {
                AdvanceGroupFollower(&coin->mFollower);
                GetGroupFollowerCurvePosStep(&coin->mFollower, &coin->mUnk_000.mPos, &coin->mUnk_000.mPosStep);
                coin->mUnk_000.mPos.y += 0xe000;
                coin->mUnk_0d8 = coin->mUnk_000.mPos;
            } else {
                coin->mUnk_000.mPosStep.x = 0;
                coin->mUnk_000.mPosStep.y = 0;
                coin->mUnk_000.mPosStep.z = 0;
            }
            if (coin->mUnk_000.mCourseMapRow->mSettings[1] != 0) {
                radius = coin->mUnk_000.mCourseMapRow->mSettings[1];
                for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
                    kartPos = &GetKart((u16) kartIndex)->mPos;
                    dx = kartPos->x - coin->mUnk_000.mPos.x;
                    dz = kartPos->z - coin->mUnk_000.mPos.z;
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
            newAlpha = coin->mModelAlpha + 1;
            if (newAlpha >= 31) {
                newAlpha = 31;
            }
            coin->mModelAlpha = newAlpha;
            break;
        skip:
            coin->mModelAlpha = 0;
            break;
        }
        case 8:
            newAlpha = coin->mModelAlpha - 1;
            if (newAlpha <= 0) {
                newAlpha = 0;
            }
            coin->mModelAlpha = newAlpha;
            AdvanceCoinNsbtpFrame(coin, 4);
            coin->mUnk_000.mPos.y += coin->mUnk_000.mPosStep.y;
            coin->mUnk_000.mPosStep.y -= 0x333;
            if (coin->mModelAlpha == 0) {
                coin->mState = 9;
            }
            break;
        case 1: {
            Kart *kart;
            newAlpha = coin->mModelAlpha - 1;
            if (newAlpha <= 0) {
                newAlpha = 0;
            }
            coin->mModelAlpha = newAlpha;
            AdvanceCoinNsbtpFrame(coin, 4);
            kart = GetKart((u16) gRaceSetup->mEntryIndex);
            coin->mUnk_000.mPos.x = kart->mPos.x;
            coin->mUnk_000.mPos.y += coin->mUnk_000.mPosStep.y;
            coin->mUnk_000.mPos.z = kart->mPos.z;
            coin->mUnk_000.mPosStep.y -= 0x333;
            if (coin->mTimer-- <= 0) {
                ParkMapObject(&coin->mUnk_000);
            } else if (coin->mTimer == 3) {
                SetupKartFollowEffect(StartEffect(0x3f4, &kart->mPos), kart->mIndex, 0x18);
            }
            if (coin->mEffect != NULL) {
                PlaceEffect(coin->mEffect, &coin->mUnk_000.mPos);
                if (coin->mEffectTimer-- < 0) {
                    StopEffectAndClearPointer(&coin->mEffect);
                }
            }
            break;
        }
        case 3: {
            u32 collisionBits;
            Vec3 spherePosition;
            Vec3 pushOut;
            Vec3 normal;
            Vec3 secondNormal;
            newAlpha = coin->mModelAlpha + 1;
            if (newAlpha >= 31) {
                newAlpha = 31;
            }
            coin->mModelAlpha = newAlpha;
            if (coin->mScaleFactor < 0x1000) {
                coin->mScaleFactor += 0x29;
                if (coin->mScaleFactor > 0x1000) {
                    coin->mScaleFactor = 0x1000;
                }
            }
            AdvanceCoinNsbtpFrame(coin, 1);
            coin->mUnk_000.mPosStep.y -= 0x333;
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mPosStep, &coin->mUnk_000.mPos);
            spherePosition.x = coin->mUnk_000.mPos.x;
            spherePosition.y = coin->mUnk_000.mExtent.x + (coin->mUnk_000.mPos.y - 0xe000);
            spherePosition.z = coin->mUnk_000.mPos.z;
            if (CollideSphereWithMapObjects(&spherePosition, &coin->mUnk_000.mPosStep, coin->mUnk_000.mExtent.x,
                                            coin->mUnk_000.mCollisionSlotIndex, 2, &pushOut) != 0) {
                VEC_Add(&coin->mUnk_000.mPos, &pushOut, &coin->mUnk_000.mPos);
                if (LENGTH_SQUARED(pushOut) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&pushOut, &coin->mUnk_000.mPosStep);
                }
                coin->mUnk_000.mPosStep.x = MUL_FIXED12_NO_ROUND(coin->mUnk_000.mPosStep.x, 0x1400);
                coin->mUnk_000.mPosStep.y = MUL_FIXED12_NO_ROUND(coin->mUnk_000.mPosStep.y, 0x1400);
                coin->mUnk_000.mPosStep.z = MUL_FIXED12_NO_ROUND(coin->mUnk_000.mPosStep.z, 0x1400);
            }
            if (CollideSphereWithCourse(&spherePosition, NULL, 0, coin->mUnk_000.mExtent.x, 1,
                                        coin->mUnk_000.mCollisionSlotIndex, &pushOut, &normal, &secondNormal,
                                        &collisionBits, NULL, NULL, NULL, NULL) != 0) {
                VEC_Add(&coin->mUnk_000.mPos, &pushOut, &coin->mUnk_000.mPos);
                if (collisionBits & 0x214300) {
                    BounceVelocityOffSurface(&coin->mUnk_000.mPosStep, &secondNormal, 0x1000, 0x1000, 0xc00,
                                             &coin->mUnk_000.mPosStep);
                    if ((s64) coin->mUnk_000.mPosStep.x * coin->mUnk_000.mPosStep.x +
                            (s64) coin->mUnk_000.mPosStep.y * coin->mUnk_000.mPosStep.y +
                            (s64) coin->mUnk_000.mPosStep.z * coin->mUnk_000.mPosStep.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&coin->mUnk_000.mPosStep, &coin->mUnk_000.mPosStep);
                    }
                    coin->mUnk_000.mPosStep.x = MUL_FIXED12_NO_ROUND(coin->mUnk_000.mPosStep.x, 0x1400);
                    coin->mUnk_000.mPosStep.y = MUL_FIXED12_NO_ROUND(coin->mUnk_000.mPosStep.y, 0x1400);
                    coin->mUnk_000.mPosStep.z = MUL_FIXED12_NO_ROUND(coin->mUnk_000.mPosStep.z, 0x1400);
                }
                if ((collisionBits & 0x1e34ef) && coin->mUnk_000.mPosStep.y <= 0) {
                    coin->mUnk_000.mPosStep.y = MUL_FIXED12_NO_ROUND(coin->mUnk_000.mPosStep.y, -0x800);
                    if (coin->mUnk_000.mPosStep.y < 0x1000) {
                        coin->mUnk_000.mPosStep.x = 0;
                        coin->mUnk_000.mPosStep.y = 0;
                        coin->mUnk_000.mPosStep.z = 0;
                        coin->mState = 0;
                    }
                    StartSoundAtPositionIfNear(0x1d8, &coin->mUnk_000.mPos, 2);
                }
                if ((collisionBits & 0x800) || coin->mUnk_000.mPos.y < 0) {
                    coin->mState = 4;
                }
            }
            coin->mUnk_0d8.x = coin->mUnk_000.mPos.x;
            coin->mUnk_0d8.z = coin->mUnk_000.mPos.z;
            break;
        }
        case 4:
            AdvanceCoinNsbtpFrame(coin, 1);
            coin->mUnk_000.mPosStep.y -= 0x333;
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mPosStep, &coin->mUnk_000.mPos);
            newAlpha = coin->mModelAlpha - 1;
            if (newAlpha > 0) {
                coin->mModelAlpha = newAlpha;
                break;
            }
            if (coin->mUnk_000.mCourseMapRow->mSettings[2] != 0) {
                coin->mState = 7;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->mUnk_000.mFlags |= data_ov001_021a6574;
                if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                    AddMissionRunBossCount(1);
                }
            } else {
                coin->mUnk_000.mPos.x = coin->mUnk_000.mCourseMapRow->mPosition.x;
                coin->mUnk_000.mPos.y = coin->mUnk_000.mCourseMapRow->mPosition.y + 0x64000;
                coin->mUnk_000.mPos.z = coin->mUnk_000.mCourseMapRow->mPosition.z;
                coin->mUnk_000.mPosStep.x = 0;
                coin->mUnk_000.mPosStep.y = 0;
                coin->mUnk_000.mPosStep.z = 0;
                coin->mBounceY = coin->mUnk_000.mCourseMapRow->mPosition.y + 0xe000;
                coin->mState = 2;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->mUnk_000.mFlags &= ~1;
            }
            break;
        case 5:
            newAlpha = coin->mModelAlpha + 1;
            if (newAlpha >= 31) {
                newAlpha = 31;
            }
            coin->mModelAlpha = newAlpha;
            if (coin->mScaleFactor < 0x1000) {
                coin->mScaleFactor += 0x29;
                if (coin->mScaleFactor > 0x1000) {
                    coin->mScaleFactor = 0x1000;
                }
            }
            AdvanceCoinNsbtpFrame(coin, 1);
            coin->mUnk_000.mPosStep.y -= 0x333;
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mPosStep, &coin->mUnk_000.mPos);
            if (coin->mUnk_000.mPosStep.y <= 0) {
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
            AdvanceCoinNsbtpFrame(coin, 1);
            if (coin->mUnk_000.mPos.x < coin->mTargetPos->x) {
                coin->mUnk_000.mPosStep.x += 0x400;
            } else if (coin->mUnk_000.mPos.x > coin->mTargetPos->x) {
                coin->mUnk_000.mPosStep.x -= 0x400;
            }
            if (coin->mUnk_000.mPos.y < coin->mTargetPos->y) {
                coin->mUnk_000.mPosStep.y += 0x400;
            } else if (coin->mUnk_000.mPos.y > coin->mTargetPos->y) {
                coin->mUnk_000.mPosStep.y -= 0x400;
            }
            if (coin->mUnk_000.mPos.z < coin->mTargetPos->z) {
                coin->mUnk_000.mPosStep.z += 0x400;
            } else if (coin->mUnk_000.mPos.z > coin->mTargetPos->z) {
                coin->mUnk_000.mPosStep.z -= 0x400;
            }
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mPosStep, &coin->mUnk_000.mPos);
            if (coin->mTimer-- <= 0) {
                coin->mTimer = 0;
                newAlpha = coin->mModelAlpha - 1;
                if (newAlpha <= 0) {
                    newAlpha = 0;
                }
                coin->mModelAlpha = newAlpha;
                if (coin->mModelAlpha < 1) {
                    coin->mState = 7;
                    coin->mScaleFactor = 0x1000;
                    coin->mModelAlpha = 0;
                    coin->mTargetPos = NULL;
                    coin->mUnk_000.mFlags |= data_ov001_021a6574;
                }
            }
            break;
        case 7:
            if (coin->mTargetPos != NULL) {
                newAlpha = coin->mModelAlpha + 2;
                if (newAlpha >= 31) {
                    newAlpha = 31;
                }
                coin->mModelAlpha = newAlpha;
            } else {
                newAlpha = coin->mModelAlpha - 2;
                if (newAlpha <= 0) {
                    newAlpha = 0;
                }
                coin->mModelAlpha = newAlpha;
            }
            if (coin->mModelAlpha != 0 && coin->mTargetPos != NULL) {
                AdvanceCoinNsbtpFrame(coin, 1);
                coin->mUnk_000.mPosStep.y -= 0x14;
                VEC_Add(&coin->mUnk_0ec, &coin->mUnk_000.mPosStep, &coin->mUnk_0ec);
                VEC_Add(&coin->mUnk_0ec, coin->mTargetPos, &coin->mUnk_000.mPos);
                if ((s64) ((const Vec3 *) &coin->mUnk_0ec)->x * ((const Vec3 *) &coin->mUnk_0ec)->x +
                        (s64) ((const Vec3 *) &coin->mUnk_0ec)->z * ((const Vec3 *) &coin->mUnk_0ec)->z >=
                    0x190000000LL) {
                    coin->mUnk_000.mPosStep.x = MUL_FIXED12_NO_ROUND(coin->mUnk_0ec.x, -0x14);
                    coin->mUnk_000.mPosStep.z = MUL_FIXED12_NO_ROUND(coin->mUnk_0ec.z, -0x14);
                }
                if (coin->mUnk_0ec.y < -0xa000) {
                    coin->mUnk_000.mPosStep.y = 0x4cd;
                }
            }
            break;
        case 9:
            break;
    }
}

void CreateCoinKindData(void) {
    CreateMapObjectKindData(&CollideKartWithCoin, NULL, NULL, 1, 1);
}

void *CreateCoinDrawList(void) {
    return CreateMapObjectDrawList1(LoadCoin, DrawCoin, NULL);
}

void *CreateCoinShadowDrawList(void) {
    return CreateMapObjectDrawList1(ResetCoinShadowRotationIndex, DrawCoinShadow, AdvanceCoinShadowRotationIndex);
}

void *CreateCoinUpdateList(void) {
    return CreateMapObjectUpdateList(InitCoinObjects, UpdateCoin, CoinBeforeObjectsNop);
}
