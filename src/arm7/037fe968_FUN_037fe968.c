/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FinishPlayer FUN_037fe230
#define SNDi_Work SDK_data_03807ecc
#define SND_InvalidateBank FUN_037fe968
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
void SND_InvalidateBank(const void *start, const void *end)
{
    for (int playerNo = 0; playerNo < SND_PLAYER_NUM; playerNo++) {
        SNDPlayer *player_p = &SNDi_Work.player[playerNo];

        if (!player_p->active_flag) {
            continue;
        }

        if (start <= (const void *)(player_p->bank) && (const void *)(player_p->bank) <= end) {
            FinishPlayer(player_p);
        }
    }
}
