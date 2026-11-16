#include "Main/MapObjects/choropu.h"
#include "Main/System/heap.h"
#include "Main/Course/course_color_blend.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/jg.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_objects_and_race_progress.h" // ItemObject
#include "Main/Sound/kart_surface_sound.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "ITCM/kart_motion.h"
#include "Main/Item/item_pool.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "model_material_set.h"
#include "fixed_vector_math.h"
#include "fixed_arctangent.h"

#include "Main/System/state_machine_init.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/Item/held_item.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Race/entry_race_ended.h"
#include "Main/Graphics/light_color.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "01/MapObjects/mission_run_group_entry_queries.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "matrix_4x3_basic.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/MapObjects/collision_hit_link_create.h"
#include "Main/System/init_after_startup.h"
#include "Main/MapObjects/choropu_kind_descriptor.h"

const MapObjectKindData gBusAKindData = {(s32 (*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithVehicle,
                                         (s32 (*)(MapObject *, void *, void *, void *)) CollideItemObjectWithVehicle,
                                         5,
                                         0x4c000,
                                         0,
                                         0,
                                         (s32 (*)(MapObject *, Vec3 *, s32, Vec3 *)) ComputeSphereHitOnVehicle,
                                         1,
                                         1,
                                         0x17f,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0};
const MapObjectKindData gTruckAKindData = {(s32 (*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithVehicle,
                                         (s32 (*)(MapObject *, void *, void *, void *)) CollideItemObjectWithVehicle,
                                         5,
                                         0x32000,
                                         0,
                                         0,
                                         (s32 (*)(MapObject *, Vec3 *, s32, Vec3 *)) ComputeSphereHitOnVehicle,
                                         1,
                                         1,
                                         0x180,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0};
const MapObjectKindData gCarAKindData = {(s32 (*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithVehicle,
                                         (s32 (*)(MapObject *, void *, void *, void *)) CollideItemObjectWithVehicle,
                                         5,
                                         0x19000,
                                         0,
                                         0,
                                         (s32 (*)(MapObject *, Vec3 *, s32, Vec3 *)) ComputeSphereHitOnVehicle,
                                         1,
                                         1,
                                         0x181,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0};
Quaternion gIdentityQuaternion = {{0, 0, 0, 0x1000}};
const MapObjectList gVehicleUpdateListData = {NULL, 0, {0, 0}, InitVehicleUpdateList, NULL, UpdateVehicle, NULL, 0,
                                              NULL, 0, NULL};
const VehicleDrawList gVehicleDrawListData = {{NULL,
                                        0,
                                        {0, 0},
                                        (void (*)(MapObjectList *)) InitVehicleDrawList,
                                        (void (*)(MapObjectList *)) SetVehicleLinkDirection,
                                        DrawVehicle,
                                        NULL,
                                        1,
                                        NULL,
                                        0,
                                        NULL},
                                       {0, 0, 0, 0},
                                       {0, 0, 0},
                                       0,
                                       0};
struct Nsbmd *gCarA;
ModelAnimation *gCarANsbtp;
struct Nsbmd *gTruckA;
struct Nsbmd *gBusA;
struct Nsbmd *gCarTire;
struct ShadowModel *gBusAShadow;
struct ShadowModel *gCarAShadow;
struct ShadowModel *gTruckAShadow;
struct VehicleDrawList *gVehicleDrawList;
struct MapObjectList *gVehicleUpdateList;
ModelAnimation *gTruckANsbtp;


MapObjectKindData *CreateCarAKindData(void) {
    MapObjectKindData *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));

    *kindData = gCarAKindData;
    return kindData;
}

MapObjectKindData *CreateTruckAKindData(void) {
    MapObjectKindData *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));

    *kindData = gTruckAKindData;
    return kindData;
}

MapObjectKindData *CreateBusAKindData(void) {
    MapObjectKindData *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));

    *kindData = gBusAKindData;
    return kindData;
}

MapObjectList *CreateVehicleDrawList(void) {
    VehicleDrawList *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(VehicleDrawList));

    gVehicleDrawList = drawList;
    *drawList = gVehicleDrawListData;
    SetDrawListSlot(&gVehicleDrawList);
    return &gVehicleDrawList->mMapObjectList;
}

MapObjectList *CreateVehicleUpdateList(void) {
    MapObjectList *updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));

    gVehicleUpdateList = updateList;
    *updateList = gVehicleUpdateListData;
    SetUpdateListSlot(&gVehicleUpdateList);
    return gVehicleUpdateList;
}

void SetVehicleLinkDirection(VehicleDrawList *drawList) {
    u16 entryIndex;

    entryIndex = gRaceSetup->mEntryIndex;
    if (drawList->mLinkCullEnabled == FALSE) {
        return;
    }
    if (entryIndex < 8) {
        GetItemPointLinkDirection(gKartItems[entryIndex].mItemLink.mLink, &drawList->mEntryKartLinkDirection);
        drawList->mLinkCullActive =
            Vec3DotUnrounded(&drawList->mEntryKartLinkDirection, GetViewTransposeMatrixAxis2()) < 0;
    } else {
        drawList->mLinkCullActive = FALSE;
    }
}

void DrawVehicle(VehicleDrawList *drawList, Vehicle *vehicle, u32 unusedArg, u32 alpha) {
    u32 skipShadowAndTires;
    s32 dotAxis2;
    s16 directionFlag;
    s16 dotLimit;
    Vec3 *shadowPosition;
    const s16 *anglePairs;
    ModelAnimation *animation;
    MtxFx43 tireMatrix;
    s32 one;
    u32 angleIndex;
    s32 tireSin;
    s32 tireCos;

    if (drawList->mLinkCullActive != FALSE) {
        dotAxis2 = Vec3DotUnrounded(&vehicle->mMapObject.mMatrix.mRows[2], &drawList->mEntryKartLinkDirection);
        directionFlag = vehicle->mMapObject.mCourseMapRow->mSettings[3];
        dotLimit = vehicle->mFollower.mFromEntry->mCullDotLimit;
        if (directionFlag == 0) {
            dotAxis2 = -dotAxis2;
        }
        if (dotAxis2 > dotLimit) {
            return;
        }
    }
    skipShadowAndTires =
        (s32) (vehicle->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK) > 0x77A10 &&
        GetEntryRaceEnded() == 0;
    if (!skipShadowAndTires) {
        if (vehicle->mShadowModel != 0) {
            shadowPosition = vehicle->mHitReactionTimer > VEHICLE_HIT_TIMER_AIRBORNE ? &vehicle->mFollowerPosition
                                                                                     : &vehicle->mMapObject.mPos;
            vehicle->mMapObject.mMatrix.mRows[3].x = shadowPosition->x >> 4;
            vehicle->mMapObject.mMatrix.mRows[3].y = shadowPosition->y >> 4;
            vehicle->mMapObject.mMatrix.mRows[3].z = shadowPosition->z >> 4;
            DrawShadowWithMaxAlpha(vehicle->mShadowModel, &vehicle->mMapObject.mMatrix,
                                   &vehicle->mMapObject.mScale, alpha);
        }
    }
    vehicle->mMapObject.mMatrix.mRows[3].x = vehicle->mMapObject.mPos.x >> 4;
    vehicle->mMapObject.mMatrix.mRows[3].y = vehicle->mMapObject.mPos.y >> 4;
    vehicle->mMapObject.mMatrix.mRows[3].z = vehicle->mMapObject.mPos.z >> 4;
    animation = vehicle->mModelAnimation;
    if (animation != NULL) {
        animation->mHead.mFrameIndex = TO_FIXED12(vehicle->mAnimationFrame);
        animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
    }
    SendLight01Color(&vehicle->mCourseColorBlend.mColor);
    DrawNsbmdWithMatrixAndMaxAlpha(vehicle->mModel, &vehicle->mMapObject.mMatrix, &vehicle->mMapObject.mScale,
                                   alpha);
    if (skipShadowAndTires) {
        return;
    }
    angleIndex = vehicle->mTireAngle >> 4;
    anglePairs = FX_SinCosTable_;
    tireSin = MUL_FIXED12_ROUNDED(vehicle->mTireRadius, anglePairs[angleIndex * 2]);
    tireCos = MUL_FIXED12_ROUNDED(vehicle->mTireRadius, anglePairs[angleIndex * 2 + 1]);
    MTX_RotX43_(&tireMatrix, tireSin, tireCos);
    tireMatrix.mRows[0].x = vehicle->mTireOffset[0];
    tireMatrix.mRows[3].y = vehicle->mTireOffset[1];
    tireMatrix.mRows[3].z = vehicle->mTireOffset[2];
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x19, &tireMatrix, 0xc);
    DrawNsbmd(gCarTire);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    tireMatrix.mRows[3].z = -tireMatrix.mRows[3].z;
    NNS_G3dGeBufferOP_N(0x19, &tireMatrix, 0xc);
    DrawNsbmd(gCarTire);
}

