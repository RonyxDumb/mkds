#include "Main/Item/item_bomb.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Course/course_color_blend.h"

#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_object.h"
#include "Main/System/state_machine_init.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Sound/sound_start.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "fixed_vector_math.h"
#include "Main/Item/held_item.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_object_reset_collide.h"
#include "Main/MapObjects/attractor_distance_flag.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_object_bouncing.h"
#include "Main/Graphics/model_effects.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Race/race.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "sound_archive_load_result.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_f_box.h"
#include "Main/Kart/karts.h"
#include "matrix_4x3_basic.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

const Vec3 gItemBombExplodeStartScale = {0x1000, 0x1000, 0x1000};
const u16 gItemBombDisabledFlag = 1;
StateCallbacks gItemBombStateTable[4] = {{ItemBombBounceNop, UpdateItemBombBounce},
                                         {ItemBombRestNop, UpdateItemBombRest},
                                         {EnterItemBombExplode, UpdateItemBombExplode},
                                         {NULL, NULL}};
const u16 gItemBombSkipListCallbackFlag = 8;
const u16 gItemBombNoUpdateListFlag = 4;
const u32 gItemObjectDistanceSquaredMask = 0x3fffffe0;
const u16 gItemBombSkipViewTestFlag = 2;
const u16 gItemBombNoOwnerBit = ITEM_OWNER_NO_OWNER;
s32 gItemBombExplodeMaxRadiusSquared;
s32 gItemBombTimerLimit;
s32 gItemBombExplodeInverseLimit;
s32 gItemBombExplodeScaleLimit;
s32 gItemBombExplodeScaleStep;

// Reset hook of the bomb kind.
void ResetItemBomb(ItemBomb *bomb) {
    u32 initialDistanceSquared;
    MTX_Identity43_(&bomb->mMatrix);
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    SetStateMachineState(&bomb->mStateMachine, ITEM_BOMB_STATE_BOUNCE);
    bomb->mTimer = ITEM_BOMB_FUSE_FRAMES;
    bomb->mModelFrameTimer = 0;
    initialDistanceSquared = ITEM_BOMB_NO_KART_DISTANCE_SQUARED;
    bomb->mNearestKartIndex = ITEM_NO_KART_INDEX;
    bomb->mNearestKartDistanceSquared = initialDistanceSquared;
    bomb->mTimerEndBlockTimer = 0;
    bomb->mHitSpinsKart = FALSE;
    bomb->mVisible = TRUE;
    bomb->mPooledMapObject = NULL;
}

s32 InitItemBomb(ItemInUse *inUse, ItemBomb *bomb) {
    StartItemObjectSoundSource(&bomb->mBouncingItemObject.mItemObject);
    bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= gItemBombExcludedUntilCourseHitBit;
    bomb->mReflectFactor = MUL_FIXED12_NO_ROUND(inUse->mKartVelocityLength, 0x1ec) + 0x333;
    if (bomb->mReflectFactor > ITEM_BOMB_MAX_REFLECT_FACTOR) {
        bomb->mReflectFactor = ITEM_BOMB_MAX_REFLECT_FACTOR;
    }
    if (inUse->mKartItems->mFlags & KART_ITEMS_DOWN) {
        ThrowBouncingItem(&bomb->mBouncingItemObject, inUse, ITEM_BOMB_DROPPED_BOUNCES, 0, 0x7800, 0x5000, 0x219a);
        bomb->mTimer = ITEM_BOMB_SHORT_FUSE_FRAMES;
        bomb->mIsThrown = 0;
        return bomb->mIsThrown;
    }
    if (inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&bomb->mBouncingItemObject, inUse, ITEM_BOMB_THROWN_BOUNCES, 1, 0x9800, 0x5000, 0x59a);
    } else {
        ThrowBouncingItem(&bomb->mBouncingItemObject, inUse, ITEM_BOMB_THROWN_BOUNCES, 1, 0x6000, 0x5000, 0x59a);
    }
    StartSound(&bomb->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
    bomb->mIsThrown = 1;
    return bomb->mIsThrown;
}

void ItemBombBounceNop(void *stateObject) {}

