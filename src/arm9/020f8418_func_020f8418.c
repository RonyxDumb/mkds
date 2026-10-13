/* Decompiled C draft; module arm9; ROM address 020f8418. No matching claim. */
#include "types.h"
#include "deps/020f8418_func_020f8418.h"

void func_020f8418(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  if (uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0) {
    uVar5 = (uint)(param_1 + 4) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    iVar6 = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * 0x1c +
            (*(uint *)(uRam020f8490 & 0xfffffffc) >> (uRam020f8490 & 3) * 8 |
            *(uint *)(uRam020f8490 & 0xfffffffc) << (uRam020f8490 & 3) * -8 + 0x20);
    uVar5 = iVar6 + 8;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    iVar4 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * 0x44 +
            (*(uint *)(uRam020f8494 & 0xfffffffc) >> (uRam020f8494 & 3) * 8 |
            *(uint *)(uRam020f8494 & 0xfffffffc) << (uRam020f8494 & 3) * -8 + 0x20);
    uVar5 = iVar4 + 0x1c;
    uVar2 = uVar5 & 3;
    uVar3 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = iVar6 + 0xc;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(iVar4 + 0x1c) =
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) -
         (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0x13;
  param_1[4] = 0x13;
  param_1[5] = 0x13;
  param_1[8] = 0;
  return;
}