static inline s64 VehicleXzLengthSquared(const Vec3 *vector) {
    return HORIZONTAL_LENGTH_SQUARED(*vector);
}

static inline s16 GetVehicleHitReactionTimer(Vehicle *vehicle) {
    return vehicle->mHitReactionTimer;
}

void UpdateVehicle(u32 unused, Vehicle *vehicle) {
    enum { HIT_REACTION_NO } isInHitReaction;
    Quaternion *baseRotation;
    u32 hitFlags;
    Quaternion targetRotation;
    Vec3 previousPosition;
    Vec3 probeOffset;
    Vec3 probeVec;
    Vec3 testPosition;

    if (vehicle->mHitReactionTimer > VEHICLE_HIT_TIMER_AIRBORNE) {
        isInHitReaction = 1;
        isInHitReaction = (s32) isInHitReaction;
    } else {
        isInHitReaction = 0;
    }
    previousPosition = vehicle->mMapObject.mPos;
    AdvanceGroupFollower(&vehicle->mFollower);
    if (!isInHitReaction) {
        GetGroupFollowerCurveXzLinearY(&vehicle->mFollower, &vehicle->mMapObject.mPos);
        VEC_Subtract(&vehicle->mMapObject.mPos, &previousPosition, &vehicle->mMapObject.mPosStep);
    } else {
        GetGroupFollowerCurveXzLinearY(&vehicle->mFollower, &vehicle->mFollowerPosition);
        vehicle->mMapObject.mPos.x = vehicle->mFollowerPosition.x;
        vehicle->mMapObject.mPosStep.y -= VEHICLE_GRAVITY_PER_FRAME;
        vehicle->mMapObject.mPos.y = vehicle->mMapObject.mPos.y + vehicle->mMapObject.mPosStep.y;
        vehicle->mMapObject.mPos.z = vehicle->mFollowerPosition.z;
        vehicle->mMapObject.mPosStep.x = vehicle->mMapObject.mPos.x - previousPosition.x;
        vehicle->mMapObject.mPosStep.z = vehicle->mMapObject.mPos.z - previousPosition.z;
    }
    if (isInHitReaction || (vehicle->mUpdateIndex & 7) == GetRaceUpdateFramesMod8()) {
        testPosition.x = vehicle->mMapObject.mPos.x;
        testPosition.y = vehicle->mMapObject.mPos.y + (isInHitReaction ? 0xf000 : 0);
        testPosition.z = vehicle->mMapObject.mPos.z;
        probeVec = testPosition;
        if (CollideSphereWithCourse(&probeVec, NULL, 0, 0xf000, 8, -2, &probeOffset, &probeVec, NULL, &hitFlags, NULL,
                                    NULL, NULL, NULL) != 0) {
            if (hitFlags & 0x1e34ef) {
                QuaternionFromYAxisToVec3(&probeVec, &vehicle->mGroundRotation);
                AdvanceCourseColorBlend(&vehicle->mCourseColorBlend, (hitFlags & 0x3c000000) >> 26, 0x5000);
                if (vehicle->mHitReactionTimer != 0 && vehicle->mMapObject.mPosStep.y < 0) {
                    if (vehicle->mMapObject.mFlags & 1) {
                        vehicle->mMapObject.mFlags &= ~1;
                        vehicle->mMapObject.mPosStep.y = -MUL_FIXED12_NO_ROUND(
                            vehicle->mMapObject.mPosStep.y, 0x733 + ((vehicle->mExtentPositive.y - 0x14000) >> 9));
                        vehicle->mHitRotation.mComponents[0] = -vehicle->mHitRotation.mComponents[0];
                        vehicle->mHitRotation.mComponents[1] = -vehicle->mHitRotation.mComponents[1];
                        vehicle->mHitRotation.mComponents[2] = -vehicle->mHitRotation.mComponents[2];
                        QuaternionBlendTowardNearerSign(&vehicle->mHitRotation, &vehicle->mGroundRotation,
                                                        &vehicle->mHitRotation, 0x8cd);
                        vehicle->mRotationBlendRate = VEHICLE_BLEND_RATE_BOUNCE;
                        StartMapObjectSound(&vehicle->mMapObject, vehicle->mBounceSoundId);
                    } else if (isInHitReaction && vehicle != NULL) {
                        vehicle->mHitReactionTimer = VEHICLE_HIT_TIMER_AIRBORNE;
                        vehicle->mMapObject.mPosStep.y = 0;
                        vehicle->mRotationBlendRate = VEHICLE_BLEND_RATE_LANDING;
                    }
                }
            }
            if ((hitFlags & 0x214300) && isInHitReaction) {
                vehicle->mMapObject.mPos.y = vehicle->mMapObject.mPos.y + probeOffset.y;
                vehicle->mMapObject.mPosStep.y = 0;
            }
        }
    }
    switch (isInHitReaction) {
        default:
            if (vehicle->mMapObject.mPosStep.y < 0) {
                vehicle->mRotationBlendRate = MUL_FIXED12_NO_ROUND(-vehicle->mMapObject.mPosStep.y, 0xc);
                baseRotation = &vehicle->mGroundRotation;
            } else {
                baseRotation = &vehicle->mHitRotation;
            }
            break;

        case 0:
            if (GetVehicleHitReactionTimer(vehicle) != 0) {
                vehicle->mHitReactionTimer--;
                if (vehicle->mHitReactionTimer == 0) {
                    vehicle->mRotationBlendRate = vehicle->mDefaultBlendRate;
                } else {
                    baseRotation = &vehicle->mGroundRotation;
                }
            }
            break;
    }

    if (VehicleXzLengthSquared(&vehicle->mMapObject.mPosStep) < 0x10) {
        targetRotation = vehicle->mGroundRotation;
    } else {
        vehicle->mMapObject.mAngle =
            (s16) (((s64) FX_Atan2(vehicle->mMapObject.mPosStep.x, vehicle->mMapObject.mPosStep.z) * 0x28BE60DB9391 +
                    0x80000000000) >>
                   44);
        if (vehicle->mHitReactionTimer == 0) {
            baseRotation = &vehicle->mGroundRotation;
        }
        QuaternionMultiplyAngleAroundYIgnoreY(baseRotation, vehicle->mMapObject.mAngle, &targetRotation);
    }
    QuaternionBlendTowardNearerSign(&vehicle->mRotation, &targetRotation, &vehicle->mRotation,
                                    vehicle->mRotationBlendRate);
    Matrix3x3FromQuaternion(&vehicle->mMapObject.mMatrix.mAxes, &vehicle->mRotation);
    vehicle->mTireAngle += VEHICLE_TIRE_ANGLE_STEP;
    if (vehicle->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_TESTED) {
        AdvanceSoundDistanceSquaredChange(vehicle->mSoundDistanceChange,
                                          vehicle->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK);
    }
    StartMapObjectSoundWhileRequested(&vehicle->mMapObject, vehicle->mRunSoundId);
    if (vehicle->mMapObject.mPos.y < 0) {
        ResetVehicleToStartEntry(vehicle);
    }
}

