#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectKindData
#include "01/MapObjects/data_0209bc74.h"

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
