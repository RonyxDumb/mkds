#include "Main/Item/item_teresa_offset.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/state_machine_init.h"
#include "Main/Net/slot_result_pending.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Course/course_color_blend.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/Item/item_object.h"
#include "Main/Item/item_f_box.h"
#include "Main/Item/item_gesso.h"
#include "Main/Item/item_pool.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/Item/item_model.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Item/entry_kart_sound.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/segment_progress_point.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"
#include "Main/Item/item_in_use.h"
#include "01/MapObjects/periodic_effect.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "ITCM/collision_slots.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u8 gItemTeresaBattleKartOrder[16] = {4, 3, 1, 6, 7, 5, 0, 2, 4, 3, 1, 6, 7, 5, 0, 2};
const u16 gItemTeresaPickWeights[8] = {0x64, 0x4b, 0x32, 0x1e, 0x14, 0xa, 5, 0};
const ItemInfo gItemInfoTeresa = {
    1, 1, 0xb, 1, 0, 1, (void (*)(struct ItemInUse *, struct HeldItem *)) TeresaMarkItemInUseAsActiveItem};
const Vec3 gItemTeresaItemOffsets[4] = {
    {0x29, 0x47b, 0x29}, {-1556, 0x19a, 0x29}, {0x148, 0x75c, 0x29}, {-737, -819, 0x29}};
const Vec3 gItemTeresaPathPoints[11] = {
    {0x8000, 0x1800, 0x4b000},  {0x6000, 0x1800, 0x3e000},  {0x2000, 0xccd, 0x26000},  {-12288, 0xa66, 0x22000},
    {-32768, 0x800, 0x24000},   {-12288, 0x8cd, 0x27000},   {0x2000, 0x99a, 0x26000},  {0xc000, 0xccd, 0x26000},
    {0x14000, 0x1000, 0x2d000}, {0x20000, 0x1000, 0x41000}, {0x20000, 0x1000, 0x4b000}};
const ItemKind gItemKindTeresa = {0x274,
                                  2,
                                  1,
                                  -1,
                                  -1,
                                  NULL,
                                  (void (*)(void *)) ResetItemTeresa,
                                  NULL,
                                  NULL,
                                  (s32(*)(void *, void *)) InitItemTeresa,
                                  (void (*)(ItemObject *)) AdvanceItemTeresa,
                                  (void (*)(void *, void *, void *)) DrawItemTeresa,
                                  ComputeViewTest,
                                  NULL,
                                  NULL,
                                  (void (*)(void *)) ResetItemTeresaOwnerActiveItem,
                                  0,
                                  0,
                                  (void *(*) (void *, void *, s32)) CopyItemTeresaData,
                                  0,
                                  (void (*)(void *)) InitItemTeresaFromData,
                                  1,
                                  NULL,
                                  0x4b0000,
                                  2,
                                  0x319a,
                                  0,
                                  0,
                                  0x1000,
                                  0x14cd,
                                  0x333,
                                  0x11f,
                                  0,
                                  0,
                                  0,
                                  {0},
                                  1,
                                  1,
                                  1,
                                  1,
                                  1,
                                  0};
StateCallbacks gItemTeresaStateTable[7] = {{EnterItemTeresaFadeOutAtOwner, UpdateItemTeresaFadeOutAtOwner},
                                           {EnterItemTeresaWaitPickedKart, UpdateItemTeresaWaitPickedKart},
                                           {EnterItemTeresaFadeInAtPicked, UpdateItemTeresaFadeInAtPicked},
                                           {EnterItemTeresaTakeItem, UpdateItemTeresaTakeItem},
                                           {EnterItemTeresaWaitDelay, UpdateItemTeresaWaitDelay},
                                           {EnterItemTeresaFadeInAtOwner, UpdateItemTeresaFadeInAtOwner},
                                           {EnterItemTeresaFadeOutEnd, UpdateItemTeresaFadeOutEnd}};

void TeresaMarkItemInUseAsActiveItem(ItemInUse *itemInUse) {
    itemInUse->mIsActiveItem = TRUE;
}

void ResetItemTeresa(ItemTeresa *teresa) {
    const StateCallbacks *stateTable;
    teresa->mItemInfoIndex = ITEM_INFO_NONE;
    teresa->mItemCount = 0;
    stateTable = gItemTeresaStateTable;
    teresa->mFollowsPath = 0;
    teresa->mItemObjectKind = ITEM_TERESA_KIND_EMPTY;
    InitStateMachine(&teresa->mStateMachine, stateTable, 7, teresa);
    teresa->mPickedKartIndex = ITEM_TERESA_NO_KART;
    teresa->mFollowEnded = 0;
    FreeItemObjectCollisionSlot(&teresa->mItemObject);
    teresa->mActsLocally = 0;
    teresa->mPendingPickedKartIndex = ITEM_TERESA_NO_PENDING_PICK;
    teresa->mTakenItemInfoIndex = ITEM_TERESA_NOT_RECEIVED;
    teresa->mTakenItemCount = ITEM_TERESA_COUNT_NOT_RECEIVED;
    teresa->mGivenItemInfoIndex = ITEM_TERESA_NOT_RECEIVED;
    teresa->mGivenItemCount = ITEM_TERESA_COUNT_NOT_RECEIVED;
    teresa->mReportedState = ITEM_TERESA_STATE_NONE;
    teresa->mDelayTimer = 0;
    teresa->mStalled = 0;
    teresa->mStallFrames = 0;
}

static inline u32 ItemTeresaNextRandomBelow_inline(RandomState64 *random, u32 range) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (range == 0) {
        return random->mValue >> 32;
    }
    return ((random->mValue >> 32) * range) >> 32;
}

static inline s32 IsItemTeresaTargetKart_inline(KartItems *kartItems, RaceSetup *raceSetup, s32 teamIndex,
                                                u16 kartIndex) {
    KartItems *entry;
    Kart *kart;
    BOOL isTarget;
    s32 flag;

    flag = 1;
    isTarget = TRUE;
    entry = &kartItems[kartIndex];
    kart = entry->mKart;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mEntryFlags & KART_ENTRY_REMOVED_OR_PARKED) == 0) {
        isTarget = FALSE;
    }
    if (isTarget == FALSE && (kart->mEffectFlags & (KART_EFFECT_RESPAWN_DROP | KART_EFFECT_KILLER)) == 0) {
        flag = 0;
    }
    if (flag | ((kart->mEffectFlags & KART_EFFECT_STAR) ? 1 : 0)) {
        isTarget = FALSE;
    } else if (teamIndex != -1 && teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
        isTarget = FALSE;
    } else {
        isTarget = FALSE;
        if (entry->mHeldItem.mItemInfoIndex != ITEM_INFO_NONE && entry->mHeldItem.mObjectStartFramesLeft == 0) {
            isTarget = entry->mHeldItem.mItemInfoIndex != ITEM_INFO_TERESA;
        }
    }
    return isTarget;
}

