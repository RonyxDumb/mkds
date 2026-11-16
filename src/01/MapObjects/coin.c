#include "01/MapObjects/coin.h"
#include "01/MapObjects/coin_shadow.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
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
#include "Main/MapObjects/group_follower_init.h"

u16 gCoinShadowRotationIndex;

MapObjectKindDescriptor gCoinKindDescriptor = {0,
                                               {0, 0},
                                               0x104,
                                               SetMissionRunCoinCallbacks,
                                               CreateCoinKindData,
                                               CreateCoinDrawList,
                                               CreateCoinShadowDrawList,
                                               NULL,
                                               CreateCoinUpdateList,
                                               NULL,
                                               {NULL, NULL, NULL, NULL}};
const u16 gCoinShadowRotationAngles[3] = {0, 0xe38, 0x1c71};
MapObjectModel *gCoinModel;

void ResetCoinShadowRotationIndex(void) {
    gCoinShadowRotationIndex = 0;
}

void AdvanceCoinShadowRotationIndex(void) {
    s32 nextIndex = gCoinShadowRotationIndex + 1;
    if (nextIndex >= 3) {
        nextIndex = 0;
    }
    gCoinShadowRotationIndex = nextIndex;
}

void DrawCoinShadow(void *mapObjectList, Coin *coin, void *viewMatrix, u32 mapObjectAlpha) {
    s32 gxArgument;
    s32 scaleFactor;
    Vec3 shadowPosition;
    MtxFx33 rotationMatrix;
    Vec3 scale;
    Vec3 shadowScale;

    if (coin->mScaleFactor > 0 && coin->mModelAlpha != 0 && (coin->mMapObject.mFlags & MAP_OBJECT_FLAG_DISABLED) == 0 &&
        (s32) (coin->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK) < 0x3d090) {
        shadowPosition.x = coin->mMapObject.mPos.x;
        shadowPosition.y = coin->mMapObject.mPos.y - 0x16000;
        shadowPosition.z = coin->mMapObject.mPos.z;
        gxArgument = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &gxArgument, 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&shadowPosition), 0xc);
        scaleFactor = coin->mScaleFactor;
        if (scaleFactor < COIN_SCALE_FULL) {
            scale.x = scaleFactor;
            scale.y = scaleFactor;
            scale.z = scaleFactor;
            NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
        }
        NNS_G3dGeBufferOP_N(0x1b, &coin->mMapObject.mScale, 3);
        MTX_RotY33_(&rotationMatrix, FX_CosIdx(gCoinShadowRotationAngles[gCoinShadowRotationIndex]),
                    FX_SinIdx(gCoinShadowRotationAngles[gCoinShadowRotationIndex]));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
        shadowScale.x = 0x199a;
        shadowScale.y = 0x2000;
        shadowScale.z = 0x199a;
        NNS_G3dGeBufferOP_N(0x1b, &shadowScale, 3);
        DrawJgShadow(8, mapObjectAlpha);
    }
}

void StartCoinRiseOverKart(Coin *coin, Kart *kart) {
    coin->mTimer = COIN_RISE_TIMER_START;
    coin->mMapObject.mPos.x = kart->mPos.x;
    coin->mMapObject.mPos.y = kart->mPos.y + 0xc000;
    coin->mMapObject.mPos.z = kart->mPos.z;
    coin->mMapObject.mPosStep.y = 0x3000;
    coin->mState = COIN_STATE_RISE_OVER_KART;
    coin->mScaleFactor = COIN_SCALE_START;
    coin->mModelAlpha = MAP_OBJECT_ALPHA_MAX;
    coin->mMapObject.mFlags = coin->mMapObject.mFlags | gCoinHiddenFlag;
    coin->mEffect = StartEffect(0x3f5, &coin->mMapObject.mPos);
    coin->mEffectTimer = COIN_RISE_EFFECT_TIMER_START;
}

void AdvanceCoinNsbtpFrame(Coin *coin, s32 counterAdd) {
    coin->mNsbtpFrameCounter += counterAdd;
    if (coin->mNsbtpFrameCounter >= COIN_NSBTP_FRAME_STEPS) {
        coin->mNsbtpFrameCounter -= COIN_NSBTP_FRAME_STEPS;
        coin->mNsbtpFrameIndex += 1;
        if (coin->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gCoinModel)) {
            coin->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gCoinModel);
        }
    }
}

