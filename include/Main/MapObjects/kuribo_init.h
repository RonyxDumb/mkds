#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/map_object_response_and_quaternion_math.h" // Quaternion
#include "Main/MapObjects/segment_group_collision.h" // GroupFollower

typedef struct CourseMapRow CourseMapRow;

// Kuribo.mMapObject.mStateMachine states, in the order of gKuriboStateTable.
#define KURIBO_STATE_WALK_PATH 0
#define KURIBO_STATE_FALL_TO_SURFACE 1 // objects created without a path start here
#define KURIBO_STATE_STRETCH 2 // after a hit: the height scale grows to 0x1800
#define KURIBO_STATE_SHRINK 3
#define KURIBO_STATE_FLAT_WAIT 4 // waits 300 frames to return, else fades out
#define KURIBO_STATE_SPRING_BACK 5 // the height scale springs back to 0x1000

// Kuribo.mScaleFactorY: the resting value, the spring pull and the speed damping per frame that bring it back to rest,
// how close to rest (value and speed) it snaps back, and the factor the shrink state multiplies it by each frame.
#define KURIBO_SCALE_FACTOR_Y_REST TO_FIXED12(1)
#define KURIBO_SCALE_SPRING_STIFFNESS 0x200
#define KURIBO_SCALE_DAMPING 0xd99
#define KURIBO_SCALE_SETTLE_RANGE 0x29
#define KURIBO_SCALE_SHRINK_FACTOR 0xd99

// Object of kind 0x191 (Kuribo), at least 0x108 bytes; also created in pools by ov001.
typedef struct Kuribo {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mStartY;
    /* a4 */ Quaternion mOrientation;
    /* b4 */ Quaternion mTargetOrientation;
    /* c4 */ s32 mScaleFactorY;
    /* c8 */ s32 mScaleFactorYSpeed;
    /* cc */ GroupFollower mFollower;
    /* f0 */ u16 mFrameIndex;
    /* f2 */ u8 mUnk_f2[2];
    /* f4 */ s32 mFrameRandomized;
    /* f8 */ u16 mOrientationBlendAmount;
    /* fa */ u8 mUnk_fa[2];
    /* fc */ s32 mReturnsAfterWait;
    /* 100 */ u16 mModelAlpha;
    /* 102 */ s16 mToggleCountdown;
    /* 104 */ s32 mToggleState;
} Kuribo;

/* also runs for source-created objects with row == NULL (no path follower; starts in state 1) */
void InitKuribo(Kuribo *kuribo, CourseMapRow *row);
MapObjectKindData *CreateWaterKindData(void);
