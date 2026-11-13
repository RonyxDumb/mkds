#include "Main/MapObjects/shine16.h"

#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/balloon.h"
#include "Main/MapObjects/balloon_velocity.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/trophy.h"
#include "Main/MapObjects/balloon_target.h"
#include "Main/MapObjects/balloon_draw.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/MapObjects/bound.h"
#include "Main/Kart/kart_effects.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/balloon_park.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/map_object_sound_counter.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/shine_battle.h"
#include "code_02147cd8.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/MapObjects/woodbox.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/sphere_collision.h"
#include "Main/Sound/shine16_track_params.h"
#include "Main/MapObjects/data_0217b000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/data_02167000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

MapObjectKindDescriptor gShine16KindDescriptor = {0,
                                             {0, 0},
                                             0xec,
                                             InitShine16,
                                             CreateShine16KindData,
                                             CreateShine16DrawList,
                                             CreateShine16ShadowDrawList,
                                             0,
                                             CreateShine16UpdateList};
u16 gShine16ShadowAngleIndex;
MapObjectModel *gShine16;

const u16 gShine16ShadowAngles[4] = {0, 0xe38, 0x1c71, 0};
void InitShine16(MapObject *mapObject) {
    ParkMapObject(mapObject);
    mapObject->mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mSound->mSoundSource, 0xb, &mapObject->mPos);
    SetShine16TrackParamsReturnArgument(&mapObject->mSound->mSoundSource);
    mapObject->mFarDistanceSquared = gSoundFalloffs[0xb].mFarDistanceSquared;
}

u32 CollideKartWithShine16(Shine16 *shine16, Kart *kart, u8 *firstResponse, u8 *response) {
    u8 firstResponseValue;
    u8 responseValue;
    s32 isEntryKart;
    u16 highestBalloonOrShineCount;
    s32 balloonOrShineCount;

    firstResponseValue = *firstResponse;
    responseValue = *response;
    if (kart->mState != KART_STATE_NORMAL || (kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) != 0 ||
        IsKartEliminated(kart->mIndex) != FALSE) {
        return 0;
    }
    if (firstResponseValue == 1) {
        if ((kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) != 0) {
            return responseValue;
        }
        if (shine16->mPickupTimer > 0) {
            return responseValue;
        }
        shine16->mMapObject.mFlags |= gShine16HitFlag;
        shine16->mPickupTimer = 0x19;
        shine16->mMapObject.mPos.x = kart->mPos.x;
        shine16->mMapObject.mPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) + 0x7800;
        shine16->mMapObject.mPos.z = kart->mPos.z;
        shine16->mHeightAboveKart = 0;
        shine16->mMapObject.mPosStep.x = 0;
        shine16->mMapObject.mPosStep.y = 0x3000;
        shine16->mMapObject.mPosStep.z = 0;
        shine16->mDrawScale = 0;
        shine16->mState = 2;
        shine16->mKartIndex = kart->mIndex;
        shine16->mHitByKartIndex = kart->mIndex;
        AddBalloonsLeftToMake(kart->mIndex, 1);
        AddBalloonOrShineCountAndMoveRank(kart->mIndex, 1);
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex ? 1 : 0;
        highestBalloonOrShineCount = GetHighestBalloonOrShineCount();
        balloonOrShineCount = GetBalloonOrShineCount(kart->mIndex);
        QueueShine16Sound(shine16->mMapObject.mSound,
                          GetShine16SoundId(0, isEntryKart, highestBalloonOrShineCount, balloonOrShineCount));
        shine16->mEffect = StartEffect(0x7d, &shine16->mMapObject.mPos);
        shine16->mEffectTimer = 0xe;
    }
    return responseValue;
}

void CreateShine16(void *mapObjectList) {
    gShine16 = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "shine16.nsbmd", "shine16.nsbtp");
    SetMapObjectModelPolygonId(gShine16, 0x3f);
}

void SetupDrawShine16(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gShine16);
}

void DrawShine16(void *mapObjectList, Shine16 *shine16) {
    s32 gxParam;
    Vec3 scaleVector;
    s32 drawScale;

    if (shine16->mDrawScale <= 0) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&shine16->mMapObject.mPos), 0xc);
    drawScale = shine16->mDrawScale;
    if (drawScale != 0x1000) {
        scaleVector.x = drawScale;
        scaleVector.y = drawScale;
        scaleVector.z = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, &scaleVector, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &shine16->mMapObject.mScale, 3);
    SetMapObjectModelMirror(gShine16, shine16->mMirror, 0);
    SetMapObjectModelNsbtpFrameIndex(gShine16, shine16->mNsbtpFrameIndex);
    DrawMapObjectModel(mapObjectList, gShine16, shine16);
}

u16 *ResetShine16ShadowAngleIndex(void) {
    gShine16ShadowAngleIndex = 0;
    return &gShine16ShadowAngleIndex;
}

void AdvanceShine16ShadowAngleIndex(void) {
    s32 nextAngleIndex;

    nextAngleIndex = gShine16ShadowAngleIndex + 1;
    if (nextAngleIndex >= 3) {
        nextAngleIndex = 0;
    }
    gShine16ShadowAngleIndex = nextAngleIndex;
}

void DrawShine16Shadow(void *mapObjectList, Shine16 *shine16, void *unused, s32 maxAlpha) {
    s32 gxParam;
    MtxFx33 rotateYMatrix;
    Vec3 drawScaleVector;
    Vec3 shadowScaleVector;
    s32 drawScale;

    if (shine16->mDrawScale <= 0) {
        return;
    }
    if (shine16->mState == 2) {
        return;
    }
    if (shine16->mState == 3) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&shine16->mMapObject.mPos), 0xc);
    drawScale = shine16->mDrawScale;
    if (drawScale < 0x1000) {
        drawScaleVector.x = drawScale;
        drawScaleVector.y = drawScale;
        drawScaleVector.z = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, &drawScaleVector, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &shine16->mMapObject.mScale, 3);
    MTX_RotY33_(&rotateYMatrix, COS_OF_ANGLE(gShine16ShadowAngles[gShine16ShadowAngleIndex]),
                SIN_OF_ANGLE(gShine16ShadowAngles[gShine16ShadowAngleIndex]));
    NNS_G3dGeBufferOP_N(0x1a, &rotateYMatrix, 9);
    shadowScaleVector.x = 0x2000;
    shadowScaleVector.y = 0x2000;
    shadowScaleVector.z = 0x2000;
    NNS_G3dGeBufferOP_N(0x1b, &shadowScaleVector, 3);
    DrawJgShadow(8, maxAlpha);
}

