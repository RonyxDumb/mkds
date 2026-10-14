/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define StartSeq MaybeStartSeq
#define NNS_SndArcPlayerStartSeq func_0212ed58
#include <nnsys/snd/sndarc_player.h>

#include <nnsys/misc.h>
#include <nnsys/snd/sndarc.h>
#include <nnsys/snd/player.h>
#include <nnsys/snd/sndarc_loader.h>
extern BOOL StartSeq (NNSSndHandle * handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo * info, int seqNo);
#pragma thumb off
BOOL NNS_SndArcPlayerStartSeq (NNSSndHandle * handle, int seqNo)
{
    const NNSSndArcSeqInfo * info;

    NNS_NULL_ASSERT(handle);

    info = NNS_SndArcGetSeqInfo(seqNo);
    if (info == NULL) return FALSE;

    return StartSeq(
        handle,
        info->param.playerNo,
        info->param.bankNo,
        info->param.playerPrio,
        info,
        seqNo
        );
}
