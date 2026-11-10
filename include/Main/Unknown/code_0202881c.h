#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

unsigned int SelectKartGetPairHasPair(InputSlotPair *inputSlotPair);
void SetDataSharingSendByteInState8(u8 sendByte);
unsigned int GetConnectionState(void);