void UpdateShine16(void *mapObjectList, Shine16 *shine16) {
    Vec3 probePos;
    Vec3 pushOut;
    Vec3 firstNormal;
    Vec3 secondNormal;
    u32 hitFlags;
    Kart *kart;
    s32 battlePointIndex;
    CourseMapPoint *forwardBattlePoint;
    s32 distance;
    s32 deltaX;
    s32 deltaZ;
    s32 savedVelocityY;
    u16 randomAngle;
    s32 randomRadius;
    RandomState64 *randomState;

    switch (shine16->mState) {
        case 0:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            shine16->mMapObject.mPosStep.y -= 0x19a;
            VEC_Add(&shine16->mMapObject.mPos, &shine16->mMapObject.mPosStep, &shine16->mMapObject.mPos);
            if (shine16->mMapObject.mPos.y > shine16->mFloorY) {
                return;
            }
            shine16->mMapObject.mPos.y = shine16->mFloorY;
            shine16->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.y, -0x333);
            if (shine16->mMapObject.mPosStep.y < 0x1000) {
                shine16->mMapObject.mPosStep.y = 0;
                shine16->mState = 1;
            }
            QueueShine16Sound(shine16->mMapObject.mSound, 0x139);
            return;
        case 1:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            QueueShine16SoundWhileRequested(shine16->mMapObject.mSound, 0x14e);
            return;
        case 6:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale -= 0x19a;
            if (shine16->mDrawScale > 0) {
                return;
            }
            shine16->mDrawScale = 0;
            ParkMapObject(&shine16->mMapObject);
            AddShineCount(-1);
            if (shine16->mSpawnObjectIndex < 0) {
                return;
            }
            ClearShineBattleObjectShine(shine16->mSpawnObjectIndex);
            return;
        case 2:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            kart = GetKart(shine16->mKartIndex);
            shine16->mHeightAboveKart += shine16->mMapObject.mPosStep.y;
            shine16->mMapObject.mPos = *GetKartStandingPos(shine16->mKartIndex);
            shine16->mMapObject.mPos.y += shine16->mHeightAboveKart + (GetKartBalloonOrShineHeight(kart) + 0x7800);
            shine16->mMapObject.mPosStep.y -= 0x333;
            if (shine16->mPickupTimer-- <= 0) {
                shine16->mPickupTimer = 0;
                shine16->mDrawScale -= 0x19a;
                if (shine16->mDrawScale <= 0) {
                    shine16->mDrawScale = 0;
                    ParkMapObject(&shine16->mMapObject);
                    AddShineCount(-1);
                    if (shine16->mSpawnObjectIndex >= 0) {
                        ClearShineBattleObjectShine(shine16->mSpawnObjectIndex);
                    }
                }
                if (shine16->mDrawScale <= 0) {
                    SetupKartFollowEffect(StartEffect(0x7c, &kart->mPos), kart->mIndex, 0x16);
                }
            } else {
                shine16->mDrawScale += 0x19a;
                if (shine16->mDrawScale >= 0x1000) {
                    shine16->mDrawScale = 0x1000;
                }
            }
            if (shine16->mEffect == NULL) {
                return;
            }
            PlaceEffect(shine16->mEffect, &shine16->mMapObject.mPos);
            shine16->mEffectTimer--;
            if (shine16->mEffectTimer >= 0) {
                return;
            }
            StopEffectAndClearPointer(&shine16->mEffect);
            return;
        case 3:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            for (battlePointIndex = 0; battlePointIndex < 2; battlePointIndex++) {
                forwardBattlePoint = MoveToRandomForwardBattlePoint();
                distance = forwardBattlePoint->mPos.y - GetKartStandingPos(shine16->mKartIndex)->y;
                if (distance <= 0) {
                    distance = -distance;
                }
                if (distance < 0x14000) {
                    deltaX = FROM_FIXED12(forwardBattlePoint->mPos.x - GetKartStandingPos(shine16->mHitByKartIndex)->x);
                    deltaZ = FROM_FIXED12(forwardBattlePoint->mPos.z - GetKartStandingPos(shine16->mHitByKartIndex)->z);
                    distance = deltaX * deltaX + deltaZ * deltaZ;
                    if (shine16->mHitByKartIndex == shine16->mKartIndex) {
                        if (distance < 0x9c400 && distance > shine16->mTargetDistanceSquared) {
                            shine16->mTargetDistanceSquared = distance;
                            shine16->mTargetPos.x = forwardBattlePoint->mPos.x;
                            shine16->mTargetPos.y = forwardBattlePoint->mPos.y;
                            shine16->mTargetPos.z = forwardBattlePoint->mPos.z;
                            shine16->mTargetPickCount++;
                        }
                    } else {
                        if (distance < 0x9c400 && distance < shine16->mTargetDistanceSquared) {
                            shine16->mTargetDistanceSquared = distance;
                            shine16->mTargetPos.x = forwardBattlePoint->mPos.x;
                            shine16->mTargetPos.y = forwardBattlePoint->mPos.y;
                            shine16->mTargetPos.z = forwardBattlePoint->mPos.z;
                            shine16->mTargetPickCount++;
                        }
                    }
                }
            }
            shine16->mHeightAboveKart += shine16->mMapObject.mPosStep.y;
            shine16->mMapObject.mPos = *GetKartStandingPos(shine16->mKartIndex);
            shine16->mMapObject.mPos.y +=
                shine16->mHeightAboveKart + (GetKartBalloonOrShineHeight(GetKart(shine16->mKartIndex)) + 0x7800);
            shine16->mMapObject.mPosStep.y -= 0x52;
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            if (shine16->mMapObject.mPosStep.y > 0) {
                return;
            }
            if (shine16->mTargetPickCount > 0) {
                randomState = &gRaceProgress->mRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                randomAngle = ((u64) (u32) (randomState->mValue >> 32) * 0x10000) >> 32;
                randomState = &gRaceProgress->mRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                randomRadius = ((u64) (u32) (randomState->mValue >> 32) * 0x14000) >> 32;
                deltaX = shine16->mTargetPos.x + MUL_FIXED12_NO_ROUND(randomRadius, FX_SinIdx(randomAngle)) -
                         shine16->mMapObject.mPos.x;
                deltaZ = shine16->mTargetPos.z + MUL_FIXED12_NO_ROUND(randomRadius, FX_CosIdx(randomAngle)) -
                         shine16->mMapObject.mPos.z;
                shine16->mState = 4;
                shine16->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(deltaX, 0x25);
                shine16->mMapObject.mPosStep.y = 0x5000;
                shine16->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(deltaZ, 0x25);
                shine16->mDrawScale = 0x1000;
                shine16->mMapObject.mFlags &= ~1;
                return;
            }
            shine16->mState = 5;
            shine16->mMapObject.mPosStep.x = 0;
            shine16->mMapObject.mPosStep.y = 0x5000;
            shine16->mMapObject.mPosStep.z = 0;
            shine16->mDrawScale = 0x1000;
            shine16->mMapObject.mFlags &= ~1;
            return;
        case 5:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            shine16->mMapObject.mPosStep.y -= 0x19a;
            VEC_Add(&shine16->mMapObject.mPos, &shine16->mMapObject.mPosStep, &shine16->mMapObject.mPos);
            if (shine16->mMapObject.mPosStep.y >= 0) {
                return;
            }
            shine16->mState = 6;
            shine16->mMapObject.mFlags |= gShine16HitFlag;
            return;
        case 4:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            shine16->mMapObject.mPosStep.y -= 0x19a;
            VEC_Add(&shine16->mMapObject.mPos, &shine16->mMapObject.mPosStep, &shine16->mMapObject.mPos);
            if (shine16->mMapObject.mPosStep.y < 0 &&
                shine16->mMapObject.mPos.y <= shine16->mTargetPos.y + shine16->mMapObject.mExtent.x) {
                if (GetMapObjectHitResponse(&shine16->mMapObject, 0, &pushOut)) {
                    savedVelocityY = shine16->mMapObject.mPosStep.y;
                    VEC_Add(&shine16->mMapObject.mPos, &pushOut, &shine16->mMapObject.mPos);
                    BounceVelocityOffUnnormalizedSurface(&shine16->mMapObject.mPosStep, &pushOut, 0x1000, 0x1000, 0x800,
                                                         &shine16->mMapObject.mPosStep);
                    shine16->mMapObject.mPosStep.y = 0;
                    if ((s64) shine16->mMapObject.mPosStep.x * shine16->mMapObject.mPosStep.x +
                            (s64) shine16->mMapObject.mPosStep.y * shine16->mMapObject.mPosStep.y +
                            (s64) shine16->mMapObject.mPosStep.z * shine16->mMapObject.mPosStep.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&shine16->mMapObject.mPosStep,
                                                           &shine16->mMapObject.mPosStep);
                    }
                    shine16->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.x, 0x1000);
                    shine16->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.y, 0x1000);
                    shine16->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.z, 0x1000);
                    shine16->mMapObject.mPosStep.y = savedVelocityY;
                }
                probePos.x = shine16->mMapObject.mPos.x;
                probePos.y = shine16->mMapObject.mExtent.x + (shine16->mMapObject.mPos.y - 0x14000);
                probePos.z = shine16->mMapObject.mPos.z;
                if (CollideSphereWithCourse(&probePos, NULL, 0, shine16->mMapObject.mExtent.x, 8, -2, &pushOut,
                                            &firstNormal, &secondNormal, &hitFlags, NULL, NULL, NULL, NULL)) {
                    VEC_Add(&shine16->mMapObject.mPos, &pushOut, &shine16->mMapObject.mPos);
                    if (hitFlags & 0x214300) {
                        savedVelocityY = shine16->mMapObject.mPosStep.y;
                        BounceVelocityOffSurface(&shine16->mMapObject.mPosStep, &secondNormal, 0x1000, 0x1000, 0x800,
                                                 &shine16->mMapObject.mPosStep);
                        shine16->mMapObject.mPosStep.y = 0;
                        if ((s64) shine16->mMapObject.mPosStep.x * shine16->mMapObject.mPosStep.x +
                                (s64) shine16->mMapObject.mPosStep.y * shine16->mMapObject.mPosStep.y +
                                (s64) shine16->mMapObject.mPosStep.z * shine16->mMapObject.mPosStep.z >=
                            0x10) {
                            Vec3NormalizeAndGetLengthUnchecked(&shine16->mMapObject.mPosStep,
                                                               &shine16->mMapObject.mPosStep);
                        }
                        shine16->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.x, 0x1000);
                        shine16->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.y, 0x1000);
                        shine16->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.z, 0x1000);
                        shine16->mMapObject.mPosStep.y = savedVelocityY;
                    }
                    if (hitFlags & 0x1e34ef) {
                        shine16->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.x, 0x19a);
                        shine16->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.y, -0x333);
                        shine16->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.z, 0x19a);
                        if (shine16->mMapObject.mPosStep.y < 0x1000) {
                            shine16->mMapObject.mPosStep.y = 0;
                            shine16->mState = 1;
                        }
                        QueueShine16Sound(shine16->mMapObject.mSound, 0x139);
                    }
                    if (hitFlags & 0x1000000) {
                        shine16->mMapObject.mFlags |= gShine16CollisionFlag;
                    } else {
                        shine16->mMapObject.mFlags &= ~0x20;
                    }
                }
            }
            if (shine16->mMapObject.mPos.y >= 0) {
                return;
            }
            shine16->mState = 6;
            shine16->mMapObject.mFlags |= gShine16HitFlag;
            return;
    }
}

