/* Decompiled C draft; module arm9; ROM address 0212c9d4. No matching claim. */
#include "types.h"
#include "deps/0212c9d4_func_0212c9d4.h"

void func_0212c9d4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  uint uVar11;
  
  iVar5 = iRam0212cad0;
  uVar6 = param_1 + 0x18U & 3;
  uVar10 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar11 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x1cU & 3;
  uVar10 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  iVar3 = uVar11 * (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20);
  uVar6 = param_1 + 0xcU & 3;
  uVar8 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar10 = param_1 + 0x10U & 3;
  uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  iVar13 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + iVar3;
  iVar12 = (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) + iVar3;
  if (*(uint *)(uRam0212cac8 & 0xfffffffc) >> (uRam0212cac8 & 3) * 8 == 0 &&
      *(uint *)(uRam0212cac8 & 0xfffffffc) << (uRam0212cac8 & 3) * -8 + 0x20 == 0) {
    DC_InvalidateRangeNoClean(iVar13,uVar11);
    DC_InvalidateRangeNoClean(iVar12,uVar11);
    uVar6 = param_1 + 0x38U & 3;
    uVar8 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
    uVar10 = param_1 + 8U & 3;
    uVar9 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar7 = param_1 + 0x34U & 3;
    uVar14 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
    (*(code *)(uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20))
              (iVar13,iVar12,uVar11,uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20,
               uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
  }
  else {
    iVar4 = (*(uint *)((uint)piRam0212cacc & 0xfffffffc) >> ((uint)piRam0212cacc & 3) * 8 |
            *(uint *)((uint)piRam0212cacc & 0xfffffffc) << ((uint)piRam0212cacc & 3) * -8 + 0x20) *
            0x14;
    *(int *)(iRam0212cad0 + iVar4) = param_1;
    iVar5 = iVar5 + iVar4;
    *(uint *)(iVar5 + 4) = uVar11;
    *(int *)(iVar5 + 8) = iVar3;
    *(int *)(iVar5 + 0xc) = iVar13;
    uVar2 = uRam0212cad4;
    *(int *)(iVar5 + 0x10) = iVar12;
    Os_MessageQueue_Send(uVar2,iVar5,0);
    piVar1 = piRam0212cacc;
    uVar6 = *(uint *)((uint)piRam0212cacc & 0xfffffffc) >> ((uint)piRam0212cacc & 3) * 8 |
            *(uint *)((uint)piRam0212cacc & 0xfffffffc) << ((uint)piRam0212cacc & 3) * -8 + 0x20;
    iVar5 = uVar6 + 1;
    *piRam0212cacc = iVar5;
    bVar15 = SBORROW4(iVar5,8);
    if (7 < iVar5) {
      iVar5 = 0;
    }
    if ((int)(uVar6 - 7) < 0 == bVar15) {
      *piVar1 = iVar5;
    }
  }
  uVar6 = param_1 + 0x1cU & 3;
  uVar10 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) + 1;
  uVar6 = param_1 + 0x1cU & 3;
  uVar8 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar10 = param_1 + 0x30U & 3;
  uVar7 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  if ((int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) <=
      (int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}

