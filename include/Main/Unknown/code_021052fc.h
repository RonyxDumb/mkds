#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020de588.h" // ItemBox

void SetPooledMapObjectFromItem(ItemBox *object, s32 alpha, Vec3 *scale);
void AdvancePooledMapObject(ItemBox *object);
