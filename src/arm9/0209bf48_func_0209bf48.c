/* Decompiled C draft; module arm9; ROM address 0209bf48. No matching claim. */
#include "types.h"
#include "deps/0209bf48_func_0209bf48.h"

void func_0209bf48(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  iVar2 = Mem_AllocateHeap(uVar1,0x28);
  *(undefined4 *)(iVar2 + 8) = param_1;
  *(undefined4 *)(iVar2 + 0xc) = param_3;
  *(undefined4 *)(iVar2 + 0x10) = param_2;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  return;
}