void StartVehicleHitReaction(Vehicle *vehicle, Vec3 *hitterPosition) {
    Vec3 direction;
    s32 dotAxis0;
    s32 dotAxis2;
    s32 upwardSpeed;

    direction = vehicle->mMapObject.mPos;
    VEC_Subtract(&direction, hitterPosition, &direction);
    dotAxis0 = Vec3DotUnrounded(&vehicle->mMapObject.mMatrix.mRows[0], &direction);
    dotAxis2 = Vec3DotUnrounded(&vehicle->mMapObject.mMatrix.mRows[2], &direction);
    direction.x = (dotAxis0 > 0 ? vehicle->mMapObject.mMatrix.mRows[0].x : -vehicle->mMapObject.mMatrix.mRows[0].x) * 2;
    direction.x += dotAxis2 > 0 ? vehicle->mMapObject.mMatrix.mRows[2].x : -vehicle->mMapObject.mMatrix.mRows[2].x;
    direction.z = (dotAxis0 > 0 ? vehicle->mMapObject.mMatrix.mRows[0].z : -vehicle->mMapObject.mMatrix.mRows[0].z) * 2;
    direction.z += dotAxis2 > 0 ? vehicle->mMapObject.mMatrix.mRows[2].z : -vehicle->mMapObject.mMatrix.mRows[2].z;
    direction.y = ((vehicle->mExtentPositive.y - 0x14000) >> 4) + 0x2000;
    if (LENGTH_SQUARED(direction) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
    }
    QuaternionFromYAxisToVec3(&direction, &vehicle->mHitRotation);
    vehicle->mRotationBlendRate = VEHICLE_BLEND_RATE_HIT;
    if (vehicle->mHitReactionTimer > VEHICLE_HIT_TIMER_AIRBORNE || vehicle->mMapObject.mPosStep.y <= 0) {
        upwardSpeed = 0;
    } else {
        upwardSpeed = vehicle->mMapObject.mPosStep.y;
    }
    vehicle->mMapObject.mPosStep.y = upwardSpeed + VEHICLE_HIT_UPWARD_SPEED;
    vehicle->mMapObject.mFlags |= gVehicleHitFlag;
    vehicle->mHitReactionTimer = VEHICLE_HIT_TIMER_START;
}

u8 CollideKartWithVehicle(Vehicle *vehicle, Kart *kart, u8 *firstResponse, u8 *response) {
    if (*firstResponse == 1) {
        StartVehicleHitReaction(vehicle, &kart->mPos);
        StartSoundIfKartStarOrKiller(&vehicle->mMapObject, kart);
    }
    return *response;
}

u8 CollideItemObjectWithVehicle(Vehicle *vehicle, ItemObject *itemObject, u8 *firstResponse, u8 *response) {
    if (*firstResponse == 1) {
        StartVehicleHitReaction(vehicle, &itemObject->mPos);
    }
    return *response;
}

void ComputeSphereHitOnVehicle(Vehicle *vehicle, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 halfSizesPositive;
    Vec3 halfSizesNegative;
    s32 halfSizeX;
    s32 halfSizeY;
    s32 halfSizeZ;

    halfSizeZ = vehicle->mExtentPositive.z;
    halfSizeY = vehicle->mExtentPositive.y;
    halfSizeX = vehicle->mExtentPositive.x;
    halfSizesPositive.x = halfSizeX;
    halfSizesPositive.y = halfSizeY;
    halfSizesPositive.z = halfSizeZ;
    halfSizeZ = vehicle->mExtentNegativeZ;
    halfSizeX = vehicle->mExtentPositive.x;
    halfSizesNegative.x = halfSizeX;
    halfSizesNegative.y = 0;
    halfSizesNegative.z = halfSizeZ;
    ComputeSphereHitOnRotatedBox(sphereCenter, &vehicle->mMapObject.mPos, &vehicle->mMapObject.mMatrix.mRows[0],
                                 &halfSizesPositive, &halfSizesNegative, sphereRadius, overlapOffset);
}

#pragma thumb on

void InitVehicleUpdateList(MapObjectList *updateList) {
    s32 index;
    s32 count;
    u32 seenGroupMask;
    void **vehicleCursor;
    u16 entryCount;
    u16 groupIndex;
    CourseMapGroupEntry *entry;
    u16 entryIndex;
    u16 zero;
    Vehicle *vehicle;
    s16 angleDegrees;
    s16 dotLimit;
    float scaledDegrees;

    count = updateList->mMapObjectCount;
    vehicleCursor = updateList->mMapObjects;
    seenGroupMask = 0;
    zero = 0;
    for (index = 0; index < count; index++) {
        vehicle = *vehicleCursor;
        groupIndex = vehicle->mMapObject.mCourseMapRow->mGroupIndex;
        vehicle->mUpdateIndex = index;
        if ((seenGroupMask & (1 << groupIndex)) == 0) {
            entryCount = gCourseMap->mEntryGroups[groupIndex].mEntryCount;
            BIT_SET(seenGroupMask, groupIndex);
            for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
                entry = GetCourseMapGroupEntry(groupIndex, entryIndex);
                angleDegrees = entry->mValue;
                if (angleDegrees != 0) {
                    if (angleDegrees > 0) {
                        scaledDegrees = 0.5f + TO_FIXED12(angleDegrees);
                    } else {
                        scaledDegrees = TO_FIXED12(angleDegrees) - 0.5f;
                    }
                    dotLimit = COS_OF_ANGLE(DEG_TO_ANGLE((s32) scaledDegrees));
                } else {
                    dotLimit = 0x2000;
                }
                entry->mCullDotLimit = dotLimit;
                entry->mValue = zero;
            }
        }
        vehicleCursor++;
    }
}

void InitVehicleDrawList(VehicleDrawList *drawList) {
    void *carFile;
    void *truckFile;
    u32 carMaterialIndex;
    NNSG3dResMdl *carModel;
    u32 truckMaterialIndex;
    NNSG3dResMdl *truckModel;
    u32 busMaterialIndex;
    NNSG3dResMdl *busModel;
    u32 tireMaterialIndex;
    NNSG3dResMdl *tireModel;
    s32 index;
    Vehicle *vehicle;
    struct Nsbmd **modelSlot;
    struct ShadowModel **shadowModelSlot;
    ModelAnimation **animationSlot;
    s32 count;

    carFile = FindCourseMapObjFile("car_a.nsbmd");
    truckFile = FindCourseMapObjFile("truck_a.nsbmd");
    drawList->mLinkCullEnabled =
        gRaceSetup->mMode != MODE_MISSION_RUN && GetEntryRaceEnded() == 0 && (u16) gRaceSetup->mEntryIndex < 8;
    drawList->mLinkCullActive = FALSE;
    CreateNsbmd(&gCarA, carFile, NULL);
    CreateNsbmd(&gTruckA, truckFile, NULL);
    CreateNsbmd(&gBusA, FindCourseMapObjFile("bus_a.nsbmd"), NULL);
    CreateNsbmd(&gCarTire, FindCourseMapObjFile("car_tire.nsbmd"), NULL);
    CreateShadowModel(&gCarAShadow, FindCourseMapObjFile("car_a_shadow.nsbmd"), 7);
    CreateShadowModel(&gTruckAShadow, FindCourseMapObjFile("truck_a_shadow.nsbmd"), 7);
    CreateShadowModel(&gBusAShadow, FindCourseMapObjFile("bus_a_shadow.nsbmd"), 7);
    CreateModelAnimation(2, gCarA, &gCarANsbtp, carFile, FindCourseMapObjFile("car_a.nsbtp"));
    CreateModelAnimation(2, gTruckA, &gTruckANsbtp, truckFile, FindCourseMapObjFile("truck_a.nsbtp"));
    SetNsbmdPolygonIdLightEmiAll(gCarA, 0x3f, 2, 0x294a);
    for (carMaterialIndex = 0, carModel = gCarA->mResMdl; carMaterialIndex < carModel->mInfo.mNumMat;
         carMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(carModel, carMaterialIndex, 7);
    }
    SetNsbmdPolygonIdLightEmiAll(gTruckA, 0x3f, 2, 0x294a);
    for (truckMaterialIndex = 0, truckModel = gTruckA->mResMdl; truckMaterialIndex < truckModel->mInfo.mNumMat;
         truckMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(truckModel, truckMaterialIndex, 7);
    }
    SetNsbmdPolygonIdLightEmiAll(gBusA, 0x3f, 2, 0x294a);
    for (busMaterialIndex = 0, busModel = gBusA->mResMdl; busMaterialIndex < busModel->mInfo.mNumMat;
         busMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(busModel, busMaterialIndex, 7);
    }
    SetNsbmdPolygonIdLightEmiAll(gCarTire, 0x3f, 2, 0x294a);
    for (tireMaterialIndex = 0, tireModel = gCarTire->mResMdl; tireMaterialIndex < tireModel->mInfo.mNumMat;
         tireMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(tireModel, tireMaterialIndex, 7);
    }
    SetNsbmdLightEnableFlagAll(gCarTire, 0);
    count = gVehicleDrawList->mMapObjectList.mMapObjectCount;
    for (index = 0; index < count; index++) {
        vehicle = gVehicleDrawList->mMapObjectList.mMapObjects[index];
        modelSlot = vehicle->mKindInfo->mModelSlot;
        vehicle->mModel = modelSlot != NULL ? *modelSlot : 0;
        shadowModelSlot = vehicle->mKindInfo->mShadowModelSlot;
        vehicle->mShadowModel = shadowModelSlot != NULL ? *shadowModelSlot : 0;
        animationSlot = vehicle->mKindInfo->mAnimationSlot;
        vehicle->mModelAnimation = animationSlot != NULL ? *animationSlot : 0;
    }
}

