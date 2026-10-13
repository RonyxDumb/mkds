#pragma once
/* Function-specific inferred declarations. */
int ComputeRAudioBufferAllocSize(int param_1);
void CreateStructBHeap_from_thumb(undefined4 param_1);
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
void InitializeSomeZEPointers(undefined4 param_1);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void SomeAudioInit(int param_1,int param_2);
void UpdateOverlayStatusWithKind(uint param_1);
void WaitOverlayLoadedStarted(void);
void func_0205e0b0(void);
#define psRam0205e17c (*(short **)(uintptr_t)0x205e17cu)
#define uRam0205e178 (*(uint *)(uintptr_t)0x205e178u)
