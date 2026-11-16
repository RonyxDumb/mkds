#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Camera Camera;

#include "Main/Unknown/unk_0217a000.h"

typedef struct Camera Camera;

// The 0x4c-byte entries of the table at CourseMap.mCameras: a position at 0x00, two vectors at 0x18 and 0x24 (look-at
// ends in some kinds, angles or a kart index in others), blend steps, a kind (mKind), a duration (mFrameCount), the
// next entry (mNextIndex).
typedef struct CourseMapCamera {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ Vec3 mUnk_24;
    /* 30 */ u8 mUnk_30[0x2];
    /* 32 */ s16 mHalfFovPairFirst;
    /* 34 */ s16 mHalfFovPairSecond;
    /* 36 */ u8 mUnk_36[0x2];
    /* 38 */ s16 mHalfFovPairFirstEnd;
    /* 3a */ s16 mHalfFovPairSecondEnd;
    /* 3c */ s16 mFovBlendPerFrame;
    // Entry type: tested 0 .. 8 (4 = two-screen pair, 5 and 6 angle entries, 6 / 7 / 8 also picked by the loader for
    // CourseMap slots cc / d0 / d4).
    /* 3e */ u16 mKind;
    /* 40 */ u16 mEntryGroupIndex;
    // Added to the position curve's parameter each call (0x1000 = one segment); also copied into Unk02077750.mUnk_7c,
    // which nothing reads.
    /* 42 */ s16 mPosCurvePerFrame;
    /* 44 */ u16 mLookAtBlendPerFrame;
    // Frames the entry lasts (compared with mCourseMapCameraFrames); the battle step compares it with the race clock
    // instead.
    /* 46 */ u16 mFrameCount;
    /* 48 */ s16 mNextIndex;
    // 0 on most entries; 1 marks the entry where the first chain camera starts, 2 the entry where the second starts.
    // The loader keeps the first entry with each value (CourseMap.mFirstChainStartEntry, mSecondChainStartEntry).
    /* 4a */ u8 mChainStart;
    /* 4b */ u8 mShakeKind;
} CourseMapCamera;

#include "code_02012b30.h" // MtxFx43

extern s32 data_021656c4;
extern Unk0214ad4c data_021702a4;
extern MtxFx43 data_021702e8;
extern s32 data_0217aca0;

void cam_updateShake(Camera *camera);
void cam_tryCannonShakePlayerCamera(void);
void cam_tryImpactShakePlayerCamera(u32 distance, s32 scale);
void cam_tryShakePlayerCamera(s32 baseAmplitude, u32 distance, s32 scale);
void cam_setPlayerCameraPosRot(const Vec3 *kartPos, void *quaternion);
// Moves the chase camera position a toward the position goal behind the Kart: adds the Kart's movement of the last
// frame, eases to the goal (follow distance behind the direction f, plus the Kart and collision offsets and
// mPosGoalYOffset), keeps mHeldHeight while mHeightHold is set, then puts a at mFollowDistance times
// mFollowDistanceScale from e (the Kart position). With bit 0x1000 of the Kart's mUnk_48 set it only adds the Kart's
// movement times mKartMoveScale, and nothing at all while bit 0x4000000 of its mUnk_4c is also set.
void cam_20741A0(Vec3 *pos, Vec3 *posOffset, Camera *camera, Kart *kart, Vec3 *kartPos, const Vec3 *forward,
                          s32 collisionShorten);
// Moves the chase camera look-at a toward the Kart position: x and z at once, y eased. b is the eased offset (mUnk_0b4
// of the Camera) and *c the lowering (mLookAtLowering): raised by 0x1000 per call up to 0xa000 while bit 0x10000 of the
// Kart's mUnk_48 is set, else decayed. Takes the three Camera members by pointer, not the Camera.
void cam_20745D4(Vec3 *lookAt, Vec3 *lookAtOffset, s32 *lookAtLowering, Kart *kart, s32 scaledHopHeight,
                             s32 lookAtHeight);
