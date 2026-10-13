/* Decompiled C draft; module arm9; ROM address 020fb770. No matching claim. */
#include "types.h"
#include "deps/020fb770_func_020fb770.h"

void func_020fb770(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xd0U & 3;
  uVar2 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  if ((undefined4 *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) ==
      (undefined4 *)(param_1 + 0xc4)) {
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0xc4);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 200);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0xcc);
    *(undefined4 **)(param_1 + 0xd0) = (undefined4 *)(param_1 + 0x50);
  }
  uVar1 = uRam020fb7ec;
  *(undefined4 *)(param_1 + 0x260) = 0x28000;
  *(undefined4 *)(param_1 + 0x264) = uVar1;
  uVar3 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020fb7f0 & 0xfffffffc) >> (uRam020fb7f0 & 3) * 8 |
          *(uint *)(uRam020fb7f0 & 0xfffffffc) << (uRam020fb7f0 & 3) * -8 + 0x20) + 0x74;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(param_1 + 0x100) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar3 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x800000;
  *(undefined4 *)(param_1 + 0x2a4) = *(undefined4 *)(param_1 + 0x28c);
  *(undefined4 *)(param_1 + 0x2a8) = *(undefined4 *)(param_1 + 0x290);
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x294);
  uVar1 = uRam020fb7f4;
  *(undefined4 *)(param_1 + 0x27c) = 0x3000;
  *(undefined4 *)(param_1 + 0x284) = uVar1;
  return;
}

