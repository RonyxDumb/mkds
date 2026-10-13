/* Decompiled C draft; module arm7; ROM address 037fa6e4. No matching claim. */
#include "types.h"
#include "deps/037fa6e4_FUN_037fa6e4.h"

void FUN_037fa6e4(int param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  longlong lVar12;
  uint uVar7;
  
  lVar1 = CONCAT44(param_3,param_2);
  uVar8 = param_1 + 0x1cU & 3;
  uVar5 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar4 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) ||
      (uVar5 >> uVar8 * 8 != 0 || uVar5 << uVar8 * -8 + 0x20 != 0)) {
    uVar11 = FUN_037fa278();
    uVar3 = (uint)((ulonglong)uVar11 >> 0x20);
    uVar4 = (uint)uVar11;
    uVar8 = param_1 + 0x24U & 3;
    uVar5 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar9 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar8 = param_1 + 0x28U & 3;
    uVar5 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    lVar1 = CONCAT44(uVar8,uVar9);
    bVar10 = uVar3 <= uVar8;
    if (uVar8 == uVar3) {
      bVar10 = uVar4 <= uVar9;
    }
    if (!bVar10) {
      uVar5 = param_1 + 0x1cU & 3;
      uVar6 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      uVar5 = param_1 + 0x20U & 3;
      uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
      uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      lVar12 = FUN_03806924(uVar4 - uVar9,uVar3 - (uVar8 + (uVar4 < uVar9)),uVar7,uVar5);
      lVar1 = (lVar12 + 1) * CONCAT44(uVar5,uVar7) + lVar1;
    }
  }
  *(longlong *)(param_1 + 0xc) = lVar1;
  uVar8 = *(uint *)((uint)DAT_037fa810 & 0xfffffffc) >> ((uint)DAT_037fa810 & 3) * 8 |
          *(uint *)((uint)DAT_037fa810 & 0xfffffffc) << ((uint)DAT_037fa810 & 3) * -8 + 0x20;
  while( true ) {
    if (uVar8 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      piVar2 = DAT_037fa810;
      uVar8 = (uint)(DAT_037fa810 + 1) & 3;
      uVar4 = *(uint *)((uint)(DAT_037fa810 + 1) & 0xfffffffc);
      uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
      DAT_037fa810[1] = param_1;
      *(uint *)(param_1 + 0x14) = uVar8;
      if (uVar8 == 0) {
        piVar2[1] = param_1;
        *piVar2 = param_1;
        FUN_037fa884(param_1);
      }
      else {
        *(int *)(uVar8 + 0x18) = param_1;
      }
      return;
    }
    uVar4 = uVar8 + 0xc & 3;
    uVar9 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
    uVar3 = uVar8 + 0x10 & 3;
    uVar5 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
    if ((int)((int)((ulonglong)lVar1 >> 0x20) -
             ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
             (uint)((uint)lVar1 < (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20)))) < 0) break;
    uVar4 = uVar8 + 0x18 & 3;
    uVar8 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
    uVar8 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
  }
  uVar4 = uVar8 + 0x14 & 3;
  uVar3 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  *(int *)(uVar8 + 0x14) = param_1;
  *(uint *)(param_1 + 0x18) = uVar8;
  uVar8 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
  if (uVar8 == 0) {
    *DAT_037fa810 = param_1;
    FUN_037fa884(param_1);
    return;
  }
  *(int *)(uVar8 + 0x18) = param_1;
  return;
}

