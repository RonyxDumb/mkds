#pragma once

#include "types.h"

u16 AllocPolygonIdWrapping(void);
u16 AllocPolygonId(void);
u16 CountMapObjectsOfKind(u32 kind);
void ParkFlaggedMapObjects(void);
void UnparkFlaggedMapObjects(void);
