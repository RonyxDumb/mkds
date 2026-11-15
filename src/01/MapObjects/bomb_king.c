#include "01/MapObjects/bomb_king.h"
#include "01/code_0218b298.h"
#include "01/code_02188218.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/map_object_sound.h"
#include "01/code_0218b278.h"
#include "01/code_0218b034.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/code_02187bfc.h"
#include "01/code_02187c4c.h"
#include "01/code_02187d14.h"
#include "Main/Item/item_bomb.h"
#include "code_02147cd8.h"
#include "01/code_0218affc.h"
#include "01/code_0218add0.h"
#include "01/code_02188158.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "Main/Kart/camera.h"
#include "01/code_0218ad68.h"
#include "01/code_0218ac04.h"
#include "01/code_02187eb0.h"
#include "01/code_02187000.h"
#include "01/code_02187e78.h"
#include "01/code_02188000.h"
#include "01/code_02188e24.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/code_0218a000.h"
#include "01/unk_021a7000.h"
#include "01/code_0218a568.h"
#include "01/code_02187c60.h"
#include "01/code_02188de0.h"
#include "01/code_0218b000.h"
#include "Main/Course/code_02042044.h"
#include "Main/Kart/kart_drift.h"
#include "01/code_0218a444.h"
#include "01/code_0218a41c.h"
#include "01/code_02188260.h"
#include "01/code_0218a3ec.h"
#include "01/code_021882b8.h"
#include "Main/System/heap.h"
#include "01/Race/mission_run_state.h"
#include "01/code_02188484.h"
#include "code_0201c528.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "01/code_0218d520.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/snd_handle_start.h"
#include "Main/Sound/data_0210b000.h"

const u32 gBombKingSkipKindSoundFlag = 0x40000000;
const u16 gBombKingSkipListCallbackFlag = 8;
const u16 gBombKingJumpFlag = 0x20;
const u16 gBombKingDisabledFlag = 1;
const u16 gBombKingSkipViewTestFlag = 2;
SoundStartParams gBombKingEndSoundParams = {0x23d, NULL, 0xc, 0};
MapObjectKindDescriptor gBombKingKindDescriptor = {0,
                                                   {0, 0},
                                                   0x30c,
                                                   InitBombKingMapObject,
                                                   CreateBombKingKindData,
                                                   CreateBombKingDrawList,
                                                   NULL,
                                                   NULL,
                                                   CreateBombKingUpdateList,
                                                   NULL,
                                                   {NULL, NULL, NULL, NULL}};

u16 GetAbsoluteCounterWrapper(MissionRunMapObject *mapObject) {
    return GetAbsoluteCounter(mapObject);
}

void BombKingJumpKartCollisionCallback(MissionRunMapObject *mapObject) {
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_SCALE_EFFECT;
    mapObject->mUnk_000.mDistanceSquaredAndFlags |= gBombKingSkipKindSoundFlag;
}

void BombKingFirstSoundCallback(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x237);
}

void BombKingSecondSoundCallback(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x237);
}

void SetBombKingSoundCallbacks(MissionRunMapObject *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 1, BombKingFirstSoundCallback, 0x1f, BombKingSecondSoundCallback);
}

void ThrowStoredItemBomb(MissionRunMapObject *mapObject) {
    Vec3 velocity;

    if (IsItemBombStored(mapObject)) {
        velocity.x = (MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_134, FX_SinIdx((u16) mapObject->mMoveAngle)));
        velocity.y = mapObject->mPrm->mUnk_138;
        velocity.z = (MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_134, FX_CosIdx((u16) mapObject->mMoveAngle)));
        ThrowOrReleaseStoredItemBomb(mapObject, &velocity, mapObject->mPrm->mUnk_13c);
    }
}

