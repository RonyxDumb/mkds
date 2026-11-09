#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020f36d8.h" // ItemObject
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_02147000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020f3678.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "01/code_02187eb0.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_020d9000.h"
#include "code_021471bc.h"

#pragma thumb on

void InitChoropu(Unk020e2f0c *choropu, struct CourseMapRow *courseRow) {
    InitStateMachine(&choropu->mUnk_000.mStateMachine, (UnkFunc *const *) gChoropuStateTable, 8, choropu);
    choropu->mUnk_0a8 = choropu->mUnk_000.mPos.y;
    choropu->mUnk_0ac = choropu->mUnk_000.mPos.y - 0x12000;
    choropu->mUnk_0b0 = choropu->mUnk_000.mPos.y - 0x18000;
    choropu->mUnk_0a4 = courseRow->mUnk_28;
    choropu->mUnk_0a0 = courseRow->mUnk_2a;
    choropu->mUnk_000.mStateMachine.mNextState = 0;
    choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&choropu->mUnk_0bc, &choropu->mUnk_000.mPos, ((s64) choropu->mUnk_000.mScale.x * 0x1b000) >> 12,
                        0x1e);
    choropu->mUnk_000.mFlags |= data_02158b7c;
}

#pragma thumb off

void *CreateCarAKindData(void) {
    Unk020e03f8 *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *kindData = data_02158b3c;
    return kindData;
}

void *CreateTruckAKindData(void) {
    Unk020e03f8 *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *kindData = data_02158afc;
    return kindData;
}

void *CreateBusAKindData(void) {
    Unk020e03f8 *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *kindData = data_02158abc;
    return kindData;
}

void *CreateVehicleDrawList(void) {
    VehicleDrawList *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    gVehicleDrawList = drawList;
    *drawList = data_02158a7c;
    SetDrawListSlot(&gVehicleDrawList);
    return gVehicleDrawList;
}

void *CreateVehicleUpdateList(void) {
    MapObjectList *updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);

    gVehicleUpdateList = updateList;
    *updateList = data_02158a54;
    SetUpdateListSlot(&gVehicleUpdateList);
    return gVehicleUpdateList;
}

void SetVehicleLinkDirection(VehicleDrawList *drawList) {
    u16 entryIndex;

    entryIndex = gRaceSetup->mEntryIndex;
    if (drawList->mUnk_038 == FALSE) {
        return;
    }
    if (entryIndex < 8) {
        GetItemPointLinkDirection(gKartItems[entryIndex].mUnk_1f0.mLink, &drawList->mEntryKartLinkDirection);
        drawList->mUnk_03c = Vec3DotUnrounded(&drawList->mEntryKartLinkDirection, GetViewTransposeMatrixAxis2()) < 0;
    } else {
        drawList->mUnk_03c = FALSE;
    }
}

void DrawVehicle(VehicleDrawList *drawList, Unk020e1e98 *vehicle, u32 c, u32 alpha) {
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
    s32 x;
    s32 y;

    if (drawList->mUnk_03c != FALSE) {
        dotAxis2 = Vec3DotUnrounded(&vehicle->mUnk_000.mMatrix.mUnk_00[2], &drawList->mEntryKartLinkDirection);
        directionFlag = vehicle->mUnk_000.mCourseMapRow->mUnk_2e;
        dotLimit = vehicle->mUnk_0d8.mFromEntry->mUnk_12;
        if (directionFlag == 0) {
            dotAxis2 = -dotAxis2;
        }
        if (dotAxis2 > dotLimit) {
            return;
        }
    }
    skipShadowAndTires =
        (s32) (vehicle->mUnk_000.mDistanceSquaredAndFlags & 0x3FFFFFE0) > 0x77A10 && func_0203c5e4() == 0;
    if (!skipShadowAndTires) {
        if (vehicle->mUnk_128 != 0) {
            shadowPosition = vehicle->mUnk_0fe > 0xF ? &vehicle->mUnk_144 : &vehicle->mUnk_000.mPos;
            vehicle->mUnk_000.mMatrix.mUnk_00[3].x = shadowPosition->x >> 4;
            vehicle->mUnk_000.mMatrix.mUnk_00[3].y = shadowPosition->y >> 4;
            vehicle->mUnk_000.mMatrix.mUnk_00[3].z = shadowPosition->z >> 4;
            DrawShadowWithMaxAlpha((void *) vehicle->mUnk_128, &vehicle->mUnk_000.mMatrix, &vehicle->mUnk_000.mScale,
                                   alpha);
        }
    }
    vehicle->mUnk_000.mMatrix.mUnk_00[3].x = vehicle->mUnk_000.mPos.x >> 4;
    vehicle->mUnk_000.mMatrix.mUnk_00[3].y = vehicle->mUnk_000.mPos.y >> 4;
    vehicle->mUnk_000.mMatrix.mUnk_00[3].z = vehicle->mUnk_000.mPos.z >> 4;
    animation = vehicle->mUnk_12c;
    if (animation != NULL) {
        animation->mHead.mFrameIndex = vehicle->mUnk_130 << 12;
        animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
    }
    SendLight01Color(&vehicle->mUnk_132);
    DrawNsbmdWithMatrixAndMaxAlpha((void *) vehicle->mUnk_124, &vehicle->mUnk_000.mMatrix, &vehicle->mUnk_000.mScale,
                                   alpha);
    if (skipShadowAndTires) {
        return;
    }
    angleIndex = vehicle->mUnk_10c >> 4;
    anglePairs = gPairsByAngle;
    x = ((s64) vehicle->mUnk_110 * anglePairs[angleIndex * 2] + 0x800) >> 12;
    y = ((s64) vehicle->mUnk_110 * anglePairs[angleIndex * 2 + 1] + 0x800) >> 12;
    MTX_RotX43_(&tireMatrix, x, y);
    tireMatrix.mUnk_00[0].x = vehicle->mUnk_100[0];
    tireMatrix.mUnk_00[3].y = vehicle->mUnk_100[1];
    tireMatrix.mUnk_00[3].z = vehicle->mUnk_100[2];
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x19, &tireMatrix, 0xc);
    DrawNsbmd(gCarTire);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    tireMatrix.mUnk_00[3].z = -tireMatrix.mUnk_00[3].z;
    NNS_G3dGeBufferOP_N(0x19, &tireMatrix, 0xc);
    DrawNsbmd(gCarTire);
}

static inline s64 func_020e2630_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

static inline s16 func_020e2630_inline2(Unk020e1e98 *b) {
    return b->mUnk_0fe;
}

