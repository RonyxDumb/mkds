#pragma once

#include "types.h"

extern void (*wvrCallback)(u32, s32);
extern u32 wvrArg;
extern vu16 wvrVRam;
extern vu16 wvrLockId;

void WvrDummyAsyncCallback(u32 arg, s32 result);
void WvrReceiveCallback(u32 tag, u32 data);
s32 WVR_TerminateAsync(void (*callback)(u32, s32), u32 arg);
s32 WVR_StartUpAsync(u32 vram, void (*callback)(u32, s32), u32 arg);
