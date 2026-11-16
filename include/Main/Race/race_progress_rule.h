#pragma once

#include "types.h"

unsigned short GetLeadingKart(void);
unsigned int RaceProgressGetCurrentRuleKind(void);

BOOL IsRaceProgressKartRemoved(u32 kartIndex);
BOOL IsKartNonCpu(u32 kartIndex);

unsigned int RaceProgressGetCurrentKartCount(void);
