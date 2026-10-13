/* Decompiled C draft; module arm9; ROM address 020efa60. No matching claim. */
#include "types.h"
#include "deps/020efa60_func_020efa60.h"

void func_020efa60(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar9 = uRam020efb7c;
  uVar11 = param_1 + 0x20U & 3;
  uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  *(uint *)(param_1 + 0x20) = (uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) - 1;
  uVar11 = param_1 + 0x20U & 3;
  uVar8 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar7 = uVar9 & 3;
  uVar5 = *(uint *)(uVar9 & 0xfffffffc);
  uVar11 = param_1 + (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) * 4 + 0x14;
  uVar9 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar8 = uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20;
  uVar11 = uVar8 + 0x44 & 3;
  uVar9 = *(uint *)(uVar8 + 0x44 & 0xfffffffc);
  uVar11 = (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) * 0xa8 +
           (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0x24;
  uVar9 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  func_020efb84(param_1,uVar8);
  iVar2 = (*(code *)(uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20))(param_1,uVar8);
  if ((iVar2 == 0) &&
     (uVar11 = param_1 + 0xcU & 3, uVar9 = *(uint *)(param_1 + 0xcU & 0xfffffffc),
     uVar11 = (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + 0x208, uVar9 = uVar11 & 3,
     uVar11 = *(uint *)(uVar11 & 0xfffffffc),
     uVar11 >> uVar9 * 8 != 0 || uVar11 << uVar9 * -8 + 0x20 != 0)) {
    param_2 = 0;
    *(ushort *)(uVar8 + 0x78) = *(ushort *)(uVar8 + 0x78) | *puRam020efb80;
  }
  uVar11 = uVar8 + 0x44 & 3;
  uVar9 = *(uint *)(uVar8 + 0x44 & 0xfffffffc);
  iVar2 = (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020efb7c & 0xfffffffc) >> (uRam020efb7c & 3) * 8 |
          *(uint *)(uRam020efb7c & 0xfffffffc) << (uRam020efb7c & 3) * -8 + 0x20);
  uVar11 = uVar8 + 0xe0 & 3;
  uVar13 = *(uint *)(uVar8 + 0xe0 & 0xfffffffc);
  uVar9 = uVar8 + 0xd0 & 3;
  uVar3 = *(uint *)(uVar8 + 0xd0 & 0xfffffffc);
  uVar7 = iVar2 + 0x5cU & 3;
  uVar6 = *(uint *)(iVar2 + 0x5cU & 0xfffffffc);
  uVar5 = iVar2 + 0xa4U & 3;
  uVar10 = *(uint *)(iVar2 + 0xa4U & 0xfffffffc);
  uVar1 = iVar2 + 0x30U & 3;
  uVar12 = *(uint *)(iVar2 + 0x30U & 0xfffffffc);
  uVar4 = (*(code *)(uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20))
                    (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20,
                     (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) << 1,
                     uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,
                     uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20,0x1f);
  *(undefined4 *)(uVar8 + 0xd4) = uVar4;
  uVar11 = uVar8 + 0x74 & 3;
  uVar9 = *(uint *)(uVar8 + 0x74 & 0xfffffffc);
  if (((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) & 0x400000) != 0) {
    func_020f90bc(uVar8);
  }
  uVar11 = uVar8 + 0x44 & 3;
  uVar7 = *(uint *)(uVar8 + 0x44 & 0xfffffffc);
  uVar9 = uVar8 + 0x74 & 3;
  uVar5 = *(uint *)(uVar8 + 0x74 & 0xfffffffc);
  uVar11 = (uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) * 0xa8 +
           (*(uint *)(uRam020efb7c & 0xfffffffc) >> (uRam020efb7c & 3) * 8 |
           *(uint *)(uRam020efb7c & 0xfffffffc) << (uRam020efb7c & 3) * -8 + 0x20) + 0x28;
  uVar7 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  if (((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & 0x180000) == 0) {
    *(uint *)(uVar8 + 0x120) = uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20;
  }
  if (param_2 != 0) {
    uVar11 = param_1 + 0x10U & 3;
    uVar9 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    DriverContext_SomeFn_0(uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20);
    return;
  }
  return;
}

