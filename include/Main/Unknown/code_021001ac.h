#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;
typedef struct ItemTeresa ItemTeresa;

extern Vec3 gItemTeresaItemOffsets[];

void DrawItemTeresa(ItemTeresa *teresa, s32 unusedValue, NsbmdModel *model);
void SetItemTeresaFromPacket(ItemTeresa *teresa, u32 sel, s32 value);
void InitItemTeresaFromData(ItemTeresa *teresa);
void CopyItemTeresaData(void *cursor, ItemTeresa *teresa, void *toData);
void ResetItemTeresaOwnerActiveItem(ItemTeresa *teresa);
void UpdateItemTeresaState6(ItemTeresa *teresa);
