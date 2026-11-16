#include "sound_system_main.h"
#include "sound_command_requests.h"
#include "sound_init_and_mutex.h"
#include "sound_command_queue.h"
#include "sound_sleep.h"
#include "sound_player_control.h"
#include "sound_capture_effect.h"
#include "sound_archive_stream.h"
#include "power_management_commands.h"
#include "sound_archive_load.h"
#include "sound_channel_alarm_lock.h"

PMSleepCallbackInfo sPostSleepCallback;
PMSleepCallbackInfo sPreSleepCallback;
u32 sDriverInfoFirstFlag;
u32 g_SoundInitialized;
s8 sCurDriverInfo;

// Sets up the sound driver, the sleep callbacks and the resource, capture and player state once.
void Sound_EnsureInitialized(void) {
    if (g_SoundInitialized != 0) {
        return;
    }
    g_SoundInitialized = 1;
    Sound_InitializeImpl();
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
    while (Sound_CommandReceiveAndReply(0) != 0) {
    }
    NNSi_SndPlayerMain();
    NNSi_SndCaptureMain();
    NNSi_SndArcStrmMain();
    Sound_FlushCommand(0);
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
