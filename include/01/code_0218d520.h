#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"

// Object behind Unk02188950.mUnk_0a4.
typedef struct Unk0218dabc {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ u8 mUnk_010[0x174];
    /* 184 */ s32 mUnk_184;
} Unk0218dabc;

int UpdateHanachanMoveState(Unk02188950 *mapObject);
void StartHanachanMoveAnimation(Unk02188950 *mapObject);
void SetHanachanSpeedAndTurnToNextEntry(Unk02188950 *mapObject, int speedPercent);
void SetHanachanFollowersTurnTiming(Unk02188950 *mapObject, int speedPercent);
void StartHanachanAnimationScaled(Unk02188950 *mapObject, int speedPercent);
void StartHanachanFollowerMoveState(Unk02188950 *mapObject);
void AdvanceHanachanCounterForAll(Unk02188950 *mapObject);
void AdvanceHanachanCounter(Unk02188950 *mapObject);
void CopyHanachanFollowerPreviousAngle(Unk02188950 *mapObject);
void PlaceHanachanFollowerBehind(Unk02188950 *mapObject);
void TurnHanachanFollowerToPrevious(Unk02188950 *mapObject);
void PlaceHanachanFollowerBehindXz(Unk02188950 *mapObject);

#include "01/code_0219b540.h"
