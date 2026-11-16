#include "Main/Unknown/code_020e7a84.h"

#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_0210b000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147288.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020e8a78.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_020f36d8.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02012b30.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Kart/KartTimes.h"

#pragma thumb off

#pragma thumb on

void CreateModelAnimation(u32 animationKind, void *model, void **animationSlot, void *nsbmdFile, void *animationFile) {
    *animationSlot = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    anim_initManager(animationKind, *animationSlot, model, 1, proc_getHeap(proc_getCurrent()), nsbmdFile);
    anim_registerAllAnims(*animationSlot, animationFile, proc_getHeap(proc_getCurrent()));
    anim_setAnim(*animationSlot, 0);
}

#pragma thumb off

// Stores the two offset constants and the four offset vectors; every x is negated when data_0217b8f8 is 0.
void InitJgOffsets(void) {
    gJgOffsetX = 0xf662;
    gJgOffsetY = 0x1232e;
    gJgKind2Offset = data_02159434;
    gJgKind2Offset.x += 0xf662;
    gJgKind3Offset = data_021593d4;
    gJgKind3Offset.x += 0xf662;
    gJgKind4Offset = data_02159428;
    gJgKind4Offset.x += 0xf662;

    gJgLapOffset = rstat_getUncontrollable() ? data_021593f8 : data_0215941c;
    gJgLapOffset.x += gJgOffsetX;
    if (data_0217b8f8 == 0) {
        gJgKind2Offset.x = -gJgKind2Offset.x;
        gJgKind3Offset.x = -gJgKind3Offset.x;
        gJgLapOffset.x = -gJgLapOffset.x;
        gJgKind4Offset.x = -gJgKind4Offset.x;
    }
    gJgKind4Offset.y += gJgOffsetY;
}

static inline s32 AdvanceJgPointsAndSetTarget_inline(s32 start, s32 end, s32 fraction) {
    s32 d = end - start;
    return start + (s32) (((s64) d * fraction) >> 12);
}

// Moves gJgPointPointers along gJgPoints, advances gJgAngle and stores gJgTargetPos.
void AdvanceJgPointsAndSetTarget(Vec3 *offset, const Vec3 *endScale, const Vec3 *startScale) {
    Vec3 pathPoint;
    Vec3 shifted;
    s32 i;
    s32 anglePair0;
    s32 anglePair1;
    s32 lerpedY;
    s32 lerpedX;

    if (pwex_20D849C(&data_0217bb88.mUnk_00) != FALSE) {
        do {
            for (i = 0; i < 4; i++) {
                gJgPointPointers[i] += 1;
                if (gJgPointPointers[i] > &gJgPoint7) {
                    gJgPointPointers[i] = gJgPoints;
                }
            }
        } while (func_020d7c84(&data_0217bb88.mUnk_00, 0, gJgPointPointers) != FALSE);
    }
    pwex_interpolateXYZ(&data_0217bb88, &pathPoint);
    gJgAngle += 0x64;
    i = gJgAngle >> 4;
    anglePair0 = FX_SinCosTable_[i * 2];
    anglePair1 = FX_SinCosTable_[i * 2 + 1];
    lerpedX = AdvanceJgPointsAndSetTarget_inline(startScale->x, endScale->x, (anglePair1 + 0x1000) >> 2);
    lerpedY = AdvanceJgPointsAndSetTarget_inline(startScale->y, endScale->y, (anglePair0 + 0x1000) >> 2);
    pathPoint.x = ((s64) pathPoint.x * lerpedX) >> 12;
    pathPoint.y = ((s64) pathPoint.y * lerpedY) >> 12;
    pathPoint.z = 0;
    VEC_Add(&pathPoint, offset, &pathPoint);
    shifted = pathPoint;
    shifted.x += data_0217b88c;
    MTX_MultVec43(&shifted, &gJgMatrix, &gJgTargetPos);
}

