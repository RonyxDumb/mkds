#pragma once

#include "types.h"

typedef struct Kart Kart;

// Stack frame of ResetKartAtRaceEnd from its stack offset 0: a halfword and four vectors.
typedef struct KartRaceEndPlacement {
    /* 00 */ s16 mKeepSpeedFlag;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ Vec3 mOldPos;
    /* 10 */ Vec3 mRecordPos;
    /* 1c */ Vec3 mRecordRotation;
    /* 28 */ Vec3 mPosChange;
} KartRaceEndPlacement;

void AdvanceKartDriftCharge(Kart *kart);
void SetKartDriftCharge(Kart *kart, s32 charge);
void ResetKartAtRaceEnd(Kart *kart, s32 useCourseMapRecord, s32 isWinner);
void FinishKartAtBattleEnd(Kart *kart, s32 isWinner);
void FinishKartAtMissionRunEnd(Kart *kart);
void QueueKartOwnSoundIndex(Kart *kart);
void StartKartHitReaction(Kart *kart);
void SetKartCharacterAnimation(Kart *kart, s32 b, s32 c);
void StartBattleKartRemoval(Kart *kart);
void AdvanceKartRemovalShrink(Kart *kart);
