#pragma once

#include "types.h"
#include "code_020091fc.h"
#include "os_thread.h"
#include "mb_data.h"
#include "code_0200fc8c.h"
#include "Main/Net/mp_link.h"
#include "code_0200c0d8.h"
#include "code_02142eac.h"

void QueueStateMessage(void);
void ReceivePortMessage(WirelessMessage *info);
void MPLinkCallback(s32 eventKind, void *eventInfo);
u32 StartConnectToEntry(u32 entryIndex);
void ScanConnectEndScanCallback(WirelessMessage *info);
