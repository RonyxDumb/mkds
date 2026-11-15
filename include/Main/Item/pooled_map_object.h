#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/earthen_pipe_create.h" // ItemBox

typedef struct ItemFBox ItemFBox;

typedef struct ItemBox ItemBox;
typedef struct MtxFx43 MtxFx43;

void SetPooledMapObjectCallback(ItemBox *object, void (*callback)(ItemFBox *owner, MtxFx43 *out), ItemFBox *owner);

void SetPooledMapObjectFromItem(ItemBox *object, s32 alpha, Vec3 *scale);
void AdvancePooledMapObject(ItemBox *object);

void ParkPooledMapObject(ItemBox *pooledMapObject);
