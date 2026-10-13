/* Decompiled C draft; module arm9_ov003; ROM address 021c6400. No matching claim. */
#include "types.h"
#include "deps/021c6400_FUN_021c6400.h"

void FUN_021c6400(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  uVar11 = (uint)*(byte *)(*DAT_021c64f0 + 0x51);
  if (5 < uVar11) {
    uVar11 = 5;
  }
  iVar7 = 0;
  if (uVar11 != 0) {
    iVar6 = 0;
    uVar1 = *DAT_021c64f4;
    uVar2 = *DAT_021c64f8;
    do {
      uVar5 = FUN_021d1c18(0,uVar1);
      *(undefined4 *)(*DAT_021c64f0 + iVar6 + 0x10) = uVar5;
      uVar5 = FUN_021d1c18(0,uVar2);
      *(undefined4 *)(*DAT_021c64f0 + iVar6 + 0x24) = uVar5;
      iVar6 = iVar6 + 4;
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar11);
  }
  uVar9 = 0;
  iVar7 = 0;
  puVar8 = DAT_021c64f4;
  do {
    FUN_021d1c3c(0,*puVar8,*(undefined4 *)(*DAT_021c64f0 + 0x10));
    *(ushort *)(*DAT_021c64f0 + iVar7 + 0x42) =
         *(ushort *)(*(int *)(*DAT_021c64f0 + 0x10) + 4) & (ushort)DAT_021c64fc;
    puVar8 = puVar8 + 1;
    iVar7 = iVar7 + 2;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 3);
  uVar9 = 0;
  iVar7 = 0;
  puVar8 = DAT_021c64f8;
  do {
    FUN_021d1c3c(0,*puVar8,*(undefined4 *)(*DAT_021c64f0 + 0x24));
    *(ushort *)(*DAT_021c64f0 + iVar7 + 0x48) =
         *(ushort *)(*(int *)(*DAT_021c64f0 + 0x24) + 4) & (ushort)DAT_021c64fc;
    uVar4 = DAT_021c6504;
    uVar5 = DAT_021c6500;
    piVar3 = DAT_021c64f0;
    puVar8 = puVar8 + 1;
    iVar7 = iVar7 + 2;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 4);
  iVar7 = 0;
  if (uVar11 != 0) {
    iVar6 = 0;
    do {
      iVar10 = *(int *)(*piVar3 + iVar6 + 0x10);
      *(ushort *)(iVar10 + 4) = *(ushort *)(iVar10 + 4) & (ushort)uVar5 | (ushort)uVar4;
      iVar10 = *(int *)(*piVar3 + iVar6 + 0x24);
      *(ushort *)(iVar10 + 4) = *(ushort *)(iVar10 + 4) & (ushort)uVar5 | (ushort)uVar4;
      iVar6 = iVar6 + 4;
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar11);
  }
  return;
}

