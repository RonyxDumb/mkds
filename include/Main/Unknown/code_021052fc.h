#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/earthen_pipe_create.h" // ItemBox

void SetPooledMapObjectFromItem(ItemBox *object, s32 alpha, Vec3 *scale);
void AdvancePooledMapObject(ItemBox *object);
