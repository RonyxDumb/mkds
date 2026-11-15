#include "Main/MapObjects/flipper.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Menu/data_0215d000.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_02166000.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_020109c4.h"
#include "code_020184e4.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/pakkun.h"
#include "Main/MapObjects/pakkun_spit.h"

const Vec3 gFlipperFourthBoxHalfSizesPositive[2] = {{0, 0x3c000, 0x32000}, {0xc8000, 0x3c000, 0x32000}};
const Vec3 gFlipperSecondBoxHalfSizesPositive[2] = {{0, 0x3c000, 0}, {0xc8000, 0x3c000, 0}};
const Vec3 gFlipperFirstBoxHalfSizesNegative[2] = {{0xc8000, 0, 0x32000}, {-40960, 0, 0x32000}};
const Vec3 gFlipperFourthBoxHalfSizesNegative[2] = {{0xc8000, 0, 0}, {0, 0, 0}};
const Vec3 gFlipperFirstBoxHalfSizesPositive[2] = {{-40960, 0x3c000, -133120}, {0xc8000, 0x3c000, -133120}};
const Vec3 gFlipperThirdBoxHalfSizesPositive[2] = {{-40960, 0x3c000, 0x32000}, {0xc8000, 0x3c000, 0x32000}};
MapObjectKindDescriptor gFlipperKindDescriptor = {0,
                                                  {0, 0},
                                                  0xef4,
                                                  InitFlipper,
                                                  CreateFlipperKindData,
                                                  CreateFlipperDrawList,
                                                  0,
                                                  0,
                                                  CreateFlipperUpdateList};
const Vec3 gFlipperThirdBoxHalfSizesNegative[2] = {{0xc8000, 0, 0x20800}, {-40960, 0, 0x20800}};
const u16 gCoverPooHoleInitMapObjectFlag = 0x200;
const Vec3 gFlipperSecondBoxHalfSizesNegative[2] = {{0xc8000, 0, 0x32000}, {0, 0, 0x32000}};
struct MapObjectModel *gFlipper;

void InitFlipper(Flipper *flipper) {
    flipper->mMapObject.mFlags = flipper->mMapObject.mFlags | gFlipperInitMapObjectFlag;
    RefreshMapObjectMatrixFromHitNormal(&flipper->mMapObject);
}

u32 CollideKartWithFlipper(Flipper *flipper, Kart *kart, void *firstResponse, u8 *response) {
    u32 responseValue;
    BOOL pushing;
    s32 pushSpeed;
    Vec3 offset;
    s32 pushScale;
    Vec3 *pushDirection;

    responseValue = *response;
    pushing = (flipper->mState == FLIPPER_STATE_SWING_OUT || flipper->mState == FLIPPER_STATE_ALT_SWING_OUT) &&
              flipper->mHitSide > 0;
    if (pushing) {
        pushScale = -0x19a;
    } else if ((flipper->mState == FLIPPER_STATE_SWING_BACK || flipper->mState == FLIPPER_STATE_ALT_SWING_BACK) &&
               flipper->mHitSide < 0) {
        pushScale = 0x19a;
    } else {
        pushScale = 0;
    }
    if (pushScale != 0) {
        if (flipper->mKartCooldownFrames[kart->mIndex] != 0) {
            flipper->mMapObject.mPosStep.x = 0;
            flipper->mMapObject.mPosStep.y = 0;
            flipper->mMapObject.mPosStep.z = 0;
        } else {
            VEC_Subtract(&kart->mPos, &flipper->mMapObject.mPos, &offset);
            pushSpeed = VEC_Mag(&offset);
            pushDirection = &flipper->mSwingMatrices[flipper->mSwingStep].mRows[2];
            pushSpeed = MUL_FIXED12_NO_ROUND(pushSpeed, pushScale);
            flipper->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(pushDirection->x, pushSpeed);
            flipper->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(pushDirection->y, pushSpeed);
            flipper->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(pushDirection->z, pushSpeed);
            flipper->mMapObject.mDistanceSquaredAndFlags =
                flipper->mMapObject.mDistanceSquaredAndFlags | gFlipperSkipSoundFlag;
            StartSoundFullVolumeWrapper(kart, 0x1d1);
        }
        if (flipper->mIsAnimating != 0) {
            return 0xe;
        }
        return 0xc;
    }
    flipper->mMapObject.mPosStep.x = 0;
    flipper->mMapObject.mPosStep.y = 0;
    flipper->mMapObject.mPosStep.z = 0;
    return responseValue;
}