void StartCoinCountUp(void) {
    Kart *kart;
    Coin *coin;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(0x68));
    if (coin != NULL) {
        StartCoinRiseOverKart(coin, kart);
    }
}

void StartCoinDrop(void) {
    Kart *kart;
    Coin *coin;
    RandomState64 *random;
    s32 angle;
    s32 speed;
    SoundStartParams soundArg;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(0x68));
    if (coin != NULL) {
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        angle = (u16) (((u64) (u32) (random->mValue >> 32) * ANGLE_FULL_TURN) >> 32);
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        speed = (u32) (((u64) (u32) (random->mValue >> 32) * 0x800) >> 32) + 0x800;
        coin->mState = COIN_STATE_DROP;
        coin->mScaleFactor = COIN_SCALE_START;
        coin->mModelAlpha = COIN_LEAVE_KART_ALPHA;
        coin->mMapObject.mPos.x = kart->mPos.x;
        coin->mMapObject.mPos.y = kart->mPos.y + 0x1a000;
        coin->mMapObject.mPos.z = kart->mPos.z;
        coin->mMapObject.mPosStep.x = kart->mVelocity.x + MUL_FIXED12_NO_ROUND(speed, FX_SinIdx(angle));
        coin->mMapObject.mPosStep.y = kart->mVelocity.y + 0x4000;
        coin->mMapObject.mPosStep.z = kart->mVelocity.z + MUL_FIXED12_NO_ROUND(speed, FX_CosIdx(angle));
        coin->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
        soundArg.mSoundId = COIN_LEAVE_KART_SOUND_ID;
        soundArg.mPositionSource = NULL;
        soundArg.mFalloffIndex = SOUND_FALLOFF_SHORT_RANGE;
        soundArg.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        StartSoundFromParams(&soundArg);
    }
}

void StartCoinBossTransfer(void) {
    Kart *kart;
    Coin *coin;
    RandomState64 *random;
    s32 angle;
    s32 speed;
    u8 kartCount;
    MissionRunMapObject *targetObject;
    SoundStartParams soundArg;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(0x68));
    if (coin != NULL) {
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        angle = (u16) (((u64) (u32) (random->mValue >> 32) * ANGLE_FULL_TURN) >> 32);
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        speed = (u32) (((u64) (u32) (random->mValue >> 32) * 0x800) >> 32) + 0x800;
        coin->mState = COIN_STATE_TRANSFER_RISE;
        coin->mScaleFactor = COIN_SCALE_START;
        coin->mModelAlpha = COIN_LEAVE_KART_ALPHA;
        coin->mTimer = COIN_RISE_TIMER_START;
        targetObject = NULL;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            kartCount = 0;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                kartCount = MissionRunGetCurrentKartCount();
            }
            targetObject = GetMissionRunMapObject(kartCount);
        }
        coin->mTargetPos = &targetObject->mMapObject.mPos;
        coin->mMapObject.mPos.x = kart->mPos.x;
        coin->mMapObject.mPos.y = kart->mPos.y + 0x1a000;
        coin->mMapObject.mPos.z = kart->mPos.z;
        coin->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(speed, FX_SinIdx(angle));
        coin->mMapObject.mPosStep.y = 0x4000;
        coin->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(speed, FX_CosIdx(angle));
        soundArg.mSoundId = COIN_LEAVE_KART_SOUND_ID;
        soundArg.mPositionSource = NULL;
        soundArg.mFalloffIndex = SOUND_FALLOFF_SHORT_RANGE;
        soundArg.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        StartSoundFromParams(&soundArg);
    }
}

void AddPendingBossTransferInMissionRun(u32 amount) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingBossTransfer(amount);
    }
}

