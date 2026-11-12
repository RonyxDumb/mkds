#pragma once

#include "types.h"
#include "Main/MapObjects/pushed_motion.h" // PushedObject
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

void CreateEarthenPipe1AndEarthenPipe2(void);

typedef struct PushedObject PushedObject;

u8 CollideKartWithEarthenPipe(PushedObject *pipe, void *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideItemObjectWithEarthenPipe(PushedObject *pipe, void *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);

void UpdateEarthenPipe(u32 unused, PushedObject *pipe);

void DrawEarthenPipe(u32 unused0, PushedObject *pipe, u32 unused1, u16 maxAlpha);

extern struct MapObjectDrawList *gEarthenPipeDrawList;
extern struct MapObjectList *gEarthenPipeUpdateList;
extern struct NsbmdModel *gEarthenPipe1;

extern const MapObjectKindDescriptor gEarthenPipeKindDescriptor;
