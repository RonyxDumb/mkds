#pragma once

#include "types.h"
#include "code_02013bdc.h"
#include "os_thread.h"
#include "code_0200f790.h"

typedef struct NNSG3dGlb NNSG3dGlb;

extern OSThread g_Os_LauncherThread;
extern u32 isArenaInit;
// Gate of arena index 2. Zero in this game: the only store writes 0.
extern u32 OSi_MainExArenaEnabled;
extern UnkFunc *OSi_UserExceptionHandler;
extern u32 OSi_UserExceptionHandlerArg;
extern u8 OSi_ExContext[];
extern UnkFunc *OSi_DebuggerHandler;
extern u16 g_ReservedTimerMask;
// Halfword set to 1 by OS_InitTick.
extern u16 OSi_UseTick;
extern u32 OSi_NeedResetTimer;
// 64-bit count of timer 0 wraps, added by OSi_CountUpTick, read by OS_GetTick.
extern volatile u64 OSi_TickCounter;
// Halfword set to 1 by OS_InitAlarm.
extern u16 gAlarmInitialized;
// Head and tail of the armed alarms, ordered by fire time; cleared by OS_InitAlarm.
extern OSiAlarmQueue gAlarmList;
extern u16 g_VAlarmInitialized;
extern u32 g_VAlarm_PrevVCount;
extern u32 g_VAlarm_FrameCount;
extern u32 g_VAlarmQueue[2];

extern NNSG3dGlb NNS_G3dGlb;
extern Unk02170500 *data_02170500;
// The three vectors passed to G3i_LookAt_, written together before each call.
extern Vec3 data_021704dc[3];
extern NNSG3dMatAnmResult data_02170504[];
