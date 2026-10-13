/* Decompiled C draft; module arm9_ov000; ROM address 02183858. No matching claim. */
#include "types.h"
#include "deps/02183858_FUN_02183858.h"

void FUN_02183858(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  int local_34;
  
  iVar8 = *DAT_021839a8;
  iVar10 = *(int *)(iVar8 + 8);
  iVar3 = *(int *)(iVar8 + 0x44);
  uVar4 = (uint)*(ushort *)(*(int *)(iVar8 + DAT_021839ac) + 6);
  local_34 = iVar10;
  if (0x1d < iVar10) {
    local_34 = 0x1d;
  }
  iVar12 = iVar10;
  if (0x27 < iVar10) {
    iVar12 = 0x27;
  }
  uVar5 = func_0x02133068((uint)*(byte *)(DAT_021839b0 + local_34) << 0xc,100);
  uVar6 = func_0x02133068((uint)*(byte *)(DAT_021839b4 + iVar12) << 0xc,100);
  if (iVar10 < 0x20) {
    uVar2 = func_0x02133068(iVar12 << 0x11,0x20);
  }
  else {
    uVar2 = 0;
  }
  *(undefined4 *)(*(int *)(iVar8 + DAT_021839b8) + (uVar4 + *(byte *)(DAT_021839bc + iVar3)) * 0x40)
       = 1;
  iVar10 = 0;
  iVar8 = iVar3 * 2;
  pbVar9 = (byte *)(DAT_021839c0 + iVar8);
  pbVar7 = (byte *)(DAT_021839c4 + iVar8);
  pbVar11 = pbVar9;
  do {
    *(undefined4 *)(*(int *)(*DAT_021839a8 + DAT_021839b8) + (uint)*pbVar11 * 0x40) = 1;
    *(undefined4 *)(*(int *)(*DAT_021839a8 + DAT_021839b8) + (uVar4 + *pbVar7) * 0x40) = 1;
    pbVar11 = pbVar11 + 1;
    pbVar7 = pbVar7 + 1;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 2);
  iVar3 = (uint)*(byte *)(DAT_021839c8 + iVar3) * 0x40;
  *(undefined4 *)(*(int *)(*DAT_021839a8 + DAT_021839b8) + iVar3) = 1;
  *(short *)(*DAT_021839a8 + iVar8 + 0x18) = (short)*(char *)(DAT_021839cc + local_34);
  piVar1 = DAT_021839a8;
  iVar8 = 0;
  do {
    func_0x02124b1c(*(int *)(*piVar1 + DAT_021839b8) + (uint)*pbVar9 * 0x40,0,uVar5);
    pbVar9 = pbVar9 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  func_0x02124b1c(*(int *)(*DAT_021839a8 + DAT_021839b8) + iVar3,uVar2,uVar6);
  piVar1 = DAT_021839a8;
  *(int *)(*DAT_021839a8 + 8) = *(int *)(*DAT_021839a8 + 8) + 1;
  iVar3 = *(int *)(*piVar1 + 8);
  if ((0x1d < iVar3) && (0x27 < iVar3)) {
    *(undefined4 *)(*piVar1 + 8) = 0;
    iVar3 = *piVar1;
    if (*(int *)(iVar3 + 0x44) == *(int *)(iVar3 + 0x30) + -1) {
      *(undefined4 *)(iVar3 + 4) = 8;
      return;
    }
    *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + 1;
    *(undefined4 *)(*piVar1 + 4) = 5;
  }
  return;
}

