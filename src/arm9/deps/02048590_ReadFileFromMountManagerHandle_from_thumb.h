#pragma once
/* Function-specific inferred declarations. */
undefined4 Fs_File_Close(int param_1);
undefined4 Fs_File_Open(undefined4 param_1);
void Fs_File_Read(void);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
undefined4 Mem_FreeHeap(uint param_1);
int ReadFileFromMountManagerHandle_from_thumb(undefined4 param_1,undefined4 param_2,int *param_3);
#define iRam02048638 (*(int *)(uintptr_t)0x2048638u)
#define piRam02048634 (*(int **)(uintptr_t)0x2048634u)
