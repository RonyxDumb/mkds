/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_Work SDK_data_03807ecc
#define SND_StartPreparedSeq FUN_037fed40
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>

#pragma thumb off
void SND_StartPreparedSeq(int playerNo)
{
    SDK_MINMAX_ASSERT(playerNo, SND_PLAYER_MIN, SND_PLAYER_MAX);

    SNDPlayer *player_p = &SNDi_Work.player[playerNo];

    player_p->prepared_flag = TRUE;
}
