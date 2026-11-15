#include "Main/MapObjects/sanbo.h"
#include "Main/MapObjects/data_0217c000.h"

#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/shine16.h"
#include "Main/MapObjects/code_020a73b0.h"
#include "Main/MapObjects/code_020a7eb4.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/sanbo_launch.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_02167000.h"
#include "Main/MapObjects/code_020a8080.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Kart/karts.h"
#include "code_02147cd8.h"

MapObjectModel *gSanboH;
MapObjectModel *gSanboB;

void InitSanbo(Sanbo *sanbo) {
    InitGroupFollower(&sanbo->mFollower, sanbo->mMapObject.mCourseMapRow, 0);
}

MapObjectKindDescriptor gSanboKindDescriptor = {0,
                                             {0, 0},
                                             0x200,
                                             InitSanbo,
                                             CreateSanboKindData,
                                             CreateSanboDrawList,
                                             0,
                                             0,
                                             CreateSanboUpdateList};

u8 CollideKartWithSanbo(Sanbo *sanbo, Kart *kart, u8 *firstResponse, u8 *response) {
    SoundStartParams soundStartParams;
    u32 responseValue;

    responseValue = *response;
    if (*firstResponse == 1) {
        StartSanboLaunch(sanbo);
        sanbo->mMapObject.mFlags = sanbo->mMapObject.mFlags | gSanboHitFlag;
        sanbo->mMapObject.mFlags = sanbo->mMapObject.mFlags | gSanboSecondHitFlag;
        StartSoundIfKartStarOrKiller(&sanbo->mMapObject, kart);
    } else {
        if (sanbo->mFastWobbleTimer == 0) {
            soundStartParams.mSoundId = SANBO_HIT_SOUND_ID;
            soundStartParams.mPositionSource = &sanbo->mMapObject.mPos;
            soundStartParams.mFalloffIndex = SOUND_FALLOFF_SHORT_RANGE;
            soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sanbo->mMapObject.mPos);
            StartSoundFromParams(&soundStartParams);
            sanbo->mSoundTimer = SANBO_SOUND_FRAMES;
        }
        sanbo->mFastWobbleTimer = SANBO_FAST_WOBBLE_FRAMES;
    }
    return responseValue;
}

u8 CollideItemObjectWithSanbo(Sanbo *sanbo, ItemObject *itemObject, u8 *firstResponse, u8 *response) {
    SoundStartParams soundStartParams;
    u32 responseValue;

    responseValue = *response;
    if (*firstResponse == 1) {
        StartSanboLaunch(sanbo);
        sanbo->mMapObject.mFlags = sanbo->mMapObject.mFlags | gSanboHitFlag;
        sanbo->mMapObject.mFlags = sanbo->mMapObject.mFlags | gSanboSecondHitFlag;
    } else {
        if (sanbo->mFastWobbleTimer == 0) {
            soundStartParams.mSoundId = SANBO_HIT_SOUND_ID;
            soundStartParams.mPositionSource = &sanbo->mMapObject.mPos;
            soundStartParams.mFalloffIndex = SOUND_FALLOFF_SHORT_RANGE;
            soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sanbo->mMapObject.mPos);
            StartSoundFromParams(&soundStartParams);
            sanbo->mSoundTimer = SANBO_SOUND_FRAMES;
        }
        sanbo->mFastWobbleTimer = SANBO_FAST_WOBBLE_FRAMES;
    }
    return responseValue;
}

void CreateSanboHAndSanboB(void *mapObjectList) {
    gSanboH = CreateMapObjectModelNsbmd(mapObjectList, "sanbo_h.nsbmd");
    gSanboB = CreateMapObjectModelNsbmd(mapObjectList, "sanbo_b.nsbmd");
    SetMapObjectModelPolygonId(gSanboH, 0x3f);
    SetMapObjectModelPolygonId(gSanboB, 0x3f);
}

void SanboSetupDrawNop(void) {}

