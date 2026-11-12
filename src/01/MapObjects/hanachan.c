#include "01/MapObjects/hanachan.h"
#include "01/code_0218dce4.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"
#include "01/code_0218d520.h"
#include "01/code_02187d14.h"
#include "01/code_02187eb0.h"
#include "01/code_02188230.h"
#include "01/code_02188cd8.h"
#include "01/code_02187000.h"
#include "01/code_02187e78.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "code_02147cd8.h"
#include "01/code_0218d4c8.h"
#include "01/code_0218d374.h"
#include "01/code_02188da4.h"
#include "01/MapObjects/king_teresa.h"
#include "Main/Sound/snd_handle_start.h"
#include "Main/Sound/sound_handle_pool.h"
#include "01/code_021882b8.h"
#include "Main/System/heap.h"
#include "01/code_02181000.h"
#include "01/unk_021a6000.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_source_init.h"
#include "01/Race/mission_run_state.h"
#include "01/code_0219b250.h"
#include "01/code_02188484.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"

void HanachanItemHitCallback(MissionRunMapObject *mapObject) {
    mapObject->mUnk_2e0 = 0;
    SetItemCollisionCallback(mapObject, HanachanItemHitCallback);
}

void HanachanFirstSoundCallback(MissionRunMapObject *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x248);
    } else if (GetAbsoluteCounter(mapObject) >= 1) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x249);
    } else {
        StartMapObjectSound(&mapObject->mUnk_000, 0x24a);
    }
}

void HanachanSecondSoundCallback(MissionRunMapObject *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x248);
    } else if (GetAbsoluteCounter(mapObject) >= 1) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x249);
    } else {
        StartMapObjectSound(&mapObject->mUnk_000, 0x24a);
    }
}

void SetHanachanSoundCallbacks(MissionRunMapObject *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 0xc, HanachanFirstSoundCallback, 0x20, HanachanSecondSoundCallback);
}

void PlaceHanachanFollowerBehindXz(MissionRunMapObject *mapObject) {
    MissionRunMapObject *previousObject = mapObject->mUnk_0a4;
    int distance;
    u16 oppositeAngle = (previousObject->mAngle + 0x8000);

    switch (mapObject->mUnk_0a8) {
        case 1:
            distance = mapObject->mPrm->mUnk_0c0;
            break;
        case 2:
            distance = mapObject->mPrm->mUnk_0c4;
            break;
        case 3:
            distance = mapObject->mPrm->mUnk_0c8;
            break;
        case 4:
            distance = mapObject->mPrm->mUnk_0cc;
            break;
    }
    mapObject->mUnk_000.mPos.x =
        previousObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(distance, SIN_OF_ANGLE(oppositeAngle));
    mapObject->mUnk_000.mPos.z =
        mapObject->mUnk_0a4->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(distance, COS_OF_ANGLE(oppositeAngle));
}

void TurnHanachanFollowerToPrevious(MissionRunMapObject *mapObject) {
    int diff;
    int step;
    int limit;
    s32 currentAngle;

    mapObject->mUnk_13c = mapObject->mUnk_13c - 1;
    if (mapObject->mUnk_13c <= 0) {
        mapObject->mUnk_13c = 0;
        currentAngle = mapObject->mAngle;
        diff = (u16) (mapObject->mUnk_0a4->mAngle - currentAngle);
        if (diff > 0x8000) {
            diff -= 0x10000;
        }
        limit = mapObject->mAnglePerCall;
        step = diff < -limit ? -limit : (diff > limit ? limit : diff);
        mapObject->mAngle = (u16) (currentAngle + step);
        mapObject->mMoveAngle = mapObject->mAngle;
    }
}

void PlaceHanachanFollowerBehind(MissionRunMapObject *mapObject) {
    MissionRunMapObject *previousObject = mapObject->mUnk_0a4;
    int distance;
    u16 oppositeAngle = (previousObject->mAngle + 0x8000);

    switch (mapObject->mUnk_0a8) {
        case 1:
            distance = mapObject->mPrm->mUnk_0c0;
            break;
        case 2:
            distance = mapObject->mPrm->mUnk_0c4;
            break;
        case 3:
            distance = mapObject->mPrm->mUnk_0c8;
            break;
        case 4:
            distance = mapObject->mPrm->mUnk_0cc;
            break;
    }
    mapObject->mUnk_000.mPos.x =
        previousObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(distance, SIN_OF_ANGLE(oppositeAngle));
    mapObject->mUnk_000.mPos.y = mapObject->mUnk_0a4->mUnk_000.mPos.y;
    mapObject->mUnk_000.mPos.z =
        mapObject->mUnk_0a4->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(distance, COS_OF_ANGLE(oppositeAngle));
}

