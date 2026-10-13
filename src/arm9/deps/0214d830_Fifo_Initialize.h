#pragma once
/* Function-specific inferred declarations. */
void Fifo_Initialize(void);
longlong Os_DisableIrq(void);
uint Os_EnableIrqHandler(uint param_1);
undefined4 Os_RestoreIrq(void);
void Os_SetIrqHandler(uint param_1,undefined4 param_2);
uint SetIF(undefined4 param_1);
#define iRam0214d924 (*(int *)(uintptr_t)0x214d924u)
#define iRam0214d928 (*(int *)(uintptr_t)0x214d928u)
#define psRam0214d920 (*(short **)(uintptr_t)0x214d920u)
#define puRam0214d930 (*(undefined2 **)(uintptr_t)0x214d930u)
#define puRam0214d938 (*(ushort **)(uintptr_t)0x214d938u)
#define uRam0214d92c (*(undefined4 *)(uintptr_t)0x214d92cu)
#define uRam0214d934 (*(undefined4 *)(uintptr_t)0x214d934u)
