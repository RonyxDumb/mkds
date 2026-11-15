#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/code_020e005c.h"
#include "Main/MapObjects/send_obj_shadow.h"

// IronBall.mState: waits for its start (timer or lap), counts mState1Timer down, then rolls along the path.
#define IRON_BALL_STATE_WAIT_START 0
#define IRON_BALL_STATE_WAIT_APPEAR 1
#define IRON_BALL_STATE_ROLL 2

// IronBall.mShadowStage: no shadow, shadow drawn, or shadow matrix to refresh (set back to drawn after).
#define IRON_BALL_SHADOW_OFF 0
#define IRON_BALL_SHADOW_ON 1
#define IRON_BALL_SHADOW_REFRESH 2

// IronBall.mPathSpeed: the scale for the setting percent (normal and slow), which also floors the speed after a
// bound or flipper entry, the speeds of the two path entry values 10 and 11, the speeds on entering a bound or
// flipper entry, and how much the speed drops per frame there.
#define IRON_BALL_PATH_SPEED_NORMAL_UNIT 0xa000L
#define IRON_BALL_PATH_SPEED_SLOW_UNIT 0x5000L
#define IRON_BALL_PATH_SPEED_HEIGHT_FAST 0x8000
#define IRON_BALL_PATH_SPEED_HEIGHT_SLOW 0x5000
#define IRON_BALL_PATH_SPEED_BOUND 0xf000
#define IRON_BALL_PATH_SPEED_FLIPPER 0x1e000
#define IRON_BALL_PATH_SPEED_DECAY 410

// Object of kinds 0x1b0 and 0x1b3 (IronBall; kind 0x1b3 has only Init and Draw, no update or collision group), 0x134
// bytes: the shared MapObject part, a GroupFollower at 0xc4 and a ShadowMatrix at 0xe8.
typedef struct IronBall {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mRotateZAngle;
    /* 0a4 */ s32 mState1Timer;
    /* 0a8 */ s32 mTimer;
    /* 0ac */ s32 mNextStartLap;
    /* 0b0 */ s32 mPathSpeed;
    /* 0b4 */ s32 mNormalPathSpeed;
    /* 0b8 */ s32 mSlowPathSpeed;
    /* 0bc */ s32 mHeightOffset;
    /* 0c0 */ s32 mHeightSpeed;
    /* 0c4 */ GroupFollower mFollower;
    /* 0e8 */ ShadowMatrix mShadowMatrix;
    /* 11c */ Vec3 mPathPos;
    /* 128 */ s32 mSoundOffZoneMask;
    /* 12c */ s32 mShadowStage;
    /* 130 */ s32 mState;
} IronBall;

#include "Main/Course/course_sound_object.h" // CourseSoundObjectPart

void PlaceCourseSoundObjectPartSource(CourseSoundObjectPart *soundPart, Vec3 *position);
typedef struct MapObjectList MapObjectList;

MapObjectList *CreateIronBallUpdateList(void);
MapObjectList *CreateIronBallDrawList(void);
MapObjectList *CreateIronBallShadowDrawList(void);
MapObjectKindData *CreateIronBallKindData(void);
void UpdateIronBall(void *mapObjectList, IronBall *ironBall); /* kind 0x1b0 only */
void InitIronBallObjects(MapObjectList *mapObjectList);
void DrawIronBallShadow(void *mapObjectList, IronBall *ironBall, u32 unused, u32 alpha);
void IronBallNop(void);

extern const u16 gIronBallInitThirdFlag;
extern const u16 gIronBallInitSecondFlag;
extern const u16 gIronBallInitFirstFlag;
extern const u16 gIronBallPathEntryFlag;
