#pragma once

#include "types.h"
#include "code_02142eac.h" // Unk021425e8, Unk021425e8Func

void StartParentCallback(Unk021425e8 *event);
void StartParent(Unk021425e8Func callback);
void SetParentParameterCallback(Unk021425e8 *event);
void SetParentParameter(void);
u16 ComputeParentTgid(u32 unusedValue);
void StopRomArchiveTransfer(void);
void StartRomArchiveSend(void);
void RomArchiveStateCallback(s32 unusedValue);
void StartRomArchiveTransfer(void);
void *RomArchiveAllocFunc(s32 unusedValue, u32 size, void *block);
void MeasureChannelCallback(Unk021425e8 *event);
void MeasureChannel(u16 measuredChannel);
void SetLifeTimeCallback(Unk021425e8 *event);
void SetLifeTime(s32 camLifeTime);
void ResetCallback(Unk021425e8 *event);
void StopConnection(void);
void InitializeCallback(Unk021425e8 *event);
void Initialize(void);
BOOL UpdateDataSharing(void);
void StepDataSharing(void);
void ResetConnection(void);
