/* Decompiled C draft; module arm9_ov001; ROM address 02194d78. No matching claim. */
#include "types.h"
#include "deps/02194d78_FUN_02194d78.h"

void FUN_02194d78(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  uVar5 = (uint)*(ushort *)(*(int *)(*DAT_02194ef0 + 0x1c) + 6);
  iVar2 = FUN_02194d04(*(undefined4 *)(*DAT_02194ef0 + 0x78));
  if (iVar2 == 0) {
    func_0x02016468(0x1b,DAT_02194ef4,*(int *)(*DAT_02194ef0 + 0x4c) + DAT_02194ef4,DAT_02194ef8);
    piVar1 = DAT_02194ef0;
    iVar6 = 0;
    *(undefined4 *)(*(int *)(*DAT_02194ef0 + 0x54) + (uint)*(ushort *)(DAT_02194efc + 6) * 0x40) = 0
    ;
    iVar2 = DAT_02194f00;
    do {
      *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*(ushort *)(iVar2 + 0x12) * 0x40) = 0;
      iVar2 = iVar2 + 2;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*(ushort *)(DAT_02194f04 + 6) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uVar5 + *(ushort *)(DAT_02194f08 + 6)) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uVar5 + *(ushort *)(DAT_02194f0c + 6)) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uVar5 + *(ushort *)(DAT_02194f10 + 6)) * 0x40) = 0;
  }
  else {
    func_0x02016468(0x1b,DAT_02194ef4,*(int *)(*DAT_02194ef0 + 0x48) + 0xc + DAT_02194ef4,
                    DAT_02194ef8);
    piVar1 = DAT_02194ef0;
    *(undefined4 *)(*(int *)(*DAT_02194ef0 + 0x54) + (uint)*(ushort *)(DAT_02194efc + 6) * 0x40) = 1
    ;
    iVar6 = 0;
    iVar2 = DAT_02194f00;
    do {
      *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*(ushort *)(iVar2 + 0x12) * 0x40) = 1;
      iVar2 = iVar2 + 2;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*(ushort *)(DAT_02194f04 + 6) * 0x40) = 1;
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uVar5 + *(ushort *)(DAT_02194f08 + 6)) * 0x40) = 1;
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uVar5 + *(ushort *)(DAT_02194f0c + 6)) * 0x40) = 1;
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uVar5 + *(ushort *)(DAT_02194f10 + 6)) * 0x40) = 1;
  }
  iVar2 = *DAT_02194ef0;
  uVar3 = func_0x02124a68(1,*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 8));
  func_0x0211ded0(*(undefined4 *)(iVar2 + 0x78),*(undefined4 *)(iVar2 + 4),
                  *(undefined4 *)(iVar2 + 8),1,uVar3,0);
  iVar2 = *DAT_02194ef0;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x58),
                          *(undefined4 *)(DAT_02194f14 + *(int *)(iVar2 + 0x78) * 4));
  func_0x0212426c(0,0,*(undefined4 *)(*DAT_02194ef0 + 0x10),uVar3,*(undefined4 *)(iVar2 + 8),
                  *(undefined4 *)(iVar2 + 0x50));
  iVar2 = DAT_02194f1c;
  piVar1 = DAT_02194ef0;
  iVar6 = 0;
  puVar7 = DAT_02194f18;
  do {
    iVar4 = func_0x02060440(*(undefined4 *)(iVar2 + *(int *)(*piVar1 + 0x78) * 4),*puVar7);
    if (iVar4 == 0) {
      FUN_02194fd8(iVar6);
    }
    else {
      FUN_021950fc(iVar6);
    }
    puVar7 = puVar7 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 4);
  return;
}

