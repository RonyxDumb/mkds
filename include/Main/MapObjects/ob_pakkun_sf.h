#pragma once

#include "types.h"
#include "Main/MapObjects/code_020d6dc0.h" // Quaternion
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList, MapObjectKindData
#include "Main/MapObjects/data_02158000.h" // MapObjectDrawList
#include "Main/MapObjects/pushed_motion.h" // PushedObject
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/nsbmd_render_obj.h"

// Object InitSecondHand sets up, 0xd0 bytes.
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
MapObjectDrawList *CreateSecondHandDrawList(void);
MapObjectKindData *CreateSecondHandKindData(void);
void InitObPakkunSf(ObPakkunSf *obPakkunSf);

unsigned int CollideItemObjectWithSecondHand(unsigned int secondHand, unsigned int itemObject,
                                             unsigned int firstResponse, unsigned int response);

typedef struct SecondHand SecondHand;
typedef struct Kart Kart;

void UpdateSecondHandState3(SecondHand *secondHand);
s32 CollideKartWithSecondHand(SecondHand *secondHand, Kart *kart, s32 unused, u8 *response);

unsigned int SecondHandState3ReturnArgument(unsigned int value);

void UpdateSecondHandState2(SecondHand *secondHand);

void EnterSecondHandState2(SecondHand *secondHand);

void UpdateSecondHandState1(SecondHand *secondHand);

unsigned int SecondHandState1ReturnArgument(unsigned int value);

void UpdateSecondHandState0(SecondHand *secondHand);

void EnterSecondHandState0(SecondHand *secondHand);

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
