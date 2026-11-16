#include "Main/MapObjects/balloon_draw.h"
#include "Main/Sound/kart_sound.h"
#include "Main/MapObjects/map_object_model_frame.h"

#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/map_object_sound_counter.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "particle_instance.h"
#include "fixed_arctangent.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/bound.h"

const u16 gBalloonDrawRotateZAngles[4][4] = {
    {0x4000, 0, 0, 0}, {0x499a, 0x3666, 0, 0}, {0x527d, 0x4000, 0x2d83, 0}, {0, 0, 0, 0}};
const s32 gBalloonDrawListIndices[4][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 2, 1, 0}, {0, 0, 0, 0}};
MapObjectModel *gBalloon;
Vec3 gBalloonCameraPosEighth;
Vec3 gBalloonCameraPosHalf;

MapObjectKindDescriptor gBalloonKindDescriptor = {0,
                                             {0, 0},
                                             0x100,
                                             InitBalloon,
                                             CreateEmptyMapObjectKindData,
                                             CreateBalloonDrawList,
                                             0,
                                             0,
                                             CreateBalloonUpdateList};

void InitBalloon(Balloon *balloon) {
    balloon->mKartIndex = -1;
    ParkMapObject(&balloon->mMapObject);
}

void CreateBalloon(MapObjectList *mapObjectList) {
    gBalloon = CreateMapObjectFromModelAndAnimation_from_thumb(mapObjectList, "balloon.nsbmd", "balloon.nsbtp");
    StructMapObject_MaybeSetPolygonId(gBalloon, 0x3f);
    StructMapObject_SomeFn_6(gBalloon, 0x1a);
    StructMapObject_SomeFn_7(gBalloon, 0);
    mapObjectList->mSortByDistance = 1;
}

void SetupDrawBalloon(void *mapObjectList) {
    Camera *currentCamera;

    currentCamera = GetGlobalHD4();
    gBalloonCameraPosHalf.x = currentCamera->mPos.x >> 1;
    gBalloonCameraPosHalf.y = currentCamera->mPos.y >> 1;
    gBalloonCameraPosHalf.z = currentCamera->mPos.z >> 1;
    gBalloonCameraPosEighth.x = currentCamera->mPos.x >> 3;
    gBalloonCameraPosEighth.y = currentCamera->mPos.y >> 3;
    gBalloonCameraPosEighth.z = currentCamera->mPos.z >> 3;
    StructMapObject_SomeFn_9(mapObjectList, gBalloon);
}