void ThrowItemBombsInRing(MissionRunMapObject *mapObject) {
    RandomState64 *rng;
    s32 angle;
    s32 bombIndex;
    Vec3 pos;

    rng = GetMapObjectRandom();
    rng->mValue = (s64) rng->mMultiplier * (s64) rng->mValue + rng->mIncrement;
    angle = (u16) (((rng->mValue >> 32) << 16) >> 32);
    for (bombIndex = 0; bombIndex < 3; bombIndex++) {
        Vec3 vel = {0, 0, 0};
        angle += 0x5555;
        if (GetAbsoluteCounter(mapObject) == 0) {
            pos.x =
                mapObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_14c, SIN_OF_ANGLE((u16) angle));
            pos.y = mapObject->mUnk_000.mPos.y + mapObject->mPrm->mUnk_150;
            pos.z =
                mapObject->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_14c, COS_OF_ANGLE((u16) angle));
        } else {
            pos.x =
                mapObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_154, SIN_OF_ANGLE((u16) angle));
            pos.y = mapObject->mUnk_000.mPos.y + mapObject->mPrm->mUnk_158;
            pos.z =
                mapObject->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_154, COS_OF_ANGLE((u16) angle));
        }
        if (bombIndex == 0) {
            ThrowItemBombFromPosition(StartItemBomb(), &pos, &vel, mapObject->mPrm->mUnk_15c);
        } else {
            ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &pos, &vel, mapObject->mPrm->mUnk_160);
        }
    }
    StartEffectAtRowHeight(mapObject, 0x2000, 0, 0x3ae, 0x410, 0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x236);
}

void StartBombKingEffectAndSound(MissionRunMapObject *mapObject) {
    StartEffectAtRowHeight(mapObject, (0x00002000u), 0, (0x000003aeu), (0x00000410u), 0);
    StartMapObjectSound(&mapObject->mUnk_000, (0x00000236u));
}

void ThrowItemBombsInRingAndCenter(MissionRunMapObject *mapObject) {
    RandomState64 *rng;
    s32 angle;
    s32 bombIndex;
    Vec3 pos;

    rng = GetMapObjectRandom();
    rng->mValue = (s64) rng->mMultiplier * (s64) rng->mValue + rng->mIncrement;
    angle = (u16) (((rng->mValue >> 32) << 16) >> 32);
    for (bombIndex = 0; bombIndex < 3; bombIndex++) {
        Vec3 vel = {0, 0, 0};
        angle += 0x5555;
        pos.x = mapObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_1e4, SIN_OF_ANGLE((u16) angle));
        pos.y = mapObject->mUnk_000.mPos.y;
        pos.z = mapObject->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_1e4, COS_OF_ANGLE((u16) angle));
        ThrowItemBombFromPosition(StartItemBomb(), &pos, &vel, mapObject->mPrm->mUnk_1e8);
    }
    {
        Vec3 pos2;
        Vec3 vel2 = {0, 0, 0};
        pos2.x = mapObject->mUnk_000.mPos.x;
        pos2.y = mapObject->mUnk_000.mPos.y;
        pos2.z = mapObject->mUnk_000.mPos.z;
        ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &pos2, &vel2, mapObject->mPrm->mUnk_1ec);
    }
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartBombKingJumpLandState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_200, mapObject->mPrm->mUnk_204, NULL);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x412, 0);
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    mapObject->mUnk_000.mFlags &= ~0x20;
    SetKartCollisionCallback(mapObject, NULL);
}

void StartBombKingJumpFallState(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_1fc;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1f4, mapObject->mPrm->mUnk_1f8);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetCourseCollisionCallback(mapObject, StartBombKingJumpLandState);
    mapObject->mGravityEnabled = TRUE;
    StartMapObjectSound(&mapObject->mUnk_000, 0x23a);
    SetKartCollisionCallback(mapObject, BombKingJumpKartCollisionCallback);
}

void StartBombKingJumpThrowBombsState(MissionRunMapObject *mapObject) {
    ThrowItemBombsInRingAndCenter(mapObject);
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1dc, mapObject->mPrm->mUnk_1e0);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1f0, &StartBombKingJumpFallState);
    mapObject->mGravityEnabled = FALSE;
}

void StartBombKingJumpToEntryState(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1c0, mapObject->mPrm->mUnk_1c4);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_1d0, mapObject->mPrm->mUnk_1d4);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1c8, mapObject->mPrm->mUnk_1cc);
    SetVelocity(mapObject, &velocity);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1d8, StartBombKingJumpThrowBombsState);
    mapObject->mGravityEnabled = FALSE;
}