void SetBossCoinShownCount(s32 shownCount) {
    int coinIndex;
    s32 foundCount;
    MapObjectList *coinList;
    Coin *coin;
    RandomState64 *random;
    u16 angle;

    foundCount = 0;
    coinList = FindMapObjectKindUpdateList(0x68);
    GetKart((u16) gRaceSetup->mEntryIndex);
    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            if (coin->mState == COIN_STATE_TRANSFER_HELD) {
                foundCount++;
                if (foundCount <= shownCount) {
                    if (coin->mTargetPos == NULL) {
                        random = GetMapObjectRandom();
                        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
                        angle = ((u64) (u32) (random->mValue >> 32) * ANGLE_FULL_TURN) >> 32;
                        coin->mScaleFactor = COIN_SCALE_FULL;
                        coin->mModelAlpha = 0;
                        coin->mTargetPos =
                            (Vec3 *) ((gRaceSetup->mMode == MODE_MISSION_RUN
                                           ? (u32) GetMissionRunMapObject(gRaceSetup->mMode == MODE_MISSION_RUN
                                                                              ? MissionRunGetCurrentKartCount()
                                                                              : 0)
                                           : 0) +
                                      4);
                        coin->mMapObject.mPos.x = coin->mTargetPos->x;
                        coin->mMapObject.mPos.y = coin->mTargetPos->y;
                        coin->mMapObject.mPos.z = coin->mTargetPos->z;
                        coin->mMapObject.mPosStep.x = 0;
                        coin->mMapObject.mPosStep.y = 0x4cd;
                        coin->mMapObject.mPosStep.z = 0;
                        coin->mTargetOffset.x = MUL_FIXED12_NO_ROUND(SIN_OF_ANGLE(angle), 0x14000);
                        coin->mTargetOffset.y = -0xa000;
                        coin->mTargetOffset.z = MUL_FIXED12_NO_ROUND(COS_OF_ANGLE(angle), 0x14000);
                    }
                } else {
                    if (coin->mTargetPos != NULL) {
                        coin->mTargetPos = NULL;
                    }
                }
            }
        }
    }
}

void ParkBossCoins(s32 parkCount) {
    MapObjectList *coinList;
    Coin *coin;
    s32 count;
    int coinIndex;

    count = 0;
    coinList = FindMapObjectKindUpdateList(0x68);
    GetKart((u16) gRaceSetup->mEntryIndex);
    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            if (coin->mState == COIN_STATE_TRANSFER_HELD) {
                if (coin->mTargetPos != NULL) {
                    coin->mTargetPos = NULL;
                }
                count++;
                if (count <= parkCount) {
                    if ((coin->mMapObject.mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
                        ParkMapObject(&coin->mMapObject);
                    }
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        AddMissionRunPendingCountUpFromBoss(1);
                    }
                }
            }
        }
    }
}

void StartCoinsFadeOut(void) {
    int coinIndex;
    Coin *coin;
    MapObjectList *coinList;
    NNSSndSeqPlayer **sndHandleSlot;

    coinList = FindMapObjectKindUpdateList(0x68);
    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            if (coin->mState == COIN_STATE_PLACED && (coin->mMapObject.mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
                coin->mMapObject.mPosStep.y = 0x5000;
                coin->mModelAlpha = COIN_LAUNCH_FADE_START_ALPHA;
                coin->mState = COIN_STATE_LAUNCH_FADE;
                coin->mMapObject.mFlags |= gCoinHiddenFlag;
            }
        }
    }
    sndHandleSlot = GetSndHandleSlot(2);
    if ((gRaceSoundKind & 1) && gSoundModeHolder.mSeqStartEnabled != 0) {
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x233);
    }
}

void StartCoinsFadeIn(void) {
    int coinIndex;
    Coin *coin;
    MapObjectList *coinList;
    NNSSndSeqPlayer **sndHandleSlot;

    coinList = FindMapObjectKindUpdateList(0x68);
    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            if (coin->mState == COIN_STATE_HIDDEN_WAIT && (coin->mMapObject.mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
                coin->mMapObject.mPos.x = coin->mMapObject.mCourseMapRow->mPosition.x;
                coin->mMapObject.mPos.y = coin->mMapObject.mCourseMapRow->mPosition.y + 0xa000;
                coin->mMapObject.mPos.z = coin->mMapObject.mCourseMapRow->mPosition.z;
                coin->mMapObject.mPosStep.x = 0;
                coin->mMapObject.mPosStep.y = 0x5000;
                coin->mMapObject.mPosStep.z = 0;
                coin->mBounceY = coin->mMapObject.mCourseMapRow->mPosition.y + 0xe000;
                coin->mState = COIN_STATE_BOUNCE;
                coin->mScaleFactor = COIN_SCALE_FULL;
                coin->mModelAlpha = 0;
                coin->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
            }
        }
    }
    sndHandleSlot = GetSndHandleSlot(2);
    if ((gRaceSoundKind & 1) && gSoundModeHolder.mSeqStartEnabled != 0) {
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x232);
    }
}

