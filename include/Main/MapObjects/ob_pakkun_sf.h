#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_response_and_quaternion_math.h" // Quaternion
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList, MapObjectKindData
#include "Main/MapObjects/map_object_draw_list_flags.h" // MapObjectDrawList
#include "Main/MapObjects/pushed_motion.h" // PushedObject
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/nsbmd_render_obj.h"

#define OB_PAKKUN_SF_FRAME_TOGGLE_BIT 0x10

#define OB_PAKKUN_SF_SOUND_FRAME_MASK 0x1f

#define OB_PAKKUN_SF_SOUND_ID 0x163

// SecondHand.mMapObject.mStateMachine states, in the order of gSecondHandStateTable. The hand speeds up, turns at a
// steady speed, slows down and turns around, then pauses before the next turn.
enum {
    SECOND_HAND_STATE_SPEED_UP,
    SECOND_HAND_STATE_STEADY,
    SECOND_HAND_STATE_SLOW_DOWN,
    SECOND_HAND_STATE_PAUSE,
};

// A clock second hand map object that InitSecondHand sets up: its rotation, ramp, steady and pause frames and speed.
typedef struct SecondHand {
    /* 00 */ MapObject mMapObject;
    /* a0 */ Quaternion mRotationQuaternion;
    /* b0 */ Quaternion mInitialRotationQuaternion;
    /* c0 */ u16 mRampFrameCount;
    /* c2 */ u16 mSteadyFrameCount;
    /* c4 */ u16 mPauseFrameCount;
    /* c6 */ s16 mAnglePerFrame;
    /* c8 */ s32 mSpeedFraction;
    /* cc */ s32 mSpeedFractionPerFrame;
} SecondHand;

// Object InitObPakkunSf sets up.
typedef struct ObPakkunSf {
    /* 00 */ PushedObject mPushedObject;
    /* b8 */ u16 mFramesSinceInit;
} ObPakkunSf;

typedef struct CourseMapRow CourseMapRow;

void CreateSecondHand(void);

void CreateObPakkunSf(void);

void InitSecondHand(SecondHand *secondHand, CourseMapRow *courseRow);
void ComputeSphereHitOnSecondHand(SecondHand *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void UpdateSecondHand(u32 unused, SecondHand *secondHand);
void DrawSecondHand(u32 unused, SecondHand *secondHand, u32 unusedArg, u32 alpha);
MapObjectList *CreateSecondHandUpdateList(void);
MapObjectList *CreateSecondHandDrawList(void);
MapObjectKindData *CreateSecondHandKindData(void);
void InitObPakkunSf(ObPakkunSf *obPakkunSf);

unsigned int CollideItemObjectWithSecondHand(unsigned int secondHand, unsigned int itemObject,
                                             unsigned int firstResponse, const unsigned char *response);

typedef struct SecondHand SecondHand;
typedef struct Kart Kart;

void UpdateSecondHandPause(void *stateObject);
s32 CollideKartWithSecondHand(SecondHand *secondHand, Kart *kart, s32 unused, u8 *response);

void SecondHandPauseNop(void *stateObject);

void UpdateSecondHandSlowDown(void *stateObject);

void EnterSecondHandSlowDown(void *stateObject);

void UpdateSecondHandSteady(void *stateObject);

void SecondHandSteadyNop(void *stateObject);

void UpdateSecondHandSpeedUp(void *stateObject);

void EnterSecondHandSpeedUp(void *stateObject);

typedef struct ObPakkunSf ObPakkunSf;

u8 CollideItemObjectWithObPakkunSf(ObPakkunSf *obPakkunSf, void *itemObject, u8 *firstResponse, u8 *response);
u8 CollideKartWithObPakkunSf(ObPakkunSf *obPakkunSf, void *kart, u8 *firstResponse, u8 *response);
void UpdateObPakkunSf(u32 unused, ObPakkunSf *obPakkunSf);

void DrawObPakkunSf(u32 unused, ObPakkunSf *obPakkunSf, u32 unusedArg, u16 alpha);

extern const u32 gSecondHandHitFlag;
extern const MapObjectList gSecondHandUpdateListData;
extern const MapObjectDrawList gSecondHandDrawListData;
extern const MapObjectKindData gSecondHandKindData;
extern StateCallbacks gSecondHandStateTable[4];
extern struct Nsbmd *gSecondHand;
extern MapObjectDrawList *gSecondHandDrawList;
extern MapObjectList *gSecondHandUpdateList;