MapObjectKindData *CreateShine16KindData(void) {
    MapObjectKindData *mapObjectKindData;

    mapObjectKindData = CreateMapObjectKindData(CollideKartWithShine16, NULL, NULL, 1, 0);
    mapObjectKindData->mHeightRangeMax = 0x190000;
    mapObjectKindData->mHeightRangeMin = -0x190000;
    return mapObjectKindData;
}

MapObjectList *CreateShine16DrawList(void) {
    return CreateMapObjectDrawList2(CreateShine16, DrawShine16, SetupDrawShine16);
}

MapObjectList *CreateShine16ShadowDrawList(void) {
    return CreateMapObjectDrawList1(ResetShine16ShadowAngleIndex, DrawShine16Shadow, AdvanceShine16ShadowAngleIndex);
}

MapObjectList *CreateShine16UpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateShine16, NULL);
}

// Parks each map object of kind 0x6a (Shine16) that is not already parked.
void ParkShine16Objects(void) {
    s32 mapObjectIndex;
    MapObject *mapObject;
    MapObjectList *mapObjectList;

    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16);
    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (mapObject = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if ((mapObject->mFlags & 0x100) == 0) {
            ParkMapObject(mapObject);
        }
    }
}

// Unparks a Shine16 at the position; a nonzero last argument drops it from above, zero leaves it resting.
void StartShine16(Vec3 *position, s32 spawnObjectIndex, s32 dropFromAbove) {
    Shine16 *shine16;

    shine16 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16));
    if (shine16 == NULL) {
        return;
    }
    if (dropFromAbove != 0) {
        shine16->mMapObject.mPos.x = position->x;
        shine16->mMapObject.mPos.y = position->y + 0x32000;
        shine16->mMapObject.mPos.z = position->z;
        shine16->mMapObject.mPosStep.x = 0;
        shine16->mMapObject.mPosStep.y = 0x2800;
        shine16->mMapObject.mPosStep.z = 0;
        shine16->mHeightAboveKart = 0;
        shine16->mFloorY = position->y + 0x14000;
        shine16->mState = 0;
    } else {
        shine16->mMapObject.mPos.x = position->x;
        shine16->mMapObject.mPos.y = position->y + 0x14000;
        shine16->mMapObject.mPos.z = position->z;
        shine16->mMapObject.mPosStep.x = 0;
        shine16->mMapObject.mPosStep.y = 0;
        shine16->mMapObject.mPosStep.z = 0;
        shine16->mHeightAboveKart = 0;
        shine16->mFloorY = 0;
        shine16->mState = 1;
    }
    shine16->mDrawScale = 0;
    shine16->mPickupTimer = 0;
    shine16->mSpawnObjectIndex = spawnObjectIndex;
    shine16->mMapObject.mFlags &= ~1;
    shine16->mMapObject.mFlags &= ~0x20;
    AddShineCount(1);
    QueueShine16Sound(shine16->mMapObject.mSound, 0x138);
}

