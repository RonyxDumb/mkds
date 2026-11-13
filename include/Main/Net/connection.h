#pragma once

#include "types.h"
#include "code_02142eac.h" // WirelessMessage, Unk021425e8Func

void StartParentCallback(WirelessMessage *event);
void StartParent(Unk021425e8Func callback);
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
