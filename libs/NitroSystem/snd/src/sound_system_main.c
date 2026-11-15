#include "sound_system_main.h"
#include "snd_interface.h"
#include "snd_main.h"
#include "snd_command.h"
#include "sound_sleep.h"
#include "player.h"
#include "sound_capture_effect.h"
#include "sndarc_stream.h"
#include "pm.h"
#include "sound_archive_load.h"
#include "resource_mgr.h"

PMSleepCallbackInfo sPostSleepCallback;
PMSleepCallbackInfo sPreSleepCallback;
u32 sDriverInfoFirstFlag;
u32 sNnsSndInitialized;
s8 sCurDriverInfo;

// Sets up the sound driver, the sleep callbacks and the resource, capture and player state once.
void NNS_SndInit(void) {
    if (sNnsSndInitialized != 0) {
        return;
    }
    sNnsSndInitialized = 1;
    SND_Init();
    sPreSleepCallback.mCallback = BeginSleep;
    sPreSleepCallback.mArg = 0;
    sPostSleepCallback.mCallback = EndSleep;
    sPostSleepCallback.mArg = 0;
    PM_PrependPreSleepCallback(&sPreSleepCallback);
    PM_AppendPostSleepCallback(&sPostSleepCallback);
    NNSi_SndInitResourceMgr();
    NNSi_SndCaptureInit();
    NNSi_SndPlayerInit();
    sCurDriverInfo = -1;
    sDriverInfoFirstFlag = 1;
}

// Handles the driver replies, then runs the player and capture updates and sends the queued commands.
void NNS_SndMain(void) {
    while (SND_RecvCommandReply(0) != 0) {
    }
    NNSi_SndPlayerMain();
    NNSi_SndCaptureMain();
    NNSi_SndArcStrmMain();
    SND_FlushCommand(0);
}

// Sets the master volume.
void NNS_SndSetMasterVolume(int volume) {
    SND_SetMasterVolume(volume);
}

void NNS_SndSetMonoFlag(BOOL mono) {
    if (mono != 0) {
        SND_SetMasterPan(0x40);
        return;
    }
    SND_ResetMasterPan();
}
