#pragma once

#include "types.h"
#include "multiboot_game_entry.h"
#include "thread_scheduler.h"
#include "mb_data.h"
#include "reset_interrupt_enable.h"
#include "Main/Net/mp_link.h"
#include "multiboot_data_pieces.h"
#include "wireless_power_mp.h"

void QueueStateMessage(void);
void ReceivePortMessage(WirelessMessage *info);
void MPLinkCallback(s32 eventKind, void *eventInfo);
u32 StartConnectToEntry(u32 entryIndex);
void ScanConnectEndScanCallback(WirelessMessage *info);