void CopyHanachanFollowerPreviousAngle(MissionRunMapObject *mapObject) {
    mapObject->mAngle = mapObject->mUnk_0a4->mAngle;
    mapObject->mMoveAngle = mapObject->mAngle;
}

void AdvanceHanachanCounter(MissionRunMapObject *mapObject) {
    ReleaseEffects(mapObject);
    StartEffectAtOffset(mapObject, 0, mapObject->mOffset.y >> 4, 0, 0x427, 0xf);
    StartEffectAtOffset(mapObject, 0, mapObject->mOffset.y >> 4, 0, 0x426, 0xf);
    StartMapObjectSound(&mapObject->mUnk_000, 0x24d);
    DecrementCounterToNegativeLimit(mapObject);
    if (GetAbsoluteCounter(mapObject) == 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x24c);
    } else if (GetAbsoluteCounter(mapObject) >= 3) {
        mapObject->mUnk_0ac = 0;
    }
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, GetAbsoluteCounter(mapObject));
}

void AdvanceHanachanCounterForAll(MissionRunMapObject *mapObject) {
    MapObjectList *list;
    int i;
    MissionRunMapObject *follower;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && (follower = list->mMapObjects[i]) != NULL; i++) {
            StartStateFrameCountCallback(follower, (follower->mUnk_0a8 * 15), (UnkFunc *) AdvanceHanachanCounter);
        }
    }
    AdvanceHanachanCounter(mapObject);
}

void StartHanachanFollowerMoveState(MissionRunMapObject *mapObject) {
    s32 frameOffset;
    float frameIndexValue;
    ModelAnimation *modelAnimation;

    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_088, mapObject->mPrm->mUnk_08c);
    frameOffset = mapObject->mPrm->mUnk_0d0 * mapObject->mUnk_0a8;
    if (frameOffset > 0) {
        frameIndexValue = 0.5f + TO_FIXED12(frameOffset);
    } else {
        frameIndexValue = TO_FIXED12(frameOffset) - 0.5f;
    }
    modelAnimation = mapObject->mNsbmd->mAnimations[0];
    modelAnimation->mHead.mFrameIndex = frameIndexValue;
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mFrame = modelAnimation->mHead.mFrameIndex;
}

void StartHanachanAnimationScaled(MissionRunMapObject *mapObject, int speedPercent) {
    MapObjectList *list;
    int i;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && list->mMapObjects[i] != NULL; i++) {
            StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_088,
                                        (mapObject->mPrm->mUnk_08c * speedPercent / 100));
        }
    }
}

void SetHanachanFollowersTurnTiming(MissionRunMapObject *mapObject, int speedPercent) {
    MapObjectList *list;
    int i;
    MissionRunMapObject *follower;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && (follower = list->mMapObjects[i]) != NULL; i++) {
            follower->mUnk_13c = follower->mPrm->mUnk_0d8 * follower->mUnk_0a8 * 100 / speedPercent;
            follower->mAnglePerCall = mapObject->mPrm->mUnk_0d4 * speedPercent / 100;
        }
    }
}

void SetHanachanSpeedAndTurnToNextEntry(MissionRunMapObject *mapObject, int speedPercent) {
    MissionRunPrm *prm;

    prm = mapObject->mPrm;
    SetSpeedTargetAndPerCall(mapObject, (prm->mUnk_090 * speedPercent / 100), prm->mUnk_094);
    prm = mapObject->mPrm;
    TurnToPointMoveFollowsAngle(mapObject, prm->mUnk_098 * speedPercent / 100, prm->mUnk_09c);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetNextGroupEntry(mapObject)->mPos);
}

void StartHanachanMoveAnimation(MissionRunMapObject *mapObject) {
    mapObject->mUnk_150 = 1;
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_088, mapObject->mPrm->mUnk_08c);
}

