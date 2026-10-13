#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
void Fs_File_Initialize(undefined4 *param_1);
void MaybeSetupRomRootOrOverlays(int param_1,int param_2);
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
undefined4 Mem_DcDrainWriteBuffer(void);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void SomeInitialize(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
undefined4 StructGO_SomeFn_from_thumb(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,undefined2 param_6);
void func_02006aac(int param_1,int param_2,undefined4 param_3);
void func_0204bad8(void);
void func_0204c28c(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
#define iRam0204c278 (*(int *)(uintptr_t)0x204c278u)
#define iRam0204c27c (*(int *)(uintptr_t)0x204c27cu)
#define iRam0204c280 (*(int *)(uintptr_t)0x204c280u)
#define puRam0204c26c (*(undefined4 **)(uintptr_t)0x204c26cu)
#define puRam0204c270 (*(undefined4 **)(uintptr_t)0x204c270u)
#define uRam0204c274 (*(undefined4 *)(uintptr_t)0x204c274u)
#define uRam0204c284 (*(undefined4 *)(uintptr_t)0x204c284u)
#define uRam0204c288 (*(undefined4 *)(uintptr_t)0x204c288u)
