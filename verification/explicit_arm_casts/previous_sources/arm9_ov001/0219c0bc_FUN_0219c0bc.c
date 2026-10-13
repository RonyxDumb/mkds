/* Decompiled C draft; module arm9_ov001; ROM address 0219c0bc. No matching claim. */
#include "types.h"
#include "deps/0219c0bc_FUN_0219c0bc.h"

void FUN_0219c0bc(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int *piVar4;
  ushort *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [36];
  
  iVar10 = *DAT_0219c288;
  iVar8 = *(int *)(iVar10 + 0x10);
  uVar9 = (uint)*(ushort *)(iVar8 + 6);
  uVar6 = func_0x020b3f7c(*(undefined4 *)(iVar10 + 0x3c),
                          *(undefined2 *)(DAT_0219c28c + *(int *)(iVar10 + 0x60) * 2));
  func_0x0212426c(1,DAT_0219c290[4],*(undefined4 *)(*DAT_0219c288 + 0x18),uVar6,iVar8,
                  *(undefined4 *)(iVar10 + 0x34));
  iVar8 = DAT_0219c294;
  piVar4 = DAT_0219c288;
  iVar10 = *DAT_0219c288;
  if (*(int *)(iVar10 + 0x60) == 0) {
    *(undefined4 *)(*(int *)(iVar10 + 0x34) + (uint)*(ushort *)(DAT_0219c294 + 4) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uint)*(ushort *)(iVar8 + 6) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uint)*(ushort *)(iVar8 + 8) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uint)*(ushort *)(iVar8 + 10) * 0x40) = 0;
    puVar5 = DAT_0219c290;
    *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uVar9 + *DAT_0219c290) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uVar9 + puVar5[1]) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uVar9 + puVar5[2]) * 0x40) = 0;
    return;
  }
  *(undefined4 *)(*(int *)(iVar10 + 0x34) + (uint)*(ushort *)(DAT_0219c294 + 4) * 0x40) = 1;
  *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uint)*(ushort *)(iVar8 + 6) * 0x40) = 1;
  uVar1 = *(ushort *)(iVar8 + 8);
  *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uint)uVar1 * 0x40) = 1;
  uVar2 = *(ushort *)(iVar8 + 10);
  *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uint)uVar2 * 0x40) = 1;
  puVar5 = DAT_0219c290;
  *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uVar9 + *DAT_0219c290) * 0x40) = 1;
  uVar7 = (uint)puVar5[1];
  *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uVar9 + uVar7) * 0x40) = 1;
  uVar11 = (uint)puVar5[2];
  *(undefined4 *)(*(int *)(*piVar4 + 0x34) + (uVar9 + uVar11) * 0x40) = 1;
  iVar8 = func_0x0211e274(*(undefined4 *)(DAT_0219c298 + *(int *)(*piVar4 + 0x60) * 4));
  uVar3 = *(undefined2 *)(DAT_0219c29c + iVar8 * 2);
  iVar8 = *DAT_0219c288;
  func_0x02124748(uVar3,*(undefined4 *)(iVar8 + 0x24),*(undefined4 *)(iVar8 + 0x20),
                  *(undefined4 *)(iVar8 + 0x2c),1,(uint)uVar1,*(undefined4 *)(iVar8 + 0xc),
                  *(undefined4 *)(iVar8 + 0x10));
  iVar8 = *DAT_0219c288;
  iVar10 = *(int *)(*(int *)(iVar8 + 0x28) + 0xc);
  iVar8 = func_0x02124a68(uVar3,*(undefined4 *)(iVar8 + 0x24),*(undefined4 *)(iVar8 + 0x2c));
  func_0x02016468(0x1e,DAT_0219c2a0,iVar10 + iVar8 * 0x20,0x20);
  uVar6 = func_0x0211e1f0(*(undefined4 *)(DAT_0219c298 + *(int *)(*DAT_0219c288 + 0x60) * 4));
  func_0x021171a0(uVar6,*(undefined4 *)(*DAT_0219c288 + 0xc),*(undefined4 *)(*DAT_0219c288 + 0x10),
                  (uint)uVar2,9,1);
  func_0x0211e38c(*(undefined4 *)(DAT_0219c298 + *(int *)(*DAT_0219c288 + 0x60) * 4),auStack_3c);
  func_0x02116b80(auStack_3c,auStack_38);
  iVar8 = *DAT_0219c288;
  func_0x02124224(1,uVar7,*(undefined4 *)(iVar8 + 0x18),auStack_38,*(undefined4 *)(iVar8 + 0x10),
                  *(undefined4 *)(iVar8 + 0x34),9);
  func_0x0211e2f8(*(undefined4 *)(DAT_0219c298 + *(int *)(*DAT_0219c288 + 0x60) * 4),auStack_38);
  iVar8 = *DAT_0219c288;
  func_0x0212426c(1,uVar11,*(undefined4 *)(iVar8 + 0x18),auStack_38,*(undefined4 *)(iVar8 + 0x10),
                  *(undefined4 *)(iVar8 + 0x34));
  return;
}

