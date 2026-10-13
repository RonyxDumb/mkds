/* Decompiled C draft; module arm9; ROM address 021113ac. No matching claim. */
#include "types.h"
#include "deps/021113ac_func_021113ac.h"

void func_021113ac(short *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar1,uRam021113e4);
  *puRam021113e8 = uVar2;
  uVar2 = Mem_AllocateHeap(uVar1,uRam021113e4);
  *puRam021113ec = uVar2;
  func_021115b0(uVar1,(int)*param_1);
  return;
}