void DrawBalloon(void *mapObjectList, Balloon *balloon) {
    s32 drawListIndex;
    s32 drawCount;
    s32 index;
    s32 rotateZAngle;
    s32 drawScale;
    u32 distanceSquared;
    s32 scaleFactor;
    s32 restoreIndex;
    s32 listRestoreIndex;
    s32 popCount;
    MtxFx33 rotateZMatrix;
    MtxFx33 listRotateZMatrix;
    s32 drawScaleVector[3];
    s32 scaleFactorVector[3];
    s32 listDrawScaleVector[3];
    s32 listScaleFactorVector[3];
    s32 translation[3];
    Balloon *listBalloon;

    if (balloon->mKartIndex >= 0) {
        if (GetRacerMQEntry(balloon->mKartIndex)->mVisible == 0) {
            return;
        }
    }
    drawCount = balloon->mDrawCount;
    if (drawCount == 1 && balloon->mDrawList == NULL) {
        distanceSquared = balloon->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f;
        if (distanceSquared < 0x2710) {
            balloon->mDrawPos.x = gBalloonCameraPosHalf.x + (balloon->mMapObject.mPos.x >> 1);
            balloon->mDrawPos.y = gBalloonCameraPosHalf.y + (balloon->mMapObject.mPos.y >> 1);
            balloon->mDrawPos.z = gBalloonCameraPosHalf.z + (balloon->mMapObject.mPos.z >> 1);
            balloon->mDrawScale = FIXED12_RATIO(1, 2);
        } else if (distanceSquared < 0x9c40) {
            balloon->mDrawPos.x =
                gBalloonCameraPosEighth.x + balloon->mMapObject.mPos.x - (balloon->mMapObject.mPos.x >> 3);
            balloon->mDrawPos.y =
                gBalloonCameraPosEighth.y + balloon->mMapObject.mPos.y - (balloon->mMapObject.mPos.y >> 3);
            balloon->mDrawPos.z =
                gBalloonCameraPosEighth.z + balloon->mMapObject.mPos.z - (balloon->mMapObject.mPos.z >> 3);
            balloon->mDrawScale = FIXED12_RATIO(7, 8);
        } else {
            balloon->mDrawPos = balloon->mMapObject.mPos;
            balloon->mDrawScale = TO_FIXED12(1);
        }
        restoreIndex = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &restoreIndex, 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&balloon->mDrawPos), 12);
        if (balloon->mMapObject.mAngle != 0) {
            MTX_RotZ33__from_thumb(&rotateZMatrix, COS_OF_ANGLE(balloon->mMapObject.mAngle),
                        SIN_OF_ANGLE(balloon->mMapObject.mAngle));
            NNS_G3dGeBufferOP_N(0x1a, &rotateZMatrix, 9);
        }
        drawScale = balloon->mDrawScale;
        drawScaleVector[0] = drawScale;
        drawScaleVector[1] = drawScale;
        drawScaleVector[2] = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, drawScaleVector, 3);
        scaleFactor = balloon->mScaleFactor + balloon->mScaleSwing;
        if (scaleFactor != 0x1000) {
            scaleFactorVector[0] = scaleFactor;
            scaleFactorVector[1] = scaleFactor;
            scaleFactorVector[2] = scaleFactor;
            NNS_G3dGeBufferOP_N(0x1b, scaleFactorVector, 3);
        }
        StructMapObject_MaybeSetPolygonId(gBalloon, AllocPolygonIdWrapping());
        StructMapObject_SomeFn_0(gBalloon, balloon->mNsbtpFrameIndex);
        DrawMapObjectModel(mapObjectList, gBalloon, balloon);
    } else if (drawCount > 0) {
        distanceSquared = balloon->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f;
        if (distanceSquared < 0x2710) {
            balloon->mDrawPos.x = gBalloonCameraPosHalf.x + (balloon->mTargetPos.x >> 1);
            balloon->mDrawPos.y = gBalloonCameraPosHalf.y + (balloon->mTargetPos.y >> 1);
            balloon->mDrawPos.z = gBalloonCameraPosHalf.z + (balloon->mTargetPos.z >> 1);
            balloon->mDrawScale = FIXED12_RATIO(1, 2);
        } else if (distanceSquared < 0x9c40) {
            balloon->mDrawPos.x = gBalloonCameraPosEighth.x + balloon->mTargetPos.x - (balloon->mTargetPos.x >> 3);
            balloon->mDrawPos.y = gBalloonCameraPosEighth.y + balloon->mTargetPos.y - (balloon->mTargetPos.y >> 3);
            balloon->mDrawPos.z = gBalloonCameraPosEighth.z + balloon->mTargetPos.z - (balloon->mTargetPos.z >> 3);
            balloon->mDrawScale = FIXED12_RATIO(7, 8);
        } else {
            balloon->mDrawPos = balloon->mTargetPos;
            balloon->mDrawScale = TO_FIXED12(1);
        }
        listRestoreIndex = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &listRestoreIndex, 1);
        NNS_G3dGeBufferOP_N(0x19, MaybeGetBBMtxAtPosition(&balloon->mDrawPos), 12);
        drawScale = balloon->mDrawScale;
        listDrawScaleVector[0] = drawScale;
        listDrawScaleVector[1] = drawScale;
        listDrawScaleVector[2] = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, listDrawScaleVector, 3);
        for (drawListIndex = 0; drawListIndex < drawCount; drawListIndex++) {
            index = gBalloonDrawListIndices[drawCount - 1][drawListIndex];
            listBalloon = balloon->mDrawList[index];
            NNS_G3dGeBufferOP_N(0x11, NULL, 0);
            rotateZAngle = gBalloonDrawRotateZAngles[drawCount - 1][index];
            MTX_RotZ33__from_thumb(&listRotateZMatrix, FX_CosIdx(rotateZAngle), FX_SinIdx(rotateZAngle));
            NNS_G3dGeBufferOP_N(0x1a, &listRotateZMatrix, 9);
            scaleFactor = listBalloon->mScaleFactor;
            if (scaleFactor != 0x1000) {
                listScaleFactorVector[0] = scaleFactor;
                listScaleFactorVector[1] = scaleFactor;
                listScaleFactorVector[2] = scaleFactor;
                NNS_G3dGeBufferOP_N(0x1b, listScaleFactorVector, 3);
            }
            translation[0] = 0;
            translation[1] = 0xf66;
            translation[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, translation, 3);
            StructMapObject_MaybeSetPolygonId(gBalloon, AllocPolygonIdWrapping());
            StructMapObject_SomeFn_0(gBalloon, listBalloon->mNsbtpFrameIndex);
            DrawMapObjectModel(mapObjectList, gBalloon, balloon);
            popCount = 1;
            NNS_G3dGeBufferOP_N(0x12, &popCount, 1);
        }
    }
}

