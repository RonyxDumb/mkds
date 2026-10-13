/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_LockMutex Sound_LockMutex
#define SNDi_UnlockMutex Sound_UnlockMutex
#define DC_StoreRange DC_SomeClean
#define SND_AssignWaveArc func_02021cd4
#include "SND_bank.h"
#include "OS_mutex.h"
#include "nitro/types.h"
#include "code32.h"

void SND_AssignWaveArc(struct SNDBankData *bankData, s32 index, struct SNDWaveArc *waveArc) {
    SNDi_LockMutex();
    struct SNDWaveArc *selectedWaveArc = bankData->waveArcLinks[index].waveArc;
    if (selectedWaveArc != NULL) {
        if (waveArc == selectedWaveArc) {
            SNDi_UnlockMutex();
            return;
        }

        if (&bankData->waveArcLinks[index] == selectedWaveArc->waveArcLLHead) {
            selectedWaveArc->waveArcLLHead = bankData->waveArcLinks[index].waveArcLLnext;
            DC_StoreRange(bankData->waveArcLinks[index].waveArc, sizeof(struct SNDWaveArc));
        } else {
            struct SNDWaveArcLink *cur;
            for (cur = selectedWaveArc->waveArcLLHead; cur != NULL; cur = cur->waveArcLLnext) {
                if (&bankData->waveArcLinks[index] == cur->waveArcLLnext)
                    break;
            }
            cur->waveArcLLnext = bankData->waveArcLinks[index].waveArcLLnext;
            DC_StoreRange(cur, sizeof(*cur));
        }
    }
    struct SNDWaveArcLink *oldHead = waveArc->waveArcLLHead;
    waveArc->waveArcLLHead = &bankData->waveArcLinks[index];
    bankData->waveArcLinks[index].waveArcLLnext = oldHead;
    bankData->waveArcLinks[index].waveArc = waveArc;
    // BUG: Shouldn't the mutex unlock be after writing to cache?
    SNDi_UnlockMutex();
    DC_StoreRange(bankData, sizeof(*bankData));
    DC_StoreRange(waveArc, sizeof(*waveArc));
}
