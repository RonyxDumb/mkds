/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_SetPlayerParam SDK_data_020208a4
#define SND_SetPlayerChannelPriority func_02020d68
#include "SND_interface.h"
#include "SND_command.h"
#include "nitro/types.h"
#include "code32.h"
extern void SNDi_SetPlayerParam(s32 player, u32 offset, u32 data, s32 size);
#pragma thumb off
void SND_SetPlayerChannelPriority(s32 player, s32 prio) {
    SNDi_SetPlayerParam(player, 4, (u32)prio, 1);
}
