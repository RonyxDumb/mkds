/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FinishPlayer FUN_037fe230
#define SNDi_Work SDK_data_03807ecc
#define SNDi_SharedWork SDK_data_03807ec8
#define SND_StopSeq FUN_037fecc8
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>
extern void FinishPlayer(SNDPlayer *player_p);
#pragma thumb off
void SND_StopSeq(int playerNo)
{
    SDK_MINMAX_ASSERT(playerNo, SND_PLAYER_MIN, SND_PLAYER_MAX);

    SNDPlayer *player_p = &SNDi_Work.player[playerNo];

    if (player_p->active_flag) {
        FinishPlayer(player_p);

        if (SNDi_SharedWork != NULL) {
            SNDi_SharedWork->playerStatus &= ~(1 << playerNo);
        }
    }
}
