#include "03/System/task_vblank_irq.h"
#include "03/Menu/wifi_menu_shared.h"
#include "interrupt_control.h"
#include "reset_interrupts_halt.h"
#include "registers.h"
#include "03/System/touch_key_input.h"
#include "fixed_vector_math.h"

u32 gSavedIrqMask;
OSIrqFunction gSavedIrqFunction;

void EnableTaskVBlankIrq(void) {
    u16 previousIme;

    gSavedIrqMask = reg_OS_IE;
    SetIE(0x40018);
    Os_EnableIrqHandler(1);
    gSavedIrqFunction = Os_GetIrqHandler(1);
    Os_SetIrqHandler(1, TaskVBlankIrqHandler);
    previousIme = reg_OS_IME;
    reg_OS_IME = 1;
    Os_EnableIrq();
}

void RestoreTaskVBlankIrq(void) {
    u16 previousIme;

    previousIme = reg_OS_IME;
    reg_OS_IME = 0;
    SetIE(gSavedIrqMask);
    Os_SetIrqHandler(1, gSavedIrqFunction);
}

void TaskVBlankIrqHandler(void) {
    RunTasksAndRemoveRequested(1);
    IRQ_CHECK_FLAGS |= 1;
}
