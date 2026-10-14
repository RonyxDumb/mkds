/* Decompiled C draft; module arm9; ROM address 02017770. No matching claim. */
#include "types.h"
#include "deps/02017770_Mem_Exp_Free.h"

void Mem_Exp_Free(int param_1,int param_2)

{
  undefined1 auStack_18 [12];
  
  Mem_GetMemoryBlockRegion((int *)(void *)(auStack_18),param_2 + -0x10);
  Mem_ExpHeapMemoryBlockList_Remove((uint *)(uintptr_t)(param_1 + 0x2c),param_2 + -0x10);
  Mem_Exp_CoalesceFreedRegion(param_1 + 0x24,(uint)(uintptr_t)(auStack_18));
  return;
}

