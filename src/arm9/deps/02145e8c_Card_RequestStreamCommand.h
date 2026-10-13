#pragma once
/* Function-specific inferred declarations. */
void Card_BackupCommandTask(uint param_1);
bool Card_RequestStreamCommand(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9);
void Card_SetTask(undefined4 param_1);
longlong Os_DisableIrq(void);
void Os_ReferSymbol(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Sleep(int param_1);
#define iRam02145f7c (*(int *)(uintptr_t)0x2145f7cu)
#define uRam02145f70 (*(uint *)(uintptr_t)0x2145f70u)
#define uRam02145f74 (*(undefined4 *)(uintptr_t)0x2145f74u)
#define uRam02145f78 (*(undefined4 *)(uintptr_t)0x2145f78u)
