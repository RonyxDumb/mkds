#include "03/System/task_vblank_irq.h"
#include "03/Menu/wifi_menu_shared.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "registers.h"
#include "03/types_021d299c.h"
#include "code_02147cd8.h"

u32 gSavedIrqMask;
OSIrqFunction gSavedIrqFunction;

void EnableTaskVBlankIrq(void) {
    u16 previousIme;

    gSavedIrqMask = reg_OS_IE;
    OS_SetIrqMask(0x40018);
    OS_EnableIrqMask(1);
    gSavedIrqFunction = OS_GetIrqFunction(1);
    OS_SetIrqFunction(1, TaskVBlankIrqHandler);
    previousIme = reg_OS_IME;
    reg_OS_IME = 1;
    OS_EnableInterrupts();
}

void RestoreTaskVBlankIrq(void) {
    u16 previousIme;

    previousIme = reg_OS_IME;
    reg_OS_IME = 0;
    OS_SetIrqMask(gSavedIrqMask);
    OS_SetIrqFunction(1, gSavedIrqFunction);
}

void TaskVBlankIrqHandler(void) {
    RunTasksAndRemoveRequested(1);
    IRQ_CHECK_FLAGS |= 1;
}
