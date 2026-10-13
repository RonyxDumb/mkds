#pragma once
/* Function-specific inferred declarations. */
uint Os_EnableIrqHandler(uint param_1);
void Os_InitializeTick(void);
void Os_ReserveTimer(uint param_1);
void Os_SetIrqHandler(uint param_1,undefined4 param_2);
#define psRam0200f778 (*(short **)(uintptr_t)0x200f778u)
#define puRam0200f77c (*(undefined4 **)(uintptr_t)0x200f77cu)
#define puRam0200f780 (*(undefined2 **)(uintptr_t)0x200f780u)
#define puRam0200f784 (*(undefined2 **)(uintptr_t)0x200f784u)
#define puRam0200f78c (*(undefined4 **)(uintptr_t)0x200f78cu)
#define uRam0200f788 (*(undefined4 *)(uintptr_t)0x200f788u)
