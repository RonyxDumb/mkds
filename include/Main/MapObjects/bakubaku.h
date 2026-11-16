#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/MapObjects/segment_group_collision.h" // GroupFollower
#include "Main/MapObjects/send_obj_shadow.h" // ShadowMatrix
#include "01/MapObjects/map_object_model.h"

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

// A Bakubaku map object: the timer before it resets, the position its distance is checked from and its state.
typedef struct Bakubaku {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mWaitToResetTimer;
    /* a4 */ Vec3 mDistanceCheckPos;
    /* State number of this kind's own per-frame switch in UpdateBakubaku; this object does not use
       MapObject.mUnk_80's state machine; also read by the draw (BAKUBAKU_STATE_ARC_OVER_SURFACE = drawn) */
    /* b0 */ u32 mState;
} Bakubaku;

// A moving tree map object: its start delay, kart hit timer, follower, animation frame, state and shadow.
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
void LoadMoveTreeMapObject(void *mapObjectList);
u8 CollideKartWithMoveTree(MoveTree *moveTree, Kart *kart, u8 *firstResponse, u8 *response);

extern struct MapObjectModel *gBakubaku;
extern struct MapObjectModel *gBakuShadow;
