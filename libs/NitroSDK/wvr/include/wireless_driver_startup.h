#pragma once

#include "types.h"

extern void (*wvrCallback)(u32, s32);
extern u32 wvrArg;
extern vu16 wvrVRam;
extern vu16 wvrLockId;

void WvrDummyAsyncCallback(u32 arg, s32 result);
void Fifo15Handler(u32 tag, u32 data);
s32 SetWvrFifoShit(void (*callback)(u32, s32), u32 arg);
s32 WVR_StartUpAsync(u32 vram, void (*callback)(u32, s32), u32 arg);

// Bank masks of the vram argument of WVR_StartUpAsync; each bank's control register is written in the switch.
enum {
    WIRELESS_VRAM_BANK_C = 4,
    WIRELESS_VRAM_BANK_D = 8,
    WIRELESS_VRAM_BANK_C_AND_D = 12,
};

// Words sent to the other processor (the high half is the command, Fifo15Handler masks it out of the reply).
enum {
    WIRELESS_DRIVER_COMMAND_START_UP = 0x10000,
    WIRELESS_DRIVER_COMMAND_TERMINATE = 0x20000,
};
