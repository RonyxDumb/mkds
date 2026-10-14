/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_SndArcGetGroupInfo Sound_GetGroupInfoEntry
#define NNSi_SndArcLoadSeqArc Sound_GetSarcPointer
#define NNSi_SndArcLoadBank Sound_GetSbnkPointer
#define NNSi_SndArcLoadWaveArc Sound_GetSwarPointer
#define NNSi_SndArcLoadGroup Sound_LoadGroupImpl
#include <nnsys/snd/sndarc_loader.h>

#include <nitro/types.h>

#include <nnsys/snd/seqdata.h>
#include <nnsys/snd/sndarc.h>

#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/heap.h>
extern NNSSndArcLoadResult NNSi_SndArcLoadSeq (int seqNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct NNSSndSeqData ** pData);
extern NNSSndArcLoadResult NNSi_SndArcLoadSeqArc (int seqArcNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct NNSSndSeqArc ** pData);
extern NNSSndArcLoadResult NNSi_SndArcLoadBank (int bankNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDBankData ** pData);
extern NNSSndArcLoadResult NNSi_SndArcLoadWaveArc (int waveArcNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDWaveArc ** pData);
#pragma thumb off
NNSSndArcLoadResult NNSi_SndArcLoadGroup (int groupNo, NNSSndHeapHandle heap)
{
    const NNSSndArcGroupInfo * info;
    const NNSSndArcGroupItem * item;
    NNSSndArcLoadResult result;
    int itemNo;

    info = NNS_SndArcGetGroupInfo(groupNo);
    if (info == NULL) return NNS_SND_ARC_LOAD_ERROR_INVALID_GROUP_NO;

    for (itemNo = 0; itemNo < info->count; itemNo++) {
        item = &info->item[ itemNo ];

        switch (item->type) {
        case NNS_SNDARC_SNDTYPE_SEQ:
            result = NNSi_SndArcLoadSeq((int)(item->index), item->loadFlag, heap, TRUE, NULL);
            if (result != NNS_SND_ARC_LOAD_SUCESS) return result;
            break;
        case NNS_SNDARC_SNDTYPE_SEQARC:
            result = NNSi_SndArcLoadSeqArc((int)(item->index), item->loadFlag, heap, TRUE, NULL);
            if (result != NNS_SND_ARC_LOAD_SUCESS) return result;
            break;
        case NNS_SNDARC_SNDTYPE_BANK:
            result = NNSi_SndArcLoadBank((int)(item->index), item->loadFlag, heap, TRUE, NULL);
            if (result != NNS_SND_ARC_LOAD_SUCESS) return result;
            break;
        case NNS_SNDARC_SNDTYPE_WAVEARC:
            result = NNSi_SndArcLoadWaveArc((int)(item->index), item->loadFlag, heap, TRUE, NULL);
            if (result != NNS_SND_ARC_LOAD_SUCESS) return result;
            break;
        default:
            NNS_ASSERT(FALSE);
            break;
        }
    }

    return NNS_SND_ARC_LOAD_SUCESS;
}
