#include "Main/MapObjects/cover_poo_hole_cover_height.h"
#include "Main/MapObjects/flipper.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "code_02147cd8.h"
#include "01/Race/mission_run_state.h"

u32 SetFlipperState4TimerByIndex(u32 flipperIndex) {
    Flipper *flipper;
    flipper = GetMapObjectFromList(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_FLIPPER), flipperIndex);
    flipper->mState4Timer = 0xaa;
    return 1;
}

void InitCoverPooHole(MapObject *mapObject) {
    mapObject->mFlags |= gCoverPooHoleInitMapObjectFlag;
}

u32 CollideKartWithCoverPooHole(CoverPooHole *coverPooHole, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    s32 state;
    s32 itemEffect;
    u32 firstResponse = *firstResponsePtr;
    Vec3 effectPosition;
    s32 falloffIndex;
    u8 kartMask = 1 << kart->mIndex;
    SoundStartParams firstSoundParams;
    u8 secondResponse = *secondResponsePtr;
    SoundStartParams secondSoundParams;
    if (firstResponse == 3 || firstResponse == 4) {
        itemEffect = kart->mItemEffect;
        if (itemEffect != 1) {
            if (coverPooHole->mState == 4 || (coverPooHole->mState == 5 && coverPooHole->mCoverHeight > 0x7800)) {
                coverPooHole->mMapObject.mPosStep.x = 0;
                coverPooHole->mMapObject.mPosStep.y = 0x3800;
                coverPooHole->mMapObject.mPosStep.z = 0;
                return secondResponse;
            }
        }
        if ((((const CoverPooHole *) coverPooHole)->mKartHitMask & kartMask) == 0) {
            state = coverPooHole->mState;
            if (state == 0 || state == 3) {
                coverPooHole->mKartHitMask = coverPooHole->mKartHitMask | kartMask;
                if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST) {
                    if ((coverPooHole->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
                        if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (coverPooHole->mMapObject.mFarDistanceSquared ==
                                   gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        firstSoundParams.mSoundId = 0x16e;
                        firstSoundParams.mPositionSource = &coverPooHole->mMapObject.mPos;
                        firstSoundParams.mFalloffIndex = falloffIndex;
                        firstSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&coverPooHole->mMapObject.mPos);
                        StartSoundFromParams(&firstSoundParams);
                    }
                }
                coverPooHole->mMapObject.mDistanceSquaredAndFlags =
                    coverPooHole->mMapObject.mDistanceSquaredAndFlags | gCoverPooHoleSkipSoundFlag;
                return 0;
            }
            if (itemEffect == 1 && (state == 4 || (state == 5 && coverPooHole->mCoverHeight > 0x7800) || state == 1)) {
                coverPooHole->mKartHitMask = coverPooHole->mKartHitMask | kartMask;
                if ((coverPooHole->mMapObject.mFlags & 0x800) == 0 || kart->mIndex == gRaceSetup->mEntryIndex) {
                    coverPooHole->mHitState = COVER_POO_HOLE_HIT_THROWN;
                    coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
                    coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
                    coverPooHole->mHitCoverSpeed = 0x4000;
                    coverPooHole->mHitPooSpeed = 0x1333;
                    coverPooHole->mYawWobbleAngle = 0;
                    coverPooHole->mYawWobbleCenter = 0;
                    coverPooHole->mYawWobbleAmplitude = 0x2000;
                    coverPooHole->mYawWobbleAmplitudeChange = -0x40;
                    coverPooHole->mYawWobbleAngleStep = 0x200;
                    coverPooHole->mYawWobbleAngleStepChange = 0;
                    coverPooHole->mTiltWobbleAngle = 0;
                    coverPooHole->mTiltWobbleCenter = 0;
                    coverPooHole->mTiltWobbleAmplitude = 0x1000;
                    coverPooHole->mTiltWobbleAmplitudeChange = -0x30;
                    coverPooHole->mTiltWobbleAngleStep = 0x800;
                    coverPooHole->mTiltWobbleAngleStepChange = 0x100;
                    StartSoundIfKartStarOrKiller(&coverPooHole->mMapObject, kart);
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        effectPosition.x = (coverPooHole->mMapObject.mPos.x + kart->mPos.x) >> 1;
                        effectPosition.y = (coverPooHole->mMapObject.mPos.y + kart->mPos.y) >> 1;
                        effectPosition.z = (coverPooHole->mMapObject.mPos.z + kart->mPos.z) >> 1;
                        StartEffect(0x442, &effectPosition);
                        StartEffect(0x443, &effectPosition);
                        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                            AddMissionRunCountForMapObjectKind(coverPooHole->mMapObject.mKind);
                        }
                    }
                }
                if ((coverPooHole->mMapObject.mFlags & 0x800) == 0) {
                    if (coverPooHole->mState == 1) {
                        coverPooHole->mState = 6;
                    } else if (coverPooHole->mState == 4) {
                        coverPooHole->mState = 7;
                    }
                }
                coverPooHole->mMapObject.mPosStep.x = 0;
                coverPooHole->mMapObject.mPosStep.y = 0;
                coverPooHole->mMapObject.mPosStep.z = 0;
                return secondResponse;
            }
            if (state == 1) {
                coverPooHole->mKartHitMask = coverPooHole->mKartHitMask | kartMask;
                if ((coverPooHole->mMapObject.mFlags & 0x800) == 0 || kart->mIndex == gRaceSetup->mEntryIndex) {
                    coverPooHole->mHitState = COVER_POO_HOLE_HIT_THROWN;
                    coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
                    coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
                    coverPooHole->mHitCoverSpeed = 0;
                    coverPooHole->mHitPooSpeed = 0;
                    coverPooHole->mYawWobbleAngle = 0;
                    coverPooHole->mYawWobbleCenter = 0;
                    coverPooHole->mYawWobbleAmplitude = 0x2000;
                    coverPooHole->mYawWobbleAmplitudeChange = -0x40;
                    coverPooHole->mYawWobbleAngleStep = 0x200;
                    coverPooHole->mYawWobbleAngleStepChange = 0;
                    coverPooHole->mTiltWobbleAngle = 0;
                    coverPooHole->mTiltWobbleCenter = 0;
                    coverPooHole->mTiltWobbleAmplitude = 0x1000;
                    coverPooHole->mTiltWobbleAmplitudeChange = -0x30;
                    coverPooHole->mTiltWobbleAngleStep = 0x800;
                    coverPooHole->mTiltWobbleAngleStepChange = 0x100;
                    coverPooHole->mMapObject.mDistanceSquaredAndFlags =
                        coverPooHole->mMapObject.mDistanceSquaredAndFlags | gCoverPooHoleSkipSoundFlag;
                    if ((coverPooHole->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
                        if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (coverPooHole->mMapObject.mFarDistanceSquared ==
                                   gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        secondSoundParams.mSoundId = 0x16f;
                        secondSoundParams.mPositionSource = &coverPooHole->mMapObject.mPos;
                        secondSoundParams.mFalloffIndex = falloffIndex;
                        secondSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&coverPooHole->mMapObject.mPos);
                        StartSoundFromParams(&secondSoundParams);
                    }
                }
                if ((coverPooHole->mMapObject.mFlags & 0x800) == 0) {
                    coverPooHole->mState = 6;
                }
                coverPooHole->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(kart->mVelocity.x, -0x4cd);
                coverPooHole->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(kart->mVelocity.y, -0x4cd);
                coverPooHole->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(kart->mVelocity.z, -0x4cd);
                coverPooHole->mMapObject.mPosStep.y = 0x3800;
                return 12;
            }
        }
    }
    coverPooHole->mMapObject.mDistanceSquaredAndFlags =
        coverPooHole->mMapObject.mDistanceSquaredAndFlags | gCoverPooHoleSkipSoundFlag;
    coverPooHole->mMapObject.mPosStep.x = 0;
    coverPooHole->mMapObject.mPosStep.y = 0;
    coverPooHole->mMapObject.mPosStep.z = 0;
    return 0;
}

