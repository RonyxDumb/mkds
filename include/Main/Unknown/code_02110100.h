#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectSound
#include "code_0212bcac.h"

void InitVolumeFade(void);
void StartKingTeresaAlphaSound(MapObjectSound *mapSound);
BOOL IsKingTeresaState0Or2Or5(void);
void UpdateKingTeresaSeqVolume(NNSSndSeqPlayer **handle);
u32 IsSndHandleSet(NNSSndSeqPlayer **handle);
