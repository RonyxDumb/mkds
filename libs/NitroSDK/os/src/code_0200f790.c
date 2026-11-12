#include "code_0200f790.h"

#include "code_0200c914.h"
#include "os_tick.h"
#include "code_0200fc8c.h"
#include "data_02170000.h"
#include "os_timer.h"

// Runs once: empties the vertical count alarm state and clears the V-count interrupt enable.
void OS_InitVAlarm(void) {
    if (OSi_UseVAlarm != 0) {
        return;
    }
    OSi_UseVAlarm = 1;
    OSi_VAlarmQueue[0] = 0;
    OSi_VAlarmQueue[1] = 0;
    OS_DisableIrqMask(4);
    OSi_VFrameCount = 0;
    OSi_PreviousVCount = 0;
}

u16 gAlarmInitialized;
OSiAlarmQueue gAlarmList;

// Starts timer 1 so that it fires when alarm is due; the count is the time left, or the next tick when it has passed.
void OSi_SetTimer(OSAlarm *alarm) {
    u64 tick;
    s64 delta;
    u16 reload;

    tick = OS_GetTick();
    *(vu16 *) 0x4000106 = 0;
    delta = alarm->mFire - tick;
    OSi_EnterTimerCallback(1, OSi_AlarmHandler, 0);
    if (delta < 0) {
        reload = 0xfffe;
    } else if (delta < 0x10000) {
        reload = ~delta;
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
    OSAlarm *alarm;
    OSAlarm *next;
    OSAlarmHandler handler;
    u64 now;

    *(vu16 *) 0x4000106 = 0;
    OS_DisableIrqMask(0x10);
    *OFFSET_PTR(u32, &gDtcmData, 0x3ff8) |= 0x10;
    now = OS_GetTick();
    alarm = gAlarmList.mHead;
    if (alarm == 0) {
        return;
    }
    if (now < alarm->mFire) {
        OSi_SetTimer(alarm);
        return;
    }
    next = alarm->mNext;
    gAlarmList.mHead = next;
    if (next == 0) {
        gAlarmList.mTail = 0;
    } else {
        next->mPrev = 0;
    }
    handler = alarm->mHandler;
    if (alarm->mPeriod == 0) {
        alarm->mHandler = 0;
    }
    if (handler != 0) {
        handler(alarm->mArg);
    }
    if (alarm->mPeriod != 0) {
        alarm->mHandler = handler;
        OSi_InsertAlarm(alarm, 0);
    }
    if (gAlarmList.mHead != 0) {
        OSi_SetTimer(gAlarmList.mHead);
    }
}

// clang-format off
// Timer 1 handler: calls OSi_ArrangeTimer and returns.
// Hand-written asm: its only call is a tail call through `ldr ip, =callee; bx ip`.
asm void OSi_AlarmHandler(void) {
    stmdb sp!, {lr}
    bl OSi_ArrangeTimer
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