u32 CollideItemObjectWithCoverPooHole(CoverPooHole *coverPooHole, ItemObject *itemObject, u8 *firstResponsePtr,
                                      u8 *secondResponsePtr) {
    u8 firstResponse = *firstResponsePtr;
    u8 secondResponse = *secondResponsePtr;
    if (coverPooHole->mState != 4) {
        return 0;
    }
    if (firstResponse == 2) {
        coverPooHole->mHitState = COVER_POO_HOLE_HIT_THROWN;
        coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
        coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
        coverPooHole->mHitCoverSpeed = 0x4000;
        coverPooHole->mHitPooSpeed = 0x1333;
        coverPooHole->mMapObject.mPosStep.x = 0;
        coverPooHole->mMapObject.mPosStep.y = 0;
        coverPooHole->mMapObject.mPosStep.z = 0;
        coverPooHole->mYawWobbleAngle = 0;
        coverPooHole->mYawWobbleCenter = 0;
        coverPooHole->mYawWobbleAmplitude = 0x2000;
        coverPooHole->mYawWobbleAmplitudeChange = -0x40;
        coverPooHole->mYawWobbleAngleStep = 0x200;
        coverPooHole->mYawWobbleAngleStepChange = 0;
        coverPooHole->mTiltWobbleAngle = 0;
        coverPooHole->mTiltWobbleCenter = 0;
        coverPooHole->mTiltWobbleAmplitude = 0x1000;
        coverPooHole->mTiltWobbleAmplitudeChange = -0x30;
        coverPooHole->mTiltWobbleAngleStep = 0x800;
        coverPooHole->mTiltWobbleAngleStepChange = 0x100;
        coverPooHole->mMapObject.mDistanceSquaredAndFlags =
            coverPooHole->mMapObject.mDistanceSquaredAndFlags | gCoverPooHoleHitDistanceFlag;
        if ((coverPooHole->mMapObject.mFlags & 0x800) == 0) {
            coverPooHole->mState = 7;
        }
    }
    return secondResponse;
}

