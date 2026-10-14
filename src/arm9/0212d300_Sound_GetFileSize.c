/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sCurrent SDK_data_0217dec4
#define NNS_SndArcGetFileSize Sound_GetFileSize
#include <nnsys/snd/sndarc.h>
#include <nnsys/snd/config.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
#include <nnsys/snd/player.h>
extern NNSSndArc * sCurrent;
#pragma thumb off
u32 NNS_SndArcGetFileSize (u32 fileId)
{
    NNSSndArc * arc = sCurrent;
    NNS_NULL_ASSERT(arc);
    NNS_NULL_ASSERT(arc->fat);

    if (fileId >= arc->fat->count) return 0;
    return arc->fat->files[ fileId ].size;
}