void SetBalloonEffectColor(ParticleEmitter *effect, Balloon *balloon) {
    effect->mColor = GetKartPaletteColorFromTable(balloon->mNsbtpFrameIndex);
}

void FollowBalloonTarget(Balloon *balloon) {
    Kart *kart;
    Vec3 *kartVector;
    Vec3 pullOffset;
    s32 pullRatio;
    s32 distanceLimit;
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    s32 absOffsetX;
    s32 absOffsetY;
    s32 absOffsetZ;
    s32 offsetDistance;

    if (balloon->mKartIndex < 0) {
        balloon->mMapObject.mPosStep.y = balloon->mMapObject.mPosStep.y + 0x1800;
    } else {
        kart = GetRacerMQEntry((u16) balloon->mKartIndex);
        kartVector = &kart->mRotationRow1;
        balloon->mMapObject.mPosStep.x = balloon->mMapObject.mPosStep.x + (kartVector->x + (kartVector->x >> 1));
        balloon->mMapObject.mPosStep.y = balloon->mMapObject.mPosStep.y + (kartVector->y + (kartVector->y >> 1));
        balloon->mMapObject.mPosStep.z = balloon->mMapObject.mPosStep.z + (kartVector->z + (kartVector->z >> 1));
    }
    offsetX = (balloon->mMapObject.mPos.x + balloon->mMapObject.mPosStep.x) -
              (balloon->mTargetPos.x + balloon->mTargetVelocity.x);
    offsetZ = (balloon->mMapObject.mPos.z + balloon->mMapObject.mPosStep.z) -
              (balloon->mTargetPos.z + balloon->mTargetVelocity.z);
    distanceLimit = MUL_FIXED12_NO_ROUND(TO_FIXED12(10), balloon->mScaleFactor + balloon->mScaleSwing);
    absOffsetZ = ABS(offsetZ);
    absOffsetX = ABS(offsetX);
    offsetDistance = absOffsetX / 2 + absOffsetZ / 2;
    if (offsetDistance <= distanceLimit) {
        balloon->mHorizontalPullEnabled = 1;
    } else if (balloon->mHorizontalPullEnabled != 0) {
        if (offsetDistance > distanceLimit) {
            pullRatio = FX_Div(offsetDistance - distanceLimit, offsetDistance);
            pullOffset.x = MUL_FIXED12_NO_ROUND(offsetX, pullRatio);
            pullOffset.y = 0;
            pullOffset.z = MUL_FIXED12_NO_ROUND(offsetZ, pullRatio);
            VecFx32_Subtract(&balloon->mMapObject.mPos, &pullOffset, &balloon->mMapObject.mPos);
        }
    }
    offsetX = (balloon->mMapObject.mPos.x + balloon->mMapObject.mPosStep.x) -
              (balloon->mTargetPos.x + balloon->mTargetVelocity.x);
    offsetY = (balloon->mMapObject.mPos.y + balloon->mMapObject.mPosStep.y) -
              (balloon->mTargetPos.y + balloon->mTargetVelocity.y);
    offsetZ = (balloon->mMapObject.mPos.z + balloon->mMapObject.mPosStep.z) -
              (balloon->mTargetPos.z + balloon->mTargetVelocity.z);
    distanceLimit = (balloon->mScaleFactor + balloon->mScaleSwing) << 4;
    absOffsetY = ABS(offsetY);
    absOffsetX = ABS(offsetX);
    absOffsetZ = ABS(offsetZ);
    offsetDistance = absOffsetY + (absOffsetX >> 2) + (absOffsetZ >> 2);
    if (offsetDistance > distanceLimit) {
        pullRatio = FX_Div(offsetDistance - distanceLimit, offsetDistance);
        pullOffset.x = MUL_FIXED12_NO_ROUND(offsetX, pullRatio);
        pullOffset.y = MUL_FIXED12_NO_ROUND(offsetY, pullRatio);
        pullOffset.z = MUL_FIXED12_NO_ROUND(offsetZ, pullRatio);
        if (balloon->mKartIndex >= 0) {
            VecFx32_Subtract(&balloon->mMapObject.mPosStep, &pullOffset, &balloon->mMapObject.mPosStep);
        } else {
            VecFx32_Add(&balloon->mTargetVelocity, &pullOffset, &balloon->mTargetVelocity);
        }
    }
    VecFx32_Add(&balloon->mMapObject.mPos, &balloon->mMapObject.mPosStep, &balloon->mMapObject.mPos);
    VecFx32_Add(&balloon->mTargetPos, &balloon->mTargetVelocity, &balloon->mTargetPos);
}

