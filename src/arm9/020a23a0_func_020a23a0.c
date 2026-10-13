/* Decompiled C draft; module arm9; ROM address 020a23a0. No matching claim. */
#include "types.h"
#include "deps/020a23a0_func_020a23a0.h"

int func_020a23a0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar3;
  
  uVar3 = param_1 + 0x590U & 3;
  uVar2 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x20 & 3;
  uVar4 = *(uint *)(uVar3 + 0x20 & 0xfffffffc);
  uVar3 = iRam020a23c8 + uVar6 * 4;
  uVar1 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar6 * 0xc + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x48;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  return (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
}