// Runs the position, matrix and state machine; in state 0 it starts the next state from mStatus, lap and mFlags.
void jg_update(void) {
    s32 lap;
    u32 kartFlags;

    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (jg_sTargetDriver == NULL) {
        return;
    }
    if (jg_sStateMachine.mState != 0) {
        gJgTableIndex++;
        if (gJgTableIndex >= 0x3c) {
            gJgTableIndex = 0;
        }
        if (LukituObject != 4) {
            JgKindRow *kindRow = &gJgKindRows[LukituObject];
            if (LukituObject != 0 && LukituObject != 1) {
                if (kindRow->mNsbcaAnimation != NULL) {
                    anim_update(kindRow->mNsbcaAnimation);
                }
                if (kindRow->mNsbmaAnimation != NULL) {
                    anim_update(kindRow->mNsbmaAnimation);
                }
            }
        }
        if (jg_sStateMachine.mState != 4 && (jg_sStateMachine.mState != 5 || LukituObject != 4)) {
            gJgKartPos = jg_sTargetDriver->mPos;
            gJgKartPos.y -= jg_sTargetDriver->mHopHeight;
        }
        ComputeJgMatrixAndInverse();
        UpdateJgPosition();
    }
    sm_execute(&jg_sStateMachine);
    if (jg_sStateMachine.mState != 0) {
        return;
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        return;
    }
    if (gRaceMultiConfig->mMode != MODE_MISSION_RUN && gRaceStatus->mUnk_000[jg_sTargetDriverId].mStatus == 1 &&
        (jg_sTargetDriver->mUnk_48 & 0x800) == 0) {
        Vec3 targetOffset;
        jg_sMainModel.mFrameIndex = 2;
        gJgKartPos = jg_sTargetDriver->mPos;
        gJgKartPos.y -= jg_sTargetDriver->mHopHeight;
        ComputeJgMatrixAndInverse();
        targetOffset = gJgKind3Offset;
        targetOffset.x += data_0217b88c;
        MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
        LukituObject = 3;
        if (rstat_getUncontrollable() == 0) {
            if ((u32) LukituObject <= 1) {
                data_0217b900 = 1;
                data_0217b8ac = 1;
            }
        }
        sm_gotoState(&jg_sStateMachine, 6);
        return;
    }
    if (rstat_hasDriverFinished(jg_sTargetDriverId) != 0) {
        return;
    }
    if (gJgLapAndReverseEnabled != 0) {
        lap = rstat_getDriverHighestReachedLap(jg_sTargetDriverId);
        if (gJgHighestLap < (u32) lap) {
            Vec3 targetOffset;
            gJgHighestLap = lap;
            gJgKartPos = jg_sTargetDriver->mPos;
            gJgKartPos.y -= jg_sTargetDriver->mHopHeight;
            ComputeJgMatrixAndInverse();
            targetOffset = gJgLapOffset;
            targetOffset.x += data_0217b88c;
            MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
            if (gJgHighestLap == jg_sLapCount) {
                LukituObject = 1;
                if (rstat_getUncontrollable() == 0) {
                    if ((u32) LukituObject <= 1) {
                        data_0217b900 = 1;
                        data_0217b8ac = 1;
                    }
                }
                sm_gotoState(&jg_sStateMachine, 6);
                return;
            }
            LukituObject = 0;
            if (rstat_getUncontrollable() == 0) {
                if ((u32) LukituObject <= 1) {
                    data_0217b900 = 1;
                    data_0217b8ac = 1;
                }
            }
            sm_gotoState(&jg_sStateMachine, 6);
            return;
        }
    }
    kartFlags = jg_sTargetDriver->mUnk_48;
    if (kartFlags & 1) {
        return;
    }
    if (gJgLapAndReverseEnabled == 0) {
        return;
    }
    if ((gRaceStatus->mUnk_000[jg_sTargetDriverId].mFlags & 4) != 0 && (kartFlags & 0x800) == 0) {
        data_0217b8c4++;
        if (data_0217b8c4 <= 0x3c) {
            return;
        }
        gJgKartPos = jg_sTargetDriver->mPos;
        gJgKartPos.y -= jg_sTargetDriver->mHopHeight;
        ComputeJgMatrixAndInverse();
        sm_gotoState(&jg_sStateMachine, 1);
        return;
    }
    data_0217b8c4 = 0;
}

