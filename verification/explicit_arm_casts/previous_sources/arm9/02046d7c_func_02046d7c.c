/* Decompiled C draft; module arm9; ROM address 02046d7c. No matching claim. */
#include "types.h"
#include "deps/02046d7c_func_02046d7c.h"

void func_02046d7c(void)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  
  iVar3 = func_0214e6d4();
  uVar7 = *(uint *)(uRam02046e20 & 0xfffffffc) >> (uRam02046e20 & 3) * 8 |
          *(uint *)(uRam02046e20 & 0xfffffffc) << (uRam02046e20 & 3) * -8 + 0x20;
  iVar6 = uVar7 + iVar3 * 8;
  uVar2 = *(undefined2 *)(iVar6 + 2);
  *(undefined2 *)(uVar7 + 0x28) = *(undefined2 *)(uVar7 + iVar3 * 8);
  *(undefined2 *)(uVar7 + 0x2a) = uVar2;
  uVar2 = *(undefined2 *)(iVar6 + 6);
  *(undefined2 *)(uVar7 + 0x2c) = *(undefined2 *)(iVar6 + 4);
  *(undefined2 *)(uVar7 + 0x2e) = uVar2;
  func_0214e334(uVar7 + 0x28,uVar7 + 0x28);
  uVar5 = *(uint *)(uRam02046e20 & 0xfffffffc) >> (uRam02046e20 & 3) * 8 |
          *(uint *)(uRam02046e20 & 0xfffffffc) << (uRam02046e20 & 3) * -8 + 0x20;
  uVar7 = uVar5 + 0x30;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if ((int)((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) << 0x1e) < 0) {
    uVar5 = uVar5 + 0x3c;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = Struct59C4Sub_SomeFn_1(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
    uVar7 = (uint)((ulonglong)uVar8 >> 0x20);
    if (0x14 < (uint)uVar8) {
      uVar7 = 1;
    }
    uVar5 = *(uint *)(uRam02046e20 & 0xfffffffc) >> (uRam02046e20 & 3) * 8 |
            *(uint *)(uRam02046e20 & 0xfffffffc) << (uRam02046e20 & 3) * -8 + 0x20;
    if ((uint)uVar8 < 0x15) {
      uVar7 = 0;
    }
    uVar4 = uVar5 + 0x30;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar5 + 0x30) =
         (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffff7 | (uVar7 & 1) << 3;
    return;
  }
  return;
}

