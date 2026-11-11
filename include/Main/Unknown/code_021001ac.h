#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;
typedef struct ItemTeresa ItemTeresa;

// Row of the table behind gItemTeresaItemOffsets.
typedef struct ItemTeresaOffset {
    /* 00 */ u8 mUnk_00[0xc];
} ItemTeresaOffset;

extern ItemTeresaOffset gItemTeresaItemOffsets[];

void DrawItemTeresa(ItemTeresa *teresa, s32 unusedValue, NsbmdModel *model);
void SetItemTeresaFromPacket(ItemTeresa *teresa, u32 sel, s32 value);
void InitItemTeresaFromData(ItemTeresa *teresa);
void CopyItemTeresaData(void *cursor, ItemTeresa *teresa, void *toData);
void ResetItemTeresaOwnerActiveItem(ItemTeresa *teresa);
void UpdateItemTeresaState6(ItemTeresa *teresa);