void StartBombKingJumpState(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_1b8;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1a8, mapObject->mPrm->mUnk_1ac);
    SetVelocity(mapObject, &velocity);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1b0, mapObject->mPrm->mUnk_1b4);
    SetCourseCollisionCallback(mapObject, StartBombKingJumpLandState);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1bc, StartBombKingJumpToEntryState);
    StartMapObjectSound(&mapObject->mUnk_000, 0x239);
    mapObject->mUnk_000.mFlags |= gBombKingJumpFlag;
}

void StartBombKingJumpWaitState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_198, mapObject->mPrm->mUnk_19c);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1a0, &StartBombKingJumpState);
    StartMapObjectSound(&mapObject->mUnk_000, 0x238);
}

void StartBombKingJumpCycle(MissionRunMapObject *mapObject) {
    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_17c, mapObject->mPrm->mUnk_180);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_18c, mapObject->mPrm->mUnk_190);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_184, mapObject->mPrm->mUnk_188);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_194, &StartBombKingJumpWaitState);
    SetBombKingSoundCallbacks(mapObject);
}

void StartBombKingThrowBombsState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_140, mapObject->mPrm->mUnk_144, NULL);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_148, ThrowItemBombsInRing);
}

void StoreNewItemBombAndStartThrow(MissionRunMapObject *mapObject) {
    void *bomb;

    if (IsItemBombStored(mapObject) == 0) {
        bomb = StartItemBomb();
        if (bomb != NULL) {
            ReleaseAndSetItemBomb(mapObject, (bomb));
        }
    }
    if (IsItemBombStored(mapObject) != 0) {
        StartMapObjectState(mapObject, 3, NULL);
        StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_0d4, mapObject->mPrm->mUnk_0d8, 0);
        SetSpeedAndClearTarget(mapObject, 0);
        SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_0dc, ThrowStoredItemBomb);
    }
    StartMapObjectSound(&mapObject->mUnk_000, 0x23c);
}

void StartBombKingChaseState(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetEntryKartInRange(mapObject, mapObject->mPrm->mUnk_0c0, mapObject->mPrm->mUnk_0c4);
    if (kart != NULL) {
        StartMapObjectState(mapObject, 3, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_104, mapObject->mPrm->mUnk_108);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_0bc, mapObject->mPrm->mUnk_0bc);
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_0b8);
        SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_0cc, mapObject->mPrm->mUnk_0d0, &kart->mPos,
                                &StoreNewItemBombAndStartThrow);
        StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_0c8, 0);
        SetBombKingSoundCallbacks(mapObject);
    } else {
        StopMapObjectState(mapObject);
    }
}

void StartItemBombThrow(MissionRunMapObject *mapObject) {
    if (IsItemBombStored(mapObject) != 0) {
        StartMapObjectState(mapObject, 3, NULL);
        StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_0d4, mapObject->mPrm->mUnk_0d8, 0);
        SetSpeedAndClearTarget(mapObject, 0);
        SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_0dc, ThrowStoredItemBomb);
        StartMapObjectSound(&mapObject->mUnk_000, 0x23c);
    }
}

void StartBombKingStoreFoundItemBombState(MissionRunMapObject *mapObject) {
    ItemBomb *bomb;
    Kart *kart;

    bomb = FindItemBombInRange(mapObject, mapObject->mPrm->mUnk_11c, mapObject->mPrm->mUnk_120);
    if (bomb != NULL) {
        kart = GetEntryKartInRange(mapObject, mapObject->mPrm->mUnk_0c0, mapObject->mPrm->mUnk_0c4);
        if (kart != NULL) {
            ParkItemBomb(bomb);
            ReleaseAndSetItemBomb(mapObject, bomb);
            StartMapObjectState(mapObject, 3, NULL);
            StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_0ec, mapObject->mPrm->mUnk_0f0);
            TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_0f8, mapObject->mPrm->mUnk_0f8);
            SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
            SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_0f4);
            SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_0cc, mapObject->mPrm->mUnk_0d0, &kart->mPos,
                                    &StartItemBombThrow);
            SetBombKingSoundCallbacks(mapObject);
        } else {
            ParkItemBomb(bomb);
            ReleaseAndSetItemBomb(mapObject, bomb);
            StartItemBombThrow(mapObject);
        }
    }
}