void UpdateVehicle(u32 a, Unk020e1e98 *vehicle) {
    enum { K0 } isInHitReaction;
    Quaternion *baseRotation;
    u32 hitFlags;
    Quaternion targetRotation;
    Vec3 previousPosition;
    Vec3 probeOffset;
    Vec3 u;
    Vec3 testPosition;

    if (vehicle->mUnk_0fe > 0xf) {
        isInHitReaction = 1;
        isInHitReaction = (s32) isInHitReaction;
    } else {
        isInHitReaction = 0;
    }
    previousPosition = vehicle->mUnk_000.mPos;
    AdvanceGroupFollower(&vehicle->mUnk_0d8);
    if (!isInHitReaction) {
        GetGroupFollowerCurveXzLinearY(&vehicle->mUnk_0d8, &vehicle->mUnk_000.mPos);
        VEC_Subtract(&vehicle->mUnk_000.mPos, &previousPosition, &vehicle->mUnk_000.mUnk_10);
    } else {
        GetGroupFollowerCurveXzLinearY(&vehicle->mUnk_0d8, &vehicle->mUnk_144);
        vehicle->mUnk_000.mPos.x = vehicle->mUnk_144.x;
        vehicle->mUnk_000.mUnk_10.y -= 0x59a;
        vehicle->mUnk_000.mPos.y = vehicle->mUnk_000.mPos.y + vehicle->mUnk_000.mUnk_10.y;
        vehicle->mUnk_000.mPos.z = vehicle->mUnk_144.z;
        vehicle->mUnk_000.mUnk_10.x = vehicle->mUnk_000.mPos.x - previousPosition.x;
        vehicle->mUnk_000.mUnk_10.z = vehicle->mUnk_000.mPos.z - previousPosition.z;
    }
    if (isInHitReaction || (vehicle->mUnk_0d4 & 7) == GetRaceUpdateFramesMod8()) {
        testPosition.x = vehicle->mUnk_000.mPos.x;
        testPosition.y = vehicle->mUnk_000.mPos.y + (isInHitReaction ? 0xf000 : 0);
        testPosition.z = vehicle->mUnk_000.mPos.z;
        u = testPosition;
        if (CollideSphereWithCourse(&u, NULL, 0, 0xf000, 8, -2, &probeOffset, &u, NULL, &hitFlags, NULL, NULL, NULL,
                                    NULL) != 0) {
            if (hitFlags & 0x1e34ef) {
                QuaternionFromYAxisToVec3(&u, &vehicle->mUnk_0b4);
                AdvanceCourseColorBlend(&vehicle->mUnk_132, (hitFlags & 0x3c000000) >> 26, 0x5000);
                if (vehicle->mUnk_0fe != 0 && vehicle->mUnk_000.mUnk_10.y < 0) {
                    if (vehicle->mUnk_000.mFlags & 1) {
                        vehicle->mUnk_000.mFlags &= ~1;
                        vehicle->mUnk_000.mUnk_10.y = -(s32) (((s64) vehicle->mUnk_000.mUnk_10.y *
                                                               (0x733 + ((vehicle->mUnk_114.y - 0x14000) >> 9))) >>
                                                              12);
                        vehicle->mUnk_0c4.mComponents[0] = -vehicle->mUnk_0c4.mComponents[0];
                        vehicle->mUnk_0c4.mComponents[1] = -vehicle->mUnk_0c4.mComponents[1];
                        vehicle->mUnk_0c4.mComponents[2] = -vehicle->mUnk_0c4.mComponents[2];
                        QuaternionBlendTowardNearerSign(&vehicle->mUnk_0c4, &vehicle->mUnk_0b4, &vehicle->mUnk_0c4,
                                                        0x8cd);
                        vehicle->mUnk_152 = 0x320;
                        StartMapObjectSound(&vehicle->mUnk_000, vehicle->mUnk_160);
                    } else if (isInHitReaction && vehicle != NULL) {
                        vehicle->mUnk_0fe = 0xf;
                        vehicle->mUnk_000.mUnk_10.y = 0;
                        vehicle->mUnk_152 = 0x258;
                    }
                }
            }
            if ((hitFlags & 0x214300) && isInHitReaction) {
                vehicle->mUnk_000.mPos.y = vehicle->mUnk_000.mPos.y + probeOffset.y;
                vehicle->mUnk_000.mUnk_10.y = 0;
            }
        }
    }
    switch (isInHitReaction) {
        default:
            if (vehicle->mUnk_000.mUnk_10.y < 0) {
                vehicle->mUnk_152 = ((s64) (-vehicle->mUnk_000.mUnk_10.y) * 0xc) >> 12;
                baseRotation = &vehicle->mUnk_0b4;
            } else {
                baseRotation = &vehicle->mUnk_0c4;
            }
            break;

        case 0:
            if (func_020e2630_inline2(vehicle) != 0) {
                vehicle->mUnk_0fe--;
                if (vehicle->mUnk_0fe == 0) {
                    vehicle->mUnk_152 = vehicle->mUnk_150;
                } else {
                    baseRotation = &vehicle->mUnk_0b4;
                }
            }
            break;
    }

    if (func_020e2630_inline(&vehicle->mUnk_000.mUnk_10) < 0x10) {
        targetRotation = vehicle->mUnk_0b4;
    } else {
        vehicle->mUnk_000.mAngle =
            (s16) (((s64) FX_Atan2(vehicle->mUnk_000.mUnk_10.x, vehicle->mUnk_000.mUnk_10.z) * 0x28BE60DB9391 +
                    0x80000000000) >>
                   44);
        if (vehicle->mUnk_0fe == 0) {
            baseRotation = &vehicle->mUnk_0b4;
        }
        QuaternionMultiplyAngleAroundYIgnoreY(baseRotation, vehicle->mUnk_000.mAngle, &targetRotation);
    }
    QuaternionBlendTowardNearerSign(&vehicle->mUnk_0a4, &targetRotation, &vehicle->mUnk_0a4, vehicle->mUnk_152);
    Matrix3x3FromQuaternion(&vehicle->mUnk_000.mMatrix.mUnk_00_m, &vehicle->mUnk_0a4);
    vehicle->mUnk_10c += 0x600;
    if (vehicle->mUnk_000.mDistanceSquaredAndFlags & 8) {
        AdvanceSoundDistanceSquaredChange(vehicle->mUnk_158, vehicle->mUnk_000.mDistanceSquaredAndFlags & 0x3FFFFFE0);
    }
    StartMapObjectSoundWhileRequested(&vehicle->mUnk_000, vehicle->mUnk_15c);
    if (vehicle->mUnk_000.mPos.y < 0) {
        ResetVehicleToStartEntry(vehicle);
    }
}

