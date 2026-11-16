#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/segment_group_collision.h" // GroupFollower
#include "Main/MapObjects/sanbo.h"

// One piece of a Sanbo: position, velocity, draw scale and the wobble and rotation that animate it.
typedef struct SanboPiece {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mVelocity;
    /* 18 */ s32 mDrawScale;
    /* 1c */ u16 mWobbleAngle;
    /* 1e */ u8 mUnk_1e[2];
    /* 20 */ s32 mWobbleValue;
    /* 24 */ s32 mWobbleValueDelta;
    /* 28 */ s32 mWobbleMid;
    /* 2c */ s32 mWobbleAmplitude;
    /* 30 */ s32 mWobbleAmplitudePerFrame;
    /* 34 */ s32 mWobbleAnglePerFrame;
    /* 38 */ s32 mWobbleAnglePerFrameDelta;
    /* 3c */ s32 mRotateZAngle;
    /* 40 */ s32 mRotateZAnglePerFrame;
    /* 44 */ s32 mWobbleDelayTimer;
} SanboPiece;

// Sanbo.mState: standing and wobbling, the pieces flying apart after a launch, the pieces growing back one by one.
// SANBO_STATE_STANDING_UNUSED is drawn like SANBO_STATE_STANDING and never written.
#define SANBO_STATE_STANDING 0
#define SANBO_STATE_STANDING_UNUSED 1
#define SANBO_STATE_SCATTERED 2
#define SANBO_STATE_REGROWING 3

// A Sanbo map object (sanbo_h and sanbo_b models in one object): its pieces and the GroupFollower the object moves
// along.
typedef struct Sanbo {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mPathWaitTimer;
    // Wobble step is 0xb61 while above 0, else 0x2d8.
    /* 0a4 */ s32 mFastWobbleTimer;
    /* 0a8 */ s32 mLaunchWaitTimer;
    /* 0ac */ s32 mSoundTimer;
    /* 0b0 */ SanboPiece mPieces[SANBO_PIECE_COUNT];
    /* 1d0 */ u16 mPieceCount;
    /* 1d2 */ u8 mUnk_1d2[2];
    /* 1d4 */ s32 mPathSpeed;
    /* 1d8 */ GroupFollower mFollower;
    /* State number of this kind's own per-frame switch in UpdateSanbo; this object does not use
       MapObject.mUnk_80's state machine; also read in its draw, state 1 is never written */
    /* 1fc */ s32 mState;
} Sanbo;

#include "Main/MapObjects/sanbo_collide.h"
