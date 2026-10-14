/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PlayerTempoMain FUN_037fe310
#define UpdatePlayerChannel FUN_037fe044
#define SNDi_Work SDK_data_03807ecc
#define SNDi_SharedWork SDK_data_03807ec8
#define SND_SeqMain FUN_037feeb4
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>
extern void PlayerTempoMain(SNDPlayer *player_p);
extern void UpdatePlayerChannel(SNDPlayer *player_p);
#pragma thumb off
void SND_SeqMain(BOOL doPeriodicProc)
{
    SNDPlayer *player_p;
    int playerNo;
    u32 playerStatus = 0;

    for (playerNo = 0; playerNo < SND_PLAYER_NUM; playerNo++) {
        player_p = &SNDi_Work.player[playerNo];

        if (!player_p->active_flag) {
            continue;
        }

        if (player_p->prepared_flag) {
            if (doPeriodicProc && !player_p->pause_flag) {
                PlayerTempoMain(player_p);
            }
            UpdatePlayerChannel(player_p);
        }

        if (player_p->active_flag) {
            playerStatus |= (1 << playerNo);
        }
    }

    if (SNDi_SharedWork != NULL) {
        SNDi_SharedWork->playerStatus = playerStatus;
    }
}