// FALSE when the position is out of reach, else TRUE with the vector c that pushes it out (zero in most states).
BOOL TryGetCoverPooHolePushOut(CoverPooHole *coverPooHole, const Vec3 *position, s32 radius, Vec3 *pushOut) {
    Vec3 offset;
    s32 distance;
    VEC_Subtract(position, &coverPooHole->mMapObject.mPos, &offset);
    if (offset.y >= coverPooHole->mCoverHeight + radius) {
        return FALSE;
    }
    distance = VEC_Mag(&offset);
    if (distance >= coverPooHole->mMapObject.mExtent.x + radius) {
        return FALSE;
    }
    if (coverPooHole->mState == 1) {
        pushOut->x = 0;
        pushOut->y = 0;
        pushOut->z = 0;
        return TRUE;
    }
    if (coverPooHole->mState == 4 || (coverPooHole->mState == 5 && coverPooHole->mCoverHeight > 0x7800)) {
        if (LENGTH_SQUARED(offset) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
        }
        distance = coverPooHole->mMapObject.mExtent.x + radius - distance;
        pushOut->x = MUL_FIXED12_NO_ROUND(offset.x, distance);
        pushOut->y = MUL_FIXED12_NO_ROUND(offset.y, distance);
        pushOut->z = MUL_FIXED12_NO_ROUND(offset.z, distance);
        return TRUE;
    }
    pushOut->x = 0;
    pushOut->y = 0;
    pushOut->z = 0;
    return TRUE;
}

void CreateCoverPooHole(void *mapObjectList) {
    gCover = CreateMapObjectModelNsbmd(mapObjectList, "cover.nsbmd");
    gPoo = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "poo.nsbmd", "poo.nsbtp");
    gHole = CreateMapObjectModelNsbmd(mapObjectList, "hole.nsbmd");
    SetMapObjectModelPolygonId(gPoo, 0x3f);
    SetMapObjectModelPolygonId(gHole, 0x3f);
}

