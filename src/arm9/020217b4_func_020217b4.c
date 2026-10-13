/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define DC_FlushRange Arm_FlushRange
#define SNDi_InitSharedWork func_020217b4
#include "SND_work.h"
#include "SND_alarm.h"
#include "SND_main.h"
#include "OS_cache.h"
#include "nitro/types.h"
#include "code32.h"

#pragma thumb off
void SNDi_InitSharedWork(struct SNDSharedWork *sw) {
    sw->playerStatus = 0;
    sw->channelStatus = 0;
    sw->captureStatus = 0;
    sw->finishedCommandTag = 0;

    for (s32 i = 0; i < SND_PLAYER_COUNT; i++) {
        sw->players[i].tickCounter = 0;
        for (s32 j = 0; j < 16; j++) {
            sw->players[i].localVars[j] = -1;
        }
    }

    for (s32 i = 0; i < 16; i++) {
        sw->globalVars[i] = -1;
    }

    DC_FlushRange(sw, sizeof(*sw));
}
