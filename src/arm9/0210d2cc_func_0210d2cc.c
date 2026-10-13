/* Decompiled C draft; module arm9; ROM address 0210d2cc. No matching claim. */
#include "types.h"
#include "deps/0210d2cc_func_0210d2cc.h"

void func_0210d2cc(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar4 = uRam0210d488;
  uVar8 = iRam0210d480 + 0x10U & 3;
  uVar2 = *(uint *)(iRam0210d480 + 0x10U & 0xfffffffc);
  if (uVar2 >> uVar8 * 8 == 0 && uVar2 << uVar8 * -8 + 0x20 == 0) {
    return;
  }
  if (*(uint *)((uint)puRam0210d484 & 0xfffffffc) >> ((uint)puRam0210d484 & 3) * 8 != 0 ||
      *(uint *)((uint)puRam0210d484 & 0xfffffffc) << ((uint)puRam0210d484 & 3) * -8 + 0x20 != 0) {
    for (uVar8 = *(uint *)(uRam0210d488 & 0xfffffffc) >> (uRam0210d488 & 3) * 8 |
                 *(uint *)(uRam0210d488 & 0xfffffffc) << (uRam0210d488 & 3) * -8 + 0x20; uVar8 != 0;
        uVar8 = IntrusiveListWrapper_NextItem(uVar4,uVar8)) {
      func_0210cc3c(uVar8);
    }
    *puRam0210d484 = 0;
  }
  func_0210e280(uRam0210d48c);
  uVar9 = uRam0210d490;
  uVar8 = *(uint *)(uRam0210d490 & 0xfffffffc) >> (uRam0210d490 & 3) * 8 |
          *(uint *)(uRam0210d490 & 0xfffffffc) << (uRam0210d490 & 3) * -8 + 0x20;
  uVar4 = uRam0210d490;
  uVar2 = uRam0210d494;
  while (uRam0210d490 = uVar4, uRam0210d494 = uVar2, uVar8 != 0) {
    func_0210ca4c(uVar8);
    uVar4 = uVar8 + 0x18 & 3;
    uVar2 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    if (uVar4 != 3) {
      func_0210bc54(uVar4 * 0xc + uVar9,uVar8);
      *(undefined4 *)(uVar8 + 0x18) = 3;
    }
    uVar4 = uRam0210d490;
    uVar2 = uRam0210d494;
    uVar8 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
  }
  uVar9 = *(uint *)((uint)puRam0210d498 & 0xfffffffc) >> ((uint)puRam0210d498 & 3) * 8 |
          *(uint *)((uint)puRam0210d498 & 0xfffffffc) << ((uint)puRam0210d498 & 3) * -8 + 0x20;
  uVar8 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  piVar1 = piRam0210d49c;
  while (piRam0210d49c = piVar1, uVar8 != 0) {
    uVar6 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
            *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
    uVar3 = uVar9 & 3;
    uVar9 = uVar9 + 1;
    if (uVar3 == uVar6) {
      func_0210ca4c(uVar8);
    }
    else if (((uVar9 & 1) == (uVar6 & 1)) &&
            (uVar3 = uVar8 + 0xc & 3, uVar6 = *(uint *)(uVar8 + 0xc & 0xfffffffc),
            uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20, uVar3 != 0)) {
      do {
        if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
          uVar6 = uVar8 + 0x30 & 3;
          uVar7 = *(uint *)(uVar8 + 0x30 & 0xfffffffc);
          (*(code *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20))(uVar8,uVar3,0);
        }
        uVar3 = IntrusiveListWrapper_NextItem(uVar8 + 0xc,uVar3);
      } while (uVar3 != 0);
    }
    uVar3 = uVar8 + 0x18 & 3;
    uVar6 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
    uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
    if (uVar3 != 3) {
      func_0210bc54(uVar3 * 0xc + uVar4,uVar8);
      *(undefined4 *)(uVar8 + 0x18) = 3;
    }
    piVar1 = piRam0210d49c;
    uVar8 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  }
  iVar5 = (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
          *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) + 1;
  *piVar1 = iVar5;
  if (iVar5 == 4) {
    *piVar1 = 0;
  }
  *puRam0210d498 = 0;
  return;
}

