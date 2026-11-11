#include "01/code_0218d520.h"
#include "01/code_02187d14.h"
#include "01/code_02187eb0.h"
#include "01/code_02188230.h"
#include "01/code_02188cd8.h"
#include "01/code_02187000.h"
#include "01/code_02187e78.h"
#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_021000d0.h"
#include "code_02147cd8.h"

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
