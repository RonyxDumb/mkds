/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#include <nnsys/snd/main.h>

#include <nitro/spi.h>

#include <nnsys/misc.h>
#include <nnsys/snd/capture.h>
#include <nnsys/snd/player.h>
#include <nnsys/snd/sndarc_stream.h>
#include <nnsys/snd/resource_mgr.h>
#include <nnsys/snd/config.h>

static PMSleepCallbackInfo SDK_data_0217d420;
static PMSleepCallbackInfo SDK_data_0217d42c;

static SNDDriverInfo sDriverInfo[2] ATTRIBUTE_ALIGN(32);
static u32 sDriverInfoCommandTag;
static s8 SDK_data_0217d414;
static BOOL SDK_data_0217d418;

static void SDK_data_0212b9f8(void *);
static void SDK_data_0212b9ec(void *);

static const SNDDriverInfo * GetCurDriverInfo(void);

static NNS_SND_INLINE const SNDDriverInfo * GetCurDriverInfo (void)
{
    if (SDK_data_0217d414 < 0) return NULL;
    return &sDriverInfo[ SDK_data_0217d414 ];
}

void Sound_EnsureInitialized (void)
{
    {
        static BOOL SDK_data_0217d41c = FALSE;
        if (SDK_data_0217d41c) return;
        SDK_data_0217d41c = TRUE;
    }

    Sound_InitializeImpl();

    PM_SetSleepCallbackInfo(&SDK_data_0217d420, SDK_data_0212b9f8, NULL);
    PM_SetSleepCallbackInfo(&SDK_data_0217d42c, SDK_data_0212b9ec, NULL);

    func_0214f4ec(&SDK_data_0217d420);
    func_0214f4d4(&SDK_data_0217d42c);

    func_0212bb50();
    func_0212d0ec();
    func_0212c310();

    SDK_data_0217d414 = -1;
    SDK_data_0217d418 = TRUE;
}

void NNS_SndMain (void)
{
    while (SND_RecvCommandReply(SND_COMMAND_NOBLOCK) != NULL) {
    }

    NNSi_SndPlayerMain();
    NNSi_SndCaptureMain();
#ifndef SDK_SMALL_BUILD
    NNSi_SndArcStrmMain();
#endif

    (void)SND_FlushCommand(SND_COMMAND_NOBLOCK);
}

void NNS_SndSetMasterVolume (int volume)
{
    NNS_MINMAX_ASSERT(volume, 0, SND_MASTER_VOLUME_MAX);
    SND_SetMasterVolume(volume);
}

void NNS_SndSetMonoFlag (BOOL flag)
{
    if (flag) SND_SetMasterPan(SND_CHANNEL_PAN_CENTER);
    else SND_ResetMasterPan();
}

void NNS_SndStopSoundAll (void)
{
    u32 commandTag;

    NNS_SndPlayerStopSeqAll(0);
#ifndef SDK_SMALL_BUILD
    NNS_SndArcStrmStopAll(0);
#endif
    NNSi_SndCaptureStop();

    SNDi_SetSurroundDecay(0);
    SND_StopTimer(0xffff, 0xffff, 0xffff, 0);

    commandTag = SND_GetCurrentCommandTag();
    (void)SND_FlushCommand(SND_COMMAND_BLOCK);
    SND_WaitForCommandProc(commandTag);
}

void NNS_SndStopChannelAll (void)
{
    SND_StopUnlockedChannel(0xffff, 0);
}

BOOL NNS_SndUpdateDriverInfo (void)
{
    if (!SDK_data_0217d418) {
        while (SND_RecvCommandReply(SND_COMMAND_NOBLOCK) != 0) {
        }

        if (!SND_IsFinishedCommandTag(sDriverInfoCommandTag)) {
            return FALSE;
        }

        if (SDK_data_0217d414 < 0) SDK_data_0217d414 = 1;

        SND_ReadDriverInfo(&sDriverInfo[ SDK_data_0217d414 ]);
        sDriverInfoCommandTag = SND_GetCurrentCommandTag();

        if (SDK_data_0217d414 == 0) SDK_data_0217d414 = 1;
        else SDK_data_0217d414 = 0;

        DC_InvalidateRange(&sDriverInfo[ SDK_data_0217d414 ], sizeof(SNDDriverInfo));

        (void)SND_FlushCommand(SND_COMMAND_NOBLOCK);

        return TRUE;
    } else {
        SND_ReadDriverInfo(&sDriverInfo[0]);
        sDriverInfoCommandTag = SND_GetCurrentCommandTag();
        SDK_data_0217d418 = FALSE;
        return FALSE;
    }
}

BOOL NNS_SndReadDriverChannelInfo (int chNo, SNDChannelInfo * info)
{
    const SNDDriverInfo * driverInfo;

    NNS_NULL_ASSERT(info);

    driverInfo = GetCurDriverInfo();
    if (driverInfo == 0) return FALSE;

    return SND_ReadChannelInfo(driverInfo, chNo, info);
}

BOOL NNSi_SndReadDriverPlayerInfo (int playerNo, SNDPlayerInfo * info)
{
    const SNDDriverInfo * driverInfo;

    NNS_NULL_ASSERT(info);

    driverInfo = GetCurDriverInfo();
    if (driverInfo == 0) return FALSE;

    return SND_ReadPlayerInfo(driverInfo, playerNo, info);
}

BOOL NNSi_SndReadDriverTrackInfo (int playerNo, int trackNo, SNDTrackInfo * info)
{
    const SNDDriverInfo * driverInfo;

    NNS_NULL_ASSERT(info);

    driverInfo = GetCurDriverInfo();
    if (driverInfo == 0) return FALSE;

    return SND_ReadTrackInfo(driverInfo, playerNo, trackNo, info);
}

static void SDK_data_0212b9f8 (void *)
{
    u32 commandTag;

    NNSi_SndCaptureBeginSleep();

    SND_StopTimer(0, 0, 0, 0);

    commandTag = SND_GetCurrentCommandTag();
    (void)SND_FlushCommand(SND_COMMAND_BLOCK);
    SND_WaitForCommandProc(commandTag);
}

static void SDK_data_0212b9ec (void *)
{
    NNSi_SndCaptureEndSleep();
}
