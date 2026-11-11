#include "code_020219b0.h"
#include "code_0200eddc.h"
#include "snd_main.h"

// Stores address as entry index of the wave data table of waveArc and writes that word back to memory.
void SND_SetWaveDataAddress(SNDWaveArc *waveArc, u32 index, void *address) {
    SNDi_LockMutex();
    waveArc->mWaveOffset[index] = (u32) address;
    DC_StoreRange(&waveArc->mWaveOffset[index], 4);
    SNDi_UnlockMutex();
}
