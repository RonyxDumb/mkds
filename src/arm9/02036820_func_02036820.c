/* Decompiled C draft; module arm9; ROM address 02036820. No matching claim. */
#include "types.h"
#include "deps/02036820_func_02036820.h"

void func_02036820(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = Mem_Frame_SomeFn4();
  uVar2 = Mem_FindGlobalTopParentHeapHead(param_1);
  Mem_ResizeExpHeap(uVar2,param_1,uVar1);
  return;
}