void StartBombKingWalkToBombState(MissionRunMapObject *mapObject) {
    ItemBomb *bomb;

    bomb = FindItemBombInRange(mapObject, mapObject->mPrm->mUnk_114, mapObject->mPrm->mUnk_118);
    if (bomb != NULL) {
        StartMapObjectState(mapObject, 3, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_104, mapObject->mPrm->mUnk_108);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_110, mapObject->mPrm->mUnk_110);
        SetAnglePointAndMoveAnglePoint(mapObject, &bomb->mBouncingItemObject.mItemObject.mPos);
        SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_10c);
        SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_11c, mapObject->mPrm->mUnk_120,
                                &bomb->mBouncingItemObject.mItemObject.mPos, &StartBombKingStoreFoundItemBombState);
        StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_124, 0);
        SetBombKingSoundCallbacks(mapObject);
    }
}

void StartBombKingRandomState(MissionRunMapObject *mapObject) {
    u32 randomLimit;
    RandomState64 *rng;
    u32 randomValue;

    randomLimit = (u16) mapObject->mPrm->mUnk_208;
    if (randomLimit == 0x10000) {
        rng = GetMapObjectRandom();
        rng->mValue = rng->mMultiplier * rng->mValue + rng->mIncrement;
        randomValue = (u16) (((rng->mValue >> 32) * 0x10000) >> 32);
    } else {
        rng = GetMapObjectRandom();
        if ((u16) randomLimit == 0) {
            randomValue = 0;
        } else {
            rng->mValue = rng->mMultiplier * rng->mValue + rng->mIncrement;
            if ((u16) randomLimit == 0) {
                randomValue = rng->mValue >> 32;
            } else {
                randomValue = ((rng->mValue >> 32) * (s64) (u16) randomLimit) >> 32;
            }
        }
        randomValue = (u16) randomValue;
    }
    if (randomValue != 0) {
        StartBombKingThrowBombsState(mapObject);
    } else {
        StartBombKingChaseState(mapObject);
    }
}

void StartBombKingWalkState(MissionRunMapObject *mapObject) {
    MissionRunPrm *prm;

    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 2, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_084, mapObject->mPrm->mUnk_088);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_090, mapObject->mPrm->mUnk_090);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_08c);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_09c, &StartBombKingRandomState);
    prm = mapObject->mPrm;
    SetPointInRangeCallback(mapObject, prm->mUnk_094, prm->mUnk_098, &GetCurrentGroupEntry(mapObject)->mPos,
                            &StartBombKingThrowBombsState);
    SetBombKingSoundCallbacks(mapObject);
}

int StartBombKingBounceEffects(MissionRunMapObject *mapObject) {
    if ((mapObject->mCollisionBits & 0x1e34ef) != 0) {
        if (mapObject->mVelocity.y > 0x3333) {
            ReleaseEffects(mapObject);
            StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x411, 0);
            StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x412, 0);
        }
        if (mapObject->mVelocity.y > 0) {
            StartMapObjectSound(&mapObject->mUnk_000, 0x23b);
        }
    }
    return 0;
}

int SwitchToBounceEffectsOnCollision(MissionRunMapObject *mapObject) {
    if ((mapObject->mCollisionBits & 0x1e34ef) != 0) {
        mapObject->mStateFunction = StartBombKingBounceEffects;
    }
    return 0;
}

void StartBombKingStoppedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_174, mapObject->mPrm->mUnk_178, NULL);
    SetItemCollisionCallback(mapObject, (UnkFunc *) &BombKingItemHitCallback);
}

void StartBombKingBounceState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &SwitchToBounceEffectsOnCollision);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_164, mapObject->mPrm->mUnk_168);
    SetStoppedCallback(mapObject, &StartBombKingStoppedState);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mBounceEnabled = TRUE;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &BombKingItemBounceCallback);
}

void StartBombKingStoppedStateAfterHits(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074, NULL);
    SetItemCollisionCallback(mapObject, (UnkFunc *) &BombKingItemHitCallback);
}

