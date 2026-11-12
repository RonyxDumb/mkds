#pragma once

#include "types.h"

typedef struct ItemFBox ItemFBox;

typedef struct ItemBox ItemBox;
typedef struct MtxFx43 MtxFx43;

void SetPooledMapObjectCallback(ItemBox *object, void (*callback)(ItemFBox *owner, MtxFx43 *out), ItemFBox *owner);