void SetMissionRunCoinCallbacks(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        SetMissionRunCountUpCallback(StartCoinCountUp);
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        SetMissionRunDropCallback(StartCoinDrop);
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        SetMissionRunBossTransferCallback(StartCoinBossTransfer);
    }
}

u8 CollideKartWithCoin(Coin *coin, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    u8 firstResponse = *firstResponsePtr;
    u8 secondResponse = *secondResponsePtr;

    if (kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) {
        return 0;
    }
    if (firstResponse == 1) {
        if (coin->mState != COIN_STATE_DROP && coin->mState != COIN_STATE_TRANSFER_RISE &&
            coin->mState != COIN_STATE_TRANSFER_FLY) {
            ParkMapObject(&coin->mMapObject);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunPendingCountUp(1);
            }
        }
    }
    return secondResponse;
}

void LoadCoin(MapObjectList *drawList) {
    gCoinModel = LoadMapObjectModelAnimated(drawList, "coin.nsbmd");
    LoadMapObjectModelNsbtpAnimation(gCoinModel, "coin.nsbtp");
    SetMapObjectModelPolygonId(gCoinModel, 0x3f);
    SetMapObjectModelLightEnableFlag(gCoinModel, 2);
    SetNsbmdEmiAll(gCoinModel->mAnimatedModel, 0x294a);
    drawList->mSortByDistance = 1;
}

void DrawCoin(void *mapObjectList, Coin *coin) {
    s32 gxArgument;
    Vec3 scale;
    u32 alpha;
    s32 scaleFactor;

    if (coin->mScaleFactor > 0 && coin->mModelAlpha != 0) {
        gxArgument = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, (&gxArgument), 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&coin->mMapObject.mPos), 0xc);
        scaleFactor = coin->mScaleFactor;
        if (scaleFactor != COIN_SCALE_FULL) {
            scale.x = scaleFactor;
            scale.y = scaleFactor;
            scale.z = scaleFactor;
            NNS_G3dGeBufferOP_N(0x1b, (&scale), 3);
        }
        NNS_G3dGeBufferOP_N(0x1b, (&coin->mMapObject.mScale), 3);
        SetMapObjectModelPolygonId(gCoinModel, AllocPolygonIdWrapping());
        alpha = coin->mModelAlpha;
        if (alpha >= 0x1f) {
            alpha = 0x1f;
        }
        SetMapObjectModelAlpha(gCoinModel, alpha);
        SetMapObjectModelNsbtpFrameIndex(gCoinModel, coin->mNsbtpFrameIndex);
        QueueMapObjectModelMaterial(mapObjectList, gCoinModel);
        DrawMapObjectModel(mapObjectList, gCoinModel, coin);
    }
}

void InitCoinObjects(MapObjectList *coinList) {
    int coinIndex;
    Coin *coin;
    s32 speed;

    if (coinList != NULL) {
        for (coinIndex = 0; coinIndex < coinList->mMapObjectCount && (coin = coinList->mMapObjects[coinIndex]) != NULL;
             coinIndex++) {
            coin->mPosCopy = coin->mMapObject.mCourseMapRow->mPosition;
            coin->mMapObject.mPos = coin->mPosCopy;
            coin->mMapObject.mPos.y = coin->mMapObject.mPos.y + 0xe000;
            if (coin->mMapObject.mCourseMapRow->mGroupIndex >= 0) {
                InitGroupFollower(&coin->mFollower, coin->mMapObject.mCourseMapRow, 0);
                speed = TO_FIXED12(coin->mMapObject.mCourseMapRow->mSettings[0]) / 100;
                coin->mFollower.mSpeed = speed;
                coin->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                    speed, coin->mFollower.mPath->mSegments[coin->mFollower.mSegmentIndex].mInverseProgressLength);
            } else {
                coin->mFollower.mGroupIndex = GROUP_FOLLOWER_NO_GROUP;
            }
            coin->mScaleFactor = COIN_SCALE_FULL;
            if (coin->mMapObject.mCourseMapRow->mSettings[1] == 0) {
                coin->mModelAlpha = MAP_OBJECT_ALPHA_MAX;
            } else {
                coin->mModelAlpha = 0;
            }
        }
    }
}