void DrawCoverPooHole(void *mapObjectList, CoverPooHole *coverPooHole) {
    s32 restoreSlot;
    s32 popCount;
    s32 secondPopCount;
    MtxFx33 rotationMatrix;
    s32 holeTranslation[3];
    s32 pooHitTranslation[3];
    s32 pooTranslation[3];
    s32 coverHitTranslation[3];
    s32 coverTranslation[3];
    u16 yawAngle;
    s32 tiltTableIndex;
    s32 tiltSin;
    s32 coverBounce;
    s32 translationY;
    restoreSlot = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &restoreSlot, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    holeTranslation[1] = coverPooHole->mHoleHeight >> 4;
    holeTranslation[0] = 0;
    holeTranslation[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, holeTranslation, 3);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coverPooHole->mMapObject.mPos), 12);
    QueueMapObjectModelMaterial(mapObjectList, gHole);
    DrawMapObjectModel(mapObjectList, gHole, coverPooHole);
    popCount = 1;
    NNS_G3dGeBufferOP_N(0x12, &popCount, 1);
    switch (coverPooHole->mState) {
        case 1:
        case 2:
        case 6:
            SetMapObjectModelNsbtpFrameIndex(gPoo, 0);
            break;
        case 4:
        case 5:
        case 7:
            SetMapObjectModelNsbtpFrameIndex(gPoo, 1);
            break;
    }
    if (coverPooHole->mState != 0) {
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        if (coverPooHole->mHitState != COVER_POO_HOLE_HIT_NONE) {
            translationY = coverPooHole->mHitPooHeight >> 4;
            pooHitTranslation[0] = 0;
            pooHitTranslation[1] = translationY;
            pooHitTranslation[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, pooHitTranslation, 3);
        } else {
            translationY = coverPooHole->mPooHeight >> 4;
            pooTranslation[0] = 0;
            pooTranslation[1] = translationY;
            pooTranslation[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, pooTranslation, 3);
        }
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coverPooHole->mMapObject.mPos), 12);
        QueueMapObjectModelMaterial(mapObjectList, gPoo);
        DrawMapObjectModel(mapObjectList, gPoo, coverPooHole);
        secondPopCount = 1;
        NNS_G3dGeBufferOP_N(0x12, &secondPopCount, 1);
    }
    if (coverPooHole->mHitState == COVER_POO_HOLE_HIT_THROWN) {
        goto L;
    }
    if (coverPooHole->mHitState == COVER_POO_HOLE_HIT_WOBBLING) {
    L:
        yawAngle = coverPooHole->mYawWobbleOffset;
        tiltTableIndex = ((u16) coverPooHole->mTiltWobbleOffset >> 4) * 2;
        tiltSin = FX_SinCosTable_[tiltTableIndex];
        coverBounce = MUL_FIXED12_NO_ROUND(tiltSin, 0x7000);
        if (coverBounce <= 0) {
            coverBounce = -coverBounce;
        }
        translationY = coverPooHole->mHitCoverHeight + coverBounce;
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coverPooHole->mMapObject.mPos), 12);
        coverHitTranslation[1] = translationY >> 4;
        coverHitTranslation[0] = 0;
        coverHitTranslation[2] = 0;
        NNS_G3dGeBufferOP_N(0x1c, coverHitTranslation, 3);
        MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(yawAngle), COS_OF_ANGLE(yawAngle));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
        MTX_RotZ33_(&rotationMatrix, tiltSin, FX_SinCosTable_[tiltTableIndex + 1]);
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    } else {
        translationY = coverPooHole->mCoverHeight >> 4;
        coverTranslation[0] = 0;
        coverTranslation[1] = translationY;
        coverTranslation[2] = 0;
        NNS_G3dGeBufferOP_N(0x1c, coverTranslation, 3);
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coverPooHole->mMapObject.mPos), 12);
    }
    QueueMapObjectModelMaterial(mapObjectList, gCover);
    DrawMapObjectModel(mapObjectList, gCover, coverPooHole);
}

void InitCoverPooHoleObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    CoverPooHole *coverPooHole;
    RandomState64 *mapObjectRandom;
    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (coverPooHole = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        coverPooHole->mHoleHeight = 0x1000;
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        coverPooHole->mTimer = (u16) (coverPooHole->mMapObject.mCourseMapRow->mSettings[0] +
                                      (u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) - 30);
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            coverPooHole->mState = 3;
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
        } else {
            coverPooHole->mState = 0;
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
        }
    }
}

s32 CoverPooHoleFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 CoverPooHoleFX_MulInline(s32 value, s32 scale) {
    return MUL_FIXED12_ROUNDED(value, scale);
}

static inline u16 CoverPooHoleMapObjectRandomBelowU16(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * limit) >> 32);
}

static inline void StartCoverPooHoleSound(CoverPooHole *coverPooHole, s32 soundId) {
    SoundStartParams startParams;
    s32 falloffIndex;

    if (coverPooHole->mMapObject.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
        falloffIndex = 2;
    } else if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    startParams.mSoundId = soundId;
    startParams.mPositionSource = &coverPooHole->mMapObject.mPos;
    startParams.mFalloffIndex = falloffIndex;
    startParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&coverPooHole->mMapObject.mPos);
    StartSoundFromParams(&startParams);
}