// Also sets mHitSide to 0, 1 or -1 by the box hit and the state; CollideKartWithFlipper reads it.
BOOL ComputeSphereHitOnFlipper(Flipper *flipper, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *pushOut) {
    s32 hitResult;

    flipper->mHitSide = 0;
    if (ComputeSphereHitOnRotatedBox(sphereCenter, &flipper->mMapObject.mPos,
                                     &flipper->mSwingMatrices[flipper->mSwingStep].mRows[0],
                                     &gFlipperFirstBoxHalfSizesPositive[flipper->mMirror],
                                     &gFlipperFirstBoxHalfSizesNegative[flipper->mMirror], sphereRadius, NULL) != 0) {
        hitResult = ComputeSphereHitOnRotatedBox(
            sphereCenter, &flipper->mMapObject.mPos, &flipper->mSwingMatrices[flipper->mSwingStep].mRows[0],
            &gFlipperSecondBoxHalfSizesPositive[flipper->mMirror],
            &gFlipperSecondBoxHalfSizesNegative[flipper->mMirror], sphereRadius, pushOut);
        if (hitResult == 4 || flipper->mState == FLIPPER_STATE_SWING_OUT) {
            flipper->mHitSide = 1;
        } else if (flipper->mState == FLIPPER_STATE_SWING_BACK) {
            flipper->mHitSide = -1;
        }
    } else {
        if (ComputeSphereHitOnRotatedBox(
                sphereCenter, &flipper->mMapObject.mPos, &flipper->mSwingMatrices[flipper->mSwingStep].mRows[0],
                &gFlipperThirdBoxHalfSizesPositive[flipper->mMirror],
                &gFlipperThirdBoxHalfSizesNegative[flipper->mMirror], sphereRadius, NULL) != 0) {
            hitResult = ComputeSphereHitOnRotatedBox(
                sphereCenter, &flipper->mMapObject.mPos, &flipper->mTiltedSwingMatrices[flipper->mSwingStep].mRows[0],
                &gFlipperFourthBoxHalfSizesPositive[flipper->mMirror],
                &gFlipperFourthBoxHalfSizesNegative[flipper->mMirror], sphereRadius, pushOut);
            if (hitResult == 4 || flipper->mState == FLIPPER_STATE_SWING_BACK) {
                flipper->mHitSide = -1;
            } else if (flipper->mState == FLIPPER_STATE_SWING_OUT) {
                flipper->mHitSide = 1;
            }
        } else {
            hitResult = ComputeSphereHitOnRotatedCylinder(sphereCenter, &flipper->mMapObject.mPos,
                                                          &flipper->mSwingMatrices[flipper->mSwingStep].mRows[0],
                                                          0x32000, 0x3c000, 0, sphereRadius, pushOut);
        }
    }
    return hitResult != 0;
}

void CreateFlipper(void *mapObjectList) {
    gFlipper = CreateMapObjectModelAnimated(mapObjectList, "flipper.nsbmd");
    CreateMapObjectModelNsbtpAnimation(gFlipper, "flipper.nsbtp");
    CreateMapObjectModelNsbtaAnimation(gFlipper, "flipper.nsbta");
}