void UpdateItemBombBounce(void *stateObject) {
    ItemBomb *bomb = stateObject;
    u32 collisionHitLink;

    if (bomb->mIsThrown != 0) {
        AdvanceBouncingItem(&bomb->mBouncingItemObject, 0x385, 0xff8, 0x733, &collisionHitLink);
    } else {
        AdvanceBouncingItem(&bomb->mBouncingItemObject, 0x47b, 0xf91, bomb->mReflectFactor, &collisionHitLink);
    }
    if (bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_BOUNCED) {
        StartItemObjectSoundIfNear(&bomb->mBouncingItemObject.mItemObject, 0xe5);
    }
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_LANDED) == 0) {
        return;
    }
    if (bomb->mBouncingItemObject.mItemObject.mFlags &
        (ITEM_OBJECT_FLAG_FADE_OUT_STARTED | ITEM_OBJECT_FLAG_RELEASE_STARTED)) {
        return;
    }
    if (bomb->mIsThrown != 0) {
        bomb->mBouncingItemObject.mItemObject.mVelocity.y *= 2;
    }
    StopSound(&bomb->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&bomb->mBouncingItemObject.mItemObject, &collisionHitLink);
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    bomb->mStateMachine.mNextState = ITEM_BOMB_STATE_REST;
    bomb->mStateMachine.mNextStateRequested = 1;
}

void ItemBombRestNop(void *stateObject) {}

void UpdateItemBombRest(void *stateObject) {
    ItemBomb *bomb = stateObject;
    u32 flags;

    flags = bomb->mBouncingItemObject.mItemObject.mFlags;
    if (flags & ITEM_OBJECT_FLAG_RESTING) {
        AdvanceRestingItemObject(&bomb->mBouncingItemObject.mItemObject);
        return;
    }
    if (flags & ITEM_OBJECT_FLAG_LAUNCHED) {
        AdvanceFallingItemObject(&bomb->mBouncingItemObject.mItemObject);
        bomb->mTimer = ITEM_BOMB_SHORT_FUSE_FRAMES;
        bomb->mModelFrameTimer = 0;
    }
}