void InitVehicle(Vehicle *vehicle, struct CourseMapRow *courseRow, VehicleKindInfo *kindInfo) {
    vehicle->mKindInfo = kindInfo;
    InitGroupFollower(&vehicle->mFollower, courseRow, (s16) courseRow->mSettings[0] * 0x3000 / 100);
    vehicle->mStartEntryIndex = courseRow->mSettings[1];
    vehicle->mAnimationFrame = courseRow->mSettings[2];
    vehicle->mStartEntryY = GetCourseMapGroupEntry(courseRow->mGroupIndex, vehicle->mStartEntryIndex)->mPos.y;
    vehicle->mExtentPositive.x = MUL_FIXED12_NO_ROUND(kindInfo->mExtentX, vehicle->mMapObject.mScale.x);
    vehicle->mExtentPositive.y = MUL_FIXED12_NO_ROUND(kindInfo->mExtentY, vehicle->mMapObject.mScale.y);
    vehicle->mExtentPositive.z = MUL_FIXED12_NO_ROUND(kindInfo->mExtentZ, vehicle->mMapObject.mScale.z);
    vehicle->mExtentNegativeZ = MUL_FIXED12_NO_ROUND(kindInfo->mExtentNegativeZ, vehicle->mMapObject.mScale.z);
    vehicle->mRotationBlendRate = (u32) ((s16) courseRow->mSettings[0] * 0xfa) / 100;
    vehicle->mDefaultBlendRate = vehicle->mRotationBlendRate;
    vehicle->mTireOffset[0] = kindInfo->mTireOffsetX;
    vehicle->mTireOffset[1] = kindInfo->mTireOffsetY >> 4;
    vehicle->mTireOffset[2] = kindInfo->mTireOffsetZ >> 4;
    vehicle->mTireRadius = kindInfo->mTireRadius;
    ResetVehicleToStartEntry(vehicle);
    vehicle->mRunSoundId = kindInfo->mRunSoundId;
    vehicle->mSoundDistanceChange = CreateVehicleSoundSource(&vehicle->mMapObject);
    ResetSoundDistanceSquaredChange(vehicle->mSoundDistanceChange);
    vehicle->mMapObject.mSound->mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetVehicleSoundTrackParams;
    vehicle->mBounceSoundId = kindInfo->mBounceSoundId;
}

void ResetVehicleToStartEntry(Vehicle *vehicle) {
    SetupGroupFollowerAtEntry(&vehicle->mFollower, vehicle->mStartEntryIndex, 1);
    GetGroupFollowerCurvePosStepXz(&vehicle->mFollower, &vehicle->mMapObject.mPos, &vehicle->mMapObject.mPosStep);
    vehicle->mMapObject.mPos.y = vehicle->mStartEntryY;
    vehicle->mMapObject.mPosStep.y = 0;
    vehicle->mGroundRotation = gIdentityQuaternion;
    QuaternionMultiplyAngleAroundYIgnoreY(
        &vehicle->mGroundRotation,
        (u16) (((s64) FX_Atan2(vehicle->mMapObject.mPosStep.x, vehicle->mMapObject.mPosStep.z) * 0x28be60db9391 +
                0x80000000000) >>
               44),
        &vehicle->mRotation);
    Matrix3x3FromQuaternion(&vehicle->mMapObject.mMatrix.mAxes, &vehicle->mRotation);
    vehicle->mHitReactionTimer = 0;
    vehicle->mRotationBlendRate = vehicle->mDefaultBlendRate;
    vehicle->mTireAngle = 0;
    InitCourseColorBlend(&vehicle->mCourseColorBlend, 1);
}

#pragma thumb off

void DrawVisibleMapObjects(MapObjectList *list, void *viewMatrix,
                           void (*drawObject)(CollisionMapObject *, void *, u32)) {
    s32 index;
    s32 count = list->mMapObjectCount;

    for (index = 0; index < count; index++) {
        CollisionMapObject *mapObject = list->mMapObjects[index];

        if ((mapObject->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN) == 0 && mapObject->mMapObject.mAlpha != 0) {
            drawObject(mapObject, viewMatrix, mapObject->mMapObject.mAlpha);
        }
    }
}

void DrawMapObjectModelAtPos(CollisionMapObject *mapObject, void *viewMatrix, u32 alpha) {
    mapObject->mMapObject.mMatrix.mRows[3].x = mapObject->mMapObject.mPos.x >> 4;
    mapObject->mMapObject.mMatrix.mRows[3].y = mapObject->mMapObject.mPos.y >> 4;
    mapObject->mMapObject.mMatrix.mRows[3].z = mapObject->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(mapObject->mModel, &mapObject->mMapObject.mMatrix, &mapObject->mMapObject.mScale,
                                   alpha);
}

void SetMapObjectsModel(MapObjectList *list, void *model) {
    s32 index;
    s32 count = list->mMapObjectCount;

    for (index = 0; index < count; index++) {
        CollisionMapObject *mapObject = list->mMapObjects[index];

        mapObject->mModel = model;
    }
}

s32 ComputeSphereHitOnCollisionData(CollisionMapObject *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange) {
    switch (object->mCollisionData.mShape) {
        case COLLISION_SHAPE_BOX:
            return ComputeSphereHitOnCollisionBox(object, sphereCenter, sphereRadius, queryFlags, firstHitRecord,
                                                  secondHitRecord, lowestOffset, outFlags, pointMotion, angleChange);
        case COLLISION_SHAPE_CYLINDER:
            return ComputeSphereHitOnCollisionCylinder(object, sphereCenter, sphereRadius, queryFlags, firstHitRecord,
                                                       secondHitRecord, lowestOffset, outFlags, pointMotion,
                                                       angleChange);
    }
    return 0;
}

