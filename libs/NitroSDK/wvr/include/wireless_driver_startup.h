#pragma once

#include "types.h"

extern void (*wvrCallback)(u32, s32);
extern u32 wvrArg;
extern vu16 wvrVRam;
extern vu16 wvrLockId;

void WvrDummyAsyncCallback(u32 arg, s32 result);
void WvrReceiveCallback(u32 tag, u32 data);
s32 WVR_TerminateAsync(void (*callback)(u32, s32), u32 arg);
// vram is VRAM_BANK_C, VRAM_BANK_D or both; any other value returns 3.
s32 WVR_StartUpAsync(u32 vram, void (*callback)(u32, s32), u32 arg);

// Command words sent to the other processor in the high half of the word; the reply carries the command again and
// WvrReceiveCallback takes it with data & 0xffff0000 (the result is the low byte).
enum {
    WIRELESS_COMMAND_START_UP = 0x10000,
    WIRELESS_COMMAND_TERMINATE = 0x20000,
};
