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
    /* 10 */ u32 mMotionFlagsAndPush;
    /* 14 */ u32 mDriveFlags;
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
// the kart and the map object): runs TryStartKartFlip and, when it starts, for the selected kart increments the
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
// mKartModelHidden member of mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the
// record GetEntryKartCounters returns; it then stores 4 through the second parameter. Otherwise it stores 2. Returns
// 0xb.
int CollideKartWithMapObjectResponse4(Kart *kart, s32 *result, MapObject *mapObject);
// Collision response 3 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns for
// the kart and the map object): when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object
// is set it runs TrySpinKart with 1 and, when that succeeds, calls StartEffect with 0xc, 0xd and 0xe at mPos unless the
// mKartModelHidden member of mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the
// record GetEntryKartCounters returns; it then stores 3 through the second parameter. Otherwise it stores 2. Returns
// 0xb.
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

void MapObjectResponseNop(void);

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
void AdvanceKartPushDoubleFlip(Kart *kart);
s32 StartKartPushDoubleFlip(Kart *kart, const Vec3 *pushDirection, s32 record);
void AdvanceKartPushFlip(Kart *kart);
void StartKartPushFlip(Kart *kart, const Vec3 *pushDirection, s32 record);
BOOL TryStartKartPushFlipFromMapObject(Kart *kart, MapObject *mapObject);
void AdvanceKartFlip(Kart *kart);
void StartKartFlip(Kart *kart);
BOOL TryStartKartFlip(Kart *kart);
void AdvanceKartLaunchDoubleFlip(Kart *kart);
void StartKartLaunchDoubleFlip(Kart *kart);
BOOL TryStartKartLaunchDoubleFlip(Kart *kart);
void AdvanceKartSpin(Kart *kart);
void StartKartSpin(Kart *kart, int spinCount, int skipSound);

extern const u32 gKartSurfaceKind1Effects[8];
extern const s32 gKartOffsetCycleY[8];
extern const Vec3 gKartStartPlacementHeadingAxis;
extern const s32 gKartModelScaleYHardLandTable[15];
extern const s32 gKartModelOffsetYHardLandTable[15];
extern const s32 gKartModelScaleXBumpTable[15];
extern const s16 gThunderShrinkTimerByRank[8];
extern const s16 gKartRaceStartBoostFrameCounts[6];
extern const s32 gKartModelScaleYLandTable[15];
extern const u32 gKartSurfaceKind3Effects[8];
extern const u32 gKartSurfaceKind2Effects[8];
extern const s32 gKartModelOffsetYLandAndBumpTable[15];
extern const s32 gKartOffsetCycleZ[8];
extern const u32 gKartSurfaceKind5Effects[8];
extern const u32 gKartSurfaceKind17Effects[8];
extern const s32 gKartOffsetCycleX[8];
extern const u32 gKartSurfaceKind20Effects[8];
extern const u32 gKartSurfaceKind6Effects[8];
extern const u32 gKartSurfaceStopEffects[8];
extern const u32 gKartSurfaceKind10Effects[8];
extern const s32 gKartModelScaleZBumpTable[15];

// Kart.mYRotationAnglePerFrame of a spin, and the frames the driving input stays locked once the spin ends.
#define KART_SPIN_ANGLE_PER_FRAME 0x750
#define KART_SPIN_END_LOCK_FRAMES 10
// Launch double flip: the vertical speed it starts with, the rotation sum below which a landing adds speed, the frames
// that must pass before a landing ends it, the collision step frames it sets and the frames the ending rotation runs.
#define KART_LAUNCH_FLIP_VERTICAL_SPEED 0x6000
#define KART_LAUNCH_FLIP_LANDING_ROTATION_LIMIT 0x13000
#define KART_LAUNCH_FLIP_END_MIN_FRAMES 2
#define KART_LAUNCH_FLIP_COLLISION_STEP_FRAMES 0x46
#define KART_LAUNCH_FLIP_ROTATION_END_FRAMES 0x1e
// Frames the ending rotation of a push flip and of a push double flip runs.
#define KART_PUSH_FLIP_ROTATION_END_FRAMES 0x1e
#define KART_PUSH_DOUBLE_FLIP_ROTATION_END_FRAMES 10
// Steps of the thunder shrink and of the scale table effect before the kart is back at full size.
#define KART_SCALE_RESTORE_STEPS 0x19
// Frames of the scale table effect, and the timer value at which its drive flag clears.
#define KART_SCALE_EFFECT_FRAMES 0x258
#define KART_SCALE_EFFECT_DRIVE_FLAG_CLEAR_TIMER 0x1c2
// Teresa effect on a kart that is not the selected one: the toggle divisor and step limit it starts with, the toggle
// frames after which the kart stays not drawn, and the frame at which the divisor step turns around.
#define KART_TERESA_START_TOGGLE_DIVISOR 2
#define KART_TERESA_START_STEP_LIMIT 10
#define KART_TERESA_TOGGLE_END_FRAMES 0x50
#define KART_TERESA_DIVISOR_TURN_FRAMES 0x172
// A removed kart is respawned in battle after this many frames.
#define KART_BATTLE_RESPAWN_FRAMES 0xb9
