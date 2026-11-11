#pragma once

#include "types.h"
#include "code_02007148.h"
#include "mb_data.h"
#include "code_020071b4.h"
#include "code_0200c0d8.h"
#include "code_02009928.h"
#include "code_02142eac.h"
#include "code_0200fc8c.h"

void MBi_CommParentRecvData(Unk021432ac *header);
void MBi_CommParentRecvDataPerChild(WMMpRecvData *childData, u32 child);
void MBi_CommParentCallback(s32 eventCode, Unk021425e8 *eventData);
void MBi_CommChangeParentStateCallbackOnly(u32 child, u32 value, void *data);
void MBi_CommChangeParentState(u32 child, u32 value, void *data);
u32 MB_CommResponseRequest(u32 child, u32 pairIndex);
u32 MB_CommIsBootable(u32 child);
void *MB_CommGetChildUser(u32 child);
void MBi_CommCallParentError(u32 aid, u16 errcode);
u32 IsChildAidValid(u32 aid);