void UpdateCoverPooHole(void *mapObjectList, CoverPooHole *coverPooHole) {
    s32 nextValue;

    coverPooHole->mMapObject.mPosStep.y = 0;
    switch (coverPooHole->mHitState) {
        case COVER_POO_HOLE_HIT_NONE:
            break;
        case COVER_POO_HOLE_HIT_THROWN:
            coverPooHole->mHitPooHeight += coverPooHole->mHitPooSpeed;
            coverPooHole->mHitPooSpeed -= 0x800;
            if (coverPooHole->mHitCoverHeight >= 0x2000) {
                coverPooHole->mHitCoverHeight += coverPooHole->mHitCoverSpeed;
                coverPooHole->mHitCoverSpeed -= 0x19a;
            } else {
                coverPooHole->mHitCoverHeight = 0x2000;
                coverPooHole->mHitState = COVER_POO_HOLE_HIT_WOBBLING;
                StartCoverPooHoleSound(coverPooHole, 0x16c);
            }
            break;
        case COVER_POO_HOLE_HIT_WOBBLING:
            if (coverPooHole->mHitPooHeight >= 0x2000) {
                coverPooHole->mHitPooHeight += coverPooHole->mHitPooSpeed;
                coverPooHole->mHitPooSpeed -= 0x800;
            }
            coverPooHole->mYawWobbleAngle += coverPooHole->mYawWobbleAngleStep;
            coverPooHole->mYawWobbleOffsetDelta =
                coverPooHole->mYawWobbleCenter +
                CoverPooHoleFX_MulInline(coverPooHole->mYawWobbleAmplitude,
                                         CoverPooHoleFX_SinIdx(coverPooHole->mYawWobbleAngle)) -
                coverPooHole->mYawWobbleOffset;
            coverPooHole->mYawWobbleOffset += coverPooHole->mYawWobbleOffsetDelta;
            if (coverPooHole->mYawWobbleAmplitude > 0) {
                nextValue = coverPooHole->mYawWobbleAmplitude + coverPooHole->mYawWobbleAmplitudeChange;
                if (nextValue <= 0) {
                    nextValue = 0;
                }
                coverPooHole->mYawWobbleAmplitude = nextValue;
            } else if (coverPooHole->mYawWobbleAmplitude < 0) {
                nextValue = coverPooHole->mYawWobbleAmplitude + coverPooHole->mYawWobbleAmplitudeChange;
                if (nextValue >= 0) {
                    nextValue = 0;
                }
                coverPooHole->mYawWobbleAmplitude = nextValue;
            }
            if (coverPooHole->mYawWobbleAngleStep > 0) {
                nextValue = coverPooHole->mYawWobbleAngleStep + coverPooHole->mYawWobbleAngleStepChange;
                if (nextValue <= 0) {
                    nextValue = 0;
                }
                coverPooHole->mYawWobbleAngleStep = nextValue;
            } else if (coverPooHole->mYawWobbleAngleStep < 0) {
                nextValue = coverPooHole->mYawWobbleAngleStep + coverPooHole->mYawWobbleAngleStepChange;
                if (nextValue >= 0) {
                    nextValue = 0;
                }
                coverPooHole->mYawWobbleAngleStep = nextValue;
            }
            coverPooHole->mTiltWobbleAngle += coverPooHole->mTiltWobbleAngleStep;
            coverPooHole->mTiltWobbleOffsetDelta =
                coverPooHole->mTiltWobbleCenter +
                CoverPooHoleFX_MulInline(coverPooHole->mTiltWobbleAmplitude,
                                         CoverPooHoleFX_SinIdx(coverPooHole->mTiltWobbleAngle)) -
                coverPooHole->mTiltWobbleOffset;
            coverPooHole->mTiltWobbleOffset += coverPooHole->mTiltWobbleOffsetDelta;
            if (coverPooHole->mTiltWobbleAmplitude > 0) {
                nextValue = coverPooHole->mTiltWobbleAmplitude + coverPooHole->mTiltWobbleAmplitudeChange;
                if (nextValue <= 0) {
                    nextValue = 0;
                }
                coverPooHole->mTiltWobbleAmplitude = nextValue;
            } else if (coverPooHole->mTiltWobbleAmplitude < 0) {
                nextValue = coverPooHole->mTiltWobbleAmplitude + coverPooHole->mTiltWobbleAmplitudeChange;
                if (nextValue >= 0) {
                    nextValue = 0;
                }
                coverPooHole->mTiltWobbleAmplitude = nextValue;
            }
            if (coverPooHole->mTiltWobbleAngleStep > 0) {
                nextValue = coverPooHole->mTiltWobbleAngleStep + coverPooHole->mTiltWobbleAngleStepChange;
                if (nextValue <= 0) {
                    nextValue = 0;
                }
                coverPooHole->mTiltWobbleAngleStep = nextValue;
            } else if (coverPooHole->mTiltWobbleAngleStep < 0) {
                nextValue = coverPooHole->mTiltWobbleAngleStep + coverPooHole->mTiltWobbleAngleStepChange;
                if (nextValue >= 0) {
                    nextValue = 0;
                }
                coverPooHole->mTiltWobbleAngleStep = nextValue;
            }
            if (coverPooHole->mTiltWobbleAmplitude == 0 && coverPooHole->mState != 2 && coverPooHole->mState != 5) {
                coverPooHole->mHitState = COVER_POO_HOLE_HIT_NONE;
            }
            break;
    }
    if ((coverPooHole->mState == 6 || coverPooHole->mState == 7) &&
        coverPooHole->mHitState == COVER_POO_HOLE_HIT_NONE) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            coverPooHole->mState = 3;
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
        } else {
            coverPooHole->mState = 0;
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
        }
    }
    switch (coverPooHole->mState) {
        case 0:
            if (coverPooHole->mTimer-- > 0) {
                return;
            }
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(30) + 30);
            coverPooHole->mState = 1;
            coverPooHole->mHitState = COVER_POO_HOLE_HIT_NONE;
            coverPooHole->mKartHitMask = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d3);
            break;
        case 1:
            if (coverPooHole->mCoverHeight < 0x7800) {
                coverPooHole->mCoverHeight += 0x400;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - 0xf000;
                return;
            }
            if (coverPooHole->mTimer-- > 0) {
                coverPooHole->mCoverHeight = 0x7800;
                coverPooHole->mPooHeight = -0x7800;
                return;
            }
            coverPooHole->mCoverHeight = 0x7800;
            coverPooHole->mPooHeight = -0x7800;
            coverPooHole->mState = 2;
            break;
        case 2:
            if (coverPooHole->mCoverHeight > 0x2000) {
                coverPooHole->mCoverHeight -= 0x400;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - 0xf000;
                return;
            }
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(15) + 15);
            coverPooHole->mState = 3;
            coverPooHole->mKartHitMask = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d4);
            break;
        case 3:
            if (coverPooHole->mTimer-- > 0) {
                return;
            }
            coverPooHole->mCoverHeight = 0x2000;
            coverPooHole->mPooHeight = -0xd000;
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(90) + 90);
            coverPooHole->mState = 4;
            coverPooHole->mHitState = COVER_POO_HOLE_HIT_NONE;
            coverPooHole->mKartHitMask = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d3);
            break;
        case 4:
            if (coverPooHole->mCoverHeight < 0x124cd) {
                coverPooHole->mCoverHeight += 0xc00;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - 0xf000;
                return;
            }
            if (coverPooHole->mTimer-- > 0) {
                coverPooHole->mCoverHeight = 0x124cd;
                coverPooHole->mPooHeight = 0x34cd;
                return;
            }
            coverPooHole->mCoverHeight = 0x124cd;
            coverPooHole->mPooHeight = 0x34cd;
            coverPooHole->mState = 5;
            break;
        case 5:
            if (coverPooHole->mCoverHeight > 0x2000) {
                coverPooHole->mCoverHeight -= 0xc00;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - 0xf000;
                return;
            }
            coverPooHole->mTimer = (u16) (coverPooHole->mMapObject.mCourseMapRow->mSettings[0] +
                                          CoverPooHoleMapObjectRandomBelowU16(60) - 30);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                coverPooHole->mState = 3;
                coverPooHole->mCoverHeight = 0x2000;
                coverPooHole->mPooHeight = -0xd000;
            } else {
                coverPooHole->mState = 0;
                coverPooHole->mCoverHeight = 0x2000;
                coverPooHole->mPooHeight = -0xd000;
            }
            coverPooHole->mKartHitMask = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d4);
            break;
    }
}

