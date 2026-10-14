/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_SndArcLoadBank Sound_GetSbnkPointer
#define NNS_SndArcLoadBankEx Sound_LoadSbnkWithFlags
#include <nnsys/snd/sndarc_loader.h>

#include <nitro/types.h>

#include <nnsys/snd/seqdata.h>
#include <nnsys/snd/sndarc.h>

#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/heap.h>
extern NNSSndArcLoadResult NNSi_SndArcLoadBank (int bankNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDBankData ** pData);
#pragma thumb off
BOOL NNS_SndArcLoadBankEx (int bankNo, u32 loadFlag, NNSSndHeapHandle heap)
{
    NNSSndArcLoadResult result;

    result = NNSi_SndArcLoadBank(bankNo, loadFlag, heap, TRUE, NULL);

    return result == NNS_SND_ARC_LOAD_SUCESS ? TRUE : FALSE;
}
