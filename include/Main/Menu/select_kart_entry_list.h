#pragma once

#include "types.h"
#include "Main/Menu/data_02174000.h"

typedef struct InputSlotPair InputSlotPair;

u32 SelectKartSlotHasPairOrLost(u32 slot);
u32 SelectKartHasPairOrLost(InputSlotPair *pair);
void MoveSelectKartPrev(void);
void MoveSelectKartNext(void);
void SetSelectKartPositionDigits(void);
void StartSelectKartEntryListKindIfUsed(s32 kind);

extern struct SelectKart *gSelectKart;
