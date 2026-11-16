#include "alarm_timer.h"

#include "interrupt_control.h"
#include "tick_counter.h"
#include "reset_interrupts_halt.h"
#include "system_state_globals.h"
#include "timer_reserved_flag.h"

u16 g_AlarmInitialized;
OSiAlarmQueue g_Os_AlarmQueue;

// Starts timer 1 so that it fires when alarm is due; the count is the time left, or the next tick when it has passed.
void Os_SetAlarmTimer(OSAlarm *alarm) {
    u64 tick;
    s64 ticksLeft;
    u16 reload;

    tick = Os_GetTick();
    *(vu16 *) 0x4000106 = 0;
    ticksLeft = alarm->mFire - tick;
    Os_SetTimerIrqHandler(1, Os_AlarmHandler, 0);
    if (ticksLeft < 0) {
        reload = 0xfffe;
    } else if (ticksLeft < 0x10000) {
        reload = ~ticksLeft;
    } else {
        reload = 0;
    }
    *(vu16 *) 0x4000104 = reload;
    *(vu16 *) 0x4000106 = 0xc1;
    Os_EnableIrqHandler(0x10);
}

// Runs once: reserves timer 1, empties g_Os_AlarmQueue and clears the timer 1 interrupt enable.
void Os_InitializeAlarm(void) {
    if (g_AlarmInitialized != 0) {
        return;
    }
    g_AlarmInitialized = 1;
    Os_ReserveTimer(1);
    g_Os_AlarmQueue.mHead = 0;
    g_Os_AlarmQueue.mTail = 0;
    Os_DisableIrqHandler(0x10);
}

// Returns g_AlarmInitialized.
u32 OS_IsAlarmAvailable(void) {
    return g_AlarmInitialized;
}

// Clears OSAlarm.mHandler and OSAlarm.mTag.
void Os_Alarm_Create(OSAlarm *alarm) {
    alarm->mHandler = 0;
    alarm->mTag = 0;
}

// Inserts alarm into g_Os_AlarmQueue in order of OSAlarm.mFire. A periodic alarm takes OSAlarm.mStart moved forward by whole
// periods to the first time after now. Starts the timer when the alarm became the first one.
void Os_InsertAlarm(OSAlarm *alarm, u64 fire) {
    OSAlarm *next;
    u64 now;

    if (alarm->mPeriod != 0) {
        now = Os_GetTick();
        fire = alarm->mStart;
        if (fire < now) {
            fire = fire + alarm->mPeriod * ((now - fire) / alarm->mPeriod + 1);
        }
    }
    alarm->mFire = fire;
    for (next = g_Os_AlarmQueue.mHead; next != 0; next = next->mNext) {
        if ((s64) (fire - next->mFire) < 0) {
            alarm->mPrev = next->mPrev;
            next->mPrev = alarm;
            alarm->mNext = next;
            if (alarm->mPrev != 0) {
                alarm->mPrev->mNext = alarm;
                return;
            }
            g_Os_AlarmQueue.mHead = alarm;
            Os_SetAlarmTimer(alarm);
            return;
        }
    }
    alarm->mNext = 0;
    next = g_Os_AlarmQueue.mTail;
    g_Os_AlarmQueue.mTail = alarm;
    alarm->mPrev = next;
    if (next != 0) {
        next->mNext = alarm;
        return;
    }
    g_Os_AlarmQueue.mTail = alarm;
    g_Os_AlarmQueue.mHead = alarm;
    Os_SetAlarmTimer(alarm);
}

// Sets a one-shot alarm that calls handler with arg once tick ticks have passed.
void Os_Alarm_Set(OSAlarm *alarm, u64 tick, OSAlarmHandler handler, void *arg) {
    u32 enabled;

    if (alarm == 0 || alarm->mHandler != 0) {
        Os_Terminate();
    }
    enabled = Os_DisableIrq();
    alarm->mPeriod = 0;
    alarm->mHandler = handler;
    alarm->mArg = arg;
    Os_InsertAlarm(alarm, tick + Os_GetTick());
    Os_RestoreIrq(enabled);
}

// Unlinks an armed alarm from g_Os_AlarmQueue and clears OSAlarm.mHandler and OSAlarm.mPeriod.
void Os_Alarm_Cancel(OSAlarm *alarm) {
    u32 enabled;
    OSAlarm *next;

    enabled = Os_DisableIrq();
    if (alarm->mHandler == 0) {
        Os_RestoreIrq(enabled);
        return;
    }
    next = alarm->mNext;
    if (next == 0) {
        g_Os_AlarmQueue.mTail = alarm->mPrev;
    } else {
        next->mPrev = alarm->mPrev;
    }
    if (alarm->mPrev != 0) {
        alarm->mPrev->mNext = next;
    } else {
        g_Os_AlarmQueue.mHead = next;
        if (next != 0) {
            Os_SetAlarmTimer(next);
        }
    }
    alarm->mHandler = 0;
    alarm->mPeriod = 0;
    Os_RestoreIrq(enabled);
}

// Timer 1 interrupt body: runs the first alarm when it is due and starts the timer for the next one.
void Os_AlarmHandlerImpl(void) {
    OSAlarm *firstAlarm;
    OSAlarm *next;
    OSAlarmHandler alarmHandler;
    u64 now;

    *(vu16 *) 0x4000106 = 0;
    Os_DisableIrqHandler(0x10);
    IRQ_CHECK_FLAGS |= 0x10;
    now = Os_GetTick();
    firstAlarm = g_Os_AlarmQueue.mHead;
    if (firstAlarm == 0) {
        return;
    }
    if (now < firstAlarm->mFire) {
        Os_SetAlarmTimer(firstAlarm);
        return;
    }
    next = firstAlarm->mNext;
    g_Os_AlarmQueue.mHead = next;
    if (next == 0) {
        g_Os_AlarmQueue.mTail = 0;
    } else {
        next->mPrev = 0;
    }
    alarmHandler = firstAlarm->mHandler;
    if (firstAlarm->mPeriod == 0) {
        firstAlarm->mHandler = 0;
    }
    if (alarmHandler != 0) {
        alarmHandler(firstAlarm->mArg);
    }
    if (firstAlarm->mPeriod != 0) {
        firstAlarm->mHandler = alarmHandler;
        Os_InsertAlarm(firstAlarm, 0);
    }
    if (g_Os_AlarmQueue.mHead != 0) {
        Os_SetAlarmTimer(g_Os_AlarmQueue.mHead);
    }
}

// clang-format off
// Timer 1 handler: calls Os_AlarmHandlerImpl and returns.
// Kept as asm: its only call is a tail call through `ldr ip, =callee; bx ip`.
asm void Os_AlarmHandler(void) {
    stmdb sp!, {lr}
    bl Os_AlarmHandlerImpl
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
