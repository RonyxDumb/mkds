/* Decompiled C draft; module arm9; ROM address 02036bec. No matching claim. */
#include "types.h"
#include "deps/02036bec_Mem_AllocateHeap.h"

undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar2 = 0;
  if (uVar1 == uRam02036c44) {
    uVar2 = Mem_Exp_Allocate(param_1,param_2,4);
  }
  else if (uVar1 == uRam02036c48) {
    uVar2 = Mem_Frame_Allocate(param_1,param_2,4);
  }
  return uVar2;
}