u32 GetBalloonFlagBits(Balloon *balloon) {
    return balloon->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN;
}

u32 GetBalloonDistanceSquared(Balloon *balloon) {
    return balloon->mMapObject.mDistanceSquaredAndFlags & ~0xc000001fu;
}

void UpdateBalloonAngle(Balloon *balloon) {
    Camera *currentCamera;
    Vec3 cameraOffset;
    u16 cameraAngle;
    s32 pairFirst;
    s32 pairSecond;
    s32 termZ;
    s32 termX;
    s32 offsetY;
    s32 sumTerms;

    currentCamera = GetGlobalHD4();
    cameraAngle = FX_Atan2(currentCamera->mForward.x, currentCamera->mForward.z) - 0x4000;
    VecFx32_Subtract(&balloon->mMapObject.mPos, &currentCamera->mPos, &cameraOffset);
    pairFirst = SIN_OF_ANGLE(cameraAngle);
    pairSecond = COS_OF_ANGLE(cameraAngle);
    termZ = MUL_FIXED12_NO_ROUND(cameraOffset.z, pairSecond);
    termX = MUL_FIXED12_NO_ROUND(cameraOffset.x, pairFirst);
    offsetY = cameraOffset.y;
    VecFx32_Subtract(&balloon->mTargetPos, &currentCamera->mPos, &cameraOffset);
    sumTerms = MUL_FIXED12_NO_ROUND(cameraOffset.x, pairFirst) + MUL_FIXED12_NO_ROUND(cameraOffset.z, pairSecond);
    balloon->mMapObject.mAngle = FX_Atan2(offsetY - cameraOffset.y, -(termX + termZ - sumTerms));
}