void EnterItemBombExplode(void *stateObject) {
    ItemBomb *bomb = stateObject;
    NNSSndSeqPlayer **seqPlayerPointer;
    ModelEffect *modelEffect;

    bomb->mBouncingItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_FIXED_SCALE;
    bomb->mBouncingItemObject.mItemObject.mScaleTargetOrSpeed = 0;
    bomb->mBouncingItemObject.mItemObject.mScale = gItemBombExplodeStartScale;
    bomb->mModelEffect =
        StartModelEffect(MODEL_EFFECT_BOMBCORE, &bomb->mBouncingItemObject.mItemObject.mPos,
                         IsItemObjectTooFarForEffects(&bomb->mBouncingItemObject.mItemObject) == 0 ? 1 : 0);
    modelEffect = bomb->mModelEffect;
    if (modelEffect != NULL) {
        Vec3 *effectScale;

        effectScale = &modelEffect->mScale;
        effectScale->x = 0xccd;
        effectScale->y = 0xccd;
        effectScale->z = 0xccd;
    }
    StartItemObjectSoundIfNear(&bomb->mBouncingItemObject.mItemObject, 0xe4);
    if (gRaceSoundKind & 1) {
        seqPlayerPointer = TakeSoundHandleEntry(GetSoundHandlePool(0));
        if (gSoundModeHolder.mSeqStartEnabled != 0) {
            if (seqPlayerPointer[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerPointer, 0);
            }
            if (seqPlayerPointer[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerPointer, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayerPointer, 0, 0xe0);
        }
    }
    StartCameraWobbleAtDistance(bomb->mBouncingItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
}

void UpdateItemBombExplode(void *stateObject) {
    ItemBomb *bomb = stateObject;
    s32 stateFrames;

    stateFrames = bomb->mStateMachine.mStateFrames;
    if (GrowItemObjectScale(&bomb->mBouncingItemObject.mItemObject, gItemBombExplodeScaleLimit,
                            gItemBombExplodeScaleStep) != 0) {
        RefreshItemObjectScaleExact(&bomb->mBouncingItemObject.mItemObject);
    }
    if (stateFrames < 0x16) {
        return;
    }
    if (stateFrames == 0x16) {
        bomb->mHitSpinsKart = TRUE;
    } else if (stateFrames == 0x2a) {
        FreeItemObjectCollisionSlot(&bomb->mBouncingItemObject.mItemObject);
    }
    if (stateFrames <= 0x55) {
        return;
    }
    ReleaseItemPoolObject(gItemPools + bomb->mBouncingItemObject.mItemObject.mKind,
                          &bomb->mBouncingItemObject.mItemObject);
}

void AdvanceItemBombNearestKart(ItemBomb *bomb) {
    u32 candidateKartIndex;
    u16 skippedKartIndex;
    Kart *kart;
    Vec3 kartPosition;
    s32 distanceSquared;
    s32 deltaX;
    s32 deltaY;
    s32 deltaZ;

    candidateKartIndex = (u16) GetRaceUpdateFramesMod8();
    if (candidateKartIndex >= gRaceSetup->mKartCount) {
        return;
    }
    skippedKartIndex =
        (bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0
            ? (u16) (bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)
            : ITEM_NO_KART_INDEX;
    if (candidateKartIndex == skippedKartIndex) {
        return;
    }
    kart = GetKart(candidateKartIndex);
    if (IsKartNotNormal(kart) != 0) {
        return;
    }
    if (bomb->mNearestKartDistanceSquared < ITEM_BOMB_NEAREST_REMEASURE_DISTANCE_SQUARED) {
        GetKartPos(&kartPosition, bomb->mNearestKartIndex);
        deltaX = FROM_FIXED12(bomb->mBouncingItemObject.mItemObject.mPos.x - kartPosition.x);
        deltaY = FROM_FIXED12(bomb->mBouncingItemObject.mItemObject.mPos.y - kartPosition.y);
        deltaZ = FROM_FIXED12(bomb->mBouncingItemObject.mItemObject.mPos.z - kartPosition.z);
        distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
        bomb->mNearestKartDistanceSquared = distanceSquared;
    }
    kartPosition = kart->mDrawMatrixPos;
    deltaX = FROM_FIXED12(bomb->mBouncingItemObject.mItemObject.mPos.x - kartPosition.x);
    deltaY = FROM_FIXED12(bomb->mBouncingItemObject.mItemObject.mPos.y - kartPosition.y);
    deltaZ = FROM_FIXED12(bomb->mBouncingItemObject.mItemObject.mPos.z - kartPosition.z);
    distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    if (distanceSquared < bomb->mNearestKartDistanceSquared) {
        bomb->mNearestKartIndex = candidateKartIndex;
        bomb->mNearestKartDistanceSquared = distanceSquared;
    }
}

void ClampItemBombTimerByDistance(ItemBomb *bomb) {
    if (bomb->mNearestKartDistanceSquared > (gItemBombExplodeMaxRadiusSquared << 6)) {
        return;
    }
    if (bomb->mNearestKartDistanceSquared > (gItemBombExplodeMaxRadiusSquared << 4)) {
        if (bomb->mTimer > gItemBombTimerLimit) {
            bomb->mTimer = gItemBombTimerLimit;
        }
        return;
    }
    if (bomb->mNearestKartDistanceSquared > (gItemBombExplodeMaxRadiusSquared << 2)) {
        if (bomb->mTimer > (gItemBombTimerLimit >> 1)) {
            bomb->mTimer = gItemBombTimerLimit >> 1;
        }
        return;
    }
    if (bomb->mNearestKartDistanceSquared > gItemBombExplodeMaxRadiusSquared) {
        if (bomb->mTimer > (gItemBombTimerLimit >> 2)) {
            bomb->mTimer = gItemBombTimerLimit >> 2;
        }
        return;
    }
    if (bomb->mTimer > ITEM_BOMB_FINAL_FUSE_FRAMES) {
        bomb->mTimer = ITEM_BOMB_FINAL_FUSE_FRAMES;
        bomb->mModelFrameTimer = ITEM_BOMB_FINAL_FLASH_FRAMES;
    }
}

void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, ItemBox *pooledMapObject) {
    ItemBox *mapObjectToPark;

    bombAlias->mBouncingItemObject.mItemObject.mDistanceSquaredAndFlags |= gItemObjectDistanceSquaredMask;
    AdvanceStateMachine(&bomb->mStateMachine);
    if (pooledMapObject->mMapObject.mFlags & MAP_OBJECT_FLAG_PARKED) {
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mBouncingItemObject.mItemObject.mKind,
                              &bomb->mBouncingItemObject.mItemObject);
        return;
    }
    if ((bombAlias->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_RESTING) == 0) {
        pooledMapObject->mMapObject.mPos = bombAlias->mBouncingItemObject.mItemObject.mPos;
        pooledMapObject->mMapObject.mPos.y +=
            bomb->mMapObjectOffsetY - bombAlias->mBouncingItemObject.mItemObject.mCourseRadius;
    }
    if (bomb->mTimer <= 0) {
        if ((bombAlias->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_RESTING) == 0) {
            return;
        }
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mBouncingItemObject.mItemObject.mKind,
                              &bomb->mBouncingItemObject.mItemObject);
        return;
    }
    bomb->mTimer--;
    if (bomb->mTimer < pooledMapObject->mMapObject.mAlpha) {
        pooledMapObject->mMapObject.mAlpha = bomb->mTimer;
    }
    if (bomb->mTimer < ITEM_BOMB_MAP_OBJECT_DISABLE_FRAMES) {
        pooledMapObject->mMapObject.mFlags |= gItemBombDisabledFlag;
    }
    if (bomb->mTimer == 0) {
        mapObjectToPark = bomb->mPooledMapObject;
        mapObjectToPark->mMapObject.mFlags &= ~1;
        ParkMapObject(&mapObjectToPark->mMapObject);
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mBouncingItemObject.mItemObject.mKind,
                              &bomb->mBouncingItemObject.mItemObject);
    }
}