void DrawSanbo(void *mapObjectList, Sanbo *sanbo) {
    s32 pieceIndex;
    s32 gxParam;
    s32 secondGxParam;
    s32 thirdGxParam;
    MtxFx33 rotateZMatrix;
    MtxFx33 pieceRotateZMatrix;
    s32 startTranslation[3];
    s32 stackTranslation[3];
    s32 pieceTranslation[3];
    s32 pieceScaleVector[3];
    s32 stackedTranslation[3];
    s32 stackedScaleVector[3];
    s32 drawScale;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    switch (sanbo->mState) {
        case SANBO_STATE_STANDING:
        case SANBO_STATE_STANDING_UNUSED:
            NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&sanbo->mMapObject.mPos), 12);
            startTranslation[0] = 0;
            startTranslation[1] = 0xa00;
            startTranslation[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, startTranslation, 3);
            for (pieceIndex = 0; pieceIndex < sanbo->mPieceCount; pieceIndex++) {
                if (sanbo->mPieces[pieceIndex].mRotateZAngle != 0) {
                    MTX_RotZ33_(&rotateZMatrix, SIN_OF_ANGLE((u16) sanbo->mPieces[pieceIndex].mRotateZAngle),
                                COS_OF_ANGLE((u16) sanbo->mPieces[pieceIndex].mRotateZAngle));
                    NNS_G3dGeBufferOP_N(0x1a, &rotateZMatrix, 9);
                }
                if (pieceIndex != 0) {
                    stackTranslation[0] = 0;
                    stackTranslation[1] = 0x1400;
                    stackTranslation[2] = 0x80;
                    NNS_G3dGeBufferOP_N(0x1c, stackTranslation, 3);
                }
                if (pieceIndex == 3) {
                    QueueMapObjectModelMaterial(mapObjectList, gSanboH);
                    DrawMapObjectModel(mapObjectList, gSanboH, sanbo);
                } else {
                    QueueMapObjectModelMaterial(mapObjectList, gSanboB);
                    DrawMapObjectModel(mapObjectList, gSanboB, sanbo);
                }
            }
            break;
        case SANBO_STATE_SCATTERED:
            for (pieceIndex = 0; pieceIndex < sanbo->mPieceCount; pieceIndex++) {
                secondGxParam = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &secondGxParam, 1);
                pieceTranslation[0] = 0;
                pieceTranslation[1] = 0xa00;
                pieceTranslation[2] = 0;
                NNS_G3dGeBufferOP_N(0x1c, pieceTranslation, 3);
                NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&sanbo->mPieces[pieceIndex].mPos), 12);
                if ((sanbo->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN) == 0 &&
                    sanbo->mPieces[pieceIndex].mRotateZAngle != 0) {
                    MTX_RotZ33_(&pieceRotateZMatrix, SIN_OF_ANGLE((u16) sanbo->mPieces[pieceIndex].mRotateZAngle),
                                COS_OF_ANGLE((u16) sanbo->mPieces[pieceIndex].mRotateZAngle));
                    NNS_G3dGeBufferOP_N(0x1a, &pieceRotateZMatrix, 9);
                }
                drawScale = sanbo->mPieces[pieceIndex].mDrawScale;
                if (drawScale < FIXED12_UNIT) {
                    pieceScaleVector[0] = drawScale;
                    pieceScaleVector[1] = drawScale;
                    pieceScaleVector[2] = 0;
                    NNS_G3dGeBufferOP_N(0x1b, pieceScaleVector, 3);
                }
                if (pieceIndex == 3) {
                    QueueMapObjectModelMaterial(mapObjectList, gSanboH);
                    DrawMapObjectModel(mapObjectList, gSanboH, sanbo);
                } else {
                    QueueMapObjectModelMaterial(mapObjectList, gSanboB);
                    DrawMapObjectModel(mapObjectList, gSanboB, sanbo);
                }
            }
            break;
        case SANBO_STATE_REGROWING:
            for (pieceIndex = 0; pieceIndex < sanbo->mPieceCount; pieceIndex++) {
                thirdGxParam = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &thirdGxParam, 1);
                NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&sanbo->mMapObject.mPos), 12);
                stackedTranslation[2] = 0x80;
                stackedTranslation[0] = 0;
                stackedTranslation[1] = (pieceIndex * 0x14000 + 0xa000) >> 4;
                NNS_G3dGeBufferOP_N(0x1c, stackedTranslation, 3);
                drawScale = sanbo->mPieces[pieceIndex].mDrawScale;
                if (drawScale < FIXED12_UNIT) {
                    stackedScaleVector[0] = drawScale;
                    stackedScaleVector[1] = drawScale;
                    stackedScaleVector[2] = 0;
                    NNS_G3dGeBufferOP_N(0x1b, stackedScaleVector, 3);
                }
                if (pieceIndex == 3) {
                    QueueMapObjectModelMaterial(mapObjectList, gSanboH);
                    DrawMapObjectModel(mapObjectList, gSanboH, sanbo);
                } else {
                    QueueMapObjectModelMaterial(mapObjectList, gSanboB);
                    DrawMapObjectModel(mapObjectList, gSanboB, sanbo);
                }
            }
            break;
    }
}

