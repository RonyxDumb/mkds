/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_SharedWork SDK_data_03807ec8
#define GetVariablePtr FUN_037fd3c0
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>

#pragma thumb off
vs16 *GetVariablePtr(SNDPlayer *player_p, int varNo)
{
    SDK_MINMAX_ASSERT(varNo, 0, SND_PLAYER_VARIABLE_NUM + SND_GLOBAL_VARIABLE_NUM);
    SDK_WARNING(SNDi_SharedWork != NULL, "SND: Cannot use sequence variable because shared work don't set");

    if (SNDi_SharedWork == NULL) {
        return NULL;
    }

    if (varNo < SND_PLAYER_VARIABLE_NUM) {
        return &SNDi_SharedWork->player[player_p->myNo].variable[varNo];
    } else {
        return &SNDi_SharedWork->globalVariable[varNo - SND_PLAYER_VARIABLE_NUM];
    }

    return NULL;
}
