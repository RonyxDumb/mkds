#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020e005c.h" // GroupFollower
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Object of kind 0x1a4 (MkdEfBurner); Unk02093708 is a view of the draw group record (word +0x1c), not of this
// object. After the shared part, a counter at 0xa0, a halfword at 0xa4, a value at 0xa8, a
// state at 0xac, a GroupFollower at 0xb0 and a table of countdowns at 0xd4.
typedef struct MkdEfBurner {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mStateFrames;
    /* a4 */ u16 mNsbtaFrameIndex;
    /* a6 */ u8 mUnk_a6[2];
    /* a8 */ s32 mScaleFixed12;
    /* State number of this kind's own per-frame switch in UpdateMkdEfBurner; this object does not use
       MapObject.mUnk_80's state machine; state 4 only from the group pre-step */
    /* ac */ u32 mState;
    /* b0 */ GroupFollower mFollower;
    /* d4 */ s32 mKartTimers[8];
} MkdEfBurner;

u16 CountMkdEfBurnerScaleThresholds(MkdEfBurner *burner);
void CreateMkdEfBurnerUpdateList(void);
void CreateMkdEfBurnerDrawList(void);
void CreateMkdEfBurnerKindData(void);
void UpdateMkdEfBurner(void *mapObjectList,
                       MkdEfBurner *mkdEfBurner); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitMkdEfBurnerObjects(MapObjectList *mapObjectList);
void DrawMkdEfBurner(void *mapObjectList, MkdEfBurner *mkdEfBurner);
void SetupDrawMkdEfBurner(void *mapObjectList);
void CreateMkdEfBurner(MapObjectList *mapObjectList); /* also sets word +0x1c of the group record to 1 */
u8 CollideKartWithMkdEfBurner(MkdEfBurner *mkdEfBurner, Kart *kart, u8 *firstResponse, u8 *response);
void InitMkdEfBurner(
    MapObject *mapObject); /* allocates the object's sound source (CreateMapObjectSoundSourceFalloff2) */
