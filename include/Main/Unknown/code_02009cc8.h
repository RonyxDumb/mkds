#pragma once

#include "types.h"
#include "code_02007148.h"
#include "code_02007624.h"
#include "Main/Unknown/code_02007ea0.h"
#include "Main/Unknown/code_02009000.h"
#include "code_02009928.h"
#include "Main/Unknown/code_02009adc.h"
#include "code_0200ad00.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200c0d8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02161000.h"
#include "wm_etc.h"
#include "code_0214c778.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"

extern u16 gWirelessDmaNo;
extern void *gWMSysBuf;
extern u16 *data_usa_021617a0;
extern u32 data_usa_021617a4;

s32 MB_StartParentFromIdle(u16 channel);
s32 MBi_StartParentCore(u16 channel);
s32 MBi_StartCommon(void);
u32 SetMPLimits(u32 sendDataSize, u32 maxChildren);
u32 MBi_IsCommSizeValid(u32 sendDataSize, u32 receiveDataSize, u32 maxChildren);
s32 InitWirelessWork(void *buffer, Unk02009ff4 *b, u32 ggid, u32 tgid, u32 dmaNo);
u32 MBi_GetBeaconPeriodDispersion(void);
void MBi_ChildCallback(Unk021425e8 *result);
void MBi_ChildPortCallback(Unk021425e8 *result);
void MBi_ParentCallback(Unk021425e8 *result);