void InitSanboObjects(MapObjectList *mapObjectList) {
    s32 pieceIndex;
    s32 mapObjectIndex;
    Sanbo *sanbo;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (sanbo = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        sanbo->mPathSpeed = TO_FIXED12(sanbo->mMapObject.mCourseMapRow->mSettings[0]) / 100;
        sanbo->mPieceCount = SANBO_PIECE_COUNT;
        for (pieceIndex = 0; pieceIndex < sanbo->mPieceCount; pieceIndex++) {
            sanbo->mPieces[pieceIndex].mWobbleAngle = 0;
            sanbo->mPieces[pieceIndex].mWobbleMid = 0;
            sanbo->mPieces[pieceIndex].mWobbleAmplitude = SANBO_WOBBLE_AMPLITUDE;
            sanbo->mPieces[pieceIndex].mWobbleAmplitudePerFrame = 0;
            sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame = SANBO_WOBBLE_ANGLE_PER_FRAME;
            sanbo->mPieces[pieceIndex].mWobbleAnglePerFrameDelta = 0;
            sanbo->mPieces[pieceIndex].mDrawScale = FIXED12_UNIT;
            sanbo->mPieces[pieceIndex].mRotateZAngle = 0;
            sanbo->mPieces[pieceIndex].mWobbleDelayTimer = pieceIndex * 0x14;
        }
    }
}

s32 SanboFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 SanboFX_MulInline(s32 value, s32 scale) {
    return MUL_FIXED12_ROUNDED(value, scale);
}

