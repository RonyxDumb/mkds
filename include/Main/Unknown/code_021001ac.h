#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;
typedef struct ItemTeresa ItemTeresa;

// Row of the table behind gItemTeresaItemOffsets.
typedef struct Unk0215a190 {
    /* 00 */ u8 mUnk_00[0xc];
} Unk0215a190;

extern Unk0215a190 gItemTeresaItemOffsets[];

void DrawItemTeresa(ItemTeresa *teresa, s32 unusedValue, NsbmdModel *model);
void SetItemTeresaFromPacket(ItemTeresa *teresa, u32 sel, s32 value);
void InitItemTeresaFromData(ItemTeresa *teresa);
void CopyItemTeresaData(void *cursor, ItemTeresa *teresa, void *toData);
void ResetItemTeresaOwnerActiveItem(ItemTeresa *teresa);
void UpdateItemTeresaState6(ItemTeresa *teresa);
