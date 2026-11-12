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
void ReceivePortMessage(Unk021425e8 *info);
void MPLinkCallback(s32 eventKind, Unk021425e8 *info);
u32 StartConnectToEntry(u32 entryIndex);
void ScanConnectEndScanCallback(Unk021425e8 *info);
