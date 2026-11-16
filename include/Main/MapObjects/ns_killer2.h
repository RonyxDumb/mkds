#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/MapObjects/segment_group_collision.h" // GroupFollower
#include "Main/Sound/sound_distance_squared_change.h" // SoundDistanceSquaredChange
#include "01/MapObjects/map_object_model.h"

#define NS_KILLER2_PARK_WAIT_FRAMES 0x78
#define NS_KILLER2_PARK_TIMER_LIMIT 0x24e
#define NS_KILLER2_PARK_FRAMES 600

#define NS_KILLER2_HEIGHT_RANGE_MAX 0x32000

// A pooled NsKiller2 map object: its park timer, mode and sound distance change.
typedef struct NsKiller2 {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mParkTimer;
    /* a4 */ s32 mMode;
    /* a8 */ SoundDistanceSquaredChange *mSoundDistanceSquaredChange;
} NsKiller2;

// Values of NsKiller1.mState: wait, follow the path, pause at its end, then launch an NsKiller2 and start over.
enum {
    NS_KILLER1_STATE_WAIT,
    NS_KILLER1_STATE_FOLLOW_PATH,
    NS_KILLER1_STATE_PAUSE,
    NS_KILLER1_STATE_LAUNCH,
};

// An NsKiller1 map object: its state timer, state and the follower it moves along.
typedef struct NsKiller1 {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mStateTimer;
    /* a4 */ u8 mUnk_a4[4];
    /* State number of this kind's own per-frame switch in UpdateNsKiller1; this object does not use
       MapObject.mUnk_80's state machine */
    /* a8 */ s32 mState;
    /* ac */ GroupFollower mFollower;
} NsKiller1;

void StartNsKiller2(Vec3 *startPos, Vec3 *direction, u16 angle);
void CreateNsKiller2UpdateList(void);
void CreateNsKiller2DrawList(void);
void CreateNsKiller2KindData(void);
void UpdateNsKiller2(void *mapObjectList,
                     NsKiller2 *nsKiller2); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawNsKiller2(void *mapObjectList, NsKiller2 *nsKiller2);
void CreateNsKiller2AndNsKiller2S(void *mapObjectList);
u8 CollideKartWithNsKiller2(NsKiller2 *nsKiller2, Kart *kart, u8 *flagPtr, u8 *resultPtr);
/* creates the pooled object hidden (parks it with ParkMapObject); the spawner later takes it with
 * UnparkFirstParkedMapObject */
void InitNsKiller2(NsKiller2 *nsKiller2);
MapObjectList *CreateNsKiller1UpdateList(void);
MapObjectList *CreateNsKiller1DrawList(void);
void UpdateNsKiller1(void *mapObjectList,
                     NsKiller1 *nsKiller1); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitNsKiller1Objects(MapObjectList *mapObjectList);
void DrawNsKiller1(void *mapObjectList, NsKiller1 *nsKiller1);
void CreateNsKiller1(void *mapObjectList);

extern const u16 gNsKiller2SkipViewTestFlag;
extern const u16 gNsKiller2DisabledFlag;
extern const u32 gNsKiller2SkipSoundFlag;
extern struct MapObjectModel *gNsKiller2S;
extern struct MapObjectModel *gNsKiller2;
