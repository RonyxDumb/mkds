#pragma once

#include "types.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_02007000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_020071b4.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/code_02009928.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02142eac.h"
#include "code_0200fc8c.h"

void MBi_CommParentRecvData(Unk021432ac *header);
void MBi_CommParentRecvDataPerChild(Unk021432ac *childData, u32 child);
void MBi_CommParentCallback(s32 eventCode, Unk021425e8 *eventData);
void MBi_CommChangeParentStateCallbackOnly(u32 child, u32 value, void *data);
void MBi_CommChangeParentState(u32 child, u32 value, void *data);
u32 MB_CommResponseRequest(u32 child, u32 pairIndex);
u32 MB_CommIsBootable(u32 child);
void *MB_CommGetChildUser(u32 child);
