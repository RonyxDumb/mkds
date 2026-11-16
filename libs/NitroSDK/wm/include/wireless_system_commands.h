#pragma once

#include "types.h"
#include "wireless_link_control.h"
#include "wireless_key_data_sharing.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "sound_stream_control.h"
#include "sound_archive_load.h"

WMStatus *WMi_GetStatusAddress(void);
void Wm_DisableCallbackControl(void);
void Wm_FifoHandler(u32 tag, WirelessMessage *callback, s32 err);
s32 WMi_CheckStateEx(s32 paramNum, ...);
s32 WMi_CheckIdle(void);
s32 Wm_CheckInitialized(void);
WMArm9Buf *Wm_GetGlobal(void);
s32 WM_SomeFn(u32 id, u16 paramNum, ...);
void SetSomeFunctionPtr(u32 id, WirelessMessageCallback callback);
s32 WM_Finish(void);
s32 Wm_InitializeImpl(void *wmSysBuf, u16 dmaNo, u32 bufSize);
s32 Wm_Initialize(void *wmSysBuf, u16 dmaNo);

// System work area set up by Wm_InitializeImpl.
extern struct WMArm9Buf *g_GlobalWM;

// Nonzero while the library is set up.
extern u16 g_WmInitialized;

// Ring of free command messages.
extern OSMessageQueue g_WMQueue;

extern void *g_WMQueueBuffer[10];

// Message Wm_FifoHandler builds for the port callbacks on connect and disconnect.
extern struct WMPortRecvCallback gPortCallbackEvent;
// The ten 0x100-byte command messages.
extern u8 g_WMQueueMessagesData[10][0x100];
