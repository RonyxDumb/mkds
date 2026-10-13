#pragma once
/* Function-specific inferred declarations. */
bool Card_Request(uint param_1,int param_2,int param_3);
void EnsureCardEnabled(void);
bool MaybeInitializeBackup(int param_1);
longlong Os_DisableIrq(void);
void Os_ReferSymbol(void);
undefined4 Os_RestoreIrq(void);
void Os_Terminate(void);
void Os_Thread_Sleep(int param_1);
void Os_Thread_WakeUp(uint *param_1);
void Os_Thread_WakeUpDirect(int param_1);
void func_02145b54(uint param_1);
#define iRam02145e88 (*(int *)(uintptr_t)0x2145e88u)
#define uRam02145e80 (*(undefined4 *)(uintptr_t)0x2145e80u)
#define uRam02145e84 (*(uint *)(uintptr_t)0x2145e84u)
