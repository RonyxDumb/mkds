#include "Main/Unknown/code_020e0680.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/code_020f9c6c.h"
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

void choro_init(Unk020e1e98 *choropu, struct CourseMapRow *courseRow) {
    sm_init(&choropu->field0.mStateMachine, (UnkFunc *const *) choro_sStates, 8, choropu);
    choropu->fieldA8 = choropu->field0.mPos.y;
    choropu->fieldAC = choropu->field0.mPos.y - 0x12000;
    choropu->fieldB0 = choropu->field0.mPos.y - 0x18000;
    choropu->fieldA4 = courseRow->field28;
    choropu->fieldA0 = courseRow->field2A;
    choropu->field0.mStateMachine.mNextState = 0;
    choropu->field0.mStateMachine.mNextStateRequested = 1;
    oshd_setParams(&choropu->fieldB4.field8, &choropu->field0.mPos,
                        ((s64) choropu->field0.mScale.x * 0x1b000) >> 12, 0x1e);
    choropu->field0.mFlags |= data_02158b7c;
}

#pragma thumb off

void *traf_setupCarCollision(void) {
    Unk020e03f8 *kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);

    *kindData = data_02158b3c;
    return kindData;
}

void *traf_setupTruckCollision(void) {
    Unk020e03f8 *kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);

    *kindData = data_02158afc;
    return kindData;
}

void *traf_setupBusCollision(void) {
    Unk020e03f8 *kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);

    *kindData = data_02158abc;
    return kindData;
}

void *traf_setupRenderPart(void) {
    Unk020e03f8 *drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);

    data_0217b79c = (Unk0217b79c *) drawList;
    *drawList = data_02158a7c;
    mobj_renderPartSetThisPointer(&data_0217b79c);
    return data_0217b79c;
}

void *traf_setupLogicPart(void) {
    Unk020e0340 *updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);

    data_0217b7a4 = updateList;
    *updateList = data_02158a54;
    mobj_logicPartSetThisPointer(&data_0217b7a4);
    return data_0217b7a4;
}

void traf_globalPreRender(Unk020e20a8 *drawList) {
    u16 entryIndex;

    entryIndex = gRaceMultiConfig->mEntryIndex;
    if (drawList->field38 == FALSE) {
        return;
    }
    if (entryIndex < 8) {
        GetItemPointLinkDirection((u32) it_sDriverItemStatus[entryIndex].field1F0.mLink, (u32) &drawList->field2C);
        drawList->field3C = vec_dotProduct(&drawList->field2C, bbm_getBillboardForwardVec()) < 0;
    } else {
        drawList->field3C = FALSE;
    }
}

void traf_render(Unk020e20a8 *drawList, Unk020e1e98 *vehicle, u32 c, u32 alpha) {
    u32 f;
    s32 dotAxis2;
    s16 v;
    s16 w;
    Vec3 *shadowPosition;
    const s16 *anglePairs;
    Unk020e1e98_12c *animation;
    s32 tireMatrix[12];
    s32 one;
    u32 angleIndex;
    s32 x;
    s32 y;

    if (drawList->field3C != FALSE) {
        dotAxis2 = vec_dotProduct(&vehicle->field0.mMatrix.field0[2], &drawList->field2C);
        v = vehicle->field0.mCourseMapRow->field2E;
        w = vehicle->fieldD8.mFromEntry->field12;
        if (v == 0) {
            dotAxis2 = -dotAxis2;
        }
        if (dotAxis2 > w) {
            return;
        }
    }
    f = (s32) (vehicle->field0.mDistanceSquaredAndFlags & 0x3FFFFFE0) > 0x77A10 && rstat_getUncontrollable() == 0;
    if (!f) {
        if (vehicle->field128 != 0) {
            shadowPosition = vehicle->fieldFE > 0xF ? &vehicle->field144 : &vehicle->field0.mPos;
            vehicle->field0.mMatrix.field0[3].x = shadowPosition->x >> 4;
            vehicle->field0.mMatrix.field0[3].y = shadowPosition->y >> 4;
            vehicle->field0.mMatrix.field0[3].z = shadowPosition->z >> 4;
            model2_renderShadowModel((void *) vehicle->field128, &vehicle->field0.mMatrix, &vehicle->field0.mScale,
                                   alpha);
        }
    }
    vehicle->field0.mMatrix.field0[3].x = vehicle->field0.mPos.x >> 4;
    vehicle->field0.mMatrix.field0[3].y = vehicle->field0.mPos.y >> 4;
    vehicle->field0.mMatrix.field0[3].z = vehicle->field0.mPos.z >> 4;
    animation = vehicle->field12C;
    if (animation != NULL) {
        animation->fieldC = vehicle->field130 << 12;
        *animation->field1C[animation->field1A] = animation->fieldC;
    }
    light_apply(&vehicle->field132);
    model2_renderModel((void *) vehicle->field124, &vehicle->field0.mMatrix, &vehicle->field0.mScale,
                                   alpha);
    if (f) {
        return;
    }
    angleIndex = vehicle->field10C >> 4;
    anglePairs = FX_SinCosTable_;
    x = ((s64) vehicle->field110 * anglePairs[angleIndex * 2] + 0x800) >> 12;
    y = ((s64) vehicle->field110 * anglePairs[angleIndex * 2 + 1] + 0x800) >> 12;
    MTX_RotX43_(tireMatrix, x, y);
    tireMatrix[0] = vehicle->field100[0];
    tireMatrix[10] = vehicle->field100[1];
    tireMatrix[11] = vehicle->field100[2];
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x19, tireMatrix, 0xc);
    model_render(traf_sCarTireModel);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    tireMatrix[11] = -tireMatrix[11];
    NNS_G3dGeBufferOP_N(0x19, tireMatrix, 0xc);
    model_render(traf_sCarTireModel);
}

