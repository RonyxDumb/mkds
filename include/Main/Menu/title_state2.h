#pragma once

#include "types.h"
#include "Main/Menu/data_02175628.h"

typedef struct LayoutEntryTable LayoutEntryTable;

unsigned int TitleGetCellLayoutCount(LayoutEntryTable *cellLayout);

u32 TitleSlideOutReturnArgumentWrapper(u32 value);

typedef struct SceneNumbers SceneNumbers;

void UpdateTitleMenuInput(SceneNumbers *sceneNumbers);

u32 TitleGetSlotPairY(u32 slotIndex);

unsigned int TitleGetPairY(InputSlotPair *pair);

u32 TitleGetSlotPairX(u32 slotIndex);

unsigned int TitleGetPairX(InputSlotPair *pair);
