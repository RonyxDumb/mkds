#pragma once

#include "types.h"
#include "multiboot_parent_state_machine.h"
#include "wireless_power_mp.h"
#include "multiboot_mode_constants.h"

s32 MB_StartParentFromIdle(u16 channel);
s32 MBi_StartParentCore(u16 channel);
s32 MBi_StartCommon(void);
u32 MB_SetParentCommParam(u32 sendDataSize, u32 maxChildren);
u32 MBi_IsCommSizeValid(u32 sendDataSize, u32 receiveDataSize, u32 maxChildren);
s32 MB_Init(void *buffer, MBUserInfo *user, u32 ggid, u32 tgid, u32 dmaNo);
u32 MBi_GetBeaconPeriodDispersion(void);
void MBi_ChildCallback(WirelessMessage *result);
void MBi_ChildPortCallback(void *portMessage);
void MBi_ParentCallback(WirelessMessage *result);
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

extern u16 mbi_life_frame;
extern u16 mbi_life_cam;
extern u16 mbi_life_table_no;
extern u16 mbi_life_mp;
extern u16 *gMultibootGameNameCursor;
extern u32 mbi_power_save_mode;
extern u16 gMultibootGameName[10];

extern u16 gWirelessDmaNo;
extern void *gWMSysBuf;
extern ScanParam gScanParams;
extern struct MBiParam *gWirelessWork;
extern struct MB_CommPWork *mbc;