void UpdateSanbo(void *mapObjectList, Sanbo *sanbo) {
    SoundStartParams soundStartParams;
    s32 rotatePieceIndex;
    s32 resetPieceIndex;
    s32 pieceIndex;
    s32 fallPieceIndex;
    s32 value;
    s32 newValue;

    if (sanbo->mPathWaitTimer-- <= 0) {
        value = sanbo->mPathSpeed;
        sanbo->mFollower.mSpeed = value;
        sanbo->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
            value, sanbo->mFollower.mPath->mSegments[sanbo->mFollower.mSegmentIndex].mInverseProgressLength);
        if (AdvanceGroupFollower(&sanbo->mFollower) != FALSE) {
            sanbo->mPathWaitTimer = (u16) sanbo->mFollower.mFromEntry->mValue;
        } else {
            sanbo->mPathWaitTimer = 0;
        }
        if (sanbo->mFollower.mPath->mWraps != 0) {
            GetGroupFollowerCurvePosStep(&sanbo->mFollower, &sanbo->mMapObject.mPos, &sanbo->mMapObject.mPosStep);
        } else {
            GetGroupFollowerLinearPosStep(&sanbo->mFollower, &sanbo->mMapObject.mPos, &sanbo->mMapObject.mPosStep);
        }
    } else {
        sanbo->mFollower.mSpeed = 0;
        sanbo->mFollower.mProgressStep = 0;
        sanbo->mMapObject.mPosStep.x = 0;
        sanbo->mMapObject.mPosStep.y = 0;
        sanbo->mMapObject.mPosStep.z = 0;
    }
    switch (sanbo->mState) {
        case SANBO_STATE_STANDING:
            if ((sanbo->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN) != 0) {
                return;
            }
            for (pieceIndex = 0; pieceIndex < sanbo->mPieceCount; pieceIndex++) {
                if (sanbo->mFastWobbleTimer > 0) {
                    sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame = SANBO_FAST_WOBBLE_ANGLE_PER_FRAME;
                } else if (sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame > SANBO_WOBBLE_SOUND_ANGLE_PER_FRAME) {
                    sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame =
                        sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame - 0xb6;
                } else {
                    sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame = SANBO_WOBBLE_ANGLE_PER_FRAME;
                }
                if (sanbo->mPieces[pieceIndex].mWobbleDelayTimer-- <= 0) {
                    sanbo->mPieces[pieceIndex].mWobbleDelayTimer = 0;
                    sanbo->mPieces[pieceIndex].mWobbleAngle =
                        sanbo->mPieces[pieceIndex].mWobbleAngle + sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame;
                    sanbo->mPieces[pieceIndex].mWobbleValueDelta =
                        sanbo->mPieces[pieceIndex].mWobbleMid +
                        SanboFX_MulInline(sanbo->mPieces[pieceIndex].mWobbleAmplitude,
                                          SanboFX_SinIdx(sanbo->mPieces[pieceIndex].mWobbleAngle)) -
                        sanbo->mPieces[pieceIndex].mWobbleValue;
                    sanbo->mPieces[pieceIndex].mWobbleValue =
                        sanbo->mPieces[pieceIndex].mWobbleValue + sanbo->mPieces[pieceIndex].mWobbleValueDelta;
                    value = sanbo->mPieces[pieceIndex].mWobbleAmplitude;
                    if (value > 0) {
                        newValue = value + sanbo->mPieces[pieceIndex].mWobbleAmplitudePerFrame;
                        if (newValue <= 0) {
                            newValue = 0;
                        }
                        sanbo->mPieces[pieceIndex].mWobbleAmplitude = newValue;
                    } else if (value < 0) {
                        newValue = value + sanbo->mPieces[pieceIndex].mWobbleAmplitudePerFrame;
                        if (newValue >= 0) {
                            newValue = 0;
                        }
                        sanbo->mPieces[pieceIndex].mWobbleAmplitude = newValue;
                    }
                    value = sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame;
                    if (value > 0) {
                        newValue = value + sanbo->mPieces[pieceIndex].mWobbleAnglePerFrameDelta;
                        if (newValue <= 0) {
                            newValue = 0;
                        }
                        sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame = newValue;
                    } else if (value < 0) {
                        newValue = value + sanbo->mPieces[pieceIndex].mWobbleAnglePerFrameDelta;
                        if (newValue >= 0) {
                            newValue = 0;
                        }
                        sanbo->mPieces[pieceIndex].mWobbleAnglePerFrame = newValue;
                    }
                    sanbo->mPieces[pieceIndex].mRotateZAngle = (u16) sanbo->mPieces[pieceIndex].mWobbleValue;
                }
            }
            if (sanbo->mFastWobbleTimer <= 0) {
                return;
            }
            sanbo->mFastWobbleTimer = sanbo->mFastWobbleTimer - 1;
            if (sanbo->mSoundTimer > 0) {
                sanbo->mSoundTimer = sanbo->mSoundTimer - 1;
                return;
            }
            if (sanbo->mPieces[0].mWobbleAngle <= ANGLE_HALF_TURN) {
                return;
            }
            if (sanbo->mPieces[0].mWobbleAngle >= ANGLE_MINUS_QUARTER_TURN) {
                return;
            }
            soundStartParams.mSoundId = SANBO_WOBBLE_SOUND_ID;
            soundStartParams.mPositionSource = &sanbo->mMapObject.mPos;
            soundStartParams.mFalloffIndex = SOUND_FALLOFF_SHORT_RANGE;
            soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sanbo->mMapObject.mPos);
            StartSoundFromParams(&soundStartParams);
            sanbo->mSoundTimer = SANBO_SOUND_FRAMES;
            break;
        case SANBO_STATE_SCATTERED:
            for (fallPieceIndex = 0; fallPieceIndex < sanbo->mPieceCount; fallPieceIndex++) {
                if (sanbo->mPieces[fallPieceIndex].mPos.y > 0) {
                    sanbo->mPieces[fallPieceIndex].mPos.x =
                        sanbo->mPieces[fallPieceIndex].mPos.x + sanbo->mPieces[fallPieceIndex].mVelocity.x;
                    sanbo->mPieces[fallPieceIndex].mPos.y =
                        sanbo->mPieces[fallPieceIndex].mPos.y + sanbo->mPieces[fallPieceIndex].mVelocity.y;
                    sanbo->mPieces[fallPieceIndex].mPos.z =
                        sanbo->mPieces[fallPieceIndex].mPos.z + sanbo->mPieces[fallPieceIndex].mVelocity.z;
                    sanbo->mPieces[fallPieceIndex].mVelocity.y = sanbo->mPieces[fallPieceIndex].mVelocity.y - 0x400;
                }
            }
            if ((sanbo->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN) == 0) {
                for (rotatePieceIndex = 0; rotatePieceIndex < sanbo->mPieceCount; rotatePieceIndex++) {
                    sanbo->mPieces[rotatePieceIndex].mRotateZAngle =
                        sanbo->mPieces[rotatePieceIndex].mRotateZAngle +
                        sanbo->mPieces[rotatePieceIndex].mRotateZAnglePerFrame;
                }
            }
            if (sanbo->mMapObject.mCourseMapRow->mSettings[1] != 0) {
                return;
            }
            if (sanbo->mState2Timer-- > 0) {
                return;
            }
            for (resetPieceIndex = 0; resetPieceIndex < sanbo->mPieceCount; resetPieceIndex++) {
                sanbo->mPieces[resetPieceIndex].mWobbleAngle = 0;
                sanbo->mPieces[resetPieceIndex].mDrawScale = 0;
                sanbo->mPieces[resetPieceIndex].mRotateZAngle = 0;
                sanbo->mPieces[resetPieceIndex].mWobbleDelayTimer = resetPieceIndex * 0x14;
            }
            sanbo->mPieceCount = 1;
            sanbo->mState = SANBO_STATE_REGROWING;
            sanbo->mMapObject.mFlags = sanbo->mMapObject.mFlags & ~1;
            sanbo->mMapObject.mFlags = sanbo->mMapObject.mFlags & ~8;
            break;
        case SANBO_STATE_REGROWING:
            sanbo->mPieces[sanbo->mPieceCount - 1].mDrawScale =
                sanbo->mPieces[sanbo->mPieceCount - 1].mDrawScale + 0xcd;
            if (sanbo->mPieces[sanbo->mPieceCount - 1].mDrawScale < FIXED12_UNIT) {
                return;
            }
            sanbo->mPieces[sanbo->mPieceCount - 1].mDrawScale = FIXED12_UNIT;
            sanbo->mPieceCount = sanbo->mPieceCount + 1;
            if (sanbo->mPieceCount > SANBO_PIECE_COUNT) {
                sanbo->mPieceCount = SANBO_PIECE_COUNT;
                sanbo->mState = SANBO_STATE_STANDING;
            }
            break;
    }
}

