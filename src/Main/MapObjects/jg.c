#include "Main/MapObjects/jg.h"

#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/attractor_distance_flag.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "matrix_4x3_basic.h"
#include "01/MapObjects/item_bomb_node_placement.h"
#include "Main/Race/entry_race_ended.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/Kart/kart_drift.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/light_color.h"
#include "Main/MapObjects/segment_progress_point.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "ITCM/collision_slots.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "model_material_set.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/Race/kart.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/System/init_after_startup.h"

const Vec3 gJgReverseBaseOffset = {0, 0x2e000, -196608};
const Vec3 gJgVelocityFactors = {0x19a, 0x52, 0x800};
const Vec3 gJgModelOffset = {-2560, -2176, 0};
const Vec3 gJgFlagBaseOffset = {-65536, 0x2b000, -286720};
const Vec3 gJgVelocityDamping = {0x19a, 0x19a, 0xccd};
const Vec3 gJgFlagEndScale = {0x10000, 0x6000, 0};
const Vec3 gJgFlagStartScale = {0xb000, 0x4000, 0};
const Vec3 gJgLapBaseOffsetRaceEnded = {0x18000, 0x2e000, -237568};
const Vec3 gJgReverseEndScale = {0x1800, 0x1800, 0};
const Vec3 gJgReverseStartScale = {0x1000, 0x1000, 0};
const Vec3 gJgLapBaseOffsetNotEnded = {0x1e000, 0x19000, -167936};
const Vec3 gJgSourcePoints[7] = {{-8192, -8192, 0}, {-12288, -4096, 0}, {-8192, 0x1000, 0}, {0, -8192, 0},
                                 {0x2000, 0, 0},    {0x3000, -4096, 0}, {0x2000, -8192, 0}};
const Vec3 gJgNoModelBaseOffset = {0, 0x4000, -20480};
u16 gJgLapFrameCount;
u16 gJgKartIndex;
u16 gJgFinalLap;
u16 gJgHighestLap;
u16 gJgAlpha;
u16 gJgAngle;
u16 gJgProbeStep;
s32 gJgInView;
s32 gJgHeightOffsetSpeed;
s32 gJgReverseAngleActive;
s32 gJgOffsetY;
s32 gJgVelocityFactorX;
s32 gJgArriveHeightOffset;
s32 gJgKind;
s32 gJgTableIndex;
u32 gJgCourseHitBits;
s16 *gJgMainRotationSineTable;
s32 gJgNearKart;
s32 gJgOffsetX;
s32 gJgShiftSpeedX;
s32 gJgShiftX;
s32 gJgLeaveHeightOffset;
s32 gJgArriveSpeed;
Kart *gJgKart;
s32 gJgLapAndReverseEnabled;
s32 gJgCheckpointFlagFrames;
u16 *gJgKartCourseColor;
s32 gJgSnapUntilPushFlip;
s16 *gJgCloudScaleXTable;
s32 gJgStateCounter;
s32 gJgVisible;
s32 gJgStartSideNotFlipped;
s32 gJgFarFromKart;
s32 gJgHeightOffset;
s16 *gJgMainRotationCosineTable;
s32 gJgLeaveSpeed;
s16 *gJgCloudOffsetYTable;
s16 *gJgCloudScaleYTable;
s32 gJgLapKindActive;
Vec3 gJgTargetPos;
Vec3 gJgKartMove;
Vec3 gJgPreviousPos;
Vec3 gJgFlagOffset;
Vec3 gJgLeaveLocalTargetPos;
Vec3 gJgLapOffset;
Vec3 gJgArriveLocalTargetPos;
Vec3 gJgNoModelOffset;
Vec3 gJgKartPos;
Vec3 gJgEasedPos;
Vec3 gJgCollisionCenter;
Vec3 gJgPos;
Vec3 gJgVelocity;
Vec3 gJgPreviousCollisionCenter;
Vec3 gJgProbeCenter;
Vec3 gJgReverseOffset;
SoundStartParams gJgSoundStartParams;
Vec3 *gJgPointPointers[4];
StateMachine gJgStateMachine;
NsbmdModel gJgMain;
NsbmdModel gJgCloud;
MtxFx43 gJgMatrix;
MtxFx43 gJgPreviousInverseMatrix;
MtxFx43 gJgInverseMatrix;
JgKindRow gJgKindRows[4];
SegmentProgress gJgSegmentProgress;
Vec3 gJgPoints[8];

#pragma thumb off

#pragma thumb on

void CreateModelAnimation(u32 animationKind, void *model, ModelAnimation **animationSlot, void *nsbmdFile,
                          void *animationFile) {
    *animationSlot = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(**animationSlot));
    InitModelAnimation(animationKind, *animationSlot, model, 1, GetHeap(GetCurrentHeapCall()), nsbmdFile);
    InitModelAnimationEntries(*animationSlot, animationFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(*animationSlot, 0);
}