static inline s64 func_020e2630_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

static inline s16 func_020e2630_inline2(Unk020e1e98 *b) {
    return b->fieldFE;
}

void traf_update(u32 a, Unk020e1e98 *vehicle) {
    enum { K0 } f;
    void *baseRotation;
    u32 hitFlags;
    Unk020e1e98_0b4 targetRotation;
    Vec3 previousPosition;
    s32 out[3];
    Vec3 u;
    Vec3 testPosition;

    if (vehicle->fieldFE > 0xf) {
        f = 1;
        f = (s32) f;
    } else {
        f = 0;
    }
    previousPosition = vehicle->field0.mPos;
    pw_update(&vehicle->fieldD8);
    if (!f) {
        pw_calcCurrentPointXZLinearY(&vehicle->fieldD8, &vehicle->field0.mPos);
        VEC_Subtract(&vehicle->field0.mPos, &previousPosition, &vehicle->field0.field10);
    } else {
        pw_calcCurrentPointXZLinearY(&vehicle->fieldD8, &vehicle->field144);
        vehicle->field0.mPos.x = vehicle->field144.x;
        vehicle->field0.field10.y -= 0x59a;
        vehicle->field0.mPos.y = vehicle->field0.mPos.y + vehicle->field0.field10.y;
        vehicle->field0.mPos.z = vehicle->field144.z;
        vehicle->field0.field10.x = vehicle->field0.mPos.x - previousPosition.x;
        vehicle->field0.field10.z = vehicle->field0.mPos.z - previousPosition.z;
    }
    if (f || (vehicle->fieldD4 & 7) == race_getFrameCounterModulo8()) {
        testPosition.x = vehicle->field0.mPos.x;
        testPosition.y = vehicle->field0.mPos.y + (f ? 0xf000 : 0);
        testPosition.z = vehicle->field0.mPos.z;
        u = testPosition;
        if (col_collide(&u, NULL, 0, 0xf000, 8, -2, out, &u, NULL, &hitFlags, NULL, NULL, NULL, NULL) != 0) {
            if (hitFlags & 0x1e34ef) {
                qrtn_fromForwardVec(&u, &vehicle->fieldB4);
                light_interpolateToKclColor(&vehicle->field132, (hitFlags & 0x3c000000) >> 26, 0x5000);
                if (vehicle->fieldFE != 0 && vehicle->field0.field10.y < 0) {
                    if (vehicle->field0.mFlags & 1) {
                        vehicle->field0.mFlags &= ~1;
                        vehicle->field0.field10.y = -(s32) (((s64) vehicle->field0.field10.y *
                                                               (0x733 + ((vehicle->field114.y - 0x14000) >> 9))) >>
                                                              12);
                        vehicle->fieldC4 = -vehicle->fieldC4;
                        vehicle->fieldC8 = -vehicle->fieldC8;
                        vehicle->fieldCC = -vehicle->fieldCC;
                        qrtn_slerp(&vehicle->fieldC4, &vehicle->fieldB4, &vehicle->fieldC4,
                                                        0x8cd);
                        vehicle->field152 = 0x320;
                        mobj_emitSfxFromEmitter2(&vehicle->field0, vehicle->field160);
                    } else if (f && vehicle != NULL) {
                        vehicle->fieldFE = 0xf;
                        vehicle->field0.field10.y = 0;
                        vehicle->field152 = 0x258;
                    }
                }
            }
            if ((hitFlags & 0x214300) && f) {
                vehicle->field0.mPos.y = vehicle->field0.mPos.y + out[1];
                vehicle->field0.field10.y = 0;
            }
        }
    }
    switch (f) {
        default:
            if (vehicle->field0.field10.y < 0) {
                vehicle->field152 = ((s64) (-vehicle->field0.field10.y) * 0xc) >> 12;
                baseRotation = &vehicle->fieldB4;
            } else {
                baseRotation = &vehicle->fieldC4;
            }
            break;

        case 0:
            if (func_020e2630_inline2(vehicle) != 0) {
                vehicle->fieldFE--;
                if (vehicle->fieldFE == 0) {
                    vehicle->field152 = vehicle->field150;
                } else {
                    baseRotation = &vehicle->fieldB4;
                }
            }
            break;
    }

    if (func_020e2630_inline(&vehicle->field0.field10) < 0x10) {
        targetRotation = vehicle->fieldB4;
    } else {
        vehicle->field0.mAngle =
            (s16) (((s64) FX_Atan2(vehicle->field0.field10.x, vehicle->field0.field10.z) * 0x28BE60DB9391 +
                    0x80000000000) >>
                   44);
        if (vehicle->fieldFE == 0) {
            baseRotation = &vehicle->fieldB4;
        }
        func_020d79b0(baseRotation, vehicle->field0.mAngle, &targetRotation);
    }
    qrtn_slerp(&vehicle->fieldA4, &targetRotation, &vehicle->fieldA4, vehicle->field152);
    qtrn_toMtx33(&vehicle->field0.mMatrix.field0[0].x, &vehicle->fieldA4);
    vehicle->field10C += 0x600;
    if (vehicle->field0.mDistanceSquaredAndFlags & 8) {
        AdvanceSoundDistanceSquaredChange(vehicle->field158, vehicle->field0.mDistanceSquaredAndFlags & 0x3FFFFFE0);
    }
    mobj_emitSfxFromEmitter(&vehicle->field0, vehicle->field15C);
    if (vehicle->field0.mPos.y < 0) {
        traf_20E1E98(vehicle);
    }
}

