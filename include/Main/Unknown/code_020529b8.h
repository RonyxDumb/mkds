#pragma once

#include "types.h"
#include "code_02142eac.h" // Unk021425e8, Unk021425e8Func

void StartParentCallback(Unk021425e8 *event);
void StartParent(Unk021425e8Func callback);
void func_02052bb8(Unk021425e8 *event);
void SetParentParameter(void);
u16 sub_2052C5C(u32 a);
void StopRomArchiveTransfer(void);
void func_02052da4(void);
void RomArchiveStateCallback(s32 a);
void StartRomArchiveTransfer(void);
void *RomArchiveAllocFunc(s32 a, u32 size, void *block);
void MeasureChannelCallback(Unk021425e8 *event);
void MeasureChannel(u16 measuredChannel);
void func_0205329c(Unk021425e8 *event);
void SetLifeTime(s32 camLifeTime);
void ResetCallback(Unk021425e8 *event);
void sub_20533A0(void);
void InitializeCallback(Unk021425e8 *event);
void Initialize(void);
BOOL UpdateDataSharing(void);
void StepDataSharing(void);
void sub_2053D00(void);
