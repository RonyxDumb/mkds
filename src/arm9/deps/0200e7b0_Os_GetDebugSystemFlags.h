#pragma once
/* Function-specific inferred declarations. */
void Operation_CartArm7(undefined4 param_1);
void Operation_CartArm9(undefined4 param_1);
int Os_AllocateLockId(void);
longlong Os_DisableIrq(void);
undefined4 Os_GetDebugSystemFlags(void);
undefined2 Os_Lock_GetOwnerId(int param_1);
undefined4 Os_RestoreIrq(void);
#define _DAT_08000000 (*(int *)(uintptr_t)0x8000000u)
#define iRam0200e878 (*(int *)(uintptr_t)0x200e878u)
#define uRam0200e874 (*(undefined4 *)(uintptr_t)0x200e874u)
#define uRam0200e87c (*(uint *)(uintptr_t)0x200e87cu)
#define uRam0200e880 (*(uint *)(uintptr_t)0x200e880u)