void traf_20E24D0(Unk020e1e98 *vehicle, Vec3 *hitterPosition) {
    Vec3 c;
    s32 dotAxis0;
    s32 dotAxis2;
    s32 upwardSpeed;

    c = vehicle->field0.mPos;
    VEC_Subtract(&c, hitterPosition, &c);
    dotAxis0 = vec_dotProduct(&vehicle->field0.mMatrix.field0[0], &c);
    dotAxis2 = vec_dotProduct(&vehicle->field0.mMatrix.field0[2], &c);
    c.x = (dotAxis0 > 0 ? vehicle->field0.mMatrix.field0[0].x : -vehicle->field0.mMatrix.field0[0].x) * 2;
    c.x += dotAxis2 > 0 ? vehicle->field0.mMatrix.field0[2].x : -vehicle->field0.mMatrix.field0[2].x;
    c.z = (dotAxis0 > 0 ? vehicle->field0.mMatrix.field0[0].z : -vehicle->field0.mMatrix.field0[0].z) * 2;
    c.z += dotAxis2 > 0 ? vehicle->field0.mMatrix.field0[2].z : -vehicle->field0.mMatrix.field0[2].z;
    c.y = ((vehicle->field114.y - 0x14000) >> 4) + 0x2000;
    if ((s64) c.x * c.x + (s64) c.y * c.y + (s64) c.z * c.z >= 0x10) {
        vec_normalize(&c, &c);
    }
    qrtn_fromForwardVec(&c, &vehicle->fieldC4);
    vehicle->field152 = 0x384;
    if (vehicle->fieldFE > 0xf || vehicle->field0.field10.y <= 0) {
        upwardSpeed = 0;
    } else {
        upwardSpeed = vehicle->field0.field10.y;
    }
    vehicle->field0.field10.y = upwardSpeed + 0x7000;
    vehicle->field0.mFlags |= *(const u16 *) data_02158a50;
    vehicle->fieldFE = 0x14;
}

u8 traf_onDriverCollide(Unk020e1e98 *vehicle, Kart *kart, u8 *c, u8 *d) {
    if (*c == 1) {
        traf_20E24D0(vehicle, &kart->mPos);
        mobj_tryDestroyByDriver(&vehicle->field0, kart);
    }
    return *d;
}

u8 traf_onItemCollide(Unk020e1e98 *vehicle, Unk020e246c *itemObject, u8 *c, u8 *d) {
    if (*c == 1) {
        traf_20E24D0(vehicle, &itemObject->field50);
    }
    return *d;
}

void traf_collide(Unk020e1e98 *vehicle, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 e;
    Vec3 f;
    s32 x;
    s32 y;
    s32 z;

    z = vehicle->field114.z;
    y = vehicle->field114.y;
    x = vehicle->field114.x;
    e.x = x;
    e.y = y;
    e.z = z;
    z = vehicle->field120;
    x = vehicle->field114.x;
    f.x = x;
    f.y = 0;
    f.z = z;
    col_collideSphereBox(sphereCenter, &vehicle->field0.mPos, &vehicle->field0.mMatrix.field0[0], &e, &f,
                                 sphereRadius, overlapOffset);
}

#pragma thumb on

void traf_prepareRoutes(Unk0217b79c *updateList) {
    s32 index;
    s32 count;
    u32 seenGroupMask;
    Unk020e1e98 **vehicleCursor;
    u16 entryCount;
    u16 groupIndex;
    CourseMapGroupEntry *entry;
    u16 entryIndex;
    u16 z;
    Unk020e1e98 *vehicle;
    s16 v;
    s16 w;
    float f;

    count = updateList->field4;
    vehicleCursor = updateList->field0;
    seenGroupMask = 0;
    z = 0;
    for (index = 0; index < count; index++) {
        vehicle = *vehicleCursor;
        groupIndex = vehicle->field0.mCourseMapRow->field26;
        vehicle->fieldD4 = index;
        if ((seenGroupMask & (1 << groupIndex)) == 0) {
            entryCount = gMapData->mEntryGroups[groupIndex].mEntryCount;
            seenGroupMask |= 1 << groupIndex;
            for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
                entry = mdat_getPathPoint(groupIndex, entryIndex);
                v = entry->fieldE;
                if (v != 0) {
                    if (v > 0) {
                        f = 0.5f + (v << 12);
                    } else {
                        f = (v << 12) - 0.5f;
                    }
                    w = FX_SinCosTable_[((((u16) (((s64) (s32) f * 0xB60B60B60B + 0x80000000000) >> 44)) >> 4) << 1) + 1];
                } else {
                    w = 0x2000;
                }
                entry->field12 = w;
                entry->fieldE = z;
            }
        }
        vehicleCursor++;
    }
}

