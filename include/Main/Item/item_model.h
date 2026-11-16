#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;

NsbmdModel *MaybeGetItemByIndex(u32 kind);

typedef struct ItemObject ItemObject;

void DrawItemModelAtObjectPos(ItemObject *item, NsbmdModel *model);
