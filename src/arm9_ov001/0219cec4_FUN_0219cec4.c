/* Decompiled C draft; module arm9_ov001; ROM address 0219cec4. No matching claim. */
#include "types.h"
#include "deps/0219cec4_FUN_0219cec4.h"

void FUN_0219cec4(void)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  
  iVar5 = DAT_0219cf50;
  piVar2 = DAT_0219cf44;
  iVar6 = *DAT_0219cf44;
  uVar1 = *(ushort *)(*(int *)(iVar6 + DAT_0219cf48) + 6);
  *(short *)(*(int *)(iVar6 + DAT_0219cf50) + (uint)*DAT_0219cf4c * 0x40 + 6) =
       -(short)*(undefined4 *)(iVar6 + 0x14);
  iVar6 = 0;
  pbVar7 = DAT_0219cf54;
  do {
    iVar4 = *piVar2;
    *(short *)(*(int *)(iVar4 + iVar5) + (uint)*pbVar7 * 0x40 + 6) =
         (short)*(undefined4 *)(iVar4 + 0x1c) - (short)*(undefined4 *)(iVar4 + 0x14);
    iVar4 = DAT_0219cf50;
    piVar3 = DAT_0219cf44;
    pbVar7 = pbVar7 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  iVar5 = 0;
  pbVar7 = DAT_0219cf58;
  do {
    *(short *)(*(int *)(*piVar3 + iVar4) + (uint)*pbVar7 * 0x40 + 4) =
         (short)*(undefined4 *)(*piVar3 + 0x18);
    iVar6 = DAT_0219cf50;
    piVar2 = DAT_0219cf44;
    pbVar7 = pbVar7 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  iVar5 = 0;
  pbVar7 = DAT_0219cf5c;
  do {
    *(short *)((uint)*pbVar7 * 0x40 + (uint)uVar1 * 0x40 + *(int *)(*piVar2 + iVar6) + 4) =
         (short)*(undefined4 *)(*piVar2 + 0x18);
    pbVar7 = pbVar7 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