void traf_loadModels(Unk020e20a8 *drawList) {
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
    u32 *q;
    Unk020e1e98_12c **animationSlot;
    s32 count;

    carFile = mobj_getMapObjFile(aCar_a_nsbmd);
    truckFile = mobj_getMapObjFile(aTruck_a_nsbmd);
    drawList->field38 =
        gRaceMultiConfig->mMode != MODE_MISSION_RUN && rstat_getUncontrollable() == 0 && (u16) gRaceMultiConfig->mEntryIndex < 8;
    drawList->field3C = FALSE;
    model2_createFromNsbmd(&traf_sCarModel, carFile, NULL);
    model2_createFromNsbmd(&traf_sTruckModel, truckFile, NULL);
    model2_createFromNsbmd(&traf_sBusModel, mobj_getMapObjFile(aBus_a_nsbmd), NULL);
    model2_createFromNsbmd(&traf_sCarTireModel, mobj_getMapObjFile(aCar_tire_nsbmd), NULL);
    model2_createShadowFromNsbmd(&traf_sCarShadowModel, mobj_getMapObjFile(aCar_a_shadow_n), 7);
    model2_createShadowFromNsbmd(&traf_sTruckShadowModel, mobj_getMapObjFile(aTruck_a_shadow), 7);
    model2_createShadowFromNsbmd(&traf_sBusShadowModel, mobj_getMapObjFile(aBus_a_shadow_n), 7);
    CreateModelAnimation(2, traf_sCarModel, &traf_sCarNsbtpAnim, carFile, mobj_getMapObjFile(aCar_a_nsbtp));
    CreateModelAnimation(2, traf_sTruckModel, &traf_sTruckNsbtpAnim, truckFile, mobj_getMapObjFile(aTruck_a_nsbtp));
    model_setPolyIdLightFlagsEmi(traf_sCarModel, 0x3f, 2, 0x294a);
    for (carMaterialIndex = 0, carModel = ((Unk0217b7a0 *) traf_sCarModel)->field4; carMaterialIndex < carModel->mInfo.mNumMat;
         carMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(carModel, carMaterialIndex, 7);
    }
    model_setPolyIdLightFlagsEmi(traf_sTruckModel, 0x3f, 2, 0x294a);
    for (truckMaterialIndex = 0, truckModel = ((Unk0217b7a0 *) traf_sTruckModel)->field4;
         truckMaterialIndex < truckModel->mInfo.mNumMat; truckMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(truckModel, truckMaterialIndex, 7);
    }
    model_setPolyIdLightFlagsEmi(traf_sBusModel, 0x3f, 2, 0x294a);
    for (busMaterialIndex = 0, busModel = ((Unk0217b7a0 *) traf_sBusModel)->field4; busMaterialIndex < busModel->mInfo.mNumMat;
         busMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(busModel, busMaterialIndex, 7);
    }
    model_setPolyIdLightFlagsEmi(traf_sCarTireModel, 0x3f, 2, 0x294a);
    for (tireMaterialIndex = 0, tireModel = ((Unk0217b7a0 *) traf_sCarTireModel)->field4;
         tireMaterialIndex < tireModel->mInfo.mNumMat; tireMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(tireModel, tireMaterialIndex, 7);
    }
    model_setLightEnableFlag(traf_sCarTireModel, 0);
    count = data_0217b79c->field4;
    for (index = 0; index < count; index++) {
        vehicle = data_0217b79c->field0[index];
        q = vehicle->field154->field20;
        vehicle->field124 = q != NULL ? *q : 0;
        q = vehicle->field154->field24;
        vehicle->field128 = q != NULL ? *q : 0;
        animationSlot = vehicle->field154->field28;
        vehicle->field12C = animationSlot != NULL ? *animationSlot : 0;
    }
}

void traf_init(Unk020e1e98 *vehicle, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo) {
    vehicle->field154 = kindInfo;
    pw_initFromObject(&vehicle->fieldD8, courseRow, (s16) courseRow->field28 * 0x3000 / 100);
    vehicle->fieldFC = courseRow->field2A;
    vehicle->field130 = courseRow->field2C;
    vehicle->fieldA0 = mdat_getPathPoint(courseRow->field26, vehicle->fieldFC)->mPos.y;
    vehicle->field114.x = ((s64) kindInfo->field0 * vehicle->field0.mScale.x) >> 12;
    vehicle->field114.y = ((s64) kindInfo->field4 * vehicle->field0.mScale.y) >> 12;
    vehicle->field114.z = ((s64) kindInfo->field8 * vehicle->field0.mScale.z) >> 12;
    vehicle->field120 = ((s64) kindInfo->fieldC * vehicle->field0.mScale.z) >> 12;
    vehicle->field152 = (u32) ((s16) courseRow->field28 * 0xfa) / 100;
    vehicle->field150 = vehicle->field152;
    vehicle->field100[0] = kindInfo->field10;
    vehicle->field100[1] = kindInfo->field14 >> 4;
    vehicle->field100[2] = kindInfo->field18 >> 4;
    vehicle->field110 = kindInfo->field1C;
    traf_20E1E98(vehicle);
    vehicle->field15C = kindInfo->field2C;
    vehicle->field158 = mobj_initSoundEmitterExForObjectSfxParam2(&vehicle->field0);
    sfx_210B850(vehicle->field158);
    vehicle->field0.mSound->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210a6ec;
    vehicle->field160 = kindInfo->field30;
}

void traf_20E1E98(Unk020e1e98 *vehicle) {
    pw_init(&vehicle->fieldD8, vehicle->fieldFC, 1);
    pw_20D8B18_XZ(&vehicle->fieldD8, &vehicle->field0.mPos, &vehicle->field0.field10);
    vehicle->field0.mPos.y = vehicle->fieldA0;
    vehicle->field0.field10.y = 0;
    vehicle->fieldB4 = *(const Unk020e1e98_0b4 *) data_0216c044;
    func_020d79b0(&vehicle->fieldB4,
                  (u16) (((s64) FX_Atan2(vehicle->field0.field10.x, vehicle->field0.field10.z) * 0x28be60db9391 +
                          0x80000000000) >>
                         44),
                  &vehicle->fieldA4);
    qtrn_toMtx33(&vehicle->field0.mMatrix.field0[0].x, &vehicle->fieldA4);
    vehicle->fieldFE = 0;
    vehicle->field152 = vehicle->field150;
    vehicle->field10C = 0;
    light_init(&vehicle->field132, 1);
}

