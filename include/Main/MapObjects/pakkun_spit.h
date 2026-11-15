#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "particle_instance.h" // ParticleInstance
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/segment_group_collision.h" // GroupFollower

// Object up to 0xd4 bytes: the shared part, an GroupFollower at 0xa0, then three words and a pointer.
typedef struct PakkunSpit {
    /* 00 */ MapObject mMapObject;
    /* a0 */ GroupFollower mFollower;
    /* c4 */ s32 mHeightOffset;
    /* c8 */ s32 mHeightSpeed;
    /* cc */ s32 mState;
    /* d0 */ ParticleEmitter *mEmitter;
} PakkunSpit;

#include "Main/Kart/kart_drift.h" // Kart

#define PAKKUN_SPIT_HEIGHT_SPEED 0x5800

#define PAKKUN_SPIT_OBJECT_SOUND_ID 0x1af

MapObjectKindData *CreatePakkunSpitKindData(void);
void UpdatePakkunSpit(void *mapObjectList, PakkunSpit *pakkunSpit);
u32 CollideKartWithPakkunSpit(PakkunSpit *pakkunSpit, Kart *kart, u8 *firstResponse, u8 *response);
void InitPakkunSpit(MapObject *mapObject);

extern const u16 gFlipperInitMapObjectFlag;
