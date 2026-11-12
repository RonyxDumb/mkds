#pragma once

#include "types.h"
#include "code_02013bdc.h"
#include "os_thread.h"
#include "code_0200f790.h"

typedef struct NNSG3dGlb NNSG3dGlb;

extern OSThread OSi_LauncherThread;
extern u32 OSi_Initialized;
// Gate of arena index 2. Zero in this game: the only store writes 0.
extern u32 gArena2Enabled;
extern UnkFunc *OSi_UserExceptionHandler;
extern u32 OSi_UserExceptionHandlerArg;
extern u8 OSi_ExContext[];
extern UnkFunc *OSi_DebuggerHandler;
extern u16 OSi_TimerReserved;
// Halfword set to 1 by OS_InitTick.
extern u16 gTickInitialized;
extern u32 OSi_NeedResetTimer;
// 64-bit count of timer 0 wraps, added by OSi_CountUpTick, read by OS_GetTick.
extern volatile u64 gTickOverflowCount;
// Halfword set to 1 by OS_InitAlarm.
extern u16 gAlarmInitialized;
// Head and tail of the armed alarms, ordered by fire time; cleared by OS_InitAlarm.
extern OSiAlarmQueue gAlarmList;

extern NNSG3dGlb NNS_G3dGlb;
extern NNSG3dRS *NNS_G3dRS;
extern NNSG3dRSOnGlb NNS_G3dRSOnGlb;
