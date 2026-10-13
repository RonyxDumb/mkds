#pragma once
/* Function-specific inferred declarations. */
int AllocateReadFileBuffer_from_thumb(undefined4 param_1,undefined4 param_2);
void DC_SomeClean(uint param_1,int param_2);
uint ExecutionContext_GetHeapHandle(int param_1);
undefined4 Fs_File_Close(int param_1);
void Fs_File_Initialize(undefined4 *param_1);
undefined4 Fs_File_Open(undefined4 param_1);
void Fs_File_Read(void);
uint Fs_IsInitialized(void);
uint GetActiveExecutionContext(void);
undefined4 Mem_AllocateHeapAligned(uint param_1,undefined4 param_2,undefined4 param_3);
undefined4 Mem_FreeHeap(uint param_1);

