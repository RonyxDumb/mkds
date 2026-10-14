/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define StartTrack FUN_037fe52c
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>

#pragma thumb off
void StartTrack(SNDTrack *track_p, const void *seqBase, u32 seqOffset)
{
    track_p->base = (const u8 *)seqBase;
    track_p->cur = track_p->base + seqOffset;
}
