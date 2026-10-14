/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_LockMutex Sound_LockMutex
#define DC_StoreRange DC_SomeClean
#define SNDi_UnlockMutex Sound_UnlockMutex
#define SND_DestroyWaveArc SND_func_0042
#include "SND_bank.h"
#include "OS_mutex.h"
#include "nitro/types.h"
#include "code32.h"

void SND_DestroyWaveArc(struct SNDWaveArc *waveArc) {
    SNDi_LockMutex();
    struct SNDWaveArcLink *cur = waveArc->waveArcLLHead;

    while (cur != NULL) {
        struct SNDWaveArcLink *newCur = cur->waveArcLLnext;
        cur->waveArc = NULL;
        cur->waveArcLLnext = NULL;
        DC_StoreRange(cur, sizeof(*cur));
        cur = newCur;
    }

    SNDi_UnlockMutex();
}
