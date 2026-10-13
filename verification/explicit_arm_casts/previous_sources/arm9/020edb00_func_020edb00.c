/* Decompiled C draft; module arm9; ROM address 020edb00. No matching claim. */
#include "types.h"
#include "deps/020edb00_func_020edb00.h"

void func_020edb00(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  
  uVar4 = uRam020edb88;
  uVar5 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  if (0 < (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20)) {
    piVar6 = (int *)(param_1 + 0x20);
    do {
      *piVar6 = (*(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
                *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20) - 1;
      uVar5 = param_1 + 0x20U & 3;
      uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
      uVar1 = uVar4 & 3;
      uVar3 = *(uint *)(uVar4 & 0xfffffffc);
      uVar5 = param_1 + (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * 4 + 0x14;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x44;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      func_020f0f70((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * 0x44 +
                    (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20));
      uVar5 = param_1 + 0x20U & 3;
      uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    } while (0 < (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20));
  }
  func_020ee6a8(param_1);
  uVar5 = param_1 + 0x170U & 3;
  uVar4 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
    uVar5 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(undefined4 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x14) = 0x13;
    *(undefined4 *)(param_1 + 0x170) = 0;
  }
  return;
}

