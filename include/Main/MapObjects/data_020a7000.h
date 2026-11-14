#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/code_020e005c.h" // GroupFollower

// 0x48-byte entries from 0xb0 of Sanbo; StartSanboLaunch writes the first mPieceCount of them.
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

// Object of kind 0x1b2 (Sanbo: sanbo_h and sanbo_b models in one object). Object passed to CollideItemObjectWithSanbo
// and CollideKartWithSanbo as their first argument and on to StartSanboLaunch: the shared MapObject part, words at 0xa0
// to 0xac, four 0x48-byte entries with their count at 0x1d0, a word at 0x1d4, an GroupFollower at 0x1d8 and a word at
// 0x1fc.
typedef struct Sanbo {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mPathWaitTimer;
    // Wobble step is 0xb61 while above 0, else 0x2d8.
    /* 0a4 */ s32 mFastWobbleTimer;
    /* 0a8 */ s32 mState2Timer;
    /* 0ac */ s32 mSoundTimer;
    /* 0b0 */ SanboPiece mPieces[4];
    /* 1d0 */ u16 mPieceCount;
    /* 1d2 */ u8 mUnk_1d2[2];
    /* 1d4 */ s32 mPathSpeed;
    /* 1d8 */ GroupFollower mFollower;
    /* State number of this kind's own per-frame switch in UpdateSanbo; this object does not use
       MapObject.mUnk_80's state machine; also read in its draw, state 1 is never written */
    /* 1fc */ s32 mState;
} Sanbo;

#include "Main/MapObjects/sanbo.h"
#include "Main/MapObjects/code_020a7eb4.h"
