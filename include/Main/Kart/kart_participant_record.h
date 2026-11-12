#pragma once

#include "types.h"

typedef struct Kart Kart;

// Second parameter of ApplyParticipantKartRecord.
typedef struct ParticipantKartRecord {
    /* 00 */ s16 mPosX;
    /* 02 */ s16 mPosY;
    /* 04 */ s16 mPosZ;
    /* 06 */ s16 mForwardSpeed;
    /* 08 */ s16 mTurnAngle;
    /* 0a */ u16 mHeadingAngle;
    /* 0c */ u32 mFlags;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} ParticipantKartRecord;

void ApplyParticipantKartRecord(Kart *kart, ParticipantKartRecord *record, s32 stepCount);

// Collision response 12 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns
// for the kart and the map object): stores 0xc through the second parameter and returns 5.
int CollideKartWithMapObjectResponse12(Kart *kart, s32 *output);
// Collision response 10 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns
// for the kart and the map object): stores 0xa through the second parameter and returns 2.
int CollideKartWithMapObjectResponse10(Kart *kart, s32 *output);
// Collision response 9 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): stores 9 through the second parameter and returns 2.
int CollideKartWithMapObjectResponse9(Kart *kart, s32 *output);
// Collision response 8 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): stores 8 through the second parameter and returns 2.
int CollideKartWithMapObjectResponse8(Kart *kart, s32 *output);

typedef struct MapObject MapObject;

// Collision response 7 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): runs TryStartKartState3 and, when it starts, for the selected kart increments the
// counter of the record GetEntryKartCounters returns and sets KART_DRIVE_HIT_STATE in mDriveFlags. Stores 7 through the
// second parameter and returns 2.
int CollideKartWithMapObjectResponse7(Kart *kart, s32 *result);
// Collision response 5 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): runs TrySpinKart with 2 and, when that succeeds, passes the result of StartEffect with
// 0x4f at mPos to SetupKartFollowEffectWithVelocity with the kart index and 0x46 if KART_ENTRY_HAS_CHARACTER_ANIMATION
// is set in mEntryFlags and, for the selected kart, increments the counter of the record GetEntryKartCounters returns.
// Stores 5 through the second parameter and returns 0.
int CollideKartWithMapObjectResponse5(Kart *kart, s32 *result);
// Collision response 6 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object
// is set it runs TrySpinKart with 2 and, when that succeeds, for the selected kart increments the counter of the record
// GetEntryKartCounters returns and runs StartKartSpinSideEffects with the kart index; it then stores 4 through the
// second parameter. Otherwise it stores 0. Returns 0.
int CollideKartWithMapObjectResponse6(Kart *kart, s32 *result, MapObject *mapObject);
// Collision response 4 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object
// is set it runs TrySpinKart with 2 and, when that succeeds, calls StartEffect with 0xc, 0xd and 0xe at mPos unless the
// mUnk_058 member of mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the record
// GetEntryKartCounters returns; it then stores 4 through the second parameter. Otherwise it stores 2. Returns 0xb.
int CollideKartWithMapObjectResponse4(Kart *kart, s32 *result, MapObject *mapObject);
// Collision response 3 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object
// is set it runs TrySpinKart with 1 and, when that succeeds, calls StartEffect with 0xc, 0xd and 0xe at mPos unless the
// mUnk_058 member of mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the record
// GetEntryKartCounters returns; it then stores 3 through the second parameter. Otherwise it stores 2. Returns 0xb.
int CollideKartWithMapObjectResponse3(Kart *kart, s32 *result, MapObject *mapObject);

// Collision response 2 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): stores 2 through the second parameter and returns 0xb.
s32 CollideKartWithMapObjectResponse2(Kart *kart, s32 *output);
// Collision response 0 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): stores 0 through the second parameter and returns 0. Same bytes as
// CollideKartWithMapObjectNoResponse, the table entry for index 1.
s32 CollideKartWithMapObjectResponse0(Kart *kart, s32 *output);

void StartKartPushDoubleFlipOnHit(Kart *kart, const Vec3 *direction);
void StartKartPushFlipOnHitByMapObject(Kart *kart, s32 direction, MapObject *mapObject);
void StartKartPushFlipOnHit(Kart *kart, const Vec3 *direction);

unsigned int MapObjectResponseReturnArgument(unsigned int value);

s32 CollideKartWithMapObjectNoResponse(Kart *kart, s32 *outValue);

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
void SetKartCharacterAnimation(Kart *kart, s32 animationIndex, s32 useBlend);
void StartBattleKartRemoval(Kart *kart);
void AdvanceKartRemovalShrink(Kart *kart);

BOOL IsKartRemoved(Kart *kart);
BOOL StartKartRemoval(Kart *kart, s32 fromRaceProgress);
void StartKartRemovalFromProgress(Kart *kart);
void StartKartAheadBoost(Kart *kart);
void AdvanceKartGesso(Kart *kart);
void StartKartGesso(Kart *kart, u32 orthoQuadCount);
void AdvanceKartKiller(Kart *kart);
void StartKartKiller(Kart *kart);
void AdvanceKartTeresa(Kart *kart);
void StartKartTeresa(Kart *kart);
void StartKartStar(Kart *kart);
void StartKartKinokoBoost(Kart *kart);
void StartKartThunder(Kart *kart);
void ResetKartScaleEffects(Kart *kart);
void AdvanceKartScaleTableEffect(Kart *kart);
BOOL TryStartKartScaleTableEffect(Kart *kart);


void AdvanceKartThunderShrink(Kart *kart);
void StartKartThunderShrink(Kart *kart);
void AdvanceKartState5(Kart *kart);
s32 StartKartState5(Kart *kart, const Vec3 *pushDirection, s32 record);
void AdvanceKartState4(Kart *kart);
void StartKartState4(Kart *kart, const Vec3 *pushDirection, s32 record);
BOOL TryStartKartState4(Kart *kart, MapObject *mapObject);
void AdvanceKartState3(Kart *kart);
void StartKartState3(Kart *kart);
BOOL TryStartKartState3(Kart *kart);
void AdvanceKartState6(Kart *kart);
void StartKartState6(Kart *kart);
BOOL TryStartKartState6(Kart *kart);
void AdvanceKartState1And2(Kart *kart);
void StartKartState2(Kart *kart, int spinCount, int skipSound);

extern const u32 gKartSurfaceKind1Effects[8];
extern const s32 gKartOffsetCycleY[8];
extern const Vec3 gKartStartPlacementHeadingAxis;
extern const s32 gKartModelScaleYKind1Table[15];
extern const s32 gKartModelOffsetYKind1Table[15];
extern const s32 gKartModelScaleXKind2Table[15];
extern const s16 gThunderShrinkTimerByRank[8];
extern const s16 gKartRaceStartBoostFrameCounts[6];
extern const s32 gKartModelScaleYKind0Table[15];
extern const u32 gKartSurfaceKind3Effects[8];
extern const u32 gKartSurfaceKind2Effects[8];
extern const s32 gKartModelOffsetYKind0And2Table[15];
extern const s32 gKartOffsetCycleZ[8];
extern const u32 gKartSurfaceKind5Effects[8];
extern const u32 gKartSurfaceKind17Effects[8];
extern const s32 gKartOffsetCycleX[8];
extern const u32 gKartSurfaceKind20Effects[8];
extern const u32 gKartSurfaceKind6Effects[8];
extern const u32 gKartSurfaceStopEffects[8];
extern const u32 gKartSurfaceKind10Effects[8];
extern const s32 gKartModelScaleZKind2Table[15];
