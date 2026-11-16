#pragma once

#include "types.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/pukupuku_init.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/MapObjects/pendulum.h"

#define PUKUPUKU_WAIT_FRAMES 0x12c

#define PUKUPUKU_HOP_SOUND_ID 0x10b

void CreatePukupuku(void);

typedef struct Pukupuku Pukupuku;

// Pukupuku.mPushedObject.mMapObject.mStateMachine states, in the order of gPukupukuStateTable. HOP bounces around the
// start; PUSHED follows a hit; WAIT_RESPAWN waits 300 frames; RESPAWN returns to the start and goes on with HOP.
enum {
    PUKUPUKU_STATE_HOP,
    PUKUPUKU_STATE_PUSHED,
    PUKUPUKU_STATE_WAIT_RESPAWN,
    PUKUPUKU_STATE_RESPAWN,
};

s32 CollideItemObjectWithPukupuku(Pukupuku *pukupuku, void *itemObject, u8 *firstResponse, u8 *response);

u8 CollideKartWithPukupuku(Pukupuku *pukupuku, Kart *kart, u8 *firstResponse, u8 *response);

void UpdatePukupukuRespawn(void *stateObject);

void EnterPukupukuRespawn(void *stateObject);

void UpdatePukupukuWaitRespawn(void *stateObject);

void EnterPukupukuWaitRespawn(void *stateObject);

void UpdatePukupukuPushed(void *stateObject);

void EnterPukupukuPushed(void *stateObject);

void UpdatePukupukuHop(void *stateObject);

void EnterPukupukuHop(void *stateObject);

void UpdatePukupuku(u32 unused, Pukupuku *pukupuku);

// The shadow request of a Pukupuku: a scale and a position.
typedef struct PukupukuShadowParams {
    /* 00 */ s32 mScale;
    /* 04 */ Vec3 mPos;
} PukupukuShadowParams;

void DrawPukupukuShadow(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u32 alpha);

void SetupDrawPukupukuShadow(void);

typedef struct MapObjectKindData MapObjectKindData;

MapObjectKindData *CreatePukupukuKindData(void);
MapObjectList *CreatePukupukuDrawList(void);
MapObjectList *CreatePukupukuShadowDrawList(void);
MapObjectList *CreatePukupukuUpdateList(void);
void SetupDrawPukupuku(void);
void DrawPukupuku(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u16 alpha);

extern const u16 gPukupukuWaitRespawnFlag;
extern const u16 gPukupukuWaitRespawnSecondFlag;
extern const struct MapObjectList gPukupukuUpdateListData;
extern const MapObjectDrawList gPukupukuShadowDrawListData;
extern const MapObjectDrawList gPukupukuDrawListData;
extern const u16 gPukupukuPushedFlag;
extern const struct MapObjectKindData gPukupukuKindData;
extern struct NsbmdModel *gPukupuku;
extern MapObjectDrawList *gPukupukuShadowDrawList;
extern MapObjectList *gPukupukuUpdateList;
extern Vec3 gPukupukuDrawScale;
extern MapObjectDrawList *gPukupukuDrawList;
