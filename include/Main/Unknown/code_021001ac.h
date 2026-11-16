#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;
typedef struct ItemTeresa ItemTeresa;

// Row of the table behind data_0215a190.
typedef struct Unk0215a190 {
    /* 00 */ u8 field0[0xc];
} Unk0215a190;

extern Unk0215a190 data_0215a190[];

void ittrsa_21001AC(ItemTeresa *teresa, s32 c, NsbmdModel *model);
void sub_21003E8(ItemTeresa *teresa, u32 sel, s32 value);
void ittrsa_210045C(ItemTeresa *teresa);
void ittrsa_21004C4(void *cursor, ItemTeresa *teresa, void *toData);
void ittrsa_210050C(ItemTeresa *teresa);
void UpdateItemTeresaState6(ItemTeresa *teresa);
