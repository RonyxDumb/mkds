/* Decompiled C draft; module arm9; ROM address 020f0ea0. No matching claim. */
#include "types.h"
#include "deps/020f0ea0_func_020f0ea0.h"

void func_020f0ea0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  uVar2 = uRam020f0f6c;
  uVar8 = param_1 + 0x14 & 3;
  uVar5 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar5 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 0x10 & 3;
  uVar6 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar7 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  uVar8 = uVar5;
  while ((uVar9 = uVar7, (int)uVar8 < (int)uVar7 &&
         (uVar9 = uVar6 + uVar8 * 4, uVar1 = uVar9 & 3, uVar3 = *(uint *)(uVar9 & 0xfffffffc),
         uVar9 = uVar8, (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != param_2))) {
    uVar8 = uVar8 + 1;
  }
  if ((int)uVar5 < (int)uVar9) {
    uVar8 = uVar6 + uVar5 * 4;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(uVar6 + uVar9 * 4) = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
    uVar8 = param_1 + 0x14 & 3;
    uVar5 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    *(uint *)(uVar6 + (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * 4) = param_2;
  }
  uVar8 = param_1 + 0x14 & 3;
  uVar5 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + 1;
  uVar8 = param_2 + 0x74 & 3;
  uVar5 = *(uint *)(param_2 + 0x74 & 0xfffffffc);
  *(uint *)(param_2 + 0x74) = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20 | 0x2000;
  uVar8 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar8 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 0xa8 +
          (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + 0x6c;
  uVar2 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  if (uVar8 >> uVar2 * 8 != 0 || uVar8 << uVar2 * -8 + 0x20 != 0) {
    func_020f9ca8(param_2);
  }
  *(undefined4 *)(param_2 + 0x11c) = 0;
  uVar8 = param_2 + 0x44 & 3;
  uVar2 = *(uint *)(param_2 + 0x44 & 0xfffffffc);
  uVar8 = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f0f6c & 0xfffffffc) >> (uRam020f0f6c & 3) * 8 |
          *(uint *)(uRam020f0f6c & 0xfffffffc) << (uRam020f0f6c & 3) * -8 + 0x20) + 0x1c;
  uVar2 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  pcVar4 = (code *)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(param_2);
    return;
  }
  return;
}

