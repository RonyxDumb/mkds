/* Decompiled C draft; module arm9; ROM address 020179d4. No matching claim. */
#include "types.h"
#include "deps/020179d4_Mem_Exp_CoalesceFreedRegion.h"

undefined4 Mem_Exp_CoalesceFreedRegion(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_18;
  uint local_14;
  
  local_18 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar4 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  local_14 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      uVar5 = uVar4;
      if ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) <= uVar5) {
        uVar4 = param_2 + 4 & 3;
        uVar1 = *(uint *)(param_2 + 4 & 0xfffffffc);
        if (uVar5 == (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20)) {
          uVar4 = uVar5 + 4 & 3;
          uVar1 = *(uint *)(uVar5 + 4 & 0xfffffffc);
          local_14 = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + uVar5 + 0x10;
          Mem_ExpHeapMemoryBlockList_Remove(param_1);
        }
        break;
      }
      uVar4 = uVar5 + 0xc & 3;
      uVar3 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar3 = uVar5;
    } while (uVar4 != 0);
  }
  if ((uVar3 != 0) &&
     (uVar4 = uVar3 + 4 & 3, uVar5 = *(uint *)(uVar3 + 4 & 0xfffffffc),
     (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + uVar3 + 0x10 ==
     (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
     *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20))) {
    local_18 = uVar3;
    uVar3 = Mem_ExpHeapMemoryBlockList_Remove(param_1,uVar3);
  }
  if (0xf < local_14 - local_18) {
    uVar2 = Mem_Exp_InitializeMemoryBlock(&local_18,uRam02017ac8);
    Mem_ExpHeapMemoryBlockList_Insert(param_1,uVar2,uVar3);
    return 1;
  }
  return 0;
}