void AdvanceItemBomb(ItemBomb *bomb) {
    if (bomb->mPooledMapObject != NULL) {
        AdvanceItemBombWithMapObject(bomb, bomb, bomb->mPooledMapObject);
        return;
    }
    AdvanceStateMachine(&bomb->mStateMachine);
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADING_OUT) || bomb->mTimer < 0) {
        FadeOutEndedItemObject(&bomb->mBouncingItemObject.mItemObject, 1);
    }
    bomb->mTimer--;
    if (bomb->mTimerEndBlockTimer > 0) {
        bomb->mTimerEndBlockTimer--;
        if (bomb->mTimer == 0) {
            bomb->mTimer = ITEM_BOMB_END_BLOCK_FUSE_FRAMES;
        }
    }
    if (bomb->mBouncingItemObject.mBouncesRemaining >= ITEM_BOMB_THROWN_BOUNCES) {
        return;
    }
    if (bomb->mIsThrown == 0 && bomb->mBouncingItemObject.mBouncesRemaining >= ITEM_BOMB_DROPPED_BOUNCES) {
        return;
    }
    if ((bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0) {
        AdvanceItemBombNearestKart(bomb);
        if (bomb->mTimerEndBlockTimer == 0) {
            ClampItemBombTimerByDistance(bomb);
        }
    }
    if (bomb->mTimer >= ITEM_BOMB_FLASH_START_FRAMES) {
        return;
    }
    bomb->mModelFrameTimer--;
    if (bomb->mModelFrameTimer > 0) {
        return;
    }
    bomb->mModelFrameTimer = bomb->mTimer >> 2;
    if (bomb->mModelFrameTimer < ITEM_BOMB_FLASH_MIN_PERIOD) {
        bomb->mModelFrameTimer = ITEM_BOMB_FLASH_MIN_PERIOD;
    }
}

void *CopyItemBombData(void *cursor, ItemBomb *bomb, void *toData) {
    void *nextCursor;

    if (bomb != NULL && toData != NULL) {
        StoreItemDataFlagBit(bomb->mIsThrown, &bomb->mBouncingItemObject.mItemObject.mVelocity.y);
    }
    nextCursor = CopyItemObjectData(cursor, bomb, toData);
    nextCursor = CopyItemShiftedByte(nextCursor, bomb != NULL ? &bomb->mReflectFactor : 0, toData);
    if (bomb != NULL && toData == NULL) {
        LoadItemDataFlagBit(bomb->mBouncingItemObject.mItemObject.mVelocity.y, &bomb->mIsThrown);
    }
    if (bomb != NULL && toData != NULL) {
        return AddItemDataSizedByKind(bomb->mBouncingItemObject.mItemObject.mKind);
    }
    return nextCursor;
}