void DrawFlipper(void *mapObjectList, Flipper *flipper) {
    s32 gxParam;
    MtxFx43 *matrix;
    ModelAnimation *animation;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    matrix = &flipper->mSwingMatrices[flipper->mSwingStep];
    matrix->mRows[3].x = flipper->mMapObject.mPos.x >> 4;
    matrix->mRows[3].y = flipper->mMapObject.mPos.y >> 4;
    matrix->mRows[3].z = flipper->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &flipper->mMapObject.mScale, 3);
    SetMapObjectModelMirror(gFlipper, flipper->mMirror, 0);
    animation = gFlipper->mAnimations[1];
    animation->mHead.mFrameIndex = TO_FIXED12(flipper->mNsbtpFrameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
    animation = gFlipper->mAnimations[3];
    animation->mHead.mFrameIndex = TO_FIXED12(flipper->mNsbtaFrameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
    DrawMapObjectModel(mapObjectList, gFlipper, flipper);
}

void InitFlipperObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    s32 segmentIndex;
    s32 offsetDistance;
    s32 angleStep;
    s32 offsetAngle;
    u32 angle;
    Flipper *flipper;
    MtxFx43 *segmentMatrix;
    MtxFx33 tiltMatrix;
    MtxFx33 segmentRotation;

    if (mapObjectList == NULL) {
        return;
    }
    offsetDistance = gFlipperFirstBoxHalfSizesNegative[0].x;
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (flipper = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        switch (flipper->mMapObject.mCourseMapRow->mSettings[0]) {
            case 0:
                flipper->mMirror = 0;
                flipper->mMapObject.mFlags &= ~0x400;
                flipper->mMapObject.mAngle = ANGLE_EIGHTH_TURN;
                flipper->mWaitTimer = FLIPPER_WAIT_FRAMES;
                MTX_RotY33_(&tiltMatrix, SIN_OF_ANGLE(0xefa0), COS_OF_ANGLE(0xefa0));
                break;
            case 1:
                flipper->mMirror = 1;
                flipper->mMapObject.mFlags |= gFlipperMirrorFlag;
                flipper->mMapObject.mAngle = ANGLE_EIGHTH_TURN;
                flipper->mWaitTimer = FLIPPER_WAIT_FRAMES;
                MTX_RotY33_(&tiltMatrix, SIN_OF_ANGLE(0x1050), COS_OF_ANGLE(0x1050));
                break;
        }
        flipper->mIsAnimating = 0;
        if (flipper->mMirror == 0) {
            angle = flipper->mMapObject.mAngle;
        } else {
            angle = -flipper->mMapObject.mAngle;
        }
        for (segmentIndex = 0; segmentIndex < 30; segmentIndex++) {
            if (flipper->mMirror == 0) {
                angleStep = 0x16c;
            } else {
                angleStep = -0x16c;
            }
            angle = angle - angleStep;
            MTX_RotY33_(&segmentRotation, SIN_OF_ANGLE((u16) angle), COS_OF_ANGLE((u16) angle));
            segmentMatrix = &flipper->mSwingMatrices[segmentIndex];
            MTX_Concat33(&segmentRotation, &flipper->mMapObject.mMatrix.mAxes, &segmentMatrix->mAxes);
            MTX_Concat33(&tiltMatrix, &segmentMatrix->mAxes, &flipper->mTiltedSwingMatrices[segmentIndex].mAxes);
            flipper->mEmitterStarts[segmentIndex].x = flipper->mMapObject.mPos.x >> 4;
            flipper->mEmitterStarts[segmentIndex].y = flipper->mMapObject.mPos.y >> 4;
            flipper->mEmitterStarts[segmentIndex].z = flipper->mMapObject.mPos.z >> 4;
            if (flipper->mMirror == 0) {
                offsetAngle = (u16) (-angle + FX_Atan2Idx(-2, -10));
                flipper->mEmitterEnds[segmentIndex].x =
                    (flipper->mMapObject.mPos.x + MUL_FIXED12_NO_ROUND(offsetDistance, COS_OF_ANGLE(offsetAngle))) >> 4;
                flipper->mEmitterEnds[segmentIndex].y = flipper->mMapObject.mPos.y >> 4;
                flipper->mEmitterEnds[segmentIndex].z =
                    (flipper->mMapObject.mPos.z + MUL_FIXED12_NO_ROUND(offsetDistance, SIN_OF_ANGLE(offsetAngle))) >> 4;
            } else {
                offsetAngle = (u16) (-angle - FX_Atan2Idx(-2, -10));
                flipper->mEmitterEnds[segmentIndex].x =
                    (flipper->mMapObject.mPos.x - MUL_FIXED12_NO_ROUND(offsetDistance, COS_OF_ANGLE(offsetAngle))) >> 4;
                flipper->mEmitterEnds[segmentIndex].y = flipper->mMapObject.mPos.y >> 4;
                flipper->mEmitterEnds[segmentIndex].z =
                    (flipper->mMapObject.mPos.z - MUL_FIXED12_NO_ROUND(offsetDistance, SIN_OF_ANGLE(offsetAngle))) >> 4;
            }
        }
    }
}

