#pragma once
/* Function-specific inferred declarations. */
void Os_DisableIrqHandler(uint param_1);
void Os_SetIrqHandler(uint param_1,undefined4 param_2);
void SomeDmaIrqHandler(void);
#define puRam0214ce00 (*(uint **)(uintptr_t)0x214ce00u)
#define puRam0214ce04 (*(undefined4 **)(uintptr_t)0x214ce04u)
