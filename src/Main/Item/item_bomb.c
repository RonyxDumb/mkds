#include "Main/Item/item_bomb.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Course/course_color_blend.h"

#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_object.h"
#include "Main/System/state_machine_init.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Sound/sound_start.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Sound/data_0216c000.h"
#include "code_02147cd8.h"
#include "Main/Item/held_item.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/code_020f9334.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_object_bouncing.h"
#include "Main/Graphics/model_effects.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Race/race.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
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
#include "code_0212df7c.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_f_box.h"
#include "Main/Kart/karts.h"
#include "fx_mtx43.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

const Vec3 gItemBombState2StartScale = {0x1000, 0x1000, 0x1000};
const u16 gItemBombDisabledFlag = 1;
StateCallbacks gItemBombStateTable[4] = {{(UnkFunc *) ItemBombState0ReturnArgument, UpdateItemBombState0},
                                         {(UnkFunc *) ItemBombState1ReturnArgument, UpdateItemBombState1},
                                         {EnterItemBombState2, UpdateItemBombState2},
                                         {NULL, NULL}};
const u16 gItemBombSkipListCallbackFlag = 8;
const u16 gItemBombNoUpdateListFlag = 4;
const u32 gItemObjectDistanceSquaredMask = 0x3fffffe0;
const u16 gItemBombSkipViewTestFlag = 2;
const u16 gItemBombNoOwnerBit = 0x8000;
s32 gItemBombState2MaxRadiusSquared;
s32 gItemBombTimerLimit;
s32 gItemBombState2InverseLimit;
s32 gItemBombState2ScaleLimit;
s32 gItemBombState2ScaleStep;

// Reset hook of the bomb kind.
void ResetItemBomb(ItemBomb *bomb) {
    u32 initialDistanceSquared;
    MTX_Identity43_(&bomb->mUnk_13c);
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    SetStateMachineState(&bomb->mStateMachine, 0);
    bomb->mTimer = 300;
    bomb->mModelFrameTimer = 0;
    initialDistanceSquared = 0x05f592e1u;
    bomb->mNearestKartIndex = 8;
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
    if (bomb->mReflectFactor > 0xccd) {
        bomb->mReflectFactor = 0xccd;
    }
    if (inUse->mKartItems->mFlags & KART_ITEMS_DOWN) {
        ThrowBouncingItem(&bomb->mBouncingItemObject, inUse, 2, 0, 0x7800, 0x5000, 0x219a);
        bomb->mTimer = 0x5a;
        bomb->mIsThrown = 0;
        return bomb->mIsThrown;
    }
    if (inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&bomb->mBouncingItemObject, inUse, 3, 1, 0x9800, 0x5000, 0x59a);
    } else {
        ThrowBouncingItem(&bomb->mBouncingItemObject, inUse, 3, 1, 0x6000, 0x5000, 0x59a);
    }
    StartSound(&bomb->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
    bomb->mIsThrown = 1;
    return bomb->mIsThrown;
}

u32 ItemBombState0ReturnArgument(u32 value) {
    return value;
}

void UpdateItemBombState0(ItemBomb *bomb) {
    u32 collisionHitLink;

    if (bomb->mIsThrown != 0) {
        AdvanceBouncingItem(&bomb->mBouncingItemObject, 0x385, 0xff8, 0x733, &collisionHitLink);
    } else {
        AdvanceBouncingItem(&bomb->mBouncingItemObject, 0x47b, 0xf91, bomb->mReflectFactor, &collisionHitLink);
    }
    if (bomb->mBouncingItemObject.mItemObject.mFlags & 0x10) {
        StartItemObjectSoundIfNear(&bomb->mBouncingItemObject.mItemObject, 0xe5);
    }
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x8) == 0) {
        return;
    }
    if (bomb->mBouncingItemObject.mItemObject.mFlags & 0x3) {
        return;
    }
    if (bomb->mIsThrown != 0) {
        bomb->mBouncingItemObject.mItemObject.mVelocity.y *= 2;
    }
    StopSound(&bomb->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&bomb->mBouncingItemObject.mItemObject, &collisionHitLink);
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    bomb->mStateMachine.mNextState = 1;
    bomb->mStateMachine.mNextStateRequested = 1;
}

