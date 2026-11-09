#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Element of 0x10 bytes: a position, then two halfwords.
typedef struct Unk0209df84_c4 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk0209df84_c4;

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
    /* 00c4 */ Unk0209df84_c4 mElements[20][20];
    /* 19c4 */ s32 mKartHitTimers[8];
    /* 19e4 */ s32 mEntryKartAxisDistance;
} Fireball2;

void *CreateFireball2UpdateList(void);
void *CreateFireball2DrawList(void);
void CreateFireball2KindData(void);
void UpdateFireball2(void *a, Fireball2 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitFireball2Objects(MapObjectList *p);
void DrawFireball2(void *a, Fireball2 *b);
void SetupDrawFireball2(void *a);
void CreateFireball2(MapObjectList *a); /* also sets word +0x1c of the group record to 1 */
BOOL IsPosNearFireball2(Fireball2 *a, Vec3 *b, s32 c);
u8 CollideKartWithFireball2(Fireball2 *a, Kart *b, u8 *c, u8 *d);
void InitFireball2(Fireball2 *a);
void *CreatePuddleDrawList(void);
