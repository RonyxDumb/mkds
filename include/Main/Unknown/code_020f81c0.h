#pragma once

#include "types.h"

typedef struct KartItems KartItems;

void StartGessoBlockTimer(s32 isRaceStart);
void AdvanceItemBlockTimers(void);
void FinishItemSlotAndStopSound(KartItems *slot);
