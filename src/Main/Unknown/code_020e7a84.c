#include "Main/Unknown/code_020e7a84.h"

#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020846c0.h" // Nsbmd
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
#include "Main/Unknown/code_02036820.h"
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
#include "Main/Unknown/code_020ed5c0.h"
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
#include "Main/Unknown/code_0203c5f8.h"

#pragma thumb off

#pragma thumb on

void CreateModelAnimation(u32 animationKind, void *model, ModelAnimation **animationSlot, void *nsbmdFile,
                          void *animationFile) {
    *animationSlot = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimation(animationKind, *animationSlot, model, 1, GetHeap(GetCurrentHeapCall()), nsbmdFile);
    InitModelAnimationEntries(*animationSlot, animationFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(*animationSlot, 0);
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

    gJgLapOffset = GetEntryRaceEnded() ? data_021593f8 : data_0215941c;
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
    s32 delta = end - start;
    return start + MUL_FIXED12_NO_ROUND(delta, fraction);
}

// Moves gJgPointPointers along gJgPoints, advances gJgAngle and stores gJgTargetPos.
void AdvanceJgPointsAndSetTarget(Vec3 *offset, const Vec3 *endScale, const Vec3 *startScale) {
    Vec3 pathPoint;
    Vec3 shifted;
    s32 index;
    s32 anglePair0;
    s32 anglePair1;
    s32 lerpedY;
    s32 lerpedX;

    if (AdvanceSegmentProgress(&data_0217bb88.mSegmentProgress) != FALSE) {
        do {
            for (index = 0; index < 4; index++) {
                gJgPointPointers[index] += 1;
                if (gJgPointPointers[index] > &gJgPoint7) {
                    gJgPointPointers[index] = gJgPoints;
                }
            }
        } while (BuildNextSegmentProgress(&data_0217bb88.mSegmentProgress, 0, gJgPointPointers) != FALSE);
    }
    GetSegmentProgressPoint(&data_0217bb88, &pathPoint);
    gJgAngle += 0x64;
    anglePair0 = SIN_OF_ANGLE(gJgAngle);
    anglePair1 = COS_OF_ANGLE(gJgAngle);
    lerpedX = AdvanceJgPointsAndSetTarget_inline(startScale->x, endScale->x, (anglePair1 + 0x1000) >> 2);
    lerpedY = AdvanceJgPointsAndSetTarget_inline(startScale->y, endScale->y, (anglePair0 + 0x1000) >> 2);
    pathPoint.x = MUL_FIXED12_NO_ROUND(pathPoint.x, lerpedX);
    pathPoint.y = MUL_FIXED12_NO_ROUND(pathPoint.y, lerpedY);
    pathPoint.z = 0;
    VEC_Add(&pathPoint, offset, &pathPoint);
    shifted = pathPoint;
    shifted.x += gJgShiftX;
    MTX_MultVec43(&shifted, &gJgMatrix, &gJgTargetPos);
}

// Runs the position, matrix and state machine; in state 0 it starts the next state from mStatus, lap and mFlags.
void UpdateJg(void) {
    s32 lap;
    u32 kartFlags;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (gJgKart == NULL) {
        return;
    }
    if (gJgStateMachine.mState != 0) {
        gJgTableIndex++;
        if (gJgTableIndex >= 0x3c) {
            gJgTableIndex = 0;
        }
        if (gJgKind != 4) {
            JgKindRow *kindRow = &gJgKindRows[gJgKind];
            if (gJgKind != 0 && gJgKind != 1) {
                if (kindRow->mNsbcaAnimation != NULL) {
                    AdvanceModelAnimation(kindRow->mNsbcaAnimation);
                }
                if (kindRow->mNsbmaAnimation != NULL) {
                    AdvanceModelAnimation(kindRow->mNsbmaAnimation);
                }
            }
        }
        if (gJgStateMachine.mState != 4 && (gJgStateMachine.mState != 5 || gJgKind != 4)) {
            gJgKartPos = gJgKart->mPos;
            gJgKartPos.y -= gJgKart->mHopHeight;
        }
        ComputeJgMatrixAndInverse();
        UpdateJgPosition();
    }
    AdvanceStateMachine(&gJgStateMachine);
    if (gJgStateMachine.mState != 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN &&
        gRaceProgress->mKarts[gJgKartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED &&
        (gJgKart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) == 0) {
        Vec3 targetOffset;
        gJgMain.mFrameIndex = 2;
        gJgKartPos = gJgKart->mPos;
        gJgKartPos.y -= gJgKart->mHopHeight;
        ComputeJgMatrixAndInverse();
        targetOffset = gJgKind3Offset;
        targetOffset.x += gJgShiftX;
        MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
        gJgKind = 3;
        if (GetEntryRaceEnded() == 0) {
            if ((u32) gJgKind <= 1) {
                data_0217b900 = 1;
                data_0217b8ac = 1;
            }
        }
        SetStateMachineState(&gJgStateMachine, 6);
        return;
    }
    if (IsKartEnded(gJgKartIndex) != 0) {
        return;
    }
    if (gJgLapAndReverseEnabled != 0) {
        lap = GetKartHighestLap(gJgKartIndex);
        if (gJgHighestLap < (u32) lap) {
            Vec3 targetOffset;
            gJgHighestLap = lap;
            gJgKartPos = gJgKart->mPos;
            gJgKartPos.y -= gJgKart->mHopHeight;
            ComputeJgMatrixAndInverse();
            targetOffset = gJgLapOffset;
            targetOffset.x += gJgShiftX;
            MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
            if (gJgHighestLap == gJgFinalLap) {
                gJgKind = 1;
                if (GetEntryRaceEnded() == 0) {
                    if ((u32) gJgKind <= 1) {
                        data_0217b900 = 1;
                        data_0217b8ac = 1;
                    }
                }
                SetStateMachineState(&gJgStateMachine, 6);
                return;
            }
            gJgKind = 0;
            if (GetEntryRaceEnded() == 0) {
                if ((u32) gJgKind <= 1) {
                    data_0217b900 = 1;
                    data_0217b8ac = 1;
                }
            }
            SetStateMachineState(&gJgStateMachine, 6);
            return;
        }
    }
    kartFlags = gJgKart->mDriveFlags;
    if (kartFlags & KART_DRIVE_ON_BOOST_SURFACE) {
        return;
    }
    if (gJgLapAndReverseEnabled == 0) {
        return;
    }
    if ((gRaceProgress->mKarts[gJgKartIndex].mFlags & RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT) != 0 &&
        (kartFlags & KART_DRIVE_RESPAWN_WAIT) == 0) {
        data_0217b8c4++;
        if (data_0217b8c4 <= 0x3c) {
            return;
        }
        gJgKartPos = gJgKart->mPos;
        gJgKartPos.y -= gJgKart->mHopHeight;
        ComputeJgMatrixAndInverse();
        SetStateMachineState(&gJgStateMachine, 1);
        return;
    }
    data_0217b8c4 = 0;
}

// Draws the cloud, gJgMain and the model gJgKind selects; counts gJgAlpha up to 0x1f while visible.
void DrawJg(void) {
    s32 commandArg1, commandArg2, commandArg3, commandArg4, commandArg5, commandArg6, commandArg7, commandArg8;
    MtxFx33 rotation;
    Vec3 smallScale, tableOffset, baseScale, tableScale, mainOffset, mirrorScale1, mirrorScale2;
    BOOL sentOpening;
    s32 tableScaleX;
    s32 tableScaleY;
    Nsbmd *kindModel;
    NsbmdModel *lapModel;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (gJgKart == NULL) {
        return;
    }
    if (gJgVisible == 0) {
        goto reset;
    }
    sentOpening = FALSE;
    kindModel = NULL;
    lapModel = NULL;
    switch (gJgKind) {
        case 2:
        case 3:
            kindModel = gJgKindRows[gJgKind].mModel;
            break;
        case 0:
        case 1:
            lapModel = gJgKindRows[gJgKind].mLapModel;
            break;
    }
    SendLight01Color(data_0217b8c0);
    gJgAlpha++;
    if (gJgAlpha > 0x1f) {
        gJgAlpha = 0x1f;
    }
    gJgMain.mPolygonAttributes &= ~0x1f0000;
    gJgMain.mPolygonAttributes |= gJgAlpha << 16;
    gJgCloud.mPolygonAttributes &= ~0x1f0000;
    gJgCloud.mPolygonAttributes |= gJgAlpha << 16;
    if (kindModel != NULL) {
        NNS_G3dMdlSetMdlAlphaAll(kindModel->mResMdl, gJgAlpha);
    }
    if (lapModel != NULL) {
        lapModel->mPolygonAttributes &= ~0x1f0000;
        lapModel->mPolygonAttributes |= gJgAlpha << 16;
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
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&gJgEasedPos), 0xc);
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
    QueueNsbmdModelMaterial(&gJgCloud);
    DrawNsbmdModelWithMaxAlpha(&gJgCloud, NULL, 0, 0x1f);
    commandArg4 = 1;
    NNS_G3dGeBufferOP_N(0x12, &commandArg4, 1);
    mainOffset.x = 0;
    mainOffset.y = 0;
    mainOffset.z = 0xa4;
    NNS_G3dGeBufferOP_N(0x1c, &mainOffset, 3);
    MTX_RotZ33_(&rotation, data_0217b8a8[gJgTableIndex], data_0217b8a0[gJgTableIndex]);
    NNS_G3dGeBufferOP_N(0x1a, &rotation, 9);
    QueueNsbmdModelMaterial(&gJgMain);
    DrawNsbmdModelWithMaxAlpha(&gJgMain, NULL, 0, 0x1f);
    if (kindModel != NULL) {
        if (gJgKind == 3) {
            commandArg5 = 0;
            NNS_G3dGeBufferOP_N(0x12, &commandArg5, 1);
            NNS_G3dDraw(&kindModel->mRenderObj);
        } else {
            NNS_G3dGeBufferOP_N(0x1c, &data_021593c8, 3);
            if (data_0217b8f8 == 0) {
                mirrorScale1.x = -0x1000;
                mirrorScale1.y = 0x1000;
                mirrorScale1.z = 0x1000;
                NNS_G3dGeBufferOP_N(0x1b, &mirrorScale1, 3);
            }
            NNS_G3dDraw(&kindModel->mRenderObj);
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
        QueueNsbmdModelMaterial(lapModel);
        DrawNsbmdModelWithMaxAlpha(lapModel, NULL, 0, 0x1f);
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
    gJgAlpha = 0;
done:;
}

// Rebuilds gJgMatrix at gJgKartPos and its inverse; first keeps the previous inverse and the position change.
void ComputeJgMatrixAndInverse(void) {
    s32 normalizedLength;
    s64 lengthSquared;
    Vec3 *turnedForward;

    gJgPreviousInverseMatrix = gJgInverseMatrix;
    VEC_Subtract(&gJgKartPos, &gJgMatrix.mRows[3], &gJgKartMove);
    gJgMatrix.mRows[3] = gJgKartPos;
    gJgMatrix.mRows[3].y = gJgMatrix.mRows[3].y + (gJgKart->mVelocity.y - gJgKart->mHopSpeed);
    gJgMatrix.mRows[1] = data_02159494;

    if (GetEntryRaceEnded() != 0) {
        turnedForward = &gJgKart->mTurnedForward;
        gJgMatrix.mRows[2].x = -turnedForward->x;
        gJgMatrix.mRows[2].y = -turnedForward->y;
        gJgMatrix.mRows[2].z = -turnedForward->z;
    } else {
        gJgMatrix.mRows[2] = GetViewTransposeMatrix()->mRows[2];
    }
    Vec3CrossUnrounded(&gJgMatrix.mRows[1], &gJgMatrix.mRows[2], &gJgMatrix.mRows[2]);
    lengthSquared = (s64) gJgMatrix.mRows[2].x * gJgMatrix.mRows[2].x +
                    (s64) gJgMatrix.mRows[2].y * gJgMatrix.mRows[2].y +
                    (s64) gJgMatrix.mRows[2].z * gJgMatrix.mRows[2].z;
    normalizedLength = 0;
    if (lengthSquared >= 0x10) {
        normalizedLength = Vec3NormalizeAndGetLengthUnchecked(&gJgMatrix.mRows[2], &gJgMatrix.mRows[2]);
    }
    if (normalizedLength != 0) {
        gJgMatrix.mRows[0] = gJgMatrix.mRows[2];
    }
    Vec3CrossUnrounded(&gJgMatrix.mRows[0], &gJgMatrix.mRows[1], &gJgMatrix.mRows[2]);
    MTX_Transpose33_(&gJgMatrix, &gJgInverseMatrix);
    MTX_MultVec33(&gJgMatrix.mRows[3], &gJgInverseMatrix.mAxes, &gJgInverseMatrixPos);
    gJgInverseMatrix.mRows[3].x = -gJgInverseMatrix.mRows[3].x;
    gJgInverseMatrix.mRows[3].y = -gJgInverseMatrix.mRows[3].y;
    gJgInverseMatrix.mRows[3].z = -gJgInverseMatrix.mRows[3].z;
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

    if (gJgStateMachine.mState == 4 || gJgVisible == 0) {
        gJgProbeCenter = gJgTargetPos;
        data_0217b918 = gJgProbeCenter;
        gJgCollisionCenter = data_0217b918;
        data_0217b99c = gJgCollisionCenter;
        gJgPos = data_0217b99c;
        gJgKartMove.x = 0;
        gJgKartMove.y = 0;
        gJgKartMove.z = 0;
        gJgVelocity.x = 0;
        gJgVelocity.y = 0;
        gJgVelocity.z = 0;
        gJgProbeStep = 0;
        gJgShiftSpeedX = 0;
        gJgShiftX = 0;
        data_0217b8cc = 0;
        data_0217b8ec = 0;
        gJgEasedPos = gJgPos;
        data_0217b8f0 = 1;
        data_0217b8bc = 1;
        data_0217b894 = 0;
    } else {
        Vec3 *previousPos;
        Vec3 offsetVec;
        Vec3 localVec;
        Vec3 normalVec;
        s32 slotIndex;
        BOOL pushed = FALSE;
        Vec3 pushMin, pushMax;
        s32 halfOffset;
        s32 speed;
        s32 limitX;
        s32 limitZ;

        pushMin = (Vec3){0, 0, 0};
        pushMax = (Vec3){0, 0, 0};
        if (gJgStateMachine.mState == 6 || gJgStateMachine.mState == 2) {
            previousPos = NULL;
        } else {
            previousPos = &data_0217b918;
        }
        data_0217b918 = gJgCollisionCenter;
        if (data_0217b8f8 != 0) {
            halfOffset = -gJgOffsetX >> 1;
            offsetVec.x = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[0].x, halfOffset);
            offsetVec.y = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[0].y, halfOffset);
            offsetVec.z = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[0].z, halfOffset);
        } else {
            halfOffset = gJgOffsetX >> 1;
            offsetVec.x = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[0].x, halfOffset);
            offsetVec.y = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[0].y, halfOffset);
            offsetVec.z = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[0].z, halfOffset);
        }
        VEC_Add(&gJgPos, &offsetVec, &gJgCollisionCenter);
        halfOffset = -gJgOffsetY >> 1;
        offsetVec.x = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[1].x, halfOffset);
        offsetVec.y = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[1].y, halfOffset);
        offsetVec.z = MUL_FIXED12_NO_ROUND(gJgMatrix.mRows[1].z, halfOffset);
        VEC_Add(&gJgCollisionCenter, &offsetVec, &gJgCollisionCenter);
        data_0217b8fc = 0;
        if (data_0217b900 == 0) {
            if (data_0217b8bc != 0 || data_0217b8f0 != 0) {
                FindCollisionSlotsAroundPos(&gJgCollisionCenter, 0x12000, 0x2000);
                for (slotIndex = 0; slotIndex < gFoundCollisionSlotCount; slotIndex++) {
                    MapObject *foundObject = gFoundCollisionSlotObjects[slotIndex];

                    if ((foundObject->mFlags & 0x40) == 0 &&
                        IsSphereHittingMapObject(&gJgCollisionCenter, 0x12000, foundObject, &offsetVec) != FALSE) {
                        UpdateJgPosition_inline(&pushMin, &offsetVec, &pushMin);
                        UpdateJgPosition_inline_2(&pushMax, &offsetVec, &pushMax);
                        pushed = TRUE;
                    }
                }
                if (CollideSphereWithCourse(&gJgCollisionCenter, previousPos, 0, 0x12000, 4, -1, &offsetVec, NULL, NULL,
                                            &data_0217b8fc, NULL, NULL, NULL, NULL) != 0) {
                    UpdateJgPosition_inline(&pushMin, &offsetVec, &pushMin);
                    UpdateJgPosition_inline_2(&pushMax, &offsetVec, &pushMax);
                    pushed = TRUE;
                }
            }
        }
        if (pushed != FALSE) {
            if ((data_0217b8fc & 0x80000) == 0) {
                data_0217b894 = 0;
            }
            offsetVec = pushMin;
            VEC_Add(&offsetVec, &pushMax, &offsetVec);
            if (offsetVec.y < 0 && gJgStateMachine.mState == 5) {
                offsetVec.y = 0;
            }
            VEC_Add(&gJgPos, &offsetVec, &gJgPos);
            VEC_Add(&gJgCollisionCenter, &offsetVec, &gJgCollisionCenter);
        }
        if (data_0217b900 == 0) {
            gJgProbeStep++;
            if (gJgProbeStep > 0xc) {
                gJgProbeStep = 0;
            }
            gJgProbeCenter.x = gJgPos.x + gJgProbeStep * MUL_FIXED12_NO_ROUND(gJgKart->mVelocity.x, 0x5000);
            gJgProbeCenter.z = gJgPos.z + gJgProbeStep * MUL_FIXED12_NO_ROUND(gJgKart->mVelocity.z, 0x5000);
            gJgProbeCenter.y = gJgPos.y;
            if (CollideSphereWithCourse(&gJgProbeCenter, NULL, 0, 0x18e66, 0x10, -1, NULL, NULL, &normalVec, NULL, NULL,
                                        NULL, NULL, NULL) != 0) {
                speed = gJgKart->mForwardSpeed;
                if (speed <= 0) {
                    speed = -speed;
                }
                if (Vec3DotUnrounded(&normalVec, &gJgMatrix.mRows[0]) > 0) {
                    gJgShiftSpeedX = ((s64) speed << 11) >> 12;
                } else {
                    gJgShiftSpeedX = -(s32) (((s64) speed << 11) >> 12);
                }
                data_0217b908 += 0xc;
                gJgProbeStep = 0xc;
            }
            speed = gJgShiftSpeedX - MUL_FIXED12_NO_ROUND(gJgShiftX, 0x29);
            gJgShiftSpeedX = speed;
            if (gJgShiftX * (s64) speed < 0) {
                gJgShiftSpeedX = speed - MUL_FIXED12_NO_ROUND(speed, 0x19a);
            }
            gJgShiftX += gJgShiftSpeedX;
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
        if (gJgKart->mState >= KART_STATE_PUSH_FLIP) {
            data_0217b8ac = 0;
        }
        if (data_0217b900 != 0 && data_0217b8ac != 0) {
            gJgPos.x = gJgTargetPos.x;
            gJgPos.z = gJgTargetPos.z;
            localVec.x = localVec.z = 0;
            offsetVec.y = gJgTargetPos.y - gJgPos.y;
            offsetVec.y = offsetVec.y + data_0217b8ec;
        } else {
            data_0217b908 -= 0x29;
            if (data_0217b908 > data_021593bc.x) {
                data_0217b908 = data_021593bc.x;
            }
            if (data_0217b908 < 0x7b) {
                data_0217b908 = 0x7b;
            }
            VEC_Subtract(&gJgTargetPos, &gJgPos, &offsetVec);
            offsetVec.y += data_0217b8ec;
            localVec.x = Vec3DotUnrounded(&offsetVec, &gJgMatrix.mRows[0]);
            localVec.z = Vec3DotUnrounded(&offsetVec, &gJgMatrixAxis2);
            gJgVelocity.x = MUL_FIXED12_NO_ROUND(data_0217b908, localVec.x);
            gJgVelocity.z += MUL_FIXED12_NO_ROUND(data_021593bc.z, localVec.z) -
                             MUL_FIXED12_NO_ROUND(data_021593b0.z, gJgVelocity.z);
            normalVec.x = Vec3DotUnrounded(&gJgKartMove, &gJgMatrix.mRows[0]);
            normalVec.z = Vec3DotUnrounded(&gJgKartMove, &gJgMatrixAxis2);
            gJgVelocity.x -= normalVec.x;
            gJgVelocity.z -= normalVec.z;
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
            gJgVelocity.x += normalVec.x;
            gJgVelocity.z += normalVec.z;
            MTX_MultVec33(&gJgVelocity, &gJgMatrix.mAxes, &localVec);
        }
        gJgVelocity.y = gJgVelocity.y + (MUL_FIXED12_NO_ROUND(data_021593bc.y, offsetVec.y) -
                                         MUL_FIXED12_NO_ROUND(data_021593b0.y, gJgVelocity.y));
        localVec.y = gJgVelocity.y;
        VEC_Add(&gJgPos, &localVec, &gJgPos);
        VEC_Subtract(&gJgPos, &gJgEasedPos, &normalVec);
        VEC_MultAdd(0xd9a, &normalVec, &gJgEasedPos, &gJgEasedPos);
    }
    if (gJgVisible == 0) {
        return;
    }
    data_0217b8f0 = (ComputeTwoPlaneViewTest(&gJgPos, 0x12000, 0x708000, 0x5f592e1, 0x1f) & 3) == 0 ? 1 : 0;
    deltaX = gJgPos.x - gJgMatrix.mRows[3].x;
    deltaZ = gJgPos.z - gJgMatrix.mRows[3].z;
    distanceSquared = (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
    data_0217b8bc = distanceSquared < 0x57e4000000LL ? 1 : 0;
    if (data_0217b8bc != 0) {
        data_0217b8f4 = 0;
        return;
    }
    data_0217b8f4 = distanceSquared >= 0x3d090000000LL ? 1 : 0;
}

