#pragma once

#include "types.h"
#include "sound_archive_load.h"

u16 SND_CalcChannelVolume(s32 dB);
void *SND_GetWaveDataAddress(SNDWaveArc *waveArc, u32 index);

extern const u8 VolumeTable[724];

// Objects whose layout isn't known yet.
extern const s16 gVolumeDecibelTable[128];
