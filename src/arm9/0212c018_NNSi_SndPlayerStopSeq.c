/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ForceStopSeq func_0212be78
#define NNSi_SndFaderSet func_0212f834
#define SetPlayerPriority func_0212bcac
#include <nnsys/snd/player.h>

#include <nitro/os.h>
#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/main.h>
extern void ForceStopSeq (NNSSndSeqPlayer * seqPlayer);
extern void SetPlayerPriority (NNSSndSeqPlayer * seqPlayer, int priority);
#pragma thumb off
void NNSi_SndPlayerStopSeq (NNSSndSeqPlayer * seqPlayer, int fadeFrame)
{
    if (seqPlayer == NULL) return;
    if (seqPlayer->status == NNS_SND_SEQ_PLAYER_STATUS_STOP) return;

    if (fadeFrame == 0) {
        ForceStopSeq(seqPlayer);
        return;
    }

    NNSi_SndFaderSet(&seqPlayer->fader, 0, fadeFrame);
    SetPlayerPriority(seqPlayer, 0);

    seqPlayer->status = NNS_SND_SEQ_PLAYER_STATUS_FADEOUT;
}
