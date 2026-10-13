/* Decompiled C draft; module arm9; ROM address 020f8498. No matching claim. */
#include "types.h"
#include "deps/020f8498_func_020f8498.h"

void func_020f8498(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = (uint)(param_1 + 4) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  iVar6 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 0x1c +
          (*(uint *)(uRam020f8504 & 0xfffffffc) >> (uRam020f8504 & 3) * 8 |
          *(uint *)(uRam020f8504 & 0xfffffffc) << (uRam020f8504 & 3) * -8 + 0x20);
  uVar2 = iVar6 + 8;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar5 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * 0x44 +
          (*(uint *)(uRam020f8508 & 0xfffffffc) >> (uRam020f8508 & 3) * 8 |
          *(uint *)(uRam020f8508 & 0xfffffffc) << (uRam020f8508 & 3) * -8 + 0x20);
  uVar2 = iVar5 + 0x1c;
  uVar4 = uVar2 & 3;
  uVar3 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = iVar6 + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(iVar5 + 0x1c) =
       (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) -
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0x13;
  param_1[4] = 0x13;
  param_1[5] = 0x13;
  param_1[8] = 0;
  return;
}

