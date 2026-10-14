/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sCurrent SDK_data_0217dec4
#define NNS_SndArcGetFileAddress Sound_MaybeGetRawFilePointer
#include <nnsys/snd/sndarc.h>
#include <nnsys/snd/config.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
#include <nnsys/snd/player.h>
extern NNSSndArc * sCurrent;
#pragma thumb off
void * NNS_SndArcGetFileAddress (u32 fileId)
{
    NNSSndArc * arc = sCurrent;

    NNS_NULL_ASSERT(arc);
    NNS_NULL_ASSERT(arc->fat);

    if (fileId >= arc->fat->count) return NULL;
    return arc->fat->files[ fileId ].mem;
}
