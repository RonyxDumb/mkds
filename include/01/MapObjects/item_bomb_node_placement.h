#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx43
#include "model_draw_blend.h" // NNSG3dRS
#include "01/MapObjects/mission_run_map_object.h"
#include "01/MapObjects/hanachan_move_and_followers.h"

extern MtxFx43 gJgPreviousInverseMatrix;

extern MtxFx43 gJgInverseMatrix;

extern MtxFx43 gJgMatrix;

void StoreNodePositionAndPlaceItemBomb(NNSG3dRS *renderState);
void *StartItemBombWithParkedKuribo(void);
void *StartItemBombWithParkedItemBox(u16 forcedRow);
void IncrementEntryGroupIndex(MissionRunMapObject *mapObject, s32 groupSpan);
