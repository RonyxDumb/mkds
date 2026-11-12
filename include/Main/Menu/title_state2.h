#pragma once

#include "types.h"
#include "Main/Menu/data_02175628.h"

typedef struct LayoutEntryTable LayoutEntryTable;

unsigned int TitleGetCellLayoutCount(LayoutEntryTable *cellLayout);

u32 TitleState3ReturnArgumentWrapper(u32 value);

typedef struct SceneNumbers SceneNumbers;

void UpdateTitleState2(SceneNumbers *sceneNumbers);

u32 TitleGetSlotPairY(u32 slotIndex);

unsigned int TitleGetPairY(InputSlotPair *pair);

u32 TitleGetSlotPairX(u32 slotIndex);

unsigned int TitleGetPairX(InputSlotPair *pair);
