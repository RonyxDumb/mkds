#pragma once
/* Function-specific inferred declarations. */
void DC_SomeClean(uint param_1,int param_2);
uint ExecutionContext_GetHeapHandle(int param_1);
void Fs_File_Initialize(undefined4 *param_1);
undefined4 Fs_File_Open(undefined4 param_1);
void Fs_File_Read(void);
uint GetActiveExecutionContext(void);
void LzDecompressContext_Create(undefined4 *param_1,undefined4 param_2,uint param_3);
uint LzDecompressContext_DoCycle(undefined4 *param_1,byte *param_2,int param_3);
undefined4 Mem_AllocateHeapAligned(uint param_1,undefined4 param_2,undefined4 param_3);
int Mem_GetExpHeapTotalFreeSize(int param_1);
void ReadDecompressCurrentMountEntry_from_thumb(void);
#define iRam02047f70 (*(int *)(uintptr_t)0x2047f70u)
#define piRam02047f6c (*(int **)(uintptr_t)0x2047f6cu)
#define uRam02047f74 (*(uint *)(uintptr_t)0x2047f74u)
#define uRam02047f78 (*(undefined4 *)(uintptr_t)0x2047f78u)
