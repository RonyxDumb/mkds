/* Decompiled C draft; module arm9_ov001; ROM address 021972f4. No matching claim. */
#include "types.h"
#include "deps/021972f4_FUN_021972f4.h"

void FUN_021972f4(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [32];
  undefined1 auStack_2c [24];
  
  iVar5 = *DAT_021974ec;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar5 + 0x40),
                          *(undefined4 *)(DAT_021974f0 + *(int *)(iVar5 + 0x6c) * 4));
  func_0x0212426c(0,0,*(undefined4 *)(*DAT_021974ec + 0x10),uVar3,*(undefined4 *)(iVar5 + 8),
                  *(undefined4 *)(iVar5 + 0x38));
  iVar5 = DAT_021974f8;
  piVar2 = DAT_021974ec;
  uVar7 = 0;
  puVar6 = DAT_021974f4;
  do {
    iVar4 = func_0x02060228(*(undefined4 *)(iVar5 + *(int *)(*piVar2 + 0x6c) * 4),*puVar6);
    if (iVar4 == 0) {
      FUN_0219750c(uVar7 & 0xffff);
    }
    else {
      FUN_021975f4(uVar7 & 0xffff);
    }
    puVar6 = puVar6 + 1;
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 5);
  uVar7 = (uint)*(ushort *)(*(int *)(*DAT_021974ec + 8) + 6);
  iVar5 = func_0x02060228(*(undefined4 *)(DAT_021974f8 + *(int *)(*DAT_021974ec + 0x6c) * 4),5);
  piVar2 = DAT_021974ec;
  if (iVar5 == 0) {
    *(undefined4 *)(*(int *)(*DAT_021974ec + 0x38) + DAT_021974fc) = 0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x38) + DAT_02197504) = 0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x38) + (uVar7 + 2) * 0x40) = 1;
    iVar5 = *piVar2;
    func_0x02124224(0,2,*(undefined4 *)(iVar5 + 0x10),DAT_02197508,*(undefined4 *)(iVar5 + 8),
                    *(undefined4 *)(iVar5 + 0x38),7);
    *(undefined4 *)(*(int *)(*DAT_021974ec + 0x38) + (uVar7 + 4) * 0x40) = 0;
    return;
  }
  iVar5 = func_0x020601e4(*(undefined4 *)(DAT_021974f8 + *(int *)(*DAT_021974ec + 0x6c) * 4),5);
  piVar2 = DAT_021974ec;
  *(undefined4 *)(*(int *)(*DAT_021974ec + 0x38) + DAT_021974fc) = 1;
  uVar1 = *(undefined2 *)(DAT_02197500 + iVar5 * 2);
  iVar5 = *piVar2;
  func_0x02124748(uVar1,*(undefined4 *)(iVar5 + 0x2c),*(undefined4 *)(iVar5 + 0x28),
                  *(undefined4 *)(iVar5 + 0x34),0,5,*(undefined4 *)(iVar5 + 4),
                  *(undefined4 *)(iVar5 + 8));
  iVar5 = *DAT_021974ec;
  iVar4 = *(int *)(*(int *)(iVar5 + 0x30) + 0xc);
  iVar5 = func_0x02124a68(uVar1,*(undefined4 *)(iVar5 + 0x2c),*(undefined4 *)(iVar5 + 0x34));
  func_0x02016468(0xe,0x80,iVar4 + iVar5 * 0x20,0x20);
  uVar3 = func_0x020601a0(*(undefined4 *)(DAT_021974f8 + *(int *)(*DAT_021974ec + 0x6c) * 4),5);
  piVar2 = DAT_021974ec;
  *(undefined4 *)(*(int *)(*DAT_021974ec + 0x38) + DAT_02197504) = 1;
  func_0x021171a0(uVar3,*(undefined4 *)(*piVar2 + 4),*(undefined4 *)(*piVar2 + 8),6,6,0);
  func_0x02060134(*(undefined4 *)(DAT_021974f8 + *(int *)(*DAT_021974ec + 0x6c) * 4),5,auStack_50);
  func_0x02116b8c(auStack_50,auStack_4c);
  piVar2 = DAT_021974ec;
  *(undefined4 *)(*(int *)(*DAT_021974ec + 0x38) + (uVar7 + 2) * 0x40) = 1;
  iVar5 = *piVar2;
  func_0x02124224(0,2,*(undefined4 *)(iVar5 + 0x10),auStack_4c,*(undefined4 *)(iVar5 + 8),
                  *(undefined4 *)(iVar5 + 0x38),7);
  func_0x020600d0(*(undefined4 *)(DAT_021974f8 + *(int *)(*DAT_021974ec + 0x6c) * 4),5,auStack_2c);
  func_0x0214d168(auStack_4c,0,0x20);
  func_0x0214cffc(auStack_2c,auStack_4c,0x14);
  piVar2 = DAT_021974ec;
  *(undefined4 *)(*(int *)(*DAT_021974ec + 0x38) + (uVar7 + 4) * 0x40) = 1;
  iVar5 = *piVar2;
  func_0x0212426c(0,4,*(undefined4 *)(iVar5 + 0x10),auStack_4c,*(undefined4 *)(iVar5 + 8),
                  *(undefined4 *)(iVar5 + 0x38));
  return;
}

