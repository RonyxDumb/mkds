/* Decompiled C draft; module arm9; ROM address 0210e128. No matching claim. */
#include "types.h"
#include "deps/0210e128_GetSomeSndPlayer.h"

uint GetSomeSndPlayer(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar6;
  
  uVar8 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar11 = 0xffffffff;
  uVar7 = 0;
  uVar10 = 0xffffffff;
  uVar2 = 0;
  uVar6 = param_1 + 8 & 3;
  uVar5 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar3 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  for (uVar8 = uVar3; uVar5 = 0xffffffff,
      (int)uVar8 <
      (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20); uVar8 = uVar8 + 1) {
    uVar7 = uVar6;
    if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
      uVar7 = uVar6 + 4 & 3;
      uVar5 = *(uint *)(uVar6 + 4 & 0xfffffffc);
      uVar7 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
      if ((int)uVar11 < (int)uVar7) {
        uVar2 = uVar6;
        uVar11 = uVar7;
        uVar10 = uVar8;
      }
      uVar7 = 0;
    }
    uVar5 = uVar8;
    if (uVar7 != 0) break;
    uVar5 = param_1 + 0x10 & 3;
    uVar9 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
    uVar6 = uVar6 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
  }
  uVar8 = uVar5;
  if (uVar7 == 0) {
    uVar6 = param_1 + 0xc & 3;
    uVar9 = *(uint *)(param_1 + 0xc & 0xfffffffc);
    uVar9 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
    uVar6 = 0;
    if (0 < (int)uVar3) {
      do {
        uVar8 = uVar6;
        uVar7 = uVar9;
        if (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 != 0 ||
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20 != 0) {
          uVar6 = uVar9 + 4 & 3;
          uVar7 = *(uint *)(uVar9 + 4 & 0xfffffffc);
          uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
          uVar7 = 0;
          if ((int)uVar11 < (int)uVar6) {
            uVar2 = uVar9;
            uVar10 = uVar8;
            uVar11 = uVar6;
          }
        }
        if (uVar7 != 0) break;
        uVar1 = param_1 + 0x10 & 3;
        uVar4 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
        uVar6 = uVar8 + 1;
        uVar9 = uVar9 + (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
        uVar8 = uVar5;
      } while ((int)uVar6 < (int)uVar3);
    }
  }
  if (uVar7 == 0) {
    func_0212c6f0(uVar2,0);
    uVar7 = uVar2;
    uVar8 = uVar10;
  }
  *(undefined4 *)(uVar7 + 4) = 0;
  func_0212c6a0((undefined4 *)(uintptr_t)(uVar7));
  *(uint *)(param_1 + 4) = uVar8;
  uVar8 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(uint *)(param_1 + 4) = (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 1;
  uVar8 = param_1 + 0x10 & 3;
  uVar6 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar7 + (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20);
  uVar8 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  if ((int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) <=
      (int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 4) = 0;
    uVar8 = param_1 + 0xc & 3;
    uVar6 = *(uint *)(param_1 + 0xc & 0xfffffffc);
    *(uint *)(param_1 + 8) = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  }
  return uVar7;
}

