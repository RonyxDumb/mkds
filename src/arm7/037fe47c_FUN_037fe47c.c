/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_SharedWork SDK_data_03807ec8
#define InitPlayer FUN_037fe47c
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>

#pragma thumb off
void InitPlayer(SNDPlayer *player_p, SNDBankData *bank_p)
{
    player_p->pause_flag = FALSE;

    player_p->bank = bank_p;

    player_p->tempo = SND_DEFAULT_TEMPO;
    player_p->tempo_ratio = 256;
    player_p->tempo_counter = SND_BASE_TEMPO;

    player_p->volume = 127;
    player_p->extFader = 0;

    player_p->prio = 64;

    for (int trackNo = 0; trackNo < SND_TRACK_NUM_PER_PLAYER; trackNo++) {
        player_p->tracks[trackNo] = SND_INVALID_TRACK_INDEX;
    }

    if (SNDi_SharedWork != NULL) {
        SNDi_SharedWork->player[player_p->myNo].tickCounter = 0;

        for (int varNo = 0; varNo < SND_PLAYER_VARIABLE_NUM; varNo++) {
            SNDi_SharedWork->player[player_p->myNo].variable[varNo] = SND_DEFAULT_VARIABLE;
        }
    }
}
