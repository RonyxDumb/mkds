#include "Main/Item/item_koura_w.h"
#include "code_02012b30.h"

#include "Main/System/heap.h"
#include "Main/MapObjects/rock.h"
#include "Main/Item/item_links.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Item/data_027e0000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/karts.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_kinds_init.h"
#include "Main/Item/held_item.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Item/code_020f9334.h"
#include "Main/Item/item_gesso.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/Item/code_020f6be8.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Item/item_koura_w_kart_items.h"
#include "Main/Item/item_f_box.h"
#include "Main/Sound/sound_start.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01fff000.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "Main/Sound/sound_system.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/kart_items_update.h"
#include "Main/System/state_machine_init.h"
#include "Main/Race/race.h"
#include "Main/Kart/camera.h"
#include "Main/Graphics/model_effects.h"
#include "Main/Kart/kart_ai_item_throw.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Item/code_020f73fc.h"
#include "Main/Item/item_object.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/data_0210b000.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Course/course_color_blend.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "fx_mtx43.h"
#include "Main/Item/item_koura_w_far.h"
#include "ITCM/collision_slots.h"
#include "Main/Item/item_kinoko_p_boost.h"
#include "Main/Item/item_owner_bit_and_normal.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

const u16 gItemObjectNoOwnerBit = ITEM_OWNER_NO_OWNER;
const ItemInfo gItemInfoKouraW = {1, 1, 5, 1, 0, 1, (void (*)(ItemInUse *, HeldItem *)) MarkItemInUseAsActiveItem};
const ItemKind gItemKindKouraW = {0x31c,
                                  1,
                                  1,
                                  -1,
                                  -1,
                                  SetupItemKouraWKind,
                                  (void (*)(void *)) ResetItemKouraW,
                                  NULL,
                                  NULL,
                                  (s32(*)(void *, void *)) InitItemKouraW,
                                  (void (*)(ItemObject *)) AdvanceItemKouraW,
                                  (void (*)(void *, void *, void *)) DrawItemKouraW,
                                  ComputeTwoPlaneViewTest,
                                  (s32(*)(void *)) RequestItemKouraWBurst,
                                  NULL,
                                  NULL,
                                  0,
                                  0,
                                  (void *(*) (void *, void *, s32)) CopyItemKouraWData,
                                  0,
                                  (void (*)(void *)) InitItemKouraWFromData,
                                  1,
                                  GetItemKouraWFarDistanceSquared,
                                  0x960000,
                                  2,
                                  0x319a,
                                  0x6000,
                                  0x2e66,
                                  0x1000,
                                  0x1ccd,
                                  0x52,
                                  0xa4,
                                  0,
                                  1,
                                  1,
                                  {1, 0, 0, 0},
                                  3,
                                  1,
                                  1,
                                  1,
                                  7,
                                  0};
Vec3 gKouraWVec3UnitY = {0, 0x1000, 0};
StateCallbacks gItemKouraWStateTable[ITEM_KOURA_W_STATE_COUNT] = {
    {NULL, UpdateItemKouraWStraight},
    {NULL, UpdateItemKouraWPickTarget},
    {NULL, UpdateItemKouraWFollowLink},
    {EnterItemKouraWSteerToTarget, UpdateItemKouraWSteerToTarget},
    {EnterItemKouraWCircleTarget, UpdateItemKouraWCircleTarget},
    {EnterItemKouraWRise, UpdateItemKouraWRise},
    {EnterItemKouraWFall, UpdateItemKouraWFall},
    {EnterItemKouraWBurst, UpdateItemKouraWBurst}};
Nsbmd *gKouraW;
s32 gKouraWBurstScaleStep;
s32 gKouraWBurstInverseLimit;
s32 gKouraWBurstScaleLimit;
volatile s32 gKouraWBurstMaxRadiusSquared;
struct ItemObject **gCollidedItemObjects;

void MarkItemInUseAsActiveItem(ItemInUse *itemInUse) {
    itemInUse->mIsActiveItem = TRUE;
}

void ResetItemKouraW(ItemKouraW *item) {
    InitStateMachine(&item->mStateMachine, gItemKouraWStateTable, ITEM_KOURA_W_STATE_COUNT, item);
    MTX_Identity43_(&item->mMatrix);
    item->mRank = 1;
    item->mRankKartIndex = gRaceProgress->mKartAtRank[0];
    item->mRankTargetSkipped = 0;
    item->mPosStrip = NULL;
    item->mSoundId = ITEM_KOURA_W_SOUND_ID_DEFAULT;
    item->mKartMask = 0;
    item->mHitSpinsKart = 0;
}

void InitItemKouraWCommon(ItemKouraW *item) {
    ResetSoundDistanceSquaredChange(&item->mSoundDistanceSquaredChange);
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraWSoundTrackParams;
    item->mLinkFollowingItemObject.mDirectedItemObject.mReflectsOnHit = 0;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos =
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
    FreeItemObjectCollisionSlot(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_HITS_FAR_KARTS;
    ClearItemKouraWKartItemsAndAngle(item);
    if (gRaceProgress->mRaceDone != 0) {
        item->mRank = 1;
        item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
    } else {
        item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
        while (IsKartEnded(item->mRankKartIndex) != 0 && item->mRank < (u32) gRaceSetup->mKartCount) {
            item->mRank++;
            item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
        }
    }
    item->mLift = ITEM_KOURA_W_START_LIFT;
    item->mBobAmplitudeOrGain = TO_FIXED12(15);
    item->mDrawOffsetAngle = 0;
    item->mSpeed = ITEM_KOURA_W_START_SPEED;
    item->mSmoothedDirectionDelta.x = 0;
    item->mSmoothedDirectionDelta.y = 0;
    item->mSmoothedDirectionDelta.z = 0;
    VEC_Subtract(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                 &item->mSmoothedDirectionDelta, &item->mPreviousDirection);
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer =
        &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos;
    InitCourseColorBlend(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mColorBlend, 1);
}

void SetItemKouraWKartItemsAndStateIfNone(ItemKouraW *item, s32 kartIndex) {
    Kart *kart;

    if (item->mKartItems != NULL) {
        return;
    }
    SetItemKouraWKartItems(item, kartIndex);
    kart = item->mKartItems->mKart;
    item->mStateMachine.mNextState =
        ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) ||
         (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE))
            ? ITEM_KOURA_W_STATE_FOLLOW_LINK
            : ITEM_KOURA_W_STATE_STEER_TO_TARGET;
    item->mStateMachine.mNextStateRequested = 1;
}

