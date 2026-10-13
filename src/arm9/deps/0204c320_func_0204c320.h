#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
void Fs_Archive_NotifyAsyncEnded(int param_1,undefined4 param_2);
void MaybeBoundsCheck(uint param_1,uint param_2);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Terminate(void);
void SomeFileAsyncReadFunc(int param_1);
uint SomeRomUnkFatFntReload(uint param_1);
undefined4 func_02006d3c(undefined2 param_1,undefined4 param_2,int param_3,undefined4 param_4);
void func_02006d78(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
void func_02006db0(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void func_02006ddc(undefined2 param_1,undefined4 param_2);
uint func_02006fdc(int param_1);
void func_0204c320(uint param_1);
#define iRam0204c7d4 (*(int *)(uintptr_t)0x204c7d4u)
#define iRam0204c7d8 (*(int *)(uintptr_t)0x204c7d8u)
#define uRam0204c7dc (*(undefined4 *)(uintptr_t)0x204c7dcu)
#define uRam0204c7e0 (*(undefined4 *)(uintptr_t)0x204c7e0u)