#pragma thumb off

void dcol_render(Unk020e1dc0 *list, void *viewMatrix, void (*drawObject)(Unk020e3ef4 *, void *, u32)) {
    s32 index;
    s32 count = list->field4;

    for (index = 0; index < count; index++) {
        Unk020e3ef4 *mapObject = list->field0[index];

        if ((mapObject->field0.mFlags & 0x12) == 0 && mapObject->field0.mAlpha != 0) {
            drawObject(mapObject, viewMatrix, mapObject->field0.mAlpha);
        }
    }
}

void dcol_commonRender(Unk020e3ef4 *mapObject, void *viewMatrix, u32 alpha) {
    mapObject->field0.mMatrix.field0[3].x = mapObject->field0.mPos.x >> 4;
    mapObject->field0.mMatrix.field0[3].y = mapObject->field0.mPos.y >> 4;
    mapObject->field0.mMatrix.field0[3].z = mapObject->field0.mPos.z >> 4;
    model2_renderModel(mapObject->mModel, &mapObject->field0.mMatrix, &mapObject->field0.mScale.x,
                                   alpha);
}

void dcol_setModel(Unk020e1dc0 *list, void *model) {
    s32 index;
    s32 count = list->field4;

    for (index = 0; index < count; index++) {
        list->field0[index]->mModel = model;
    }
}

s32 dcol_collide(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *e, Unk020e0764 *f,
                  Vec3 *g, u16 *h, Vec3 *i, u16 *j) {
    switch (object->field134) {
        case 0:
            return dcol_collideBox(object, sphereCenter, sphereRadius, d, e, f, g, h, i, j);
        case 1:
            return dcol_collideCylinder(object, sphereCenter, sphereRadius, d, e, f, g, h, i, j);
    }
    return 0;
}

void dcol_20E1A80(s32 a, s32 b, s32 c, u32 d, u16 e, u16 *f, s32 v, Unk020e005c *object, Vec3 *g, Vec3 *h,
                   Unk020e0764 *i, Unk020e0764 *j, Vec3 *k, Vec3 *l, u16 *m) {
    BOOL q;
    s32 t;
    Unk020e0764 *s;
    u16 n;
    Vec3 u;

    q = FALSE;
    if (v != 0) {
        if (d & e) {
            t = h->y;
        } else {
            t = -h->y;
        }
        if (t > object->field120) {
            q = TRUE;
        }
    }
    u.x = h->x << 10;
    u.y = h->y << 10;
    u.z = h->z << 10;
    u.x = ((s64) u.x * b) >> 12;
    u.y = ((s64) u.y * b) >> 12;
    u.z = ((s64) u.z * b) >> 12;
    if (q) {
        n = object->field114.z != 0 && (d & 8) ? 0x12 : 0;
        *f = n;
        s = i;
    } else {
        *f = 8;
        s = j;
    }
    if (c >= s->field18) {
        s->field18 = c;
        if (d & e) {
            s->field1C = *h;
        } else {
            s->field1C.x = -h->x;
            s->field1C.y = -h->y;
            s->field1C.z = -h->z;
        }
    }
    if (u.x > s->field0) {
        s->field0 = u.x;
    } else if (u.x < s->fieldC) {
        s->fieldC = u.x;
    }
    if (u.y > s->field4) {
        s->field4 = u.y;
    } else if (u.y < s->field10) {
        s->field10 = u.y;
    }
    if (u.z > s->field8) {
        s->field8 = u.z;
    } else if (u.z < s->field14) {
        s->field14 = u.z;
    }
    if (k != NULL) {
        if (d & e) {
            s32 v = -(a - c);

            u.x = ((s64) h->x * v) >> 12;
            u.y = ((s64) h->y * v) >> 12;
            u.z = ((s64) h->z * v) >> 12;
        } else {
            s32 v = a - c;

            u.x = ((s64) h->x * v) >> 12;
            u.y = ((s64) h->y * v) >> 12;
            u.z = ((s64) h->z * v) >> 12;
        }
        if (u.y < k->y) {
            *k = u;
        }
    }
    if (!q) {
        return;
    }
    dcol_20E0680(object, g, h, l, m);
}

