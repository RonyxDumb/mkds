#pragma once

#include "types.h"
#include "multiboot_communication.h"
#include "multiboot_mode_constants.h"
#include "mb_data.h"
#include "wireless_link_control.h"

int MBi_SendMP(void *data, u32 size, u32 childMask);
s32 MBi_SetMPData(WirelessMessageCallback callback, void *data, s32 dataSize, u16 unusedValue, u16 childMask);
