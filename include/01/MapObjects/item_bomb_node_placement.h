#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_02010c84.h" // NNSG3dRS
#include "01/MapObjects/mission_run_map_object.h"
#include "01/MapObjects/hanachan_move_and_followers.h"

extern MtxFx43 gJgPreviousInverseMatrix;

extern MtxFx43 gJgInverseMatrix;

extern MtxFx43 gJgMatrix;

void StoreNodePositionAndPlaceItemBomb(NNSG3dRS *renderState);
void *StartItemBombWithParkedKuribo(void);
void *StartItemBombWithParkedItemBox(u16 forcedRow);
void IncrementEntryGroupIndex(MissionRunMapObject *mapObject, s32 groupSpan);
