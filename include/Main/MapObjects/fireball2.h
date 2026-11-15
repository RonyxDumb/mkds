#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "01/MapObjects/map_object_model.h"

#define FIREBALL2_KART_HIT_FRAMES 0xb
#define FIREBALL2_ROW_ANGLE_SPACING 0x10000

// Element of 0x10 bytes: a position, then two halfwords.
typedef struct Fireball2Element {
    /* 00 */ Vec3 mPos;
    /* 0c */ u16 mAngle;
    /* 0e */ u16 mRotationAngle;
} Fireball2Element;

// Object of kind 0x1af (Fireball2). After the shared part, the counts at 0xa0 and 0xa2, a grid of elements from 0xc4
// (rows of 0x140 bytes, 0xa0 rows of 0xa2 elements) and the words from 0x19c4.
typedef struct Fireball2 {
    /* 0000 */ MapObject mMapObject;
    /* 00a0 */ u16 mRowCount;
    /* 00a2 */ u16 mRowElementCount;
    /* 00a4 */ u16 mRowAngleSpacing;
    /* 00a6 */ u8 mUnk_a6[2];
    /* 00a8 */ s32 mElementRadiusSpacing;
    /* 00ac */ s32 mRadius;
    /* 00b0 */ u16 mRowAnglePerFrame;
    /* 00b2 */ u16 mRowAngle;
    /* 00b4 */ Vec3 mCenterPos;
    /* 00c0 */ u8 mUnk_c0[2];
    /* 00c2 */ u16 mCenterRotationAngle;
    /* 00c4 */ Fireball2Element mElements[20][20];
    /* 19c4 */ s32 mKartHitTimers[8];
    /* 19e4 */ s32 mEntryKartAxisDistance;
} Fireball2;

MapObjectList *CreateFireball2UpdateList(void);
MapObjectList *CreateFireball2DrawList(void);
MapObjectKindData *CreateFireball2KindData(void);
void UpdateFireball2(void *mapObjectList,
                     Fireball2 *fireball2); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitFireball2Objects(MapObjectList *mapObjectList);
void DrawFireball2(void *mapObjectList, Fireball2 *fireball2);
void SetupDrawFireball2(void *mapObjectList);
void CreateFireball2(MapObjectList *mapObjectList); /* also sets word +0x1c of the group record to 1 */
BOOL IsPosNearFireball2(Fireball2 *fireball2, Vec3 *pos, s32 radius);
u8 CollideKartWithFireball2(Fireball2 *fireball2, Kart *kart, u8 *firstResponse, u8 *response);
void InitFireball2(Fireball2 *fireball2);
MapObjectList *CreatePuddleDrawList(void);

extern const u16 gSunFireballInitMapObjectFlag;
extern const u32 gFireball2SkipSoundFlag;
extern struct MapObjectModel *gFireball2;