void StartShine16FromKart(Kart *hitKart, Kart *hitByKart) {
    Shine16 *shine16;
    s32 isEntryKart;
    u16 highestBalloonOrShineCount;
    s32 balloonOrShineCount;

    shine16 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16));
    if (shine16 == NULL) {
        return;
    }
    shine16->mMapObject.mFlags = shine16->mMapObject.mFlags | gShine16HitFlag;
    shine16->mMapObject.mFlags &= ~0x20;
    shine16->mMapObject.mPos.x = hitKart->mPos.x;
    shine16->mMapObject.mPos.y = hitKart->mPos.y;
    shine16->mMapObject.mPos.z = hitKart->mPos.z;
    shine16->mMapObject.mPosStep.x = 0;
    shine16->mMapObject.mPosStep.y = 0x1000;
    shine16->mMapObject.mPosStep.z = 0;
    shine16->mKartIndex = hitKart->mIndex;
    shine16->mHitByKartIndex = hitByKart->mIndex;
    shine16->mHeightAboveKart = 0;
    shine16->mFloorY = 0;
    shine16->mDrawScale = 0;
    shine16->mPickupTimer = 0;
    shine16->mState = 3;
    shine16->mTargetPos = hitByKart->mPos;
    if (hitByKart == hitKart) {
        shine16->mTargetDistanceSquared = 0;
    } else {
        shine16->mTargetDistanceSquared = 0x9c400;
    }
    shine16->mTargetPickCount = 0;
    shine16->mSpawnObjectIndex = -1;
    AddShineCount(1);
    isEntryKart = hitKart->mIndex == gRaceSetup->mEntryIndex ? 1 : 0;
    highestBalloonOrShineCount = GetHighestBalloonOrShineCount();
    balloonOrShineCount = GetBalloonOrShineCount(hitKart->mIndex);
    QueueShine16Sound(shine16->mMapObject.mSound,
                      GetShine16SoundId(1, isEntryKart, highestBalloonOrShineCount, balloonOrShineCount));
}