void AddCollisionHitOneAxis(s32 sphereRadius, s32 signedDepth, s32 depth, u32 regionFlags, u16 positiveSideBit,
                            u16 *outFlags, s32 axisFlag, CollisionMapObject *object, Vec3 *sphereCenter, Vec3 *normal,
                            CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset,
                            Vec3 *pointMotion, u16 *angleChange) {
    BOOL normalAboveThreshold;
    s32 signedNormalY;
    CollisionHitRecord *chosenHitRecord;
    u16 hitFlags;
    Vec3 offset;

    normalAboveThreshold = FALSE;
    if (axisFlag != 0) {
        if (regionFlags & positiveSideBit) {
            signedNormalY = normal->y;
        } else {
            signedNormalY = -normal->y;
        }
        if (signedNormalY > object->mCollisionData.mFloorThreshold) {
            normalAboveThreshold = TRUE;
        }
    }
    offset.x = normal->x << 10;
    offset.y = normal->y << 10;
    offset.z = normal->z << 10;
    offset.x = MUL_FIXED12_NO_ROUND(offset.x, signedDepth);
    offset.y = MUL_FIXED12_NO_ROUND(offset.y, signedDepth);
    offset.z = MUL_FIXED12_NO_ROUND(offset.z, signedDepth);
    if (normalAboveThreshold) {
        hitFlags = object->mCollisionData.mHitFlagWords.z != 0 && (regionFlags & 8) ? 0x12 : 0;
        *outFlags = hitFlags;
        chosenHitRecord = firstHitRecord;
    } else {
        *outFlags = 8;
        chosenHitRecord = secondHitRecord;
    }
    if (depth >= chosenHitRecord->mDeepestDepth) {
        chosenHitRecord->mDeepestDepth = depth;
        if (regionFlags & positiveSideBit) {
            chosenHitRecord->mDeepestNormal = *normal;
        } else {
            chosenHitRecord->mDeepestNormal.x = -normal->x;
            chosenHitRecord->mDeepestNormal.y = -normal->y;
            chosenHitRecord->mDeepestNormal.z = -normal->z;
        }
    }
    if (offset.x > chosenHitRecord->mMaxOffset.x) {
        chosenHitRecord->mMaxOffset.x = offset.x;
    } else if (offset.x < chosenHitRecord->mMinOffset.x) {
        chosenHitRecord->mMinOffset.x = offset.x;
    }
    if (offset.y > chosenHitRecord->mMaxOffset.y) {
        chosenHitRecord->mMaxOffset.y = offset.y;
    } else if (offset.y < chosenHitRecord->mMinOffset.y) {
        chosenHitRecord->mMinOffset.y = offset.y;
    }
    if (offset.z > chosenHitRecord->mMaxOffset.z) {
        chosenHitRecord->mMaxOffset.z = offset.z;
    } else if (offset.z < chosenHitRecord->mMinOffset.z) {
        chosenHitRecord->mMinOffset.z = offset.z;
    }
    if (lowestOffset != NULL) {
        if (regionFlags & positiveSideBit) {
            s32 negatedPenetration = -(sphereRadius - depth);

            offset.x = MUL_FIXED12_NO_ROUND(normal->x, negatedPenetration);
            offset.y = MUL_FIXED12_NO_ROUND(normal->y, negatedPenetration);
            offset.z = MUL_FIXED12_NO_ROUND(normal->z, negatedPenetration);
        } else {
            s32 negatedGap = sphereRadius - depth;

            offset.x = MUL_FIXED12_NO_ROUND(normal->x, negatedGap);
            offset.y = MUL_FIXED12_NO_ROUND(normal->y, negatedGap);
            offset.z = MUL_FIXED12_NO_ROUND(normal->z, negatedGap);
        }
        if (offset.y < lowestOffset->y) {
            *lowestOffset = offset;
        }
    }
    if (!normalAboveThreshold) {
        return;
    }
    ComputeCollisionPointMotion(object, sphereCenter, normal, pointMotion, angleChange);
}

BOOL AddCollisionHitTwoAxes(s32 sphereRadius, s32 firstOffset, s32 secondOffset, u32 regionFlags,
                            u16 firstPositiveSideBit, u16 secondPositiveSideBit, u16 *outFlags, u16 queryFlags,
                            s32 firstAxisFlag, s32 secondAxisFlag, CollisionMapObject *object, Vec3 *sphereCenter,
                            Vec3 *firstNormal, Vec3 *secondNormal, CollisionHitRecord *firstHitRecord,
                            CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset, Vec3 *pointMotion,
                            u16 *angleChange) {
    BOOL normalAboveThreshold;
    BOOL eitherAxisQualifies;
    BOOL axisQualifies;
    s32 value;
    CollisionHitRecord *chosenHitRecord;
    Vec3 firstPush;
    Vec3 secondPush;
    Vec3 direction;

    normalAboveThreshold = FALSE;
    if ((queryFlags & 0x60) == 0) {
        eitherAxisQualifies = TRUE;
        axisQualifies = FALSE;
        if (firstAxisFlag != 0) {
            value = (regionFlags & firstPositiveSideBit) ? firstNormal->y : -firstNormal->y;
            if (value > object->mCollisionData.mFloorThreshold) {
                axisQualifies = TRUE;
            }
        }
        if (axisQualifies == FALSE) {
            axisQualifies = FALSE;
            if (secondAxisFlag != 0) {
                value = (regionFlags & secondPositiveSideBit) ? secondNormal->y : -secondNormal->y;
                if (value > object->mCollisionData.mFloorThreshold) {
                    axisQualifies = TRUE;
                }
            }
            if (axisQualifies == FALSE) {
                eitherAxisQualifies = FALSE;
            }
        }
        if (eitherAxisQualifies != FALSE) {
            normalAboveThreshold = TRUE;
        }
    }
    firstPush.x = MUL_FIXED12_NO_ROUND(firstNormal->x, firstOffset);
    firstPush.y = MUL_FIXED12_NO_ROUND(firstNormal->y, firstOffset);
    firstPush.z = MUL_FIXED12_NO_ROUND(firstNormal->z, firstOffset);
    secondPush.x = MUL_FIXED12_NO_ROUND(secondNormal->x, secondOffset);
    secondPush.y = MUL_FIXED12_NO_ROUND(secondNormal->y, secondOffset);
    secondPush.z = MUL_FIXED12_NO_ROUND(secondNormal->z, secondOffset);
    VEC_Add(&firstPush, &secondPush, &firstPush);
    firstPush.x <<= 10;
    firstPush.y <<= 10;
    firstPush.z <<= 10;
    value = Vec3NormalizeAndGetLengthOrZero(&firstPush, &direction);
    if (value > (sphereRadius << 10)) {
        return FALSE;
    }
    if (value != 0) {
        secondPush.x = MUL_FIXED12_NO_ROUND(direction.x, sphereRadius);
        secondPush.y = MUL_FIXED12_NO_ROUND(direction.y, sphereRadius);
        secondPush.z = MUL_FIXED12_NO_ROUND(direction.z, sphereRadius);
        firstPush.x >>= 10;
        firstPush.y >>= 10;
        firstPush.z >>= 10;
        VEC_Subtract(&secondPush, &firstPush, &secondPush);
        secondOffset = VEC_Mag(&secondPush);
    } else {
        direction = *secondNormal;
        secondPush.x = MUL_FIXED12_NO_ROUND(direction.x, sphereRadius);
        secondPush.y = MUL_FIXED12_NO_ROUND(direction.y, sphereRadius);
        secondPush.z = MUL_FIXED12_NO_ROUND(direction.z, sphereRadius);
        secondOffset = sphereRadius;
    }
    if (normalAboveThreshold) {
        if (object->mCollisionData.mHitFlagWords.z != 0 && (regionFlags & 8)) {
            *outFlags = 0x1e;
            chosenHitRecord = secondHitRecord;
        } else {
            *outFlags = 0;
            chosenHitRecord = firstHitRecord;
        }
    } else {
        *outFlags = 8;
        chosenHitRecord = secondHitRecord;
    }
    if (secondOffset >= chosenHitRecord->mDeepestDepth) {
        chosenHitRecord->mDeepestDepth = secondOffset;
        chosenHitRecord->mDeepestNormal = direction;
    }
    secondPush.x <<= 10;
    secondPush.y <<= 10;
    secondPush.z <<= 10;
    if (secondPush.x > chosenHitRecord->mMaxOffset.x) {
        chosenHitRecord->mMaxOffset.x = secondPush.x;
    } else if (secondPush.x < chosenHitRecord->mMinOffset.x) {
        chosenHitRecord->mMinOffset.x = secondPush.x;
    }
    if (secondPush.y > chosenHitRecord->mMaxOffset.y) {
        chosenHitRecord->mMaxOffset.y = secondPush.y;
    } else if (secondPush.y < chosenHitRecord->mMinOffset.y) {
        chosenHitRecord->mMinOffset.y = secondPush.y;
    }
    if (secondPush.z > chosenHitRecord->mMaxOffset.z) {
        chosenHitRecord->mMaxOffset.z = secondPush.z;
    } else if (secondPush.z < chosenHitRecord->mMinOffset.z) {
        chosenHitRecord->mMinOffset.z = secondPush.z;
    }
    if (lowestOffset != NULL) {
        firstPush.x = -firstPush.x;
        firstPush.y = -firstPush.y;
        firstPush.z = -firstPush.z;
        if (firstPush.y < lowestOffset->y) {
            *lowestOffset = firstPush;
        }
    }
    if (normalAboveThreshold) {
        ComputeCollisionPointMotion(object, sphereCenter, &direction, pointMotion, angleChange);
    }
    return TRUE;
}

