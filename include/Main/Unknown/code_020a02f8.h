#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object with the MapObject base at 0x00 (bsfx_update, bsfx_globalLogicInit, bsfx_init).
typedef struct Unk020a0318 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mDistanceVolumeFixed12;
    // Radius in whole units; the inner half-radius test uses w / 2 without the << 12.
    /* a8 */ s32 mRadius;
    /* ac */ s32 mCenterX;
    /* b0 */ s32 mCenterY;
    /* b4 */ s32 mCenterZ;
    /* b8 */ BOOL mDistanceLevelInverted;
    /* bc */ u16 mSoundId;
    /* be */ u16 mSecondSoundId;
    /* c0 */ s32 mDistanceLevelTimer;
    /* c4 */ s32 mDistanceLevel;
    /* c8 */ s32 mSoundTimer;
} Unk020a0318;

// Array of object pointers: pointer to the array and the number of entries (bsfx_globalLogicInit).
typedef struct Unk020a066c {
    /* 00 */ Unk020a0318 **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
} Unk020a066c;

#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h" // CourseMapPoint

void *bsfx_setupLogicPart(void);
void bsfx_update(void *mapObjectList, Unk020a0318 *mapObject);
void bsfx_globalLogicInit(MapObjectList *mapObjectList);
void bsfx_init(Unk020a0318 *mapObject);
// Steps Standings once per race_update call in battle and mission run: the end timer and end callback, the hand- over of
// eliminated karts, the hit tracking, and the copy of each kart's position.
void mgcnt_update(void);
// Ends the Standings end timer (mEndTimer = -1) and runs mEndCallback when it is set; the mode 4 end step of the race
// progress calls it.
void mgcnt_forceEnd(void);
void mgcnt_init(void);
CourseMapPoint *mgcnt_getRandomShineMepo(void);
Vec3 *mgcnt_getDriverPosition(int kartIndex);
void mgcnt_20A1748(u16 kartIndex);
void mgcnt_checkMgEnd(void);
void mgcnt_killDriverDirect(u16 kartIndex);
void mgcnt_handleDriverBalloonShineCountDecrease(u16 kartIndex);
void mgcnt_handleDriverBalloonShineCountIncrease(u16 kartIndex);
u16 mgcnt_20A1CD8(s32 kartIndex);
void mgcnt_20A1DDC(s32 kartIndex);
unsigned int mgcnt_notifyStarInvincibilityStart(unsigned int value);
