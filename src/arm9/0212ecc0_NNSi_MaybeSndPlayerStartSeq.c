/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_SndArcGetSeqArcInfo Sound_GetSarcInfoEntry
#define NNS_SndArcGetFileAddress Sound_MaybeGetRawFilePointer
#define NNSi_SndSeqArcGetSeqInfo func_0212f788
#define StartSeqArc func_0212ea28
#define NNS_SndArcPlayerStartSeqArc NNSi_MaybeSndPlayerStartSeq
#include <nnsys/snd/sndarc_player.h>

#include <nnsys/misc.h>
#include <nnsys/snd/sndarc.h>
#include <nnsys/snd/player.h>
#include <nnsys/snd/sndarc_loader.h>
extern BOOL StartSeqArc (NNSSndHandle * handle, int playerNo, int bankNo, int playerPrio, const NNSSndSeqArcSeqInfo * sound, const NNSSndSeqArc * seqArc, int seqArcNo, int index);
#pragma thumb off
BOOL NNS_SndArcPlayerStartSeqArc (NNSSndHandle * handle, int seqArcNo, int index)
{
    const NNSSndArcSeqArcInfo * info;
    const NNSSndSeqArcSeqInfo * sound;
    const NNSSndSeqArc * seqArc;

    NNS_NULL_ASSERT(handle);

    info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (info == NULL) return FALSE;
    seqArc = (NNSSndSeqArc *)NNS_SndArcGetFileAddress(info->fileId);
    if (seqArc == NULL) return FALSE;
    sound = NNSi_SndSeqArcGetSeqInfo(seqArc, index);
    if (sound == NULL) return FALSE;

    return StartSeqArc(
        handle,
        sound->param.playerNo,
        sound->param.bankNo,
        sound->param.playerPrio,
        sound,
        seqArc,
        seqArcNo,
        index
        );
}
