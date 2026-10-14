/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_SndArcLoadGroup Sound_LoadGroupImpl
#define NNS_SndArcLoadGroup Sound_LoadGroup
#include <nnsys/snd/sndarc_loader.h>

#include <nitro/types.h>

#include <nnsys/snd/seqdata.h>
#include <nnsys/snd/sndarc.h>

#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/heap.h>
extern NNSSndArcLoadResult NNSi_SndArcLoadGroup (int groupNo, NNSSndHeapHandle heap);
#pragma thumb off
BOOL NNS_SndArcLoadGroup (int groupNo, NNSSndHeapHandle heap)
{
    NNSSndArcLoadResult result;

    result = NNSi_SndArcLoadGroup(groupNo, heap);

    return result == NNS_SND_ARC_LOAD_SUCESS ? TRUE : FALSE;
}
