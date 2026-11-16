#pragma once

#include "types.h"
#include "wireless_link_control.h" // WirelessMessage, WirelessMessageCallback

void StartParentCallback(WirelessMessage *event);
void StartParent(WirelessMessageCallback callback);
void SetParentParameterCallback(WirelessMessage *event);
void SetParentParameter(void);
u16 ComputeParentTgid(u32 unusedValue);
void StopRomArchiveTransfer(void);
void StartRomArchiveSend(void);
void RomArchiveStateCallback(s32 unusedValue);
void StartRomArchiveTransfer(void);
void *RomArchiveAllocFunc(s32 unusedValue, u32 size, void *block);
void MeasureChannelCallback(WirelessMessage *event);
void MeasureChannel(u16 measuredChannel);
void SetLifeTimeCallback(WirelessMessage *event);
void SetLifeTime(s32 camLifeTime);
void ResetCallback(WirelessMessage *event);
void StopConnection(void);
void InitializeCallback(WirelessMessage *event);
void Initialize(void);
BOOL UpdateDataSharing(void);
void StepDataSharing(void);
void ResetConnection(void);
