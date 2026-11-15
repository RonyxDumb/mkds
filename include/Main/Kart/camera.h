#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Camera Camera;

#include "Main/System/backup_net_camera_work.h"

typedef struct Camera Camera;

// Values of CourseMapCamera.mKind.
#define COURSE_MAP_CAMERA_KIND_STATIC_LOOK_AT_KART 0
#define COURSE_MAP_CAMERA_KIND_CURVE_LOOK_AT_KART 1
#define COURSE_MAP_CAMERA_KIND_STATIC_LOOK_AT_BLEND 2
#define COURSE_MAP_CAMERA_KIND_CURVE_LOOK_AT_BLEND 3
#define COURSE_MAP_CAMERA_KIND_CHAIN_PAIR 4
#define COURSE_MAP_CAMERA_KIND_ANGLE 5
#define COURSE_MAP_CAMERA_KIND_ANGLE_START 6
#define COURSE_MAP_CAMERA_KIND_SEQUENCE 7
#define COURSE_MAP_CAMERA_KIND_MISSION_RUN 8 // recorded only in mission run mode

// CourseMapCamera.mChainStart values that mark the first and the second chain camera of a course.
#define CAMERA_CHAIN_START_FIRST 1
#define CAMERA_CHAIN_START_SECOND 2

// One camera of CourseMap.mCameras: its position, two vectors, blend steps, kind, duration and next entry.
typedef struct CourseMapCamera {
    /* 00 */ Vec3 mPosOrParams;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ Vec3 mLookAtStartOrParams;
    /* 24 */ Vec3 mLookAtEndOrParams;
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
    // Added to the position curve's parameter each call (0x1000 = one segment); also copied into
    // SequenceCameraEntry.mUnk_7c, which nothing reads.
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
#include "code_021479b4.h"


void UpdateCameraWobble(Camera *camera);
void StartCameraWobbleByCourse(void);
void StartCameraWobbleAtDistance(u32 distance, s32 scale);
void StartCameraWobble(s32 baseAmplitude, u32 distance, s32 scale);
void ResetCameraBehind(const Vec3 *kartPos, void *quaternion);
// Moves the chase camera position a toward the position goal behind the Kart: adds the Kart's movement of the last
// frame, eases to the goal (follow distance behind the direction f, plus the Kart and collision offsets and
// mPosGoalYOffset), keeps mHeldHeight while mHeightHold is set, then puts a at mFollowDistance times
// mFollowDistanceScale from e (the Kart position). With KART_DRIVE_RESPAWN_FALL set in the Kart's mDriveFlags it only
// adds the Kart's movement times mKartMoveScale, and nothing at all while KART_EFFECT_WATER_FALL is also set in its
// mEffectFlags.
void UpdateChaseCameraPos(Vec3 *pos, Vec3 *posOffset, Camera *camera, Kart *kart, Vec3 *kartPos, const Vec3 *forward,
                          s32 collisionShorten);
// Moves the chase camera look-at a toward the Kart position: x and z at once, y eased. b is the eased offset (mUnk_0b4
// of the Camera) and *c the lowering (mLookAtLowering): raised by 0x1000 per call up to 0xa000 while
// KART_DRIVE_KEYED_PLACEMENT is set in the Kart's mDriveFlags, else decayed. Takes the three Camera members by pointer,
// not the Camera.
void UpdateChaseCameraLookAt(Vec3 *lookAt, Vec3 *lookAtOffset, s32 *lookAtLowering, Kart *kart, s32 scaledHopHeight,
                             s32 lookAtHeight);
void SetCameraHeightHold(s32 hold);
void ResetCameraHalfFovAngle(void);
void ResetCameraHalfFovAngleGoal(void);
void SetCameraHalfFovAngleGoal(unsigned int halfFovAngleGoal);
Camera *GetCurrentChainCamera(void);
Camera *GetEntryCamera(void);
// Returns the chase camera (gChaseCamera).
Camera *GetChaseCamera(void);
// Sets mLookAt between the entry's first point (mUnk_18) and second point (mUnk_24) by mLookAtBlend, which grows by the
// entry's mLookAtBlendPerFrame up to 0x1000; without a step it copies the first point.
void UpdateCameraLookAtBlend(Camera *camera);
// Entry kind 3: moves mPos along the entry's curve (UpdateCameraPosCurve), blends mLookAt (UpdateCameraLookAtBlend),
// then updates the view with world up (UpdateCameraViewWithWorldUp).
void UpdateCameraPosCurveLookAtBlend(Camera *camera);
// Moves mPos along the points of the entry's group by a (0x1000 = one segment): four or more points run the curve
// mPosCurve, two or three a straight line from the first to the second point, fewer than two do nothing.
void UpdateCameraPosCurve(Camera *camera, s32 paramPerFrame);
void UpdateStaffRollCameraAndLight(Camera *camera);
// Entry kinds 5 and 6 (the angle entries of CourseMapCamera.mKind): puts the Camera around the followed Kart from the
// entry's angles (mUnk_18.x, mUnk_18.y, mUnk_24.x, mUnk_24.y: degrees converted to 0x10000 per turn) and distance
// (mUnk_18.z), lowers the position and look-at by the Kart's mUnk_2bc, pushes mPos out of walls except in modes 2 and 4
// of gRaceSetup.mMode, then updates the view.
void UpdateCameraAngleEntry(Camera *camera);
// Entry kind 1: moves mPos along the entry's curve (UpdateCameraPosCurve), points mLookAt at the followed Kart (raised
// by 0x6000; when gRaceSetup.mRaceKind is 5 the Kart comes from the entry's mUnk_24.z and the raise from its
// mUnk_18.y) and updates the view.
void UpdateCameraPosCurveLookAtKart(Camera *camera);
// Does nothing while mCourseMapCamera is NULL. Otherwise runs the entry (UpdateCameraByEntryKind), counts
// mCourseMapCameraFrames and, when it reaches the entry's mFrameCount, starts the entry at mNextIndex (sets
// gRaceProgress.mUnk_4d0 when there is none). For gFirstChainCamera with mFrustumShift 1 it also starts the next entry
// of gSecondChainCamera. UpdateRace reaches it once a frame, only while gRace.mUseChainCameras is non-zero.
void UpdateCameraEntry(Camera *camera);
// Steps gFirstChainCamera (UpdateCameraEntry), updates its view, stores it in gCurrentChainCamera and returns its view
// matrix. UpdateRace calls it when gRaceSetup.mRaceKind is 4.
MtxFx43 *UpdateFirstChainCamera(void);
// Sets mFrustumShift of the two chain cameras (1 and 2 while the second's entry is of kind 4, else 0) and steps the
// first. Then it copies the first's field of view pair, mPos and mLookAt into the second (shift 2) or steps the second.
// It updates the view of the first on even frames and of the second on odd frames, stores that camera in
// gCurrentChainCamera and returns its view matrix. UpdateRace calls it when gRaceSetup.mRaceKind is 3 or 5.
MtxFx43 *UpdateChainCameraPair(void);
// As StartEntryCameraAngleStart for CourseMap.mFirstMissionRunCamera, setting mMissionRunCameraRunning.
void StartEntryCameraMissionRun(void);
// Runs the Camera's current entry by its mKind: 0 puts the camera at the entry position and looks at the followed Kart,
// 1 UpdateCameraPosCurveLookAtKart, 2 puts the camera at the entry position with a blended look-at
// (UpdateCameraLookAtBlend), 3 UpdateCameraPosCurveLookAtBlend, 5 and 6 UpdateCameraAngleEntry; kinds 4, 7 and 8 have
// no case. Then sets the field of view pair: blended toward the entry's end pair by mFovBlend when the entry has an
// mFovBlendPerFrame, else copied from the entry.
void UpdateCameraByEntryKind(Camera *camera);
// Steps the Camera through CourseMapCamera entries and returns whether it is the camera in use this frame (UpdateRace
// then shows it, else the chase camera). With gRaceSetup.mRaceKind equal to RACE_KIND_STAFF_ROLL it runs
// UpdateStaffRollCameraAndLight and returns TRUE. Returns FALSE while mEntryUpdateHold or mEntryUpdateDisabled is set,
// and when no CourseMapShape of mKind 1 contains the followed Kart's position (GetCourseMapCameraIndexAtPos finds
// none); mPrevPos and gEntryCameraUpdateRan are written before either. Otherwise it starts the entry that shape names
// when it differs from the last one, runs it and returns TRUE. UpdateRace calls it only while gRace.mUseChainCameras
// is 0 and GetEntryRaceEnded() is non-zero.
BOOL TryUpdateEntryCamera(Camera *camera);
void DisableEntryCameraUpdate(void);
void SetEntryCameraUpdateHold(s32 hold);
// Does nothing when CourseMap.mFirstAngleStartCamera is NULL. Otherwise sets mAngleStartRunning and makes that entry
// the current entry of gEntryCamera (fresh mFovBlend, field of view pair and mShakeKind), sets up its mPosCurve (and
// mUnk_1d0 in mode 2), advances the local random once when the entry Kart has ended and sets gCameraEntryChanged.
void StartEntryCameraAngleStart(void);
// Eases mPosGoalYOffset toward 0 or, while KART_MOTION_ON_GROUND is set in the Kart's mMotionFlags or
// KART_DRIVE_KEYED_PLACEMENT in its mDriveFlags, toward a multiple of the y of c (the Kart's forward vector times
// mFollowDirectionSign); while KART_DRIVE_BOOST_SURFACE_HELD is set it eases toward 0 at once.
void UpdateChaseCameraPosGoalYOffset(Camera *camera, Kart *kart, Vec3 *forward);
// Tests the camera's path from mPrevPos to mPos against the course collision. On a hit it sets mPosGoalCollisionOffset
// and mCollisionOffsetLengthGoal or moves mPos out directly; it always eases mCollisionOffsetLength toward its goal.
// Also sets mUnk_254, mUnk_258 and mUnk_25c and clears gChaseCameraUnusedWord.
void UpdateChaseCameraCollision(Camera *camera, Kart *kart, Vec3 *forward);
// One frame of the chase camera (gChaseCamera) following Kart b: eases the field of view, the look-at, the position
// goal and the position toward the Kart, then runs the collision test and the wobble. With KART_ENTRY_REMOVED set in
// the Kart's mEntryFlags it only updates mViewPosYOffset, and only while water is present. UpdateRace does not call it
// while gRace.mUseChainCameras is non-zero.
void UpdateChaseCamera(Camera *camera, Kart *kart);
void SetupCameraBehindKart(void);
void ApplyCameraLookAt(Camera *camera);
void ApplyCameraFrustum(Camera *camera, s32 useSecondFar);
MtxFx44 *GetProjectionMatrix(void);

// The Camera that picks its CourseMapCamera entry from the position of the followed Kart (GetCourseMapCameraIndexAtPos)
// and is stepped by TryUpdateEntryCamera. mKind is 1, or 3 in mode 2 when CourseMap.mFirstBattleSequenceCamera is set.
// The Kart code starts its kind 6 and kind 8 entries (StartEntryCameraAngleStart, StartEntryCameraMissionRun). The
// chain cameras also run entries but never pick by position.
extern Camera *gEntryCamera;
extern struct Camera *gChaseCamera;
extern s32 gDefaultLookAtHeight;
extern s32 gFollowHeight;
extern s32 gChaseCameraUnusedWord;
// The Camera (mKind 2) that starts at CourseMap.mSecondChainStartEntry; NULL when only the first chain camera exists.
// While its entry is of kind 4 it is not stepped itself: it copies the field of view, mPos and mLookAt of
// gFirstChainCamera, and its entry advances together with the first one's. Its view is the one used on odd frames.
extern Camera *gSecondChainCamera;
// Set to 1 at race set-up and when a camera entry is started or advanced; cleared once per UpdateRace call by
// ClearCameraEntryFlags. UpdateRace calls RequestViewTestRefresh when it is set.
extern s32 gCameraEntryChanged;
// Set to 1 when TryUpdateEntryCamera is entered; cleared once per UpdateRace call by ClearCameraEntryFlags.
// RefreshCameraProjection does not skip the chase camera's projection while it is 1.
extern s32 gEntryCameraUpdateRan;
extern s32 gDefaultFollowDistance;
// The chain camera whose view matrix the last chain step returned; UpdateRace stores it as the camera in use. Not
// written in races without chain cameras.
extern Camera *gCurrentChainCamera;
// The Camera (mKind 2) that starts at CourseMap.mFirstChainStartEntry and follows mNextIndex through its entries; the
// only chain camera when gRaceSetup.mRaceKind is 4. Created by CreateFirstChainCamera or CreateChainCameraPair. With
// two chain cameras its view is the one used on even frames of gRace.mUpdateFrames.
extern Camera *gFirstChainCamera;

extern MtxFx44 gProjectionMatrix;

// Camera.mLookAtHeight never falls below this while the height hold lowers it; the frames the camera angle start runs.
#define CAMERA_LOOK_AT_HEIGHT_MIN 0x5000
#define CAMERA_ANGLE_START_FRAMES 300