void UpdateBalloon(void *mapObjectList, Balloon *balloon) {
    Kart *kart;

    if (balloon->mKartIndex >= 0) {
        switch (balloon->mState) {
            case BALLOON_STATE_SWING:
                balloon->mScaleSwing = balloon->mScaleSwing + balloon->mScaleSwingPerFrame;
                if (balloon->mScaleSwing >= 0) {
                    if (balloon->mScaleSwingPerFrame < 0) {
                        balloon->mScaleSwingPerFrame = -50;
                    } else {
                        balloon->mScaleSwingPerFrame = balloon->mScaleSwingPerFrame - 10;
                    }
                } else {
                    if (balloon->mScaleSwingPerFrame >= 0) {
                        balloon->mScaleSwingPerFrame = BALLOON_SCALE_SWING_PER_FRAME;
                    } else {
                        balloon->mScaleSwingPerFrame = balloon->mScaleSwingPerFrame + 10;
                    }
                }
                if (balloon->mKartIndex == g_GlobalCO->mEntryIndex) {
                    if (IsAwardOrStaffRoll() == 1) {
                        kart = GetRacerMQEntry((u16) balloon->mKartIndex);
                        StartBalloonScaleSound(kart, balloon->mScaleFactor + balloon->mScaleSwing,
                                               balloon->mScaleFactorPerFrame);
                    }
                }
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    FollowBalloonTarget(balloon);
                    if (GetBalloonFlagBits(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mMapObject.mPos.x = balloon->mTargetPos.x;
                    balloon->mMapObject.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mMapObject.mPos.z = balloon->mTargetPos.z;
                }
                break;
            case BALLOON_STATE_SETTLE:
                balloon->mScaleSwing = 0;
                balloon->mScaleFactor = balloon->mScaleFactor + balloon->mScaleFactorPerFrame;
                if (balloon->mScaleFactor >= TO_FIXED12(1)) {
                    balloon->mScaleFactorPerFrame = balloon->mScaleFactorPerFrame - 200;
                }
                if (balloon->mScaleFactorPerFrame < 0) {
                    if (balloon->mScaleFactor <= TO_FIXED12(1)) {
                        balloon->mScaleFactor = TO_FIXED12(1);
                        balloon->mState = BALLOON_STATE_FULL;
                    }
                }
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    FollowBalloonTarget(balloon);
                    if (GetBalloonFlagBits(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mMapObject.mPos.x = balloon->mTargetPos.x;
                    balloon->mMapObject.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mMapObject.mPos.z = balloon->mTargetPos.z;
                }
                break;
            case BALLOON_STATE_FULL:
                balloon->mScaleSwing = 0;
                balloon->mScaleFactor = TO_FIXED12(1);
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    FollowBalloonTarget(balloon);
                    if (GetBalloonFlagBits(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mMapObject.mPos.x = balloon->mTargetPos.x;
                    balloon->mMapObject.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mMapObject.mPos.z = balloon->mTargetPos.z;
                }
                break;
            default:
                return;
        }
    } else {
        balloon->mScaleSwing = 0;
        balloon->mScaleFactor = TO_FIXED12(1);
        if (balloon->mNoKartTimer-- <= 0) {
            StartEffectWithCallback(0x5b, &balloon->mMapObject.mPos, balloon, SetBalloonEffectColor);
            StartEffectWithCallback(0x5c, &balloon->mMapObject.mPos, balloon, SetBalloonEffectColor);
            StartEffectWithCallback(0x5d, &balloon->mMapObject.mPos, balloon, SetBalloonEffectColor);
            QueueBalloonSound(&balloon->mMapObject.mPos, GetHorizontalCameraDistanceSquared(&balloon->mMapObject.mPos));
            ParkMapObject(&balloon->mMapObject);
        } else {
            balloon->mSwingAngle = balloon->mSwingAngle + balloon->mSwingAnglePerFrame;
            if (balloon->mSwingAngle >= 0) {
                if (balloon->mSwingAnglePerFrame < 0) {
                    balloon->mSwingAnglePerFrame = -0x640;
                } else {
                    balloon->mSwingAnglePerFrame = balloon->mSwingAnglePerFrame - 200;
                }
            } else {
                if (balloon->mSwingAnglePerFrame >= 0) {
                    balloon->mSwingAnglePerFrame = BALLOON_SWING_ANGLE_PER_FRAME;
                } else {
                    balloon->mSwingAnglePerFrame = balloon->mSwingAnglePerFrame + 200;
                }
            }
        }
        balloon->mMapObject.mAngle = balloon->mSwingAngle + 0x4000;
        balloon->mMapObject.mPosStep.y = balloon->mMapObject.mPosStep.y + 0x59a;
        balloon->mTargetVelocity.y = balloon->mTargetVelocity.y - 0x2000;
        balloon->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(balloon->mMapObject.mPosStep.x, 0xc00);
        balloon->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(balloon->mMapObject.mPosStep.y, 0xc00);
        balloon->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(balloon->mMapObject.mPosStep.z, 0xc00);
        VecFx32_Add(&balloon->mMapObject.mPos, &balloon->mMapObject.mPosStep, &balloon->mMapObject.mPos);
        VecFx32_Add(&balloon->mTargetPos, &balloon->mTargetVelocity, &balloon->mTargetPos);
    }
}

MapObjectList *CreateBalloonDrawList(void) {
    return CreateAllocateMapObject_from_thumb(CreateBalloon, DrawBalloon, SetupDrawBalloon);
}

MapObjectList *CreateBalloonUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateBalloon, NULL);
}

void ResetBalloons(void) {
    s32 balloonIndex;
    MapObjectList *mapObjectList;
    Balloon *balloon;

    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BALLOON);
    if (mapObjectList == NULL) {
        return;
    }
    for (balloonIndex = 0;
         balloonIndex < mapObjectList->mMapObjectCount && (balloon = mapObjectList->mMapObjects[balloonIndex]) != NULL;
         balloonIndex++) {
        if (balloon->mKartIndex >= 0) {
            balloon->mKartIndex = (u16) g_GlobalCO->mEntryIndex;
            balloon->mScaleFactor = TO_FIXED12(1);
            balloon->mScaleFactorPerFrame = 0;
            balloon->mScaleSwing = 0;
            balloon->mScaleSwingPerFrame = 0;
            balloon->mState = BALLOON_STATE_FULL;
        } else if ((balloon->mMapObject.mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
            ParkMapObject(&balloon->mMapObject);
        }
    }
}

Balloon *StartBalloon(u16 nsbtpFrameIndex, Vec3 *targetPos) {
    Balloon *balloon;

    balloon = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BALLOON));
    if (balloon == NULL) {
        return NULL;
    }
    balloon->mTargetPos = *targetPos;
    balloon->mMapObject.mPos = balloon->mTargetPos;
    balloon->mScaleFactor = 0;
    balloon->mScaleFactorPerFrame = 0;
    balloon->mScaleSwing = 0;
    balloon->mScaleSwingPerFrame = 0;
    balloon->mHorizontalPullEnabled = 0;
    balloon->mNsbtpFrameIndex = nsbtpFrameIndex;
    balloon->mState = BALLOON_STATE_SWING;
    return balloon;
}