BOOL BalloonKartHitByKartCallback(u16 hitKartIndex, u16 hitByKartIndex) {
    Kart *kart;
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;
    Vec3 balloonPos;
    s32 balloonOrShineCount;

    kart = GetKart(hitKartIndex);
    GetStandingsKartBalloons();
    if (GetBalloonOrShineCount(hitByKartIndex) >= 3 || GetBalloonOrShineCount(hitKartIndex) == 0) {
        kartBalloons = GetStandingsKartBalloons() + hitKartIndex;
        inflatingBalloon = IsKartInflatingBalloon(hitKartIndex) != 0
                               ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)]
                               : 0;
        lastBalloon = GetBalloonOrShineCount(hitKartIndex) != 0
                          ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex) - 1]
                          : 0;
        if (GetBalloonOrShineCount(hitKartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(hitKartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            if (hitKartIndex == gRaceSetup->mEntryIndex) {
                StartBalloonWithoutKart(lastBalloon, NULL);
            } else {
                balloonPos.x = kart->mPos.x;
                balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
                balloonPos.z = kart->mPos.z;
                lastBalloon->mMapObject.mFlags &= ~4;
                lastBalloon->mMapObject.mFlags &= ~2;
                lastBalloon->mMapObject.mFlags &= ~8;
                lastBalloon->mMapObject.mAlpha = 0x1f;
                StartBalloonWithoutKart(lastBalloon, &balloonPos);
            }
            StartSoundFullVolumeWrapper(kart, 0x153);
            if (GetBalloonOrShineCount(hitKartIndex) == 0) {
                EliminateKartAndCheckWinner(hitKartIndex);
            }
            return FALSE;
        }
    } else {
        kartBalloons = GetStandingsKartBalloons() + hitKartIndex;
        inflatingBalloon = IsKartInflatingBalloon(hitKartIndex) != 0
                               ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)]
                               : 0;
        lastBalloon = GetBalloonOrShineCount(hitKartIndex) != 0
                          ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex) - 1]
                          : 0;
        if (GetBalloonOrShineCount(hitKartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(hitKartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            kartBalloons = GetStandingsKartBalloons() + hitByKartIndex;
            balloonOrShineCount = GetBalloonOrShineCount(hitByKartIndex);
            kartBalloons->mBalloons[balloonOrShineCount + 1] =
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitByKartIndex)];
            kartBalloons->mBalloons[GetBalloonOrShineCount(hitByKartIndex)] = lastBalloon;
            AddBalloonOrShineCountAndMoveRank(hitByKartIndex, 1);
            DisableBalloonHorizontalPull(lastBalloon);
            SetBalloonKartIndex(lastBalloon, hitByKartIndex);
            if (GetBalloonOrShineCount(hitByKartIndex) >= 2 && IsKartInflatingBalloon(hitByKartIndex) != 0) {
                kartBalloons->mState = 4;
            }
            SetupKartFollowEffect(StartEffect(0x7a, &kart->mPos), kart->mIndex, 0x20);
            SetupKartFollowEffect(StartEffect(0x7b, &kart->mPos), kart->mIndex, 0x20);
            StartSoundFullVolumeWrapper(GetKart(hitByKartIndex), 0x14f);
            if (GetBalloonOrShineCount(hitKartIndex) == 0) {
                EliminateKartAndCheckWinner(hitKartIndex);
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 BalloonKartsHitEachOtherCallback(u16 firstKartIndex, u16 secondKartIndex) {
    KartBalloons *firstKartBalloons;
    KartBalloons *secondKartBalloons;
    Balloon *firstInflatingBalloon;
    Balloon *firstLastBalloon;
    Balloon *secondInflatingBalloon;
    Balloon *secondLastBalloon;
    SoundStartParams soundStartParams;
    s32 balloonOrShineCount;

    firstKartBalloons = GetStandingsKartBalloons();
    firstKartBalloons += firstKartIndex;
    firstInflatingBalloon = IsKartInflatingBalloon(firstKartIndex) != 0
                                ? firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)]
                                : 0;
    firstLastBalloon = GetBalloonOrShineCount(firstKartIndex) != 0
                           ? firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex) - 1]
                           : 0;
    if (GetBalloonOrShineCount(firstKartIndex) != 0 && firstLastBalloon != NULL) {
        if (IsKartInflatingBalloon(firstKartIndex) != 0 && firstInflatingBalloon != NULL) {
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = firstLastBalloon;
            AddBalloonOrShineCountAndMoveRank(firstKartIndex, -1);
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = firstInflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(firstKartIndex, -1);
        }
    }
    secondKartBalloons = GetStandingsKartBalloons();
    secondKartBalloons += secondKartIndex;
    secondInflatingBalloon = IsKartInflatingBalloon(secondKartIndex) != 0
                                 ? secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)]
                                 : 0;
    secondLastBalloon = GetBalloonOrShineCount(secondKartIndex) != 0
                            ? secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex) - 1]
                            : 0;
    if (GetBalloonOrShineCount(secondKartIndex) != 0 && secondLastBalloon != NULL) {
        if (IsKartInflatingBalloon(secondKartIndex) != 0 && secondInflatingBalloon != NULL) {
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = secondLastBalloon;
            AddBalloonOrShineCountAndMoveRank(secondKartIndex, -1);
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = secondInflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(secondKartIndex, -1);
        }
    }
    if (firstLastBalloon != NULL) {
        secondKartBalloons = GetStandingsKartBalloons();
        secondKartBalloons += secondKartIndex;
        balloonOrShineCount = GetBalloonOrShineCount(secondKartIndex);
        secondKartBalloons->mBalloons[balloonOrShineCount + 1] =
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)];
        secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = firstLastBalloon;
        AddBalloonOrShineCountAndMoveRank(secondKartIndex, 1);
        DisableBalloonHorizontalPull(firstLastBalloon);
        SetBalloonKartIndex(firstLastBalloon, secondKartIndex);
        if (GetBalloonOrShineCount(secondKartIndex) >= 2 && IsKartInflatingBalloon(secondKartIndex) != 0) {
            secondKartBalloons->mState = 4;
        }
    }
    if (secondLastBalloon != NULL) {
        firstKartBalloons = GetStandingsKartBalloons();
        firstKartBalloons += firstKartIndex;
        balloonOrShineCount = GetBalloonOrShineCount(firstKartIndex);
        firstKartBalloons->mBalloons[balloonOrShineCount + 1] =
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)];
        firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = secondLastBalloon;
        AddBalloonOrShineCountAndMoveRank(firstKartIndex, 1);
        DisableBalloonHorizontalPull(secondLastBalloon);
        SetBalloonKartIndex(secondLastBalloon, firstKartIndex);
        if (GetBalloonOrShineCount(firstKartIndex) >= 2 && IsKartInflatingBalloon(firstKartIndex) != 0) {
            firstKartBalloons->mState = 4;
        }
    }
    if (firstKartIndex == gRaceSetup->mEntryIndex || secondKartIndex == gRaceSetup->mEntryIndex) {
        soundStartParams.mSoundId = 0x14f;
        soundStartParams.mPositionSource = NULL;
        soundStartParams.mFalloffIndex = 2;
        soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        StartSoundFromParams(&soundStartParams);
    }
    return 1;
}