void StartVehicleHitReaction(Unk020e1e98 *vehicle, Vec3 *hitterPosition) {
    Vec3 direction;
    s32 dotAxis0;
    s32 dotAxis2;
    s32 upwardSpeed;

    direction = vehicle->mUnk_000.mPos;
    VEC_Subtract(&direction, hitterPosition, &direction);
    dotAxis0 = Vec3DotUnrounded(&vehicle->mUnk_000.mMatrix.mUnk_00[0], &direction);
    dotAxis2 = Vec3DotUnrounded(&vehicle->mUnk_000.mMatrix.mUnk_00[2], &direction);
    direction.x = (dotAxis0 > 0 ? vehicle->mUnk_000.mMatrix.mUnk_00[0].x : -vehicle->mUnk_000.mMatrix.mUnk_00[0].x) * 2;
    direction.x += dotAxis2 > 0 ? vehicle->mUnk_000.mMatrix.mUnk_00[2].x : -vehicle->mUnk_000.mMatrix.mUnk_00[2].x;
    direction.z = (dotAxis0 > 0 ? vehicle->mUnk_000.mMatrix.mUnk_00[0].z : -vehicle->mUnk_000.mMatrix.mUnk_00[0].z) * 2;
    direction.z += dotAxis2 > 0 ? vehicle->mUnk_000.mMatrix.mUnk_00[2].z : -vehicle->mUnk_000.mMatrix.mUnk_00[2].z;
    direction.y = ((vehicle->mUnk_114.y - 0x14000) >> 4) + 0x2000;
    if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
    }
    QuaternionFromYAxisToVec3(&direction, &vehicle->mUnk_0c4);
    vehicle->mUnk_152 = 0x384;
    if (vehicle->mUnk_0fe > 0xf || vehicle->mUnk_000.mUnk_10.y <= 0) {
        upwardSpeed = 0;
    } else {
        upwardSpeed = vehicle->mUnk_000.mUnk_10.y;
    }
    vehicle->mUnk_000.mUnk_10.y = upwardSpeed + 0x7000;
    vehicle->mUnk_000.mFlags |= data_02158a50;
    vehicle->mUnk_0fe = 0x14;
}

u8 CollideKartWithVehicle(Unk020e1e98 *vehicle, Kart *kart, u8 *c, u8 *d) {
    if (*c == 1) {
        StartVehicleHitReaction(vehicle, &kart->mPos);
        StartSoundIfKartStarOrKiller(&vehicle->mUnk_000, kart);
    }
    return *d;
}

u8 CollideItemObjectWithVehicle(Unk020e1e98 *vehicle, ItemObject *itemObject, u8 *c, u8 *d) {
    if (*c == 1) {
        StartVehicleHitReaction(vehicle, &itemObject->mPos);
    }
    return *d;
}

