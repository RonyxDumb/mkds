/* Decompiled C draft; module arm9_ov001; ROM address 02198bbc. No matching claim. */
#include "types.h"
#include "deps/02198bbc_FUN_02198bbc.h"

void FUN_02198bbc(void)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  byte *local_34;
  byte *local_30;
  int local_28;
  int local_24;
  int local_1c;
  
  piVar6 = DAT_02198d04;
  iVar7 = *DAT_02198d04;
  uVar1 = *(ushort *)(*(int *)(iVar7 + 0x74) + 6);
  uVar2 = *(ushort *)(*(int *)(iVar7 + 0x78) + 6);
  *(undefined2 *)(*(int *)(iVar7 + 0x54) + (uint)*DAT_02198d08 * 0x40 + 6) =
       *(undefined2 *)(iVar7 + 0x24);
  iVar7 = 0;
  pbVar11 = DAT_02198d0c;
  do {
    *(undefined2 *)((uint)*pbVar11 * 0x40 + (uint)uVar1 * 0x40 + *(int *)(*piVar6 + 0x54) + 6) =
         *(undefined2 *)(*piVar6 + 0x24);
    piVar3 = DAT_02198d04;
    pbVar11 = pbVar11 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  iVar8 = 0;
  local_24 = 0;
  local_30 = DAT_02198d18;
  iVar9 = (uint)uVar2 * 0x40;
  piVar6 = DAT_02198d14;
  iVar7 = DAT_02198d10;
  do {
    iVar10 = 0;
    if (0 < *piVar6) {
      do {
        *(undefined2 *)(*(int *)(*piVar3 + 0x58) + (uint)*(byte *)(iVar7 + iVar10) * 0x40 + 4) =
             *(undefined2 *)(iVar8 + *piVar3 + 0x26);
        *(undefined2 *)(*(int *)(*piVar3 + 0x58) + (uint)*(byte *)(iVar7 + iVar10) * 0x40 + 6) =
             *(undefined2 *)(iVar8 + *piVar3 + 0x28);
        iVar10 = iVar10 + 1;
      } while (iVar10 < *piVar6);
    }
    *(undefined2 *)((uint)*local_30 * 0x40 + iVar9 + *(int *)(*piVar3 + 0x58) + 4) =
         *(undefined2 *)(*piVar3 + iVar8 + 0x26);
    *(undefined2 *)((uint)*local_30 * 0x40 + iVar9 + *(int *)(*piVar3 + 0x58) + 6) =
         *(undefined2 *)(*piVar3 + iVar8 + 0x28);
    piVar4 = DAT_02198d04;
    iVar8 = iVar8 + 4;
    iVar7 = iVar7 + 0xc;
    piVar6 = piVar6 + 1;
    local_30 = local_30 + 1;
    local_24 = local_24 + 1;
  } while (local_24 < 3);
  iVar8 = 0;
  local_28 = 0;
  local_34 = DAT_02198d1c;
  local_1c = 0;
  pbVar11 = DAT_02198d1c;
  iVar7 = local_1c;
  do {
    do {
      sVar5 = func_0x020adc64(6 - *(int *)(iVar8 + *piVar4 + 0x40));
      iVar9 = *(int *)(*piVar4 + 0x58) + (uint)*pbVar11 * 0x40;
      *(short *)(iVar9 + 4) = *(short *)(iVar9 + 4) - sVar5;
      sVar5 = func_0x020adc64(6 - *(int *)(iVar8 + *piVar4 + 0x44));
      iVar9 = *(int *)(*piVar4 + 0x58) + (uint)pbVar11[1] * 0x40;
      *(short *)(iVar9 + 4) = *(short *)(iVar9 + 4) + sVar5;
      iVar7 = iVar7 + 1;
      pbVar11 = pbVar11 + 2;
    } while (iVar7 < 3);
    iVar8 = iVar8 + 8;
    pbVar11 = local_34 + 6;
    local_28 = local_28 + 1;
    iVar7 = local_1c;
    local_34 = pbVar11;
  } while (local_28 < 2);
  return;
}