s32 InitItemKouraW(ItemInUse *itemInUse, ItemKouraW *item) {
    Kart *kart;

    StartItemObjectSoundSource(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    if (itemInUse->mKartItems->mItemLink.mLink != NULL) {
        InitLinkFollowingItemFromInUse(&item->mLinkFollowingItemObject, itemInUse, 0x14, 0xcc, 1, 1, 0, 0x6000,
                                       item->mRankKartIndex, 1);
        SetStateMachineState(&item->mStateMachine, ITEM_KOURA_W_STATE_PICK_TARGET);
    } else {
        SetItemKouraWKartItems(item, (u16) gRaceProgress->mKartAtRank[0]);
        kart = item->mKartItems->mKart;
        item->mStateMachine.mNextState = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
                                           ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) ||
                                          (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE))
                                             ? ITEM_KOURA_W_STATE_FOLLOW_LINK
                                             : ITEM_KOURA_W_STATE_STEER_TO_TARGET;
        item->mStateMachine.mNextStateRequested = 1;
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
            AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_W, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
    }
    InitItemKouraWCommon(item);
    // one 36-byte copy of the three vectors (three Vec3 assignments give 0x160 bytes against 0x150)
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mAxes = itemInUse->mKartOrientation;
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
        item->mStateMachine.mNextState = ITEM_KOURA_W_STATE_STRAIGHT;
        item->mStateMachine.mNextStateRequested = 1;
    }
    return 1;
}

void UpdateItemKouraWDrawPos(ItemKouraW *item) {
    Vec3 buf;
    s16 angleFactor;
    s32 liftOffset;

    liftOffset = item->mLift;
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) {
        item->mDrawOffsetAngle += 0x5dc;
        angleFactor = FX_SinIdx(item->mDrawOffsetAngle);
        VEC_MultAdd(liftOffset + MUL_FIXED12_NO_ROUND(item->mBobAmplitudeOrGain, angleFactor),
                    &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal,
                    &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos, &buf);
        VEC_Subtract(&buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos, &buf);
        VEC_MultAdd(0x333, &buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos,
                    &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos);
    } else {
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.y +=
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y >> 1;
        item->mDrawOffsetAngle += 0x5dc;
        angleFactor = FX_SinIdx(item->mDrawOffsetAngle);
        liftOffset += MUL_FIXED12_NO_ROUND(item->mBobAmplitudeOrGain, angleFactor);
        liftOffset = liftOffset + item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.y -
                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.y;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.y +=
            MUL_FIXED12_NO_ROUND(liftOffset, 0x19a);
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.x =
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.x;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.z =
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.z;
    }
}

void UpdateItemKouraWOrientation(ItemKouraW *item, Vec3 *direction, s32 followDelta, Vec3 *normal) {
    Vec3 buf;
    Vec3 tiltedDirection;
    Vec3 *previousDirection = &item->mPreviousDirection;
    Vec3 *smoothedDelta = &item->mSmoothedDirectionDelta;
    s32 ok;

    if (normal != NULL) {
        if (LENGTH_SQUARED(*direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(
                direction, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2]);
        }
        smoothedDelta->x = MUL_FIXED12_NO_ROUND(smoothedDelta->x, 0xccd);
        smoothedDelta->y = MUL_FIXED12_NO_ROUND(smoothedDelta->y, 0xccd);
        smoothedDelta->z = MUL_FIXED12_NO_ROUND(smoothedDelta->z, 0xccd);
        VEC_MultAdd(0x3000, smoothedDelta, normal, &buf);
        Vec3CrossUnrounded(&buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2],
                           &buf);
        if (LENGTH_SQUARED(buf) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(
                &buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0]);
        }
    } else {
        if (LENGTH_SQUARED(*direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(direction, &buf);
        }
        if (buf.x * buf.x + buf.z * buf.z < 0x112510) {
            return;
        }
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2] = buf;
        if (followDelta != 0) {
            smoothedDelta->x += MUL_FIXED12_NO_ROUND(direction->x - previousDirection->x - smoothedDelta->x, 0x148);
            smoothedDelta->z += MUL_FIXED12_NO_ROUND(direction->z - previousDirection->z - smoothedDelta->z, 0x148);
        } else {
            smoothedDelta->x = MUL_FIXED12_NO_ROUND(smoothedDelta->x, 0xc00);
            smoothedDelta->z = MUL_FIXED12_NO_ROUND(smoothedDelta->z, 0xc00);
        }
        tiltedDirection = gKouraWVec3UnitY;
        tiltedDirection.x = MUL_FIXED12_NO_ROUND(smoothedDelta->x, 0x3000);
        tiltedDirection.z = MUL_FIXED12_NO_ROUND(smoothedDelta->z, 0x3000);
        buf = tiltedDirection;
        Vec3CrossUnrounded(&buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2],
                           &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0]);
        if ((s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].x *
                    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].x +
                (s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].y *
                    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].y +
                (s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].z *
                    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].z >=
            0x10) {
            ok = Vec3NormalizeAndGetLengthUnchecked(
                &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0],
                &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0]);
        } else {
            ok = 0;
        }
        if (ok == 0) {
            Vec3 sideDirection = {0, 0, 0};
            sideDirection.x = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].z;
            sideDirection.z = -item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].x;
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0] = sideDirection;
        }
    }
    Vec3CrossUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2],
                       &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0],
                       &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[1]);
    *previousDirection = *direction;
}

void AdvanceItemKouraW(ItemKouraW *item) {
    AdvanceStateMachine(&item->mStateMachine);
    ClearItemObjectCollisionBits(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0x3c000400u);
}

#pragma thumb off

void UpdateItemKouraWStraight(void *stateObject) {
    ItemKouraW *item = stateObject;
    AdvanceItemObjectMotion((DirectedItemObject *) item, 0xd000);
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(
        &item->mSoundDistanceSquaredChange,
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
    if (item->mSoundId == 1) {
        return;
    }
    StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                             item->mSoundId, 0x7f, 0);
}

static inline Vec3 *GetItemKouraWNormalOrNull(ItemKouraW *item) {
    if (item->mStateMachine.mState >= ITEM_KOURA_W_STATE_STEER_TO_TARGET) {
        if (item->mKartItems->mKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) {
            return &item->mKartItems->mKart->mGroundNormal;
        }
    } else if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
               ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) {
        return &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal;
    }
    return NULL;
}

