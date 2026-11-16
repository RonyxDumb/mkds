#pragma once

#include "types.h"
#include "Main/MapObjects/pakkun_spit.h"
#include "01/MapObjects/map_object_model.h" // MapObjectModel
#include "Main/MapObjects/segment_group_collision.h" // GroupFollower
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "Main/MapObjects/map_object_kind_update_list.h"

#define PAKKUN_SPIT_PATH_SPEED 0x7800
#define PAKKUN_HEAD_HEIGHT 0x46000
#define PAKKUN_BODY_STRETCH_SPEED_LIMIT 4
#define PAKKUN_LEAN_FRAMES 0x1e
#define PAKKUN_BODY_STRETCH_SETTLE 0xffc
#define PAKKUN_HEAD_SCALE_SPEED_START 0x7b
#define PAKKUN_HEAD_SCALE_SPIT_LIMIT 0x119a

#define PAKKUN_SPIT_SOUND_ID 0x171

// Values of Pakkun.mState: turn to a follower, lean back, grow the head, spit, lean forward.
enum {
    PAKKUN_STATE_PICK_TARGET,
    PAKKUN_STATE_TURN_HEAD,
    PAKKUN_STATE_WAIT_BODY_SETTLE,
    PAKKUN_STATE_LEAN_BACK,
    PAKKUN_STATE_GROW_HEAD,
    PAKKUN_STATE_SPIT,
    PAKKUN_STATE_LEAN_FORWARD,
};

// A Pakkun map object: its mouth animation, state, up to seven followers, head and body stretch motion.
typedef struct Pakkun {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ u16 mPolygonId;
    /* 0a2 */ u8 mUnk_0a2[2];
    /* 0a4 */ s32 mMouthFrame;
    /* 0a8 */ s32 mMouthFrameStep;
    /* 0ac */ s32 mMouthLoopFrame;
    /* 0b0 */ s32 mMouthEndFrame;
    /* 0b4 */ s32 mState;
    /* 0b8 */ GroupFollower mFollowers[7];
    /* 1b4 */ s32 mTimer;
    /* 1b8 */ u16 mFollowerIndex;
    /* 1ba */ u16 mFollowerCount;
    /* 1bc */ s32 mFollowerYawOffsets[7];
    /* 1d8 */ s32 mBaseYaw;
    /* 1dc */ s32 mHeadYaw;
    /* 1e0 */ s32 mHeadPitch;
    /* 1e4 */ BOOL mBodyStretchActive;
    /* 1e8 */ s32 mBodyStretch;
    /* 1ec */ s32 mBodyStretchSpeed;
    /* 1f0 */ s32 mHeadScale;
    /* 1f4 */ s32 mHeadScaleSpeed;
    /* 1f8 */ s32 mHeadHeight;
    /* 1fc */ s32 mHeightAboveFollowerPath;
} Pakkun;


MapObjectList *CreatePakkunUpdateList(void);
MapObjectList *CreatePakkunZHeadDrawList(void);
MapObjectList *CreatePakkunBodyDrawList(void);
MapObjectList *CreatePakkunMouthDrawList(void);
void UpdatePakkun(void *mapObjectList, Pakkun *pakkun); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitPakkunObjects(void);
void DrawPakkunBody(void *mapObjectList, Pakkun *pakkun);
void SetupDrawPakkunBody(void *mapObjectList);
void CreatePakkunBody(void *mapObjectList);
void DrawPakkunZHead(void *mapObjectList, Pakkun *pakkun);
void SetupDrawPakkunZHead(void *mapObjectList);
void CreatePakkunZHead(void *mapObjectList);
void DrawPakkunMouth(void *mapObjectList, Pakkun *pakkun);
void CreatePakkunMouth(void *mapObjectList);
void InitPakkun(Pakkun *pakkun);
void StartPakkunSpit(GroupFollower *groupFollower, s32 heightOffset);
MapObjectList *CreatePakkunSpitUpdateList(void);

extern MapObjectKindDescriptor gPakkunKindDescriptor;
extern MapObjectList *gPakkunUpdateList;
extern void *gPakkunZHead;
extern MapObjectModel *gPakkunMouth;
extern MapObjectList *gPakkunMouthDrawList;
extern void *gPakkunBodyDrawList;
extern void *gPakkunBody;
extern MapObjectList *gPakkunZHeadDrawList;

extern const u16 gFlipperMirrorFlag;
extern const u32 gFlipperSkipSoundFlag;
