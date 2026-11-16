#pragma once

#include "types.h"

typedef struct Unk0216c860 Unk0216c860;

u32 csfx_setWallOverride(u32 rowIndex, u32 columnIndex, Unk0216c860 *entries);
u32 csfx_setFloorOverride(u32 rowIndex, u32 columnIndex, void *entries);