void InitItemBombFromData(ItemBomb *bomb) {
    SetupItemObjectFromData(&bomb->mBouncingItemObject.mItemObject);
    StartItemObjectBouncing(&bomb->mBouncingItemObject, bomb->mIsThrown != 0 ? 3 : 2);
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    if (!(bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FROM_DATA)) {
        return;
    }
    if (bomb->mIsThrown == 0) {
        return;
    }
    StartSound(&bomb->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

void DrawItemBomb(ItemBomb *bomb, Vec3 *viewAxis, NsbmdModel *model) {
    if (bomb->mVisible == FALSE) {
        return;
    }
    if (bomb->mStateMachine.mState != ITEM_BOMB_STATE_EXPLODE) {
        if (bomb->mModelFrameTimer != 0 && bomb->mModelFrameTimer < ITEM_BOMB_FLASH_SHOWN_FRAMES) {
            model->mFrameIndex = 1;
        } else {
            model->mFrameIndex = 0;
        }
        DrawItemObjectModel(&bomb->mBouncingItemObject.mItemObject, model, viewAxis);
        return;
    }
    if (bomb->mModelEffect == NULL) {
        return;
    }
    bomb->mModelEffect->mVisible = (bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_OUT_OF_VIEW) == 0;
}

int RequestItemBombExplode(ItemBomb *bomb) {
    if (bomb->mStateMachine.mState != ITEM_BOMB_STATE_EXPLODE) {
        InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
        bomb->mStateMachine.mNextState = ITEM_BOMB_STATE_EXPLODE;
        bomb->mStateMachine.mNextStateRequested = 1;
        if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
            bomb->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
        }
        bomb->mBouncingItemObject.mItemObject.mFlags &= ~ITEM_OBJECT_FLAG_RESTING;
        bomb->mBouncingItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_FADING_OUT;
        bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags &= ~ITEM_OWNER_EXCLUDED;
    }
    return 1;
}

void RequestItemBombRest(ItemBomb *bomb) {
    if (bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADING_OUT) {
        return;
    }
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    bomb->mStateMachine.mNextState = ITEM_BOMB_STATE_REST;
    bomb->mStateMachine.mNextStateRequested = 1;
    bomb->mTimerEndBlockTimer = ITEM_BOMB_END_BLOCK_FRAMES;
    bomb->mIsThrown = 0;
    bomb->mBouncingItemObject.mBouncesRemaining = 0;
}

// Release hook of the bomb kind: parks its map object, if it has one.
void ParkItemBombMapObject(ItemBomb *bomb) {
    ItemBox *pooledMapObject = bomb->mPooledMapObject;
    if (pooledMapObject == NULL) {
        return;
    }
    pooledMapObject->mMapObject.mFlags &= ~1;
    ParkMapObject(&pooledMapObject->mMapObject);
}

u32 GetItemBombActiveCount(void) {
    return gItemPools[ITEM_OBJECT_KIND_BOMB].mActiveCount;
}

#pragma thumb off

ItemBomb *GetRestingItemBomb(int index) {
    ItemBomb *bomb;
    u32 flags;

    bomb = (ItemBomb *) gItemPools[ITEM_OBJECT_KIND_BOMB].mObjects[index];
    flags = bomb->mBouncingItemObject.mItemObject.mFlags;
    if ((flags & ITEM_OBJECT_FLAG_RESTING) && (flags & ITEM_OBJECT_FLAGS_ENDING) == 0 &&
        bomb->mStateMachine.mState != ITEM_BOMB_STATE_PARKED && bomb->mPooledMapObject == NULL) {
        return bomb;
    }
    return NULL;
}

void ParkItemBomb(void *object) {
    ItemBomb *bomb;

    bomb = object;
    bomb->mBouncingItemObject.mItemObject.mFlags &= ~ITEM_OBJECT_FLAG_RESTING;
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot(&bomb->mBouncingItemObject.mItemObject);
    bomb->mVisible = FALSE;
    SetStateMachineState(&bomb->mStateMachine, ITEM_BOMB_STATE_PARKED);
    bomb->mModelFrameTimer = 0;
}

void PlaceItemBomb(void *object, Vec3 *normal, Vec3 *position) {
    ItemBomb *bomb;
    Vec3 *normalAlias;
    Vec3 *positionAlias;
    ItemBox *pooledMapObject;

    bomb = object;
    normalAlias = normal;
    positionAlias = position;
    if (bomb->mPooledMapObject == NULL) {
        bomb->mVisible = TRUE;
        SetCourseColorBlendColor(&bomb->mBouncingItemObject.mItemObject.mColorBlend, 1);
    }
    if (normalAlias != NULL) {
        bomb->mBouncingItemObject.mItemObject.mNormal = *normalAlias;
        bomb->mBouncingItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_KEEP_NORMAL;
    }
    if (positionAlias == NULL) {
        return;
    }
    bomb->mBouncingItemObject.mItemObject.mPos = *positionAlias;
    VEC_Subtract(&bomb->mBouncingItemObject.mItemObject.mPos, &bomb->mBouncingItemObject.mItemObject.mPrevPos,
                 &bomb->mBouncingItemObject.mItemObject.mVelocity);
    if (bomb->mPooledMapObject == NULL) {
        return;
    }
    bomb->mPooledMapObject->mMapObject.mPos = *positionAlias;
    bomb->mPooledMapObject->mMapObject.mPos.y += bomb->mMapObjectOffsetY;
    pooledMapObject = bomb->mPooledMapObject;
    pooledMapObject->mMapObject.mFlags &= ~2;
    pooledMapObject->mMapObject.mFlags &= ~8;
    pooledMapObject->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
}

void ThrowItemBombFromSlot(void **bombSlot, Vec3 *velocity, s32 timerStart) {
    ItemBomb *bomb;
    ItemBox *pooledMapObject;

    bomb = *bombSlot;
    pooledMapObject = bomb->mPooledMapObject;
    bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= gItemBombNoOwnerBit;
    if (pooledMapObject == NULL) {
        CreateItemObjectCollisionSlot(&bomb->mBouncingItemObject.mItemObject);
        bomb->mVisible = TRUE;
    }
    StartItemObjectSoundSource(&bomb->mBouncingItemObject.mItemObject);
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    SetStateMachineState(&bomb->mStateMachine, ITEM_BOMB_STATE_BOUNCE);
    bomb->mTimer = ITEM_BOMB_FUSE_FRAMES;
    bomb->mModelFrameTimer = 0;
    bomb->mNearestKartIndex = ITEM_NO_KART_INDEX;
    bomb->mNearestKartDistanceSquared = ITEM_BOMB_NO_KART_DISTANCE_SQUARED;
    bomb->mTimerEndBlockTimer = 0;
    bomb->mHitSpinsKart = FALSE;
    bomb->mReflectFactor = ITEM_BOMB_MAX_REFLECT_FACTOR;
    bomb->mTimer = timerStart;
    bomb->mIsThrown = 1;
    InitBouncingItem(&bomb->mBouncingItemObject, ITEM_BOMB_THROWN_BOUNCES, velocity);
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    if (pooledMapObject != NULL) {
        pooledMapObject->mMapObject.mFlags &= ~2;
        pooledMapObject->mMapObject.mFlags &= ~8;
        pooledMapObject->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
        pooledMapObject->mMapObject.mFlags &= ~4;
        if (pooledMapObject->mMapObject.mKind != MAP_OBJECT_KIND_KURIBO) {
            pooledMapObject->mMapObject.mFlags &= ~1;
        }
    }
    *bombSlot = NULL;
}

BOOL IsItemBombExploding(ItemObject *object) {
    ItemBomb *bomb;

    bomb = (ItemBomb *) object;
    return bomb->mStateMachine.mState == ITEM_BOMB_STATE_EXPLODE;
}

void ReleaseItemBomb(void **bombSlot) {
    ItemBomb *bomb;
    ItemBox *pooledMapObject;

    bomb = *bombSlot;
    SetStateMachineState(&bomb->mStateMachine, ITEM_BOMB_STATE_BOUNCE);
    pooledMapObject = bomb->mPooledMapObject;
    if (pooledMapObject != NULL) {
        pooledMapObject->mMapObject.mFlags &= ~1;
        ParkMapObject(&pooledMapObject->mMapObject);
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mBouncingItemObject.mItemObject.mKind,
                              &bomb->mBouncingItemObject.mItemObject);
    } else {
        ReleaseItemPoolObject(gItemPools + bomb->mBouncingItemObject.mItemObject.mKind,
                              &bomb->mBouncingItemObject.mItemObject);
    }
    *bombSlot = NULL;
}

