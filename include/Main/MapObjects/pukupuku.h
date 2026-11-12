#pragma once

#include "types.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/pukupuku_init.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/MapObjects/pendulum.h"

void CreatePukupuku(void);

typedef struct Pukupuku Pukupuku;

s32 CollideItemObjectWithPukupuku(Pukupuku *pukupuku, void *itemObject, u8 *firstResponse, u8 *response);

u8 CollideKartWithPukupuku(Pukupuku *pukupuku, Kart *kart, u8 *firstResponse, u8 *response);

void UpdatePukupukuState3(Pukupuku *pukupuku);

void EnterPukupukuState3(Pukupuku *pukupuku);

void UpdatePukupukuState2(Pukupuku *pukupuku);

void EnterPukupukuState2(Pukupuku *pukupuku);

void UpdatePukupukuState1(Pukupuku *pukupuku);

void EnterPukupukuState1(Pukupuku *pukupuku);

void UpdatePukupukuState0(Pukupuku *pukupuku);

void EnterPukupukuState0(Pukupuku *pukupuku);

void UpdatePukupuku(u32 unused, Pukupuku *pukupuku);

// 0x10-byte request built on the stack here.
typedef struct PukupukuShadowParams {
    /* 00 */ s32 mScale;
    /* 04 */ Vec3 mPos;
} PukupukuShadowParams;

void DrawPukupukuShadow(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u32 alpha);

void SetupDrawPukupukuShadow(void);

typedef struct MapObjectKindData MapObjectKindData;


// 0x2c-byte object built from a table: a MapObjectList followed by the slot.
typedef struct PukupukuShadowDrawList {
    /* 00 */ void **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ void (*mInit)(struct MapObjectList *p);
    /* 0c */ void (*mBeforeObjects)(struct MapObjectList *p);
    /* 10 */ UnkFunc *mForEachObject;
    /* 14 */ void (*mAfterObjects)(struct MapObjectList *p);
    /* 18 */ u32 mDrawPass;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ void **mDrawObjects;
    /* 28 */ u32 mListSlot;
} PukupukuShadowDrawList;


// 0x2c-byte object built from a table: a MapObjectList followed by the slot.
typedef struct PukupukuDrawList {
    /* 00 */ void **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ void (*mInit)(struct MapObjectList *p);
    /* 0c */ void (*mBeforeObjects)(struct MapObjectList *p);
    /* 10 */ UnkFunc *mForEachObject;
    /* 14 */ void (*mAfterObjects)(struct MapObjectList *p);
    /* 18 */ u32 mDrawPass;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ void **mDrawObjects;
    /* 28 */ u32 mListSlot;
} PukupukuDrawList;


MapObjectKindData *CreatePukupukuKindData(void);
PukupukuDrawList *CreatePukupukuDrawList(void);
PukupukuShadowDrawList *CreatePukupukuShadowDrawList(void);
MapObjectList *CreatePukupukuUpdateList(void);
void SetupDrawPukupuku(void);
void DrawPukupuku(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u16 alpha);

extern const u16 gPukupukuState2Flag;
extern const u16 gPukupukuState2SecondFlag;
extern const struct MapObjectList gPukupukuUpdateListData;
extern const struct PukupukuShadowDrawList gPukupukuShadowDrawListData;
extern const struct PukupukuDrawList gPukupukuDrawListData;
extern const u16 gPukupukuPushedFlag;
extern const struct MapObjectKindData gPukupukuKindData;
extern struct NsbmdModel *gPukupuku;
extern PukupukuShadowDrawList *gPukupukuShadowDrawList;
extern MapObjectList *gPukupukuUpdateList;
extern Vec3 gPukupukuDrawScale;
extern PukupukuDrawList *gPukupukuDrawList;
