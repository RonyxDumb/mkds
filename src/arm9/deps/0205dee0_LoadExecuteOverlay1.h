#pragma once
/* Function-specific inferred declarations. */
int ComputeRAudioBufferAllocSize(int param_1);
void DisposeSomeSoundStuff(void);
void EnableGreenSwap(void);
void EnableVblankIRQ(void);
uint ExecutionContext_GetHeapHandle(int param_1);
undefined4 Fs_LoadOverlay(undefined4 param_1,undefined4 param_2);
undefined4 Fs_UnloadOverlay(undefined4 param_1,undefined4 param_2);
ushort GX_VBlankIntr(int param_1,ushort param_2);
uint GetActiveExecutionContext(void);
void LoadExecuteOverlay1(void);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
undefined4 Mem_AllocateHeapAligned(uint param_1,undefined4 param_2,undefined4 param_3);
void Mem_CreateChildExpHeap(uint param_1);
uint Mem_DestroyHeap(uint param_1);
undefined4 Mem_FreeHeap(uint param_1);
longlong Os_DisableIrq(void);
void Os_DisableIrqHandler(uint param_1);
void Os_SetIrqHandler(uint param_1,undefined4 param_2);
void SetBrightness(ushort *param_1,int param_2);
void SetGlobalSdatActive(void);
void SomeAudioInit(int param_1,int param_2);
void WaitForWorkerTask(void);
void func_02108ed8(void);
void func_02145d38(void);
#define iRam0205e084 (*(int *)(uintptr_t)0x205e084u)
#define psRam0205e070 (*(short **)(uintptr_t)0x205e070u)
#define puRam0205e07c (*(undefined2 **)(uintptr_t)0x205e07cu)
#define uRam0205e06c (*(uint *)(uintptr_t)0x205e06cu)
#define uRam0205e074 (*(uint *)(uintptr_t)0x205e074u)
#define uRam0205e078 (*(undefined4 *)(uintptr_t)0x205e078u)
#define uRam0205e080 (*(uint *)(uintptr_t)0x205e080u)
#define uRam0205e088 (*(undefined4 *)(uintptr_t)0x205e088u)
#define uRam0205e08c (*(undefined4 *)(uintptr_t)0x205e08cu)
