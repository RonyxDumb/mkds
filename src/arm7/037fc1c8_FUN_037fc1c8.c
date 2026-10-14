/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_InitIntervalTimer FUN_037fc350
#define SND_ExChannelInit FUN_037fd31c
#define SND_SeqInit FUN_037fef54
#define SND_AlarmInit FUN_037ff564
#define SND_Enable FUN_037fba7c
#define SND_SetOutputSelector FUN_037fb924
#define SND_SetMasterVolume FUN_037fb95c
#define SND_StartIntervalTimer FUN_037fc2f8
#define SND_WaitForIntervalTimer FUN_037fc2b8
#define SND_UpdateExChannel FUN_037fd130
#define SND_CommandProc FUN_037ff908
#define SND_SeqMain FUN_037feeb4
#define SND_ExChannelMain FUN_037fce24
#define SND_UpdateSharedWork FUN_037ff2f4
#define SND_CalcRandom FUN_037fbf70
#define SndThread FUN_037fc1c8
#include <nitro/snd/common/main.h>

#include <nitro/os.h>
#include <nitro/snd/common/global.h>
#include <nitro/snd/common/exchannel.h>
#include <nitro/snd/common/seq.h>
#include <nitro/snd/common/alarm.h>
#include <nitro/snd/common/command.h>
#include <nitro/snd/common/util.h>
#include <nitro/snd/common/work.h>
extern void SND_InitIntervalTimer (void);
extern void SND_StartIntervalTimer (void);
extern OSMessage SND_WaitForIntervalTimer (void);
#pragma thumb off
void SndThread (void *)
    {
        SND_InitIntervalTimer();
        SND_ExChannelInit();
        SND_SeqInit();
        SND_AlarmInit();
        SND_Enable();
        SND_SetOutputSelector(SND_OUTPUT_MIXER,
                            SND_OUTPUT_MIXER, SND_CHANNEL_OUT_MIXER, SND_CHANNEL_OUT_MIXER);
        SND_SetMasterVolume(SND_MASTER_VOLUME_MAX);

        SND_StartIntervalTimer();

        while (1) {
            OSMessage message;
            BOOL doPeriodicProc = FALSE;

            message = SND_WaitForIntervalTimer();

            switch ((u32)message) {
            case SND_MESSAGE_PERIODIC:
                doPeriodicProc = TRUE;
                break;
            case SND_MESSAGE_WAKEUP_THREAD:
                break;
            }

            SND_UpdateExChannel();

            SND_CommandProc();

            SND_SeqMain(doPeriodicProc);
            SND_ExChannelMain(doPeriodicProc);

            SND_UpdateSharedWork();

            (void)SND_CalcRandom();
        }

        SND_Disable();
        SND_StopIntervalTimer();
    }