BOOL dcol_20E16DC(s32 a, s32 b, s32 c, u32 d, u16 e, u16 f, u16 *g, u16 h, s32 i, s32 j, Unk020e005c *object, Vec3 *l,
                   Vec3 *m, Vec3 *n, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, Vec3 *r, u16 *s) {
    BOOL u;
    BOOL v;
    BOOL k;
    s32 t;
    Unk020e0764 *x;
    Vec3 y;
    Vec3 z;
    Vec3 tmp;

    u = FALSE;
    if ((h & 0x60) == 0) {
        v = TRUE;
        k = FALSE;
        if (i != 0) {
            t = (d & e) ? m->y : -m->y;
            if (t > object->field120) {
                k = TRUE;
            }
        }
        if (k == FALSE) {
            k = FALSE;
            if (j != 0) {
                t = (d & f) ? n->y : -n->y;
                if (t > object->field120) {
                    k = TRUE;
                }
            }
            if (k == FALSE) {
                v = FALSE;
            }
        }
        if (v != FALSE) {
            u = TRUE;
        }
    }
    y.x = ((s64) m->x * b) >> 12;
    y.y = ((s64) m->y * b) >> 12;
    y.z = ((s64) m->z * b) >> 12;
    z.x = ((s64) n->x * c) >> 12;
    z.y = ((s64) n->y * c) >> 12;
    z.z = ((s64) n->z * c) >> 12;
    VEC_Add(&y, &z, &y);
    y.x <<= 10;
    y.y <<= 10;
    y.z <<= 10;
    t = vec_normalizeFast(&y, &tmp);
    if (t > (a << 10)) {
        return FALSE;
    }
    if (t != 0) {
        z.x = ((s64) tmp.x * a) >> 12;
        z.y = ((s64) tmp.y * a) >> 12;
        z.z = ((s64) tmp.z * a) >> 12;
        y.x >>= 10;
        y.y >>= 10;
        y.z >>= 10;
        VEC_Subtract(&z, &y, &z);
        c = VEC_Mag(&z);
    } else {
        tmp = *n;
        z.x = ((s64) tmp.x * a) >> 12;
        z.y = ((s64) tmp.y * a) >> 12;
        z.z = ((s64) tmp.z * a) >> 12;
        c = a;
    }
    if (u) {
        if (object->field114.z != 0 && (d & 8)) {
            *g = 0x1e;
            x = p;
        } else {
            *g = 0;
            x = o;
        }
    } else {
        *g = 8;
        x = p;
    }
    if (c >= x->field18) {
        x->field18 = c;
        x->field1C = tmp;
    }
    z.x <<= 10;
    z.y <<= 10;
    z.z <<= 10;
    if (z.x > x->field0) {
        x->field0 = z.x;
    } else if (z.x < x->fieldC) {
        x->fieldC = z.x;
    }
    if (z.y > x->field4) {
        x->field4 = z.y;
    } else if (z.y < x->field10) {
        x->field10 = z.y;
    }
    if (z.z > x->field8) {
        x->field8 = z.z;
    } else if (z.z < x->field14) {
        x->field14 = z.z;
    }
    if (q != NULL) {
        y.x = -y.x;
        y.y = -y.y;
        y.z = -y.z;
        if (y.y < q->y) {
            *q = y;
        }
    }
    if (u) {
        dcol_20E0680(object, l, &tmp, r, s);
    }
    return TRUE;
}

