#pragma once

#include "types.h"
#include "wireless_power_mp.h"
#include "wireless_data_sharing.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "stream.h"
#include "sound_archive_load.h"

WMStatus *WMi_GetStatusAddress(void);
void WmClearFifoRecvFlag(void);
void WmReceiveFifo(u32 tag, WirelessMessage *callback, s32 err);
s32 WMi_CheckStateEx(s32 paramNum, ...);
s32 WMi_CheckIdle(void);
s32 WMi_CheckInitialized(void);
WMArm9Buf *WMi_GetSystemWork(void);
s32 WMi_SendCommand(u32 id, u16 paramNum, ...);
void WMi_SetCallbackTable(u32 id, WirelessMessageCallback callback);
s32 WM_Finish(void);
s32 WmInitCore(void *wmSysBuf, u16 dmaNo, u32 bufSize);
s32 WM_Init(void *wmSysBuf, u16 dmaNo);

// System work area set up by WmInitCore.
extern struct WMArm9Buf *wm9buf;

// Nonzero while the library is set up.
extern u16 wmInitialized;

// Ring of free command messages.
extern OSMessageQueue bufMsgQ;

extern void *bufMsg[10];

// Message WmReceiveFifo builds for the port callbacks on connect and disconnect.
extern struct WMPortRecvCallback gPortCallbackEvent;
// The ten 0x100-byte command messages.
extern u8 fifoBuf[10][0x100];