void cam_20747F4(s32 hold);
void cam_resetPlayerCameraFov(void);
void cam_resetPlayerCameraTargetFov(void);
void cam_setPlayerCameraTargetFov(unsigned int halfFovAngleGoal);
Camera *cam_getIntroCamera(void);
Camera *cam_getReplayCamera(void);
// Returns the chase camera (cam_sPlayerCamera).
Camera *cam_getPlayerCamera(void);
// Sets mLookAt between the entry's first point (mUnk_18) and second point (mUnk_24) by mLookAtBlend, which grows by the
// entry's mLookAtBlendPerFrame up to 0x1000; without a step it copies the first point.
void cam_updateCameTarget(Camera *camera);
// Entry kind 3: moves mPos along the entry's curve (cam_updateCameRoutePos), blends mLookAt (cam_updateCameTarget),
// then updates the view with world up (cam_updateLookAt).
void cam_updateCameByRoute(Camera *camera);
// Moves mPos along the points of the entry's group by a (0x1000 = one segment): four or more points run the curve
// mPosCurve, two or three a straight line from the first to the second point, fewer than two do nothing.
void cam_updateCameRoutePos(Camera *camera, s32 paramPerFrame);
void cam_updateStaffRollCamera(Camera *camera);
// Entry kinds 5 and 6 (the angle entries of CourseMapCamera.mKind): puts the Camera around the followed Kart from the
// entry's angles (mUnk_18.x, mUnk_18.y, mUnk_24.x, mUnk_24.y: degrees converted to 0x10000 per turn) and distance
// (mUnk_18.z), lowers the position and look-at by the Kart's mUnk_2bc, pushes mPos out of walls except in modes 2 and 4
// of gRaceMultiConfig->mMode, then updates the view.
void cam_2074E6C(Camera *camera);
// Entry kind 1: moves mPos along the entry's curve (cam_updateCameRoutePos), points mLookAt at the followed Kart (raised
// by 0x6000; when gRaceMultiConfig->mUnk_00c is 5 the Kart comes from the entry's mUnk_24.z and the raise from its
// mUnk_18.y) and updates the view.
void cam_updateCameByRouteAndDriver(Camera *camera);
// Does nothing while mCourseMapCamera is NULL. Otherwise runs the entry (cam_updateCame), counts
// mCourseMapCameraFrames and, when it reaches the entry's mFrameCount, starts the entry at mNextIndex (sets
// gRaceStatus->mUnk_4d0 when there is none). For cam_sIntroCameraTop with mFrustumShift 1 it also starts the next entry
// of cam_sIntroCameraBottom. race_update reaches it once a frame, only while race_sState->mUseChainCameras is non-zero.
void cam_updateIntroCam(Camera *camera);
// Steps cam_sIntroCameraTop (cam_updateIntroCam), updates its view, stores it in cam_sIntroCamera and returns its view
// matrix. race_update calls it when gRaceMultiConfig->mUnk_00c is 4.
MtxFx43 *cam_updateIntroCamSingle(void);
// Sets mFrustumShift of the two chain cameras (1 and 2 while the second's entry is of kind 4, else 0) and steps the
// first. Then it copies the first's field of view pair, mPos and mLookAt into the second (shift 2) or steps the second.
// It updates the view of the first on even frames and of the second on odd frames, stores that camera in
// cam_sIntroCamera and returns its view matrix. race_update calls it when gRaceMultiConfig->mUnk_00c is 3 or 5.
MtxFx43 *cam_updateIntroCamDouble(void);
// As cam_2075EB8 for CourseMap.mFirstKind8EntryInMode4, setting mKind8EntryRunning.
void cam_setupMissionFinishCamera(void);
// Runs the Camera's current entry by its mKind: 0 puts the camera at the entry position and looks at the followed Kart,
// 1 cam_updateCameByRouteAndDriver, 2 puts the camera at the entry position with a blended look-at
// (cam_updateCameTarget), 3 cam_updateCameByRoute, 5 and 6 cam_2074E6C; kinds 4, 7 and 8 have
// no case. Then sets the field of view pair: blended toward the entry's end pair by mFovBlend when the entry has an
// mFovBlendPerFrame, else copied from the entry.
void cam_updateCame(Camera *camera);
// Steps the Camera through CourseMapCamera entries and returns whether it is the camera in use this frame (race_update
// then shows it, else the chase camera). With gRaceMultiConfig->mRaceKind equal to RACE_KIND_STAFF_ROLL it runs\n//
// cam_updateStaffRollCamera and returns TRUE. Returns FALSE while mEntryUpdateHold or mEntryUpdateDisabled is set,
// and when no CourseMapShape of mKind 1 contains the followed Kart's position (mdat_findCameraId finds
// none); mPrevPos and gEntryCameraUpdateRan are written before either. Otherwise it starts the entry that shape names
// when it differs from the last one, runs it and returns TRUE. race_update calls it only while race_sState->mUseChainCameras
// is 0 and rstat_getUncontrollable() is non-zero.
BOOL cam_updateReplayCamera(Camera *camera);
u32 cam_2075CF0(void);
void cam_2075D08(s32 hold);
// Does nothing when CourseMap.mFirstKind6Entry is NULL. Otherwise sets mKind6EntryRunning and makes that entry the
// current entry of cam_sReplayCamera (fresh mFovBlend, field of view pair and mShakeKind), sets up its mPosCurve (and
// mUnk_1d0 in mode 2), advances the local random once when the entry Kart has ended and sets gCameraEntryChanged.
void cam_2075EB8(void);
// Eases mPosGoalYOffset toward 0 or, while bit 0x10 of the Kart's mUnk_44 or bit 0x10000 of its mUnk_48 is set, toward
// a multiple of the y of c (the Kart's forward vector times mFollowDirectionSign); while bit 0x40000000 of mUnk_48 is
// set it eases toward 0 at once.
void cam_2075FE0(Camera *camera, Kart *kart, Vec3 *forward);
// Tests the camera's path from mPrevPos to mPos against the course collision. On a hit it sets mPosGoalCollisionOffset
// and mCollisionOffsetLengthGoal or moves mPos out directly; it always eases mCollisionOffsetLength toward its goal.
// Also sets mUnk_254, mUnk_258 and mUnk_25c and clears data_0217aca0.
void cam_applyPlayerCamCollision(Camera *camera, Kart *kart, Vec3 *forward);
// One frame of the chase camera (cam_sPlayerCamera) following Kart b: eases the field of view, the look-at, the position
// goal and the position toward the Kart, then runs the collision test and the wobble. With bit 0x20 of the Kart's
// mUnk_7c set it only updates mViewPosYOffset, and only while water is present. race_update does not call it while
// race_sState->mUseChainCameras is non-zero.
void cam_updatePlayerCamera(Camera *camera, Kart *kart);
void cam_resetPlayerCamera(void);
void cam_applyLookAt(Camera *camera);
void cam_applyFrustum(Camera *camera, s32 useSecondFar);
MtxFx43 *cam_getProjectionMtx(void);
