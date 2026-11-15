#include "Main/MapObjects/cover_poo_hole_cover_height.h"
#include "Main/MapObjects/flipper.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "code_02147cd8.h"
#include "01/Race/mission_run_state.h"

u32 SetFlipperAltWaitTimerByIndex(u32 flipperIndex) {
    Flipper *flipper;
    flipper = GetMapObjectFromList(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_FLIPPER), flipperIndex);
    flipper->mAltWaitFrames = FLIPPER_ALT_WAIT_FRAMES;
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
            if (coverPooHole->mState == COVER_POO_HOLE_STATE_RAISE_TALL ||
                (coverPooHole->mState == COVER_POO_HOLE_STATE_LOWER_TALL &&
                 coverPooHole->mCoverHeight > COVER_POO_HOLE_SHORT_HEIGHT)) {
                coverPooHole->mMapObject.mPosStep.x = 0;
                coverPooHole->mMapObject.mPosStep.y = 0x3800;
                coverPooHole->mMapObject.mPosStep.z = 0;
                return secondResponse;
            }
        }
        if ((((const CoverPooHole *) coverPooHole)->mKartHitMask & kartMask) == 0) {
            state = coverPooHole->mState;
            if (state == COVER_POO_HOLE_STATE_WAIT_SHORT || state == COVER_POO_HOLE_STATE_WAIT_TALL) {
                coverPooHole->mKartHitMask = coverPooHole->mKartHitMask | kartMask;
                if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST) {
                    if ((coverPooHole->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) ==
                        0) {
                        if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (coverPooHole->mMapObject.mFarDistanceSquared ==
                                   gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        firstSoundParams.mSoundId = COVER_POO_HOLE_KART_HIT_SOUND_ID;
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
            if (itemEffect == 1 && (state == COVER_POO_HOLE_STATE_RAISE_TALL ||
                                    (state == COVER_POO_HOLE_STATE_LOWER_TALL &&
                                     coverPooHole->mCoverHeight > COVER_POO_HOLE_SHORT_HEIGHT) ||
                                    state == COVER_POO_HOLE_STATE_RAISE_SHORT)) {
                coverPooHole->mKartHitMask = coverPooHole->mKartHitMask | kartMask;
                if ((coverPooHole->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) == 0 ||
                    kart->mIndex == gRaceSetup->mEntryIndex) {
                    coverPooHole->mHitState = COVER_POO_HOLE_HIT_THROWN;
                    coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
                    coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
                    coverPooHole->mHitCoverSpeed = COVER_POO_HOLE_HIT_COVER_SPEED;
                    coverPooHole->mHitPooSpeed = COVER_POO_HOLE_HIT_POO_SPEED;
                    coverPooHole->mYawWobbleAngle = 0;
                    coverPooHole->mYawWobbleCenter = 0;
                    coverPooHole->mYawWobbleAmplitude = COVER_POO_HOLE_YAW_WOBBLE_AMPLITUDE;
                    coverPooHole->mYawWobbleAmplitudeChange = COVER_POO_HOLE_YAW_WOBBLE_AMPLITUDE_CHANGE;
                    coverPooHole->mYawWobbleAngleStep = COVER_POO_HOLE_YAW_WOBBLE_ANGLE_STEP;
                    coverPooHole->mYawWobbleAngleStepChange = 0;
                    coverPooHole->mTiltWobbleAngle = 0;
                    coverPooHole->mTiltWobbleCenter = 0;
                    coverPooHole->mTiltWobbleAmplitude = COVER_POO_HOLE_TILT_WOBBLE_AMPLITUDE;
                    coverPooHole->mTiltWobbleAmplitudeChange = COVER_POO_HOLE_TILT_WOBBLE_AMPLITUDE_CHANGE;
                    coverPooHole->mTiltWobbleAngleStep = COVER_POO_HOLE_TILT_WOBBLE_ANGLE_STEP;
                    coverPooHole->mTiltWobbleAngleStepChange = COVER_POO_HOLE_TILT_WOBBLE_ANGLE_STEP_CHANGE;
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
                if ((coverPooHole->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) == 0) {
                    if (coverPooHole->mState == COVER_POO_HOLE_STATE_RAISE_SHORT) {
                        coverPooHole->mState = COVER_POO_HOLE_STATE_HIT_SHORT;
                    } else if (coverPooHole->mState == COVER_POO_HOLE_STATE_RAISE_TALL) {
                        coverPooHole->mState = COVER_POO_HOLE_STATE_HIT_TALL;
                    }
                }
                coverPooHole->mMapObject.mPosStep.x = 0;
                coverPooHole->mMapObject.mPosStep.y = 0;
                coverPooHole->mMapObject.mPosStep.z = 0;
                return secondResponse;
            }
            if (state == COVER_POO_HOLE_STATE_RAISE_SHORT) {
                coverPooHole->mKartHitMask = coverPooHole->mKartHitMask | kartMask;
                if ((coverPooHole->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) == 0 ||
                    kart->mIndex == gRaceSetup->mEntryIndex) {
                    coverPooHole->mHitState = COVER_POO_HOLE_HIT_THROWN;
                    coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
                    coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
                    coverPooHole->mHitCoverSpeed = 0;
                    coverPooHole->mHitPooSpeed = 0;
                    coverPooHole->mYawWobbleAngle = 0;
                    coverPooHole->mYawWobbleCenter = 0;
                    coverPooHole->mYawWobbleAmplitude = COVER_POO_HOLE_YAW_WOBBLE_AMPLITUDE;
                    coverPooHole->mYawWobbleAmplitudeChange = COVER_POO_HOLE_YAW_WOBBLE_AMPLITUDE_CHANGE;
                    coverPooHole->mYawWobbleAngleStep = COVER_POO_HOLE_YAW_WOBBLE_ANGLE_STEP;
                    coverPooHole->mYawWobbleAngleStepChange = 0;
                    coverPooHole->mTiltWobbleAngle = 0;
                    coverPooHole->mTiltWobbleCenter = 0;
                    coverPooHole->mTiltWobbleAmplitude = COVER_POO_HOLE_TILT_WOBBLE_AMPLITUDE;
                    coverPooHole->mTiltWobbleAmplitudeChange = COVER_POO_HOLE_TILT_WOBBLE_AMPLITUDE_CHANGE;
                    coverPooHole->mTiltWobbleAngleStep = COVER_POO_HOLE_TILT_WOBBLE_ANGLE_STEP;
                    coverPooHole->mTiltWobbleAngleStepChange = COVER_POO_HOLE_TILT_WOBBLE_ANGLE_STEP_CHANGE;
                    coverPooHole->mMapObject.mDistanceSquaredAndFlags =
                        coverPooHole->mMapObject.mDistanceSquaredAndFlags | gCoverPooHoleSkipSoundFlag;
                    if ((coverPooHole->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) ==
                        0) {
                        if (coverPooHole->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (coverPooHole->mMapObject.mFarDistanceSquared ==
                                   gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        secondSoundParams.mSoundId = COVER_POO_HOLE_TILT_SOUND_ID;
                        secondSoundParams.mPositionSource = &coverPooHole->mMapObject.mPos;
                        secondSoundParams.mFalloffIndex = falloffIndex;
                        secondSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&coverPooHole->mMapObject.mPos);
                        StartSoundFromParams(&secondSoundParams);
                    }
                }
                if ((coverPooHole->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) == 0) {
                    coverPooHole->mState = COVER_POO_HOLE_STATE_HIT_SHORT;
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
    if (coverPooHole->mState != COVER_POO_HOLE_STATE_RAISE_TALL) {
        return 0;
    }
    if (firstResponse == 2) {
        coverPooHole->mHitState = COVER_POO_HOLE_HIT_THROWN;
        coverPooHole->mHitCoverHeight = coverPooHole->mCoverHeight;
        coverPooHole->mHitPooHeight = coverPooHole->mPooHeight;
        coverPooHole->mHitCoverSpeed = COVER_POO_HOLE_HIT_COVER_SPEED;
        coverPooHole->mHitPooSpeed = COVER_POO_HOLE_HIT_POO_SPEED;
        coverPooHole->mMapObject.mPosStep.x = 0;
        coverPooHole->mMapObject.mPosStep.y = 0;
        coverPooHole->mMapObject.mPosStep.z = 0;
        coverPooHole->mYawWobbleAngle = 0;
        coverPooHole->mYawWobbleCenter = 0;
        coverPooHole->mYawWobbleAmplitude = COVER_POO_HOLE_YAW_WOBBLE_AMPLITUDE;
        coverPooHole->mYawWobbleAmplitudeChange = COVER_POO_HOLE_YAW_WOBBLE_AMPLITUDE_CHANGE;
        coverPooHole->mYawWobbleAngleStep = COVER_POO_HOLE_YAW_WOBBLE_ANGLE_STEP;
        coverPooHole->mYawWobbleAngleStepChange = 0;
        coverPooHole->mTiltWobbleAngle = 0;
        coverPooHole->mTiltWobbleCenter = 0;
        coverPooHole->mTiltWobbleAmplitude = COVER_POO_HOLE_TILT_WOBBLE_AMPLITUDE;
        coverPooHole->mTiltWobbleAmplitudeChange = COVER_POO_HOLE_TILT_WOBBLE_AMPLITUDE_CHANGE;
        coverPooHole->mTiltWobbleAngleStep = COVER_POO_HOLE_TILT_WOBBLE_ANGLE_STEP;
        coverPooHole->mTiltWobbleAngleStepChange = COVER_POO_HOLE_TILT_WOBBLE_ANGLE_STEP_CHANGE;
        coverPooHole->mMapObject.mDistanceSquaredAndFlags =
            coverPooHole->mMapObject.mDistanceSquaredAndFlags | gCoverPooHoleHitDistanceFlag;
        if ((coverPooHole->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) == 0) {
            coverPooHole->mState = COVER_POO_HOLE_STATE_HIT_TALL;
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
    if (coverPooHole->mState == COVER_POO_HOLE_STATE_RAISE_SHORT) {
        pushOut->x = 0;
        pushOut->y = 0;
        pushOut->z = 0;
        return TRUE;
    }
    if (coverPooHole->mState == COVER_POO_HOLE_STATE_RAISE_TALL ||
        (coverPooHole->mState == COVER_POO_HOLE_STATE_LOWER_TALL &&
         coverPooHole->mCoverHeight > COVER_POO_HOLE_SHORT_HEIGHT)) {
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
        case COVER_POO_HOLE_STATE_RAISE_SHORT:
        case COVER_POO_HOLE_STATE_LOWER_SHORT:
        case COVER_POO_HOLE_STATE_HIT_SHORT:
            SetMapObjectModelNsbtpFrameIndex(gPoo, 0);
            break;
        case COVER_POO_HOLE_STATE_RAISE_TALL:
        case COVER_POO_HOLE_STATE_LOWER_TALL:
        case COVER_POO_HOLE_STATE_HIT_TALL:
            SetMapObjectModelNsbtpFrameIndex(gPoo, 1);
            break;
    }
    if (coverPooHole->mState != COVER_POO_HOLE_STATE_WAIT_SHORT) {
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
        coverPooHole->mHoleHeight = COVER_POO_HOLE_HOLE_HEIGHT;
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        coverPooHole->mTimer = (u16) (coverPooHole->mMapObject.mCourseMapRow->mSettings[0] +
                                      (u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) - 30);
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            coverPooHole->mState = COVER_POO_HOLE_STATE_WAIT_TALL;
            coverPooHole->mCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
            coverPooHole->mPooHeight = COVER_POO_HOLE_REST_POO_HEIGHT;
        } else {
            coverPooHole->mState = COVER_POO_HOLE_STATE_WAIT_SHORT;
            coverPooHole->mCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
            coverPooHole->mPooHeight = COVER_POO_HOLE_REST_POO_HEIGHT;
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

    if (coverPooHole->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) {
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
            if (coverPooHole->mHitCoverHeight >= COVER_POO_HOLE_REST_HEIGHT) {
                coverPooHole->mHitCoverHeight += coverPooHole->mHitCoverSpeed;
                coverPooHole->mHitCoverSpeed -= 0x19a;
            } else {
                coverPooHole->mHitCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
                coverPooHole->mHitState = COVER_POO_HOLE_HIT_WOBBLING;
                StartCoverPooHoleSound(coverPooHole, 0x16c);
            }
            break;
        case COVER_POO_HOLE_HIT_WOBBLING:
            if (coverPooHole->mHitPooHeight >= COVER_POO_HOLE_REST_HEIGHT) {
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
            if (coverPooHole->mTiltWobbleAmplitude == 0 && coverPooHole->mState != COVER_POO_HOLE_STATE_LOWER_SHORT &&
                coverPooHole->mState != COVER_POO_HOLE_STATE_LOWER_TALL) {
                coverPooHole->mHitState = COVER_POO_HOLE_HIT_NONE;
            }
            break;
    }
    if ((coverPooHole->mState == COVER_POO_HOLE_STATE_HIT_SHORT ||
         coverPooHole->mState == COVER_POO_HOLE_STATE_HIT_TALL) &&
        coverPooHole->mHitState == COVER_POO_HOLE_HIT_NONE) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            coverPooHole->mState = COVER_POO_HOLE_STATE_WAIT_TALL;
            coverPooHole->mCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
            coverPooHole->mPooHeight = COVER_POO_HOLE_REST_POO_HEIGHT;
        } else {
            coverPooHole->mState = COVER_POO_HOLE_STATE_WAIT_SHORT;
            coverPooHole->mCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
            coverPooHole->mPooHeight = COVER_POO_HOLE_REST_POO_HEIGHT;
        }
    }
    switch (coverPooHole->mState) {
        case COVER_POO_HOLE_STATE_WAIT_SHORT:
            if (coverPooHole->mTimer-- > 0) {
                return;
            }
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(30) + 30);
            coverPooHole->mState = COVER_POO_HOLE_STATE_RAISE_SHORT;
            coverPooHole->mHitState = COVER_POO_HOLE_HIT_NONE;
            coverPooHole->mKartHitMask = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d3);
            break;
        case COVER_POO_HOLE_STATE_RAISE_SHORT:
            if (coverPooHole->mCoverHeight < COVER_POO_HOLE_SHORT_HEIGHT) {
                coverPooHole->mCoverHeight += COVER_POO_HOLE_SHORT_STEP;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - COVER_POO_HOLE_POO_DEPTH;
                return;
            }
            if (coverPooHole->mTimer-- > 0) {
                coverPooHole->mCoverHeight = COVER_POO_HOLE_SHORT_HEIGHT;
                coverPooHole->mPooHeight = COVER_POO_HOLE_SHORT_POO_HEIGHT;
                return;
            }
            coverPooHole->mCoverHeight = COVER_POO_HOLE_SHORT_HEIGHT;
            coverPooHole->mPooHeight = COVER_POO_HOLE_SHORT_POO_HEIGHT;
            coverPooHole->mState = COVER_POO_HOLE_STATE_LOWER_SHORT;
            break;
        case COVER_POO_HOLE_STATE_LOWER_SHORT:
            if (coverPooHole->mCoverHeight > COVER_POO_HOLE_REST_HEIGHT) {
                coverPooHole->mCoverHeight -= COVER_POO_HOLE_SHORT_STEP;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - COVER_POO_HOLE_POO_DEPTH;
                return;
            }
            coverPooHole->mCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
            coverPooHole->mPooHeight = COVER_POO_HOLE_REST_POO_HEIGHT;
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(15) + 15);
            coverPooHole->mState = COVER_POO_HOLE_STATE_WAIT_TALL;
            coverPooHole->mKartHitMask = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d4);
            break;
        case COVER_POO_HOLE_STATE_WAIT_TALL:
            if (coverPooHole->mTimer-- > 0) {
                return;
            }
            coverPooHole->mCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
            coverPooHole->mPooHeight = COVER_POO_HOLE_REST_POO_HEIGHT;
            coverPooHole->mTimer = (u16) (CoverPooHoleMapObjectRandomBelowU16(90) + 90);
            coverPooHole->mState = COVER_POO_HOLE_STATE_RAISE_TALL;
            coverPooHole->mHitState = COVER_POO_HOLE_HIT_NONE;
            coverPooHole->mKartHitMask = 0;
            StartCoverPooHoleSound(coverPooHole, 0x1d3);
            break;
        case COVER_POO_HOLE_STATE_RAISE_TALL:
            if (coverPooHole->mCoverHeight < COVER_POO_HOLE_TALL_HEIGHT) {
                coverPooHole->mCoverHeight += COVER_POO_HOLE_TALL_STEP;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - COVER_POO_HOLE_POO_DEPTH;
                return;
            }
            if (coverPooHole->mTimer-- > 0) {
                coverPooHole->mCoverHeight = COVER_POO_HOLE_TALL_HEIGHT;
                coverPooHole->mPooHeight = COVER_POO_HOLE_TALL_POO_HEIGHT;
                return;
            }
            coverPooHole->mCoverHeight = COVER_POO_HOLE_TALL_HEIGHT;
            coverPooHole->mPooHeight = COVER_POO_HOLE_TALL_POO_HEIGHT;
            coverPooHole->mState = COVER_POO_HOLE_STATE_LOWER_TALL;
            break;
        case COVER_POO_HOLE_STATE_LOWER_TALL:
            if (coverPooHole->mCoverHeight > COVER_POO_HOLE_REST_HEIGHT) {
                coverPooHole->mCoverHeight -= COVER_POO_HOLE_TALL_STEP;
                coverPooHole->mPooHeight = coverPooHole->mCoverHeight - COVER_POO_HOLE_POO_DEPTH;
                return;
            }
            coverPooHole->mTimer = (u16) (coverPooHole->mMapObject.mCourseMapRow->mSettings[0] +
                                          CoverPooHoleMapObjectRandomBelowU16(60) - 30);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                coverPooHole->mState = COVER_POO_HOLE_STATE_WAIT_TALL;
                coverPooHole->mCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
                coverPooHole->mPooHeight = COVER_POO_HOLE_REST_POO_HEIGHT;
            } else {
                coverPooHole->mState = COVER_POO_HOLE_STATE_WAIT_SHORT;
                coverPooHole->mCoverHeight = COVER_POO_HOLE_REST_HEIGHT;
                coverPooHole->mPooHeight = COVER_POO_HOLE_REST_POO_HEIGHT;
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
    kindData->mCollideItemObjectSoundId = COVER_POO_HOLE_ITEM_HIT_SOUND_ID;
    return kindData;
}

MapObjectList *CreateCoverPooHoleDrawList(void) {
    return CreateMapObjectDrawList2(CreateCoverPooHole, DrawCoverPooHole, NULL);
}

MapObjectList *CreateCoverPooHoleUpdateList(void) {
    return CreateMapObjectUpdateList(InitCoverPooHoleObjects, UpdateCoverPooHole, NULL);
}

BOOL IsCoverPooHoleRaising(CoverPooHole *coverPooHole) {
    if (coverPooHole->mState == COVER_POO_HOLE_STATE_RAISE_SHORT ||
        coverPooHole->mState == COVER_POO_HOLE_STATE_RAISE_TALL) {
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
                                                       InitCoverPooHole,
                                                       CreateCoverPooHoleKindData,
                                                       CreateCoverPooHoleDrawList,
                                                       0,
                                                       0,
                                                       CreateCoverPooHoleUpdateList};