void *StartItemBomb(void) {
    ItemBomb *bomb;

    bomb = StartItemObjectOrZero(ITEM_OBJECT_KIND_BOMB, 8, gItemBombVec3UnitY, gItemBombVec3UnitY);
    if (bomb == NULL) {
        return NULL;
    }
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot(&bomb->mBouncingItemObject.mItemObject);
    bomb->mVisible = FALSE;
    SetStateMachineState(&bomb->mStateMachine, ITEM_BOMB_STATE_PARKED);
    bomb->mModelFrameTimer = 0;
    return bomb;
}

void *StartItemBombWithMapObject(void *mapObject, s32 offsetY) {
    ItemBomb *bomb;
    ItemBox *pooledMapObject;

    pooledMapObject = mapObject;
    bomb = StartItemObjectOrZero(ITEM_OBJECT_KIND_BOMB, 8, gItemBombVec3UnitY, gItemBombVec3UnitY);
    if (bomb == NULL) {
        bomb = NULL;
    } else {
        if ((bomb->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
            bomb->mBouncingItemObject.mItemObject.mAdvance = NULL;
        }
        FreeItemObjectCollisionSlot(&bomb->mBouncingItemObject.mItemObject);
        bomb->mVisible = FALSE;
        SetStateMachineState(&bomb->mStateMachine, ITEM_BOMB_STATE_PARKED);
        bomb->mModelFrameTimer = 0;
    }
    if (bomb == NULL) {
        return NULL;
    }
    UnparkMapObject(&pooledMapObject->mMapObject);
    pooledMapObject->mMapObject.mFlags |= gItemBombDisabledFlag;
    pooledMapObject->mMapObject.mFlags |= gItemBombSkipViewTestFlag;
    pooledMapObject->mMapObject.mFlags |= gItemBombSkipListCallbackFlag;
    pooledMapObject->mMapObject.mFlags |= gItemBombNoUpdateListFlag;
    bomb->mPooledMapObject = pooledMapObject;
    bomb->mMapObjectOffsetY = offsetY;
    return bomb;
}

Vec3 *GetItemBombExplodeInfo(ItemBomb *bomb, s32 *stateFrames, s32 *scaledScaleZ) {
    *stateFrames = bomb->mStateMachine.mStateFrames;
    *scaledScaleZ = MUL_FIXED12_NO_ROUND(bomb->mBouncingItemObject.mItemObject.mScale.z, gItemBombExplodeInverseLimit);
    return &bomb->mBouncingItemObject.mItemObject.mPos;
}

#pragma thumb on

void SetupItemBombKind(void) {
    s32 engineIndex;

    gItemBombExplodeScaleLimit = 0x18006;
    gItemBombExplodeInverseLimit = FX_Div(0x1000, 0x18006);
    gItemBombExplodeScaleStep = 0x2148;
    gItemBombExplodeMaxRadiusSquared = MUL_FIXED12_NO_ROUND(gItemBombExplodeScaleLimit, gItemKinds[9].mRadius);
    gItemBombExplodeMaxRadiusSquared >>= 12;
    gItemBombExplodeMaxRadiusSquared *= gItemBombExplodeMaxRadiusSquared;
    engineIndex = gRaceSetup->mEngineIndex;
    switch (engineIndex) {
        case ENGINE_CLASS_SLOW:
            gItemBombTimerLimit = 0xb4;
            break;
        case ENGINE_CLASS_MEDIUM:
            gItemBombTimerLimit = 0x96;
            break;
        default:
            gItemBombTimerLimit = 0x78;
            break;
    }
}

#pragma thumb off