BOOL dcol_collideBox(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *o, Unk020e0764 *p,
                   Vec3 *q, u16 *g, Vec3 *r, u16 *s) {
    Vec3 v;
    Vec3 w;
    Vec3 tmp;
    Unk020e0764 *x;
    u16 n;
    s32 f6;
    s32 f5;
    s32 f4;
    s32 k6;
    s32 k5;
    s32 m6;
    s32 m5;
    s32 m4;
    BOOL u;
    BOOL e;
    BOOL h;
    BOOL y;
    s32 t;

    n = 0;
    VEC_Subtract(sphereCenter, &object->fieldF4, &v);
    f6 = vec_dotProduct(&v, &object->field28);
    if (f6 > 0) {
        if (f6 > object->field100 + sphereRadius) {
            return FALSE;
        }
        if (f6 > object->field100) {
            n |= 0xa00;
        } else {
            n |= 0x900;
        }
    } else {
        if (f6 < -(object->field100 + sphereRadius)) {
            return FALSE;
        }
        if (f6 < -object->field100) {
            n |= 0x600;
        } else {
            n |= 0x500;
        }
    }
    f5 = vec_dotProduct(&v, &object->field34);
    if (f5 > 0) {
        if (f5 > object->field104 + sphereRadius) {
            return FALSE;
        }
        if (f5 > object->field104) {
            n |= 0xa0;
        } else {
            n |= 0x90;
        }
    } else {
        if (f5 < -(object->field104 + sphereRadius)) {
            return FALSE;
        }
        if (f5 < -object->field104) {
            n |= 0x60;
        } else {
            n |= 0x50;
        }
    }
    f4 = vec_dotProduct(&v, &object->field40);
    if (f4 > 0) {
        if (f4 > object->field108 + sphereRadius) {
            return FALSE;
        }
        if (f4 > object->field108) {
            n |= 0xa;
        } else {
            n |= 0x9;
        }
    } else {
        if (f4 < -(object->field10C + sphereRadius)) {
            return FALSE;
        }
        if (f4 < -object->field10C) {
            n |= 0x6;
        } else {
            n |= 0x5;
        }
    }
    if ((d & 4) && object->field13C != 0) {
        return FALSE;
    }
    if (n & 0x100) {
        if (n & 0x10) {
            if (n & 0x8) {
                f4 = (object->field108 + sphereRadius) - f4;
            } else {
                f4 = -(object->field10C + sphereRadius) - f4;
            }
            if (n & 0x1) {
                if (n & 0x800) {
                    k6 = (object->field100 + sphereRadius) - f6;
                } else {
                    k6 = -(object->field100 + sphereRadius) - f6;
                }
                if (n & 0x80) {
                    k5 = (object->field104 + sphereRadius) - f5;
                } else {
                    k5 = -(object->field104 + sphereRadius) - f5;
                }
                m6 = k6 > 0 ? k6 : -k6;
                m5 = k5 > 0 ? k5 : -k5;
                m4 = f4 > 0 ? f4 : -f4;
                goto smallest;
            }
            m4 = f4 > 0 ? f4 : -f4;
            goto call_8;
        }
        if (n & 0x80) {
            k5 = (object->field104 + sphereRadius) - f5;
        } else {
            k5 = -(object->field104 + sphereRadius) - f5;
        }
        if (!(n & 0x1)) {
            goto call_80_8;
        }
        m5 = k5 > 0 ? k5 : -k5;
        goto call_80;
    }
    if (n & 0x800) {
        k6 = (object->field100 + sphereRadius) - f6;
    } else {
        k6 = -(object->field100 + sphereRadius) - f6;
    }
    if (n & 0x10) {
        if (!(n & 0x1)) {
            goto call_8_800;
        }
        m6 = k6 > 0 ? k6 : -k6;
    } else {
        if (!(n & 0x1)) {
            goto rest;
        }
        goto call_800_80;
    }
call_800:
    dcol_20E1A80(sphereRadius, k6, m6, n, 0x800, g, object->field110, object, sphereCenter, &object->field28, o, p, q,
                  r, s);
    return TRUE;
call_80:
    dcol_20E1A80(sphereRadius, k5, m5, n, 0x80, g, object->field114.x, object, sphereCenter, &object->field34, o, p,
                  q, r, s);
    return TRUE;
call_8:
    dcol_20E1A80(sphereRadius, f4, m4, n, 8, g, object->field114.y, object, sphereCenter, &object->field40, o, p, q,
                  r, s);
    return TRUE;
smallest:
    if (m6 < m4) {
        if (m6 < m5) {
            goto call_800;
        }
        goto call_80;
    }
    if (m4 < m5) {
        goto call_8;
    }
    goto call_80;
call_800_80:
    if (n & 0x800) {
        f6 = f6 - object->field100;
    } else {
        f6 = f6 + object->field100;
    }
    if (n & 0x80) {
        f5 = f5 - object->field104;
    } else {
        f5 = f5 + object->field104;
    }
    return dcol_20E16DC(sphereRadius, f6, f5, n, 0x800, 0x80, g, d, object->field110, object->field114.x, object,
                         sphereCenter, &object->field28, &object->field34, o, p, q, r, s);
call_80_8:
    if (n & 0x80) {
        f5 = f5 - object->field104;
    } else {
        f5 = f5 + object->field104;
    }
    if (n & 0x8) {
        f4 = f4 - object->field108;
    } else {
        f4 = f4 + object->field10C;
    }
    return dcol_20E16DC(sphereRadius, f5, f4, n, 0x80, 0x8, g, d, object->field114.x, object->field114.y, object,
                         sphereCenter, &object->field34, &object->field40, o, p, q, r, s);
call_8_800:
    if (n & 0x8) {
        f4 = f4 - object->field108;
    } else {
        f4 = f4 + object->field10C;
    }
    if (n & 0x800) {
        f6 = f6 - object->field100;
    } else {
        f6 = f6 + object->field100;
    }
    return dcol_20E16DC(sphereRadius, f4, f6, n, 8, 0x800, g, d, object->field114.y, object->field110, object,
                         sphereCenter, &object->field40, &object->field28, o, p, q, r, s);
rest:
    u = FALSE;
    if ((d & 0x60) == 0) {
        e = TRUE;
        y = TRUE;
        h = FALSE;
        if (object->field110 != 0) {
            t = (n & 0x800) ? object->field28.y : -object->field28.y;
            if (t > object->field120) {
                h = TRUE;
            }
        }
        if (h == FALSE) {
            h = FALSE;
            if (object->field114.x != 0) {
                t = (n & 0x80) ? object->field34.y : -object->field34.y;
                if (t > object->field120) {
                    h = TRUE;
                }
            }
            if (h == FALSE) {
                y = FALSE;
            }
        }
        if (y == FALSE) {
            k5 = 0;
            if (object->field114.y != 0) {
                t = (n & 0x8) ? object->field40.y : -object->field40.y;
                if (t > object->field120) {
                    k5 = 1;
                }
            }
            if (k5 == 0) {
                e = FALSE;
            }
        }
        if (e != FALSE) {
            u = TRUE;
        }
    }
    if (n & 0x800) {
        f6 = f6 - object->field100;
    } else {
        f6 = f6 + object->field100;
    }
    if (n & 0x80) {
        f5 = f5 - object->field104;
    } else {
        f5 = f5 + object->field104;
    }
    if (n & 0x8) {
        f4 = f4 - object->field108;
    } else {
        f4 = f4 + object->field10C;
    }
    v.x = ((s64) object->field28.x * f6) >> 12;
    v.y = ((s64) object->field28.y * f6) >> 12;
    v.z = ((s64) object->field28.z * f6) >> 12;
    w.x = ((s64) object->field34.x * f5) >> 12;
    w.y = ((s64) object->field34.y * f5) >> 12;
    w.z = ((s64) object->field34.z * f5) >> 12;
    VEC_Add(&w, &v, &v);
    w.x = ((s64) object->field40.x * f4) >> 12;
    w.y = ((s64) object->field40.y * f4) >> 12;
    w.z = ((s64) object->field40.z * f4) >> 12;
    VEC_Add(&w, &v, &v);
    v.x <<= 10;
    v.y <<= 10;
    v.z <<= 10;
    t = vec_normalizeFast(&v, &w);
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
        w = object->field34;
        tmp.x = ((s64) w.x * sphereRadius) >> 12;
        tmp.y = ((s64) w.y * sphereRadius) >> 12;
        tmp.z = ((s64) w.z * sphereRadius) >> 12;
    }
    if (u) {
        if (object->field114.z != 0 && (n & 0x8)) {
            *g = 0x1e;
            x = p;
        } else {
            *g = 0;
            x = o;
        }
    } else {
        *g = 8;
        x = p;
    }
    if (sphereRadius >= x->field18) {
        x->field18 = sphereRadius;
        x->field1C = w;
    }
    tmp.x <<= 10;
    tmp.y <<= 10;
    tmp.z <<= 10;
    if (tmp.x > x->field0) {
        x->field0 = tmp.x;
    } else if (tmp.x < x->fieldC) {
        x->fieldC = tmp.x;
    }
    if (tmp.y > x->field4) {
        x->field4 = tmp.y;
    } else if (tmp.y < x->field10) {
        x->field10 = tmp.y;
    }
    if (tmp.z > x->field8) {
        x->field8 = tmp.z;
    } else if (tmp.z < x->field14) {
        x->field14 = tmp.z;
    }
    if (q != NULL) {
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
        if (v.y < q->y) {
            *q = v;
        }
    }
    if (u) {
        dcol_20E0680(object, sphereCenter, &w, r, s);
    }
    return TRUE;
}

