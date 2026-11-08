#pragma once

#include "types.h"

typedef struct ItemFBox ItemFBox;

typedef struct ItemBox ItemBox;

void SetPooledMapObjectCallback(ItemBox *object, UnkFunc *callback, ItemFBox *owner);
