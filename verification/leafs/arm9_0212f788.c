/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_SndSeqArcGetSeqInfo func_0212f788
#include <nnsys/snd/seqdata.h>
    #include <nnsys/misc.h>

#pragma thumb off
const NNSSndSeqArcSeqInfo * NNSi_SndSeqArcGetSeqInfo (const NNSSndSeqArc * seqArc, int index)
{
    NNS_NULL_ASSERT(seqArc);

    if (index < 0) return NULL;
    if (index >= seqArc->count) return NULL;
    if (seqArc->info[ index ].offset == NNS_SND_SEQ_ARC_INVALID_OFFSET) return NULL;

    return &seqArc->info[ index ];
}