void UpdateItemKouraWPickTarget(void *stateObject) {
    ItemKouraW *item = stateObject;
    u16 rank;
    s32 value;
    s32 entry;
    void *normal;
    Kart *kart;

    if (item->mStateMachine.mStateFrames == ITEM_KOURA_W_POS_STRIP_FRAME) {
        item->mPosStrip = StartPosStrip(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer);
    }
    AdvanceLinkFollowingItem(&item->mLinkFollowingItemObject, item->mSpeed, 0x21, item->mRankKartIndex, 1);
    if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED)) {
        AdvanceSoundDistanceSquaredChange(
            &item->mSoundDistanceSquaredChange,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                                     item->mSoundId, 0x7f, 0);
        }
    }
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y -=
        MUL_FIXED12_NO_ROUND(item->mLinkFollowingItemObject.mDirectedItemObject.mSpeed, 0x66);
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    UpdateItemKouraWDrawPos(item);
    normal = GetItemKouraWNormalOrNull(item);
    UpdateItemKouraWOrientation(item, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity, 1,
                                normal);
    if (item->mRankTargetSkipped == 0) {
        if (gRaceProgress->mRaceDone != 0) {
            item->mRank = 1;
            item->mRankKartIndex = GetKartAtRank(item->mRank);
        } else {
            item->mRankKartIndex = GetKartAtRank(item->mRank);
            while (IsKartEnded(item->mRankKartIndex) != 0 && (u32) item->mRank < gRaceSetup->mKartCount) {
                (item->mRank)++;
                item->mRankKartIndex = GetKartAtRank(item->mRank);
            }
        }
        if (item->mRankKartIndex ==
                (u16) (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                         0x8000)
                           ? (u16) (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject
                                        .mOwnerKartIndexAndFlags &
                                    ~ITEM_OWNER_FLAGS_MASK)
                           : ITEM_NO_KART_INDEX) ||
            IsKartRemoved(GetKart(item->mRankKartIndex)) != 0) {
            item->mRankTargetSkipped = 1;
        } else {
            item->mKartMask |= 1 << item->mRankKartIndex;
        }
    }
    if (item->mRankTargetSkipped != 0) {
        u32 kartCount;
        kartCount = (u8) gRaceSetup->mKartCount;
        for (rank = 1; rank <= kartCount; rank++) {
            item->mRankKartIndex = GetKartAtRank(rank);
            if (IsKartRemoved(GetKart(item->mRankKartIndex)) == 0) {
                break;
            }
        }
        item->mKartMask |= 1 << item->mRankKartIndex;
    }
    if (TrySetItemKouraWKartItems(item, item->mRankKartIndex) != 0) {
        kart = item->mKartItems->mKart;
        value = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
                  ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) ||
                 (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE))
                    ? ITEM_KOURA_W_STATE_FOLLOW_LINK
                    : ITEM_KOURA_W_STATE_STEER_TO_TARGET;
        item->mStateMachine.mNextState = value;
        item->mStateMachine.mNextStateRequested = 1;
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
            AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_W, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
        return;
    }
    value = (u16) GetRaceUpdateFramesMod8();
    if (BIT_IS_SET(item->mKartMask, value) && item->mRankKartIndex != value && IsKartEnded(value) != 0 &&
        TrySetItemKouraWKartItems(item, value) != 0) {
        kart = item->mKartItems->mKart;
        entry = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
                  ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) ||
                 (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE))
                    ? ITEM_KOURA_W_STATE_FOLLOW_LINK
                    : ITEM_KOURA_W_STATE_STEER_TO_TARGET;
        item->mStateMachine.mNextState = entry;
        item->mStateMachine.mNextStateRequested = 1;
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
            AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_W, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
        return;
    }
    if (item->mStateMachine.mStateFrames <= ITEM_KOURA_W_PICK_TARGET_LIMIT_FRAMES) {
        return;
    }
    entry = (u16) gRaceProgress->mKartAtRank[0];
    if (item->mKartItems != NULL) {
        return;
    }
    if ((u32) entry >= 8) {
        entry = 0;
    }
    SetItemKouraWKartItems(item, (u16) entry);
    kart = item->mKartItems->mKart;
    value =
        ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) ||
         (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE))
            ? ITEM_KOURA_W_STATE_FOLLOW_LINK
            : ITEM_KOURA_W_STATE_STEER_TO_TARGET;
    item->mStateMachine.mNextState = value;
    item->mStateMachine.mNextStateRequested = 1;
}

void EnterItemKouraWSteerToTarget(void *stateObject) {
    ItemKouraW *item = stateObject;
    item->mSpeed = VEC_Mag(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity);
    item->mRadiusOrEaseFactor = TO_FIXED12(30);
    if (item->mKartItems->mKartIndex == gRaceSetup->mEntryIndex) {
        item->mSoundId = ITEM_KOURA_W_SOUND_ID_ENTRY_STEERING;
    }
}

void UpdateItemKouraWSteerToTarget(void *stateObject) {
    ItemKouraW *item = stateObject;
    s32 gain;
    void *normal;
    Kart *kart;

    kart = item->mKartItems->mKart;
    gain = 0x800;
    if ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FROM_DATA) &&
        (kart->mEntryFlags & KART_ENTRY_SELECTED)) {
        gain += 0x19a;
    }
    if (item->mSpeed > ITEM_KOURA_W_CRUISE_SPEED) {
        item->mSpeed -= ITEM_KOURA_W_SPEED_STEP;
    } else {
        item->mSpeed += ITEM_KOURA_W_SPEED_STEP;
    }
    SteerItemKouraWAtAngleZero(item, gain, item->mSpeed, item->mRadiusOrEaseFactor);
    if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED)) {
        AdvanceSoundDistanceSquaredChange(
            &item->mSoundDistanceSquaredChange,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                                     item->mSoundId, 0x7f, 0);
        }
    }
    if (HORIZONTAL_LENGTH_SQUARED(item->mToTarget) < 0x1900000000LL) {
        item->mStateMachine.mNextState = ITEM_KOURA_W_STATE_CIRCLE_TARGET;
        item->mStateMachine.mNextStateRequested = 1;
    }
    UpdateItemKouraWDrawPos(item);
    normal = GetItemKouraWNormalOrNull(item);
    UpdateItemKouraWOrientation(item, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity, 1,
                                normal);
}

void UpdateItemKouraWFollowLink(void *stateObject) {
    ItemKouraW *item = stateObject;
    s32 index;
    void *normal;
    ItemPointLink *link;

    if (item->mSpeed > ITEM_KOURA_W_CRUISE_SPEED) {
        item->mSpeed -= ITEM_KOURA_W_SPEED_STEP;
    } else {
        item->mSpeed += ITEM_KOURA_W_SPEED_STEP;
    }
    AdvanceLinkFollowingItem(&item->mLinkFollowingItemObject, item->mSpeed, 0x21, item->mRankKartIndex, 1);
    if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED)) {
        AdvanceSoundDistanceSquaredChange(
            &item->mSoundDistanceSquaredChange,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                                     item->mSoundId, 0x7f, 0);
        }
    }
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    UpdateItemKouraWDrawPos(item);
    normal = GetItemKouraWNormalOrNull(item);
    UpdateItemKouraWOrientation(item, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity, 1,
                                normal);
    link = item->mKartItems->mItemLink.mLink;
    for (index = 0; index < 4; index++) {
        if (link == item->mLinkFollowingItemObject.mTargetLink.mLink) {
            item->mStateMachine.mNextState = ITEM_KOURA_W_STATE_STEER_TO_TARGET;
            item->mStateMachine.mNextStateRequested = 1;
        }
        link = link->mNextLinks[0];
    }
}

void EnterItemKouraWCircleTarget(void *stateObject) {
    ItemKouraW *item = stateObject;
    item->mBobAmplitudeOrGain = TO_FIXED12(5);
    item->mAngleStep = ITEM_KOURA_W_CIRCLE_START_ANGLE_STEP;
    VEC_Subtract(&item->mToTarget, &item->mSmoothedDirectionDelta, &item->mPreviousDirection);
    if (item->mPosStrip != NULL) {
        StopPosStrip(item->mPosStrip);
        item->mPosStrip = NULL;
    }
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
        AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_W, item->mKartItems->mKartIndex,
                                 item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
    }
}

