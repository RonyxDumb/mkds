/* Decompiled C draft; module arm9; ROM address 020181f0. No matching claim. */
#include "types.h"
#include "deps/020181f0_Mem_Frame_AllocFromHead.h"

uint Mem_Frame_AllocFromHead(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar5 = ~(param_3 - 1U) & (param_3 - 1U) + uVar3;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar4 = param_2 + uVar5;
  if (uVar4 <= (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    uVar1 = (uint)(param_1 + -1) & 3;
    uVar2 = *(uint *)((uint)(param_1 + -1) & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0) {
      MIi_CpuClear32(0,(undefined4 *)(uintptr_t)(uVar3),uVar4 - uVar3);
    }
    *param_1 = uVar4;
    return uVar5;
  }
  return 0;
}

