/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define DC_InvalidateRange DC_InvalidateRangeNoClean
#define SNDi_SharedWork SDK_data_02174e00
#define SND_GetPlayerLocalVariable func_02021868
#include <nitro/snd/common/work.h>
extern SNDSharedWork * SNDi_SharedWork;
#pragma thumb off
s16 SND_GetPlayerLocalVariable (int playerNo, int varNo)
{
    SDK_NULL_ASSERT(SNDi_SharedWork);
    SDK_MINMAX_ASSERT(playerNo, SND_PLAYER_MIN, SND_PLAYER_MAX);
    SDK_MINMAX_ASSERT(varNo, 0, SND_PLAYER_VARIABLE_NUM - 1);

#ifdef SDK_ARM9
    DC_InvalidateRange((void *)&SNDi_SharedWork->player[playerNo].variable[varNo],
                       sizeof(SNDi_SharedWork->player[playerNo].variable[varNo]));
#endif

    return SNDi_SharedWork->player[playerNo].variable[varNo];
}