void PickItemTeresaKartByRank(ItemTeresa *teresa, s32 teamIndex) {
    u16 cumulativeWeights[7];
    u16 candidateKarts[7];
    u32 kartCount;
    RaceProgress *raceProgress;
    u32 rankBehind;
    u16 kartIndex;
    u16 randomValue;
    RandomState64 *random;
    u16 index;
    s32 candidateCount;
    u16 weightSum;
    const u16 *weightCursor;
    u32 rankAhead;
    KartItems *kartItemsBehindFirst;
    RaceSetup *raceSetupBehindFirst;
    KartItems *kartItems;
    RaceSetup *raceSetup;

    kartCount = gRaceSetup->mKartCount;
    weightSum = candidateCount = 0;
    weightCursor = gItemTeresaPickWeights;
    rankBehind = rankAhead =
        GetKartRank((u16) ((teresa->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0
                               ? (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)
                               : ITEM_NO_KART_INDEX));
    if (teresa->mPicksAheadFirst != FALSE) {
        raceProgress = gRaceProgress;
        kartItems = gKartItems;
        raceSetup = gRaceSetup;
        do {
            if (rankAhead > 1) {
                rankAhead = (u16) (rankAhead - 1);
                kartIndex = GetKartAtRank(rankAhead);
                if (IsItemTeresaTargetKart_inline(kartItems, raceSetup, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
            if (rankBehind < kartCount) {
                rankBehind = (u16) (rankBehind + 1);
                kartIndex = GetKartAtRank(rankBehind);
                if (IsItemTeresaTargetKart_inline(kartItems, raceSetup, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
        } while (rankBehind < kartCount || rankAhead > 1);
    } else {
        raceProgress = gRaceProgress;
        kartItemsBehindFirst = gKartItems;
        raceSetupBehindFirst = gRaceSetup;
        do {
            if (rankBehind < kartCount) {
                rankBehind = (u16) (rankBehind + 1);
                kartIndex = GetKartAtRank(rankBehind);
                if (IsItemTeresaTargetKart_inline(kartItemsBehindFirst, raceSetupBehindFirst, teamIndex, kartIndex) !=
                    0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
            if (rankAhead > 1) {
                rankAhead = (u16) (rankAhead - 1);
                kartIndex = GetKartAtRank(rankAhead);
                if (IsItemTeresaTargetKart_inline(kartItemsBehindFirst, raceSetupBehindFirst, teamIndex, kartIndex) !=
                    0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
        } while (rankBehind < kartCount || rankAhead > 1);
    }
    random = &raceProgress->mRandom;
    randomValue = weightSum == 0 ? 0 : ItemTeresaNextRandomBelow_inline(random, weightSum);
    for (index = 0; index < candidateCount; index++) {
        if (randomValue < cumulativeWeights[index]) {
            teresa->mPickedKartIndex = candidateKarts[index];
            return;
        }
    }
}

void PickItemTeresaKartBattle(ItemTeresa *teresa, s32 teamIndex) {
    RaceProgress *raceProgress;
    RandomState64 *random;
    s32 endIndex;
    s32 rowIndex;
    u32 kartCount;
    s32 skippedKartIndex;
    KartItems *kartItems;
    RaceSetup *raceSetup;
    s32 kartIndex;
    KartItems *entry;
    Kart *kart;
    s32 isTarget;
    s32 flag;
    const u8 *row;

    raceProgress = gRaceProgress;
    random = &raceProgress->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    raceSetup = gRaceSetup;
    rowIndex = (u16) (((u64) (u32) (random->mValue >> 32) * 8) >> 32);
    endIndex = rowIndex + 8;
    kartCount = raceSetup->mKartCount;
    skippedKartIndex = (u16) ((teresa->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0
                                  ? (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)
                                  : ITEM_NO_KART_INDEX);
    if (rowIndex >= endIndex) {
        return;
    }
    kartItems = gKartItems;
    row = &gItemTeresaBattleKartOrder[rowIndex];
    do {
        kartIndex = *row;
        if (kartIndex < kartCount && kartIndex != skippedKartIndex) {
            entry = &kartItems[kartIndex];
            kart = entry->mKart;
            flag = isTarget = 1;
            if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mEntryFlags & KART_ENTRY_REMOVED_OR_PARKED) == 0) {
                flag = 0;
            }
            if (flag == 0 && (kart->mEffectFlags & (KART_EFFECT_RESPAWN_DROP | KART_EFFECT_KILLER)) == 0) {
                isTarget = 0;
            }
            if (isTarget | ((kart->mEffectFlags & KART_EFFECT_STAR) ? 1 : 0)) {
                isTarget = 0;
            } else if (teamIndex != -1 && teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                isTarget = 0;
            } else {
                isTarget = 0;
                if (entry->mHeldItem.mItemInfoIndex != ITEM_INFO_NONE && entry->mHeldItem.mObjectStartFramesLeft == 0) {
                    isTarget = entry->mHeldItem.mItemInfoIndex != ITEM_INFO_TERESA;
                }
            }
            if (isTarget != 0) {
                teresa->mPickedKartIndex = kartIndex;
                return;
            }
        }
        rowIndex++;
        row++;
    } while (rowIndex < endIndex);
}

void InitItemTeresa(ItemInUse *inUse, ItemTeresa *teresa) {
    Kart *kart;

    kart = inUse->mKart;
    StartKartTeresa(kart);
    StartEntryKartSound(kart, 0xf6);
    SetActiveItem(inUse->mKartItems, 0x10);
    InitCourseColorBlend(&teresa->mItemObject.mColorBlend, 1);
    if (inUse->mKartItems->mFlags & KART_ITEMS_DOWN) {
        teresa->mPicksAheadFirst = FALSE;
    } else {
        teresa->mPicksAheadFirst = TRUE;
    }
    SetStateMachineState(&teresa->mStateMachine, ITEM_TERESA_STATE_FADE_OUT_AT_OWNER);
    teresa->mActsLocally = TRUE;
}

void AdvanceItemTeresa(ItemTeresa *teresa) {
    Kart *kart;
    Vec3 *kartDrawMatrixPos;
    Vec3 offset;

    AdvanceStateMachine(&teresa->mStateMachine);
    VEC_Subtract(&teresa->mItemObject.mPos, &teresa->mItemObject.mPrevPos, &teresa->mItemObject.mVelocity);
    if (teresa->mItemObject.mPosPointer != &teresa->mItemObject.mDrawPos) {
        return;
    }
    kart = teresa->mKart;
    if (kart == NULL) {
        return;
    }
    kartDrawMatrixPos = &kart->mDrawMatrixPos;
    VEC_Subtract(&teresa->mItemObject.mPos, kartDrawMatrixPos, &offset);
    MTX_MultVec33(&offset, &GetViewTransposeMatrix()->mAxes, &offset);
    VEC_Add(kartDrawMatrixPos, &offset, &teresa->mItemObject.mDrawPos);
}

void PlaceItemTeresaAtKart(ItemTeresa *teresa, s32 shiftAlongCameraSide) {
    Kart *kart;
    Vec3 *position;
    Camera *camera;
    Vec3 *cameraSide;
    s32 delta[3];
    s32 flag;
    BOOL isTarget;
    s32 easeFactor;
    s32 maxOffsetChange;
    s32 sideDistance;
    s32 scaledRadius;

    kart = teresa->mKart;
    camera = GetCurrentCamera();
    position = &teresa->mItemObject.mPos;
    flag = isTarget = TRUE;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mEntryFlags & KART_ENTRY_REMOVED_OR_PARKED) == 0) {
        flag = 0;
    }
    if (flag == 0 && (kart->mEffectFlags & (KART_EFFECT_RESPAWN_DROP | KART_EFFECT_KILLER)) == 0) {
        isTarget = FALSE;
    }
    if (isTarget != FALSE) {
        if (teresa->mFollowEnded == FALSE && (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) &&
            teresa->mActsLocally != FALSE) {
            teresa->mFollowEnded = TRUE;
            AddItemDataItemIdAndBytes(ITEM_OBJECT_KIND_TERESA, teresa->mItemObject.mId, ITEM_TERESA_PACKET_STATE,
                                      teresa->mStateMachine.mState & 0xff);
        } else {
            teresa->mFollowEnded = TRUE;
        }
    }
    ((Vec3 *) delta)->x = position->x - (&teresa->mItemObject.mVelocity)->x;
    delta[2] = position->z - (&teresa->mItemObject.mVelocity)->z;
    if (teresa->mFollowEnded != FALSE) {
        VEC_Add(&teresa->mKartDrawMatrixPos, &teresa->mKartVelocity, &teresa->mKartDrawMatrixPos);
        teresa->mKartVelocity.x = MUL_FIXED12_NO_ROUND(teresa->mKartVelocity.x, 0xeb8);
        teresa->mKartVelocity.y = MUL_FIXED12_NO_ROUND(teresa->mKartVelocity.y, 0xeb8);
        teresa->mKartVelocity.z = MUL_FIXED12_NO_ROUND(teresa->mKartVelocity.z, 0xeb8);
        *position = teresa->mKartDrawMatrixPos;
    } else {
        *position = kart->mDrawMatrixPos;
        VEC_Subtract(position, &teresa->mKartDrawMatrixPos, &teresa->mKartVelocity);
        teresa->mKartDrawMatrixPos = *position;
        position->y -= kart->mHopHeight;
    }
    VEC_Add(position, &teresa->mOffset, position);
    cameraSide = &camera->mSide;
    if (teresa->mFollowsPath != FALSE) {
        easeFactor = 0xccd;
        maxOffsetChange = 0x800;
    } else {
        easeFactor = 0x800;
        maxOffsetChange = 0x400;
    }
    if (shiftAlongCameraSide != 0) {
        scaledRadius = MUL_FIXED12_ROUNDED(kart->mPhysicalParam->mRadius, kart->mScale.z);
        position->x += MUL_FIXED12_NO_ROUND(-scaledRadius, cameraSide->x);
        position->z += MUL_FIXED12_NO_ROUND(-scaledRadius, cameraSide->z);
    }
    delta[0] -= position->x;
    delta[2] -= position->z;
    sideDistance = DOT2_FIXED12(cameraSide->x, delta[0], cameraSide->z, delta[2]);
    delta[0] = MUL_FIXED12_NO_ROUND(cameraSide->x, sideDistance);
    delta[2] = MUL_FIXED12_NO_ROUND(cameraSide->z, sideDistance);
    delta[0] = MUL_FIXED12_NO_ROUND(delta[0], easeFactor);
    delta[2] = MUL_FIXED12_NO_ROUND(delta[2], easeFactor);
    if (delta[0] > maxOffsetChange) {
        delta[0] = maxOffsetChange;
    } else if (delta[0] < -maxOffsetChange) {
        delta[0] = -maxOffsetChange;
    }
    if (delta[2] > maxOffsetChange) {
        delta[2] = maxOffsetChange;
    } else if (delta[2] < -maxOffsetChange) {
        delta[2] = -maxOffsetChange;
    }
    teresa->mOffsetX = delta[0] + (s32) teresa->mOffsetX;
    teresa->mOffsetZ = delta[2] + (s32) teresa->mOffsetZ;
}

void EnterItemTeresaFadeOutAtOwner(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    teresa->mKart = GetKart((u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK));
    teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
    teresa->mKartVelocity = teresa->mKart->mVelocity;
    teresa->mOffset =
        (Vec3){0, MUL_FIXED12_ROUNDED(teresa->mKart->mPhysicalParam->mRadius, teresa->mKart->mScale.z), 0};
    teresa->mOffsetVelocityY = 0;
    teresa->mItemObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    if (teresa->mKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) {
        teresa->mItemObject.mPosPointer = &teresa->mItemObject.mDrawPos;
    }
}

void AdvanceItemTeresaPath(ItemTeresa *teresa) {
    Vec3 targetOffset;
    Vec3 pathPoint;
    Vec3 *viewAxis0;

    if (teresa->mPointIndex >= ITEM_TERESA_PATH_POINT_COUNT) {
        return;
    }
    if (AdvanceSegmentProgress(&teresa->mPathSegmentPoints.mSegmentProgress) != FALSE) {
        do {
            teresa->mPointIndex++;
            if (teresa->mPointIndex >= ITEM_TERESA_PATH_POINT_COUNT) {
                return;
            }
        } while (PushSegmentPoint(&teresa->mPathSegmentPoints, &gItemTeresaPathPoints[teresa->mPointIndex]) != 0);
    }
    GetSegmentProgressPoint(&teresa->mPathSegmentPoints.mSegmentProgress, &pathPoint);
    SetSegmentProgressRate(&teresa->mPathSegmentPoints.mSegmentProgress, pathPoint.y);
    if (teresa->mItemObject.mPosPointer == &teresa->mItemObject.mDrawPos) {
        targetOffset = (Vec3){pathPoint.x};
    } else {
        s32 axisScale = pathPoint.x;

        viewAxis0 = GetViewTransposeMatrixAxis0();
        targetOffset.x = MUL_FIXED12_NO_ROUND(viewAxis0->x, axisScale);
        targetOffset.y = MUL_FIXED12_NO_ROUND(viewAxis0->y, axisScale);
        targetOffset.z = MUL_FIXED12_NO_ROUND(viewAxis0->z, axisScale);
    }
    targetOffset.y += pathPoint.z;
    VEC_Subtract(&targetOffset, &teresa->mOffset, &pathPoint);
    VEC_MultAdd(0x4f6, &pathPoint, &teresa->mOffset, &teresa->mOffset);
}

BOOL AdvanceItemTeresaFadeOut(ItemTeresa *teresa, s32 shiftAlongCameraSide, s32 nextState) {
    s32 stateFrames;
    s32 fadeStartFrame;
    s32 fadeStep;

    stateFrames = teresa->mStateMachine.mStateFrames;
    if (teresa->mFollowsPath != FALSE) {
        fadeStartFrame = -7;
        fadeStep = GetRaceUpdateFramesMod8() > 2;
        AdvanceItemTeresaPath(teresa);
    } else {
        if (nextState < ITEM_TERESA_STATE_FINISHED) {
            teresa->mOffsetVelocityY += 0x133;
            fadeStartFrame = 0x1c;
            fadeStep = 6;
        } else {
            fadeStartFrame = 0x14;
            fadeStep = 2;
            if (teresa->mOffsetVelocityY < 0) {
                teresa->mOffsetVelocityY += 0x2cd;
            } else {
                teresa->mOffsetVelocityY += 0x8f;
            }
        }
        teresa->mOffsetY += teresa->mOffsetVelocityY;
    }
    PlaceItemTeresaAtKart(teresa, shiftAlongCameraSide);
    if (stateFrames > fadeStartFrame) {
        if (teresa->mItemObject.mAlpha > 0) {
            teresa->mItemObject.mAlpha -= fadeStep;
        }
        if (stateFrames >= (teresa->mFollowsPath != FALSE ? 0x37 : 0x28)) {
            if (nextState < ITEM_TERESA_STATE_FINISHED) {
                if (teresa->mStateMachine.mState == ITEM_TERESA_STATE_FADE_OUT_AT_OWNER) {
                    teresa->mSavedOffsetY = teresa->mOffsetY;
                    teresa->mSavedOffsetVelocityY = teresa->mOffsetVelocityY;
                }
                teresa->mStateMachine.mNextState = nextState;
                teresa->mStateMachine.mNextStateRequested = 1;
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 AdvanceItemTeresaFadeIn(ItemTeresa *teresa, s32 shiftAlongCameraSide, s32 nextState) {
    s32 stateFrames;
    u16 factor;

    stateFrames = teresa->mStateMachine.mStateFrames;
    if (teresa->mFollowsPath != FALSE) {
        AdvanceItemTeresaPath(teresa);
    } else if (teresa->mStalled != FALSE) {
        factor = gItemTeresaFrameScales[stateFrames];
        teresa->mOffsetX = MUL_FIXED12_NO_ROUND(teresa->mOffsetX, factor);
        teresa->mOffsetZ = MUL_FIXED12_NO_ROUND(teresa->mOffsetZ, factor);
    } else {
        teresa->mOffsetY += teresa->mOffsetVelocityY;
        teresa->mOffsetVelocityY += 0x133;
        factor = gItemTeresaFrameScales[stateFrames];
        teresa->mOffsetX = MUL_FIXED12_NO_ROUND(teresa->mOffsetX, factor);
        teresa->mOffsetZ = MUL_FIXED12_NO_ROUND(teresa->mOffsetZ, factor);
    }
    PlaceItemTeresaAtKart(teresa, shiftAlongCameraSide);
    if (stateFrames > 7) {
        if (teresa->mItemObject.mAlpha < MAP_OBJECT_ALPHA_MAX) {
            teresa->mItemObject.mAlpha += 6;
        }
        if (stateFrames == 0x27) {
            if (teresa->mFollowsPath == FALSE) {
                teresa->mOffsetVelocityX = teresa->mOffsetX;
                teresa->mOffsetVelocityZ = teresa->mOffsetZ;
            }
        } else if (stateFrames == 0x28) {
            if (teresa->mFollowsPath == FALSE) {
                teresa->mOffsetVelocityX = teresa->mOffsetX - teresa->mOffsetVelocityX;
                teresa->mOffsetVelocityZ = teresa->mOffsetZ - teresa->mOffsetVelocityZ;
            }
            teresa->mStateMachine.mNextState = nextState;
            teresa->mStateMachine.mNextStateRequested = 1;
            teresa->mStalled = FALSE;
        }
    }
    return stateFrames;
}

void UpdateItemTeresaFadeOutAtOwner(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    AdvanceItemTeresaFadeOut(teresa, 0,
                             (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)
                                 ? ITEM_TERESA_STATE_WAIT_PICKED_KART
                                 : ITEM_TERESA_STATE_FADE_IN_AT_PICKED);
    if (!(teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        return;
    }
    if (teresa->mActsLocally != FALSE) {
        return;
    }
    if (teresa->mFollowEnded != FALSE) {
        return;
    }
    if (teresa->mReportedState == ITEM_TERESA_STATE_NONE) {
        return;
    }
    if (teresa->mReportedState == ITEM_TERESA_STATE_FADE_OUT_AT_OWNER ||
        teresa->mReportedState == ITEM_TERESA_STATE_FINISHED) {
        teresa->mFollowEnded = TRUE;
        teresa->mReportedState = ITEM_TERESA_STATE_NONE;
    }
}

void EnterItemTeresaWaitPickedKart(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    if (teresa->mActsLocally == FALSE) {
        return;
    }
    PickItemTeresaKartByRank(teresa, -1);
    AddItemDataItemIdAndBytes(ITEM_OBJECT_KIND_TERESA, teresa->mItemObject.mId, ITEM_TERESA_PACKET_PICKED_KART,
                              teresa->mPickedKartIndex & 0xff);
    teresa->mPendingPickedKartIndex = teresa->mPickedKartIndex;
    teresa->mActsLocally = FALSE;
}

void UpdateItemTeresaWaitPickedKart(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    s32 stateFrames;

    if (teresa->mPendingPickedKartIndex == ITEM_TERESA_NO_PENDING_PICK) {
        return;
    }
    stateFrames = teresa->mStateMachine.mStateFrames;
    if (teresa->mActsLocally == FALSE && stateFrames < 0x28) {
        return;
    }
    teresa->mDelayTimer = stateFrames - 0x28;
    teresa->mPickedKartIndex = teresa->mPendingPickedKartIndex;
    teresa->mStateMachine.mNextState = ITEM_TERESA_STATE_FADE_IN_AT_PICKED;
    teresa->mStateMachine.mNextStateRequested = 1;
}

void EnterItemTeresaFadeInAtPicked(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    s32 *offset;
    Camera *camera;
    RaceSetup *raceSetup;
    void (*pickFunction)(ItemTeresa *, s32);
    int ownerKartIndex;

    offset = &teresa->mOffsetX;
    camera = GetCurrentCamera();
    if (!(teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        raceSetup = gRaceSetup;
        pickFunction = (raceSetup->mMode == MODE_BATTLE) ? PickItemTeresaKartBattle : PickItemTeresaKartByRank;
        if (raceSetup->mUseTeams != 0) {
            if ((teresa->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0) {
                ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK);
            } else {
                ownerKartIndex = ITEM_NO_KART_INDEX;
            }
            pickFunction(teresa, GetCurrentEntry(ownerKartIndex)->mPlayer.mTeamIndex);
            if (teresa->mPickedKartIndex == ITEM_TERESA_NO_KART) {
                pickFunction(teresa, -1);
            }
        } else {
            pickFunction(teresa, -1);
        }
    }
    if (teresa->mItemObject.mPosPointer == &teresa->mItemObject.mDrawPos) {
        teresa->mItemObject.mPos = teresa->mItemObject.mDrawPos;
        teresa->mItemObject.mPosPointer = &teresa->mItemObject.mPos;
    }
    if (teresa->mPickedKartIndex < ITEM_TERESA_NO_KART) {
        teresa->mKart = GetKart(teresa->mPickedKartIndex);
        teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
        teresa->mKartVelocity = teresa->mKart->mVelocity;
        teresa->mFollowEnded = FALSE;
        StartEntryKartSound(teresa->mKart, 0xf4);
        if (teresa->mKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) {
            teresa->mItemObject.mPosPointer = &teresa->mItemObject.mDrawPos;
        }
    }
    offset[0] = MUL_FIXED12_NO_ROUND(camera->mSide.x, -0xa000);
    offset[2] = MUL_FIXED12_NO_ROUND(camera->mSide.z, -0xa000);
    offset[0] += MUL_FIXED12_NO_ROUND(camera->mForward.x, -0x11000);
    offset[2] += MUL_FIXED12_NO_ROUND(camera->mForward.z, -0x11000);
    teresa->mOffsetVelocityY = -teresa->mOffsetVelocityY;
    teresa->mStallFrames = 0;
}

s32 RemoveItemTeresaPickedKartItem(ItemTeresa *teresa) {
    KartItems *pickedKartItems;
    Kart *kart;
    HeldItem *heldItem;
    s32 flag;
    s32 isTarget;
    enum { ITEM_INFO_INDEX_FIRST } itemInfoIndex;

    pickedKartItems = GetKartItems(teresa->mPickedKartIndex);
    kart = pickedKartItems->mKart;
    heldItem = &pickedKartItems->mHeldItem;
    if (heldItem->mItemInfoIndex == ITEM_INFO_NONE || heldItem->mObjectStartFramesLeft != 0) {
        return ITEM_TERESA_KIND_TOOK_NOTHING;
    }
    if (heldItem->mItemInfoIndex == ITEM_INFO_TERESA) {
        return ITEM_TERESA_KIND_TOOK_NOTHING;
    }
    if (teresa->mFollowEnded != FALSE) {
        return ITEM_TERESA_KIND_TOOK_NOTHING;
    }
    flag = isTarget = 1;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mEntryFlags & KART_ENTRY_REMOVED_OR_PARKED) == 0) {
        flag = 0;
    }
    if (flag == 0 && (kart->mEffectFlags & (KART_EFFECT_RESPAWN_DROP | KART_EFFECT_KILLER)) == 0) {
        isTarget = 0;
    }
    if (isTarget | ((kart->mEffectFlags & KART_EFFECT_STAR) ? 1 : 0)) {
        return ITEM_TERESA_KIND_TOOK_NOTHING;
    }
    if (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
        teresa->mItemInfoIndex = heldItem->mItemInfoIndex;
        teresa->mItemCount = heldItem->mObjectCount;
        ResetParticipantHeldItem(((u8 *) gParticipantKartMap)[teresa->mPickedKartIndex & 0xff]);
    } else {
        RemoveHeldItem(heldItem, &teresa->mItemInfoIndex, &teresa->mItemCount);
    }
    StartKartHitReaction(kart);
    itemInfoIndex = teresa->mItemInfoIndex;
    return gItemInfos[itemInfoIndex].mObjectKind;
}

void UpdateItemTeresaFadeInAtPicked(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    u32 framesLeft;
    BOOL receivedItem;

    if (teresa->mPickedKartIndex == ITEM_TERESA_NO_KART) {
        if (teresa->mStateMachine.mStateFrames > ITEM_TERESA_NO_PICK_LIMIT_FRAMES) {
            teresa->mItemObjectKind = ITEM_TERESA_KIND_TOOK_NOTHING;
            teresa->mStateMachine.mNextState = (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)
                                                   ? ITEM_TERESA_STATE_WAIT_DELAY
                                                   : ITEM_TERESA_STATE_FADE_IN_AT_OWNER;
            teresa->mStateMachine.mNextStateRequested = 1;
        }
    } else {
        framesLeft = 0x28 - AdvanceItemTeresaFadeIn(teresa, 1, ITEM_TERESA_STATE_TAKE_ITEM);
        if (teresa->mItemObjectKind == ITEM_TERESA_KIND_EMPTY) {
            if (teresa->mActsLocally != FALSE) {
                if (framesLeft == 0xa) {
                    teresa->mItemObjectKind = RemoveItemTeresaPickedKartItem(teresa);
                    teresa->mItemModelAlpha = 0;
                    if (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
                        AddItemDataItemIdAndBytes(ITEM_OBJECT_KIND_TERESA, teresa->mItemObject.mId,
                                                  ITEM_TERESA_PACKET_TAKEN_ITEM,
                                                  ((teresa->mItemInfoIndex << 2) | teresa->mItemCount) & 0xff);
                    }
                }
            } else if (framesLeft <= 0xa) {
                if (teresa->mTakenItemCount != -1) {
                    teresa->mItemInfoIndex = teresa->mTakenItemInfoIndex;
                    teresa->mItemCount = teresa->mTakenItemCount;
                    teresa->mTakenItemInfoIndex = ITEM_TERESA_NOT_RECEIVED;
                    teresa->mTakenItemCount = -1;
                    if (teresa->mItemInfoIndex == ITEM_INFO_NONE) {
                        teresa->mItemObjectKind = ITEM_TERESA_KIND_TOOK_NOTHING;
                    } else {
                        teresa->mItemObjectKind = gItemInfos[teresa->mItemInfoIndex].mObjectKind;
                        ResetParticipantHeldItem(((u8 *) gParticipantKartMap)[teresa->mPickedKartIndex & 0xff]);
                    }
                    teresa->mItemModelAlpha = 0;
                    receivedItem = TRUE;
                } else {
                    receivedItem = FALSE;
                }
                if (receivedItem == FALSE && framesLeft == 1) {
                    teresa->mStateMachine.mStateFrames--;
                    teresa->mStalled = TRUE;
                    teresa->mStallFrames++;
                    if (teresa->mStallFrames > ITEM_TERESA_STALL_LIMIT_FRAMES) {
                        teresa->mTakenItemInfoIndex = ITEM_INFO_NONE;
                        teresa->mTakenItemCount = 0;
                    }
                }
            }
        }
    }
    if (!(teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        return;
    }
    if (teresa->mActsLocally != FALSE) {
        return;
    }
    if (teresa->mFollowEnded != FALSE) {
        return;
    }
    if (teresa->mReportedState == ITEM_TERESA_STATE_NONE) {
        return;
    }
    if (teresa->mReportedState == ITEM_TERESA_STATE_FADE_IN_AT_PICKED ||
        teresa->mReportedState == ITEM_TERESA_STATE_FINISHED) {
        teresa->mFollowEnded = TRUE;
        teresa->mReportedState = ITEM_TERESA_STATE_NONE;
    }
}

void EnterItemTeresaTakeItem(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    teresa->mOffsetAccelerationY = 0x0u;
}

void UpdateItemTeresaTakeItem(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    if (teresa->mItemModelAlpha < ITEM_OBJECT_ALPHA_OPAQUE) {
        teresa->mItemModelAlpha += 5;
    }
    teresa->mOffsetVelocityX = MUL_FIXED12_NO_ROUND(teresa->mOffsetVelocityX, 0xf85);
    teresa->mOffsetVelocityZ = MUL_FIXED12_NO_ROUND(teresa->mOffsetVelocityZ, 0xf85);
    if (teresa->mStateMachine.mStateFrames == ITEM_TERESA_DIP_START_FRAME) {
        if (teresa->mOffsetAccelerationY == 0) {
            teresa->mOffsetAccelerationY = ITEM_TERESA_TAKE_DROP_ACCELERATION;
            teresa->mStartOffsetVelocityY = teresa->mOffsetVelocityY;
        }
        teresa->mOffsetVelocityY += teresa->mOffsetAccelerationY;
        teresa->mOffsetY += teresa->mOffsetVelocityY;
        PlaceItemTeresaAtKart(teresa, 1);
        if (teresa->mOffsetAccelerationY >= 0 && teresa->mOffsetVelocityY >= teresa->mStartOffsetVelocityY) {
            return;
        }
        teresa->mStateMachine.mStateFrames--;
        if (teresa->mOffsetAccelerationY >= 0) {
            return;
        }
        if (teresa->mOffsetVelocityY < -0xc00) {
            teresa->mOffsetAccelerationY = ITEM_TERESA_TAKE_RISE_ACCELERATION;
            return;
        }
        if (teresa->mOffsetVelocityY <= 0) {
            return;
        }
        if (teresa->mOffsetVelocityY >= -teresa->mOffsetAccelerationY) {
            return;
        }
        StartEntryKartSound(teresa->mKart, 0xf5);
    } else {
        teresa->mOffsetX += teresa->mOffsetVelocityX;
        teresa->mOffsetZ += teresa->mOffsetVelocityZ;
        AdvanceItemTeresaFadeOut(teresa, 1,
                                 (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)
                                     ? ITEM_TERESA_STATE_WAIT_DELAY
                                     : ITEM_TERESA_STATE_FADE_IN_AT_OWNER);
        if (!(teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
            return;
        }
        if (teresa->mActsLocally != FALSE) {
            return;
        }
        if (teresa->mFollowEnded != FALSE) {
            return;
        }
        if (teresa->mReportedState == ITEM_TERESA_STATE_NONE) {
            return;
        }
        if (teresa->mReportedState - ITEM_TERESA_STATE_FADE_IN_AT_PICKED <= 1) {
            teresa->mFollowEnded = TRUE;
            teresa->mReportedState = ITEM_TERESA_STATE_NONE;
        }
    }
}

void EnterItemTeresaWaitDelay(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    teresa->mDelayTimer = ((teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_FROM_DATA) ? 0xf : 0) - teresa->mDelayTimer;
    teresa->mActsLocally = FALSE;
}

void UpdateItemTeresaWaitDelay(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    teresa->mDelayTimer--;
    if (teresa->mDelayTimer >= 0) {
        return;
    }
    teresa->mActsLocally = (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_FROM_DATA) == 0;
    teresa->mStateMachine.mNextState = ITEM_TERESA_STATE_FADE_IN_AT_OWNER;
    teresa->mStateMachine.mNextStateRequested = 1;
}

void SetItemTeresaPosPointerToDrawPos(ItemTeresa *teresa) {
    teresa->mItemObject.mPosPointer = &teresa->mItemObject.mDrawPos;
}

void RestoreItemTeresaPosPointer(ItemTeresa *teresa) {
    if (teresa->mItemObject.mPosPointer == &teresa->mItemObject.mDrawPos) {
        teresa->mItemObject.mPos = teresa->mItemObject.mDrawPos;
        teresa->mItemObject.mPosPointer = &teresa->mItemObject.mPos;
    }
}

void EnterItemTeresaFadeInAtOwner(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    int ownerKartIndex;
    KartItems *ownerKartItems;
    void (*positionFunction)(ItemTeresa *);

    if ((teresa->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0) {
        ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK);
    } else {
        ownerKartIndex = ITEM_NO_KART_INDEX;
    }
    ownerKartItems = GetKartItems(ownerKartIndex);
    teresa->mKart = ownerKartItems->mKart;
    teresa->mFollowEnded = FALSE;
    if (teresa->mActsLocally != FALSE) {
        if (ownerKartItems->mActiveItem == ITEM_INFO_TERESA) {
            teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
            teresa->mKartVelocity = teresa->mKart->mVelocity;
            teresa->mOffsetX = 0;
            teresa->mOffsetZ = 0;
        } else {
            teresa->mFollowEnded = TRUE;
            if (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
                AddItemDataItemIdAndBytes(ITEM_OBJECT_KIND_TERESA, teresa->mItemObject.mId, ITEM_TERESA_PACKET_STATE,
                                          ITEM_TERESA_STATE_FADE_IN_AT_OWNER);
            }
            teresa->mOffsetX = 0;
            teresa->mOffsetZ = 0;
        }
    }
    if (teresa->mItemObjectKind == ITEM_TERESA_KIND_TOOK_NOTHING) {
        InitSegmentPoints(&teresa->mPathSegmentPoints, gItemTeresaPathPoints, gItemTeresaPathPoints[0].y);
        teresa->mPointIndex = ITEM_TERESA_PATH_START_INDEX;
        teresa->mFollowsPath = TRUE;
    } else {
        teresa->mOffsetVelocityY = -teresa->mSavedOffsetVelocityY;
        teresa->mOffsetY = teresa->mSavedOffsetY;
    }
    if (teresa->mFollowEnded == FALSE) {
        StartEntryKartSound(teresa->mKart, 0xf7);
    }
    teresa->mStallFrames = 0;
    positionFunction = (teresa->mKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) ? SetItemTeresaPosPointerToDrawPos
                                                                                  : RestoreItemTeresaPosPointer;
    positionFunction(teresa);
}

void UpdateItemTeresaFadeInAtOwner(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    s32 ownerKartIndex;
    KartItems *ownerKartItems;
    u32 framesLeft;
    BOOL receivedItem;
    s32 startOffsetX;
    s32 startOffsetZ;

    if ((teresa->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0) {
        ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK);
    } else {
        ownerKartIndex = ITEM_NO_KART_INDEX;
    }
    ownerKartItems = GetKartItems(ownerKartIndex);
    if (teresa->mActsLocally != FALSE && ownerKartItems->mActiveItem != ITEM_INFO_TERESA &&
        teresa->mItemCount != -0x40) {
        teresa->mFollowEnded = TRUE;
        if (teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
            AddItemDataItemIdAndBytes(ITEM_OBJECT_KIND_TERESA, teresa->mItemObject.mId, ITEM_TERESA_PACKET_STATE,
                                      ITEM_TERESA_STATE_FADE_IN_AT_OWNER);
        }
    } else {
        framesLeft = 0x28 - AdvanceItemTeresaFadeIn(teresa, teresa->mFollowsPath == FALSE ? 1 : 0,
                                                    ITEM_TERESA_STATE_FADE_OUT_END);
        if (framesLeft < 7) {
            if (teresa->mItemModelAlpha > 0) {
                teresa->mItemModelAlpha -= 5;
            }
            if (framesLeft == 1) {
                if (teresa->mActsLocally == FALSE) {
                    if (teresa->mGivenItemCount == -1) {
                        receivedItem = FALSE;
                    } else {
                        teresa->mItemInfoIndex = teresa->mGivenItemInfoIndex;
                        teresa->mItemCount = teresa->mGivenItemCount;
                        teresa->mGivenItemInfoIndex = ITEM_TERESA_NOT_RECEIVED;
                        teresa->mGivenItemCount = -1;
                        receivedItem = TRUE;
                    }
                    if (receivedItem == FALSE) {
                        teresa->mStateMachine.mStateFrames--;
                        teresa->mStalled = TRUE;
                        teresa->mStallFrames++;
                        if (teresa->mStallFrames > ITEM_TERESA_STALL_LIMIT_FRAMES) {
                            teresa->mGivenItemInfoIndex = ITEM_INFO_NONE;
                            teresa->mGivenItemCount = -0x40;
                            teresa->mItemObjectKind = ITEM_TERESA_KIND_EMPTY;
                        }
                        goto skip;
                    }
                }
                ownerKartItems->mActiveItem = ITEM_INFO_NONE;
                if (teresa->mItemInfoIndex != ITEM_INFO_NONE) {
                    if (teresa->mActsLocally == FALSE) {
                        SetParticipantHeldItem(((u8 *) gParticipantKartMap)[ownerKartItems->mKartIndex & 0xff],
                                               teresa->mItemInfoIndex, teresa->mItemCount);
                    } else {
                        SetHeldItemWithCount(&ownerKartItems->mHeldItem, teresa->mItemInfoIndex, teresa->mItemCount);
                    }
                    teresa->mItemInfoIndex = ITEM_INFO_NONE;
                    teresa->mItemCount = -0x40;
                    teresa->mItemObjectKind = ITEM_TERESA_KIND_EMPTY;
                    StartEntryKartSound(ownerKartItems->mKart, 0xf8);
                } else {
                    teresa->mItemCount = -0x40;
                    teresa->mItemObjectKind = ITEM_TERESA_KIND_EMPTY;
                }
                if ((teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) && teresa->mActsLocally != FALSE) {
                    AddItemDataItemIdAndBytes(
                        ITEM_OBJECT_KIND_TERESA, teresa->mItemObject.mId, ITEM_TERESA_PACKET_GIVEN_ITEM,
                        ((ownerKartItems->mHeldItem.mItemInfoIndex << 2) | ownerKartItems->mHeldItem.mObjectCount) &
                            0xff);
                }
            }
        }
    }
skip:
    if (teresa->mFollowsPath == FALSE && teresa->mFollowEnded != FALSE) {
        startOffsetX = teresa->mOffsetX;
        startOffsetZ = teresa->mOffsetZ;
        AdvanceItemTeresaFadeIn(teresa, 1, ITEM_TERESA_STATE_FADE_OUT_END);
        teresa->mOffsetVelocityX = teresa->mOffsetX - startOffsetX;
        teresa->mOffsetVelocityZ = teresa->mOffsetZ - startOffsetZ;
        teresa->mStateMachine.mNextState = ITEM_TERESA_STATE_FADE_OUT_END;
        teresa->mStateMachine.mNextStateRequested = 1;
        teresa->mStalled = FALSE;
    }
    if (!(teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        return;
    }
    if (teresa->mActsLocally != FALSE) {
        return;
    }
    if (teresa->mFollowEnded != FALSE) {
        return;
    }
    if (teresa->mReportedState == ITEM_TERESA_STATE_NONE) {
        return;
    }
    if (teresa->mReportedState == ITEM_TERESA_STATE_FADE_IN_AT_OWNER ||
        teresa->mReportedState == ITEM_TERESA_STATE_FINISHED) {
        teresa->mFollowEnded = TRUE;
        teresa->mReportedState = ITEM_TERESA_STATE_NONE;
    }
}

void EnterItemTeresaFadeOutEnd(void *stateObject) {}

void UpdateItemTeresaFadeOutEnd(void *stateObject) {
    ItemTeresa *teresa = stateObject;
    BOOL hasItem;
    s32 ownerKartIndex;

    hasItem = teresa->mItemInfoIndex != ITEM_INFO_NONE;
    if (teresa->mFollowsPath == FALSE) {
        teresa->mOffsetVelocityX = MUL_FIXED12_NO_ROUND(teresa->mOffsetVelocityX, 0xf85);
        teresa->mOffsetVelocityZ = MUL_FIXED12_NO_ROUND(teresa->mOffsetVelocityZ, 0xf85);
        teresa->mOffsetX += teresa->mOffsetVelocityX;
        teresa->mOffsetZ += teresa->mOffsetVelocityZ;
    }
    if (hasItem != FALSE) {
        if (teresa->mItemModelAlpha < ITEM_OBJECT_ALPHA_OPAQUE) {
            teresa->mItemModelAlpha += 8;
        }
    }
    if (AdvanceItemTeresaFadeOut(teresa, teresa->mFollowsPath == FALSE ? 1 : 0, ITEM_TERESA_STATE_FINISHED) != FALSE) {
        if (hasItem != FALSE) {
            if ((teresa->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0) {
                ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK);
            } else {
                ownerKartIndex = ITEM_NO_KART_INDEX;
            }
            ((void (*)(s32 itemInfoIndex, s32 amount, s32 ownerKartIndex)) RemoveReservedItemObjects)(
                teresa->mItemInfoIndex, teresa->mItemCount, (u16) ownerKartIndex);
        }
        ReleaseItemPoolObject(gItemPools + teresa->mItemObject.mKind, &teresa->mItemObject);
    }
    if (!(teresa->mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        return;
    }
    if (teresa->mActsLocally != FALSE) {
        return;
    }
    if (teresa->mFollowEnded != FALSE) {
        return;
    }
    if (teresa->mReportedState == ITEM_TERESA_STATE_NONE) {
        return;
    }
    if (teresa->mReportedState - ITEM_TERESA_STATE_FADE_IN_AT_OWNER <= 1) {
        teresa->mFollowEnded = TRUE;
        teresa->mReportedState = ITEM_TERESA_STATE_NONE;
    }
}

void ResetItemTeresaOwnerActiveItem(ItemTeresa *teresa) {
    int ownerKartIndex;
    KartItems *ownerKartItems;

    if ((teresa->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0) {
        ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK);
    } else {
        ownerKartIndex = ITEM_NO_KART_INDEX;
    }
    ownerKartItems = GetKartItems(ownerKartIndex);
    if (ownerKartItems->mActiveItem != ITEM_INFO_TERESA) {
        return;
    }
    if (teresa->mItemCount != -0x40) {
        ownerKartItems->mActiveItem = ITEM_INFO_NONE;
    }
}

void CopyItemTeresaData(void *cursor, ItemTeresa *teresa, void *toData) {
    CopyItemObjectData(cursor, teresa, toData);
    if (teresa == NULL) {
        return;
    }
    if (toData == NULL) {
        return;
    }
    AddItemDataSizedByKind(teresa->mItemObject.mKind);
}

void InitItemTeresaFromData(ItemTeresa *teresa) {
    int ownerKartIndex;

    SetupItemObjectFromData(&teresa->mItemObject);
    InitCourseColorBlend(&teresa->mItemObject.mColorBlend, 1);
    SetStateMachineState(&teresa->mStateMachine, ITEM_TERESA_STATE_FADE_OUT_AT_OWNER);
    if ((teresa->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0) {
        ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK);
    } else {
        ownerKartIndex = ITEM_NO_KART_INDEX;
    }
    SetActiveItem(GetKartItems(ownerKartIndex), 0x10);
}

// Selectors: 0 picked kart, 1 reported state, 2 item taken, 3 item given (item index << 2 | count).
void SetItemTeresaFromPacket(ItemTeresa *teresa, u32 sel, s32 value) {
    switch (sel) {
        case ITEM_TERESA_PACKET_PICKED_KART:
            teresa->mPendingPickedKartIndex = value;
            if (teresa->mPendingPickedKartIndex == gRaceSetup->mEntryIndex) {
                teresa->mActsLocally = TRUE;
            }
            break;
        case ITEM_TERESA_PACKET_STATE:
            teresa->mReportedState = value;
            break;
        case ITEM_TERESA_PACKET_TAKEN_ITEM:
            teresa->mTakenItemInfoIndex = value >> 2;
            teresa->mTakenItemCount = value & 3;
            break;
        case ITEM_TERESA_PACKET_GIVEN_ITEM:
            teresa->mGivenItemInfoIndex = value >> 2;
            teresa->mGivenItemCount = value & 3;
            break;
    }
}

void DrawItemTeresa(ItemTeresa *teresa, s32 unusedValue, NsbmdModel *model) {
    s32 commandParam;
    s32 itemModelAlpha;
    s32 secondCommandParam;
    s32 polygonId;
    u16 drawAlpha;
    s32 scale[3];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    NsbmdModel *itemModel;
    s32 index;
    s32 itemCount;

    if (teresa->mItemObject.mAlpha <= 0) {
        return;
    }
    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(teresa->mItemObject.mPosPointer), 0xc);
    scaleZ = teresa->mItemObject.mScale.z;
    scaleY = teresa->mItemObject.mScale.y;
    scaleX = teresa->mItemObject.mScale.x;
    scale[0] = scaleX;
    scale[1] = scaleY;
    scale[2] = scaleZ;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    if (teresa->mItemObjectKind < ITEM_OBJECT_KIND_COUNT &&
        teresa->mStateMachine.mState >= ITEM_TERESA_STATE_TAKE_ITEM) {
        itemModel = GetItemModel(teresa->mItemObjectKind);
        itemModelAlpha = teresa->mItemModelAlpha;
        itemCount = teresa->mItemCount;
        if (teresa->mItemObject.mAlpha < MAP_OBJECT_ALPHA_MAX) {
            if (teresa->mItemObject.mAlpha < itemModelAlpha) {
                itemModelAlpha = teresa->mItemObject.mAlpha;
            }
        }
        if (itemModelAlpha > 0x1f) {
            itemModelAlpha = 0x1f;
        }
        if (itemModelAlpha < 1) {
            itemModelAlpha = 1;
        }
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        itemModel->mPolygonAttributes = itemModel->mPolygonAttributes & ~POLYGON_ATTR_ALPHA_MASK;
        itemModel->mPolygonAttributes =
            itemModel->mPolygonAttributes | ((u16) itemModelAlpha << POLYGON_ATTR_ALPHA_SHIFT);
        QueueNsbmdModelMaterial(itemModel);
        index = 0;
        itemModel->mFrameIndex = 0;
        while (index < itemCount) {
            NNS_G3dGeBufferOP_N(0x1c, &gItemTeresaItemOffsets[itemCount == 2 ? 1 - index : index + 1], 3);
            polygonId = AllocPolygonIdWrapping();
            itemModel->mPolygonAttributes = itemModel->mPolygonAttributes & ~POLYGON_ATTR_ID_MASK;
            itemModel->mPolygonAttributes = itemModel->mPolygonAttributes | (polygonId << POLYGON_ATTR_ID_SHIFT);
            DrawNsbmdModelWithMaxAlpha(itemModel, &teresa->mItemObject.mPos, 1, 0x1f);
            index++;
        }
        secondCommandParam = 1;
        NNS_G3dGeBufferOP_N(0x12, &secondCommandParam, 1);
        if (itemModelAlpha != 0x1f) {
            itemModel->mPolygonAttributes = itemModel->mPolygonAttributes & ~POLYGON_ATTR_ALPHA_MASK;
            itemModel->mPolygonAttributes = itemModel->mPolygonAttributes | POLYGON_ATTR_ALPHA_MASK;
        }
    }
    polygonId = AllocPolygonIdWrapping();
    model->mPolygonAttributes = model->mPolygonAttributes & ~POLYGON_ATTR_ID_MASK;
    model->mPolygonAttributes = model->mPolygonAttributes | (polygonId << POLYGON_ATTR_ID_SHIFT);
    drawAlpha = teresa->mItemObject.mAlpha;
    model->mPolygonAttributes = model->mPolygonAttributes & ~POLYGON_ATTR_ALPHA_MASK;
    model->mPolygonAttributes = model->mPolygonAttributes | (drawAlpha << POLYGON_ATTR_ALPHA_SHIFT);
    DrawItemModelAtObjectPos(&teresa->mItemObject, model);
}

s32 GetTeresaOffsetYDivisor(void) {
    return 0x3bf60u;
}
