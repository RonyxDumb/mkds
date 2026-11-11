#pragma once

#include "types.h"
#include "code_02007148.h"
#include "code_02142eac.h"

extern u16 mbi_life_frame;
extern u16 mbi_life_cam;
extern u16 mbi_life_mp;
extern u16 mbi_life_table_no;
extern u16 gWirelessDmaNo;
extern void *gWMSysBuf;
extern u16 *data_usa_021617a0;
extern u32 data_usa_021617a4;

s32 MB_StartParentFromIdle(u16 channel);
s32 MBi_StartParentCore(u16 channel);
s32 MBi_StartCommon(void);
u32 MB_SetParentCommParam(u32 sendDataSize, u32 maxChildren);
u32 MBi_IsCommSizeValid(u32 sendDataSize, u32 receiveDataSize, u32 maxChildren);
s32 MB_Init(void *buffer, MBUserInfo *user, u32 ggid, u32 tgid, u32 dmaNo);
u32 MBi_GetBeaconPeriodDispersion(void);
void MBi_ChildCallback(Unk021425e8 *result);
void MBi_ChildPortCallback(Unk021425e8 *result);
void MBi_ParentCallback(Unk021425e8 *result);
void MBi_SetMaxScanTime(u32 maxChannelTime);
void MB_DisconnectChild(u32 childIndex);
void MB_EndToIdle(void);
u32 MBi_CommEnd(void);
u32 MBi_OnReset(void);
int MBi_CallReset(void);
void MBi_CheckWmErrcode(u16 command, s32 resultCode);
u32 MBi_IsStarted(void);
u8 MBi_GetAttribute(void);
u16 MBi_GetTgid(void);
unsigned int MBi_GetGgid(void);