#pragma thumb off

// Stores the two offset constants and the four offset vectors; every x is negated when gJgStartSideNotFlipped is 0.
void InitJgOffsets(void) {
    gJgOffsetX = 0xf662;
    gJgOffsetY = 0x1232e;
    gJgReverseOffset = gJgReverseBaseOffset;
    gJgReverseOffset.x += 0xf662;
    gJgFlagOffset = gJgFlagBaseOffset;
    gJgFlagOffset.x += 0xf662;
    gJgNoModelOffset = gJgNoModelBaseOffset;
    gJgNoModelOffset.x += 0xf662;

    gJgLapOffset = GetEntryRaceEnded() ? gJgLapBaseOffsetRaceEnded : gJgLapBaseOffsetNotEnded;
    gJgLapOffset.x += gJgOffsetX;
    if (gJgStartSideNotFlipped == 0) {
        gJgReverseOffset.x = -gJgReverseOffset.x;
        gJgFlagOffset.x = -gJgFlagOffset.x;
        gJgLapOffset.x = -gJgLapOffset.x;
        gJgNoModelOffset.x = -gJgNoModelOffset.x;
    }
    gJgNoModelOffset.y += gJgOffsetY;
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

    if (AdvanceSegmentProgress(&gJgSegmentProgress) != FALSE) {
        do {
            for (index = 0; index < 4; index++) {
                gJgPointPointers[index] += 1;
                if (gJgPointPointers[index] > &gJgPoints[7]) {
                    gJgPointPointers[index] = gJgPoints;
                }
            }
        } while (BuildNextSegmentProgress(&gJgSegmentProgress, 0, gJgPointPointers) != FALSE);
    }
    GetSegmentProgressPoint(&gJgSegmentProgress, &pathPoint);
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

// Unless staff roll or no kart: while not Off updates the animation, matrix and position; advances the state machine;
// while Off (not in Battle) starts Arrive at goal or a new lap and Reverse after more than 60 frames against a
// checkpoint.
void UpdateJg(void) {
    s32 lap;
    u32 kartFlags;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (gJgKart == NULL) {
        return;
    }
    if (gJgStateMachine.mState != JG_STATE_OFF) {
        gJgTableIndex++;
        if (gJgTableIndex >= JG_TABLE_LENGTH) {
            gJgTableIndex = 0;
        }
        if (gJgKind != JG_KIND_NONE) {
            JgKindRow *kindRow = &gJgKindRows[gJgKind];
            if (gJgKind != JG_KIND_LAP_COUNT && gJgKind != JG_KIND_LAP_FINAL) {
                if (kindRow->mNsbcaAnimation != NULL) {
                    AdvanceModelAnimation(kindRow->mNsbcaAnimation);
                }
                if (kindRow->mNsbmaAnimation != NULL) {
                    AdvanceModelAnimation(kindRow->mNsbmaAnimation);
                }
            }
        }
        if (gJgStateMachine.mState != JG_STATE_FOLLOW_KART &&
            (gJgStateMachine.mState != JG_STATE_LEAVE || gJgKind != JG_KIND_NONE)) {
            gJgKartPos = gJgKart->mPos;
            gJgKartPos.y -= gJgKart->mHopHeight;
        }
        ComputeJgMatrixAndInverse();
        UpdateJgPosition();
    }
    AdvanceStateMachine(&gJgStateMachine);
    if (gJgStateMachine.mState != JG_STATE_OFF) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN &&
        gRaceProgress->mKarts[gJgKartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED &&
        (gJgKart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) == 0) {
        Vec3 targetOffset;
        gJgMain.mFrameIndex = JG_GOAL_FRAME_INDEX;
        gJgKartPos = gJgKart->mPos;
        gJgKartPos.y -= gJgKart->mHopHeight;
        ComputeJgMatrixAndInverse();
        targetOffset = gJgFlagOffset;
        targetOffset.x += gJgShiftX;
        MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
        gJgKind = JG_KIND_FLAG;
        if (GetEntryRaceEnded() == 0) {
            if ((u32) gJgKind <= JG_KIND_LAP_FINAL) {
                gJgLapKindActive = 1;
                gJgSnapUntilPushFlip = 1;
            }
        }
        SetStateMachineState(&gJgStateMachine, JG_STATE_ARRIVE);
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
                gJgKind = JG_KIND_LAP_FINAL;
                if (GetEntryRaceEnded() == 0) {
                    if ((u32) gJgKind <= JG_KIND_LAP_FINAL) {
                        gJgLapKindActive = 1;
                        gJgSnapUntilPushFlip = 1;
                    }
                }
                SetStateMachineState(&gJgStateMachine, JG_STATE_ARRIVE);
                return;
            }
            gJgKind = JG_KIND_LAP_COUNT;
            if (GetEntryRaceEnded() == 0) {
                if ((u32) gJgKind <= JG_KIND_LAP_FINAL) {
                    gJgLapKindActive = 1;
                    gJgSnapUntilPushFlip = 1;
                }
            }
            SetStateMachineState(&gJgStateMachine, JG_STATE_ARRIVE);
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
        gJgCheckpointFlagFrames++;
        if (gJgCheckpointFlagFrames <= 0x3c) {
            return;
        }
        gJgKartPos = gJgKart->mPos;
        gJgKartPos.y -= gJgKart->mHopHeight;
        ComputeJgMatrixAndInverse();
        SetStateMachineState(&gJgStateMachine, JG_STATE_REVERSE);
        return;
    }
    gJgCheckpointFlagFrames = 0;
}