void CoinBeforeObjectsNop(void) {}

void UpdateCoin(void *mapObjectList, Coin *coin) {
    s32 newAlpha;
    switch (coin->mState) {
        case COIN_STATE_BOUNCE:
            newAlpha = coin->mModelAlpha + 1;
            if (newAlpha >= 31) {
                newAlpha = 31;
            }
            coin->mModelAlpha = newAlpha;
            AdvanceCoinNsbtpFrame(coin, 1);
            coin->mMapObject.mPosStep.y -= 0x333;
            VEC_Add(&coin->mMapObject.mPos, &coin->mMapObject.mPosStep, &coin->mMapObject.mPos);
            if (coin->mMapObject.mPos.y <= coin->mBounceY) {
                coin->mMapObject.mPos.y = coin->mBounceY;
                if (coin->mMapObject.mPosStep.y <= 0) {
                    coin->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(coin->mMapObject.mPosStep.y, -0x800);
                    if (coin->mMapObject.mPosStep.y < 0x1000) {
                        coin->mMapObject.mPosStep.x = 0;
                        coin->mMapObject.mPosStep.y = 0;
                        coin->mMapObject.mPosStep.z = 0;
                        coin->mState = COIN_STATE_PLACED;
                    }
                    StartSoundAtPositionIfNear(0x1d8, &coin->mMapObject.mPos, SOUND_FALLOFF_SHORT_RANGE);
                }
            }
            break;
        case COIN_STATE_PLACED: {
            u16 radius;
            s32 kartIndex;
            BOOL found;
            Vec3 *kartPos;
            s32 differenceX;
            s32 differenceZ;
            AdvanceCoinNsbtpFrame(coin, 1);
            if (coin->mFollower.mGroupIndex != GROUP_FOLLOWER_NO_GROUP) {
                AdvanceGroupFollower(&coin->mFollower);
                GetGroupFollowerCurvePosStep(&coin->mFollower, &coin->mMapObject.mPos, &coin->mMapObject.mPosStep);
                coin->mMapObject.mPos.y += 0xe000;
                coin->mPosCopy = coin->mMapObject.mPos;
            } else {
                coin->mMapObject.mPosStep.x = 0;
                coin->mMapObject.mPosStep.y = 0;
                coin->mMapObject.mPosStep.z = 0;
            }
            if (coin->mMapObject.mCourseMapRow->mSettings[1] != 0) {
                radius = coin->mMapObject.mCourseMapRow->mSettings[1];
                for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
                    kartPos = &GetKart((u16) kartIndex)->mPos;
                    differenceX = kartPos->x - coin->mMapObject.mPos.x;
                    differenceZ = kartPos->z - coin->mMapObject.mPos.z;
                    if (SQUARE_SUM2(differenceX, differenceZ) < (s64) TO_FIXED12(radius) * TO_FIXED12(radius)) {
                        found = TRUE;
                        goto checked;
                    }
                }
                found = FALSE;
            checked:
                if (!found) {
                    goto skip;
                }
            }
            newAlpha = coin->mModelAlpha + 1;
            if (newAlpha >= 31) {
                newAlpha = 31;
            }
            coin->mModelAlpha = newAlpha;
            break;
        skip:
            coin->mModelAlpha = 0;
            break;
        }
        case COIN_STATE_LAUNCH_FADE:
            newAlpha = coin->mModelAlpha - 1;
            if (newAlpha <= 0) {
                newAlpha = 0;
            }
            coin->mModelAlpha = newAlpha;
            AdvanceCoinNsbtpFrame(coin, 4);
            coin->mMapObject.mPos.y += coin->mMapObject.mPosStep.y;
            coin->mMapObject.mPosStep.y -= 0x333;
            if (coin->mModelAlpha == 0) {
                coin->mState = COIN_STATE_HIDDEN_WAIT;
            }
            break;
        case COIN_STATE_RISE_OVER_KART: {
            Kart *kart;
            newAlpha = coin->mModelAlpha - 1;
            if (newAlpha <= 0) {
                newAlpha = 0;
            }
            coin->mModelAlpha = newAlpha;
            AdvanceCoinNsbtpFrame(coin, 4);
            kart = GetKart((u16) gRaceSetup->mEntryIndex);
            coin->mMapObject.mPos.x = kart->mPos.x;
            coin->mMapObject.mPos.y += coin->mMapObject.mPosStep.y;
            coin->mMapObject.mPos.z = kart->mPos.z;
            coin->mMapObject.mPosStep.y -= 0x333;
            if (coin->mTimer-- <= 0) {
                ParkMapObject(&coin->mMapObject);
            } else if (coin->mTimer == COIN_RISE_KART_EFFECT_TIMER) {
                SetupKartFollowEffect(StartEffect(0x3f4, &kart->mPos), kart->mIndex, 0x18);
            }
            if (coin->mEffect != NULL) {
                PlaceEffect(coin->mEffect, &coin->mMapObject.mPos);
                if (coin->mEffectTimer-- < 0) {
                    StopEffectAndClearPointer(&coin->mEffect);
                }
            }
            break;
        }
        case COIN_STATE_DROP: {
            u32 collisionBits;
            Vec3 spherePosition;
            Vec3 pushOut;
            Vec3 normal;
            Vec3 secondNormal;
            newAlpha = coin->mModelAlpha + 1;
            if (newAlpha >= 31) {
                newAlpha = 31;
            }
            coin->mModelAlpha = newAlpha;
            if (coin->mScaleFactor < COIN_SCALE_FULL) {
                coin->mScaleFactor += COIN_SCALE_GROW_PER_FRAME;
                if (coin->mScaleFactor > COIN_SCALE_FULL) {
                    coin->mScaleFactor = COIN_SCALE_FULL;
                }
            }
            AdvanceCoinNsbtpFrame(coin, 1);
            coin->mMapObject.mPosStep.y -= 0x333;
            VEC_Add(&coin->mMapObject.mPos, &coin->mMapObject.mPosStep, &coin->mMapObject.mPos);
            spherePosition.x = coin->mMapObject.mPos.x;
            spherePosition.y = coin->mMapObject.mExtent.x + (coin->mMapObject.mPos.y - 0xe000);
            spherePosition.z = coin->mMapObject.mPos.z;
            if (CollideSphereWithMapObjects(&spherePosition, &coin->mMapObject.mPosStep, coin->mMapObject.mExtent.x,
                                            coin->mMapObject.mCollisionSlotIndex, 2, &pushOut) != 0) {
                VEC_Add(&coin->mMapObject.mPos, &pushOut, &coin->mMapObject.mPos);
                if (LENGTH_SQUARED(pushOut) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&pushOut, &coin->mMapObject.mPosStep);
                }
                coin->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(coin->mMapObject.mPosStep.x, 0x1400);
                coin->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(coin->mMapObject.mPosStep.y, 0x1400);
                coin->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(coin->mMapObject.mPosStep.z, 0x1400);
            }
            if (CollideSphereWithCourse(&spherePosition, NULL, 0, coin->mMapObject.mExtent.x, 1,
                                        coin->mMapObject.mCollisionSlotIndex, &pushOut, &normal, &secondNormal,
                                        &collisionBits, NULL, NULL, NULL, NULL) != 0) {
                VEC_Add(&coin->mMapObject.mPos, &pushOut, &coin->mMapObject.mPos);
                if (collisionBits & 0x214300) {
                    BounceVelocityOffSurface(&coin->mMapObject.mPosStep, &secondNormal, 0x1000, 0x1000, 0xc00,
                                             &coin->mMapObject.mPosStep);
                    if ((s64) coin->mMapObject.mPosStep.x * coin->mMapObject.mPosStep.x +
                            (s64) coin->mMapObject.mPosStep.y * coin->mMapObject.mPosStep.y +
                            (s64) coin->mMapObject.mPosStep.z * coin->mMapObject.mPosStep.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&coin->mMapObject.mPosStep, &coin->mMapObject.mPosStep);
                    }
                    coin->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(coin->mMapObject.mPosStep.x, 0x1400);
                    coin->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(coin->mMapObject.mPosStep.y, 0x1400);
                    coin->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(coin->mMapObject.mPosStep.z, 0x1400);
                }
                if ((collisionBits & 0x1e34ef) && coin->mMapObject.mPosStep.y <= 0) {
                    coin->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(coin->mMapObject.mPosStep.y, -0x800);
                    if (coin->mMapObject.mPosStep.y < 0x1000) {
                        coin->mMapObject.mPosStep.x = 0;
                        coin->mMapObject.mPosStep.y = 0;
                        coin->mMapObject.mPosStep.z = 0;
                        coin->mState = COIN_STATE_PLACED;
                    }
                    StartSoundAtPositionIfNear(0x1d8, &coin->mMapObject.mPos, SOUND_FALLOFF_SHORT_RANGE);
                }
                if ((collisionBits & 0x800) || coin->mMapObject.mPos.y < 0) {
                    coin->mState = COIN_STATE_FADE_OUT_DROP;
                }
            }
            coin->mPosCopy.x = coin->mMapObject.mPos.x;
            coin->mPosCopy.z = coin->mMapObject.mPos.z;
            break;
        }
        case COIN_STATE_FADE_OUT_DROP:
            AdvanceCoinNsbtpFrame(coin, 1);
            coin->mMapObject.mPosStep.y -= 0x333;
            VEC_Add(&coin->mMapObject.mPos, &coin->mMapObject.mPosStep, &coin->mMapObject.mPos);
            newAlpha = coin->mModelAlpha - 1;
            if (newAlpha > 0) {
                coin->mModelAlpha = newAlpha;
                break;
            }
            if (coin->mMapObject.mCourseMapRow->mSettings[2] != 0) {
                coin->mState = COIN_STATE_TRANSFER_HELD;
                coin->mScaleFactor = COIN_SCALE_FULL;
                coin->mModelAlpha = 0;
                coin->mMapObject.mFlags |= gCoinHiddenFlag;
                if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                    AddMissionRunBossCount(1);
                }
            } else {
                coin->mMapObject.mPos.x = coin->mMapObject.mCourseMapRow->mPosition.x;
                coin->mMapObject.mPos.y = coin->mMapObject.mCourseMapRow->mPosition.y + 0x64000;
                coin->mMapObject.mPos.z = coin->mMapObject.mCourseMapRow->mPosition.z;
                coin->mMapObject.mPosStep.x = 0;
                coin->mMapObject.mPosStep.y = 0;
                coin->mMapObject.mPosStep.z = 0;
                coin->mBounceY = coin->mMapObject.mCourseMapRow->mPosition.y + 0xe000;
                coin->mState = COIN_STATE_BOUNCE;
                coin->mScaleFactor = COIN_SCALE_FULL;
                coin->mModelAlpha = 0;
                coin->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
            }
            break;
        case COIN_STATE_TRANSFER_RISE:
            newAlpha = coin->mModelAlpha + 1;
            if (newAlpha >= 31) {
                newAlpha = 31;
            }
            coin->mModelAlpha = newAlpha;
            if (coin->mScaleFactor < COIN_SCALE_FULL) {
                coin->mScaleFactor += COIN_SCALE_GROW_PER_FRAME;
                if (coin->mScaleFactor > COIN_SCALE_FULL) {
                    coin->mScaleFactor = COIN_SCALE_FULL;
                }
            }
            AdvanceCoinNsbtpFrame(coin, 1);
            coin->mMapObject.mPosStep.y -= 0x333;
            VEC_Add(&coin->mMapObject.mPos, &coin->mMapObject.mPosStep, &coin->mMapObject.mPos);
            if (coin->mMapObject.mPosStep.y <= 0) {
                coin->mState = COIN_STATE_TRANSFER_FLY;
            }
            break;
        case COIN_STATE_TRANSFER_FLY:
            if (coin->mScaleFactor < COIN_SCALE_FULL) {
                coin->mScaleFactor += COIN_SCALE_GROW_PER_FRAME;
                if (coin->mScaleFactor > COIN_SCALE_FULL) {
                    coin->mScaleFactor = COIN_SCALE_FULL;
                }
            }
            AdvanceCoinNsbtpFrame(coin, 1);
            if (coin->mMapObject.mPos.x < coin->mTargetPos->x) {
                coin->mMapObject.mPosStep.x += 0x400;
            } else if (coin->mMapObject.mPos.x > coin->mTargetPos->x) {
                coin->mMapObject.mPosStep.x -= 0x400;
            }
            if (coin->mMapObject.mPos.y < coin->mTargetPos->y) {
                coin->mMapObject.mPosStep.y += 0x400;
            } else if (coin->mMapObject.mPos.y > coin->mTargetPos->y) {
                coin->mMapObject.mPosStep.y -= 0x400;
            }
            if (coin->mMapObject.mPos.z < coin->mTargetPos->z) {
                coin->mMapObject.mPosStep.z += 0x400;
            } else if (coin->mMapObject.mPos.z > coin->mTargetPos->z) {
                coin->mMapObject.mPosStep.z -= 0x400;
            }
            VEC_Add(&coin->mMapObject.mPos, &coin->mMapObject.mPosStep, &coin->mMapObject.mPos);
            if (coin->mTimer-- <= 0) {
                coin->mTimer = 0;
                newAlpha = coin->mModelAlpha - 1;
                if (newAlpha <= 0) {
                    newAlpha = 0;
                }
                coin->mModelAlpha = newAlpha;
                if (coin->mModelAlpha < 1) {
                    coin->mState = COIN_STATE_TRANSFER_HELD;
                    coin->mScaleFactor = COIN_SCALE_FULL;
                    coin->mModelAlpha = 0;
                    coin->mTargetPos = NULL;
                    coin->mMapObject.mFlags |= gCoinHiddenFlag;
                }
            }
            break;
        case COIN_STATE_TRANSFER_HELD:
            if (coin->mTargetPos != NULL) {
                newAlpha = coin->mModelAlpha + 2;
                if (newAlpha >= 31) {
                    newAlpha = 31;
                }
                coin->mModelAlpha = newAlpha;
            } else {
                newAlpha = coin->mModelAlpha - 2;
                if (newAlpha <= 0) {
                    newAlpha = 0;
                }
                coin->mModelAlpha = newAlpha;
            }
            if (coin->mModelAlpha != 0 && coin->mTargetPos != NULL) {
                AdvanceCoinNsbtpFrame(coin, 1);
                coin->mMapObject.mPosStep.y -= 0x14;
                VEC_Add(&coin->mTargetOffset, &coin->mMapObject.mPosStep, &coin->mTargetOffset);
                VEC_Add(&coin->mTargetOffset, coin->mTargetPos, &coin->mMapObject.mPos);
                if ((s64) ((const Vec3 *) &coin->mTargetOffset)->x * ((const Vec3 *) &coin->mTargetOffset)->x +
                        (s64) ((const Vec3 *) &coin->mTargetOffset)->z * ((const Vec3 *) &coin->mTargetOffset)->z >=
                    0x190000000LL) {
                    coin->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(coin->mTargetOffset.x, -0x14);
                    coin->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(coin->mTargetOffset.z, -0x14);
                }
                if (coin->mTargetOffset.y < -0xa000) {
                    coin->mMapObject.mPosStep.y = 0x4cd;
                }
            }
            break;
        case COIN_STATE_HIDDEN_WAIT:
            break;
    }
}

MapObjectKindData *CreateCoinKindData(void) {
    return CreateMapObjectKindData(&CollideKartWithCoin, NULL, NULL, 1, 1);
}

MapObjectList *CreateCoinDrawList(void) {
    return CreateMapObjectDrawList1(LoadCoin, DrawCoin, NULL);
}

MapObjectList *CreateCoinShadowDrawList(void) {
    return CreateMapObjectDrawList1(ResetCoinShadowRotationIndex, DrawCoinShadow, AdvanceCoinShadowRotationIndex);
}

MapObjectList *CreateCoinUpdateList(void) {
    return CreateMapObjectUpdateList(InitCoinObjects, UpdateCoin, CoinBeforeObjectsNop);
}