int UpdateHanachanMoveState(MissionRunMapObject *mapObject) {
    int speedPercent;
    s32 entryPercent;
    s32 *v;

    if (IsPointInRange(mapObject, &GetCurrentGroupEntry(mapObject)->mPos, mapObject->mPrm->mUnk_0a0, 0)) {
        if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 1) {
            speedPercent = 0x1000 - mapObject->mPrm->mUnk_0ac;
            entryPercent = GetCurrentGroupEntryPercent(mapObject);
            speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, speedPercent);
        } else if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 2) {
            speedPercent = 0x1000 - mapObject->mPrm->mUnk_0a8;
            entryPercent = GetCurrentGroupEntryPercent(mapObject);
            speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, speedPercent);
        } else {
            speedPercent = GetCurrentGroupEntryPercent(mapObject);
        }
        if (GetCurrentGroupEntryValue(mapObject) >= 1) {
            AdvanceHanachanCounterForAll(mapObject);
        }
        if ((gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) == FALSE && mapObject->mUnk_0a8 == 0 &&
            IsStateNumberBelow(mapObject, 3) != 0) {
            if (GetEntryKartInAngleRange(mapObject, mapObject->mPrm->mUnk_120, mapObject->mPrm->mUnk_124,
                                         mapObject->mPrm->mUnk_128)) {
                mapObject->mUnk_0a8 = mapObject->mPrm->mUnk_12c;
                mapObject->mUnk_150 = 3;
                StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_118, mapObject->mPrm->mUnk_11c,
                                              (UnkFunc *) StartHanachanMoveAnimation);
                speedPercent -= mapObject->mPrm->mUnk_130;
                StartMapObjectSound(&mapObject->mUnk_000, 0x24b);
            } else if (GetEntryKartInAngleRange(mapObject, mapObject->mPrm->mUnk_10c, mapObject->mPrm->mUnk_110,
                                                mapObject->mPrm->mUnk_114)) {
                mapObject->mUnk_0a8 = mapObject->mPrm->mUnk_12c;
                mapObject->mUnk_150 = 3;
                StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_104, mapObject->mPrm->mUnk_108,
                                              (UnkFunc *) StartHanachanMoveAnimation);
                speedPercent -= mapObject->mPrm->mUnk_130;
                StartMapObjectSound(&mapObject->mUnk_000, 0x24b);
            }
        }
        SetHanachanSpeedAndTurnToNextEntry(mapObject, speedPercent);
        SetHanachanFollowersTurnTiming(mapObject, speedPercent);
        IncrementEntryIndex(mapObject);
        if (mapObject->mEntryIndex == 0) {
            IncrementEntryGroupIndex(mapObject, 4);
        }
    }
    if (mapObject->mUnk_0a8 > 0) {
        mapObject->mUnk_0a8 = mapObject->mUnk_0a8 - 1;
    }
    if (IsStateNumberBelow(mapObject, 5)) {
        if (GetAbsoluteCounter(mapObject) == 2) {
            mapObject->mUnk_140 = mapObject->mUnk_140 + 1 >= 6 ? 0 : mapObject->mUnk_140 + 1;
            if (mapObject->mUnk_140 == 0) {
                StartEffectAtOffset(mapObject, 0, 0, 0, 0x3f9, 0x1c);
            }
            mapObject->mUnk_144 = mapObject->mUnk_144 + 1 >= 0x12 ? 0 : mapObject->mUnk_144 + 1;
            if (mapObject->mUnk_144 == 0) {
                StartMapObjectSound(&mapObject->mUnk_000, 0x24f);
            }
        } else if (GetAbsoluteCounter(mapObject) == 1) {
            mapObject->mUnk_140 = mapObject->mUnk_140 + 1 >= 0x12 ? 0 : mapObject->mUnk_140 + 1;
            if (mapObject->mUnk_140 == 0) {
                StartEffectAtOffset(mapObject, 0, 0, 0, 0x3f8, 0x1c);
                StartMapObjectSound(&mapObject->mUnk_000, 0x24e);
            }
        }
    }
    return 0;
}

void StartHanachanMoveState(MissionRunMapObject *mapObject) {
    u32 entryPercent;
    StartMapObjectState(mapObject, 1, &UpdateHanachanMoveState);
    SetStoppedCallback(mapObject, 0);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_088, mapObject->mPrm->mUnk_08c);
    entryPercent = GetCurrentGroupEntryPercent(mapObject);
    SetHanachanSpeedAndTurnToNextEntry(mapObject, entryPercent);
    entryPercent = GetCurrentGroupEntryPercent(mapObject);
    SetHanachanFollowersTurnTiming(mapObject, entryPercent);
    SetHanachanSoundCallbacks(mapObject);
}

