/* Decompiled C draft; module arm9; ROM address 0203bf04. No matching claim. */
#include "types.h"
#include "deps/0203bf04_func_0203bf04.h"

void func_0203bf04(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  Mem_CpuCopy8(param_1,param_2,0x30);
  Mem_CpuCopy8(param_1 + 0x30,param_2 + 0x230,uRam0203bfbc);
  uVar4 = *(uint *)(uRam0203bfc0 & 0xfffffffc) >> (uRam0203bfc0 & 3) * 8 |
          *(uint *)(uRam0203bfc0 & 0xfffffffc) << (uRam0203bfc0 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 4 & 3;
  uVar2 = *(uint *)(uVar4 + 4 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (((int)((uint)*(byte *)(uVar3 + 4) << 0x1f) < 0) &&
     (-1 < (int)((uint)*(byte *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x31)
                << 0x1c))) {
    Mem_CpuCopy8(uVar3 + 8,param_2 + 0x30,0x200);
    uVar3 = param_2 + 8U & 3;
    uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 2;
  }
  else {
    Mem_CpuFill8(param_2 + 0x30,0,0x200);
    uVar3 = param_2 + 8U & 3;
    uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xfffffffd;
  }
  bVar1 = GetWorstStarRank_from_thumb();
  *(byte *)(param_2 + 0x2f) = *(byte *)(param_2 + 0x2f) & 0xfc | bVar1 & 3;
  return;
}