void UpdateFlipper(void *mapObjectList, Flipper *flipper) {
    s32 kartIndex;
    s32 kartCount;
    RandomState64 *mapObjectRandom;
    u32 randomValue;
    s32 frameIndex;

    flipper->mAltWaitFrames = flipper->mAltWaitFrames - (flipper->mAltWaitFrames > 0);
    switch (flipper->mState) {
        case FLIPPER_STATE_START:
            flipper->mEmitter = StartEffect(0x5f, &flipper->mMapObject.mPos);
            flipper->mState = FLIPPER_STATE_WAIT;
            break;
        case FLIPPER_STATE_WAIT:
            if (flipper->mAltWaitFrames != 0) {
                flipper->mState = FLIPPER_STATE_ALT_WAIT;
            } else {
                flipper->mWaitTimer = flipper->mWaitTimer - 1;
                if (flipper->mWaitTimer <= 0) {
                    flipper->mSwingStep = 0;
                    flipper->mState = FLIPPER_STATE_SWING_OUT;
                }
            }
            flipper->mIsAnimating = 0;
            break;
        case FLIPPER_STATE_SWING_OUT:
            flipper->mMapObject.mAngle -= 0x16c;
            flipper->mSwingStep = flipper->mSwingStep + 1;
            if (flipper->mSwingStep >= FLIPPER_SWING_OUT_STEPS) {
                flipper->mSwingStep = FLIPPER_SWING_OUT_STEPS;
                flipper->mState = FLIPPER_STATE_SWING_BACK;
            }
            flipper->mIsAnimating = 1;
            break;
        case FLIPPER_STATE_SWING_BACK:
            flipper->mMapObject.mAngle += 0x16c;
            if (flipper->mSwingStep >= FLIPPER_SWING_BACK_STEP_LIMIT) {
                flipper->mIsAnimating = 1;
            } else {
                flipper->mIsAnimating = 0;
            }
            flipper->mSwingStep = flipper->mSwingStep - 1;
            if (flipper->mSwingStep <= 0) {
                flipper->mSwingStep = 0;
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                randomValue = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 12) >> 32;
                flipper->mWaitTimer = (u16) ((u16) randomValue * 0x14);
                flipper->mState = FLIPPER_STATE_WAIT;
            }
            break;
        case FLIPPER_STATE_ALT_WAIT:
            if (flipper->mAltWaitFrames <= 0) {
                flipper->mSwingStep = 0;
                flipper->mState = FLIPPER_STATE_ALT_SWING_OUT;
            }
            flipper->mIsAnimating = 0;
            break;
        case FLIPPER_STATE_ALT_SWING_OUT:
            flipper->mMapObject.mAngle -= 0x2d8;
            flipper->mSwingStep = flipper->mSwingStep + 2;
            if (flipper->mSwingStep >= FLIPPER_ALT_SWING_OUT_STEPS) {
                flipper->mSwingStep = FLIPPER_ALT_SWING_OUT_STEPS;
                flipper->mState = FLIPPER_STATE_ALT_SWING_BACK;
            }
            flipper->mIsAnimating = 1;
            break;
        case FLIPPER_STATE_ALT_SWING_BACK:
            flipper->mMapObject.mAngle += 0x2d8;
            if (flipper->mSwingStep >= FLIPPER_SWING_BACK_STEP_LIMIT) {
                flipper->mIsAnimating = 1;
            } else {
                flipper->mIsAnimating = 0;
            }
            flipper->mSwingStep = flipper->mSwingStep - 2;
            if (flipper->mSwingStep <= 0) {
                flipper->mSwingStep = 0;
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                randomValue = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 12) >> 32;
                flipper->mWaitTimer = (u16) ((u16) randomValue * 0x14);
                flipper->mState = FLIPPER_STATE_WAIT;
            }
            break;
    }
    if (flipper->mIsAnimating != 0 && (flipper->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN) == 0) {
        frameIndex = flipper->mNsbtpFrameIndex + 1;
        if (frameIndex >= GetMapObjectModelNsbtpFrameCount(gFlipper)) {
            frameIndex = 1;
        }
        flipper->mNsbtpFrameIndex = frameIndex;
        frameIndex = flipper->mNsbtaFrameIndex + 1;
        if (frameIndex >= GetMapObjectModelNsbtaFrameCount(gFlipper)) {
            frameIndex = 1;
        }
        flipper->mNsbtaFrameIndex = frameIndex;
        flipper->mEmitter->mFlags.mEmissionStopped = 0;
        SPLUtil_SetCylinderEmitterDir(flipper->mEmitter, &flipper->mEmitterStarts[flipper->mSwingStep],
                                      &flipper->mEmitterEnds[flipper->mSwingStep]);
    } else {
        flipper->mNsbtpFrameIndex = 0;
        flipper->mNsbtaFrameIndex = 0;
        flipper->mEmitter->mFlags.mEmissionStopped = 1;
    }
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        if (flipper->mKartCooldownFrames[kartIndex] > 0) {
            flipper->mKartCooldownFrames[kartIndex] = flipper->mKartCooldownFrames[kartIndex] - 1;
        }
    }
}

MapObjectKindData *CreateFlipperKindData(void) {
    return CreateMapObjectKindDataWithSound(CollideKartWithFlipper, NULL, ComputeSphereHitOnFlipper, 0, 1, 0x1d0);
}

MapObjectList *CreateFlipperDrawList(void) {
    return CreateMapObjectDrawList1(CreateFlipper, DrawFlipper, NULL);
}

MapObjectList *CreateFlipperUpdateList(void) {
    return CreateMapObjectUpdateList(InitFlipperObjects, UpdateFlipper, NULL);
}
