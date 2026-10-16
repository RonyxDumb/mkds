#define SVC_SoundBiasSet thunk_FUN_038011ca
#define OS_SpinWait FUN_037fafd4
#define SND_Enable FUN_037fba7c
#define SND_EndSleep FUN_037fb96c
/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#include "SND_global.h"

#include "SND_channel.h"
#include "SND_work.h"

#include "OS_system.h"
#include "PM.h"
#include "registers.h"
#include "syscall.h"
#include "code32.h"
#undef SVC_SoundBiasSet
#undef OS_SpinWait
#undef SND_Enable
#undef SND_EndSleep

void FUN_037fba7c(void)
{
    reg_SOUNDCNT_MIX |= 0x80;
}

void SND_Disable(void)
{
    reg_SOUNDCNT_MIX &= ~0x80;
}

void SND_Shutdown(void)
{
    SND_Disable();

    for (int i = 0; i < SND_CHANNEL_COUNT; i++)
    {
        SND_StopChannel(i, 1);
    }

    reg_SNDCAPxCNT(0) = 0;
    reg_SNDCAPxCNT(1) = 0;
}

void SND_BeginSleep(void)
{
    SND_Disable();
    SVC_SoundBiasReset(0x80);
    FUN_037fafd4(0x40000);
    PMi_ResetControl(1);
    reg_POWCNT2 &= ~1;
}

void FUN_037fb96c(void)
{
    reg_POWCNT2 |= 1; // enable speakers
    FUN_038027a8(1);
    thunk_FUN_038011ca(0x100);
    FUN_037fafd4(0x7AB80); // what does this wait for and how long does it wait?
    FUN_037fba7c();
}

void SND_SetMasterVolume(int vol)
{
    reg_SOUNDCNT_VOL = (u8)vol;
}

void SND_SetOutputSelector(
    int leftOutputFrom, int rightOutputFrom, int outputCh1ToMixer, int outputCh3ToMixer)
{
    int masterEnable = (reg_SOUNDCNT_MIX & 0x80) ? 1 : 0;
    reg_SOUNDCNT_MIX = (u8)((masterEnable << 7) | (outputCh3ToMixer << 5) |
                            (outputCh1ToMixer << 4) | (rightOutputFrom << 2) | (leftOutputFrom));
}