MapObjectKindData *CreateSanboKindData(void) {
    return CreateMapObjectKindData(&CollideKartWithSanbo, &CollideItemObjectWithSanbo, NULL, 1, 1);
}

MapObjectList *CreateSanboDrawList(void) {
    return CreateMapObjectDrawList2(CreateSanboHAndSanboB, DrawSanbo, SanboSetupDrawNop);
}

MapObjectList *CreateSanboUpdateList(void) {
    return CreateMapObjectUpdateList(InitSanboObjects, UpdateSanbo, NULL);
}

BOOL ShineKartHitCallback(u16 kartIndex, u16 hitByKartIndex) {
    if (GetBalloonOrShineCount(kartIndex) != 0) {
        AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
        if (hitByKartIndex >= 8) {
            hitByKartIndex = kartIndex;
        }
        StartShine16FromKart(GetKart(kartIndex), GetKart(hitByKartIndex));
        return TRUE;
    }
    return FALSE;
}

void ShineKartEliminatedCallback(u16 kartIndex) {
    if (GetBalloonOrShineCount(kartIndex) == 0) {
        return;
    }
    AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
    StartShine16FromKart(GetKart(kartIndex), GetKart(kartIndex));
}

void ShineEndCallback(void) {
    s32 mapObjectIndex;
    MapObject *mapObject;
    MapObjectList *mapObjectList;

    mapObjectList = FindMapObjectKindUpdateList(0x6b);
    if (mapObjectList != NULL) {
        for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                                 (mapObject = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
             mapObjectIndex++) {
            if ((mapObject->mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
                ParkMapObject(mapObject);
            }
        }
    }
    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE_BALLOON);
    if (mapObjectList != NULL) {
        for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                                 (mapObject = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
             mapObjectIndex++) {
            if ((mapObject->mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
                ParkMapObject(mapObject);
            }
        }
    }
    ParkShine16Objects();
}

const u16 gSanboHitFlag = 1;
const u16 gSanboSecondHitFlag = 8;