// Draws the cloud, jg_sMainModel and the model LukituObject selects; counts jg_sAlpha up to 0x1f while visible.
void jg_render(void) {
    s32 commandArg1, commandArg2, commandArg3, commandArg4, commandArg5, commandArg6, commandArg7, commandArg8;
    s32 rotation[9];
    Vec3 smallScale, tableOffset, baseScale, tableScale, mainOffset, mirrorScale1, mirrorScale2;
    BOOL sentOpening;
    s32 tableScaleX;
    s32 tableScaleY;
    Unk020e9810 *kindModel;
    NsbmdModel *lapModel;

    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (jg_sTargetDriver == NULL) {
        return;
    }
    if (jg_sVisible == 0) {
        goto reset;
    }
    sentOpening = FALSE;
    kindModel = NULL;
    lapModel = NULL;
    switch (LukituObject) {
        case 2:
        case 3:
            kindModel = gJgKindRows[LukituObject].mModel;
            break;
        case 0:
        case 1:
            lapModel = gJgKindRowLapModels[LukituObject].mModel;
            break;
    }
    light_apply(jg_sLight);
    jg_sAlpha++;
    if (jg_sAlpha > 0x1f) {
        jg_sAlpha = 0x1f;
    }
    jg_sMainModel.mUnk_14 &= ~0x1f0000;
    jg_sMainModel.mUnk_14 |= jg_sAlpha << 16;
    jg_sCloudModel.mUnk_14 &= ~0x1f0000;
    jg_sCloudModel.mUnk_14 |= jg_sAlpha << 16;
    if (kindModel != NULL) {
        NNS_G3dMdlSetMdlAlphaAll(kindModel->mUnk_04, jg_sAlpha);
    }
    if (lapModel != NULL) {
        lapModel->mUnk_14 &= ~0x1f0000;
        lapModel->mUnk_14 |= jg_sAlpha << 16;
    }
    if (data_0217b900 != 0) {
        commandArg1 = 0;
        NNS_G3dGeBufferOP_N(0x10, &commandArg1, 1);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        smallScale.x = 0x19a;
        smallScale.y = 0x19a;
        smallScale.z = 0x19a;
        NNS_G3dGeBufferOP_N(0x1b, &smallScale, 3);
        commandArg2 = 2;
        NNS_G3dGeBufferOP_N(0x10, &commandArg2, 1);
        sentOpening = TRUE;
    }
    commandArg3 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg3, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&gJgEasedPos), 0xc);
    tableOffset.y = data_0217b8a4[gJgTableIndex];
    tableOffset.x = 0;
    tableOffset.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &tableOffset, 3);
    baseScale.x = data_0217b8f8 != 0 ? 0x1666 : -0x1666;
    baseScale.y = 0x1666;
    baseScale.z = 0x1666;
    NNS_G3dGeBufferOP_N(0x1b, &baseScale, 3);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    tableScaleX = data_0217b904[gJgTableIndex];
    tableScaleY = data_0217b8e0[gJgTableIndex];
    tableScale.x = tableScaleX;
    tableScale.y = tableScaleY;
    tableScale.z = 0;
    NNS_G3dGeBufferOP_N(0x1b, &tableScale, 3);
    bbm_applyMaterial(&jg_sCloudModel);
    bbm_render(&jg_sCloudModel, NULL, 0, 0x1f);
    commandArg4 = 1;
    NNS_G3dGeBufferOP_N(0x12, &commandArg4, 1);
    mainOffset.x = 0;
    mainOffset.y = 0;
    mainOffset.z = 0xa4;
    NNS_G3dGeBufferOP_N(0x1c, &mainOffset, 3);
    MTX_RotZ33_(rotation, data_0217b8a8[gJgTableIndex], data_0217b8a0[gJgTableIndex]);
    NNS_G3dGeBufferOP_N(0x1a, rotation, 9);
    bbm_applyMaterial(&jg_sMainModel);
    bbm_render(&jg_sMainModel, NULL, 0, 0x1f);
    if (kindModel != NULL) {
        if (LukituObject == 3) {
            commandArg5 = 0;
            NNS_G3dGeBufferOP_N(0x12, &commandArg5, 1);
            NNS_G3dDraw(kindModel);
        } else {
            NNS_G3dGeBufferOP_N(0x1c, &data_021593c8, 3);
            if (data_0217b8f8 == 0) {
                mirrorScale1.x = -0x1000;
                mirrorScale1.y = 0x1000;
                mirrorScale1.z = 0x1000;
                NNS_G3dGeBufferOP_N(0x1b, &mirrorScale1, 3);
            }
            NNS_G3dDraw(kindModel);
        }
    }
    if (lapModel != NULL) {
        NNS_G3dGeBufferOP_N(0x1c, &data_021593c8, 3);
        if (data_0217b8f8 == 0) {
            mirrorScale2.x = -0x1000;
            mirrorScale2.y = 0x1000;
            mirrorScale2.z = 0x1000;
            NNS_G3dGeBufferOP_N(0x1b, &mirrorScale2, 3);
        }
        bbm_applyMaterial(lapModel);
        bbm_render(lapModel, NULL, 0, 0x1f);
    }
    if (sentOpening != FALSE) {
        commandArg6 = 0;
        NNS_G3dGeBufferOP_N(0x10, &commandArg6, 1);
        commandArg7 = 1;
        NNS_G3dGeBufferOP_N(0x12, &commandArg7, 1);
        commandArg8 = 2;
        NNS_G3dGeBufferOP_N(0x10, &commandArg8, 1);
    }
    goto done;
reset:
    jg_sAlpha = 0;
done:;
}

// Rebuilds gJgMatrix at gJgKartPos and its inverse; first keeps the previous inverse and the position change.
void ComputeJgMatrixAndInverse(void) {
    s32 normalizedLength;
    s64 lengthSquared;
    Vec3 *turnedForward;

    gJgPreviousInverseMatrix = gJgInverseMatrix;
    VEC_Subtract(&gJgKartPos, &gJgMatrix.mUnk_00[3], &data_0217b9b4);
    gJgMatrix.mUnk_00[3] = gJgKartPos;
    gJgMatrix.mUnk_00[3].y = gJgMatrix.mUnk_00[3].y + (jg_sTargetDriver->mVelocity.y - jg_sTargetDriver->mHopSpeed);
    gJgMatrix.mUnk_00[1] = data_02159494;

    if (rstat_getUncontrollable() != 0) {
        turnedForward = &jg_sTargetDriver->mTurnedForward;
        gJgMatrix.mUnk_00[2].x = -turnedForward->x;
        gJgMatrix.mUnk_00[2].y = -turnedForward->y;
        gJgMatrix.mUnk_00[2].z = -turnedForward->z;
    } else {
        gJgMatrix.mUnk_00[2] = ((MtxFx43 *) bbm_getBillboardMtx())->mUnk_00[2];
    }
    vec_crossProduct(&gJgMatrix.mUnk_00[1], &gJgMatrix.mUnk_00[2], &gJgMatrix.mUnk_00[2]);
    lengthSquared = (s64) gJgMatrix.mUnk_00[2].x * gJgMatrix.mUnk_00[2].x +
                    (s64) gJgMatrix.mUnk_00[2].y * gJgMatrix.mUnk_00[2].y +
                    (s64) gJgMatrix.mUnk_00[2].z * gJgMatrix.mUnk_00[2].z;
    normalizedLength = 0;
    if (lengthSquared >= 0x10) {
        normalizedLength = vec_normalize(&gJgMatrix.mUnk_00[2], &gJgMatrix.mUnk_00[2]);
    }
    if (normalizedLength != 0) {
        gJgMatrix.mUnk_00[0] = gJgMatrix.mUnk_00[2];
    }
    vec_crossProduct(&gJgMatrix.mUnk_00[0], &gJgMatrix.mUnk_00[1], &gJgMatrix.mUnk_00[2]);
    MTX_Transpose33_(&gJgMatrix, &gJgInverseMatrix);
    MTX_MultVec33(&gJgMatrix.mUnk_00[3], (const s32 *) &gJgInverseMatrix, &gJgInverseMatrixPos);
    gJgInverseMatrix.mUnk_00[3].x = -gJgInverseMatrix.mUnk_00[3].x;
    gJgInverseMatrix.mUnk_00[3].y = -gJgInverseMatrix.mUnk_00[3].y;
    gJgInverseMatrix.mUnk_00[3].z = -gJgInverseMatrix.mUnk_00[3].z;
}

