/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ForceStopStrm func_0212c824
#define NNS_SndStrmStop func_0212c918
#include <nnsys/snd/stream.h>

#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/resource_mgr.h>
extern void ForceStopStrm (NNSSndStrm * stream);
#pragma thumb off
void NNS_SndStrmStop (NNSSndStrm * stream)
{
    NNS_NULL_ASSERT(stream);

    if (!stream->activeFlag) return;

    ForceStopStrm(stream);
}
