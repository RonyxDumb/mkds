#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct CourseMapRow CourseMapRow;

MapObject *CreateMapObject(u32 kind, CourseMapRow *courseRow, MapObject *source);
MapObject *CreateMapObjectFromObject(MapObject *source, s32 kind);
MapObject *CreateMapObjectFromCourseMapRow(CourseMapRow *courseRow, s32 kind);
void InitMapObjects(void);
void RunMapObjectDrawListInits(void);
void RunMapObjectUpdateListInits(void);

extern const u16 gCollisionSlotPosStepFlag;
extern const u16 gMapObjectNoUpdateListFlag;
extern const u16 gMapObjectNoDrawListSecondFlag;
extern const u16 gMapObjectNoDrawListFlag;
extern const u16 gMapObjectNotCollidableFlag;
extern const u16 gMapObjectNoShapeFlag;
extern const u16 gMapObjectTimeAttackOrWiFiFlag;
extern const u16 gCollisionSlotKindFlag;