MapObjectKindData *CreateCoverPooHoleKindData(void) {
    MapObjectKindData *kindData;
    kindData = CreateMapObjectKindDataWithSound(CollideKartWithCoverPooHole, CollideItemObjectWithCoverPooHole,
                                                TryGetCoverPooHolePushOut, 0, 1, 0x16d);
    kindData->mCollideItemObjectSoundId = 0x1b0;
    return kindData;
}

MapObjectList *CreateCoverPooHoleDrawList(void) {
    return CreateMapObjectDrawList2(CreateCoverPooHole, DrawCoverPooHole, NULL);
}

MapObjectList *CreateCoverPooHoleUpdateList(void) {
    return CreateMapObjectUpdateList(InitCoverPooHoleObjects, UpdateCoverPooHole, NULL);
}

BOOL IsCoverPooHoleState1Or4(CoverPooHole *coverPooHole) {
    if (coverPooHole->mState == 1 || coverPooHole->mState == 4) {
        return TRUE;
    }
    return FALSE;
}

s32 GetCoverPooHoleHitCoverHeight(CoverPooHole *object) {
    return object->mHitCoverHeight;
}

const u32 gCoverPooHoleSkipSoundFlag = 0x40000000;
const u32 gCoverPooHoleHitDistanceFlag = 0x80000000;
const u16 gNsKiller2InitMapObjectFlag = 0x200;
MapObjectModel *gPoo;
MapObjectModel *gCover;
MapObjectModel *gHole;

MapObjectKindDescriptor gCoverPooHoleKindDescriptor = {0,
                                                       {0, 0},
                                                       0x10c,
                                                       (void (*)(void *, CourseMapRow *, void *)) InitCoverPooHole,
                                                       CreateCoverPooHoleKindData,
                                                       CreateCoverPooHoleDrawList,
                                                       0,
                                                       0,
                                                       CreateCoverPooHoleUpdateList};
