/* Decompiled C draft; module arm9; ROM address 0212145c. No matching claim. */
#include "types.h"
#include "deps/0212145c_func_0212145c.h"

void func_0212145c(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar4 = uRam0212157c;
  bVar1 = false;
  uVar9 = 0;
  if (*(char *)((*(uint *)(uRam0212157c & 0xfffffffc) >> (uRam0212157c & 3) * 8 |
                *(uint *)(uRam0212157c & 0xfffffffc) << (uRam0212157c & 3) * -8 + 0x20) + 0x1f53) !=
      '\0') {
    do {
      iVar2 = func_0x0219bb50();
      uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      uVar3 = param_1 * 0x44 + uVar5 + uVar9 * 4 + 0x1d1c;
      uVar6 = uVar3 & 3;
      uVar7 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = iVar2 * 0x44 + uVar5 + uVar9 * 4 + 0x1e2c;
      uVar8 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) ==
          (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20)) {
        iVar2 = func_0x0219bb50();
        uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
        uVar3 = param_1 * 0x44 + uVar5 + uVar9 * 4 + 0x1d0c;
        uVar6 = uVar3 & 3;
        uVar7 = *(uint *)(uVar3 & 0xfffffffc);
        uVar3 = iVar2 * 0x44 + uVar5 + uVar9 * 4 + 0x1e1c;
        uVar8 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) !=
            (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20)) goto LAB_021214f4;
      }
      else {
LAB_021214f4:
        bVar1 = true;
      }
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < *(byte *)(uVar5 + 0x1f53));
  }
  iVar2 = func_0x0219bb50();
  uVar8 = *(uint *)(uRam0212157c & 0xfffffffc) >> (uRam0212157c & 3) * 8 |
          *(uint *)(uRam0212157c & 0xfffffffc) << (uRam0212157c & 3) * -8 + 0x20;
  uVar4 = param_1 * 0x44 + uVar8 + 0x1d2c;
  uVar9 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = iVar2 * 0x44 + uVar8 + 0x1e3c;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) !=
      (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20)) {
    bVar1 = true;
  }
  if (bVar1) {
    *(undefined1 *)(uVar8 + 0x19ad) = 1;
    func_0x021a2ccc();
    func_0x0219bbfc();
    *(undefined4 *)
     ((*(uint *)(uRam0212157c & 0xfffffffc) >> (uRam0212157c & 3) * 8 |
      *(uint *)(uRam0212157c & 0xfffffffc) << (uRam0212157c & 3) * -8 + 0x20) + 0x1950) = 0xb;
    return;
  }
  return;
}

