/* Decompiled C draft; module arm9; ROM address 0201889c. No matching claim. */
#include "types.h"
#include "deps/0201889c_func_0201889c.h"

undefined4 func_0201889c(int param_1,code *param_2)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar8;
  uint uVar2;
  uint uVar7;
  
  func_0214c48c();
  iVar8 = 0;
  if (*(short *)(param_1 + 0x32) != 0) {
    iVar4 = 0;
    do {
      uVar6 = param_1 + 0x2cU & 3;
      uVar1 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20;
      uVar5 = 0;
      uVar6 = uVar2 + iVar4;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar7 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
      uVar2 = uVar2 + iVar4;
      uVar6 = uVar7 + 0x10 & 3;
      uVar1 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
      uVar6 = uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20;
      if (uVar6 != 0) {
        uVar1 = uVar7 + 4 & 3;
        uVar3 = *(uint *)(uVar7 + 4 & 0xfffffffc);
        uVar5 = (*param_2)(uVar6,((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xf) == 2);
        uVar6 = uVar7 + 0xc & 3;
        uVar3 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
        uVar1 = uVar7 + 0x10 & 3;
        uVar7 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
        SomeDmaCopy_0((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) +
                      (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20),uVar5,
                      uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
      }
      *(undefined4 *)(uVar2 + 8) = uVar5;
      iVar8 = iVar8 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar8 < (int)(uint)*(ushort *)(param_1 + 0x32));
  }
  func_0214c3c0();
  return 1;
}

