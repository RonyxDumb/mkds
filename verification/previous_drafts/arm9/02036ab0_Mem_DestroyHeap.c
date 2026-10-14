/* Decompiled C draft; module arm9; ROM address 02036ab0. No matching claim. */
#include "types.h"
#include "deps/02036ab0_Mem_DestroyHeap.h"

uint Mem_DestroyHeap(uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 == uRam02036b28) {
    Mem_Exp_Finalize();
  }
  else if (uVar1 == uRam02036b2c) {
    Mem_Frame_Finalize();
  }
  uVar1 = Mem_FindGlobalTopParentHeapHead(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  if ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) != uRam02036b28) {
    return uRam02036b2c;
  }
  uVar1 = Mem_Exp_Free(uVar1,param_1);
  return uVar1;
}