s32 *EnterJgState0(void) {
    gJgKind = 4;
    gJgVisible = 0;
    data_0217b8c4 = 0;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    return &data_0217b8ac;
}

u32 JgState0ReturnArgument(u32 value) {
    return value;
}

void EnterJgState1(void) {
    ModelAnimation *animation;
    s32 rotatedZ;

    // Written through a cast: a plain store changes the test below.
    *(s32 *) &gJgKind = 2;
    gJgVisible = 1;
    data_0217b8c4 = 0;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    gJgTableIndex = 0;
    if (gJgKind != 4) {
        animation = gJgKindRows[gJgKind].mNsbcaAnimation;
        if (animation != NULL) {
            animation->mHead.mFrameIndex = 0;
            animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
        }
        animation = gJgKindRows[gJgKind].mNsbmaAnimation;
        if (animation != NULL) {
            animation->mHead.mFrameIndex = 0;
            animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
        }
    }
    gJgPointPointers[0] = &gJgPoint7;
    gJgPointPointers[1] = gJgPoints;
    gJgPointPointers[2] = &gJgPoint1;
    gJgPointPointers[3] = &gJgPoint2;
    InitSegmentProgress(&data_0217bb88.mSegmentProgress, 0, gJgPointPointers, 0x1ec);
    gJgAngle = 0;
    rotatedZ = MUL_FIXED12_NO_ROUND(gJgKind2Offset.z, data_0215f4b4[1]) -
               MUL_FIXED12_NO_ROUND(gJgKind2Offset.x, data_0215f4b4[0]);
    data_0217b8b4 = 0x8000;
    gJgTargetPos.z = rotatedZ;
    if (rotatedZ > 0) {
        gJgTargetPos.z = rotatedZ * 3;
    }
    gJgTargetPos.x = MUL_FIXED12_NO_ROUND(gJgKind2Offset.z, data_0215f4b4[0]) +
                     MUL_FIXED12_NO_ROUND(gJgKind2Offset.x, data_0215f4b4[1]);
    gJgTargetPos.y = gJgKind2Offset.y;
    MTX_MultVec43(&gJgTargetPos, &gJgMatrix, &gJgTargetPos);
    gJgProbeCenter = gJgTargetPos;
    data_0217b918 = gJgProbeCenter;
    gJgCollisionCenter = data_0217b918;
    data_0217b99c = gJgCollisionCenter;
    gJgPos = data_0217b99c;
    gJgKartMove.x = 0;
    gJgKartMove.y = 0;
    gJgKartMove.z = 0;
    gJgVelocity.x = 0;
    gJgProbeStep = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    gJgShiftSpeedX = 0;
    gJgShiftX = 0;
    data_0217b8cc = 0;
    gJgEasedPos = gJgPos;
    data_0217b8ec = 0;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

void UpdateJgState1(void) {
    ModelAnimation *animation;
    s32 angle;
    u32 frame;
    s32 anglePair0;
    s32 anglePair1;
    s32 rotatedZ;
    NNSSndSeqPlayer **seqPlayer;
    s32 scaledZ;
    enum { K0 } frameFixed;

    animation = gJgKindRows[gJgKind].mNsbmaAnimation;
    frameFixed = animation->mHead.mFrameIndex;
    angle = data_0217b8b4;
    frame = ((u32) frameFixed << 4) >> 16;
    if (angle > 0 && angle < 0x10000) {
        anglePair0 = SIN_OF_ANGLE(angle);
        anglePair1 = COS_OF_ANGLE(angle);
        scaledZ = MUL_FIXED12_NO_ROUND(gJgKind2Offset.z, anglePair1);
        rotatedZ = scaledZ - MUL_FIXED12_NO_ROUND(gJgKind2Offset.x, anglePair0);
        gJgTargetPos.z = rotatedZ;
        if (rotatedZ > 0) {
            gJgTargetPos.z = rotatedZ * 3;
        }
        gJgTargetPos.x =
            MUL_FIXED12_NO_ROUND(gJgKind2Offset.z, anglePair0) + MUL_FIXED12_NO_ROUND(gJgKind2Offset.x, anglePair1);
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
            SetStateMachineState(&gJgStateMachine, 1);
        }
    }
    if (frame == 0xa || frame == 0x28) {
        seqPlayer = GetSndHandleSlot(4);
        data_0217b9dc.mDistanceSquared = GetHorizontalCameraDistanceSquared(&gJgPos);
        NNS_SndPlayerStopSeq(seqPlayer, 0);
        StartSndHandleSound(&data_0217b9dc, seqPlayer);
    }
    if (IsKartEnded(gJgKartIndex) != 0 || (gJgKart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) != 0) {
        SetStateMachineState(&gJgStateMachine, 5);
        return;
    }
    if ((gRaceProgress->mKarts[gJgKartIndex].mFlags & RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT) == 0) {
        if (++data_0217b8c4 > 0x3c) {
            SetStateMachineState(&gJgStateMachine, 5);
            return;
        }
    } else {
        data_0217b8c4 = 0;
    }
    if ((gJgKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) == 0) {
        return;
    }
    SetStateMachineState(&gJgStateMachine, 5);
}

