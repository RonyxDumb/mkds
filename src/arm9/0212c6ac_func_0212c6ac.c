/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sSeqPlayer SDK_data_0217d45c
#define NNS_SndPlayerStopSeqAll func_0212c6ac
#include <nnsys/snd/player.h>

#include <nitro/os.h>
#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/main.h>
extern void NNSi_SndPlayerStopSeq (NNSSndSeqPlayer * seqPlayer, int fadeFrame);
extern NNSSndSeqPlayer sSeqPlayer[ SND_PLAYER_NUM ];
#pragma thumb off
void NNS_SndPlayerStopSeqAll (int fadeFrame)
{
    NNSSndSeqPlayer * seqPlayer;
    int i;

    for (i = 0; i < SND_PLAYER_NUM; i++) {
        seqPlayer = &sSeqPlayer[ i ];

        if (seqPlayer->status != NNS_SND_SEQ_PLAYER_STATUS_STOP) {
            NNSi_SndPlayerStopSeq(seqPlayer, fadeFrame);
        }
    }
}