BOOL ComputeSphereHitOnCollisionBox(CollisionMapObject *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange) {
    Vec3 offset;
    Vec3 normal;
    Vec3 pushVec;
    CollisionHitRecord *chosenHitRecord;
    u16 regionFlags;
    s32 distanceAxis0;
    s32 distanceAxis1;
    s32 distanceAxis2;
    s32 signedDepthAxis0;
    s32 signedDepthAxis1;
    s32 depthAxis0;
    s32 depthAxis1;
    s32 depthAxis2;
    BOOL normalAboveThreshold;
    BOOL anyAxisQualifies;
    BOOL axisQualifies;
    BOOL firstTwoQualify;
    s32 value;

    regionFlags = 0;
    VEC_Subtract(sphereCenter, &object->mCollisionData.mCenterPos, &offset);
    distanceAxis0 = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[0]);
    if (distanceAxis0 > 0) {
        if (distanceAxis0 > object->mCollisionData.mHalfSizeX + sphereRadius) {
            return FALSE;
        }
        if (distanceAxis0 > object->mCollisionData.mHalfSizeX) {
            regionFlags |= 0xa00;
        } else {
            regionFlags |= 0x900;
        }
    } else {
        if (distanceAxis0 < -(object->mCollisionData.mHalfSizeX + sphereRadius)) {
            return FALSE;
        }
        if (distanceAxis0 < -object->mCollisionData.mHalfSizeX) {
            regionFlags |= 0x600;
        } else {
            regionFlags |= 0x500;
        }
    }
    distanceAxis1 = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[1]);
    if (distanceAxis1 > 0) {
        if (distanceAxis1 > object->mCollisionData.mHalfSizeY + sphereRadius) {
            return FALSE;
        }
        if (distanceAxis1 > object->mCollisionData.mHalfSizeY) {
            regionFlags |= 0xa0;
        } else {
            regionFlags |= 0x90;
        }
    } else {
        if (distanceAxis1 < -(object->mCollisionData.mHalfSizeY + sphereRadius)) {
            return FALSE;
        }
        if (distanceAxis1 < -object->mCollisionData.mHalfSizeY) {
            regionFlags |= 0x60;
        } else {
            regionFlags |= 0x50;
        }
    }
    distanceAxis2 = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[2]);
    if (distanceAxis2 > 0) {
        if (distanceAxis2 > object->mCollisionData.mPositiveHalfSizeZ + sphereRadius) {
            return FALSE;
        }
        if (distanceAxis2 > object->mCollisionData.mPositiveHalfSizeZ) {
            regionFlags |= 0xa;
        } else {
            regionFlags |= 0x9;
        }
    } else {
        if (distanceAxis2 < -(object->mCollisionData.mNegativeHalfSizeZ + sphereRadius)) {
            return FALSE;
        }
        if (distanceAxis2 < -object->mCollisionData.mNegativeHalfSizeZ) {
            regionFlags |= 0x6;
        } else {
            regionFlags |= 0x5;
        }
    }
    if ((queryFlags & 4) && object->mSkipsFlaggedQueries != 0) {
        return FALSE;
    }
    if (regionFlags & 0x100) {
        if (regionFlags & 0x10) {
            if (regionFlags & 0x8) {
                distanceAxis2 = (object->mCollisionData.mPositiveHalfSizeZ + sphereRadius) - distanceAxis2;
            } else {
                distanceAxis2 = -(object->mCollisionData.mNegativeHalfSizeZ + sphereRadius) - distanceAxis2;
            }
            if (regionFlags & 0x1) {
                if (regionFlags & 0x800) {
                    signedDepthAxis0 = (object->mCollisionData.mHalfSizeX + sphereRadius) - distanceAxis0;
                } else {
                    signedDepthAxis0 = -(object->mCollisionData.mHalfSizeX + sphereRadius) - distanceAxis0;
                }
                if (regionFlags & 0x80) {
                    signedDepthAxis1 = (object->mCollisionData.mHalfSizeY + sphereRadius) - distanceAxis1;
                } else {
                    signedDepthAxis1 = -(object->mCollisionData.mHalfSizeY + sphereRadius) - distanceAxis1;
                }
                depthAxis0 = signedDepthAxis0 > 0 ? signedDepthAxis0 : -signedDepthAxis0;
                depthAxis1 = signedDepthAxis1 > 0 ? signedDepthAxis1 : -signedDepthAxis1;
                depthAxis2 = distanceAxis2 > 0 ? distanceAxis2 : -distanceAxis2;
                goto smallest;
            }
            depthAxis2 = distanceAxis2 > 0 ? distanceAxis2 : -distanceAxis2;
            goto hitAxisZ;
        }
        if (regionFlags & 0x80) {
            signedDepthAxis1 = (object->mCollisionData.mHalfSizeY + sphereRadius) - distanceAxis1;
        } else {
            signedDepthAxis1 = -(object->mCollisionData.mHalfSizeY + sphereRadius) - distanceAxis1;
        }
        if (!(regionFlags & 0x1)) {
            goto hitEdgeYZ;
        }
        depthAxis1 = signedDepthAxis1 > 0 ? signedDepthAxis1 : -signedDepthAxis1;
        goto hitAxisY;
    }
    if (regionFlags & 0x800) {
        signedDepthAxis0 = (object->mCollisionData.mHalfSizeX + sphereRadius) - distanceAxis0;
    } else {
        signedDepthAxis0 = -(object->mCollisionData.mHalfSizeX + sphereRadius) - distanceAxis0;
    }
    if (regionFlags & 0x10) {
        if (!(regionFlags & 0x1)) {
            goto hitEdgeZX;
        }
        depthAxis0 = signedDepthAxis0 > 0 ? signedDepthAxis0 : -signedDepthAxis0;
    } else {
        if (!(regionFlags & 0x1)) {
            goto rest;
        }
        goto hitEdgeXY;
    }
hitAxisX:
    AddCollisionHitOneAxis(sphereRadius, signedDepthAxis0, depthAxis0, regionFlags, 0x800, outFlags,
                           object->mCollisionData.mAxis0Flag, object, sphereCenter,
                           &object->mMapObject.mMatrix.mRows[0], firstHitRecord, secondHitRecord, lowestOffset,
                           pointMotion, angleChange);
    return TRUE;
hitAxisY:
    AddCollisionHitOneAxis(sphereRadius, signedDepthAxis1, depthAxis1, regionFlags, 0x80, outFlags,
                           object->mCollisionData.mHitFlagWords.x, object, sphereCenter,
                           &object->mMapObject.mMatrix.mRows[1], firstHitRecord, secondHitRecord, lowestOffset,
                           pointMotion, angleChange);
    return TRUE;
hitAxisZ:
    AddCollisionHitOneAxis(sphereRadius, distanceAxis2, depthAxis2, regionFlags, 8, outFlags,
                           object->mCollisionData.mHitFlagWords.y, object, sphereCenter,
                           &object->mMapObject.mMatrix.mRows[2], firstHitRecord, secondHitRecord, lowestOffset,
                           pointMotion, angleChange);
    return TRUE;
smallest:
    if (depthAxis0 < depthAxis2) {
        if (depthAxis0 < depthAxis1) {
            goto hitAxisX;
        }
        goto hitAxisY;
    }
    if (depthAxis2 < depthAxis1) {
        goto hitAxisZ;
    }
    goto hitAxisY;
