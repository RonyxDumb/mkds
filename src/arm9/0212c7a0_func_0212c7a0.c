/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sPlayer SDK_data_0217d89c
#define NNS_SndPlayerSetAllocatableChannel func_0212c7a0
#include <nnsys/snd/player.h>

#include <nitro/os.h>
#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/main.h>
extern NNSSndPlayer sPlayer[ NNS_SND_PLAYER_NUM ];
#pragma thumb off
void NNS_SndPlayerSetAllocatableChannel (int playerNo, u32 chBitFlag)
{
    NNS_MINMAX_ASSERT(playerNo, 0, NNS_SND_PLAYER_NO_MAX);
    NNS_MINMAX_ASSERT(chBitFlag, 0, 0xffff);

    sPlayer[ playerNo ].allocChBitFlag = chBitFlag;
}