u32 ItemBombState1ReturnArgument(u32 value) {
    return value;
}

void UpdateItemBombState1(ItemBomb *bomb) {
    u32 flags;

    flags = bomb->mBouncingItemObject.mItemObject.mFlags;
    if (flags & 0x8000) {
        AdvanceRestingItemObject(&bomb->mBouncingItemObject.mItemObject);
        return;
    }
    if (flags & 0x4000) {
        AdvanceFallingItemObject(&bomb->mBouncingItemObject.mItemObject);
        bomb->mTimer = 0x5a;
        bomb->mModelFrameTimer = 0;
    }
}

void EnterItemBombState2(ItemBomb *bomb) {
    NNSSndSeqPlayer **seqPlayerPointer;
    ModelEffect *modelEffect;

    bomb->mBouncingItemObject.mItemObject.mFlags |= 0x800000;
    bomb->mBouncingItemObject.mItemObject.mScaleTargetOrSpeed = 0;
    bomb->mBouncingItemObject.mItemObject.mScale = gItemBombState2StartScale;
    bomb->mModelEffect =
        StartModelEffect(0, &bomb->mBouncingItemObject.mItemObject.mPos,
                         IsItemObjectTooFarForEffects(&bomb->mBouncingItemObject.mItemObject) == 0 ? 1 : 0);
    modelEffect = bomb->mModelEffect;
    if (modelEffect != NULL) {
        s32 *effectScale;

        effectScale = modelEffect->mScale;
        effectScale[0] = 0xccd;
        effectScale[1] = 0xccd;
        effectScale[2] = 0xccd;
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

void UpdateItemBombState2(ItemBomb *bomb) {
    s32 stateFrames;

    stateFrames = bomb->mStateMachine.mStateFrames;
    if (GrowItemObjectScale(&bomb->mBouncingItemObject.mItemObject, gItemBombState2ScaleLimit,
                            gItemBombState2ScaleStep) != 0) {
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
    skippedKartIndex = (bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0
                           ? (u16) (bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & ~0xff00)
                           : 8;
    if (candidateKartIndex == skippedKartIndex) {
        return;
    }
    kart = GetKart(candidateKartIndex);
    if (IsKartNotNormal(kart) != 0) {
        return;
    }
    if (bomb->mNearestKartDistanceSquared < 8) {
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
    if (bomb->mNearestKartDistanceSquared > (gItemBombState2MaxRadiusSquared << 6)) {
        return;
    }
    if (bomb->mNearestKartDistanceSquared > (gItemBombState2MaxRadiusSquared << 4)) {
        if (bomb->mTimer > gItemBombTimerLimit) {
            bomb->mTimer = gItemBombTimerLimit;
        }
        return;
    }
    if (bomb->mNearestKartDistanceSquared > (gItemBombState2MaxRadiusSquared << 2)) {
        if (bomb->mTimer > (gItemBombTimerLimit >> 1)) {
            bomb->mTimer = gItemBombTimerLimit >> 1;
        }
        return;
    }
    if (bomb->mNearestKartDistanceSquared > gItemBombState2MaxRadiusSquared) {
        if (bomb->mTimer > (gItemBombTimerLimit >> 2)) {
            bomb->mTimer = gItemBombTimerLimit >> 2;
        }
        return;
    }
    if (bomb->mTimer > 4) {
        bomb->mTimer = 4;
        bomb->mModelFrameTimer = 3;
    }
}

void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, ItemBox *pooledMapObject) {
    ItemBox *mapObjectToPark;

    bombAlias->mBouncingItemObject.mItemObject.mDistanceSquaredAndFlags |= gItemObjectDistanceSquaredMask;
    AdvanceStateMachine(&bomb->mStateMachine);
    if (pooledMapObject->mMapObject.mFlags & 0x100) {
        bomb->mPooledMapObject = NULL;
        ReleaseItemPoolObject(gItemPools + bomb->mBouncingItemObject.mItemObject.mKind,
                              &bomb->mBouncingItemObject.mItemObject);
        return;
    }
    if ((bombAlias->mBouncingItemObject.mItemObject.mFlags & 0x8000) == 0) {
        pooledMapObject->mMapObject.mPos = bombAlias->mBouncingItemObject.mItemObject.mPos;
        pooledMapObject->mMapObject.mPos.y +=
            bomb->mMapObjectOffsetY - bombAlias->mBouncingItemObject.mItemObject.mCourseRadius;
    }
    if (bomb->mTimer <= 0) {
        if ((bombAlias->mBouncingItemObject.mItemObject.mFlags & 0x8000) == 0) {
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
    if (bomb->mTimer < 0x10) {
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
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x80000) || bomb->mTimer < 0) {
        FadeOutEndedItemObject(&bomb->mBouncingItemObject.mItemObject, 1);
    }
    bomb->mTimer--;
    if (bomb->mTimerEndBlockTimer > 0) {
        bomb->mTimerEndBlockTimer--;
        if (bomb->mTimer == 0) {
            bomb->mTimer = 0x10;
        }
    }
    if (bomb->mBouncingItemObject.mBouncesRemaining >= 3) {
        return;
    }
    if (bomb->mIsThrown == 0 && bomb->mBouncingItemObject.mBouncesRemaining >= 2) {
        return;
    }
    if ((bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
        AdvanceItemBombNearestKart(bomb);
        if (bomb->mTimerEndBlockTimer == 0) {
            ClampItemBombTimerByDistance(bomb);
        }
    }
    if (bomb->mTimer >= 0xd2) {
        return;
    }
    bomb->mModelFrameTimer--;
    if (bomb->mModelFrameTimer > 0) {
        return;
    }
    bomb->mModelFrameTimer = bomb->mTimer >> 2;
    if (bomb->mModelFrameTimer < 8) {
        bomb->mModelFrameTimer = 8;
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
    if (!(bomb->mBouncingItemObject.mItemObject.mFlags & 0x10000000)) {
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
    if (bomb->mStateMachine.mState != 2) {
        if (bomb->mModelFrameTimer != 0 && bomb->mModelFrameTimer < 6) {
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
    bomb->mModelEffect->mVisible = (bomb->mBouncingItemObject.mItemObject.mFlags & 0x10000) == 0;
}

int RequestItemBombState2(ItemBomb *bomb) {
    if (bomb->mStateMachine.mState != 2) {
        InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
        bomb->mStateMachine.mNextState = 2;
        bomb->mStateMachine.mNextStateRequested = 1;
        if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
            bomb->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
        }
        bomb->mBouncingItemObject.mItemObject.mFlags &= ~0x8000;
        bomb->mBouncingItemObject.mItemObject.mFlags |= 0x80000;
        bomb->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags &= ~0x4000;
    }
    return 1;
}

void RequestItemBombState1(ItemBomb *bomb) {
    if (bomb->mBouncingItemObject.mItemObject.mFlags & 0x80000) {
        return;
    }
    InitStateMachine(&bomb->mStateMachine, gItemBombStateTable, 4, bomb);
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    bomb->mStateMachine.mNextState = 1;
    bomb->mStateMachine.mNextStateRequested = 1;
    bomb->mTimerEndBlockTimer = 0x10e;
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
    return gItemPools[9].mActiveCount;
}

#pragma thumb off

ItemBomb *GetRestingItemBomb(int index) {
    ItemBomb *bomb;
    u32 flags;

    bomb = (ItemBomb *) gItemPools[9].mObjects[index];
    flags = bomb->mBouncingItemObject.mItemObject.mFlags;
    if ((flags & 0x8000) && (flags & 0x180000) == 0 && bomb->mStateMachine.mState != 3 &&
        bomb->mPooledMapObject == NULL) {
        return bomb;
    }
    return NULL;
}

void ParkItemBomb(void *object) {
    ItemBomb *bomb;

    bomb = object;
    bomb->mBouncingItemObject.mItemObject.mFlags &= ~0x8000;
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot(&bomb->mBouncingItemObject.mItemObject);
    bomb->mVisible = FALSE;
    SetStateMachineState(&bomb->mStateMachine, 3);
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
        bomb->mBouncingItemObject.mItemObject.mFlags |= 0x80;
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
    pooledMapObject->mMapObject.mAlpha = 0x1f;
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
    SetStateMachineState(&bomb->mStateMachine, 0);
    bomb->mTimer = 0x12c;
    bomb->mModelFrameTimer = 0;
    bomb->mNearestKartIndex = 8;
    bomb->mNearestKartDistanceSquared = 0x5f592e1;
    bomb->mTimerEndBlockTimer = 0;
    bomb->mHitSpinsKart = FALSE;
    bomb->mReflectFactor = 0xccd;
    bomb->mTimer = timerStart;
    bomb->mIsThrown = 1;
    InitBouncingItem(&bomb->mBouncingItemObject, 3, velocity);
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemBomb;
    }
    if (pooledMapObject != NULL) {
        pooledMapObject->mMapObject.mFlags &= ~2;
        pooledMapObject->mMapObject.mFlags &= ~8;
        pooledMapObject->mMapObject.mAlpha = 0x1f;
        pooledMapObject->mMapObject.mFlags &= ~4;
        if (pooledMapObject->mMapObject.mKind != MAP_OBJECT_KIND_KURIBO) {
            pooledMapObject->mMapObject.mFlags &= ~1;
        }
    }
    *bombSlot = NULL;
}

BOOL IsItemBombState2(ItemObject *object) {
    ItemBomb *bomb;

    bomb = (ItemBomb *) object;
    return bomb->mStateMachine.mState == 2;
}

void ReleaseItemBomb(void **bombSlot) {
    ItemBomb *bomb;
    ItemBox *pooledMapObject;

    bomb = *bombSlot;
    SetStateMachineState(&bomb->mStateMachine, 0);
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

    bomb = StartItemObjectOrZero(9, 8, gItemBombVec3UnitY, gItemBombVec3UnitY);
    if (bomb == NULL) {
        return NULL;
    }
    if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        bomb->mBouncingItemObject.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot(&bomb->mBouncingItemObject.mItemObject);
    bomb->mVisible = FALSE;
    SetStateMachineState(&bomb->mStateMachine, 3);
    bomb->mModelFrameTimer = 0;
    return bomb;
}

void *StartItemBombWithMapObject(void *mapObject, s32 offsetY) {
    ItemBomb *bomb;
    ItemBox *pooledMapObject;

    pooledMapObject = mapObject;
    bomb = StartItemObjectOrZero(9, 8, gItemBombVec3UnitY, gItemBombVec3UnitY);
    if (bomb == NULL) {
        bomb = NULL;
    } else {
        if ((bomb->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
            bomb->mBouncingItemObject.mItemObject.mAdvance = NULL;
        }
        FreeItemObjectCollisionSlot(&bomb->mBouncingItemObject.mItemObject);
        bomb->mVisible = FALSE;
        SetStateMachineState(&bomb->mStateMachine, 3);
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

Vec3 *GetItemBombState2Info(ItemBomb *bomb, s32 *stateFrames, s32 *scaledScaleZ) {
    *stateFrames = bomb->mStateMachine.mStateFrames;
    *scaledScaleZ = MUL_FIXED12_NO_ROUND(bomb->mBouncingItemObject.mItemObject.mScale.z, gItemBombState2InverseLimit);
    return &bomb->mBouncingItemObject.mItemObject.mPos;
}

#pragma thumb on

void SetupItemBombKind(void) {
    s32 engineIndex;

    gItemBombState2ScaleLimit = 0x18006;
    gItemBombState2InverseLimit = FX_Div(0x1000, 0x18006);
    gItemBombState2ScaleStep = 0x2148;
    gItemBombState2MaxRadiusSquared = MUL_FIXED12_NO_ROUND(gItemBombState2ScaleLimit, gItemKinds[9].mRadius);
    gItemBombState2MaxRadiusSquared >>= 12;
    gItemBombState2MaxRadiusSquared *= gItemBombState2MaxRadiusSquared;
    engineIndex = gRaceSetup->mEngineIndex;
    switch (engineIndex) {
        case 0:
            gItemBombTimerLimit = 0xb4;
            break;
        case 1:
            gItemBombTimerLimit = 0x96;
            break;
        default:
            gItemBombTimerLimit = 0x78;
            break;
    }
}

#pragma thumb off