void ComputeSphereHitOnVehicle(Unk020e1e98 *vehicle, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 halfSizesPositive;
    Vec3 halfSizesNegative;
    s32 x;
    s32 y;
    s32 z;

    z = vehicle->mUnk_114.z;
    y = vehicle->mUnk_114.y;
    x = vehicle->mUnk_114.x;
    halfSizesPositive.x = x;
    halfSizesPositive.y = y;
    halfSizesPositive.z = z;
    z = vehicle->mUnk_120;
    x = vehicle->mUnk_114.x;
    halfSizesNegative.x = x;
    halfSizesNegative.y = 0;
    halfSizesNegative.z = z;
    ComputeSphereHitOnRotatedBox(sphereCenter, &vehicle->mUnk_000.mPos, &vehicle->mUnk_000.mMatrix.mUnk_00[0],
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
    Unk020e1e98 *vehicle;
    s16 angleDegrees;
    s16 dotLimit;
    float scaledDegrees;

    count = updateList->mMapObjectCount;
    vehicleCursor = updateList->mMapObjects;
    seenGroupMask = 0;
    zero = 0;
    for (index = 0; index < count; index++) {
        vehicle = *vehicleCursor;
        groupIndex = vehicle->mUnk_000.mCourseMapRow->mUnk_26;
        vehicle->mUnk_0d4 = index;
        if ((seenGroupMask & (1 << groupIndex)) == 0) {
            entryCount = gCourseMap->mEntryGroups[groupIndex].mEntryCount;
            seenGroupMask |= 1 << groupIndex;
            for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
                entry = GetCourseMapGroupEntry(groupIndex, entryIndex);
                angleDegrees = entry->mUnk_0e;
                if (angleDegrees != 0) {
                    if (angleDegrees > 0) {
                        scaledDegrees = 0.5f + (angleDegrees << 12);
                    } else {
                        scaledDegrees = (angleDegrees << 12) - 0.5f;
                    }
                    dotLimit = gPairsByAngle
                        [((((u16) (((s64) (s32) scaledDegrees * 0xB60B60B60B + 0x80000000000) >> 44)) >> 4) << 1) + 1];
                } else {
                    dotLimit = 0x2000;
                }
                entry->mUnk_12 = dotLimit;
                entry->mUnk_0e = zero;
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
    Unk020e1e98 *vehicle;
    u32 *modelSlot;
    ModelAnimation **animationSlot;
    s32 count;

    carFile = FindCourseMapObjFile(gCarANsbmdName);
    truckFile = FindCourseMapObjFile(gTruckANsbmdName);
    drawList->mUnk_038 =
        gRaceSetup->mMode != MODE_MISSION_RUN && func_0203c5e4() == 0 && (u16) gRaceSetup->mEntryIndex < 8;
    drawList->mUnk_03c = FALSE;
    CreateNsbmd(&gCarA, carFile, NULL);
    CreateNsbmd(&gTruckA, truckFile, NULL);
    CreateNsbmd(&gBusA, FindCourseMapObjFile(gBusANsbmdName), NULL);
    CreateNsbmd(&gCarTire, FindCourseMapObjFile(gCarTireNsbmdName), NULL);
    CreateShadowModel(&gCarAShadow, FindCourseMapObjFile(gCarAShadowNsbmdName), 7);
    CreateShadowModel(&gTruckAShadow, FindCourseMapObjFile(gTruckAShadowNsbmdName), 7);
    CreateShadowModel(&gBusAShadow, FindCourseMapObjFile(gBusAShadowNsbmdName), 7);
    CreateModelAnimation(2, gCarA, &gCarANsbtp, carFile, FindCourseMapObjFile(gCarANsbtpName));
    CreateModelAnimation(2, gTruckA, &gTruckANsbtp, truckFile, FindCourseMapObjFile(gTruckANsbtpName));
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
        modelSlot = vehicle->mUnk_154->mUnk_20;
        vehicle->mUnk_124 = modelSlot != NULL ? *modelSlot : 0;
        modelSlot = vehicle->mUnk_154->mUnk_24;
        vehicle->mUnk_128 = modelSlot != NULL ? *modelSlot : 0;
        animationSlot = vehicle->mUnk_154->mUnk_28;
        vehicle->mUnk_12c = animationSlot != NULL ? *animationSlot : 0;
    }
}

void InitVehicle(Unk020e1e98 *vehicle, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo) {
    vehicle->mUnk_154 = kindInfo;
    InitGroupFollower(&vehicle->mUnk_0d8, courseRow, (s16) courseRow->mUnk_28 * 0x3000 / 100);
    vehicle->mUnk_0fc = courseRow->mUnk_2a;
    vehicle->mUnk_130 = courseRow->mUnk_2c;
    vehicle->mUnk_0a0 = GetCourseMapGroupEntry(courseRow->mUnk_26, vehicle->mUnk_0fc)->mPos.y;
    vehicle->mUnk_114.x = ((s64) kindInfo->mUnk_00 * vehicle->mUnk_000.mScale.x) >> 12;
    vehicle->mUnk_114.y = ((s64) kindInfo->mUnk_04 * vehicle->mUnk_000.mScale.y) >> 12;
    vehicle->mUnk_114.z = ((s64) kindInfo->mUnk_08 * vehicle->mUnk_000.mScale.z) >> 12;
    vehicle->mUnk_120 = ((s64) kindInfo->mUnk_0c * vehicle->mUnk_000.mScale.z) >> 12;
    vehicle->mUnk_152 = (u32) ((s16) courseRow->mUnk_28 * 0xfa) / 100;
    vehicle->mUnk_150 = vehicle->mUnk_152;
    vehicle->mUnk_100[0] = kindInfo->mUnk_10;
    vehicle->mUnk_100[1] = kindInfo->mUnk_14 >> 4;
    vehicle->mUnk_100[2] = kindInfo->mUnk_18 >> 4;
    vehicle->mUnk_110 = kindInfo->mUnk_1c;
    ResetVehicleToStartEntry(vehicle);
    vehicle->mUnk_15c = kindInfo->mUnk_2c;
    vehicle->mUnk_158 = CreateVehicleSoundSource(&vehicle->mUnk_000);
    ResetSoundDistanceSquaredChange(vehicle->mUnk_158);
    vehicle->mUnk_000.mSound->mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetVehicleSoundTrackParams;
    vehicle->mUnk_160 = kindInfo->mUnk_30;
}

void ResetVehicleToStartEntry(Unk020e1e98 *vehicle) {
    SetupGroupFollowerAtEntry(&vehicle->mUnk_0d8, vehicle->mUnk_0fc, 1);
    GetGroupFollowerCurvePosStepXz(&vehicle->mUnk_0d8, &vehicle->mUnk_000.mPos, &vehicle->mUnk_000.mUnk_10);
    vehicle->mUnk_000.mPos.y = vehicle->mUnk_0a0;
    vehicle->mUnk_000.mUnk_10.y = 0;
    vehicle->mUnk_0b4 = gIdentityQuaternion;
    QuaternionMultiplyAngleAroundYIgnoreY(
        &vehicle->mUnk_0b4,
        (u16) (((s64) FX_Atan2(vehicle->mUnk_000.mUnk_10.x, vehicle->mUnk_000.mUnk_10.z) * 0x28be60db9391 +
                0x80000000000) >>
               44),
        &vehicle->mUnk_0a4);
    Matrix3x3FromQuaternion(&vehicle->mUnk_000.mMatrix.mUnk_00_m, &vehicle->mUnk_0a4);
    vehicle->mUnk_0fe = 0;
    vehicle->mUnk_152 = vehicle->mUnk_150;
    vehicle->mUnk_10c = 0;
    InitCourseColorBlend(&vehicle->mUnk_132, 1);
}

#pragma thumb off

void DrawVisibleMapObjects(MapObjectList *list, void *viewMatrix, void (*drawObject)(Unk020e3ef4 *, void *, u32)) {
    s32 index;
    s32 count = list->mMapObjectCount;

    for (index = 0; index < count; index++) {
        Unk020e3ef4 *mapObject = list->mMapObjects[index];

        if ((mapObject->mUnk_000.mMapObject.mFlags & 0x12) == 0 && mapObject->mUnk_000.mMapObject.mAlpha != 0) {
            drawObject(mapObject, viewMatrix, mapObject->mUnk_000.mMapObject.mAlpha);
        }
    }
}

void DrawMapObjectModelAtPos(Unk020e3ef4 *mapObject, void *viewMatrix, u32 alpha) {
    mapObject->mUnk_000.mMapObject.mMatrix.mUnk_00[3].x = mapObject->mUnk_000.mMapObject.mPos.x >> 4;
    mapObject->mUnk_000.mMapObject.mMatrix.mUnk_00[3].y = mapObject->mUnk_000.mMapObject.mPos.y >> 4;
    mapObject->mUnk_000.mMapObject.mMatrix.mUnk_00[3].z = mapObject->mUnk_000.mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(mapObject->mModel, &mapObject->mUnk_000.mMapObject.mMatrix,
                                   &mapObject->mUnk_000.mMapObject.mScale.x, alpha);
}

void SetMapObjectsModel(MapObjectList *list, void *model) {
    s32 index;
    s32 count = list->mMapObjectCount;

    for (index = 0; index < count; index++) {
        Unk020e3ef4 *mapObject = list->mMapObjects[index];

        mapObject->mModel = model;
    }
}

s32 ComputeSphereHitOnCollisionData(Unk020e1d10 *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange) {
    switch (object->mCollisionData.mUnk_134) {
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
                            u16 *outFlags, s32 axisFlag, Unk020e1d10 *object, Vec3 *sphereCenter, Vec3 *normal,
                            CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset,
                            Vec3 *pointMotion, u16 *angleChange) {
    BOOL normalAboveThreshold;
    s32 signedNormalY;
    CollisionHitRecord *chosenHitRecord;
    u16 hitFlags;
    Vec3 u;

    normalAboveThreshold = FALSE;
    if (axisFlag != 0) {
        if (regionFlags & positiveSideBit) {
            signedNormalY = normal->y;
        } else {
            signedNormalY = -normal->y;
        }
        if (signedNormalY > object->mCollisionData.mUnk_120) {
            normalAboveThreshold = TRUE;
        }
    }
    u.x = normal->x << 10;
    u.y = normal->y << 10;
    u.z = normal->z << 10;
    u.x = ((s64) u.x * signedDepth) >> 12;
    u.y = ((s64) u.y * signedDepth) >> 12;
    u.z = ((s64) u.z * signedDepth) >> 12;
    if (normalAboveThreshold) {
        hitFlags = object->mCollisionData.mUnk_114.z != 0 && (regionFlags & 8) ? 0x12 : 0;
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
    if (u.x > chosenHitRecord->mMaxOffset.x) {
        chosenHitRecord->mMaxOffset.x = u.x;
    } else if (u.x < chosenHitRecord->mMinOffset.x) {
        chosenHitRecord->mMinOffset.x = u.x;
    }
    if (u.y > chosenHitRecord->mMaxOffset.y) {
        chosenHitRecord->mMaxOffset.y = u.y;
    } else if (u.y < chosenHitRecord->mMinOffset.y) {
        chosenHitRecord->mMinOffset.y = u.y;
    }
    if (u.z > chosenHitRecord->mMaxOffset.z) {
        chosenHitRecord->mMaxOffset.z = u.z;
    } else if (u.z < chosenHitRecord->mMinOffset.z) {
        chosenHitRecord->mMinOffset.z = u.z;
    }
    if (lowestOffset != NULL) {
        if (regionFlags & positiveSideBit) {
            s32 axisFlag = -(sphereRadius - depth);

            u.x = ((s64) normal->x * axisFlag) >> 12;
            u.y = ((s64) normal->y * axisFlag) >> 12;
            u.z = ((s64) normal->z * axisFlag) >> 12;
        } else {
            s32 negatedGap = sphereRadius - depth;

            u.x = ((s64) normal->x * negatedGap) >> 12;
            u.y = ((s64) normal->y * negatedGap) >> 12;
            u.z = ((s64) normal->z * negatedGap) >> 12;
        }
        if (u.y < lowestOffset->y) {
            *lowestOffset = u;
        }
    }
    if (!normalAboveThreshold) {
        return;
    }
    ComputeCollisionPointMotion(object, sphereCenter, normal, pointMotion, angleChange);
}

BOOL AddCollisionHitTwoAxes(s32 sphereRadius, s32 firstOffset, s32 c, u32 regionFlags, u16 firstPositiveSideBit,
                            u16 secondPositiveSideBit, u16 *outFlags, u16 queryFlags, s32 firstAxisFlag,
                            s32 secondAxisFlag, Unk020e1d10 *object, Vec3 *sphereCenter, Vec3 *firstNormal,
                            Vec3 *secondNormal, CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                            Vec3 *lowestOffset, Vec3 *pointMotion, u16 *angleChange) {
    BOOL normalAboveThreshold;
    BOOL eitherAxisQualifies;
    BOOL axisQualifies;
    s32 t;
    CollisionHitRecord *chosenHitRecord;
    Vec3 y;
    Vec3 z;
    Vec3 tmp;

    normalAboveThreshold = FALSE;
    if ((queryFlags & 0x60) == 0) {
        eitherAxisQualifies = TRUE;
        axisQualifies = FALSE;
        if (firstAxisFlag != 0) {
            t = (regionFlags & firstPositiveSideBit) ? firstNormal->y : -firstNormal->y;
            if (t > object->mCollisionData.mUnk_120) {
                axisQualifies = TRUE;
            }
        }
        if (axisQualifies == FALSE) {
            axisQualifies = FALSE;
            if (secondAxisFlag != 0) {
                t = (regionFlags & secondPositiveSideBit) ? secondNormal->y : -secondNormal->y;
                if (t > object->mCollisionData.mUnk_120) {
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
    y.x = ((s64) firstNormal->x * firstOffset) >> 12;
    y.y = ((s64) firstNormal->y * firstOffset) >> 12;
    y.z = ((s64) firstNormal->z * firstOffset) >> 12;
    z.x = ((s64) secondNormal->x * c) >> 12;
    z.y = ((s64) secondNormal->y * c) >> 12;
    z.z = ((s64) secondNormal->z * c) >> 12;
    VEC_Add(&y, &z, &y);
    y.x <<= 10;
    y.y <<= 10;
    y.z <<= 10;
    t = Vec3NormalizeAndGetLengthOrZero(&y, &tmp);
    if (t > (sphereRadius << 10)) {
        return FALSE;
    }
    if (t != 0) {
        z.x = ((s64) tmp.x * sphereRadius) >> 12;
        z.y = ((s64) tmp.y * sphereRadius) >> 12;
        z.z = ((s64) tmp.z * sphereRadius) >> 12;
        y.x >>= 10;
        y.y >>= 10;
        y.z >>= 10;
        VEC_Subtract(&z, &y, &z);
        c = VEC_Mag(&z);
    } else {
        tmp = *secondNormal;
        z.x = ((s64) tmp.x * sphereRadius) >> 12;
        z.y = ((s64) tmp.y * sphereRadius) >> 12;
        z.z = ((s64) tmp.z * sphereRadius) >> 12;
        c = sphereRadius;
    }
    if (normalAboveThreshold) {
        if (object->mCollisionData.mUnk_114.z != 0 && (regionFlags & 8)) {
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
    if (c >= chosenHitRecord->mDeepestDepth) {
        chosenHitRecord->mDeepestDepth = c;
        chosenHitRecord->mDeepestNormal = tmp;
    }
    z.x <<= 10;
    z.y <<= 10;
    z.z <<= 10;
    if (z.x > chosenHitRecord->mMaxOffset.x) {
        chosenHitRecord->mMaxOffset.x = z.x;
    } else if (z.x < chosenHitRecord->mMinOffset.x) {
        chosenHitRecord->mMinOffset.x = z.x;
    }
    if (z.y > chosenHitRecord->mMaxOffset.y) {
        chosenHitRecord->mMaxOffset.y = z.y;
    } else if (z.y < chosenHitRecord->mMinOffset.y) {
        chosenHitRecord->mMinOffset.y = z.y;
    }
    if (z.z > chosenHitRecord->mMaxOffset.z) {
        chosenHitRecord->mMaxOffset.z = z.z;
    } else if (z.z < chosenHitRecord->mMinOffset.z) {
        chosenHitRecord->mMinOffset.z = z.z;
    }
    if (lowestOffset != NULL) {
        y.x = -y.x;
        y.y = -y.y;
        y.z = -y.z;
        if (y.y < lowestOffset->y) {
            *lowestOffset = y;
        }
    }
    if (normalAboveThreshold) {
        ComputeCollisionPointMotion(object, sphereCenter, &tmp, pointMotion, angleChange);
    }
    return TRUE;
}

BOOL ComputeSphereHitOnCollisionBox(Unk020e1d10 *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange) {
    Vec3 v;
    Vec3 w;
    Vec3 tmp;
    CollisionHitRecord *chosenHitRecord;
    u16 regionFlags;
    s32 f6;
    s32 f5;
    s32 f4;
    s32 signedDepthAxis0;
    s32 k5;
    s32 depthAxis0;
    s32 depthAxis1;
    s32 depthAxis2;
    BOOL normalAboveThreshold;
    BOOL anyAxisQualifies;
    BOOL axisQualifies;
    BOOL firstTwoQualify;
    s32 t;

    regionFlags = 0;
    VEC_Subtract(sphereCenter, &object->mCollisionData.mCenterPos, &v);
    f6 = Vec3DotUnrounded(&v, &object->mMapObject.mMatrix.mUnk_00[0]);
    if (f6 > 0) {
        if (f6 > object->mCollisionData.mUnk_100 + sphereRadius) {
            return FALSE;
        }
        if (f6 > object->mCollisionData.mUnk_100) {
            regionFlags |= 0xa00;
        } else {
            regionFlags |= 0x900;
        }
    } else {
        if (f6 < -(object->mCollisionData.mUnk_100 + sphereRadius)) {
            return FALSE;
        }
        if (f6 < -object->mCollisionData.mUnk_100) {
            regionFlags |= 0x600;
        } else {
            regionFlags |= 0x500;
        }
    }
    f5 = Vec3DotUnrounded(&v, &object->mMapObject.mMatrix.mUnk_00[1]);
    if (f5 > 0) {
        if (f5 > object->mCollisionData.mHalfSizeY + sphereRadius) {
            return FALSE;
        }
        if (f5 > object->mCollisionData.mHalfSizeY) {
            regionFlags |= 0xa0;
        } else {
            regionFlags |= 0x90;
        }
    } else {
        if (f5 < -(object->mCollisionData.mHalfSizeY + sphereRadius)) {
            return FALSE;
        }
        if (f5 < -object->mCollisionData.mHalfSizeY) {
            regionFlags |= 0x60;
        } else {
            regionFlags |= 0x50;
        }
    }
    f4 = Vec3DotUnrounded(&v, &object->mMapObject.mMatrix.mUnk_00[2]);
    if (f4 > 0) {
        if (f4 > object->mCollisionData.mPositiveHalfSizeZ + sphereRadius) {
            return FALSE;
        }
        if (f4 > object->mCollisionData.mPositiveHalfSizeZ) {
            regionFlags |= 0xa;
        } else {
            regionFlags |= 0x9;
        }
    } else {
        if (f4 < -(object->mCollisionData.mNegativeHalfSizeZ + sphereRadius)) {
            return FALSE;
        }
        if (f4 < -object->mCollisionData.mNegativeHalfSizeZ) {
            regionFlags |= 0x6;
        } else {
            regionFlags |= 0x5;
        }
    }
    if ((queryFlags & 4) && object->mUnk_13c != 0) {
        return FALSE;
    }
    if (regionFlags & 0x100) {
        if (regionFlags & 0x10) {
            if (regionFlags & 0x8) {
                f4 = (object->mCollisionData.mPositiveHalfSizeZ + sphereRadius) - f4;
            } else {
                f4 = -(object->mCollisionData.mNegativeHalfSizeZ + sphereRadius) - f4;
            }
            if (regionFlags & 0x1) {
                if (regionFlags & 0x800) {
                    signedDepthAxis0 = (object->mCollisionData.mUnk_100 + sphereRadius) - f6;
                } else {
                    signedDepthAxis0 = -(object->mCollisionData.mUnk_100 + sphereRadius) - f6;
                }
                if (regionFlags & 0x80) {
                    k5 = (object->mCollisionData.mHalfSizeY + sphereRadius) - f5;
                } else {
                    k5 = -(object->mCollisionData.mHalfSizeY + sphereRadius) - f5;
                }
                depthAxis0 = signedDepthAxis0 > 0 ? signedDepthAxis0 : -signedDepthAxis0;
                depthAxis1 = k5 > 0 ? k5 : -k5;
                depthAxis2 = f4 > 0 ? f4 : -f4;
                goto smallest;
            }
            depthAxis2 = f4 > 0 ? f4 : -f4;
            goto call_8;
        }
        if (regionFlags & 0x80) {
            k5 = (object->mCollisionData.mHalfSizeY + sphereRadius) - f5;
        } else {
            k5 = -(object->mCollisionData.mHalfSizeY + sphereRadius) - f5;
        }
        if (!(regionFlags & 0x1)) {
            goto call_80_8;
        }
        depthAxis1 = k5 > 0 ? k5 : -k5;
        goto call_80;
    }
    if (regionFlags & 0x800) {
        signedDepthAxis0 = (object->mCollisionData.mUnk_100 + sphereRadius) - f6;
    } else {
        signedDepthAxis0 = -(object->mCollisionData.mUnk_100 + sphereRadius) - f6;
    }
    if (regionFlags & 0x10) {
        if (!(regionFlags & 0x1)) {
            goto call_8_800;
        }
        depthAxis0 = signedDepthAxis0 > 0 ? signedDepthAxis0 : -signedDepthAxis0;
    } else {
        if (!(regionFlags & 0x1)) {
            goto rest;
        }
        goto call_800_80;
    }
call_800:
    AddCollisionHitOneAxis(sphereRadius, signedDepthAxis0, depthAxis0, regionFlags, 0x800, outFlags,
                           object->mCollisionData.mUnk_110, object, sphereCenter,
                           &object->mMapObject.mMatrix.mUnk_00[0], firstHitRecord, secondHitRecord, lowestOffset,
                           pointMotion, angleChange);
    return TRUE;
call_80:
    AddCollisionHitOneAxis(sphereRadius, k5, depthAxis1, regionFlags, 0x80, outFlags, object->mCollisionData.mUnk_114.x,
                           object, sphereCenter, &object->mMapObject.mMatrix.mUnk_00[1], firstHitRecord,
                           secondHitRecord, lowestOffset, pointMotion, angleChange);
    return TRUE;
call_8:
    AddCollisionHitOneAxis(sphereRadius, f4, depthAxis2, regionFlags, 8, outFlags, object->mCollisionData.mUnk_114.y,
                           object, sphereCenter, &object->mMapObject.mMatrix.mUnk_00[2], firstHitRecord,
                           secondHitRecord, lowestOffset, pointMotion, angleChange);
    return TRUE;
smallest:
    if (depthAxis0 < depthAxis2) {
        if (depthAxis0 < depthAxis1) {
            goto call_800;
        }
        goto call_80;
    }
    if (depthAxis2 < depthAxis1) {
        goto call_8;
    }
    goto call_80;
call_800_80:
    if (regionFlags & 0x800) {
        f6 = f6 - object->mCollisionData.mUnk_100;
    } else {
        f6 = f6 + object->mCollisionData.mUnk_100;
    }
    if (regionFlags & 0x80) {
        f5 = f5 - object->mCollisionData.mHalfSizeY;
    } else {
        f5 = f5 + object->mCollisionData.mHalfSizeY;
    }
    return AddCollisionHitTwoAxes(sphereRadius, f6, f5, regionFlags, 0x800, 0x80, outFlags, queryFlags,
                                  object->mCollisionData.mUnk_110, object->mCollisionData.mUnk_114.x, object,
                                  sphereCenter, &object->mMapObject.mMatrix.mUnk_00[0],
                                  &object->mMapObject.mMatrix.mUnk_00[1], firstHitRecord, secondHitRecord, lowestOffset,
                                  pointMotion, angleChange);
call_80_8:
    if (regionFlags & 0x80) {
        f5 = f5 - object->mCollisionData.mHalfSizeY;
    } else {
        f5 = f5 + object->mCollisionData.mHalfSizeY;
    }
    if (regionFlags & 0x8) {
        f4 = f4 - object->mCollisionData.mPositiveHalfSizeZ;
    } else {
        f4 = f4 + object->mCollisionData.mNegativeHalfSizeZ;
    }
    return AddCollisionHitTwoAxes(sphereRadius, f5, f4, regionFlags, 0x80, 0x8, outFlags, queryFlags,
                                  object->mCollisionData.mUnk_114.x, object->mCollisionData.mUnk_114.y, object,
                                  sphereCenter, &object->mMapObject.mMatrix.mUnk_00[1],
                                  &object->mMapObject.mMatrix.mUnk_00[2], firstHitRecord, secondHitRecord, lowestOffset,
                                  pointMotion, angleChange);
call_8_800:
    if (regionFlags & 0x8) {
        f4 = f4 - object->mCollisionData.mPositiveHalfSizeZ;
    } else {
        f4 = f4 + object->mCollisionData.mNegativeHalfSizeZ;
    }
    if (regionFlags & 0x800) {
        f6 = f6 - object->mCollisionData.mUnk_100;
    } else {
        f6 = f6 + object->mCollisionData.mUnk_100;
    }
    return AddCollisionHitTwoAxes(sphereRadius, f4, f6, regionFlags, 8, 0x800, outFlags, queryFlags,
                                  object->mCollisionData.mUnk_114.y, object->mCollisionData.mUnk_110, object,
                                  sphereCenter, &object->mMapObject.mMatrix.mUnk_00[2],
                                  &object->mMapObject.mMatrix.mUnk_00[0], firstHitRecord, secondHitRecord, lowestOffset,
                                  pointMotion, angleChange);
rest:
    normalAboveThreshold = FALSE;
    if ((queryFlags & 0x60) == 0) {
        anyAxisQualifies = TRUE;
        firstTwoQualify = TRUE;
        axisQualifies = FALSE;
        if (object->mCollisionData.mUnk_110 != 0) {
            t = (regionFlags & 0x800) ? object->mMapObject.mMatrix.mUnk_00[0].y
                                      : -object->mMapObject.mMatrix.mUnk_00[0].y;
            if (t > object->mCollisionData.mUnk_120) {
                axisQualifies = TRUE;
            }
        }
        if (axisQualifies == FALSE) {
            axisQualifies = FALSE;
            if (object->mCollisionData.mUnk_114.x != 0) {
                t = (regionFlags & 0x80) ? object->mMapObject.mMatrix.mUnk_00[1].y
                                         : -object->mMapObject.mMatrix.mUnk_00[1].y;
                if (t > object->mCollisionData.mUnk_120) {
                    axisQualifies = TRUE;
                }
            }
            if (axisQualifies == FALSE) {
                firstTwoQualify = FALSE;
            }
        }
        if (firstTwoQualify == FALSE) {
            k5 = 0;
            if (object->mCollisionData.mUnk_114.y != 0) {
                t = (regionFlags & 0x8) ? object->mMapObject.mMatrix.mUnk_00[2].y
                                        : -object->mMapObject.mMatrix.mUnk_00[2].y;
                if (t > object->mCollisionData.mUnk_120) {
                    k5 = 1;
                }
            }
            if (k5 == 0) {
                anyAxisQualifies = FALSE;
            }
        }
        if (anyAxisQualifies != FALSE) {
            normalAboveThreshold = TRUE;
        }
    }
    if (regionFlags & 0x800) {
        f6 = f6 - object->mCollisionData.mUnk_100;
    } else {
        f6 = f6 + object->mCollisionData.mUnk_100;
    }
    if (regionFlags & 0x80) {
        f5 = f5 - object->mCollisionData.mHalfSizeY;
    } else {
        f5 = f5 + object->mCollisionData.mHalfSizeY;
    }
    if (regionFlags & 0x8) {
        f4 = f4 - object->mCollisionData.mPositiveHalfSizeZ;
    } else {
        f4 = f4 + object->mCollisionData.mNegativeHalfSizeZ;
    }
    v.x = ((s64) object->mMapObject.mMatrix.mUnk_00[0].x * f6) >> 12;
    v.y = ((s64) object->mMapObject.mMatrix.mUnk_00[0].y * f6) >> 12;
    v.z = ((s64) object->mMapObject.mMatrix.mUnk_00[0].z * f6) >> 12;
    w.x = ((s64) object->mMapObject.mMatrix.mUnk_00[1].x * f5) >> 12;
    w.y = ((s64) object->mMapObject.mMatrix.mUnk_00[1].y * f5) >> 12;
    w.z = ((s64) object->mMapObject.mMatrix.mUnk_00[1].z * f5) >> 12;
    VEC_Add(&w, &v, &v);
    w.x = ((s64) object->mMapObject.mMatrix.mUnk_00[2].x * f4) >> 12;
    w.y = ((s64) object->mMapObject.mMatrix.mUnk_00[2].y * f4) >> 12;
    w.z = ((s64) object->mMapObject.mMatrix.mUnk_00[2].z * f4) >> 12;
    VEC_Add(&w, &v, &v);
    v.x <<= 10;
    v.y <<= 10;
    v.z <<= 10;
    t = Vec3NormalizeAndGetLengthOrZero(&v, &w);
    if (t > (sphereRadius << 10)) {
        return FALSE;
    }
    if (t != 0) {
        tmp.x = ((s64) w.x * sphereRadius) >> 12;
        tmp.y = ((s64) w.y * sphereRadius) >> 12;
        tmp.z = ((s64) w.z * sphereRadius) >> 12;
        v.x >>= 10;
        v.y >>= 10;
        v.z >>= 10;
        VEC_Subtract(&tmp, &v, &tmp);
        sphereRadius = VEC_Mag(&tmp);
    } else {
        w = object->mMapObject.mMatrix.mUnk_00[1];
        tmp.x = ((s64) w.x * sphereRadius) >> 12;
        tmp.y = ((s64) w.y * sphereRadius) >> 12;
        tmp.z = ((s64) w.z * sphereRadius) >> 12;
    }
    if (normalAboveThreshold) {
        if (object->mCollisionData.mUnk_114.z != 0 && (regionFlags & 0x8)) {
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
        chosenHitRecord->mDeepestNormal = w;
    }
    tmp.x <<= 10;
    tmp.y <<= 10;
    tmp.z <<= 10;
    if (tmp.x > chosenHitRecord->mMaxOffset.x) {
        chosenHitRecord->mMaxOffset.x = tmp.x;
    } else if (tmp.x < chosenHitRecord->mMinOffset.x) {
        chosenHitRecord->mMinOffset.x = tmp.x;
    }
    if (tmp.y > chosenHitRecord->mMaxOffset.y) {
        chosenHitRecord->mMaxOffset.y = tmp.y;
    } else if (tmp.y < chosenHitRecord->mMinOffset.y) {
        chosenHitRecord->mMinOffset.y = tmp.y;
    }
    if (tmp.z > chosenHitRecord->mMaxOffset.z) {
        chosenHitRecord->mMaxOffset.z = tmp.z;
    } else if (tmp.z < chosenHitRecord->mMinOffset.z) {
        chosenHitRecord->mMinOffset.z = tmp.z;
    }
    if (lowestOffset != NULL) {
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
        if (v.y < lowestOffset->y) {
            *lowestOffset = v;
        }
    }
    if (normalAboveThreshold) {
        ComputeCollisionPointMotion(object, sphereCenter, &w, pointMotion, angleChange);
    }
    return TRUE;
}

BOOL ComputeSphereHitOnCollisionCylinder(Unk020e1d10 *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                         CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                         Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange) {
    Vec3 v;
    s32 axialDepth;
    Vec3 w;
    s32 combinedRadius;
    s32 radialOverlap;
    s64 squaredRadialDistance;
    u16 regionFlags;
    s32 x;
    s32 alongAxis2;
    s32 n;

    regionFlags = 0;
    VEC_Subtract(sphereCenter, &object->mCollisionData.mCenterPos, &v);
    x = Vec3DotUnrounded(&v, &object->mMapObject.mMatrix.mUnk_00[0]);
    alongAxis2 = Vec3DotUnrounded(&v, &object->mMapObject.mMatrix.mUnk_00[2]);
    squaredRadialDistance = (s64) x * x + (s64) alongAxis2 * alongAxis2;
    combinedRadius = object->mCollisionData.mUnk_100 + sphereRadius;
    if ((s64) combinedRadius * combinedRadius < squaredRadialDistance) {
        return FALSE;
    }
    if ((s64) object->mCollisionData.mUnk_100 * object->mCollisionData.mUnk_100 < squaredRadialDistance) {
        regionFlags |= data_021588e8;
    } else {
        regionFlags |= data_021588ec;
    }
    n = Vec3DotUnrounded(&v, &object->mMapObject.mMatrix.mUnk_00[1]);
    if (n > 0) {
        if (n > object->mCollisionData.mHalfSizeY + sphereRadius) {
            return FALSE;
        }
        if (n > object->mCollisionData.mHalfSizeY) {
            regionFlags |= 0xa0;
        } else {
            regionFlags |= 0x90;
        }
    } else {
        if (n < -(object->mCollisionData.mHalfSizeY + sphereRadius)) {
            return FALSE;
        }
        if (n < -object->mCollisionData.mHalfSizeY) {
            regionFlags |= 0x60;
        } else {
            regionFlags |= 0x50;
        }
    }
    if (regionFlags & 0x1000) {
        if (regionFlags & 0x80) {
            n = object->mCollisionData.mHalfSizeY + sphereRadius - n;
        } else {
            n = -(object->mCollisionData.mHalfSizeY + sphereRadius) - n;
        }
        if (n > 0) {
            axialDepth = n;
        } else {
            axialDepth = -n;
        }
        if (!(regionFlags & 0x10)) {
            goto apply80;
        }
        v.x = x;
        v.y = 0;
        v.z = alongAxis2;
        x = Vec3NormalizeXZAndGetLengthOrZero(&v, &v);
        radialOverlap = combinedRadius - x;
        if (x == 0) {
            w = data_021588f0;
        } else {
            w.x = ((s64) object->mMapObject.mMatrix.mUnk_00[0].x * v.x) >> 12;
            w.y = ((s64) object->mMapObject.mMatrix.mUnk_00[0].y * v.x) >> 12;
            w.z = ((s64) object->mMapObject.mMatrix.mUnk_00[0].z * v.x) >> 12;
            VEC_MultAdd(v.z, &object->mMapObject.mMatrix.mUnk_00[2], &w, &w);
        }
        goto cmp;
    }
    v.x = x;
    v.y = 0;
    v.z = alongAxis2;
    x = Vec3NormalizeXZAndGetLengthOrZero(&v, &v);
    radialOverlap = combinedRadius - x;
    if (x == 0) {
        w = data_021588fc;
    } else {
        w.x = ((s64) object->mMapObject.mMatrix.mUnk_00[0].x * v.x) >> 12;
        w.y = ((s64) object->mMapObject.mMatrix.mUnk_00[0].y * v.x) >> 12;
        w.z = ((s64) object->mMapObject.mMatrix.mUnk_00[0].z * v.x) >> 12;
        VEC_MultAdd(v.z, &object->mMapObject.mMatrix.mUnk_00[2], &w, &w);
    }
    if (regionFlags & 0x10) {
        goto apply3000;
    }
    goto tail;
apply80:
    AddCollisionHitOneAxis(sphereRadius, n, axialDepth, regionFlags, 0x80, outFlags, object->mCollisionData.mUnk_114.x,
                           object, sphereCenter, &object->mMapObject.mMatrix.mUnk_00[1], firstHitRecord,
                           secondHitRecord, lowestOffset, pointMotion, angleChange);
    return TRUE;
apply3000:
    AddCollisionHitOneAxis(sphereRadius, radialOverlap, x, regionFlags, 0x3000, outFlags,
                           object->mCollisionData.mUnk_110, object, sphereCenter, &w, firstHitRecord, secondHitRecord,
                           lowestOffset, pointMotion, angleChange);
    return TRUE;
tail:
    x = x - object->mCollisionData.mUnk_100;
    if (regionFlags & 0x80) {
        n = n - object->mCollisionData.mHalfSizeY;
    } else {
        n = n + object->mCollisionData.mHalfSizeY;
    }
    return AddCollisionHitTwoAxes(sphereRadius, x, n, regionFlags, 0x3000, 0x80, outFlags, queryFlags,
                                  object->mCollisionData.mUnk_110, object->mCollisionData.mUnk_114.x, object,
                                  sphereCenter, &w, &object->mMapObject.mMatrix.mUnk_00[1], firstHitRecord,
                                  secondHitRecord, lowestOffset, pointMotion, angleChange);
cmp:
    if (radialOverlap < axialDepth) {
        goto apply3000;
    }
    goto apply80;
}

void ComputeCollisionPointMotion(Unk020e1d10 *object, Vec3 *position, Vec3 *contactNormal, Vec3 *pointMotion,
                                 u16 *angleChange) {
    Vec3 offset;

    if (pointMotion != NULL) {
        pointMotion->x = -object->mMapObject.mUnk_10.x;
        pointMotion->y = -object->mMapObject.mUnk_10.y;
        pointMotion->z = -object->mMapObject.mUnk_10.z;
        VEC_Subtract(position, &object->mMapObject.mPos, &offset);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mUnk_00[0]),
                    &object->mCollisionData.mPrevMatrix.mUnk_00[0], pointMotion, pointMotion);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mUnk_00[1]),
                    &object->mCollisionData.mPrevMatrix.mUnk_00[1], pointMotion, pointMotion);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mUnk_00[2]),
                    &object->mCollisionData.mPrevMatrix.mUnk_00[2], pointMotion, pointMotion);
        VEC_Subtract(&offset, pointMotion, pointMotion);
    }
    if (angleChange != NULL) {
        *angleChange = Vec3DotUnrounded(&object->mCollisionData.mAngleChangeVector, contactNormal);
    }
}
