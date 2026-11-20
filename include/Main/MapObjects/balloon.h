#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject

// Values of Balloon.mState: the scale changes with the kart's balloon count and the balloon swings, the scale settles
// to full size, and full size.
enum {
    BALLOON_STATE_SWING,
    BALLOON_STATE_SETTLE,
    BALLOON_STATE_FULL,
};

// A battle balloon map object, also held by the KartBalloons of the KartBalloonsObject that steps the balloons of every
// kart.
typedef struct Balloon {
    /* 00 */ MapObject mMapObject;
    // Frames left while the balloon has no kart: 0x1e from StartBalloonWithoutKart, counted down each update; at 0 the
    // end effects start and the object is parked.
    /* a0 */ s32 mNoKartTimer;
    // Index of the kart whose list holds the balloon, -1 while it has no kart (set at creation and by
    // StartBalloonWithoutKart).
    /* a4 */ s32 mKartIndex;
    // Frame index of the balloon's .nsbtp animation, stored at creation from the kart's mBalloonNsbtpFrameIndex and
    // held fixed; the draw passes it to the frame setter and the effect callback uses it as an index into a table.
    /* a8 */ s32 mNsbtpFrameIndex;
    /* ac */ u8 mUnk_ac[4];
    // The point the balloon follows, derived from the kart's position; set at creation and every frame by
    // SetBalloonTargetPosAndVelocity and moved by mTargetVelocity.
    /* b0 */ Vec3 mTargetPos;
    // Velocity of mTargetPos: the kart's velocity while attached; a balloon without a kart falls (y -0x2000 per frame).
    /* bc */ Vec3 mTargetVelocity;
    /* c8 */ s32 mSwingAngle;
    /* cc */ s32 mSwingAnglePerFrame;
    // Size of the balloon in 20.12 fixed point (0x1000 = full size): grows while inflating; UpdateKartBalloons treats
    // <= 0 as gone and >= 0x1000 as full.
    /* d0 */ s32 mScaleFactor;
    /* d4 */ s32 mScaleFactorPerFrame;
    /* d8 */ s32 mScaleSwing;
    /* dc */ s32 mScaleSwingPerFrame;
    /* e0 */ s32 mHorizontalPullEnabled;
    /* e4 */ s32 mDrawScale;
    /* e8 */ Vec3 mDrawPos;
    // Number of balloons this object draws: 1 for the local kart's balloons (each draws itself), the kart's count for
    // the first balloon of another kart's list, 0 for its other balloons.
    /* f4 */ s32 mDrawCount;
    // The kart's balloon list that the first balloon draws (mDrawCount entries); NULL when a balloon draws only itself.
    /* f8 */ struct Balloon **mDrawList;
    /* State number of this kind's own per-frame switch in UpdateBalloon; this object does not use
       MapObject.mUnk_80's state machine */
    /* fc */ s32 mState;
} Balloon;

void SetBalloonDrawCountAndList(Balloon *balloon, u16 drawCount, void *drawList);
void SetBalloonKartIndex(Balloon *balloon, u16 kartIndex);
s32 GetBalloonScaleFactor(Balloon *balloon);
void DisableBalloonHorizontalPull(Balloon *balloon);
