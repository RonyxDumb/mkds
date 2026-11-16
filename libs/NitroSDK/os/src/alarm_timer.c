#include "alarm_timer.h"

#include "interrupt_control.h"
#include "tick_counter.h"
#include "reset_interrupts_halt.h"
#include "system_state_globals.h"
#include "timer_reserved_flag.h"

u16 gAlarmInitialized;
OSiAlarmQueue gAlarmList;

// Starts timer 1 so that it fires when alarm is due; the count is the time left, or the next tick when it has passed.
void OSi_SetTimer(OSAlarm *alarm) {
    u64 tick;
    s64 ticksLeft;
    u16 reload;

    tick = OS_GetTick();
    *(vu16 *) 0x4000106 = 0;
    ticksLeft = alarm->mFire - tick;
    OSi_EnterTimerCallback(1, OSi_AlarmHandler, 0);
    if (ticksLeft < 0) {
        reload = 0xfffe;
    } else if (ticksLeft < 0x10000) {
        reload = ~ticksLeft;
    } else {
        reload = 0;
    }
    *(vu16 *) 0x4000104 = reload;
    *(vu16 *) 0x4000106 = 0xc1;
    OS_EnableIrqMask(0x10);
}

// Runs once: reserves timer 1, empties gAlarmList and clears the timer 1 interrupt enable.
void OS_InitAlarm(void) {
    if (gAlarmInitialized != 0) {
        return;
    }
    gAlarmInitialized = 1;
    OSi_SetTimerReserved(1);
    gAlarmList.mHead = 0;
    gAlarmList.mTail = 0;
    OS_DisableIrqMask(0x10);
}

// Returns gAlarmInitialized.
u32 OS_IsAlarmAvailable(void) {
    return gAlarmInitialized;
}

// Clears OSAlarm.mHandler and OSAlarm.mTag.
void OS_CreateAlarm(OSAlarm *alarm) {
    alarm->mHandler = 0;
    alarm->mTag = 0;
}

// Inserts alarm into gAlarmList in order of OSAlarm.mFire. A periodic alarm takes OSAlarm.mStart moved forward by whole
// periods to the first time after now. Starts the timer when the alarm became the first one.
void OSi_InsertAlarm(OSAlarm *alarm, u64 fire) {
    OSAlarm *next;
    u64 now;

    if (alarm->mPeriod != 0) {
        now = OS_GetTick();
        fire = alarm->mStart;
        if (fire < now) {
            fire = fire + alarm->mPeriod * ((now - fire) / alarm->mPeriod + 1);
        }
    }
    alarm->mFire = fire;
    for (next = gAlarmList.mHead; next != 0; next = next->mNext) {
        if ((s64) (fire - next->mFire) < 0) {
            alarm->mPrev = next->mPrev;
            next->mPrev = alarm;
            alarm->mNext = next;
            if (alarm->mPrev != 0) {
                alarm->mPrev->mNext = alarm;
                return;
            }
            gAlarmList.mHead = alarm;
            OSi_SetTimer(alarm);
            return;
        }
    }
    alarm->mNext = 0;
    next = gAlarmList.mTail;
    gAlarmList.mTail = alarm;
    alarm->mPrev = next;
    if (next != 0) {
        next->mNext = alarm;
        return;
    }
    gAlarmList.mTail = alarm;
    gAlarmList.mHead = alarm;
    OSi_SetTimer(alarm);
}

// Sets a one-shot alarm that calls handler with arg once tick ticks have passed.
void OS_SetAlarm(OSAlarm *alarm, u64 tick, OSAlarmHandler handler, void *arg) {
    u32 enabled;

    if (alarm == 0 || alarm->mHandler != 0) {
        OS_Terminate();
    }
    enabled = OS_DisableInterrupts();
    alarm->mPeriod = 0;
    alarm->mHandler = handler;
    alarm->mArg = arg;
    OSi_InsertAlarm(alarm, tick + OS_GetTick());
    OS_RestoreInterrupts(enabled);
}

// Unlinks an armed alarm from gAlarmList and clears OSAlarm.mHandler and OSAlarm.mPeriod.
void OS_CancelAlarm(OSAlarm *alarm) {
    u32 enabled;
    OSAlarm *next;

    enabled = OS_DisableInterrupts();
    if (alarm->mHandler == 0) {
        OS_RestoreInterrupts(enabled);
        return;
    }
    next = alarm->mNext;
    if (next == 0) {
        gAlarmList.mTail = alarm->mPrev;
    } else {
        next->mPrev = alarm->mPrev;
    }
    if (alarm->mPrev != 0) {
        alarm->mPrev->mNext = next;
    } else {
        gAlarmList.mHead = next;
        if (next != 0) {
            OSi_SetTimer(next);
        }
    }
    alarm->mHandler = 0;
    alarm->mPeriod = 0;
    OS_RestoreInterrupts(enabled);
}

// Timer 1 interrupt body: runs the first alarm when it is due and starts the timer for the next one.
void OSi_ArrangeTimer(void) {
    OSAlarm *firstAlarm;
    OSAlarm *next;
    OSAlarmHandler alarmHandler;
    u64 now;

    *(vu16 *) 0x4000106 = 0;
    OS_DisableIrqMask(0x10);
    IRQ_CHECK_FLAGS |= 0x10;
    now = OS_GetTick();
    firstAlarm = gAlarmList.mHead;
    if (firstAlarm == 0) {
        return;
    }
    if (now < firstAlarm->mFire) {
        OSi_SetTimer(firstAlarm);
        return;
    }
    next = firstAlarm->mNext;
    gAlarmList.mHead = next;
    if (next == 0) {
        gAlarmList.mTail = 0;
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
        OSi_InsertAlarm(firstAlarm, 0);
    }
    if (gAlarmList.mHead != 0) {
        OSi_SetTimer(gAlarmList.mHead);
    }
}

// clang-format off
// Timer 1 handler: calls OSi_ArrangeTimer and returns.
// Kept as asm: pushes only lr with `stmdb`, calls OSi_ArrangeTimer with `bl`, pops lr and returns with `bx lr`.
asm void OSi_AlarmHandler(void) {
    stmdb sp!, {lr}
    bl OSi_ArrangeTimer
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
