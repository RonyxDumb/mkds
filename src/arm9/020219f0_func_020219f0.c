/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_GetNextInstData func_020219f0
#include "SND_bank.h"
#include "OS_mutex.h"
#include "nitro/types.h"
#include "code32.h"

BOOL SND_GetNextInstData(const struct SNDBankData *bankData, struct SNDInstData *instData, struct SNDInstPos *instPos) {
    while (instPos->program < bankData->instCount) {
        struct SNDDrumSet *drums;
        struct SNDKeySplit *keySplit;

        u32 instOffset = bankData->instOffsets[instPos->program];
        instData->type = SND_INST_OFFSET_TYPE(instOffset);

        switch (instData->type) {
        case SND_INST_PCM:
        case SND_INST_PSG:
        case SND_INST_NOISE:
        case SND_INST_DIRECTPCM:
        case SND_INST_DUMMY:
            instData->param = *SND_INST_OFFSET_NORMAL(bankData, instOffset);
            instPos->program++;
            return TRUE;
        case SND_INST_DRUM_TABLE:
            drums = SND_INST_OFFSET_DRUMS(bankData, instOffset);
            // silly programming 101: put a loop in a place that never loops
            for (; instPos->index < drums->maxKey - drums->minKey + 1;) {
                *instData = drums->instruments[instPos->index];
                instPos->index++;
                return TRUE;
            }
            break;
        case SND_INST_KEY_SPLIT:
            keySplit = SND_INST_OFFSET_KEYSPL(bankData, instOffset);
            for (; instPos->index < SND_INST_MAX_KEYSPLIT;) {
                if (keySplit->key[instPos->index] == 0)
                    break;
                *instData = keySplit->instruments[instPos->index];
                instPos->index++;
                return TRUE;
            }
            break;
        }

        instPos->program++;
        instPos->index = 0;
    }
    return FALSE;
}
