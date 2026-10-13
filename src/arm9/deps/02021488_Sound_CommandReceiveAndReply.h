#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_SpinWait(uint param_1);
uint Sound_CommandReceiveAndReply(uint param_1);
uint func_02021834(void);
#define iRam020215ac (*(int *)(uintptr_t)0x20215acu)
#define piRam020215a4 (*(int **)(uintptr_t)0x20215a4u)
#define piRam020215a8 (*(int **)(uintptr_t)0x20215a8u)
#define piRam020215b4 (*(int **)(uintptr_t)0x20215b4u)
#define puRam020215b0 (*(uint **)(uintptr_t)0x20215b0u)
#define puRam020215b8 (*(uint **)(uintptr_t)0x20215b8u)
