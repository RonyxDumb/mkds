#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/MapObjects/attractor.h" // MapObjectSound
#include "player.h"

void InitVolumeFade(void);
void StartKingTeresaAlphaSound(MapObjectSound *mapSound);
BOOL IsKingTeresaState0Or2Or5(void);
void UpdateKingTeresaSeqVolume(NNSSndSeqPlayer **handle);
u32 IsSndHandleSet(NNSSndSeqPlayer **handle);
