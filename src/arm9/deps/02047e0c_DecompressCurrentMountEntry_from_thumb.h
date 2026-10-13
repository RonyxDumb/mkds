#pragma once
/* Function-specific inferred declarations. */
void DC_SomeClean(uint param_1,int param_2);
void DecompressCurrentMountEntry_from_thumb(void);
void DecompressLzss(uint param_1,byte *param_2);
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
undefined4 Mem_AllocateHeapAligned(uint param_1,undefined4 param_2,undefined4 param_3);
int Mem_GetExpHeapTotalFreeSize(int param_1);
#define iRam02047e90 (*(int *)(uintptr_t)0x2047e90u)
#define piRam02047e8c (*(int **)(uintptr_t)0x2047e8cu)