hitEdgeXY:
    if (regionFlags & 0x800) {
        distanceAxis0 = distanceAxis0 - object->mCollisionData.mHalfSizeX;
    } else {
        distanceAxis0 = distanceAxis0 + object->mCollisionData.mHalfSizeX;
    }
    if (regionFlags & 0x80) {
        distanceAxis1 = distanceAxis1 - object->mCollisionData.mHalfSizeY;
    } else {
        distanceAxis1 = distanceAxis1 + object->mCollisionData.mHalfSizeY;
    }
    return AddCollisionHitTwoAxes(sphereRadius, distanceAxis0, distanceAxis1, regionFlags, 0x800, 0x80, outFlags,
                                  queryFlags, object->mCollisionData.mAxis0Flag, object->mCollisionData.mHitFlagWords.x,
                                  object, sphereCenter, &object->mMapObject.mMatrix.mRows[0],
                                  &object->mMapObject.mMatrix.mRows[1], firstHitRecord, secondHitRecord, lowestOffset,
                                  pointMotion, angleChange);
hitEdgeYZ:
    if (regionFlags & 0x80) {
        distanceAxis1 = distanceAxis1 - object->mCollisionData.mHalfSizeY;
    } else {
        distanceAxis1 = distanceAxis1 + object->mCollisionData.mHalfSizeY;
    }
    if (regionFlags & 0x8) {
        distanceAxis2 = distanceAxis2 - object->mCollisionData.mPositiveHalfSizeZ;
    } else {
        distanceAxis2 = distanceAxis2 + object->mCollisionData.mNegativeHalfSizeZ;
    }
    return AddCollisionHitTwoAxes(sphereRadius, distanceAxis1, distanceAxis2, regionFlags, 0x80, 0x8, outFlags,
                                  queryFlags, object->mCollisionData.mHitFlagWords.x,
                                  object->mCollisionData.mHitFlagWords.y, object, sphereCenter,
                                  &object->mMapObject.mMatrix.mRows[1], &object->mMapObject.mMatrix.mRows[2],
                                  firstHitRecord, secondHitRecord, lowestOffset, pointMotion, angleChange);
hitEdgeZX:
    if (regionFlags & 0x8) {
        distanceAxis2 = distanceAxis2 - object->mCollisionData.mPositiveHalfSizeZ;
    } else {
        distanceAxis2 = distanceAxis2 + object->mCollisionData.mNegativeHalfSizeZ;
    }
    if (regionFlags & 0x800) {
        distanceAxis0 = distanceAxis0 - object->mCollisionData.mHalfSizeX;
    } else {
        distanceAxis0 = distanceAxis0 + object->mCollisionData.mHalfSizeX;
    }
    return AddCollisionHitTwoAxes(sphereRadius, distanceAxis2, distanceAxis0, regionFlags, 8, 0x800, outFlags,
                                  queryFlags, object->mCollisionData.mHitFlagWords.y, object->mCollisionData.mAxis0Flag,
                                  object, sphereCenter, &object->mMapObject.mMatrix.mRows[2],
                                  &object->mMapObject.mMatrix.mRows[0], firstHitRecord, secondHitRecord, lowestOffset,
                                  pointMotion, angleChange);
rest:
    normalAboveThreshold = FALSE;
    if ((queryFlags & 0x60) == 0) {
        anyAxisQualifies = TRUE;
        firstTwoQualify = TRUE;
        axisQualifies = FALSE;
        if (object->mCollisionData.mAxis0Flag != 0) {
            value =
                (regionFlags & 0x800) ? object->mMapObject.mMatrix.mRows[0].y : -object->mMapObject.mMatrix.mRows[0].y;
            if (value > object->mCollisionData.mFloorThreshold) {
                axisQualifies = TRUE;
            }
        }
        if (axisQualifies == FALSE) {
            axisQualifies = FALSE;
            if (object->mCollisionData.mHitFlagWords.x != 0) {
                value = (regionFlags & 0x80) ? object->mMapObject.mMatrix.mRows[1].y
                                             : -object->mMapObject.mMatrix.mRows[1].y;
                if (value > object->mCollisionData.mFloorThreshold) {
                    axisQualifies = TRUE;
                }
            }
            if (axisQualifies == FALSE) {
                firstTwoQualify = FALSE;
            }
        }
        if (firstTwoQualify == FALSE) {
            signedDepthAxis1 = 0;
            if (object->mCollisionData.mHitFlagWords.y != 0) {
                value = (regionFlags & 0x8) ? object->mMapObject.mMatrix.mRows[2].y
                                            : -object->mMapObject.mMatrix.mRows[2].y;
                if (value > object->mCollisionData.mFloorThreshold) {
                    signedDepthAxis1 = 1;
                }
            }
            if (signedDepthAxis1 == 0) {
                anyAxisQualifies = FALSE;
            }
        }
        if (anyAxisQualifies != FALSE) {
            normalAboveThreshold = TRUE;
        }
    }
    if (regionFlags & 0x800) {
        distanceAxis0 = distanceAxis0 - object->mCollisionData.mHalfSizeX;
    } else {
        distanceAxis0 = distanceAxis0 + object->mCollisionData.mHalfSizeX;
    }
    if (regionFlags & 0x80) {
        distanceAxis1 = distanceAxis1 - object->mCollisionData.mHalfSizeY;
    } else {
        distanceAxis1 = distanceAxis1 + object->mCollisionData.mHalfSizeY;
    }
    if (regionFlags & 0x8) {
        distanceAxis2 = distanceAxis2 - object->mCollisionData.mPositiveHalfSizeZ;
    } else {
        distanceAxis2 = distanceAxis2 + object->mCollisionData.mNegativeHalfSizeZ;
    }
    offset.x = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].x, distanceAxis0);
    offset.y = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].y, distanceAxis0);
    offset.z = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].z, distanceAxis0);
    normal.x = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[1].x, distanceAxis1);
    normal.y = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[1].y, distanceAxis1);
    normal.z = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[1].z, distanceAxis1);
    VEC_Add(&normal, &offset, &offset);
    normal.x = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[2].x, distanceAxis2);
    normal.y = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[2].y, distanceAxis2);
    normal.z = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[2].z, distanceAxis2);
    VEC_Add(&normal, &offset, &offset);
    offset.x <<= 10;
    offset.y <<= 10;
    offset.z <<= 10;
    value = Vec3NormalizeAndGetLengthOrZero(&offset, &normal);
    if (value > (sphereRadius << 10)) {
        return FALSE;
    }
    if (value != 0) {
        pushVec.x = MUL_FIXED12_NO_ROUND(normal.x, sphereRadius);
        pushVec.y = MUL_FIXED12_NO_ROUND(normal.y, sphereRadius);
        pushVec.z = MUL_FIXED12_NO_ROUND(normal.z, sphereRadius);
        offset.x >>= 10;
        offset.y >>= 10;
        offset.z >>= 10;
        VEC_Subtract(&pushVec, &offset, &pushVec);
        sphereRadius = VEC_Mag(&pushVec);
    } else {
        normal = object->mMapObject.mMatrix.mRows[1];
        pushVec.x = MUL_FIXED12_NO_ROUND(normal.x, sphereRadius);
        pushVec.y = MUL_FIXED12_NO_ROUND(normal.y, sphereRadius);
        pushVec.z = MUL_FIXED12_NO_ROUND(normal.z, sphereRadius);
    }
    if (normalAboveThreshold) {
        if (object->mCollisionData.mHitFlagWords.z != 0 && (regionFlags & 0x8)) {
            *outFlags = 0x1e;
            chosenHitRecord = secondHitRecord;
        } else {
            *outFlags = 0;
            chosenHitRecord = firstHitRecord;
        }
    } else {
        *outFlags = 8;
        chosenHitRecord = secondHitRecord;
    }
    if (sphereRadius >= chosenHitRecord->mDeepestDepth) {
        chosenHitRecord->mDeepestDepth = sphereRadius;
        chosenHitRecord->mDeepestNormal = normal;
    }
    pushVec.x <<= 10;
    pushVec.y <<= 10;
    pushVec.z <<= 10;
    if (pushVec.x > chosenHitRecord->mMaxOffset.x) {
        chosenHitRecord->mMaxOffset.x = pushVec.x;
    } else if (pushVec.x < chosenHitRecord->mMinOffset.x) {
        chosenHitRecord->mMinOffset.x = pushVec.x;
    }
    if (pushVec.y > chosenHitRecord->mMaxOffset.y) {
        chosenHitRecord->mMaxOffset.y = pushVec.y;
    } else if (pushVec.y < chosenHitRecord->mMinOffset.y) {
        chosenHitRecord->mMinOffset.y = pushVec.y;
    }
    if (pushVec.z > chosenHitRecord->mMaxOffset.z) {
        chosenHitRecord->mMaxOffset.z = pushVec.z;
    } else if (pushVec.z < chosenHitRecord->mMinOffset.z) {
        chosenHitRecord->mMinOffset.z = pushVec.z;
    }
    if (lowestOffset != NULL) {
        offset.x = -offset.x;
        offset.y = -offset.y;
        offset.z = -offset.z;
        if (offset.y < lowestOffset->y) {
            *lowestOffset = offset;
        }
    }
    if (normalAboveThreshold) {
        ComputeCollisionPointMotion(object, sphereCenter, &normal, pointMotion, angleChange);
    }
    return TRUE;
}

