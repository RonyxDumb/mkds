/* Decompiled C draft; module arm9; ROM address 02018174. No matching claim. */
#include "types.h"
#include "deps/02018174_Mem_Frame_AllocFromTail.h"

uint Mem_Frame_AllocFromTail(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar3 = ~(param_3 - 1U) & uVar4 - param_2;
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) <= uVar3) {
    uVar1 = param_1 - 4 & 3;
    uVar2 = *(uint *)(param_1 - 4 & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0) {
      MIi_CpuClear32(0,(undefined4 *)(uintptr_t)(uVar3),uVar4 - uVar3);
    }
    *(uint *)(param_1 + 4) = uVar3;
    return uVar3;
  }
  return 0;
}

