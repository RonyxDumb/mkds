#pragma once

#include "types.h"
#include "03/Graphics/nce_oam.h"

void ReleaseSelectionObjectSlots(void);
void PlaceSelectionCorners(u32 left, u32 right, u32 top, u32 bottom);
void PlaceSelectionPair(u32 pairIndex, u32 leftX, u32 rightX, u32 yPos);
void ReleaseSelectionObjects(void);
void InitSelectionObjects(void);

extern const u8 gSelectionPairImages[8];
extern struct OamRange **gSelectionObjects;
