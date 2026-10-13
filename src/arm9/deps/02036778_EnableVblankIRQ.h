#pragma once
/* Function-specific inferred declarations. */
void EnableVblankIRQ(void);
ushort GX_VBlankIntr(int param_1,ushort param_2);
longlong Os_EnableIrq(void);
uint Os_EnableIrqHandler(uint param_1);
void Os_SetIrqHandler(uint param_1,undefined4 param_2);
#define puRam020367c0 (*(undefined2 **)(uintptr_t)0x20367c0u)
#define uRam020367bc (*(undefined4 *)(uintptr_t)0x20367bcu)
