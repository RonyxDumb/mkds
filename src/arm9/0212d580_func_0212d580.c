/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_SndArcGetSeqArcInfo Sound_GetSarcInfoEntry
#define NNS_SndArcGetFileAddress Sound_MaybeGetRawFilePointer
#define NNSi_SndSeqArcGetSeqInfo func_0212f788
#define NNS_SndArcGetSeqArcParam func_0212d580
#include <nnsys/snd/sndarc.h>
#include <nnsys/snd/config.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
#include <nnsys/snd/player.h>
extern const NNSSndArcSeqArcInfo * NNS_SndArcGetSeqArcInfo (int seqArcNo);
extern void * NNS_SndArcGetFileAddress (u32 fileId);
#pragma thumb off
const NNSSndSeqParam * NNS_SndArcGetSeqArcParam (int seqArcNo, int index)
{
    const NNSSndArcSeqArcInfo * info;
    const NNSSndSeqArc * seqArc;
    const NNSSndSeqArcSeqInfo * sound;

    info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (info == NULL) return NULL;

    seqArc = (const NNSSndSeqArc *)NNS_SndArcGetFileAddress(info->fileId);
    if (seqArc == NULL) return NULL;

    sound = NNSi_SndSeqArcGetSeqInfo(seqArc, index);
    if (sound == NULL) return NULL;

    return &sound->param;
}