BOOL BalloonKartHitCallback(u16 kartIndex, u16 hitByKartIndex) {
    Kart *kart;
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;
    Vec3 balloonPos;

    kartBalloons = GetStandingsKartBalloons() + kartIndex;
    inflatingBalloon =
        IsKartInflatingBalloon(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] : 0;
    lastBalloon =
        GetBalloonOrShineCount(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex) - 1] : 0;
    if (GetBalloonOrShineCount(kartIndex) != 0 && lastBalloon != NULL) {
        if (IsKartInflatingBalloon(kartIndex) != 0 && inflatingBalloon != NULL) {
            kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = lastBalloon;
            AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
            kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = inflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
        }
    }
    if (lastBalloon != NULL) {
        kart = GetKart(kartIndex);
        GetStandingsKartBalloons();
        if (kartIndex == gRaceSetup->mEntryIndex) {
            StartBalloonWithoutKart(lastBalloon, NULL);
        } else {
            balloonPos.x = kart->mPos.x;
            balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
            balloonPos.z = kart->mPos.z;
            lastBalloon->mMapObject.mFlags &= ~4;
            lastBalloon->mMapObject.mFlags &= ~2;
            lastBalloon->mMapObject.mFlags &= ~8;
            lastBalloon->mMapObject.mAlpha = 0x1f;
            StartBalloonWithoutKart(lastBalloon, &balloonPos);
        }
        StartSoundFullVolumeWrapper(kart, 0x153);
        if (GetBalloonOrShineCount(kartIndex) == 0) {
            EliminateKartAndCheckWinner(kartIndex);
        }
        return TRUE;
    }
    return FALSE;
}