void EnterJgState2(void) {
    Vec3 targetOffset;

    if (gJgHighestLap != gJgFinalLap) {
        gJgKindRows[0].mLapModel->mFrameIndex = gJgHighestLap - 2;
    }
    data_0217b8b4 = 0;
    targetOffset = gJgLapOffset;
    targetOffset.x += gJgShiftX;
    MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
}

void UpdateJgState2(void) {
    Vec3 targetOffset;

    targetOffset = gJgLapOffset;
    targetOffset.x += gJgShiftX;
    MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
    if (++data_0217b8b4 > gJgState2FrameCount || (gJgKart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) != 0) {
        SetStateMachineState(&gJgStateMachine, 5);
    }
}

void EnterJgState3(void) {
    gJgPointPointers[0] = &gJgPoint7;
    gJgPointPointers[1] = gJgPoints;
    gJgPointPointers[2] = &gJgPoint1;
    gJgPointPointers[3] = &gJgPoint2;
    InitSegmentProgress(&data_0217bb88.mSegmentProgress, 0, gJgPointPointers, 0x1ec);
    gJgAngle = 0;
    AdvanceJgPointsAndSetTarget(&gJgKind3Offset, &data_021593e0, &data_021593ec);
}

void UpdateJgState3(void) {
    AdvanceJgPointsAndSetTarget(&gJgKind3Offset, &data_021593e0, &data_021593ec);
    if ((gJgKart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) == 0) {
        return;
    }
    SetStateMachineState(&gJgStateMachine, 5);
}

