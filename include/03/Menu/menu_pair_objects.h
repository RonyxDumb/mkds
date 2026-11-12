#pragma once

#include "types.h"
#include "03/code_021cdd28.h"

void AdvanceUploadMenuPairScreenMap(u32 task);
void LoadMenuPairScreenMap(u32 pathIndex);

extern const MenuPairObjectPosition gMenuPairObjectPositions[5];
extern const u8 gMenuPairObjectImageIds[3][5];
extern const u8 gMenuPairObjectPaletteIds[3][5];
extern char *gMenuPairScreenMapPaths[5];

extern struct MenuPairObjects *gMenuPairObjects;
extern void *gMenuPairScreenMap;