void UpdateItemKouraWCircleTarget(void *stateObject) {
    ItemKouraW *item = stateObject;
    Vec3 direction;
    void *normal;

    if (item->mSpeed > ITEM_KOURA_W_CRUISE_SPEED) {
        item->mSpeed -= ITEM_KOURA_W_SPEED_STEP;
    } else {
        item->mSpeed += ITEM_KOURA_W_SPEED_STEP;
    }
    item->mLift -= 0xccd;
    item->mAngleStep += 0x2d;
    if ((u32) item->mAngle < ITEM_KOURA_W_CIRCLE_HALF_ANGLE) {
        item->mRadiusOrEaseFactor -= FIXED12_RATIO(2, 5);
    } else {
        item->mRadiusOrEaseFactor -= FIXED12_RATIO(4, 5);
    }
    SteerItemKouraWToNextAnglePoint(item, 0x4cd, item->mSpeed, item->mRadiusOrEaseFactor, item->mAngleStep);
    if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED)) {
        AdvanceSoundDistanceSquaredChange(
            &item->mSoundDistanceSquaredChange,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                                     item->mSoundId, 0x7f, 0);
        }
    }
    UpdateItemKouraWDrawPos(item);
    if ((u32) item->mAngle < ITEM_KOURA_W_CIRCLE_NORMAL_END_ANGLE) {
        normal = GetItemKouraWNormalOrNull(item);
        if (normal != NULL) {
            direction.x = item->mAnglePointOffset.x * 2;
            direction.y = item->mAnglePointOffset.y * 2;
            direction.z = item->mAnglePointOffset.z * 2;
            Vec3CrossUnrounded(normal, &direction, &direction);
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(item->mAngle - 0x10000, 0xccd), normal, &direction, &direction);
        } else {
            direction.x = MUL_FIXED12_NO_ROUND(item->mAnglePointOffset.z, 0x2000);
            direction.y = MUL_FIXED12_NO_ROUND(item->mAngle - 0x10000, 0xccd);
            direction.z = -MUL_FIXED12_NO_ROUND(item->mAnglePointOffset.x, 0x2000);
        }
        if (item->mStateMachine.mStateFrames == 0) {
            VEC_Subtract(&direction, &item->mSmoothedDirectionDelta, &item->mPreviousDirection);
        }
        UpdateItemKouraWOrientation(item, &direction, 1, normal);
        return;
    }
    item->mStateMachine.mNextState = ITEM_KOURA_W_STATE_RISE;
    item->mStateMachine.mNextStateRequested = 1;
}

void EnterItemKouraWRise(void *stateObject) {
    ItemKouraW *item = stateObject;
    enum { KIND_FIRST } kind;

    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer ==
        &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos) {
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos =
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer =
            &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
    }
    item->mLift = ITEM_KOURA_W_HOVER_LIFT;
    item->mBobAmplitudeOrGain = FIXED12_RATIO(1, 5);
    kind = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScaleTargetOrSpeed = gItemKinds[kind].mTargetScale;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_FIXED_SCALE;
    item->mEasedDirection = item->mPreviousDirection;
    item->mSpeed = ITEM_KOURA_W_RISE_START_SPEED;
    item->mRadiusOrEaseFactor = FIXED12_RATIO(7, 20);
}

void UpdateItemKouraWRise(void *stateObject) {
    ItemKouraW *item = stateObject;
    Vec3 targetDirection;
    Vec3 *normal;
    s32 directionX;
    s32 speed;
    s32 directionZ;

    item->mLift += 0x4cd;
    SteerItemKouraWToKartForward(item, item->mBobAmplitudeOrGain, item->mLift);
    if (item->mBobAmplitudeOrGain < FIXED12_RATIO(7, 10)) {
        item->mBobAmplitudeOrGain += FIXED12_RATIO(1, 50);
    }
    if (item->mLift > ITEM_KOURA_W_RISE_LIFT_LIMIT) {
        item->mStateMachine.mNextState = ITEM_KOURA_W_STATE_FALL;
        item->mStateMachine.mNextStateRequested = 1;
    }
    item->mSpeed -= 0xa14;
    item->mRadiusOrEaseFactor -= FIXED12_RATIO(63, 1000);
    if (item->mRadiusOrEaseFactor < FIXED12_RATIO(3, 100)) {
        item->mRadiusOrEaseFactor = FIXED12_RATIO(3, 100);
    }
    normal = GetItemKouraWNormalOrNull(item);
    if (normal != NULL) {
        VEC_MultAdd(item->mSpeed, normal, &item->mKartForward, &targetDirection);
    } else {
        directionZ = item->mKartForward.z;
        speed = item->mSpeed;
        directionX = item->mKartForward.x;
        targetDirection.x = directionX;
        targetDirection.y = speed;
        targetDirection.z = directionZ;
    }
    VEC_Subtract(&targetDirection, &item->mEasedDirection, &targetDirection);
    VEC_MultAdd(item->mRadiusOrEaseFactor, &targetDirection, &item->mEasedDirection, &item->mEasedDirection);
    UpdateItemKouraWOrientation(item, &item->mEasedDirection, 0, normal);
}

