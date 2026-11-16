#pragma once

#include "types.h"
#include "power_management_commands.h" // PMSleepCallbackInfo

void NNS_SndSetMonoFlag(BOOL mono);

extern s8 sCurDriverInfo;
extern u32 sDriverInfoFirstFlag;
extern u32 g_SoundInitialized;
extern PMSleepCallbackInfo sPreSleepCallback;
extern PMSleepCallbackInfo sPostSleepCallback;

void NNS_SndSetMasterVolume(int volume);
void NNS_SndMain(void);
void Sound_EnsureInitialized(void);