void StartHanachanMoveStateByBalloons(MissionRunMapObject *mapObject) {
    s32 speedPercent;
    s32 scaleFactor;
    s32 entryPercent;

    if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 1) {
        scaleFactor = 0x1000 - mapObject->mPrm->mUnk_0ac;
        entryPercent = GetCurrentGroupEntryPercent(mapObject);
        speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, scaleFactor);
    } else if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 2) {
        scaleFactor = 0x1000 - mapObject->mPrm->mUnk_0a8;
        entryPercent = GetCurrentGroupEntryPercent(mapObject);
        speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, scaleFactor);
    } else {
        speedPercent = GetCurrentGroupEntryPercent(mapObject);
    }
    StartMapObjectState(mapObject, 1, UpdateHanachanMoveState);
    SetStoppedCallback(mapObject, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_088, mapObject->mPrm->mUnk_08c);
    SetHanachanSpeedAndTurnToNextEntry(mapObject, speedPercent);
    SetHanachanFollowersTurnTiming(mapObject, speedPercent);
    StartHanachanAnimationScaled(mapObject, speedPercent);
    SetHanachanSoundCallbacks(mapObject);
}

void StartHanachanKartEliminatedState(MissionRunMapObject *mapObject) {
    int i;
    MapObjectList *list;
    MissionRunMapObject *follower;

    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_078, mapObject->mPrm->mUnk_07c);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && (follower = list->mMapObjects[i]) != NULL; i++) {
            StartMapObjectState(follower, 1, NULL);
            StartAnimationNoEndCallback(follower, follower->mPrm->mUnk_078, follower->mPrm->mUnk_07c);
        }
    }
}

void StartHanachanKartNotEliminatedState(MissionRunMapObject *mapObject) {
    int i;
    MapObjectList *list;
    MissionRunMapObject *follower;
    SoundStartParams soundRequest;

    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, 0);
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && (follower = list->mMapObjects[i]) != NULL; i++) {
            StartMapObjectState(follower, 1, NULL);
            StartAnimationNoEndCallback(follower, follower->mPrm->mUnk_070, follower->mPrm->mUnk_074);
            SetMapObjectModelNsbtpFrameIndex((follower->mNsbmd), 0);
        }
    }
    soundRequest = gHanachanEndSoundParams;
    soundRequest.mPositionSource = &mapObject->mUnk_000.mPos;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mUnk_000.mPos);
    StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
}

void HanachanStandingsEndCallback(void) {
    MapObjectList *list;
    MissionRunMapObject *follower;
    int i;

    ResetMissionRunMapObjects();
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && (follower = list->mMapObjects[i]) != NULL; i++) {
            PlaceHanachanFollowerBehind(follower);
            CopyHanachanFollowerPreviousAngle(follower);
        }
    }
}

s32 UpdateHanachanWaitForRaceStart(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StartHanachanMoveState(mapObject);
    }
    return 0;
}

void StartHanachanWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateHanachanWaitForRaceStart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
}

void StartHanachanStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  &StartHanachanWaitForRaceStart);
}

void StartHanachanStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &StartHanachanStartupSecond);
}

void StartHanachanChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_040, mapObject->mPrm->mUnk_044);
}

void StartHanachanChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, &StartHanachanChainStartupSecond);
}

s32 UpdateFollowerWaitForRaceStart(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StartHanachanFollowerMoveState(mapObject);
    }
    return 0;
}

s32 UpdateFollowerStartupEffects(MissionRunMapObject *mapObject) {
    int nsbcaFrameIndex;
    nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
    if (nsbcaFrameIndex == 0x33) {
        ReleaseEffects(mapObject);
        StartEffectAtOffset(mapObject, (0xfffff666u), 0, (0x00000400u), (0x00000434u), 0);
    } else {
        nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        if (nsbcaFrameIndex == 0x66) {
            ReleaseEffects(mapObject);
            StartEffectAtOffset(mapObject, (0x0000099au), 0, (0x00000400u), (0x00000434u), 0);
        }
    }
    return 0;
}

void StartFollowerWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateFollowerWaitForRaceStart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
}

void StartHanachanFollowerStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateFollowerStartupEffects);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  &StartFollowerWaitForRaceStart);
}

void StartHanachanFollowerStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &StartHanachanFollowerStartupSecond);
}

void StartFollowerChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_040, mapObject->mPrm->mUnk_044);
}

void StartFollowerChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, &StartFollowerChainStartupSecond);
}

void StartHanachanFollowerWaitAnimState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &StartHanachanFollowerStartupSecond);
}

void InitHanachanObjects(MapObjectList *mapObjectList) {
    int i;
    MissionRunMapObject *mapObject;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            mapObject->mUnk_2c4 = TRUE;
            if (GetRaceUseChainCameras() != 0) {
                StartHanachanChainStartupFirst(mapObject);
            } else {
                StartHanachanStartupFirst(mapObject);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) HanachanStandingsEndCallback);
}

void UpdateHanachan(u32 unused, MissionRunMapObject *mapObject) {
    int result;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        result = IsWinnerDecided();
    } else {
        result = 0;
    }
    if (result != 0) {
        if (IsStateNumberBelow(mapObject, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                result = IsKartEliminated((u16) gRaceSetup->mEntryIndex);
            } else {
                result = 0;
            }
            if (result != 0) {
                StartHanachanKartEliminatedState(mapObject);
            } else {
                StartHanachanKartNotEliminatedState(mapObject);
            }
        }
    } else {
        if (IsStateNumberBelow(mapObject, 1) != 0) {
            StartHanachanMoveStateByBalloons(mapObject);
        }
    }
    if (CollideSphereWithMapObjects(&mapObject->mPosWithOffset, &mapObject->mUnk_000.mPosStep,
                                    mapObject->mPrm->mUnk_100, mapObject->mUnk_000.mCollisionSlotIndex, 9, NULL) == 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x253);
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitHanachanFollowerObjects(MapObjectList *mapObjectList) {
    int i;
    MissionRunMapObject *mapObject;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if (GetRaceUseChainCameras() != 0) {
                StartFollowerChainStartupFirst(mapObject);
            } else if (i == 0) {
                StartHanachanFollowerStartupFirst(mapObject);
            } else {
                StartHanachanFollowerWaitAnimState(mapObject);
            }
        }
    }
}

void UpdateHanachanFollower(u32 unused, MissionRunMapObject *mapObject) {
    int collisionResult;
    PlaceHanachanFollowerBehindXz(mapObject);
    TurnHanachanFollowerToPrevious(mapObject);
    collisionResult =
        CollideSphereWithMapObjects(&mapObject->mPosWithOffset, &mapObject->mUnk_000.mPosStep,
                                    mapObject->mPrm->mUnk_100, mapObject->mUnk_000.mCollisionSlotIndex, 9, NULL);
    if (collisionResult == 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x253);
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitHanachanMapObject(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstFollower;
    MissionRunMapObject *secondFollower;
    MissionRunMapObject *thirdFollower;
    MissionRunMapObject *fourthFollower;

    firstFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mUnk_000, 0x1fe);
    secondFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mUnk_000, 0x1fe);
    thirdFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mUnk_000, 0x1fe);
    fourthFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mUnk_000, 0x1fe);
    firstFollower->mUnk_0a4 = mapObject;
    secondFollower->mUnk_0a4 = firstFollower;
    thirdFollower->mUnk_0a4 = secondFollower;
    fourthFollower->mUnk_0a4 = thirdFollower;
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mUnk_000.mSound->mSoundSource, 0xd, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffs[13].mFarDistanceSquared;
}

void InitHanachanFollowerMapObject(MissionRunMapObject *mapObject) {
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mUnk_000.mSound->mSoundSource, 0xd, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffs[13].mFarDistanceSquared;
}

