#pragma once
/* Function-specific inferred declarations. */
void Os_DisableIrqHandler(uint param_1);
void Os_InitializeAlarm(void);
void Os_ReserveTimer(uint param_1);
#define psRam0200fb78 (*(short **)(uintptr_t)0x200fb78u)
#define puRam0200fb7c (*(undefined4 **)(uintptr_t)0x200fb7cu)