void StartBombKingBounceStateAfterHits(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &SwitchToBounceEffectsOnCollision);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_164, mapObject->mPrm->mUnk_168);
    SetStoppedCallback(mapObject, &StartBombKingStoppedStateAfterHits);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mBounceEnabled = TRUE;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &BombKingItemBounceCallback);
}

void StartBombKingItemHitState(MissionRunMapObject *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartBombKingBounceStateAfterHits(mapObject);
    } else {
        StartBombKingBounceState(mapObject);
    }
    IncrementHitCountAndCheckLimit(mapObject);
}

void StartBombKingKartEliminatedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_078, mapObject->mPrm->mUnk_07c);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartBombKingNotEliminatedEffects(MissionRunMapObject *mapObject) {
    SoundStartParams soundRequest;

    StartMapObjectState(mapObject, 8, NULL);
    ReleaseEffects(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x421, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40c, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40e, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40d, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40f, 0);
    soundRequest = gBombKingEndSoundParams;
    soundRequest.mPositionSource = &mapObject->mUnk_000.mPos;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mUnk_000.mPos);
    StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
    mapObject->mUnk_000.mFlags |= gBombKingSkipViewTestFlag;
    mapObject->mUnk_000.mFlags |= gBombKingSkipListCallbackFlag;
    mapObject->mUnk_000.mFlags |= gBombKingDisabledFlag;
}

void StartBombKingKartNotEliminatedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StartStateFrameCountCallback(mapObject, 0x3c, &StartBombKingNotEliminatedEffects);
}

void BombKingStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

s32 StopStateWhenRaceStarted(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

void StartBombKingWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, StopStateWhenRaceStarted);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mWaitForRaceStartAnimationEntry,
                                mapObject->mPrm->mWaitForRaceStartFrameStep);
}

void StartBombKingStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mStartupSecondAnimationEntry,
                                  mapObject->mPrm->mStartupSecondFrameStep, (UnkFunc *) &StartBombKingWaitForRaceStart);
    SetAnimationFrameCallback(mapObject, ((u32) mapObject->mPrm->mUnk_148), ThrowItemBombsInRing);
}

void StartBombKingStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mStartupFirstAnimationEntry,
                                mapObject->mPrm->mStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mStartupFirstFrameCount, &StartBombKingStartupSecond);
    StartMapObjectSound(&mapObject->mUnk_000, 0x00000235u);
}

void StartBombKingChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mChainStartupSecondAnimationEntry,
                                mapObject->mPrm->mChainStartupSecondFrameStep);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_148, StartBombKingEffectAndSound);
}

void StartBombKingChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mChainStartupFirstAnimationEntry,
                                mapObject->mPrm->mChainStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mChainStartupFirstFrameCount,
                                 &StartBombKingChainStartupSecond);
}

void InitBombKingObjects(MapObjectList *list) {
    int objectIndex;
    MissionRunMapObject *mapObject;

    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (mapObject = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            Vec3 offset = {0, 0, 0};
            offset.x = mapObject->mPrm->mUnk_0fc;
            offset.y = mapObject->mPrm->mUnk_100;
            SetNodePositionSourceAndBombOffset(mapObject, 5, (&offset));
            if (GetRaceUseChainCameras() != 0) {
                StartBombKingChainStartupFirst(mapObject);
            } else {
                StartBombKingStartupFirst(mapObject);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) BombKingStandingsEndCallback);
}

void UpdateBombKing(u32 unused, MissionRunMapObject *mapObject) {
    int active;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        active = IsWinnerDecided();
    } else {
        active = 0;
    }
    if (active != 0) {
        if (IsStateNumberBelow(mapObject, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                active = IsKartEliminated((u16) gRaceSetup->mEntryIndex);
            } else {
                active = 0;
            }
            if (active != 0) {
                StartBombKingKartEliminatedState(mapObject);
            } else {
                StartBombKingKartNotEliminatedState(mapObject);
            }
        }
    } else {
        if (IsStateNumberBelow(mapObject, 3) != 0) {
            if (GetAbsoluteCounter(mapObject) >= 2) {
                StartBombKingJumpCycle(mapObject);
            }
        }
        if (IsStateNumberBelow(mapObject, 3) != 0) {
            StartBombKingWalkToBombState(mapObject);
        }
        if (IsStateNumberBelow(mapObject, 2) != 0) {
            StartBombKingWalkState(mapObject);
        }
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitBombKingMapObject(MissionRunMapObject *mapObject) {
    CreateParkedMapObjects(0xc9, 0xa, mapObject);
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) mapObject->mUnk_000.mSound, 0xc, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffs[12].mFarDistanceSquared;
}

