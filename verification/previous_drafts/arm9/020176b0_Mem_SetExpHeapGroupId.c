/* Decompiled C draft; module arm9; ROM address 020176b0. No matching claim. */
#include "types.h"
#include "deps/020176b0_Mem_SetExpHeapGroupId.h"

undefined2 Mem_SetExpHeapGroupId(int param_1,undefined2 param_2)

{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)(param_1 + 0x34);
  *(undefined2 *)(param_1 + 0x34) = param_2;
  return uVar1;
}

