#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "code_0201c528.h" // ParticleInstance
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h" // GroupFollower

// Object up to 0xd4 bytes: the shared part, an GroupFollower at 0xa0, then three words and a pointer.
typedef struct PakkunSpit {
    /* 00 */ MapObject mMapObject;
    /* a0 */ GroupFollower mFollower;
    /* c4 */ s32 mHeightOffset;
    /* c8 */ s32 mHeightSpeed;
    /* cc */ s32 mState;
    /* d0 */ ParticleEmitter *mEmitter;
} PakkunSpit;

#include "Main/Unknown/code_0206bcb0.h" // Kart

extern u16 data_usa_02156590;
extern u32 data_usa_02156594;

void CreatePakkunSpitKindData(void);
void UpdatePakkunSpit(void *mapObjectList, PakkunSpit *pakkunSpit);
u32 CollideKartWithPakkunSpit(PakkunSpit *pakkunSpit, Kart *kart, u8 *firstResponse, u8 *response);
void InitPakkunSpit(MapObject *mapObject);
