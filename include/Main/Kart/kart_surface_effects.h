#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/Kart/kart_participant_record.h" // ParticipantKartRecord

// A node of the participant kart record list: a record with the timer that applies it.
typedef struct ParticipantKartRecordNode {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s16 mApplyTimer;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ ParticipantKartRecord mRecord;
} ParticipantKartRecordNode;

void AdvanceParticipantKartRecords(Kart *kart);
void AdvanceKartWobble(Kart *kart);
void StartKartRaceEnd(Kart *kart);
void AdvanceKartAi(Kart *kart);
// 1 when the turn start group, the level 3 group or the level 4 group (not while mLevel4StopRequested is TRUE) exists,
// else 0; the level 2 group is not counted.
u32 IsKartTurnEffectsActive(Kart *kart);
// Surface kind 10 (entry 10 of gKartSurfaceFunctions): passes the entry that gKartSurfaceKind10Effects gives for
// mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 0, for which RefreshKartSurface uses the factor
// 0x1000 instead of an entry of mSurfaceSpeedLimitFactors.
s32 ApplyKartSurfaceKind10(Kart *kart);
// Surface kind 19 (entry 19 of gKartSurfaceFunctions): unless mSurfaceGroup is already 0xb and KART_MOTION_STATE_RESET
// is clear in mMotionFlags it runs StartKartBoost and, for the selected kart, calls StartSound with 0x1b9; otherwise it
// sets mBoostTimer to 0x3c. Then it sets KART_DRIVE_BOOST_SURFACE_HELD and KART_DRIVE_ON_BOOST_SURFACE in mDriveFlags,
// runs StopKartCurrentEffects and returns surface group 0xb.
s32 ApplyKartSurfaceBoostHeld(Kart *kart);
// Surface kind 17 (entry 17 of gKartSurfaceFunctions): passes the entry that gKartSurfaceKind17Effects gives for
// mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 0xa.
s32 ApplyKartSurfaceKind17(Kart *kart);
// Surface kind 15 (entry 15 of gKartSurfaceFunctions): runs ApplyKartSurfaceEffect with 0; while
// KART_DRIVE_KEYED_PLACEMENT is clear in mDriveFlags it then runs PlaceKartAtKeyedPlacement with mSurfaceVariant when
// RaceSetup.mMode is MODE_BATTLE or MODE_MISSION_RUN, and in the other modes sets that bit and runs
// ResetKartMotionState with 0. Returns surface group 9.
s32 ApplyKartSurfaceKeyedPlacement(Kart *kart);
// Surface kind 18 (entry 18 of gKartSurfaceFunctions): the body of kind 7, followed by setting
// KART_DRIVE_BOOST_SPEED_FLOOR in mDriveFlags; returns surface group 8.
s32 ApplyKartSurfaceBoostWithSpeedFloor(Kart *kart);
// Surface kind 12 (entry 12 of gKartSurfaceFunctions): sets KART_DRIVE_JUMP_PAD in mDriveFlags, sets mVerticalSpeed
// from gKartJumpPadVerticalSpeeds and mUnk_4c4 from gKartJumpPadSpeedLimitGoals by mSurfaceVariant, runs
// StopKartCurrentEffects and returns surface group 8; on course 0xc or 0x28, when mSurfaceGroup was not already 8 or
// KART_MOTION_STATE_RESET is set in mMotionFlags, it first calls StartSound with 0x15e.
s32 ApplyKartSurfaceJumpPad(Kart *kart);
// Surface kind 7 (entry 7 of gKartSurfaceFunctions): unless mSurfaceGroup is already 8 and KART_MOTION_STATE_RESET is
// clear in mMotionFlags it runs StartKartBoost and, for the selected kart with mSurfaceVariant above 0, calls
// StartSound with the id that gKartSurfaceSoundIds gives for mSurfaceVariant minus 1; otherwise it sets mBoostTimer to
// 0x3c. Then it runs StopKartCurrentEffects and returns surface group 8.
s32 ApplyKartSurfaceBoost(Kart *kart);
// Surface kind 6 (entry 6 of gKartSurfaceFunctions): passes the entry that gKartSurfaceKind6Effects gives for
// mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 6.
s32 ApplyKartSurfaceKind6(Kart *kart);
// Surface kind 5 (entry 5 of gKartSurfaceFunctions): runs IncrementEntryKartSurfaceCount, passes the entry that
// gKartSurfaceKind5Effects gives for mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 4.
s32 ApplyKartSurfaceKind5(Kart *kart);
// Surface kind 3 (entry 3 of gKartSurfaceFunctions): runs IncrementEntryKartSurfaceCount, passes the entry that
// gKartSurfaceKind3Effects gives for mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 3.
s32 ApplyKartSurfaceKind3(Kart *kart);
// Surface kind 2 (entry 2 of gKartSurfaceFunctions): runs IncrementEntryKartSurfaceCount, passes the entry that
// gKartSurfaceKind2Effects gives for mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 2.
s32 ApplyKartSurfaceKind2(Kart *kart);
// Surface kind 1 (entry 1 of gKartSurfaceFunctions): passes the entry that gKartSurfaceKind1Effects gives for
// mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 5.
s32 ApplyKartSurfaceKind1(Kart *kart);
// Surface kind 20 (entry 20 of gKartSurfaceFunctions): passes the entry that gKartSurfaceKind20Effects gives for
// mSurfaceVariant to ApplyKartSurfaceEffect and returns surface group 0, for which RefreshKartSurface uses the factor
// 0x1000 instead of an entry of mSurfaceSpeedLimitFactors.
s32 ApplyKartSurfaceKind20(Kart *kart);
s32 ApplyKartSurfaceStopEffects(Kart *kart);
// Collision response 11 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns
// for the kart and the map object): when TryStartKartScaleTableEffect holds for the kart, mScaleEffectMapObject of the
// kart is not the object and the kart is the selected kart, increments the counter of the record GetEntryKartCounters
// returns. Stores 0 through the second parameter and returns 0.
s32 CollideKartWithMapObjectResponse11(Kart *kart, s32 *output, s32 mapObject);
// Collision response 14 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns
// for the kart and the map object): stores 0xc through the second parameter, clears the boost bits of mDriveFlags
// (BOOST, RACE_START_BOOST, MINI_TURBO, KINOKO_BOOST, ITEM_BOOST), zeroes mBoostTimer, the mKinokoBoostTimer member of
// mItemEffectData and mMiniTurboTimer, for the selected kart calls ResetCameraHalfFovAngleGoal unless
// KART_EFFECT_KILLER in mEffectFlags or KART_DRIVE_SCALE_TABLE_EFFECT in mDriveFlags is set and then runs
// StopDispCapBlend, then runs TrySpinKart with 1 and, when that succeeds, StartKartSpinFollowEffect with the kart
// index. Returns 5.
s32 CollideKartWithMapObjectResponse14(Kart *kart, s32 *output);
// Collision response 13 of gCollideKartWithMapObjectResponses (indexed by the value CollideKartWithMapObject returns
// for the kart and the map object): stores 0xc through the second parameter, clears the boost bits of mDriveFlags
// (BOOST, RACE_START_BOOST, MINI_TURBO, KINOKO_BOOST, ITEM_BOOST), zeroes mBoostTimer, the mKinokoBoostTimer member of
// mItemEffectData and mMiniTurboTimer, for the selected kart calls ResetCameraHalfFovAngleGoal unless
// KART_EFFECT_KILLER in mEffectFlags or KART_DRIVE_SCALE_TABLE_EFFECT in mDriveFlags is set and then runs
// StopDispCapBlend, and sets mForwardSpeed to 0. Returns 5.
s32 CollideKartWithMapObjectResponse13(Kart *kart, s32 *output);
