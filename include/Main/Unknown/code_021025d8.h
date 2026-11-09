#pragma once

#include "types.h"

typedef struct ItemTeresa ItemTeresa;

void ResetItemTeresa(ItemTeresa *teresa);
typedef struct ItemInUse ItemInUse;

void TeresaMarkItemInUseAsActiveItem(ItemInUse *itemInUse);