static inline void UpdateJgPosition_inline(Vec3 *result, const Vec3 *first, const Vec3 *second) {
    result->x = first->x < second->x ? first->x : second->x;
    result->y = first->y < second->y ? first->y : second->y;
    result->z = first->z < second->z ? first->z : second->z;
}

static inline void UpdateJgPosition_inline_2(Vec3 *result, const Vec3 *first, const Vec3 *second) {
    result->x = first->x > second->x ? first->x : second->x;
    result->y = first->y > second->y ? first->y : second->y;
    result->z = first->z > second->z ? first->z : second->z;
}

// Steers gJgPos toward gJgTargetPos (damped, pushed out of map objects and the course); snaps in state 4 or hidden.
void UpdateJgPosition(void) {
    s64 distanceSquared;
    s32 deltaZ;
    s32 deltaX;

    if (jg_sStateMachine.mState == 4 || jg_sVisible == 0) {
        data_0217b90c = gJgTargetPos;
        data_0217b918 = data_0217b90c;
        data_0217b93c = data_0217b918;
        data_0217b99c = data_0217b93c;
        gJgPos = data_0217b99c;
        data_0217b9b4.x = 0;
        data_0217b9b4.y = 0;
        data_0217b9b4.z = 0;
        gJgVelocity.x = 0;
        gJgVelocity.y = 0;
        gJgVelocity.z = 0;
        data_0217b870 = 0;
        data_0217b8b8 = 0;
        data_0217b88c = 0;
        data_0217b8cc = 0;
        data_0217b8ec = 0;
        gJgEasedPos = gJgPos;
        data_0217b8f0 = 1;
        data_0217b8bc = 1;
        data_0217b894 = 0;
    } else {
        void *previousPos;
        Vec3 t;
        Vec3 u;
        Vec3 v;
        s32 i;
        BOOL pushed = FALSE;
        Vec3 pushMin, pushMax;
        s32 halfOffset;
        s32 w;
        s32 limitX;
        s32 limitZ;

        pushMin = (Vec3){0, 0, 0};
        pushMax = (Vec3){0, 0, 0};
        if (jg_sStateMachine.mState == 6 || jg_sStateMachine.mState == 2) {
            previousPos = NULL;
        } else {
            previousPos = &data_0217b918;
        }
        data_0217b918 = data_0217b93c;
        if (data_0217b8f8 != 0) {
            halfOffset = -gJgOffsetX >> 1;
            t.x = ((s64) gJgMatrix.mUnk_00[0].x * halfOffset) >> 12;
            t.y = ((s64) gJgMatrix.mUnk_00[0].y * halfOffset) >> 12;
            t.z = ((s64) gJgMatrix.mUnk_00[0].z * halfOffset) >> 12;
        } else {
            halfOffset = gJgOffsetX >> 1;
            t.x = ((s64) gJgMatrix.mUnk_00[0].x * halfOffset) >> 12;
            t.y = ((s64) gJgMatrix.mUnk_00[0].y * halfOffset) >> 12;
            t.z = ((s64) gJgMatrix.mUnk_00[0].z * halfOffset) >> 12;
        }
        VEC_Add(&gJgPos, &t, &data_0217b93c);
        halfOffset = -gJgOffsetY >> 1;
        t.x = ((s64) gJgMatrix.mUnk_00[1].x * halfOffset) >> 12;
        t.y = ((s64) gJgMatrix.mUnk_00[1].y * halfOffset) >> 12;
        t.z = ((s64) gJgMatrix.mUnk_00[1].z * halfOffset) >> 12;
        VEC_Add(&data_0217b93c, &t, &data_0217b93c);
        data_0217b8fc = 0;
        if (data_0217b900 == 0) {
            if (data_0217b8bc != 0 || data_0217b8f0 != 0) {
                col_queryBySphere(&data_0217b93c, 0x12000, 0x2000);
                for (i = 0; i < gColQueryResultCount; i++) {
                    MapObject *q = gColQueryResultObjects[i];

                    if ((q->mFlags & 0x40) == 0 && mobj_sphereCollide(&data_0217b93c, 0x12000, q, &t) != FALSE) {
                        UpdateJgPosition_inline(&pushMin, &t, &pushMin);
                        UpdateJgPosition_inline_2(&pushMax, &t, &pushMax);
                        pushed = TRUE;
                    }
                }
                if (col_collide(&data_0217b93c, previousPos, 0, 0x12000, 4, -1, &t, NULL, NULL, &data_0217b8fc, NULL,
                                  NULL, NULL, NULL) != 0) {
                    UpdateJgPosition_inline(&pushMin, &t, &pushMin);
                    UpdateJgPosition_inline_2(&pushMax, &t, &pushMax);
                    pushed = TRUE;
                }
            }
        }
        if (pushed != FALSE) {
            if ((data_0217b8fc & 0x80000) == 0) {
                data_0217b894 = 0;
            }
            t = pushMin;
            VEC_Add(&t, &pushMax, &t);
            if (t.y < 0 && jg_sStateMachine.mState == 5) {
                t.y = 0;
            }
            VEC_Add(&gJgPos, &t, &gJgPos);
            VEC_Add(&data_0217b93c, &t, &data_0217b93c);
        }
        if (data_0217b900 == 0) {
            data_0217b870++;
            if (data_0217b870 > 0xc) {
                data_0217b870 = 0;
            }
            data_0217b90c.x = gJgPos.x + data_0217b870 * (s32) (((s64) jg_sTargetDriver->mVelocity.x * 0x5000) >> 12);
            data_0217b90c.z = gJgPos.z + data_0217b870 * (s32) (((s64) jg_sTargetDriver->mVelocity.z * 0x5000) >> 12);
            data_0217b90c.y = gJgPos.y;
            if (col_collide(&data_0217b90c, NULL, 0, 0x18e66, 0x10, -1, NULL, NULL, (s32 *) &v, NULL, NULL, NULL,
                              NULL, NULL) != 0) {
                w = jg_sTargetDriver->mForwardSpeed;
                if (w <= 0) {
                    w = -w;
                }
                if (vec_dotProduct(&v, &gJgMatrix.mUnk_00[0]) > 0) {
                    data_0217b8b8 = ((s64) w << 11) >> 12;
                } else {
                    data_0217b8b8 = -(s32) (((s64) w << 11) >> 12);
                }
                data_0217b908 += 0xc;
                data_0217b870 = 0xc;
            }
            w = data_0217b8b8 - (s32) (((s64) data_0217b88c * 0x29) >> 12);
            data_0217b8b8 = w;
            if (data_0217b88c * (s64) w < 0) {
                data_0217b8b8 = w - (s32) (((s64) w * 0x19a) >> 12);
            }
            data_0217b88c += data_0217b8b8;
            if (data_0217b8bc == 0) {
                data_0217b8cc += 0xcd;
                data_0217b8ec += data_0217b8cc;
            } else {
                if (data_0217b8ec <= 0) {
                    data_0217b8ec = 0;
                    data_0217b8cc = 0;
                } else {
                    data_0217b8ec -= data_0217b8cc;
                    data_0217b8cc -= 0xcd;
                }
            }
        }
        data_0217b99c = gJgPos;
        if (jg_sTargetDriver->mState >= KART_STATE_PUSH_FLIP) {
            data_0217b8ac = 0;
        }
        if (data_0217b900 != 0 && data_0217b8ac != 0) {
            gJgPos.x = gJgTargetPos.x;
            gJgPos.z = gJgTargetPos.z;
            u.x = u.z = 0;
            t.y = gJgTargetPos.y - gJgPos.y;
            t.y = t.y + data_0217b8ec;
        } else {
            data_0217b908 -= 0x29;
            if (data_0217b908 > data_021593bc.x) {
                data_0217b908 = data_021593bc.x;
            }
            if (data_0217b908 < 0x7b) {
                data_0217b908 = 0x7b;
            }
            VEC_Subtract(&gJgTargetPos, &gJgPos, &t);
            t.y += data_0217b8ec;
            u.x = vec_dotProduct(&t, &gJgMatrix.mUnk_00[0]);
            u.z = vec_dotProduct(&t, &gJgMatrixAxis2);
            gJgVelocity.x = ((s64) data_0217b908 * u.x) >> 12;
            gJgVelocity.z +=
                (s32) (((s64) data_021593bc.z * u.z) >> 12) - (s32) (((s64) data_021593b0.z * gJgVelocity.z) >> 12);
            v.x = vec_dotProduct(&data_0217b9b4, &gJgMatrix.mUnk_00[0]);
            v.z = vec_dotProduct(&data_0217b9b4, &gJgMatrixAxis2);
            gJgVelocity.x -= v.x;
            gJgVelocity.z -= v.z;
            if (data_0217b8f0 != 0 || data_0217b8bc != 0) {
                limitX = data_0217b894 != 0 ? 0x1000 : 0x800;
                if (gJgVelocity.x > limitX) {
                    gJgVelocity.x = limitX;
                } else if (gJgVelocity.x < -limitX) {
                    gJgVelocity.x = -limitX;
                }
                limitZ = data_0217b894 != 0 ? 0x2000 : 0x1000;
                if (gJgVelocity.z > limitZ) {
                    gJgVelocity.z = limitZ;
                } else if (gJgVelocity.z < -limitZ) {
                    gJgVelocity.z = -limitZ;
                }
            }
            gJgVelocity.x += v.x;
            gJgVelocity.z += v.z;
            MTX_MultVec33(&gJgVelocity, (const s32 *) &gJgMatrix.mUnk_00[0], &u);
        }
        gJgVelocity.y = gJgVelocity.y + ((s32) (((s64) data_021593bc.y * t.y) >> 12) -
                                         (s32) (((s64) data_021593b0.y * gJgVelocity.y) >> 12));
        u.y = gJgVelocity.y;
        VEC_Add(&gJgPos, &u, &gJgPos);
        VEC_Subtract(&gJgPos, &gJgEasedPos, &v);
        VEC_MultAdd(0xd9a, &v, &gJgEasedPos, &gJgEasedPos);
    }
    if (jg_sVisible == 0) {
        return;
    }
    data_0217b8f0 = (mobj_calcVisibilityFlags3d(&gJgPos, 0x12000, 0x708000, 0x5f592e1, 0x1f) & 3) == 0 ? 1 : 0;
    deltaX = gJgPos.x - gJgMatrix.mUnk_00[3].x;
    deltaZ = gJgPos.z - gJgMatrix.mUnk_00[3].z;
    distanceSquared = (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
    data_0217b8bc = distanceSquared < 0x57e4000000LL ? 1 : 0;
    if (data_0217b8bc != 0) {
        data_0217b8f4 = 0;
        return;
    }
    data_0217b8f4 = distanceSquared >= 0x3d090000000LL ? 1 : 0;
}

u32 jg_idleStateInit(void) {
    u32 secondFlagAddress;
    u32 flagAddress;
    u32 counterAddress;
    u32 visibleAddress;
    u32 initialKind;
    u32 kindAddress;
    u32 zero;
    kindAddress = (u32) &LukituObject;
    initialKind = 4u;
    visibleAddress = (u32) &jg_sVisible;
    zero = 0u;
    counterAddress = (u32) &data_0217b8c4;
    flagAddress = (u32) &data_0217b900;
    secondFlagAddress = (u32) &data_0217b8ac;
    *(u32 *) ((kindAddress) + (0)) = initialKind;
    *(u32 *) ((visibleAddress) + (0)) = zero;
    *(u32 *) ((counterAddress) + (0)) = zero;
    *(u32 *) ((flagAddress) + (0)) = zero;
    *(u32 *) ((secondFlagAddress) + (0)) = zero;
    return secondFlagAddress;
}

u32 jg_idleStateUpdate(u32 value) {
    return value;
}

void jg_state1Init(void) {
    Unk020e6514 *animation;
    s32 rotatedZ;

    // Written through a cast: a plain store changes the test below.
    *(s32 *) &LukituObject = 2;
    jg_sVisible = 1;
    data_0217b8c4 = 0;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    gJgTableIndex = 0;
    if (LukituObject != 4) {
        animation = gJgKindRowNsbcaAnimations[LukituObject].mUnk_00;
        if (animation != NULL) {
            animation->mUnk_00c = 0;
            animation->mUnk_1c[animation->mUnk_1a]->mFrame = animation->mUnk_00c;
        }
        animation = gJgKindRowNsbmaAnimations[LukituObject].mUnk_00;
        if (animation != NULL) {
            animation->mUnk_00c = 0;
            animation->mUnk_1c[animation->mUnk_1a]->mFrame = animation->mUnk_00c;
        }
    }
    gJgPointPointers[0] = &gJgPoint7;
    gJgPointPointers[1] = gJgPoints;
    gJgPointPointers[2] = &gJgPoint1;
    gJgPointPointers[3] = &gJgPoint2;
    func_020d7d18(&data_0217bb88.mUnk_00, 0, gJgPointPointers, 0x1ec);
    gJgAngle = 0;
    rotatedZ = (s32) (((s64) gJgKind2Offset.z * data_0215f4b4[1]) >> 12) -
               (s32) (((s64) gJgKind2Offset.x * data_0215f4b4[0]) >> 12);
    data_0217b8b4 = 0x8000;
    gJgTargetPos.z = rotatedZ;
    if (rotatedZ > 0) {
        gJgTargetPos.z = rotatedZ * 3;
    }
    gJgTargetPos.x = (s32) (((s64) gJgKind2Offset.z * data_0215f4b4[0]) >> 12) +
                     (s32) (((s64) gJgKind2Offset.x * data_0215f4b4[1]) >> 12);
    gJgTargetPos.y = gJgKind2Offset.y;
    MTX_MultVec43(&gJgTargetPos, &gJgMatrix, &gJgTargetPos);
    data_0217b90c = gJgTargetPos;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    gJgPos = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    gJgVelocity.x = 0;
    data_0217b870 = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    gJgEasedPos = gJgPos;
    data_0217b8ec = 0;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

void jg_state1Update(void) {
    Unk020e6514 *animation;
    s32 angle;
    u32 frame;
    s32 pairIndex;
    s32 anglePair0;
    s32 anglePair1;
    s32 rotatedZ;
    NNSSndSeqPlayer **seqPlayer;
    s32 scaledZ;
    enum { K0 } frameFixed;

    animation = gJgKindRowNsbmaAnimations[LukituObject].mUnk_00;
    frameFixed = animation->mUnk_00c;
    angle = data_0217b8b4;
    frame = ((u32) frameFixed << 4) >> 16;
    if (angle > 0 && angle < 0x10000) {
        pairIndex = (angle >> 4) << 1;
        anglePair0 = FX_SinCosTable_[pairIndex];
        anglePair1 = FX_SinCosTable_[pairIndex + 1];
        scaledZ = ((s64) gJgKind2Offset.z * anglePair1) >> 12;
        rotatedZ = scaledZ - (s32) (((s64) gJgKind2Offset.x * anglePair0) >> 12);
        gJgTargetPos.z = rotatedZ;
        if (rotatedZ > 0) {
            gJgTargetPos.z = rotatedZ * 3;
        }
        gJgTargetPos.x =
            (s32) (((s64) gJgKind2Offset.z * anglePair0) >> 12) + (s32) (((s64) gJgKind2Offset.x * anglePair1) >> 12);
        gJgTargetPos.y = gJgKind2Offset.y;
        MTX_MultVec43(&gJgTargetPos, &gJgMatrix, &gJgTargetPos);
        if (data_0217b8f8 != 0) {
            data_0217b8b4 -= 0xf0;
        } else {
            data_0217b8b4 += 0xf0;
        }
        data_0217b908 = data_021593bc.x;
        data_0217b894 = 1;
    } else {
        data_0217b894 = 0;
        AdvanceJgPointsAndSetTarget(&gJgKind2Offset, &data_02159404, &data_02159410);
        if (data_0217b8f0 == 0 && data_0217b8bc == 0) {
            sm_gotoState(&jg_sStateMachine, 1);
        }
    }
    if (frame == 0xa || frame == 0x28) {
        seqPlayer = GetSndHandleSlot(4);
        data_0217b9dc.mDistanceSquared = mobj_calcXZCamDist(&gJgPos);
        NNS_SndPlayerStopSeq(seqPlayer, 0);
        func_0210b760(&data_0217b9dc, seqPlayer);
    }
    if (rstat_hasDriverFinished(jg_sTargetDriverId) != 0 || (jg_sTargetDriver->mUnk_48 & 0x800) != 0) {
        sm_gotoState(&jg_sStateMachine, 5);
        return;
    }
    if ((gRaceStatus->mUnk_000[jg_sTargetDriverId].mFlags & 4) == 0) {
        if (++data_0217b8c4 > 0x3c) {
            sm_gotoState(&jg_sStateMachine, 5);
            return;
        }
    } else {
        data_0217b8c4 = 0;
    }
    if ((jg_sTargetDriver->mUnk_48 & 1) == 0) {
        return;
    }
    sm_gotoState(&jg_sStateMachine, 5);
}

void jg_state2Init(void) {
    Vec3 targetOffset;

    if (gJgHighestLap != jg_sLapCount) {
        gJgKindRows[0].mLapModel->mFrameIndex = gJgHighestLap - 2;
    }
    data_0217b8b4 = 0;
    targetOffset = gJgLapOffset;
    targetOffset.x += data_0217b88c;
    MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
}

void jg_state2Update(void) {
    Vec3 targetOffset;

    targetOffset = gJgLapOffset;
    targetOffset.x += data_0217b88c;
    MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
    if (++data_0217b8b4 > gJgState2FrameCount || (jg_sTargetDriver->mUnk_48 & 0x800) != 0) {
        sm_gotoState(&jg_sStateMachine, 5);
    }
}

void jg_state3Init(void) {
    gJgPointPointers[0] = &gJgPoint7;
    gJgPointPointers[1] = gJgPoints;
    gJgPointPointers[2] = &gJgPoint1;
    gJgPointPointers[3] = &gJgPoint2;
    func_020d7d18(&data_0217bb88.mUnk_00, 0, gJgPointPointers, 0x1ec);
    gJgAngle = 0;
    AdvanceJgPointsAndSetTarget(&gJgKind3Offset, &data_021593e0, &data_021593ec);
}

void jg_state3Update(void) {
    AdvanceJgPointsAndSetTarget(&gJgKind3Offset, &data_021593e0, &data_021593ec);
    if ((jg_sTargetDriver->mUnk_48 & 0x800) == 0) {
        return;
    }
    sm_gotoState(&jg_sStateMachine, 5);
}

void jg_respawningStateInit(void) {
    Unk020e6514 *animation;
    NNSSndSeqPlayer **seqPlayer;
    MtxFx43 *matrix;

    data_0217b8c4 = 0;
    // Written through a cast: a plain store changes the test below.
    *(s32 *) &LukituObject = 4;
    jg_sVisible = 1;
    jg_sAlpha = 0x1f;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    gJgTableIndex = 0;
    if (LukituObject != 4) {
        animation = gJgKindRowNsbcaAnimations[LukituObject].mUnk_00;
        if (animation != NULL) {
            animation->mUnk_00c = 0;
            animation->mUnk_1c[animation->mUnk_1a]->mFrame = animation->mUnk_00c;
        }
        animation = gJgKindRowNsbmaAnimations[LukituObject].mUnk_00;
        if (animation != NULL) {
            animation->mUnk_00c = 0;
            animation->mUnk_1c[animation->mUnk_1a]->mFrame = animation->mUnk_00c;
        }
    }
    jg_sMainModel.mFrameIndex = 1;
    data_0217b8b4 = 0;
    if (rstat_getUncontrollable() != 0) {
        matrix = bbm_getYBillboardMtx();
        matrix->mUnk_00[3] = gJgKartPos;
        MTX_MultVec43(&gJgKind4Offset, matrix, &gJgTargetPos);
    } else {
        MTX_MultVec43(&gJgKind4Offset, &gJgMatrix, &gJgTargetPos);
    }
    data_0217b90c = gJgTargetPos;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    gJgPos = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    gJgVelocity.x = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    gJgEasedPos = gJgPos;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(4), 1);
    seqPlayer = GetSndHandleSlot(4);
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (SoundHandle_217D084.mUnk_0c == 0) {
        return;
    }
    if (*seqPlayer != NULL) {
        NNS_SndPlayerStopSeq(seqPlayer, 0);
    }
    if (*seqPlayer != NULL) {
        NNS_SndPlayerStopSeq(seqPlayer, 0);
    }
    NNS_SndArcPlayerStartSeqArc(seqPlayer, 0, 0x102);
}

void jg_respawningStateUpdate(void) {
    MtxFx43 *matrix;

    if (data_0217b8b4 == 0) {
        gJgKartPos = jg_sTargetDriver->mPos;
    } else if (--data_0217b8b4 <= 0) {
        jg_sMainModel.mFrameIndex = 0;
        sm_gotoState(&jg_sStateMachine, 5);
    }
    if (rstat_getUncontrollable() != 0) {
        matrix = bbm_getYBillboardMtx();
        matrix->mUnk_00[3] = gJgKartPos;
        MTX_MultVec43(&gJgKind4Offset, matrix, &gJgTargetPos);
    } else {
        MTX_MultVec43(&gJgKind4Offset, &gJgMatrix, &gJgTargetPos);
    }
}

void jg_state5Init(void) {
    s32 initialSpeed;

    jg_sVisible = 1;
    MTX_MultVec43(&gJgTargetPos, &gJgPreviousInverseMatrix, &data_0217b984);
    data_0217b89c = 0;
    initialSpeed = 0;
    if ((jg_sTargetDriver->mUnk_48 & 1) == 0) {
        initialSpeed = 0xffffbccd;
    }
    data_0217b8d8 = initialSpeed;
}

void jg_state5Update(void) {
    s32 acceleration;

    MTX_MultVec43(&data_0217b984, &gJgMatrix, &gJgTargetPos);
    if ((jg_sTargetDriver->mUnk_48 & 1) != 0) {
        acceleration = 0x2000;
    } else {
        acceleration = 0x800;
    }
    data_0217b8d8 += acceleration;
    data_0217b89c += data_0217b8d8;
    gJgTargetPos.y += data_0217b89c;
    if (data_0217b89c <= 0x5dc000) {
        return;
    }
    if (data_0217b8f0 != 0) {
        return;
    }
    NNS_SndPlayerStopSeq(GetSndHandleSlot(4), 1);
    sm_gotoState(&jg_sStateMachine, 0);
}

void jg_state6Init(void) {
    Unk020e6514 *animation;
    s32 step;
    s32 heightOffset;
    s32 i;
    s32 clampedStep;

    jg_sVisible = 1;
    gJgTableIndex = 0;
    if (LukituObject != 4) {
        animation = gJgKindRowNsbcaAnimations[LukituObject].mUnk_00;
        if (animation != NULL) {
            animation->mUnk_00c = 0;
            animation->mUnk_1c[animation->mUnk_1a]->mFrame = animation->mUnk_00c;
        }
        animation = gJgKindRowNsbmaAnimations[LukituObject].mUnk_00;
        if (animation != NULL) {
            animation->mUnk_00c = 0;
            animation->mUnk_1c[animation->mUnk_1a]->mFrame = animation->mUnk_00c;
        }
    }
    MTX_MultVec43(&gJgTargetPos, &gJgPreviousInverseMatrix, &data_0217b96c);
    for (i = 0, step = 0, heightOffset = 0; i < 0x1e; i++) {
        clampedStep = (step > -0x3000) ? -0x3000 : step;
        heightOffset -= clampedStep;
        step += 0x19a;
    }
    gJgTargetPos.y += heightOffset;
    data_0217b90c = gJgTargetPos;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b898 = heightOffset;
    data_0217b99c = data_0217b93c;
    data_0217b8d0 = step;
    gJgPos = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    gJgVelocity.x = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    gJgEasedPos = gJgPos;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

// Lowers the target from above; when the height reaches 0 it picks state 2 (kinds 0, 1), 3 (kind 3) or 5.
void jg_state6Update(void) {
    s32 clampedStep;
    s32 heightOffset;

    MTX_MultVec43(&data_0217b96c, &gJgMatrix, &gJgTargetPos);
    data_0217b8d0 -= 0x19a;
    clampedStep = data_0217b8d0;
    if (clampedStep > -0x3000) {
        clampedStep = -0x3000;
    }
    heightOffset = data_0217b898 + clampedStep;
    data_0217b898 = heightOffset;
    gJgTargetPos.y += heightOffset;
    if (heightOffset <= 0) {
        switch (LukituObject) {
            case 0:
            case 1:
                sm_gotoState(&jg_sStateMachine, 2);
                break;
            case 3:
                sm_gotoState(&jg_sStateMachine, 3);
                break;
            default:
                sm_gotoState(&jg_sStateMachine, 5);
                break;
        }
    }
    data_0217b908 = data_021593bc.x;
}