void UpdateBalloonInflating(Balloon *balloon, u16 kartIndex, s32 scaleStep) {
    balloon->mKartIndex = kartIndex;
    balloon->mScaleFactorPerFrame = scaleStep;
    balloon->mScaleFactor = balloon->mScaleFactor + balloon->mScaleFactorPerFrame;
    balloon->mScaleSwing = 0;
    balloon->mScaleSwingPerFrame = 0;
    balloon->mState = BALLOON_STATE_SWING;
    if (balloon->mScaleFactor >= TO_FIXED12(1)) {
        balloon->mScaleSwing = 0;
        balloon->mScaleFactorPerFrame = BALLOON_SCALE_FACTOR_PER_FRAME;
        balloon->mState = BALLOON_STATE_SETTLE;
    }
}

void UpdateBalloonShrinking(Balloon *balloon, u16 kartIndex, s32 scaleStep) {
    balloon->mKartIndex = kartIndex;
    balloon->mScaleFactorPerFrame = -scaleStep;
    balloon->mScaleFactor = balloon->mScaleFactor + balloon->mScaleFactorPerFrame;
    balloon->mState = BALLOON_STATE_SWING;
    if (balloon->mScaleFactor > 0) {
        return;
    }
    balloon->mScaleSwing = 0;
    balloon->mScaleFactor = 0;
    balloon->mKartIndex = -1;
    balloon->mDrawCount = 1;
    balloon->mDrawList = NULL;
    ParkMapObject(&balloon->mMapObject);
}
