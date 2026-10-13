/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_LockMutex Sound_LockMutex
#define SNDi_UnlockMutex Sound_UnlockMutex
#include "SND_bank.h"
#include "OS_mutex.h"
#include "nitro/types.h"
#include "code32.h"

const struct SNDWaveData *SND_GetWaveDataAddress(const struct SNDWaveArc *waveArc, s32 index) {
    SNDi_LockMutex();
    u32 retval = waveArc->waveOffsets[index];
    if (retval != 0) {
        // < 0x2000000 aka, not a pointer to main RAM
        if (retval < 0x2000000)
            retval = (u32)&((u8 *)waveArc)[retval];
    } else {
        retval = 0;
    }
    SNDi_UnlockMutex();
    return (struct SNDWaveData *)retval;
}
