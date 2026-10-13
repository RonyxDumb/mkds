/* Decompiled C draft; module arm9; ROM address 020dc474. No matching claim. */
#include "types.h"
#include "deps/020dc474_func_020dc474.h"

void func_020dc474(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  bool bVar14;
  uint local_20 [2];
  uint local_18;
  
  uVar5 = param_1 + 0xcU & 3;
  uVar7 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar9 = param_1 + 0xa8U & 3;
  uVar3 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  uVar10 = param_1 + 0x1fcU & 3;
  uVar13 = *(uint *)(param_1 + 0x1fcU & 0xfffffffc);
  uVar13 = uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20;
  iVar4 = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) -
          (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20);
  uVar5 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar9 = param_1 + 0xa0U & 3;
  uVar10 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  lVar2 = (longlong)(int)uVar13 * (longlong)(int)uVar13;
  iVar8 = (int)((ulonglong)lVar2 >> 0x20);
  iVar11 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) -
           (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20);
  lVar1 = (longlong)iVar11 * (longlong)iVar11 + (longlong)iVar4 * (longlong)iVar4;
  iVar4 = (int)((ulonglong)lVar1 >> 0x20);
  bVar14 = (uint)lVar1 < (uint)lVar2;
  if ((int)(iVar4 - (iVar8 + (uint)bVar14)) < 0 ==
      (SBORROW4(iVar4,iVar8) != SBORROW4(iVar4 - iVar8,(uint)bVar14))) {
    VecFx32_Subtract(param_1 + 0xa0,param_1 + 4,local_20);
    uVar5 = param_1 + 0x10U & 3;
    uVar9 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    *(uint *)(param_1 + 0x10) =
         (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
         ((local_20[0] << 2) >> 0xc |
         (((int)local_20[0] >> 0x1f) << 2 | local_20[0] >> 0x1e) << 0x14);
    uVar5 = param_1 + 0x18U & 3;
    uVar9 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    *(uint *)(param_1 + 0x18) =
         (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
         ((local_18 << 2) >> 0xc | (((int)local_18 >> 0x1f) << 2 | local_18 >> 0x1e) << 0x14);
    uVar9 = uRam020dc5d8;
    uVar5 = param_1 + 0x18U & 3;
    uVar10 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar3 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
    uVar5 = param_1 + 0x10U & 3;
    uVar10 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar5 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar5 * (longlong)(int)uVar5 +
            (longlong)(int)uVar3 * (longlong)(int)uVar3;
    piVar12 = (int *)(param_1 + 0x10);
    piVar6 = (int *)(param_1 + 0x18);
    if ((int)(uint)((uint)lVar1 < 0x1000000) <= (int)((ulonglong)lVar1 >> 0x20)) {
      uVar5 = param_1 + 0x10U & 3;
      uVar10 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      uVar5 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
      lVar1 = (ulonglong)uRam020dc5d8 * (ulonglong)uVar5;
      *piVar12 = (*(uint *)((uint)piVar12 & 0xfffffffc) >> ((uint)piVar12 & 3) * 8 |
                 *(uint *)((uint)piVar12 & 0xfffffffc) << ((uint)piVar12 & 3) * -8 + 0x20) -
                 ((uint)lVar1 >> 0xc |
                 (((int)uVar5 >> 0x1f) * uRam020dc5d8 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000)
      ;
      uVar5 = param_1 + 0x18U & 3;
      uVar10 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
      uVar5 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
      lVar1 = (ulonglong)uVar9 * (ulonglong)uVar5;
      *piVar6 = (*(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
                *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20) -
                ((uint)lVar1 >> 0xc |
                (((int)uVar5 >> 0x1f) * uVar9 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    }
    uVar5 = param_1 + 4U & 3;
    uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar9 = param_1 + 0x10U & 3;
    uVar10 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    *(uint *)(param_1 + 4) =
         (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) +
         (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20);
    uVar5 = param_1 + 0xcU & 3;
    uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar9 = param_1 + 0x18U & 3;
    uVar10 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    *(uint *)(param_1 + 0xc) =
         (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) +
         (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20);
  }
  uVar5 = param_1 + 0x84U & 3;
  uVar9 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  bVar14 = 0xb3 < uVar5;
  if (bVar14) {
    uVar5 = 0;
  }
  if (bVar14) {
    *(short *)(param_1 + 0x90) = (short)uVar5;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

