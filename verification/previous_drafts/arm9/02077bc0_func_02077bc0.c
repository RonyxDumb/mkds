/* Decompiled C draft; module arm9; ROM address 02077bc0. No matching claim. */
#include "types.h"
#include "deps/02077bc0_func_02077bc0.h"

void func_02077bc0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = ComputeSomeAllocSize_0(0x20);
  uVar2 = ComputeSomeAllocSize_1(0x20);
  uVar3 = Mem_AllocateHeap(param_1,uVar1);
  uVar4 = Mem_AllocateHeap(param_1,uVar2);
  func_02017070(uRam02077c10,uRam02077c14,uVar3,uVar1,1);
  func_02017274(uRam02077c18,uVar4,uVar2,1);
  return;
}

