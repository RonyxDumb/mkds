/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CalcRelease FUN_037fc6dc
#define SND_SetExChannelRelease FUN_037fcc30
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"
extern u16 CalcRelease(int release);
#pragma thumb off
void SND_SetExChannelRelease(SNDExChannel *ch_p, int release)
{
    SDK_MINMAX_ASSERT(release, 0, 127);

    ch_p->release = CalcRelease(release);
}
