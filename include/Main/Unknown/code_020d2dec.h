#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct CourseMapRow CourseMapRow;

MapObject *mobj_createObject(u32 kind, CourseMapRow *courseRow, MapObject *source);
MapObject *mobj_createSubObject(MapObject *source, s32 kind);
MapObject *mobj_createObjectFromObji(CourseMapRow *courseRow, s32 kind);
void mobj_init(void);
void mobj_initAllRenderParts(void);
void mobj_initAllLogicParts(void);
