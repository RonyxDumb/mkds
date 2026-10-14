/* Decompiled C draft; module arm9; ROM address 02036b30. No matching claim. */
#include "types.h"
#include "deps/02036b30_Mem_FreeHeap.h"

undefined4 Mem_FreeHeap(uint param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) != uRam02036b6c) {
    return uRam02036b70;
  }
  uVar1 = Mem_Exp_Free();
  return uVar1;
}

