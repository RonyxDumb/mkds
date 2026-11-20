#pragma once

#include "types.h"

// Two halfwords (x and y) kept as one 32-bit value: the corners and the start pair of OrthoQuad, and SetupOrthoQuad's
// second argument.
typedef union {
    u32 mWord;
    struct {
        /* 00 */ s16 mX;
        /* 02 */ s16 mY;
    } mHalf;
} HalfwordPair;

// One of the four quads: corner pairs, their velocities, the start pair, the update function, a mode and a timer.
typedef struct OrthoQuad OrthoQuad;

struct OrthoQuad {
    /* 00 */ HalfwordPair mCorners[4];
    // Per corner: the offset SetupOrthoQuad picks, scaled by a motion table; rebuilt from the corners by
    // SetOrthoQuadVelocitiesFromCorners, after which the velocity update adds it to the corners.
    /* 10 */ s16 mCornerVelocities[4][2];
    /* 20 */ HalfwordPair mStartPair;
    /* 24 */ void (*mUpdateFunction)(OrthoQuad *quad);
    // 0 until SetOrthoQuadVelocitiesFromCorners sets 1; at 1 AdvanceOrthoQuadCornersByVelocity adds the velocities to
    // the corners, at 0 it only lowers them.
    /* 28 */ u32 mVelocityMode;
    // Counts down from the start delay and keeps counting below 0 in the later update functions.
    /* 2c */ s32 mTimer;
    // Random 0 to 5, picked again every 16th timer step of the velocity update; 4, 5 and the starting -1 match no
    // corner; only used while mVelocityMode is 0.
    /* 30 */ u32 mPickedCornerIndex;
};

static inline HalfwordPair *GetOrthoQuadCorner(OrthoQuad *quad, u32 cornerIndex) {
    return &quad->mCorners[cornerIndex];
}

void SkipOrthoQuadsHoldAndSetVelocities(int kartIndex);
void SetOrthoQuadVelocitiesFromCorners(OrthoQuad *quad);