void SetBombKingEffectScale(ParticleEmitter *emitter) {
    emitter->mSizeScale = 0x2000;
}

void BombKingItemBounceCallback(MissionRunMapObject *mapObject, ItemObject *itemObject) {
    if (itemObject->mKind == ITEM_OBJECT_KIND_BOMB) {
        if (IsItemBombState2(itemObject) == FALSE) {
            StartEffectWithCallback(0x3a, &itemObject->mPos, NULL, SetBombKingEffectScale);
        }
    }
    mapObject->mItemResponse = ITEM_MAP_OBJECT_RESPONSE_BOUNCE;
    SetItemCollisionCallback(mapObject, (UnkFunc *) BombKingItemBounceCallback);
}

void BombKingItemHitCallback(MissionRunMapObject *mapObject, ItemObject *itemObject) {
    Vec3 velocity;
    s64 scale;

    if (IsItemBombStored(mapObject) != 0) {
        ThrowOrReleaseStoredItemBomb(mapObject, NULL, 0);
    }
    mapObject->mItemResponse = ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT;
    SetItemCollisionCallback(mapObject, (UnkFunc *) BombKingItemHitCallback);
    if (IsStateNumberBelow(mapObject, 7) != 0) {
        velocity.x = mapObject->mUnk_000.mPos.x - itemObject->mPos.x;
        velocity.y = 0;
        velocity.z = mapObject->mUnk_000.mPos.z - itemObject->mPos.z;
        if (LENGTH_SQUARED(velocity) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&velocity, &velocity);
        }
        scale = mapObject->mPrm->mUnk_16c;
        velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, scale);
        velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, scale);
        velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, scale);
        velocity.y = mapObject->mPrm->mUnk_170;
        SetVelocity(mapObject, &velocity);
        StartBombKingItemHitState(mapObject);
    }
}
void InitBombKing(MapObjectList *list) {
    MissionRunMapObject *mapObject;
    MissionRunPrm *prm;
    int objectIndex;

    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (mapObject = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(mapObject);
            }
            InitMissionRunMapObject(list, mapObject, "bomb_king.nsbmd", "bomb_king.nsbca", "bomb_king.prm");
            LoadMissionRunMapObjectShadow(list, mapObject, "sh_circle.nsbmd");
            prm = mapObject->mPrm;
            SetCollisionOffsetAndExtent(mapObject, prm->mCollisionOffsetY, prm->mCollisionExtentXZ, prm->mUnk_20c);
            SetShadowOffsetYAndScale(mapObject, 0, 0x23000);
            SetItemCollisionCallback(mapObject, (UnkFunc *) BombKingItemHitCallback);
        }
    }
}

void DrawBombKing(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

MapObjectKindData *CreateBombKingKindData(void) {
    u32 soundId = 0x23eu;
    void *kartCollisionCallback = &CollideKartWithMissionRunMapObject;
    void *itemCollisionCallback = &CollideItemWithMissionRunMapObject;
    void *sphereHitCallback = &ComputeSphereHitOnMissionRunMapObject;
    return CreateMapObjectKindDataWithSoundIds(kartCollisionCallback, itemCollisionCallback, sphereHitCallback, 0x2u,
                                               0x1u, soundId, 0x0u);
}

MapObjectList *CreateBombKingDrawList(void) {
    return CreateMapObjectDrawList1(InitBombKing, DrawBombKing, ToggleShadowScale);
}

MapObjectList *CreateBombKingUpdateList(void) {
    return CreateMapObjectUpdateList(InitBombKingObjects, UpdateBombKing, NULL);
}
