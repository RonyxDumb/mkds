/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_ReceiveMessage FUN_037f97b4
#define sndMesgQueue SDK_data_038079b4
#define SND_WaitForIntervalTimer FUN_037fc2b8
#include <nitro/snd/common/main.h>

#include <nitro/os.h>
#include <nitro/snd/common/global.h>
#include <nitro/snd/common/exchannel.h>
#include <nitro/snd/common/seq.h>
#include <nitro/snd/common/alarm.h>
#include <nitro/snd/common/command.h>
#include <nitro/snd/common/util.h>
#include <nitro/snd/common/work.h>
extern OSMessageQueue sndMesgQueue;
#pragma thumb off
    OSMessage SND_WaitForIntervalTimer (void)
    {
        OSMessage message;

        (void)OS_ReceiveMessage(&sndMesgQueue, &message, OS_MESSAGE_BLOCK);
        return message;
    }
