#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectKindData
#include "01/MapObjects/map_object_model.h"

#define SANBO_SOUND_FRAMES 0x14
#define SANBO_FAST_WOBBLE_FRAMES 0x3c
#define SANBO_PIECE_COUNT 4
#define SANBO_WOBBLE_AMPLITUDE 0x71c
#define SANBO_WOBBLE_ANGLE_PER_FRAME 0x2d8
#define SANBO_FAST_WOBBLE_ANGLE_PER_FRAME 0xb61
#define SANBO_WOBBLE_SOUND_ANGLE_PER_FRAME 0x38e

#define SANBO_HIT_SOUND_ID 0x193
#define SANBO_WOBBLE_SOUND_ID 0x194

void ShineEndCallback(void);
void ShineKartEliminatedCallback(u16 kartIndex);
BOOL ShineKartHitCallback(u16 kartIndex, u16 hitByKartIndex);

typedef struct MapObjectList MapObjectList;

MapObjectList *CreateSanboUpdateList(void);
MapObjectList *CreateSanboDrawList(void);

MapObjectKindData *CreateSanboKindData(void);

void SanboSetupDrawNop(void);

extern const u16 gSanboHitFlag;
extern const u16 gSanboSecondHitFlag;
extern struct MapObjectModel *gSanboB;
extern struct MapObjectModel *gSanboH;
