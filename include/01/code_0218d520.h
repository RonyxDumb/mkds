#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"

// Object behind MissionRunMapObject.mUnk_0a4.
typedef struct Unk0218dabc {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ u8 mUnk_010[0x174];
    /* 184 */ s32 mUnk_184;
} Unk0218dabc;

int UpdateHanachanMoveState(MissionRunMapObject *mapObject);
void StartHanachanMoveAnimation(MissionRunMapObject *mapObject);
void SetHanachanSpeedAndTurnToNextEntry(MissionRunMapObject *mapObject, int speedPercent);
void SetHanachanFollowersTurnTiming(MissionRunMapObject *mapObject, int speedPercent);
void StartHanachanAnimationScaled(MissionRunMapObject *mapObject, int speedPercent);
void StartHanachanFollowerMoveState(MissionRunMapObject *mapObject);
void AdvanceHanachanCounterForAll(MissionRunMapObject *mapObject);
void AdvanceHanachanCounter(MissionRunMapObject *mapObject);
void CopyHanachanFollowerPreviousAngle(MissionRunMapObject *mapObject);
void PlaceHanachanFollowerBehind(MissionRunMapObject *mapObject);
void TurnHanachanFollowerToPrevious(MissionRunMapObject *mapObject);
void PlaceHanachanFollowerBehindXz(MissionRunMapObject *mapObject);

#include "01/code_0219b540.h"