BOOL dcol_collideCylinder(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *o, Unk020e0764 *p,
                   Vec3 *q, u16 *g, Vec3 *r, u16 *s) {
    Vec3 v;
    s32 d0;
    Vec3 w;
    s32 t;
    s32 k;
    s64 sq;
    u16 fl;
    s32 x;
    s32 y;
    s32 n;

    fl = 0;
    VEC_Subtract(sphereCenter, &object->fieldF4, &v);
    x = vec_dotProduct(&v, &object->field28);
    y = vec_dotProduct(&v, &object->field40);
    sq = (s64) x * x + (s64) y * y;
    t = object->field100 + sphereRadius;
    if ((s64) t * t < sq) {
        return FALSE;
    }
    if ((s64) object->field100 * object->field100 < sq) {
        fl |= data_021588e8;
    } else {
        fl |= data_021588ec;
    }
    n = vec_dotProduct(&v, &object->field34);
    if (n > 0) {
        if (n > object->field104 + sphereRadius) {
            return FALSE;
        }
        if (n > object->field104) {
            fl |= 0xa0;
        } else {
            fl |= 0x90;
        }
    } else {
        if (n < -(object->field104 + sphereRadius)) {
            return FALSE;
        }
        if (n < -object->field104) {
            fl |= 0x60;
        } else {
            fl |= 0x50;
        }
    }
    if (fl & 0x1000) {
        if (fl & 0x80) {
            n = object->field104 + sphereRadius - n;
        } else {
            n = -(object->field104 + sphereRadius) - n;
        }
        if (n > 0) {
            d0 = n;
        } else {
            d0 = -n;
        }
        if (!(fl & 0x10)) {
            goto apply80;
        }
        v.x = x;
        v.y = 0;
        v.z = y;
        x = vec_normalizeXZFast(&v, &v);
        k = t - x;
        if (x == 0) {
            w = data_021588f0;
        } else {
            w.x = ((s64) object->field28.x * v.x) >> 12;
            w.y = ((s64) object->field28.y * v.x) >> 12;
            w.z = ((s64) object->field28.z * v.x) >> 12;
            VEC_MultAdd(v.z, &object->field40, &w, &w);
        }
        goto cmp;
    }
    v.x = x;
    v.y = 0;
    v.z = y;
    x = vec_normalizeXZFast(&v, &v);
    k = t - x;
    if (x == 0) {
        w = data_021588fc;
    } else {
        w.x = ((s64) object->field28.x * v.x) >> 12;
        w.y = ((s64) object->field28.y * v.x) >> 12;
        w.z = ((s64) object->field28.z * v.x) >> 12;
        VEC_MultAdd(v.z, &object->field40, &w, &w);
    }
    if (fl & 0x10) {
        goto apply3000;
    }
    goto tail;
apply80:
    dcol_20E1A80(sphereRadius, n, d0, fl, 0x80, g, object->field114.x, object, sphereCenter, &object->field34, o, p,
                  q, r, s);
    return TRUE;
apply3000:
    dcol_20E1A80(sphereRadius, k, x, fl, 0x3000, g, object->field110, object, sphereCenter, &w, o, p, q, r, s);
    return TRUE;
tail:
    x = x - object->field100;
    if (fl & 0x80) {
        n = n - object->field104;
    } else {
        n = n + object->field104;
    }
    return dcol_20E16DC(sphereRadius, x, n, fl, 0x3000, 0x80, g, d, object->field110, object->field114.x, object,
                         sphereCenter, &w, &object->field34, o, p, q, r, s);
cmp:
    if (k < d0) {
        goto apply3000;
    }
    goto apply80;
}

void dcol_20E0680(Unk020e005c *object, Vec3 *position, Vec3 *c, Vec3 *d, u16 *e) {
    Vec3 offset;

    if (d != NULL) {
        d->x = -object->field10.x;
        d->y = -object->field10.y;
        d->z = -object->field10.z;
        VEC_Subtract(position, &object->mPos, &offset);
        VEC_MultAdd(vec_dotProduct(&offset, &object->field28), &object->fieldA0, d, d);
        VEC_MultAdd(vec_dotProduct(&offset, &object->field34), &object->fieldAC, d, d);
        VEC_MultAdd(vec_dotProduct(&offset, &object->field40), &object->fieldB8, d, d);
        VEC_Subtract(&offset, d, d);
    }
    if (e != NULL) {
        *e = vec_dotProduct(&object->field124, c);
    }
}
