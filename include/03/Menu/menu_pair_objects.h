#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "03/Menu/menu_pair_objects_slide_out.h"

void AdvanceUploadMenuPairScreenMap(TaskEntry *task, void *arg);
void LoadMenuPairScreenMap(u32 pathIndex);

extern const MenuPairObjectPosition gMenuPairObjectPositions[5];
extern const u8 gMenuPairObjectImageIds[3][5];
extern const u8 gMenuPairObjectPaletteIds[3][5];
extern char *gMenuPairScreenMapPaths[5];

extern struct MenuPairObjects *gMenuPairObjects;
extern void *gMenuPairScreenMap;
