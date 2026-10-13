/* Decompiled C draft; module arm9; ROM address 02151640. No matching claim. */
#include "types.h"
#include "deps/02151640_func_02151640.h"

bool func_02151640(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint local_18;
  uint local_14 [2];
  
  iVar1 = FUN_02151620();
  if (iVar1 == 0) {
    return false;
  }
  Mem_CpuCopy8(param_1,&local_18,4);
  Mem_CpuCopy8(param_2,local_14,4);
  if ((local_18 | local_14[0]) == 0xfffffffe) {
    return false;
  }
  return (local_18 & ~local_14[0]) != 0;
}

