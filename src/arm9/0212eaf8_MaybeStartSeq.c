/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_SndPlayerAllocSeqPlayer func_0212c0e0
#define NNSi_SndPlayerAllocHeap func_0212bfbc
#define NNSi_SndArcLoadBank Sound_GetSbnkPointer
#define NNSi_SndPlayerFreeSeqPlayer func_0212c0d4
#define NNSi_SndPlayerStartSeq func_0212c078
#define NNS_SndPlayerSetInitialVolume func_0212c668
#define NNS_SndPlayerSetChannelPriority func_0212c5c4
#define NNS_SndPlayerSetSeqNo func_0212c478
#define StartSeq MaybeStartSeq
#include <nnsys/snd/sndarc_player.h>

#include <nnsys/misc.h>
#include <nnsys/snd/sndarc.h>
#include <nnsys/snd/player.h>
#include <nnsys/snd/sndarc_loader.h>

#pragma thumb off
BOOL StartSeq (NNSSndHandle * handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo * info, int seqNo)
{
    NNSSndSeqPlayer * player;
    NNSSndHeapHandle heap;
    NNSSndSeqData * seq;
    SNDBankData * bank;
    NNSSndArcLoadResult result;

    NNS_NULL_ASSERT(handle);
    NNS_MINMAX_ASSERT(playerNo, 0, NNS_SND_PLAYER_NO_MAX);
    NNS_MINMAX_ASSERT(playerPrio, 0, NNS_SND_PLAYER_PRIO_MAX);
    NNS_NULL_ASSERT(info);

    player = NNSi_SndPlayerAllocSeqPlayer(handle, playerNo, playerPrio);
    if (player == NULL) return FALSE;

    heap = NNSi_SndPlayerAllocHeap(playerNo, player);

    result = NNSi_SndArcLoadBank(bankNo, NNS_SND_ARC_LOAD_BANK | NNS_SND_ARC_LOAD_WAVE, heap, FALSE, &bank);
    if (result != NNS_SND_ARC_LOAD_SUCESS) {
        NNSi_SndPlayerFreeSeqPlayer(player);
        return FALSE;
    }

    result = NNSi_SndArcLoadSeq(seqNo, NNS_SND_ARC_LOAD_SEQ, heap, FALSE, &seq);
    if (result != NNS_SND_ARC_LOAD_SUCESS) {
        NNSi_SndPlayerFreeSeqPlayer(player);
        return FALSE;
    }

    NNSi_SndPlayerStartSeq(
        player,
        (u8 *)seq + seq->baseOffset,
        0,
        bank
        );

    NNS_SndPlayerSetInitialVolume(handle, info->param.volume);
    NNS_SndPlayerSetChannelPriority(handle, info->param.channelPrio);
    NNS_SndPlayerSetSeqNo(handle, seqNo);

    return TRUE;
}
