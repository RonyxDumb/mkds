/* Decompiled C draft; module arm9; ROM address 020d98a4. No matching claim. */
#include "types.h"
#include "deps/020d98a4_func_020d98a4.h"

void func_020d98a4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  puVar3 = (undefined4 *)Mem_AllocateHeap(uVar2,0x10);
  *piRam020d98f0 = (int)puVar3;
  *puVar3 = *(undefined4 *)(param_1 + 8);
  uVar2 = FindFileBuffer_CRS_CST_from_thumb(uRam020d98f4);
  *(undefined4 *)(*piRam020d98f0 + 4) = uVar2;
  uVar2 = FindFileBuffer_CRS_CST_from_thumb(uRam020d98f8);
  *(undefined4 *)(*piRam020d98f0 + 8) = uVar2;
  uVar2 = FindFileBuffer_CRS_CST_from_thumb(uRam020d98fc);
  piVar1 = piRam020d98f0;
  *(undefined4 *)(*piRam020d98f0 + 0xc) = uVar2;
  func_020d4970(*piVar1);
  return;
}