// Draws the cloud, gJgMain and the model gJgKind selects; counts gJgAlpha up to 0x1f while visible.
void DrawJg(void) {
    s32 modeProjection, modePositionVector, restoreIndex, popCount, noPopCount, modeProjectionEnd, popCountEnd,
        modePositionVectorEnd;
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
        case JG_KIND_REVERSE:
        case JG_KIND_FLAG:
            kindModel = gJgKindRows[gJgKind].mModel;
            break;
        case JG_KIND_LAP_COUNT:
        case JG_KIND_LAP_FINAL:
            lapModel = gJgKindRows[gJgKind].mLapModel;
            break;
    }
    SendLight01Color(gJgKartCourseColor);
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
    if (gJgLapKindActive != 0) {
        modeProjection = 0;
        NNS_G3dGeBufferOP_N(0x10, &modeProjection, 1);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        smallScale.x = 0x19a;
        smallScale.y = 0x19a;
        smallScale.z = 0x19a;
        NNS_G3dGeBufferOP_N(0x1b, &smallScale, 3);
        modePositionVector = 2;
        NNS_G3dGeBufferOP_N(0x10, &modePositionVector, 1);
        sentOpening = TRUE;
    }
    restoreIndex = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &restoreIndex, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&gJgEasedPos), 0xc);
    tableOffset.y = gJgCloudOffsetYTable[gJgTableIndex];
    tableOffset.x = 0;
    tableOffset.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &tableOffset, 3);
    baseScale.x = gJgStartSideNotFlipped != 0 ? 0x1666 : -0x1666;
    baseScale.y = 0x1666;
    baseScale.z = 0x1666;
    NNS_G3dGeBufferOP_N(0x1b, &baseScale, 3);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    tableScaleX = gJgCloudScaleXTable[gJgTableIndex];
    tableScaleY = gJgCloudScaleYTable[gJgTableIndex];
    tableScale.x = tableScaleX;
    tableScale.y = tableScaleY;
    tableScale.z = 0;
    NNS_G3dGeBufferOP_N(0x1b, &tableScale, 3);
    QueueNsbmdModelMaterial(&gJgCloud);
    DrawNsbmdModelWithMaxAlpha(&gJgCloud, NULL, 0, 0x1f);
    popCount = 1;
    NNS_G3dGeBufferOP_N(0x12, &popCount, 1);
    mainOffset.x = 0;
    mainOffset.y = 0;
    mainOffset.z = 0xa4;
    NNS_G3dGeBufferOP_N(0x1c, &mainOffset, 3);
    MTX_RotZ33_(&rotation, gJgMainRotationSineTable[gJgTableIndex], gJgMainRotationCosineTable[gJgTableIndex]);
    NNS_G3dGeBufferOP_N(0x1a, &rotation, 9);
    QueueNsbmdModelMaterial(&gJgMain);
    DrawNsbmdModelWithMaxAlpha(&gJgMain, NULL, 0, 0x1f);
    if (kindModel != NULL) {
        if (gJgKind == JG_KIND_FLAG) {
            noPopCount = 0;
            NNS_G3dGeBufferOP_N(0x12, &noPopCount, 1);
            NNS_G3dDraw(&kindModel->mRenderObj);
        } else {
            NNS_G3dGeBufferOP_N(0x1c, &gJgModelOffset, 3);
            if (gJgStartSideNotFlipped == 0) {
                mirrorScale1.x = -0x1000;
                mirrorScale1.y = 0x1000;
                mirrorScale1.z = 0x1000;
                NNS_G3dGeBufferOP_N(0x1b, &mirrorScale1, 3);
            }
            NNS_G3dDraw(&kindModel->mRenderObj);
        }
    }
    if (lapModel != NULL) {
        NNS_G3dGeBufferOP_N(0x1c, &gJgModelOffset, 3);
        if (gJgStartSideNotFlipped == 0) {
            mirrorScale2.x = -0x1000;
            mirrorScale2.y = 0x1000;
            mirrorScale2.z = 0x1000;
            NNS_G3dGeBufferOP_N(0x1b, &mirrorScale2, 3);
        }
        QueueNsbmdModelMaterial(lapModel);
        DrawNsbmdModelWithMaxAlpha(lapModel, NULL, 0, 0x1f);
    }
    if (sentOpening != FALSE) {
        modeProjectionEnd = 0;
        NNS_G3dGeBufferOP_N(0x10, &modeProjectionEnd, 1);
        popCountEnd = 1;
        NNS_G3dGeBufferOP_N(0x12, &popCountEnd, 1);
        modePositionVectorEnd = 2;
        NNS_G3dGeBufferOP_N(0x10, &modePositionVectorEnd, 1);
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
    gJgMatrix.mRows[1] = gJgMatrixRow1Source;

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
    MTX_MultVec33(&gJgMatrix.mRows[3], &gJgInverseMatrix.mAxes, &gJgInverseMatrix.mRows[3]);
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

// Steers gJgPos toward gJgTargetPos (damped, pushed out of map objects and the course); snaps in FollowKart or hidden,
// and in x/z while the snap flags are on.
void UpdateJgPosition(void) {
    s64 distanceSquared;
    s32 deltaZ;
    s32 deltaX;

    if (gJgStateMachine.mState == JG_STATE_FOLLOW_KART || gJgVisible == 0) {
        gJgProbeCenter = gJgTargetPos;
        gJgPreviousCollisionCenter = gJgProbeCenter;
        gJgCollisionCenter = gJgPreviousCollisionCenter;
        gJgPreviousPos = gJgCollisionCenter;
        gJgPos = gJgPreviousPos;
        gJgKartMove.x = 0;
        gJgKartMove.y = 0;
        gJgKartMove.z = 0;
        gJgVelocity.x = 0;
        gJgVelocity.y = 0;
        gJgVelocity.z = 0;
        gJgProbeStep = 0;
        gJgShiftSpeedX = 0;
        gJgShiftX = 0;
        gJgHeightOffsetSpeed = 0;
        gJgHeightOffset = 0;
        gJgEasedPos = gJgPos;
        gJgInView = 1;
        gJgNearKart = 1;
        gJgReverseAngleActive = 0;
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
        if (gJgStateMachine.mState == JG_STATE_ARRIVE || gJgStateMachine.mState == JG_STATE_LAP) {
            previousPos = NULL;
        } else {
            previousPos = &gJgPreviousCollisionCenter;
        }
        gJgPreviousCollisionCenter = gJgCollisionCenter;
        if (gJgStartSideNotFlipped != 0) {
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
        gJgCourseHitBits = 0;
        if (gJgLapKindActive == 0) {
            if (gJgNearKart != 0 || gJgInView != 0) {
                FindCollisionSlotsAroundPos(&gJgCollisionCenter, 0x12000, 0x2000);
                for (slotIndex = 0; slotIndex < gFoundCollisionSlotCount; slotIndex++) {
                    MapObject *foundObject = gFoundCollisionSlotObjects[slotIndex];

                    if ((foundObject->mFlags & MAP_OBJECT_FLAG_NOT_COLLIDABLE) == 0 &&
                        IsSphereHittingMapObject(&gJgCollisionCenter, 0x12000, foundObject, &offsetVec) != FALSE) {
                        UpdateJgPosition_inline(&pushMin, &offsetVec, &pushMin);
                        UpdateJgPosition_inline_2(&pushMax, &offsetVec, &pushMax);
                        pushed = TRUE;
                    }
                }
                if (CollideSphereWithCourse(&gJgCollisionCenter, previousPos, 0, 0x12000, 4, -1, &offsetVec, NULL, NULL,
                                            &gJgCourseHitBits, NULL, NULL, NULL, NULL) != 0) {
                    UpdateJgPosition_inline(&pushMin, &offsetVec, &pushMin);
                    UpdateJgPosition_inline_2(&pushMax, &offsetVec, &pushMax);
                    pushed = TRUE;
                }
            }
        }
        if (pushed != FALSE) {
            if ((gJgCourseHitBits & 0x80000) == 0) {
                gJgReverseAngleActive = 0;
            }
            offsetVec = pushMin;
            VEC_Add(&offsetVec, &pushMax, &offsetVec);
            if (offsetVec.y < 0 && gJgStateMachine.mState == JG_STATE_LEAVE) {
                offsetVec.y = 0;
            }
            VEC_Add(&gJgPos, &offsetVec, &gJgPos);
            VEC_Add(&gJgCollisionCenter, &offsetVec, &gJgCollisionCenter);
        }
        if (gJgLapKindActive == 0) {
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
                gJgVelocityFactorX += 0xc;
                gJgProbeStep = 0xc;
            }
            speed = gJgShiftSpeedX - MUL_FIXED12_NO_ROUND(gJgShiftX, 0x29);
            gJgShiftSpeedX = speed;
            if (gJgShiftX * (s64) speed < 0) {
                gJgShiftSpeedX = speed - MUL_FIXED12_NO_ROUND(speed, 0x19a);
            }
            gJgShiftX += gJgShiftSpeedX;
            if (gJgNearKart == 0) {
                gJgHeightOffsetSpeed += 0xcd;
                gJgHeightOffset += gJgHeightOffsetSpeed;
            } else {
                if (gJgHeightOffset <= 0) {
                    gJgHeightOffset = 0;
                    gJgHeightOffsetSpeed = 0;
                } else {
                    gJgHeightOffset -= gJgHeightOffsetSpeed;
                    gJgHeightOffsetSpeed -= 0xcd;
                }
            }
        }
        gJgPreviousPos = gJgPos;
        if (gJgKart->mState >= KART_STATE_PUSH_FLIP) {
            gJgSnapUntilPushFlip = 0;
        }
        if (gJgLapKindActive != 0 && gJgSnapUntilPushFlip != 0) {
            gJgPos.x = gJgTargetPos.x;
            gJgPos.z = gJgTargetPos.z;
            localVec.x = localVec.z = 0;
            offsetVec.y = gJgTargetPos.y - gJgPos.y;
            offsetVec.y = offsetVec.y + gJgHeightOffset;
        } else {
            gJgVelocityFactorX -= 0x29;
            if (gJgVelocityFactorX > gJgVelocityFactors.x) {
                gJgVelocityFactorX = gJgVelocityFactors.x;
            }
            if (gJgVelocityFactorX < 0x7b) {
                gJgVelocityFactorX = 0x7b;
            }
            VEC_Subtract(&gJgTargetPos, &gJgPos, &offsetVec);
            offsetVec.y += gJgHeightOffset;
            localVec.x = Vec3DotUnrounded(&offsetVec, &gJgMatrix.mRows[0]);
            localVec.z = Vec3DotUnrounded(&offsetVec, &gJgMatrix.mRows[2]);
            gJgVelocity.x = MUL_FIXED12_NO_ROUND(gJgVelocityFactorX, localVec.x);
            gJgVelocity.z += MUL_FIXED12_NO_ROUND(gJgVelocityFactors.z, localVec.z) -
                             MUL_FIXED12_NO_ROUND(gJgVelocityDamping.z, gJgVelocity.z);
            normalVec.x = Vec3DotUnrounded(&gJgKartMove, &gJgMatrix.mRows[0]);
            normalVec.z = Vec3DotUnrounded(&gJgKartMove, &gJgMatrix.mRows[2]);
            gJgVelocity.x -= normalVec.x;
            gJgVelocity.z -= normalVec.z;
            if (gJgInView != 0 || gJgNearKart != 0) {
                limitX = gJgReverseAngleActive != 0 ? 0x1000 : 0x800;
                if (gJgVelocity.x > limitX) {
                    gJgVelocity.x = limitX;
                } else if (gJgVelocity.x < -limitX) {
                    gJgVelocity.x = -limitX;
                }
                limitZ = gJgReverseAngleActive != 0 ? 0x2000 : 0x1000;
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
        gJgVelocity.y = gJgVelocity.y + (MUL_FIXED12_NO_ROUND(gJgVelocityFactors.y, offsetVec.y) -
                                         MUL_FIXED12_NO_ROUND(gJgVelocityDamping.y, gJgVelocity.y));
        localVec.y = gJgVelocity.y;
        VEC_Add(&gJgPos, &localVec, &gJgPos);
        VEC_Subtract(&gJgPos, &gJgEasedPos, &normalVec);
        VEC_MultAdd(0xd9a, &normalVec, &gJgEasedPos, &gJgEasedPos);
    }
    if (gJgVisible == 0) {
        return;
    }
    gJgInView = (ComputeTwoPlaneViewTest(&gJgPos, 0x12000, 0x708000, 0x5f592e1, 0x1f) & 3) == 0 ? 1 : 0;
    deltaX = gJgPos.x - gJgMatrix.mRows[3].x;
    deltaZ = gJgPos.z - gJgMatrix.mRows[3].z;
    distanceSquared = SQUARE_SUM2(deltaX, deltaZ);
    gJgNearKart = distanceSquared < 0x57e4000000LL ? 1 : 0;
    if (gJgNearKart != 0) {
        gJgFarFromKart = 0;
        return;
    }
    gJgFarFromKart = distanceSquared >= 0x3d090000000LL ? 1 : 0;
}

void EnterJgOff(void *stateObject) {
    gJgKind = 4;
    gJgVisible = 0;
    gJgCheckpointFlagFrames = 0;
    gJgLapKindActive = 0;
    gJgSnapUntilPushFlip = 0;
}

void JgOffNop(void *stateObject) {}

void EnterJgReverse(void *stateObject) {
    ModelAnimation *animation;
    s32 rotatedZ;

    // Written through a cast: a plain store changes the test below.
    *(s32 *) &gJgKind = JG_KIND_REVERSE;
    gJgVisible = 1;
    gJgCheckpointFlagFrames = 0;
    gJgLapKindActive = 0;
    gJgSnapUntilPushFlip = 0;
    gJgTableIndex = 0;
    if (gJgKind != JG_KIND_NONE) {
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
    gJgPointPointers[0] = &gJgPoints[7];
    gJgPointPointers[1] = gJgPoints;
    gJgPointPointers[2] = &gJgPoints[1];
    gJgPointPointers[3] = &gJgPoints[2];
    InitSegmentProgress(&gJgSegmentProgress, 0, gJgPointPointers, 0x1ec);
    gJgAngle = 0;
    rotatedZ = MUL_FIXED12_NO_ROUND(gJgReverseOffset.z, COS_OF_ANGLE(0x8000)) -
               MUL_FIXED12_NO_ROUND(gJgReverseOffset.x, SIN_OF_ANGLE(0x8000));
    gJgStateCounter = 0x8000;
    gJgTargetPos.z = rotatedZ;
    if (rotatedZ > 0) {
        gJgTargetPos.z = rotatedZ * 3;
    }
    gJgTargetPos.x = MUL_FIXED12_NO_ROUND(gJgReverseOffset.z, SIN_OF_ANGLE(0x8000)) +
                     MUL_FIXED12_NO_ROUND(gJgReverseOffset.x, COS_OF_ANGLE(0x8000));
    gJgTargetPos.y = gJgReverseOffset.y;
    MTX_MultVec43(&gJgTargetPos, &gJgMatrix, &gJgTargetPos);
    gJgProbeCenter = gJgTargetPos;
    gJgPreviousCollisionCenter = gJgProbeCenter;
    gJgCollisionCenter = gJgPreviousCollisionCenter;
    gJgPreviousPos = gJgCollisionCenter;
    gJgPos = gJgPreviousPos;
    gJgKartMove.x = 0;
    gJgKartMove.y = 0;
    gJgKartMove.z = 0;
    gJgVelocity.x = 0;
    gJgProbeStep = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    gJgShiftSpeedX = 0;
    gJgShiftX = 0;
    gJgHeightOffsetSpeed = 0;
    gJgEasedPos = gJgPos;
    gJgHeightOffset = 0;
    gJgInView = 1;
    gJgNearKart = 1;
    gJgReverseAngleActive = 0;
}

void UpdateJgReverse(void *stateObject) {
    ModelAnimation *animation;
    s32 angle;
    u32 frame;
    s32 anglePair0;
    s32 anglePair1;
    s32 rotatedZ;
    NNSSndSeqPlayer **seqPlayer;
    s32 scaledZ;
    enum { FRAME_START } frameFixed;

    animation = gJgKindRows[gJgKind].mNsbmaAnimation;
    frameFixed = animation->mHead.mFrameIndex;
    angle = gJgStateCounter;
    frame = ((u32) frameFixed << 4) >> 16;
    if (angle > 0 && angle < 0x10000) {
        anglePair0 = SIN_OF_ANGLE(angle);
        anglePair1 = COS_OF_ANGLE(angle);
        scaledZ = MUL_FIXED12_NO_ROUND(gJgReverseOffset.z, anglePair1);
        rotatedZ = scaledZ - MUL_FIXED12_NO_ROUND(gJgReverseOffset.x, anglePair0);
        gJgTargetPos.z = rotatedZ;
        if (rotatedZ > 0) {
            gJgTargetPos.z = rotatedZ * 3;
        }
        gJgTargetPos.x =
            MUL_FIXED12_NO_ROUND(gJgReverseOffset.z, anglePair0) + MUL_FIXED12_NO_ROUND(gJgReverseOffset.x, anglePair1);
        gJgTargetPos.y = gJgReverseOffset.y;
        MTX_MultVec43(&gJgTargetPos, &gJgMatrix, &gJgTargetPos);
        if (gJgStartSideNotFlipped != 0) {
            gJgStateCounter -= 0xf0;
        } else {
            gJgStateCounter += 0xf0;
        }
        gJgVelocityFactorX = gJgVelocityFactors.x;
        gJgReverseAngleActive = 1;
    } else {
        gJgReverseAngleActive = 0;
        AdvanceJgPointsAndSetTarget(&gJgReverseOffset, &gJgReverseEndScale, &gJgReverseStartScale);
        if (gJgInView == 0 && gJgNearKart == 0) {
            SetStateMachineState(&gJgStateMachine, JG_STATE_REVERSE);
        }
    }
    if (frame == 0xa || frame == 0x28) {
        seqPlayer = GetSndHandleSlot(4);
        gJgSoundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&gJgPos);
        NNS_SndPlayerStopSeq(seqPlayer, 0);
        StartSndHandleSound(&gJgSoundStartParams, seqPlayer);
    }
    if (IsKartEnded(gJgKartIndex) != 0 || (gJgKart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) != 0) {
        SetStateMachineState(&gJgStateMachine, JG_STATE_LEAVE);
        return;
    }
    if ((gRaceProgress->mKarts[gJgKartIndex].mFlags & RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT) == 0) {
        if (++gJgCheckpointFlagFrames > 0x3c) {
            SetStateMachineState(&gJgStateMachine, JG_STATE_LEAVE);
            return;
        }
    } else {
        gJgCheckpointFlagFrames = 0;
    }
    if ((gJgKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) == 0) {
        return;
    }
    SetStateMachineState(&gJgStateMachine, JG_STATE_LEAVE);
}

void EnterJgLap(void *stateObject) {
    Vec3 targetOffset;

    if (gJgHighestLap != gJgFinalLap) {
        gJgKindRows[0].mLapModel->mFrameIndex = gJgHighestLap - 2;
    }
    gJgStateCounter = 0;
    targetOffset = gJgLapOffset;
    targetOffset.x += gJgShiftX;
    MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
}

void UpdateJgLap(void *stateObject) {
    Vec3 targetOffset;

    targetOffset = gJgLapOffset;
    targetOffset.x += gJgShiftX;
    MTX_MultVec43(&targetOffset, &gJgMatrix, &gJgTargetPos);
    if (++gJgStateCounter > gJgLapFrameCount || (gJgKart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) != 0) {
        SetStateMachineState(&gJgStateMachine, JG_STATE_LEAVE);
    }
}

void EnterJgFlag(void *stateObject) {
    gJgPointPointers[0] = &gJgPoints[7];
    gJgPointPointers[1] = gJgPoints;
    gJgPointPointers[2] = &gJgPoints[1];
    gJgPointPointers[3] = &gJgPoints[2];
    InitSegmentProgress(&gJgSegmentProgress, 0, gJgPointPointers, 0x1ec);
    gJgAngle = 0;
    AdvanceJgPointsAndSetTarget(&gJgFlagOffset, &gJgFlagEndScale, &gJgFlagStartScale);
}

void UpdateJgFlag(void *stateObject) {
    AdvanceJgPointsAndSetTarget(&gJgFlagOffset, &gJgFlagEndScale, &gJgFlagStartScale);
    if ((gJgKart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) == 0) {
        return;
    }
    SetStateMachineState(&gJgStateMachine, JG_STATE_LEAVE);
}

void EnterJgFollowKart(void *stateObject) {
    ModelAnimation *animation;
    NNSSndSeqPlayer **seqPlayer;
    MtxFx43 *matrix;

    gJgCheckpointFlagFrames = 0;
    // Written through a cast: a plain store changes the test below.
    *(s32 *) &gJgKind = JG_KIND_NONE;
    gJgVisible = 1;
    gJgAlpha = 0x1f;
    gJgLapKindActive = 0;
    gJgSnapUntilPushFlip = 0;
    gJgTableIndex = 0;
    if (gJgKind != JG_KIND_NONE) {
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
    gJgStateCounter = 0;
    if (GetEntryRaceEnded() != 0) {
        matrix = GetViewRotatedMatrix();
        matrix->mRows[3] = gJgKartPos;
        MTX_MultVec43(&gJgNoModelOffset, matrix, &gJgTargetPos);
    } else {
        MTX_MultVec43(&gJgNoModelOffset, &gJgMatrix, &gJgTargetPos);
    }
    gJgProbeCenter = gJgTargetPos;
    gJgPreviousCollisionCenter = gJgProbeCenter;
    gJgCollisionCenter = gJgPreviousCollisionCenter;
    gJgPreviousPos = gJgCollisionCenter;
    gJgPos = gJgPreviousPos;
    gJgKartMove.x = 0;
    gJgKartMove.y = 0;
    gJgKartMove.z = 0;
    gJgVelocity.x = 0;
    gJgProbeStep = 0;
    gJgShiftSpeedX = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    gJgShiftX = 0;
    gJgHeightOffsetSpeed = 0;
    gJgHeightOffset = 0;
    gJgEasedPos = gJgPos;
    gJgInView = 1;
    gJgNearKart = 1;
    gJgReverseAngleActive = 0;
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

void UpdateJgFollowKart(void *stateObject) {
    MtxFx43 *matrix;

    if (gJgStateCounter == 0) {
        gJgKartPos = gJgKart->mPos;
    } else if (--gJgStateCounter <= 0) {
        gJgMain.mFrameIndex = 0;
        SetStateMachineState(&gJgStateMachine, JG_STATE_LEAVE);
    }
    if (GetEntryRaceEnded() != 0) {
        matrix = GetViewRotatedMatrix();
        matrix->mRows[3] = gJgKartPos;
        MTX_MultVec43(&gJgNoModelOffset, matrix, &gJgTargetPos);
    } else {
        MTX_MultVec43(&gJgNoModelOffset, &gJgMatrix, &gJgTargetPos);
    }
}

void EnterJgLeave(void *stateObject) {
    s32 initialSpeed;

    gJgVisible = 1;
    MTX_MultVec43(&gJgTargetPos, &gJgPreviousInverseMatrix, &gJgLeaveLocalTargetPos);
    gJgLeaveHeightOffset = 0;
    initialSpeed = 0;
    if ((gJgKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) == 0) {
        initialSpeed = 0xffffbccd;
    }
    gJgLeaveSpeed = initialSpeed;
}

void UpdateJgLeave(void *stateObject) {
    s32 acceleration;

    MTX_MultVec43(&gJgLeaveLocalTargetPos, &gJgMatrix, &gJgTargetPos);
    if ((gJgKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) != 0) {
        acceleration = 0x2000;
    } else {
        acceleration = 0x800;
    }
    gJgLeaveSpeed += acceleration;
    gJgLeaveHeightOffset += gJgLeaveSpeed;
    gJgTargetPos.y += gJgLeaveHeightOffset;
    if (gJgLeaveHeightOffset <= 0x5dc000) {
        return;
    }
    if (gJgInView != 0) {
        return;
    }
    NNS_SndPlayerStopSeq(GetSndHandleSlot(4), 1);
    SetStateMachineState(&gJgStateMachine, JG_STATE_OFF);
}

void EnterJgArrive(void *stateObject) {
    ModelAnimation *animation;
    s32 step;
    s32 heightOffset;
    s32 frameIndex;
    s32 clampedStep;

    gJgVisible = 1;
    gJgTableIndex = 0;
    if (gJgKind != JG_KIND_NONE) {
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
    MTX_MultVec43(&gJgTargetPos, &gJgPreviousInverseMatrix, &gJgArriveLocalTargetPos);
    for (frameIndex = 0, step = 0, heightOffset = 0; frameIndex < 0x1e; frameIndex++) {
        clampedStep = (step > -0x3000) ? -0x3000 : step;
        heightOffset -= clampedStep;
        step += 0x19a;
    }
    gJgTargetPos.y += heightOffset;
    gJgProbeCenter = gJgTargetPos;
    gJgPreviousCollisionCenter = gJgProbeCenter;
    gJgCollisionCenter = gJgPreviousCollisionCenter;
    gJgArriveHeightOffset = heightOffset;
    gJgPreviousPos = gJgCollisionCenter;
    gJgArriveSpeed = step;
    gJgPos = gJgPreviousPos;
    gJgKartMove.x = 0;
    gJgKartMove.y = 0;
    gJgKartMove.z = 0;
    gJgVelocity.x = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    gJgProbeStep = 0;
    gJgShiftSpeedX = 0;
    gJgShiftX = 0;
    gJgHeightOffsetSpeed = 0;
    gJgHeightOffset = 0;
    gJgEasedPos = gJgPos;
    gJgInView = 1;
    gJgNearKart = 1;
    gJgReverseAngleActive = 0;
}

// Lowers the target from above; when the height reaches 0 it picks LAP (kinds 0, 1), FLAG (kind 3) or LEAVE.
void UpdateJgArrive(void *stateObject) {
    s32 clampedStep;
    s32 heightOffset;

    MTX_MultVec43(&gJgArriveLocalTargetPos, &gJgMatrix, &gJgTargetPos);
    gJgArriveSpeed -= 0x19a;
    clampedStep = gJgArriveSpeed;
    if (clampedStep > -0x3000) {
        clampedStep = -0x3000;
    }
    heightOffset = gJgArriveHeightOffset + clampedStep;
    gJgArriveHeightOffset = heightOffset;
    gJgTargetPos.y += heightOffset;
    if (heightOffset <= 0) {
        switch (gJgKind) {
            case JG_KIND_LAP_COUNT:
            case JG_KIND_LAP_FINAL:
                SetStateMachineState(&gJgStateMachine, JG_STATE_LAP);
                break;
            case JG_KIND_FLAG:
                SetStateMachineState(&gJgStateMachine, JG_STATE_FLAG);
                break;
            default:
                SetStateMachineState(&gJgStateMachine, JG_STATE_LEAVE);
                break;
        }
    }
    gJgVelocityFactorX = gJgVelocityFactors.x;
}