void EnterItemKouraWFall(void *stateObject) {
    ItemKouraW *item = stateObject;
    enum { KIND_FIRST } kind;

    item->mLift = ITEM_KOURA_W_HOVER_LIFT;
    kind = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScaleTargetOrSpeed = gItemKinds[kind].mTargetScale;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScaleTargetOrSpeed += 0x800;
    CreateItemObjectCollisionSlotExact(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
}

void UpdateItemKouraWFall(void *stateObject) {
    ItemKouraW *item = stateObject;
    s32 grew;
    Vec3 hitOffset;

    item->mLift -= 0x7000;
    SteerItemKouraWToKartForward(item, 0xb33, item->mLift);
    if (item->mLift < -0x32000) {
        FadeOutEndedItemObject(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0);
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
            AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_W, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
    } else {
        Vec3 *position;

        position = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
        if (CollideSphereWithCourse(position, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPrevPos,
                                    0, item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCourseRadius, 4,
                                    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex,
                                    &hitOffset, NULL, NULL,
                                    &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionBits,
                                    NULL, NULL, NULL, NULL) != 0) {
            VEC_Add(&hitOffset, position, position);
            FadeOutEndedItemObject(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0);
            if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
                AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_W, item->mKartItems->mKartIndex,
                                         item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
            }
        }
    }
    grew = GrowItemObjectScale(
        &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject,
        gItemKinds[item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind].mTargetScale,
        gItemKinds[item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind].mScaleStep);
    if (EaseItemObjectScale(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject) != 0) {
        return;
    }
    if (grew) {
        RefreshItemObjectScale(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    }
}

void EnterItemKouraWBurst(void *stateObject) {
    ItemKouraW *item = stateObject;
    NNSSndSeqPlayer **sndHandle;
    struct ModelEffect *effect;
    Vec3 *effectScale;

    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_FIXED_SCALE;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScaleTargetOrSpeed = 0;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScale = gKouraWBurstStartScale;
    item->mModelEffect = StartModelEffect(
        MODEL_EFFECT_BOMBCORE2, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos,
        IsItemObjectTooFarForEffects(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject) == 0 ? 1 : 0);
    effect = item->mModelEffect;
    if (effect != NULL) {
        effectScale = &effect->mScale;
        effectScale->x = 0x1000;
        effectScale->y = 0x1000;
        effectScale->z = 0x1000;
    }
    StartItemObjectSoundIfNear(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0xdf);
    if (gRaceSoundKind & 1) {
        sndHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
        if (gSoundModeHolder.mSeqStartEnabled != 0) {
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0xe0);
        }
    }
    StartCameraWobbleAtDistance(
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
}

void UpdateItemKouraWBurst(void *stateObject) {
    ItemKouraW *item = stateObject;
    u32 stateFrames;

    stateFrames = item->mStateMachine.mStateFrames;
    if (GrowItemObjectScale(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, gKouraWBurstScaleLimit,
                            gKouraWBurstScaleStep)) {
        RefreshItemObjectScaleExact(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    }
    if (stateFrames < 0x16) {
        return;
    }
    if (stateFrames == 0x16) {
        item->mHitSpinsKart = 1;
    } else if (stateFrames == 0x2a) {
        FreeItemObjectCollisionSlot(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    }
    if (stateFrames <= 0x55) {
        return;
    }
    ReleaseItemPoolObject(&gItemPools[item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind],
                          &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
}

void *CopyItemKouraWData(void *cursor, ItemKouraW *item, void *toData) {
    void *cursorAfterLink;
    void *cursorAfterObject;

    if (item != NULL && toData != NULL) {
        StoreItemDataFlagBit(Vec3DotUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                                              &item->mLinkFollowingItemObject.mDirectedItemObject.mDirection) < 0
                                 ? 1
                                 : 0,
                             &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y);
    }
    cursorAfterObject = CopyItemObjectData(cursor, item, toData);
    cursorAfterLink = CopyItemPointLinkIndex(
        cursorAfterObject, item != NULL ? (void *) &item->mLinkFollowingItemObject.mPreviousLink : 0, toData);
    if (item != NULL && toData == NULL) {
        LoadItemDataFlagBit(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y,
                            &item->mReverse);
    }
    if (item != NULL && toData != NULL) {
        return AddItemDataSizedByKind(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind);
    }
    return cursorAfterLink;
}

void InitItemKouraWFromData(ItemKouraW *item) {
    s32 kartIndex;
    DirectionQuaternion directionQuaternion;
    Kart *kart;
    s32 nextState;

    SetupItemObjectFromData(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    if (item->mLinkFollowingItemObject.mPreviousLink.mLink != NULL) {
        InitLinkFollowingItem(&item->mLinkFollowingItemObject, 0x14, 0xcc, 1, 0, item->mReverse,
                              gRaceProgress->mKartAtRank[0], 1);
        SetStateMachineState(&item->mStateMachine, ITEM_KOURA_W_STATE_PICK_TARGET);
    } else if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
        kartIndex = (u16) gRaceProgress->mKartAtRank[0];
        if (item->mKartItems == NULL) {
            SetItemKouraWKartItems(item, kartIndex);
            kart = item->mKartItems->mKart;
            nextState = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
                          ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) ||
                         (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE))
                            ? ITEM_KOURA_W_STATE_FOLLOW_LINK
                            : ITEM_KOURA_W_STATE_STEER_TO_TARGET;
            item->mStateMachine.mNextState = nextState;
            item->mStateMachine.mNextStateRequested = 1;
        }
    } else {
        kartIndex = (u16) gRaceProgress->mKartAtRank[0];
        SetItemKouraWKartItems(item, kartIndex);
        kart = item->mKartItems->mKart;
        nextState = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
                      ITEM_OBJECT_FLAG_ON_BOOST_SURFACE) ||
                     (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE))
                        ? ITEM_KOURA_W_STATE_FOLLOW_LINK
                        : ITEM_KOURA_W_STATE_STEER_TO_TARGET;
        item->mStateMachine.mNextState = nextState;
        item->mStateMachine.mNextStateRequested = 1;
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
            AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_W, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
    }
    InitItemKouraWCommon(item);
    if ((s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.x *
                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.x +
            (s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y *
                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y +
            (s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.z *
                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                                           &directionQuaternion.mDirection);
    }
    QuaternionFromYAxisToVec3(&directionQuaternion.mDirection, &directionQuaternion.mQuaternion);
    Matrix3x3FromQuaternion(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mAxes,
                            &directionQuaternion.mQuaternion);
}

void DrawItemKouraWModel(ItemKouraW *item, Vec3 *viewAxis, s32 model) {
    u32 alpha;
    Vec3 scale;
    void *matrix;

    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_ACTIVE) {
        if (IsItemObjectFartherFromCameraThan(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0x6a4) !=
            0) {
            return;
        }
    }
    scale.x = scale.z = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScale.x;
    scale.y = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScale.y;
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mAlpha != MAP_OBJECT_ALPHA_MAX) {
        u32 materialIndex;
        NNSG3dResMdl *resMdl;

        resMdl = gKouraW->mResMdl;
        alpha = (u16) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mAlpha;
        for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
            NNS_G3dMdlSetMdlAlpha(resMdl, materialIndex, alpha);
        }
    }
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADING_OUT) {
        matrix = BuildItemObjectMatrix(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, viewAxis);
    } else {
        Vec3 *position;

        position = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[3].x = position->x >> 4;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[3].y = position->y >> 4;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[3].z = position->z >> 4;
        matrix = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx;
    }
    DrawNsbmdWithMatrixAndMaxAlpha(gKouraW, matrix, &scale, 0x1f);
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mAlpha == MAP_OBJECT_ALPHA_MAX) {
        return;
    }
    {
        u32 materialIndex;
        NNSG3dResMdl *resMdl;

        resMdl = gKouraW->mResMdl;
        for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
            NNS_G3dMdlSetMdlAlpha(resMdl, materialIndex, 0x1f);
        }
    }
}

void DrawItemKouraW(ItemKouraW *item, Vec3 *viewAxis, s32 model) {
    ModelEffect *effect;

    if (item->mStateMachine.mState != ITEM_KOURA_W_STATE_BURST) {
        DrawItemKouraWModel(item, viewAxis, model);
        return;
    }
    effect = item->mModelEffect;
    if (effect == NULL) {
        return;
    }
    effect->mVisible =
        (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_OUT_OF_VIEW) == 0;
}

// Asks for state 7 unless the object is already in it; returns 1.
s32 RequestItemKouraWBurst(ItemKouraW *item) {
    if (item->mStateMachine.mState != ITEM_KOURA_W_STATE_BURST) {
        InitStateMachine(&item->mStateMachine, gItemKouraWStateTable, ITEM_KOURA_W_STATE_COUNT, item);
        item->mStateMachine.mNextState = ITEM_KOURA_W_STATE_BURST;
        item->mStateMachine.mNextStateRequested = 1;
        if ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mAdvance =
                (void (*)(struct ItemObject *)) AdvanceItemKouraW;
        }
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &= ~ITEM_OBJECT_FLAG_RESTING;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_FADING_OUT;
        CreateItemObjectCollisionSlotExact(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &= ~ITEM_OWNER_EXCLUDED;
    }
    return 1;
}