void BalloonKartEliminatedCallback(u16 kartIndex) {
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;

    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    BalloonKartHitCallback(kartIndex, kartIndex);
    if (GetBalloonOrShineCount(kartIndex) == 0) {
        return;
    }
    do {
        kartBalloons = GetStandingsKartBalloons() + kartIndex;
        inflatingBalloon =
            IsKartInflatingBalloon(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] : 0;
        lastBalloon =
            GetBalloonOrShineCount(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex) - 1] : 0;
        if (GetBalloonOrShineCount(kartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(kartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            ParkBalloon(lastBalloon, kartIndex);
        }
    } while (GetBalloonOrShineCount(kartIndex) != 0);
}

void BalloonEndCallback(void) {
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    ResetBalloons();
}

void BalloonKartOffsetCallback(u16 kartIndex, Vec3 *offset) {
    KartBalloons *kartBalloons;
    Balloon *balloon;
    s32 balloonIndex;
    s32 balloonCount;

    kartBalloons = GetStandingsKartBalloons() + kartIndex;
    if (offset == NULL) {
        return;
    }
    balloonCount = (IsKartInflatingBalloon(kartIndex) != 0 ? 1 : 0) + GetBalloonOrShineCount(kartIndex);
    balloonIndex = 0;
    if (balloonCount <= 0) {
        return;
    }
    do {
        balloon = kartBalloons->mBalloons[balloonIndex];
        balloon->mMapObject.mPos.x += offset->x;
        balloon->mMapObject.mPos.y += offset->y;
        balloon->mMapObject.mPos.z += offset->z;
        balloonIndex++;
    } while (balloonIndex < balloonCount);
}

// Init of the kind 0x69 object: creates and parks the kind 0x6c balloon objects (0x20 in mode 2, else 4), fills the
// frame indices, offsets and start timer, sets Standings.mKartBalloons and registers the callbacks in Standings (four
// hit callbacks, the kart-eliminated and the end callback). If kind 0x6c already exists it parks itself instead.
void InitKartBalloons(KartBalloonsObject *kartBalloonsObject) {
    RaceSetup *raceSetup;
    s32 kartCount;
    s32 index;
    KartBalloons *kartBalloons;
    s32 balloonIndex;
    s32 rowOffset;
    s32 offset;

    if (CountMapObjectsOfKind(MAP_OBJECT_KIND_BALLOON) == 0) {
        raceSetup = gRaceSetup;
        kartCount = raceSetup->mKartCount;
        if (raceSetup->mMode == MODE_BATTLE) {
            CreateParkedMapObjects(MAP_OBJECT_KIND_BALLOON, 0x20, kartBalloonsObject);
        } else {
            CreateParkedMapObjects(MAP_OBJECT_KIND_BALLOON, 4, kartBalloonsObject);
        }
        for (index = 0; index < kartCount; index++) {
            kartBalloons = &kartBalloonsObject->mKartBalloons[index];
            if (kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[2] != 0) {
                kartBalloons->mBalloonNsbtpFrameIndex = kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[2];
            } else {
                switch (GetCurrentEntry(index)->mPlayer.mTeamIndex) {
                    case 0:
                        kartBalloons->mBalloonNsbtpFrameIndex = 1;
                        break;
                    case 1:
                        kartBalloons->mBalloonNsbtpFrameIndex = 3;
                        break;
                    default:
                        kartBalloons->mBalloonNsbtpFrameIndex = index;
                        break;
                }
            }
        }
        for (index = 0, rowOffset = 0; index < 8; index++, rowOffset -= 0x600) {
            for (balloonIndex = 0, offset = rowOffset; balloonIndex < 8; balloonIndex++, offset += 0xc00) {
                kartBalloonsObject->mBalloonOffsets[index][balloonIndex] = offset;
            }
        }
        if (GetRaceUseChainCameras() != 0) {
            kartBalloonsObject->mStartTimer = 0xffff;
        } else {
            kartBalloonsObject->mStartTimer = 0x3c;
        }
        SetStandingsKartBalloons(kartBalloonsObject->mKartBalloons);
        SetStandingsKartHitByKartCallback((s32(*)(s32, s32)) BalloonKartHitByKartCallback);
        SetStandingsKartsHitEachOtherCallback((void (*)(s32, s32)) BalloonKartsHitEachOtherCallback);
        SetStandingsKartHitCallback(BalloonKartHitCallback);
        SetStandingsKartEliminatedCallback(BalloonKartEliminatedCallback);
        SetStandingsEndCallback(BalloonEndCallback);
        SetStandingsKartOffsetCallback(BalloonKartOffsetCallback);
    } else {
        ParkMapObject(&kartBalloonsObject->mMapObject);
    }
}

// Per-frame step of the kind 0x69 object: after mStartTimer runs out it steps every kart's KartBalloons (makes,
// inflates, holds and deflates its balloons), updates the kart's count and hands each balloon its kart index, target
// position and velocity.
void UpdateKartBalloons(void *mapObjectList, KartBalloonsObject *kartBalloonsObject) {
    Balloon *balloon;
    s32 kartIndex;
    s32 balloonIndex;
    s32 kartCount;
    s32 balloonCount;
    s32 sideOffset;
    s32 swingStep;
    s32 swingPerFrameDecrement;
    Vec3 balloonPos;
    Vec3 addend;
    Vec3 oddBalloonAddend;
    Vec3 *kartVector;

    kartCount = gRaceSetup->mKartCount;
    if (kartBalloonsObject->mStartTimer > 0) {
        kartBalloonsObject->mStartTimer--;
        if (kartBalloonsObject->mStartTimer > 0) {
            return;
        }
        for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
            KartBalloons *kartBalloons = &kartBalloonsObject->mKartBalloons[kartIndex];
            GetKart((u16) kartIndex);
            kartBalloons->mState = 1;
            if (kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[0] != 0 ||
                kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[1] != 0) {
                kartBalloons->mRemainingSpawnCount = kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[0];
                AddBalloonsLeftToMake(kartIndex, kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[0] +
                                                     kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[1]);
            } else {
                kartBalloons->mRemainingSpawnCount = 1;
                AddBalloonsLeftToMake(kartIndex, 5);
            }
        }
        return;
    }
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        Kart *kart;
        KartBalloons *kartBalloons = &kartBalloonsObject->mKartBalloons[kartIndex];
        GetChaseCamera();
        kart = GetKart((u16) kartIndex);
        balloonPos.x = kart->mPos.x;
        balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
        balloonPos.z = kart->mPos.z;
        switch (kartBalloons->mState) {
            case 0:
                if (kartBalloons->mSpawnTimer > 0) {
                    kartBalloons->mSpawnTimer--;
                    break;
                }
                if (GetBalloonsLeftToMake(kartIndex) == 0) {
                    break;
                }
                if (GetBalloonOrShineCount(kartIndex) >= 3) {
                    break;
                }
                if (GetKartMicInflateTimer(kartIndex) <= 0 && GetKartSelectKeyInflate(kartIndex) <= 0) {
                    break;
                }
                balloon = StartBalloon(kartBalloons->mBalloonNsbtpFrameIndex, &balloonPos);
                if (balloon == NULL) {
                    break;
                }
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = balloon;
                UpdateBalloonInflating(balloon, kartIndex, 0xcd);
                kartBalloons->mState = 2;
                SetKartInflatingBalloon(kartIndex, 1);
                AddBalloonsLeftToMake(kartIndex, -1);
                break;
            case 1:
                if (IsKartInflatingBalloon(kartIndex) != 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)], kartIndex,
                                           0x266);
                    break;
                }
                if (GetBalloonsLeftToMake(kartIndex) != 0 && GetBalloonOrShineCount(kartIndex) < 3) {
                    if (kartBalloons->mRemainingSpawnCount > 0) {
                        balloon = StartBalloon(kartBalloons->mBalloonNsbtpFrameIndex, &balloonPos);
                        if (balloon != NULL) {
                            kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = balloon;
                            UpdateBalloonInflating(balloon, kartIndex, 0x266);
                            SetKartInflatingBalloon(kartIndex, 1);
                            AddBalloonsLeftToMake(kartIndex, -1);
                            kartBalloons->mRemainingSpawnCount--;
                        }
                    }
                } else {
                    kartBalloons->mState = 0;
                }
                break;
            case 2:
                if (GetKartMicInflateTimer(kartIndex) < 0) {
                    kartBalloons->mState = 4;
                    break;
                }
                balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)];
                UpdateBalloonInflating(balloon, kartIndex, 0xcd);
                if (GetBalloonScaleFactor(balloon) >= 0x800) {
                    kartBalloons->mState = 3;
                }
                break;
            case 3:
                if (GetKartMicInflateTimer(kartIndex) < 0) {
                    kartBalloons->mState = 4;
                    break;
                }
                if (GetKartSelectKeyInflate(kartIndex) > 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)], kartIndex, 0x10);
                } else if (GetKartMicInflateTimer(kartIndex) > 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)], kartIndex, 0x29);
                } else {
                    balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)];
                    UpdateBalloonShrinking(balloon, kartIndex, 0xe);
                    if (GetBalloonScaleFactor(balloon) <= 0x400) {
                        kartBalloons->mState = 4;
                    }
                }
                break;
            case 4:
                UpdateBalloonShrinking(kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)], kartIndex, 0x19a);
                break;
        }
        if (IsKartInflatingBalloon(kartIndex) != 0) {
            balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)];
            if (GetBalloonScaleFactor(balloon) <= 0) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = NULL;
                SetKartInflatingBalloon(kartIndex, 0);
                AddBalloonsLeftToMake(kartIndex, 1);
                kartBalloons->mSpawnTimer = 0;
                kartBalloons->mState = 0;
            } else if (GetBalloonScaleFactor(balloon) >= 0x1000) {
                SetKartInflatingBalloon(kartIndex, 0);
                AddBalloonOrShineCountAndMoveRank(kartIndex, 1);
                if (kartBalloons->mRemainingSpawnCount <= 0) {
                    kartBalloons->mSpawnTimer = 30;
                    kartBalloons->mState = 0;
                }
                StartSoundFullVolumeWrapper(GetKart((u16) kartIndex), 0x152);
            }
        } else if (kartBalloons->mRemainingSpawnCount <= 0) {
            kartBalloons->mState = 0;
        }
        if (kartIndex == gRaceSetup->mEntryIndex) {
            if (GetKartMicInflateTimer(kartIndex) > 0 || GetKartSelectKeyInflate(kartIndex) > 0) {
                swingStep = GetBalloonOrShineCount(kartIndex) >= 3 ? 600 : 300;
                swingPerFrameDecrement = GetBalloonOrShineCount(kartIndex) >= 3 ? 200 : 100;
                kartBalloons->mSwing += kartBalloons->mSwingPerFrame;
                if (kartBalloons->mSwing >= 0) {
                    if (kartBalloons->mSwingPerFrame < 0) {
                        kartBalloons->mSwingPerFrame = -swingStep;
                    } else {
                        kartBalloons->mSwingPerFrame -= swingPerFrameDecrement;
                    }
                } else {
                    if (kartBalloons->mSwingPerFrame >= 0) {
                        kartBalloons->mSwingPerFrame = swingStep;
                    } else {
                        kartBalloons->mSwingPerFrame += swingPerFrameDecrement;
                    }
                }
            } else {
                swingStep = GetBalloonOrShineCount(kartIndex) >= 3 ? 600 : 300;
                if (kartBalloons->mSwing >= 0) {
                    kartBalloons->mSwing = kartBalloons->mSwing < swingStep ? 0 : kartBalloons->mSwing - swingStep;
                } else {
                    kartBalloons->mSwing = kartBalloons->mSwing > -swingStep ? 0 : kartBalloons->mSwing + swingStep;
                }
            }
            balloonCount = GetBalloonOrShineCount(kartIndex) + (IsKartInflatingBalloon(kartIndex) != 0 ? 1 : 0);
            for (balloonIndex = 0; balloonIndex < balloonCount; balloonIndex++) {
                Balloon *balloon = kartBalloons->mBalloons[balloonIndex];
                sideOffset = kartBalloons->mSwing + kartBalloonsObject->mBalloonOffsets[balloonCount - 1][balloonIndex];
                if (sideOffset != 0) {
                    kartVector = &kart->mUnk_150;
                    addend.x = MUL_FIXED12_NO_ROUND(kartVector->x, sideOffset);
                    addend.y = MUL_FIXED12_NO_ROUND(kartVector->y, sideOffset);
                    addend.z = MUL_FIXED12_NO_ROUND(kartVector->z, sideOffset);
                    AddBalloonVelocity(balloon, &addend);
                }
                if ((balloonIndex & 1) == 1) {
                    kartVector = &kart->mUnk_168;
                    oddBalloonAddend.x = MUL_FIXED12_NO_ROUND(kartVector->x, -0xcd);
                    oddBalloonAddend.y = MUL_FIXED12_NO_ROUND(kartVector->y, -0xcd);
                    oddBalloonAddend.z = MUL_FIXED12_NO_ROUND(kartVector->z, -0xcd);
                    AddBalloonVelocity(balloon, &oddBalloonAddend);
                }
                SetBalloonTargetPosAndVelocity(balloon, &balloonPos, &kart->mVelocity);
                SetBalloonKartIndex(balloon, kartIndex);
                SetBalloonDrawCountAndList(balloon, 1, NULL);
                balloon->mMapObject.mFlags &= ~4;
                balloon->mMapObject.mFlags &= ~2;
                balloon->mMapObject.mFlags &= ~8;
                balloon->mMapObject.mAlpha = 0x1f;
            }
        } else {
            balloonCount = GetBalloonOrShineCount(kartIndex) + (IsKartInflatingBalloon(kartIndex) != 0 ? 1 : 0);
            for (balloonIndex = 0; balloonIndex < balloonCount; balloonIndex++) {
                balloon = kartBalloons->mBalloons[balloonIndex];
                SetBalloonTargetPosAndVelocity(balloon, &balloonPos, &kart->mVelocity);
                SetBalloonKartIndex(balloon, kartIndex);
                if (balloonIndex == 0) {
                    SetBalloonDrawCountAndList(balloon, balloonCount, kartBalloons->mBalloons);
                    balloon->mMapObject.mFlags &= ~4;
                    balloon->mMapObject.mFlags &= ~2;
                    balloon->mMapObject.mFlags &= ~8;
                    balloon->mMapObject.mAlpha = 0x1f;
                } else {
                    SetBalloonDrawCountAndList(balloon, 0, NULL);
                    balloon->mMapObject.mFlags |= gBalloonHideFirstFlag;
                    balloon->mMapObject.mFlags |= gBalloonHideSecondFlag;
                    balloon->mMapObject.mFlags |= gBalloonHideThirdFlag;
                }
            }
        }
    }
}

MapObjectKindData *CreateKartBalloonsKindData(void) {
    RaceSetup *raceSetup;
    s32 mode;

    raceSetup = gRaceSetup;
    mode = raceSetup->mMode;
    if (mode == MODE_BATTLE && raceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        return CreateEmptyMapObjectKindData();
    }
    if (mode != MODE_MISSION_RUN) {
        return 0;
    }
    return CreateEmptyMapObjectKindData();
}

MapObjectList *CreateKartBalloonsUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateKartBalloons, NULL);
}

const u16 gShine16HitFlag = 1;
const u16 gBalloonHideThirdFlag = 8;
const u16 gBalloonHideSecondFlag = 2;
const u16 gBalloonHideFirstFlag = 4;