void EnterJgState4(void) {
    ModelAnimation *animation;
    NNSSndSeqPlayer **seqPlayer;
    MtxFx43 *matrix;

    data_0217b8c4 = 0;
    // Written through a cast: a plain store changes the test below.
    *(s32 *) &gJgKind = 4;
    gJgVisible = 1;
    gJgAlpha = 0x1f;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    gJgTableIndex = 0;
    if (gJgKind != 4) {
        animation = gJgKindRows[gJgKind].mNsbcaAnimation;
        if (animation != NULL) {
            animation->mHead.mFrameIndex = 0;
            animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
        }
        animation = gJgKindRows[gJgKind].mNsbmaAnimation;
        if (animation != NULL) {
            animation->mHead.mFrameIndex = 0;
            animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
        }
    }
    gJgMain.mFrameIndex = 1;
    data_0217b8b4 = 0;
    if (GetEntryRaceEnded() != 0) {
        matrix = GetViewRotatedMatrix();
        matrix->mRows[3] = gJgKartPos;
        MTX_MultVec43(&gJgKind4Offset, matrix, &gJgTargetPos);
    } else {
        MTX_MultVec43(&gJgKind4Offset, &gJgMatrix, &gJgTargetPos);
    }
    gJgProbeCenter = gJgTargetPos;
    data_0217b918 = gJgProbeCenter;
    gJgCollisionCenter = data_0217b918;
    data_0217b99c = gJgCollisionCenter;
    gJgPos = data_0217b99c;
    gJgKartMove.x = 0;
    gJgKartMove.y = 0;
    gJgKartMove.z = 0;
    gJgVelocity.x = 0;
    gJgProbeStep = 0;
    gJgShiftSpeedX = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    gJgShiftX = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    gJgEasedPos = gJgPos;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(4), 1);
    seqPlayer = GetSndHandleSlot(4);
    if ((gRaceSoundKind & 1) == 0) {
        return;
    }
    if (gSoundModeHolder.mSeqStartEnabled == 0) {
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

void UpdateJgState4(void) {
    MtxFx43 *matrix;

    if (data_0217b8b4 == 0) {
        gJgKartPos = gJgKart->mPos;
    } else if (--data_0217b8b4 <= 0) {
        gJgMain.mFrameIndex = 0;
        SetStateMachineState(&gJgStateMachine, 5);
    }
    if (GetEntryRaceEnded() != 0) {
        matrix = GetViewRotatedMatrix();
        matrix->mRows[3] = gJgKartPos;
        MTX_MultVec43(&gJgKind4Offset, matrix, &gJgTargetPos);
    } else {
        MTX_MultVec43(&gJgKind4Offset, &gJgMatrix, &gJgTargetPos);
    }
}

void EnterJgState5(void) {
    s32 initialSpeed;

    gJgVisible = 1;
    MTX_MultVec43(&gJgTargetPos, &gJgPreviousInverseMatrix, &data_0217b984);
    data_0217b89c = 0;
    initialSpeed = 0;
    if ((gJgKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) == 0) {
        initialSpeed = 0xffffbccd;
    }
    data_0217b8d8 = initialSpeed;
}

void UpdateJgState5(void) {
    s32 acceleration;

    MTX_MultVec43(&data_0217b984, &gJgMatrix, &gJgTargetPos);
    if ((gJgKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) != 0) {
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
    SetStateMachineState(&gJgStateMachine, 0);
}

void EnterJgState6(void) {
    ModelAnimation *animation;
    s32 step;
    s32 heightOffset;
    s32 frameIndex;
    s32 clampedStep;

    gJgVisible = 1;
    gJgTableIndex = 0;
    if (gJgKind != 4) {
        animation = gJgKindRows[gJgKind].mNsbcaAnimation;
        if (animation != NULL) {
            animation->mHead.mFrameIndex = 0;
            animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
        }
        animation = gJgKindRows[gJgKind].mNsbmaAnimation;
        if (animation != NULL) {
            animation->mHead.mFrameIndex = 0;
            animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
        }
    }
    MTX_MultVec43(&gJgTargetPos, &gJgPreviousInverseMatrix, &data_0217b96c);
    for (frameIndex = 0, step = 0, heightOffset = 0; frameIndex < 0x1e; frameIndex++) {
        clampedStep = (step > -0x3000) ? -0x3000 : step;
        heightOffset -= clampedStep;
        step += 0x19a;
    }
    gJgTargetPos.y += heightOffset;
    gJgProbeCenter = gJgTargetPos;
    data_0217b918 = gJgProbeCenter;
    gJgCollisionCenter = data_0217b918;
    data_0217b898 = heightOffset;
    data_0217b99c = gJgCollisionCenter;
    data_0217b8d0 = step;
    gJgPos = data_0217b99c;
    gJgKartMove.x = 0;
    gJgKartMove.y = 0;
    gJgKartMove.z = 0;
    gJgVelocity.x = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    gJgProbeStep = 0;
    gJgShiftSpeedX = 0;
    gJgShiftX = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    gJgEasedPos = gJgPos;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

// Lowers the target from above; when the height reaches 0 it picks state 2 (kinds 0, 1), 3 (kind 3) or 5.
void UpdateJgState6(void) {
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
        switch (gJgKind) {
            case 0:
            case 1:
                SetStateMachineState(&gJgStateMachine, 2);
                break;
            case 3:
                SetStateMachineState(&gJgStateMachine, 3);
                break;
            default:
                SetStateMachineState(&gJgStateMachine, 5);
                break;
        }
    }
    data_0217b908 = data_021593bc.x;
}