BOOL IsItemKouraWBurst(ItemKouraW *item) {
    return item->mStateMachine.mState == ITEM_KOURA_W_STATE_BURST;
}

Vec3 *GetItemKouraWBurstInfo(ItemKouraW *item, s32 *stateFrames, s32 *scaleRatio) {
    *stateFrames = item->mStateMachine.mStateFrames;
    *scaleRatio = MUL_FIXED12_NO_ROUND(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScale.z,
                                       gKouraWBurstInverseLimit);
    return &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
}

#pragma thumb on

void SetupItemKouraWKind(void) {
    s32 scaleLimit;
    s32 radiusRatio;
    s32 maxRadius;

    gKouraWBurstScaleLimit = 0x1e000;
    gKouraWBurstInverseLimit = FX_Div(0x1000, gKouraWBurstScaleLimit);
    gKouraWBurstScaleStep = 0x299a;
    scaleLimit = gKouraWBurstScaleLimit;
    radiusRatio = gItemKinds[5].mRadius;
    maxRadius = MUL_FIXED12_NO_ROUND(scaleLimit, radiusRatio);
    gKouraWBurstMaxRadiusSquared = maxRadius;
    maxRadius >>= 12;
    gKouraWBurstMaxRadiusSquared = maxRadius;
    gKouraWBurstMaxRadiusSquared = maxRadius * maxRadius;
    gKouraW = CreateItemNsbmd("koura_w.nsbmd", "koura_w.nsbtx");
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gKouraW->mResMdl, 0);
    }
}

#pragma thumb off

BOOL IsItemInfoObjectCountFree(s32 itemInfoIndex) {
    if (itemInfoIndex != ITEM_INFO_NONE) {
        return gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mObjectBudget -
                   gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mReservedCount >=
               gItemInfos[itemInfoIndex].mObjectCount;
    }
    return FALSE;
}

static inline BOOL ItemsIsItemInfoObjectCountFree(s32 itemInfoIndex) {
    if (itemInfoIndex != ITEM_INFO_NONE) {
        return gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mObjectBudget -
                   gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mReservedCount >=
               gItemInfos[itemInfoIndex].mObjectCount;
    }
    return FALSE;
}

// Replaces the rolled item by the fallback item when nothing was rolled or no objects are free for it; returns TRUE
// when it did.
BOOL ReplaceUnavailableItem(s32 *itemInfoIndexPointer) {
    s32 itemInfoIndex;
    s32 dataSize;
    ItemInfo *itemInfo;
    s32 objectCount;

    itemInfoIndex = *itemInfoIndexPointer;
    if (itemInfoIndex == ITEM_INFO_NONE) {
        goto done;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        itemInfo = &gItemInfos[itemInfoIndex];
        objectCount = itemInfo->mObjectCount;
        dataSize = objectCount * GetItemDataSize(itemInfo->mObjectKind, 0);
        if (ItemsIsItemInfoObjectCountFree(itemInfoIndex) != FALSE && gWiFiRaceSync->mUnusedItemDataBytes >= dataSize) {
            return FALSE;
        }
    } else {
        if (ItemsIsItemInfoObjectCountFree(itemInfoIndex) != FALSE) {
            return FALSE;
        }
    }
done:
    *itemInfoIndexPointer = gRaceSetup->mMode == MODE_WIFI ? 4 : 2;
    return TRUE;
}

