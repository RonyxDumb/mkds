#pragma once

#include "types.h"
#include "animation_object_calc.h"
#include "thread_scheduler.h"
#include "alarm_timer.h"

typedef struct NNSG3dGlb NNSG3dGlb;

typedef void (*OSExceptionHandler)(u32 exinfo, void *arg);

extern OSThread g_Os_LauncherThread;
extern u32 g_MemoryRegionsInit;
// Gate of arena index 2. Zero in this game: the only store writes 0.
extern u32 g_MainExRegionEnabled;
extern OSExceptionHandler g_UserExceptionHandler;
extern u32 g_UserExceptionHandlerArg;
extern u8 g_ExceptionContext[];
extern void *OSi_DebuggerHandler;
extern u16 g_ReservedTimerMask;
// Halfword set to 1 by Os_InitializeTick.
extern u16 g_Os_TickInitialized;
extern u32 g_Os_NeedsTimerReset;
// 64-bit count of timer 0 wraps, added by Os_CountTicks, read by Os_GetTick.
extern volatile u64 g_Os_TickCounter;
// Halfword set to 1 by Os_InitializeAlarm.
extern u16 g_AlarmInitialized;
// Head and tail of the armed alarms, ordered by fire time; cleared by Os_InitializeAlarm.
extern OSiAlarmQueue g_Os_AlarmQueue;

extern NNSG3dGlb g_GlobalG3;
extern NNSG3dRS *NNS_G3dRS;
extern NNSG3dRSOnGlb NNS_G3dRSOnGlb;
