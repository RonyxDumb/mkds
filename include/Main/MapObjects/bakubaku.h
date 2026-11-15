#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/MapObjects/code_020e005c.h" // GroupFollower
#include "Main/MapObjects/send_obj_shadow.h" // ShadowMatrix
#include "01/MapObjects/data_0209bc74.h"

#define BAKUBAKU_WAIT_TO_RESET_FRAMES 0x708

// Sounds started where the Bakubaku rises to the surface and where its arc over the surface ends.
#define BAKUBAKU_RISE_TO_SURFACE_SOUND_ID 0x186
#define BAKUBAKU_ARC_OVER_SURFACE_SOUND_ID 0x187

// Bakubaku.mState: waits for the kart, rises through the surface, arcs over it (the only state that is drawn), sinks
// below it and waits to start again.
#define BAKUBAKU_STATE_WAIT_FOR_KART 0
#define BAKUBAKU_STATE_RISE_TO_SURFACE 1
#define BAKUBAKU_STATE_ARC_OVER_SURFACE 2
#define BAKUBAKU_STATE_SINK_BELOW_SURFACE 3
#define BAKUBAKU_STATE_WAIT_TO_RESET 4

// Object of kind 0x13c (Bakubaku): after the shared part, a counter at 0xa0, a vector at 0xa4 and a state at 0xb0.
typedef struct Bakubaku {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mWaitToResetTimer;
    /* a4 */ Vec3 mDistanceCheckPos;
    /* State number of this kind's own per-frame switch in UpdateBakubaku; this object does not use
       MapObject.mUnk_80's state machine; also read by the draw (BAKUBAKU_STATE_ARC_OVER_SURFACE = drawn) */
    /* b0 */ u32 mState;
} Bakubaku;

// Object of kind 0x1a3 (MoveTree): after the shared part, three counters from 0xa0, a halfword at 0xac, a value at
// 0xb0, an GroupFollower at 0xb4, a state at 0xd8 and an ShadowMatrix at 0xdc.
typedef struct MoveTree {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mStartDelayFrames;
    /* a4 */ s32 mKartHitFramesLeft;
    /* a8 */ s32 mFollowerSpeed;
    /* ac */ u16 mNsbcaFrameIndex;
    /* ae */ u8 mUnk_ae[2];
    /* b0 */ s32 mNsbcaFrameStep;
    /* b4 */ GroupFollower mFollower;
    /* State number of this kind's own per-frame switch in UpdateMoveTree; this object does not use
       MapObject.mUnk_80's state machine */
    /* d8 */ u32 mState;
    /* dc */ ShadowMatrix mShadowMatrix;
} MoveTree;

MapObjectList *CreateBakubakuUpdateList(void);
MapObjectList *CreateBakubakuDrawList(void);
void UpdateBakubaku(void *mapObjectList,
                    Bakubaku *bakubaku); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitBakubakuObjects(MapObjectList *mapObjectList);
void DrawBakubaku(void *mapObjectList, Bakubaku *bakubaku);
void CreateBakubakuAndBakuShadow(void *mapObjectList);
MapObjectList *CreateMoveTreeUpdateList(void);
MapObjectList *CreateMoveTreeDrawList(void);
MapObjectKindData *CreateMoveTreeKindData(void);
void UpdateMoveTree(void *mapObjectList,
                    MoveTree *moveTree); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitMoveTreeObjects(MapObjectList *mapObjectList);
void DrawMoveTree(void *mapObjectList, MoveTree *moveTree, u32 unused, u32 alpha);
void CreateMoveTree(void *mapObjectList);
u8 CollideKartWithMoveTree(MoveTree *moveTree, Kart *kart, u8 *firstResponse, u8 *response);

extern struct MapObjectModel *gBakubaku;
extern struct MapObjectModel *gBakuShadow;
