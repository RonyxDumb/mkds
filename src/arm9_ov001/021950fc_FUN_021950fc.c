/* Decompiled C draft; module arm9_ov001; ROM address 021950fc. No matching claim. */
#include "types.h"
#include "deps/021950fc_FUN_021950fc.h"

void FUN_021950fc(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  ushort *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [32];
  
  iVar11 = param_1 * 4;
  uVar5 = *(undefined4 *)(DAT_02195384 + iVar11);
  iVar6 = func_0x020603bc(*(undefined4 *)(DAT_0219538c + *(int *)(*DAT_02195388 + 0x78) * 4),uVar5);
  piVar3 = DAT_02195388;
  iVar12 = param_1 * 2;
  uVar10 = (uint)*(ushort *)(DAT_02195390 + iVar12);
  *(undefined4 *)(*(int *)(*DAT_02195388 + 0x54) + uVar10 * 0x40) = 1;
  iVar8 = *piVar3;
  func_0x02124748(*(undefined2 *)(DAT_02195394 + *(int *)(iVar8 + 0x78) * 2),
                  *(undefined4 *)(iVar8 + 0x2c),*(undefined4 *)(iVar8 + 0x28),
                  *(undefined4 *)(iVar8 + 0x34),1,uVar10,*(undefined4 *)(iVar8 + 0x18),
                  *(undefined4 *)(iVar8 + 0x1c));
  func_0x02124a20(uVar10,*(ushort *)(DAT_02195398 + iVar6 * 2) & 0xff,
                  *(undefined4 *)(*DAT_02195388 + 0x18),*(undefined4 *)(*DAT_02195388 + 0x1c));
  iVar6 = func_0x02060414(*(undefined4 *)(DAT_0219538c + *(int *)(*DAT_02195388 + 0x78) * 4),uVar5);
  uVar1 = *(ushort *)(DAT_0219539c + iVar11);
  *(undefined4 *)(*(int *)(*DAT_02195388 + 0x54) + (uint)uVar1 * 0x40) = 1;
  uVar2 = *(undefined2 *)(DAT_021953a0 + iVar6 * 2);
  iVar6 = *DAT_02195388;
  func_0x02124748(uVar2,*(undefined4 *)(iVar6 + 0x3c),*(undefined4 *)(iVar6 + 0x38),
                  *(undefined4 *)(iVar6 + 0x44),1,(uint)uVar1,*(undefined4 *)(iVar6 + 0x18),
                  *(undefined4 *)(iVar6 + 0x1c));
  iVar6 = *DAT_02195388;
  iVar8 = *(int *)(*(int *)(iVar6 + 0x40) + 0xc);
  iVar6 = func_0x02124a68(uVar2,*(undefined4 *)(iVar6 + 0x3c),*(undefined4 *)(iVar6 + 0x44));
  func_0x02016468(0x1e,(uint)*(ushort *)(DAT_021953a4 + iVar12) << 5,iVar8 + iVar6 * 0x20,0x20);
  uVar7 = func_0x020603e8(*(undefined4 *)(DAT_0219538c + *(int *)(*DAT_02195388 + 0x78) * 4),uVar5);
  piVar3 = DAT_02195388;
  uVar1 = *(ushort *)(DAT_021953a8 + iVar11);
  *(undefined4 *)(*(int *)(*DAT_02195388 + 0x54) + (uint)uVar1 * 0x40) = 1;
  func_0x021171a0(uVar7,*(undefined4 *)(*piVar3 + 0x18),*(undefined4 *)(*piVar3 + 0x1c),(uint)uVar1,
                  *(undefined2 *)(DAT_021953ac + iVar12),1);
  uVar10 = (uint)*(ushort *)(*(int *)(*DAT_02195388 + 0x1c) + 6);
  func_0x02060318(*(undefined4 *)(DAT_0219538c + *(int *)(*DAT_02195388 + 0x78) * 4),uVar5,
                  (undefined4)(uintptr_t)(auStack_38));
  func_0x02116b8c((undefined4)(uintptr_t)(auStack_38),(undefined4)(uintptr_t)(auStack_34));
  piVar3 = DAT_02195388;
  uVar1 = *(ushort *)(DAT_021953b0 + iVar12);
  *(undefined4 *)(*(int *)(*DAT_02195388 + 0x54) + (uVar10 + uVar1) * 0x40) = 1;
  iVar6 = *piVar3;
  func_0x02124224(1,(uint)uVar1,*(undefined4 *)(iVar6 + 0x24),auStack_34,
                  *(undefined4 *)(iVar6 + 0x1c),*(undefined4 *)(iVar6 + 0x54),7);
  sVar4 = func_0x02060390(*(undefined4 *)(DAT_0219538c + *(int *)(*piVar3 + 0x78) * 4),uVar5);
  func_0x02124fac(sVar4,(int)(uintptr_t)(auStack_34));
  uVar1 = *(ushort *)(DAT_021953b4 + iVar12);
  *(undefined4 *)(*(int *)(*piVar3 + 0x54) + (uVar10 + uVar1) * 0x40) = 1;
  iVar6 = *piVar3;
  func_0x02124248(1,(uint)uVar1,*(undefined4 *)(iVar6 + 0x24),auStack_34,
                  *(undefined4 *)(iVar6 + 0x1c),*(undefined4 *)(iVar6 + 0x54),7);
  piVar3 = DAT_02195388;
  iVar8 = 0;
  iVar6 = param_1 * 6;
  puVar9 = (ushort *)(DAT_021953b8 + iVar6);
  do {
    *(undefined4 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar9 * 0x40) = 0;
    puVar9 = puVar9 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 3);
  if (sVar4 == 0) {
    *(undefined4 *)(*(int *)(*piVar3 + 0x54) + (uint)*(ushort *)(DAT_021953b8 + iVar6) * 0x40) = 1;
  }
  else if (sVar4 == 1) {
    *(undefined4 *)(*(int *)(*piVar3 + 0x54) + (uint)*(ushort *)(DAT_021953bc + iVar6) * 0x40) = 1;
  }
  else {
    *(undefined4 *)(*(int *)(*piVar3 + 0x54) + (uint)*(ushort *)(DAT_021953c0 + iVar6) * 0x40) = 1;
  }
  piVar3 = DAT_02195388;
  iVar11 = (uVar10 + *(ushort *)(DAT_021953c4 + iVar12)) * 0x40;
  iVar8 = 0;
  *(undefined4 *)(*(int *)(*DAT_02195388 + 0x54) + iVar11) = 0;
  puVar13 = (ushort *)(DAT_021953c8 + iVar6);
  puVar9 = puVar13;
  do {
    *(undefined4 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar9 * 0x40) = 0;
    puVar9 = puVar9 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 3);
  iVar6 = func_0x02060364(*(undefined4 *)(DAT_0219538c + *(int *)(*piVar3 + 0x78) * 4),uVar5);
  piVar3 = DAT_02195388;
  if (iVar6 < 5) {
    *(undefined4 *)(*(int *)(*DAT_02195388 + 0x54) + iVar11) = 1;
    iVar8 = *piVar3;
    func_0x0212426c(1,*(undefined2 *)(DAT_021953c4 + param_1 * 2),*(undefined4 *)(iVar8 + 0x24),
                    *(undefined4 *)(DAT_021953cc + iVar6 * 4),*(undefined4 *)(iVar8 + 0x1c),
                    *(undefined4 *)(iVar8 + 0x54));
    return;
  }
  *(undefined4 *)(*(int *)(*DAT_02195388 + 0x54) + (uint)puVar13[iVar6 + -5] * 0x40) = 1;
  return;
}

