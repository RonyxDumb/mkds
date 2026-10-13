/* Decompiled C draft; module arm9; ROM address 0200f9c8. No matching claim. */
#include "types.h"
#include "deps/0200f9c8_Os_InsertAlarm.h"

void Os_InsertAlarm(int param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar9;
  uint uVar10;
  bool bVar12;
  undefined8 uVar13;
  longlong lVar14;
  uint uVar8;
  uint uVar11;
  
  lVar1 = CONCAT44(param_3,param_2);
  uVar11 = param_1 + 0x1cU & 3;
  uVar5 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar6 = param_1 + 0x20U & 3;
  uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  if ((uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) ||
      (uVar5 >> uVar11 * 8 != 0 || uVar5 << uVar11 * -8 + 0x20 != 0)) {
    uVar13 = Os_GetTick();
    uVar4 = (uint)((ulonglong)uVar13 >> 0x20);
    uVar6 = (uint)uVar13;
    uVar11 = param_1 + 0x28U & 3;
    uVar5 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    uVar5 = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20;
    uVar11 = param_1 + 0x24U & 3;
    uVar10 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
    lVar1 = CONCAT44(uVar5,uVar11);
    bVar12 = uVar4 <= uVar5;
    if (uVar5 == uVar4) {
      bVar12 = uVar6 <= uVar11;
    }
    if (!bVar12) {
      uVar10 = param_1 + 0x1cU & 3;
      uVar7 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      uVar8 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
      uVar10 = param_1 + 0x20U & 3;
      uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
      uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
      lVar14 = _ll_udiv(uVar6 - uVar11,uVar4 - (uVar5 + (uVar6 < uVar11)),uVar8,uVar10);
      lVar1 = (lVar14 + 1) * CONCAT44(uVar10,uVar8) + lVar1;
    }
  }
  iVar9 = (int)((ulonglong)lVar1 >> 0x20);
  *(uint *)(param_1 + 0xc) = (uint)lVar1;
  piVar2 = piRam0200fb04;
  *(int *)(param_1 + 0x10) = iVar9;
  piVar3 = piRam0200fb04;
  uVar11 = (uint)piVar2 & 3;
  uVar6 = *(uint *)((uint)piVar2 & 0xfffffffc);
  for (uVar11 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20; uVar11 != 0;
      uVar11 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) {
    uVar6 = uVar11 + 0xc & 3;
    uVar10 = *(uint *)(uVar11 + 0xc & 0xfffffffc);
    uVar4 = uVar11 + 0x10 & 3;
    uVar5 = *(uint *)(uVar11 + 0x10 & 0xfffffffc);
    if ((int)(iVar9 - ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
                      (uint)((uint)lVar1 < (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20)))) <
        0) {
      uVar6 = uVar11 + 0x14 & 3;
      uVar4 = *(uint *)(uVar11 + 0x14 & 0xfffffffc);
      *(uint *)(param_1 + 0x14) = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
      *(int *)(uVar11 + 0x14) = param_1;
      *(uint *)(param_1 + 0x18) = uVar11;
      uVar11 = param_1 + 0x14U & 3;
      uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      uVar11 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
      if (uVar11 == 0) {
        *piRam0200fb04 = param_1;
        Os_SetAlarmTimer(param_1);
        return;
      }
      *(int *)(uVar11 + 0x18) = param_1;
      return;
    }
    uVar6 = uVar11 + 0x18 & 3;
    uVar11 = *(uint *)(uVar11 + 0x18 & 0xfffffffc);
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  uVar11 = (uint)(piVar3 + 1) & 3;
  uVar6 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
  uVar11 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
  piVar3[1] = param_1;
  *(uint *)(param_1 + 0x14) = uVar11;
  if (uVar11 == 0) {
    piVar3[1] = param_1;
    *piVar3 = param_1;
    Os_SetAlarmTimer(param_1);
    return;
  }
  *(int *)(uVar11 + 0x18) = param_1;
  return;
}

