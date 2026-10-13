/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_LockMutex Sound_LockMutex
#define DC_StoreRange DC_SomeClean
#define SNDi_UnlockMutex Sound_UnlockMutex
#define SND_DestroyBank func_02021c34
#include "SND_bank.h"
#include "OS_mutex.h"
#include "nitro/types.h"
#include "code32.h"

void SND_DestroyBank(struct SNDBankData *bankData) {
    SNDi_LockMutex();

    for (s32 i = 0; i < SND_BANK_MAX_WAVEARC; i++) {
        struct SNDWaveArcLink *curWaveArcLink = &bankData->waveArcLinks[i];
        struct SNDWaveArc *curWaveArc = bankData->waveArcLinks[i].waveArc;

        if (curWaveArc == NULL)
            continue;

        if (curWaveArcLink == curWaveArc->waveArcLLHead) {
            curWaveArc->waveArcLLHead = bankData->waveArcLinks[i].waveArcLLnext;
            DC_StoreRange(curWaveArc, sizeof(*curWaveArc));
        } else {
            struct SNDWaveArcLink *cur;
            for (cur = curWaveArc->waveArcLLHead; cur != NULL; cur = cur->waveArcLLnext) {
                if (&bankData->waveArcLinks[i] == cur->waveArcLLnext)
                    break;
            }
            cur->waveArcLLnext = bankData->waveArcLinks[i].waveArcLLnext;
            DC_StoreRange(cur, sizeof(*cur));
        }
    }

    SNDi_UnlockMutex();
}