BOOL TryReleaseItemObjectsForItemInfo(s32 itemInfoIndex) {
    ItemInfo *itemInfo;
    s32 objectCount;
    ItemPool *pool;
    enum { KIND_FIRST } kind;

    itemInfo = &gItemInfos[itemInfoIndex];
    kind = itemInfo->mObjectKind;
    pool = &gItemPools[kind];
    objectCount = itemInfo->mObjectCount;
    while (pool->mObjectBudget - pool->mReservedCount < objectCount) {
        if (gItemKinds[kind].mLimit == 1) {
            return FALSE;
        }
        if (TryReleaseFirstItemObject(pool) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void ReleaseItemsAtFinish(void) {
    enum { POOL_INDEX_FIRST } poolIndex;
    u16 kartIndex;

    for (poolIndex = 0; poolIndex < ITEM_OBJECT_KIND_COUNT; poolIndex++) {
        TryReleaseFirstItemObject(&gItemPools[poolIndex]);
    }
    for (kartIndex = 0; kartIndex < gKartItemsCount; kartIndex++) {
        ReleaseKartItems(&gKartItems[kartIndex]);
    }
}

void UpdateItems(void) {
    enum { POOL_INDEX_FIRST } poolIndex;
    u16 kartIndex;

    if (gRaceSetup->mMode == MODE_WIFI) {
        AddQueuedItemData();
        ProcessDelayedItemData();
    }
    for (poolIndex = 0; poolIndex < ITEM_OBJECT_KIND_COUNT; poolIndex++) {
        if (gItemPools[poolIndex].mActiveCount != 0) {
            UpdateItemPool(&gItemPools[poolIndex]);
        }
    }
    for (kartIndex = 0; kartIndex < gKartItemsCount; kartIndex++) {
        UpdateKartItems(&gKartItems[kartIndex]);
    }
    AdvanceItemBlockTimers();
    UpdateOrthoQuads();
    UpdateBouncingItemBoxTimers();
}

void DrawItems(void *unused) {
    enum { POOL_INDEX_FIRST } poolIndex;
    void *viewAxis;

    viewAxis = &GetViewTransposeMatrix()->mRows[2];
    QueueViewMatrix();
    for (poolIndex = 0; poolIndex < ITEM_OBJECT_KIND_COUNT; poolIndex++) {
        if (gItemPools[poolIndex].mTakenCount > 0 && gItemPools[poolIndex].mDrawnByMapObjects == 0) {
            DrawItemPool(&gItemPools[poolIndex], viewAxis);
        }
    }
}

void StartItemSlotForKart(s32 kartIndex, s32 forcedRowHandle, s32 shortSpin) {
    s32 playerKind;
    BOOL isHumanGhostOrPeer;

    if (gKartItems[kartIndex].mHeldItem.mItemInfoIndex != ITEM_INFO_NONE) {
        return;
    }
    playerKind = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if (playerKind == PLAYER_KIND_PEER) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        isHumanGhostOrPeer = FALSE;
        if ((u32) playerKind > 3) {
        } else if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
        StartItemSlot(&gKartItems[kartIndex], forcedRowHandle, GetBattleItemRank(kartIndex), isHumanGhostOrPeer ? 1 : 0,
                      shortSpin);
    } else {
        isHumanGhostOrPeer = FALSE;
        if ((u32) playerKind > 3) {
        } else if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
        StartItemSlot(&gKartItems[kartIndex], forcedRowHandle, GetKartRank(kartIndex), isHumanGhostOrPeer ? 1 : 0,
                      shortSpin);
    }
}

static inline s32 IsItemObjectHitKart(ItemObject *item, Kart *kart) {
    Vec3 previousDelta;
    Vec3 delta;
    s32 previousDistanceSquared;
    s32 distanceSquared;
    s32 radius;
    s32 deltaX;
    s64 fullDistanceSquared;

    if (!(item->mFlags & ITEM_OBJECT_FLAG_RESTING)) {
        return 1;
    }
    if (kart->mIndex != (u16) (!(item->mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER)
                                   ? (u16) (item->mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)
                                   : ITEM_NO_KART_INDEX)) {
        return 1;
    }
    if (item->mVelocity.x != 0 || item->mVelocity.y != 0 || item->mVelocity.z != 0 || kart->mForwardSpeed != 0) {
        VEC_Subtract(&item->mPrevPos, &kart->mPrevPointAlongUp, &previousDelta);
        previousDelta.y = 0;
        VEC_Subtract(&item->mPos, &kart->mPointAlongUp, &delta);
        delta.y = 0;
        previousDistanceSquared = Vec3DotUnrounded(&previousDelta, &previousDelta);
        distanceSquared = Vec3DotUnrounded(&delta, &delta);
        if (previousDistanceSquared - 0x1000 > distanceSquared) {
            return 1;
        }
    }
    radius = item->mRadius;
    deltaX = item->mPos.x - kart->mPointAlongUp.x;
    fullDistanceSquared =
        (s64) (item->mPos.z - kart->mPointAlongUp.z) * (item->mPos.z - kart->mPointAlongUp.z) +
        ((s64) deltaX * deltaX + (s64) (item->mPos.y - kart->mPointAlongUp.y) * (item->mPos.y - kart->mPointAlongUp.y));
    return fullDistanceSquared < (s64) radius * radius ? 1 : 0;
}

// Returns how many item objects hit the kart; GetCollidedItemObject reads them.
s32 CollideKartWithItemObjects(Kart *kart) {
    s32 overlapIndex;
    s32 hitCount;
    BOOL isFarFromEntryKart;
    s32 isHit;
    s32 hitCountCap;
    ItemObject *item;
    enum { KIND_FIRST } kind;

    hitCount = 0;
    isFarFromEntryKart = (kart->mDriveFlags & KART_DRIVE_FAR_FROM_ENTRY) != 0;
    hitCountCap = 0xf;
    for (overlapIndex = 0; overlapIndex < gFoundCollisionSlotCount; overlapIndex++) {
        if (!(gFoundCollisionSlotFlags[overlapIndex] & 0x4000)) {
            continue;
        }
        item = gFoundCollisionSlotObjects[overlapIndex];
        if (isFarFromEntryKart && !(item->mFlags & ITEM_OBJECT_FLAG_HITS_FAR_KARTS)) {
            continue;
        }
        if (!IsItemObjectOverlappingKart(item, kart)) {
            continue;
        }
        isHit = IsItemObjectHitKart(item, kart);
        if (isHit == 0) {
            continue;
        }
        if ((kart->mEntryFlags & KART_ENTRY_TERESA) && DoesItemObjectHurtKart(item) != 0) {
            continue;
        }
        gCollidedItemObjects[hitCount++] = item;
        if (item->mFlags & ITEM_OBJECT_FLAG_IN_USE) {
            RemoveItemInUseObject(&GetKartItems(item->mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)->mItemInUse,
                                  item);
        }
        kind = item->mKind;
        if (gItemKinds[kind].mEndsOnKartHit != 0) {
            if (DoesItemObjectHurtKart(item) != 0) {
                ApplyItemObjectPush(item, &kart->mCollisionCenter, &kart->mVelocity, &kart->mSignedTurnedForward);
                FadeOutItemObjectHitByKart(item, 1, (u16) kart->mIndex);
            } else {
                StartItemObjectReleaseSynced(item, 1);
            }
        }
        if (hitCount >= 0x10) {
            hitCount = hitCountCap;
        }
    }
    return hitCount;
}

#pragma thumb on

#pragma thumb off

struct ItemObject *GetCollidedItemObject(u32 index) {
    return gCollidedItemObjects[index];
}

#pragma thumb off

void *StartItemObjectOrZero(s32 kind, u16 kartIndex, void *pos, void *normal) {
    ItemObject *item;
    ItemPool *pool;

    item = 0;
    if (gItemPools[kind].mLimit - gItemPools[kind].mReservedCount <= 0) {
        return 0;
    }
    TakeItemPoolObjects(&gItemPools[kind], 1, &item, kartIndex, pos);
    pool = &gItemPools[kind];
    pool->mReservedCount++;
    StartItemObject(&gItemPools[item->mKind], item);
    SetItemObjectPlacement(item, pos, normal, 0, 0);
    if (kartIndex == ITEM_NO_KART_INDEX) {
        item->mOwnerKartIndexAndFlags |= gItemObjectNoOwnerBit;
    }
    return item;
}

#pragma thumb on

static inline ItemObject *CourseMapStartItemObjectOrZero(s32 kind, u16 kartIndex, void *pos, void *normal) {
    ItemObject *item;
    ItemPool *pool;

    item = 0;
    if (gItemPools[kind].mLimit - gItemPools[kind].mReservedCount <= 0) {
        return 0;
    }
    TakeItemPoolObjects(&gItemPools[kind], 1, &item, kartIndex, pos);
    pool = &gItemPools[kind];
    pool->mReservedCount++;
    StartItemObject(&gItemPools[item->mKind], item);
    SetItemObjectPlacement(item, pos, normal, 0, 0);
    if (kartIndex == ITEM_NO_KART_INDEX) {
        item->mOwnerKartIndexAndFlags |= gItemObjectNoOwnerBit;
    }
    return item;
}

// Starts an item object at every course map row of object kind 0x6d and rests it on the floor.
void StartCourseMapItemObjects(void) {
    u32 rowIndex;
    u32 rowCount;
    u32 collisionHitLink;
    ItemObject *item;
    Vec3 normal;
    enum { KIND_FIRST } kind;
    CourseMapRow *row;

    rowCount = gCourseMap->mRowCount;
    for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
        row = &gCourseMap->mRows[rowIndex];
        if (row->mKind == MAP_OBJECT_KIND_ITEM_PLACEMENT) {
            kind = row->mSettings[0];
            if (CollideSphereWithCourse(&row->mPosition, 0, 0, 0xa000, 8, -2, 0, &normal, 0, 0, 0, 0, 0,
                                        &collisionHitLink) == 0) {
                normal = gCourseMapItemVec3UnitY;
            }
            item = CourseMapStartItemObjectOrZero(kind, 8, row, &normal);
            if (item != 0) {
                void (*advance)(ItemObject *);

                kind = item->mKind;
                advance = gItemKinds[kind].mAdvance;
                if ((item->mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
                    item->mAdvance = advance;
                }
                StartRestingItemObject(item, &collisionHitLink);
            }
        }
    }
}

// Most item objects that one hit check can collect.
#define COLLIDED_ITEM_OBJECT_CAPACITY 0x10

void InitItems(void) {
    void *heap;
    s32 objectIdCounter;
    s32 kartIndex;
    enum { KIND_FIRST } kind;
    HeldItem *heldItem;
    u8 kartCount;

    heap = GetHeap(GetCurrentHeapCall());
    objectIdCounter = 0;
    CreateItemSlotTables();
    StartThunderBlockTimer(1);
    StartKouraWBlockTimer(1);
    StartGessoBlockTimer(1);
    CreateItemInfos();
    InitItemKinds();
    CreateItemPushVector();
    InitItemPointLinkDirections();
    kartCount = gRaceSetup->mKartCount;
    gKartItemsCount = kartCount;
    gKartItems = HeapAlloc(heap, kartCount * 0x210);
    for (kartIndex = 0; kartIndex < gKartItemsCount; kartIndex++) {
        InitKartItems(&gKartItems[kartIndex], kartIndex);
    }
    gItemPools = HeapAlloc(heap, ITEM_OBJECT_KIND_COUNT * sizeof(*gItemPools));
    for (kind = 0; kind < ITEM_OBJECT_KIND_COUNT; kind++) {
        CreateItemPool(&gItemPools[kind], kind, &objectIdCounter);
    }
    CreateItemModels();
    if (gRaceSetup->mMode == MODE_WIFI) {
        InitItemDataQueueLinks();
        InitItemDataDelayedLinks();
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        for (kartIndex = 0; kartIndex < gKartItemsCount; kartIndex++) {
            heldItem = &gKartItems[kartIndex].mHeldItem;
            SetHeldItem(heldItem, ITEM_INFO_KINOKO_THREE);
            switch (GetKartVariant(kartIndex)) {
                case 0:
                    RemoveHeldItemObjects(heldItem, 1);
                    break;
                case 1:
                    RemoveHeldItemObjects(heldItem, 2);
                    break;
            }
        }
    }
    gCollidedItemObjects =
        HeapAlloc(GetHeap(GetCurrentHeapCall()), COLLIDED_ITEM_OBJECT_CAPACITY * sizeof(*gCollidedItemObjects));
    StartCourseMapItemObjects();
    CreateItemTeresaFrameScaleTable();
    InitOrthoQuads();
    InitBouncingItemBoxTimers();
}

s32 GetItemDataSize(s32 itemKind, s32 messageKind) {
    switch (messageKind) {
        case ITEM_DATA_MESSAGE_START:
            return (u8) ((u8) gItemKinds[itemKind].mDataSize + 1);
        case ITEM_DATA_MESSAGE_START_GENERIC:
            return 0x12;
        case ITEM_DATA_MESSAGE_EVENT:
            return 3;
        case ITEM_DATA_MESSAGE_KART:
            return (u8) ((itemKind == ITEM_OBJECT_KIND_TERESA ? 3 : 2) + 1);
    }
    return 0;
}

#pragma thumb off

s32 GrowItemObjectScale(ItemObject *item, s32 limit, s32 step) {
    if (item->mScale.z < limit) {
        item->mScale.z += step;
        if (item->mScale.z > limit) {
            item->mScale.z = limit;
        }
        return 1;
    }
    return 0;
}

void RefreshItemObjectScale(ItemObject *item) {
    ItemKind *kindInfo;
    enum { KIND_FIRST } kind;
    s32 radiusRatio;

    kind = item->mKind;
    item->mFlags |= ITEM_OBJECT_FLAG_SCALE_CHANGED;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &gItemKinds[kind];
    radiusRatio = kindInfo->mRadius;
    item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
    item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, radiusRatio);
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
}

void RefreshItemObjectScaleExact(ItemObject *item) {
    ItemKind *kindInfo;
    enum { KIND_FIRST } kind;
    s32 radiusRatio;

    kind = item->mKind;
    item->mFlags |= ITEM_OBJECT_FLAG_SCALE_CHANGED;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &gItemKinds[kind];
    radiusRatio = kindInfo->mRadius;
    item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
    item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, radiusRatio);
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius);
}

