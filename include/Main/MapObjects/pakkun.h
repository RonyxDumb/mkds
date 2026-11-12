#pragma once

#include "types.h"
#include "Main/MapObjects/pakkun_spit.h"
#include "01/MapObjects/data_0209bc74.h" // MapObjectModel
#include "Main/MapObjects/code_020e005c.h" // GroupFollower
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList

// Object up to 0x200 bytes: the shared part, a counter at 0xa4 that cycles between 0xac and 0xb0, a state at 0xb4,
// seven GroupFollower from 0xb8, then a count and an index at 0x1b8 and 0x1ba and seven values at 0x1bc.
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

extern MapObjectList *gPakkunUpdateList;
extern MapObjectModel *gPakkunMouth;
extern void *gPakkunZHead;
extern void *gPakkunBodyDrawList;
extern void *gPakkunBody;
extern MapObjectList *gPakkunZHeadDrawList;
extern MapObjectList *gPakkunMouthDrawList;

void *CreatePakkunUpdateList(void);
void *CreatePakkunZHeadDrawList(void);
void *CreatePakkunBodyDrawList(void);
void *CreatePakkunMouthDrawList(void);
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
void *CreatePakkunSpitUpdateList(void);