void HanachanKartHitCallback(MissionRunMapObject *mapObject, MissionRunPrm *kart) {
    s32 moveAngle;
    s32 diff;

    if (kart->mUnk_29c == 1) {
        if (mapObject->mTimer > 0) {
            mapObject->mUnk_2d8 = 0xc;
        } else {
            moveAngle = mapObject->mMoveAngle;
            diff = (u16) (FX_Atan2Idx(kart->mUnk_080 - mapObject->mUnk_000.mPos.x,
                                      kart->mUnk_088 - mapObject->mUnk_000.mPos.z) -
                          moveAngle);
            if (diff > 0x8000) {
                diff -= 0x10000;
            }
            if (diff > 0) {
                mapObject->mUnk_000.mPosStep.x =
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_0fc, SIN_OF_ANGLE((u16) moveAngle + 0x4000));
                mapObject->mUnk_000.mPosStep.y = 0;
                mapObject->mUnk_000.mPosStep.z =
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_0fc, COS_OF_ANGLE((u16) mapObject->mMoveAngle + 0x4000));
            } else {
                mapObject->mUnk_000.mPosStep.x =
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_0fc, SIN_OF_ANGLE((u16) moveAngle - 0x4000));
                mapObject->mUnk_000.mPosStep.y = 0;
                mapObject->mUnk_000.mPosStep.z =
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_0fc, COS_OF_ANGLE((u16) mapObject->mMoveAngle - 0x4000));
            }
            mapObject->mUnk_2d8 = 0xc;
            StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
            mapObject->mUnk_000.mDistanceSquaredAndFlags |= gHanachanSkipKindSoundFlag;
            StartSoundFullVolumeWrapper(kart, 0x252);
        }
    } else {
        mapObject->mUnk_2d8 = 0xa;
        StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
        mapObject->mUnk_000.mDistanceSquaredAndFlags |= gHanachanSkipKindSoundFlag;
        StartSoundFullVolumeWrapper(kart, 0x251);
    }
    SetKartCollisionCallback(mapObject, HanachanKartHitCallback);
}

void InitHanachan(MapObjectList *mapObjectList) {
    MissionRunMapObject *obj;
    s32 i;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(mapObjectList, obj, gHanachanNsbmdName, gHanachanNsbcaName, gHanachanPrmName);
            LoadMissionRunMapObjectShadow(mapObjectList, obj, gHanachanShadowNsbmdName);
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, gHanachanNsbtpName);
            SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_008, obj->mPrm->mUnk_00c, obj->mPrm->mUnk_00c);
            SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
            SetKartCollisionCallback(obj, HanachanKartHitCallback);
            SetItemCollisionCallback(obj, HanachanItemHitCallback);
            obj->mUnk_0a8 = obj->mPrm->mUnk_12c;
        }
    }
}

void InitHanachanFollower(MapObjectList *mapObjectList) {
    void *firstNsbca;
    void *secondNsbca;
    void *firstNsbtp;
    MissionRunMapObject *obj;
    MissionRunMapObject *sourceObject;

    firstNsbca = LoadMissionRunFile(gHanachan1NsbcaName);
    secondNsbca = LoadMissionRunFile(gHanachan2NsbcaName);
    firstNsbtp = LoadMissionRunFile(gHanachan1NsbtpName);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        sourceObject =
            GetMissionRunMapObject(gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0);
    } else {
        sourceObject = NULL;
    }

    obj = mapObjectList->mMapObjects[0];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, gHanachan1NsbmdName, NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, firstNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mUnk_0a8 = 1;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0dc, obj->mPrm->mUnk_00c, sourceObject->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[1];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, gHanachan2NsbmdName, NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, secondNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mUnk_0a8 = 2;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0e4, obj->mPrm->mUnk_00c, sourceObject->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[2];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, gHanachan3NsbmdName, NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, firstNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mUnk_0a8 = 3;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0ec, obj->mPrm->mUnk_00c, sourceObject->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[3];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, gHanachan4NsbmdName, NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, secondNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mUnk_0a8 = 4;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0f4, obj->mPrm->mUnk_00c, sourceObject->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);
}

void DrawHanachan(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

void CreateHanachanKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData =
        CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *CreateHanachanDrawList(void) {
    return CreateMapObjectDrawList1(InitHanachan, DrawHanachan, NULL);
}

void *CreateHanachanUpdateList(void) {
    return CreateMapObjectUpdateList(InitHanachanObjects, UpdateHanachan, NULL);
}

void CreateHanachanFollowerKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData =
        CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *CreateHanachanFollowerDrawList(void) {
    return CreateMapObjectDrawList1(InitHanachanFollower, DrawHanachan, ToggleShadowScale);
}

void *CreateHanachanFollowerUpdateList(void) {
    return CreateMapObjectUpdateList(InitHanachanFollowerObjects, UpdateHanachanFollower, NULL);
}