void SetItemObjectScaleByRatios(ItemObject *objectParam, s32 xRatio, s32 yRatio) {
    ItemObject *item = objectParam;
    enum { KIND_FIRST } kind;
    s32 setupRadius;

    kind = item->mKind;
    setupRadius = gItemKinds[kind].mSetupRadius;
    item->mScale.x = MUL_FIXED12_NO_ROUND(item->mScale.z, xRatio);
    item->mScale.y = MUL_FIXED12_NO_ROUND(item->mScale.z, yRatio);
    item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, gItemKinds[kind].mCourseRadius);
    item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, setupRadius);
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
}

BOOL SwingItemObjectScale(ItemObject *item) {
    ItemKind *kindInfo;
    enum { KIND_FIRST } kind;
    s32 radiusRatio;

    if (item->mScaleTargetOrSpeed <= -ITEM_OBJECT_SCALE_SWING_REST ||
        item->mScaleTargetOrSpeed >= ITEM_OBJECT_SCALE_SWING_REST ||
        item->mScale.x - item->mScale.y <= -ITEM_OBJECT_SCALE_SWING_REST ||
        item->mScale.x - item->mScale.y >= ITEM_OBJECT_SCALE_SWING_REST) {
        kind = item->mKind;
        item->mFlags |= ITEM_OBJECT_FLAG_SCALE_CHANGED;
        item->mScale.y += item->mScaleTargetOrSpeed;
        item->mScaleTargetOrSpeed += MUL_FIXED12_NO_ROUND(item->mScale.z - item->mScale.y, 0x333);
        item->mScaleTargetOrSpeed = MUL_FIXED12_NO_ROUND(item->mScaleTargetOrSpeed, 0xc00);
        item->mScale.x = item->mScale.z * 2 - item->mScale.y;
        kindInfo = &gItemKinds[kind];
        radiusRatio = kindInfo->mRadius;
        item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
        item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, radiusRatio);
        SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
        return 1;
    }
    item->mScaleTargetOrSpeed = 0;
    return 0;
}

BOOL EaseItemObjectScale(ItemObject *item) {
    ItemKind *kindInfo;
    enum { KIND_FIRST } kind;
    s32 radiusRatio;

    if (item->mScaleTargetOrSpeed != 0) {
        kind = item->mKind;
        item->mFlags |= ITEM_OBJECT_FLAG_SCALE_CHANGED;
        item->mScale.y += MUL_FIXED12_NO_ROUND(item->mScaleTargetOrSpeed - item->mScale.y, 0x333);
        item->mScale.x = item->mScale.z * 2 - item->mScale.y;
        kindInfo = &gItemKinds[kind];
        radiusRatio = kindInfo->mRadius;
        item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
        item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, radiusRatio);
        SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
        return 1;
    }
    return 0;
}

void CreateItemObjectCollisionSlot(ItemObject *item) {
    if (item->mCollisionSlotIndex != -1) {
        return;
    }
    item->mCollisionSlotIndex = CreateCollisionSlot(&item->mPos, item->mRadius + 0xa000, 0x4000, item);
}

void CreateItemObjectCollisionSlotExact(ItemObject *item) {
    if (item->mCollisionSlotIndex != -1) {
        return;
    }
    item->mCollisionSlotIndex = CreateCollisionSlot(&item->mPos, item->mRadius, 0x4000, item);
}

#pragma thumb on