BOOL ComputeSphereHitOnCollisionCylinder(CollisionMapObject *object, Vec3 *sphereCenter, s32 sphereRadius,
                                         u16 queryFlags, CollisionHitRecord *firstHitRecord,
                                         CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset, u16 *outFlags,
                                         Vec3 *pointMotion, u16 *angleChange) {
    Vec3 offset;
    s32 axialDepth;
    Vec3 normal;
    s32 combinedRadius;
    s32 radialOverlap;
    s64 squaredRadialDistance;
    u16 regionFlags;
    s32 distanceAxis0;
    s32 alongAxis2;
    s32 distanceAxis1;

    regionFlags = 0;
    VEC_Subtract(sphereCenter, &object->mCollisionData.mCenterPos, &offset);
    distanceAxis0 = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[0]);
    alongAxis2 = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[2]);
    squaredRadialDistance = SQUARE_SUM2(distanceAxis0, alongAxis2);
    combinedRadius = object->mCollisionData.mHalfSizeX + sphereRadius;
    if ((s64) combinedRadius * combinedRadius < squaredRadialDistance) {
        return FALSE;
    }
    if ((s64) object->mCollisionData.mHalfSizeX * object->mCollisionData.mHalfSizeX < squaredRadialDistance) {
        regionFlags |= gCylinderOuterRegionFlag;
    } else {
        regionFlags |= gCylinderInnerRegionFlag;
    }
    distanceAxis1 = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[1]);
    if (distanceAxis1 > 0) {
        if (distanceAxis1 > object->mCollisionData.mHalfSizeY + sphereRadius) {
            return FALSE;
        }
        if (distanceAxis1 > object->mCollisionData.mHalfSizeY) {
            regionFlags |= 0xa0;
        } else {
            regionFlags |= 0x90;
        }
    } else {
        if (distanceAxis1 < -(object->mCollisionData.mHalfSizeY + sphereRadius)) {
            return FALSE;
        }
        if (distanceAxis1 < -object->mCollisionData.mHalfSizeY) {
            regionFlags |= 0x60;
        } else {
            regionFlags |= 0x50;
        }
    }
    if (regionFlags & 0x1000) {
        if (regionFlags & 0x80) {
            distanceAxis1 = object->mCollisionData.mHalfSizeY + sphereRadius - distanceAxis1;
        } else {
            distanceAxis1 = -(object->mCollisionData.mHalfSizeY + sphereRadius) - distanceAxis1;
        }
        if (distanceAxis1 > 0) {
            axialDepth = distanceAxis1;
        } else {
            axialDepth = -distanceAxis1;
        }
        if (!(regionFlags & 0x10)) {
            goto apply80;
        }
        offset.x = distanceAxis0;
        offset.y = 0;
        offset.z = alongAxis2;
        distanceAxis0 = Vec3NormalizeXZAndGetLengthOrZero(&offset, &offset);
        radialOverlap = combinedRadius - distanceAxis0;
        if (distanceAxis0 == 0) {
            normal = gCylinderInnerZeroDistanceNormal;
        } else {
            normal.x = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].x, offset.x);
            normal.y = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].y, offset.x);
            normal.z = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].z, offset.x);
            VEC_MultAdd(offset.z, &object->mMapObject.mMatrix.mRows[2], &normal, &normal);
        }
        goto cmp;
    }
    offset.x = distanceAxis0;
    offset.y = 0;
    offset.z = alongAxis2;
    distanceAxis0 = Vec3NormalizeXZAndGetLengthOrZero(&offset, &offset);
    radialOverlap = combinedRadius - distanceAxis0;
    if (distanceAxis0 == 0) {
        normal = gCylinderOuterZeroDistanceNormal;
    } else {
        normal.x = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].x, offset.x);
        normal.y = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].y, offset.x);
        normal.z = MUL_FIXED12_NO_ROUND(object->mMapObject.mMatrix.mRows[0].z, offset.x);
        VEC_MultAdd(offset.z, &object->mMapObject.mMatrix.mRows[2], &normal, &normal);
    }
    if (regionFlags & 0x10) {
        goto apply3000;
    }
    goto tail;
apply80:
    AddCollisionHitOneAxis(sphereRadius, distanceAxis1, axialDepth, regionFlags, 0x80, outFlags,
                           object->mCollisionData.mHitFlagWords.x, object, sphereCenter,
                           &object->mMapObject.mMatrix.mRows[1], firstHitRecord, secondHitRecord, lowestOffset,
                           pointMotion, angleChange);
    return TRUE;
apply3000:
    AddCollisionHitOneAxis(sphereRadius, radialOverlap, distanceAxis0, regionFlags, 0x3000, outFlags,
                           object->mCollisionData.mAxis0Flag, object, sphereCenter, &normal, firstHitRecord,
                           secondHitRecord, lowestOffset, pointMotion, angleChange);
    return TRUE;
tail:
    distanceAxis0 = distanceAxis0 - object->mCollisionData.mHalfSizeX;
    if (regionFlags & 0x80) {
        distanceAxis1 = distanceAxis1 - object->mCollisionData.mHalfSizeY;
    } else {
        distanceAxis1 = distanceAxis1 + object->mCollisionData.mHalfSizeY;
    }
    return AddCollisionHitTwoAxes(sphereRadius, distanceAxis0, distanceAxis1, regionFlags, 0x3000, 0x80, outFlags,
                                  queryFlags, object->mCollisionData.mAxis0Flag, object->mCollisionData.mHitFlagWords.x,
                                  object, sphereCenter, &normal, &object->mMapObject.mMatrix.mRows[1], firstHitRecord,
                                  secondHitRecord, lowestOffset, pointMotion, angleChange);
cmp:
    if (radialOverlap < axialDepth) {
        goto apply3000;
    }
    goto apply80;
}

void ComputeCollisionPointMotion(CollisionMapObject *object, Vec3 *position, Vec3 *contactNormal, Vec3 *pointMotion,
                                 u16 *angleChange) {
    Vec3 offset;

    if (pointMotion != NULL) {
        pointMotion->x = -object->mMapObject.mPosStep.x;
        pointMotion->y = -object->mMapObject.mPosStep.y;
        pointMotion->z = -object->mMapObject.mPosStep.z;
        VEC_Subtract(position, &object->mMapObject.mPos, &offset);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[0]),
                    &object->mCollisionData.mPrevMatrix.mRows[0], pointMotion, pointMotion);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[1]),
                    &object->mCollisionData.mPrevMatrix.mRows[1], pointMotion, pointMotion);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[2]),
                    &object->mCollisionData.mPrevMatrix.mRows[2], pointMotion, pointMotion);
        VEC_Subtract(&offset, pointMotion, pointMotion);
    }
    if (angleChange != NULL) {
        *angleChange = Vec3DotUnrounded(&object->mCollisionData.mAngleChangeVector, contactNormal);
    }
}

const u16 gVehicleHitFlag = 1;
