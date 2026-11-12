#pragma once

#include "types.h"
#include "code_0212d214.h"

u16 SND_CalcChannelVolume(s32 dB);
void *SND_GetWaveDataAddress(SNDWaveArc *waveArc, u32 index);

extern const u8 VolumeTable[724];
