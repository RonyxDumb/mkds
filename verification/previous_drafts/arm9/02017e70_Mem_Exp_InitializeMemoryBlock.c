/* Decompiled C draft; module arm9; ROM address 02017e70. No matching claim. */
#include "types.h"
#include "deps/02017e70_Mem_Exp_InitializeMemoryBlock.h"

undefined2 * Mem_Exp_InitializeMemoryBlock(uint param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)
           (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  *puVar3 = param_2;
  puVar3[1] = 0;
  uVar1 = param_1 + 4 & 3;
  uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(uint *)(puVar3 + 2) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - (int)(puVar3 + 8);
  *(undefined4 *)(puVar3 + 4) = 0;
  *(undefined4 *)(puVar3 + 6) = 0;
  return puVar3;
}

