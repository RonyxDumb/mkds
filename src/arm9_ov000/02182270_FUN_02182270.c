/* Decompiled C draft; module arm9_ov000; ROM address 02182270. No matching claim. */
#include "types.h"
#include "deps/02182270_FUN_02182270.h"

void FUN_02182270(void)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  short sVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  int local_20;
  
  piVar2 = DAT_02182394;
  uVar1 = *(ushort *)(*(int *)(*DAT_02182394 + DAT_02182398) + 6);
  iVar7 = 0;
  local_20 = 0;
  piVar5 = DAT_021823a0;
  iVar6 = DAT_0218239c;
  do {
    iVar9 = 0;
    if (0 < *piVar5) {
      do {
        iVar10 = *piVar2;
        *(undefined2 *)(*(int *)(iVar10 + DAT_021823a4) + (uint)*(byte *)(iVar6 + iVar9) * 0x40 + 4)
             = *(undefined2 *)(iVar7 + iVar10 + 0x14);
        iVar10 = *piVar2;
        *(undefined2 *)(*(int *)(iVar10 + DAT_021823a4) + (uint)*(byte *)(iVar6 + iVar9) * 0x40 + 6)
             = *(undefined2 *)(iVar7 + iVar10 + 0x16);
        iVar9 = iVar9 + 1;
      } while (iVar9 < *piVar5);
    }
    piVar3 = DAT_02182394;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 9;
    piVar5 = piVar5 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 3);
  iVar6 = 0;
  iVar9 = 0;
  iVar7 = (uint)uVar1 * 0x40;
  pbVar8 = DAT_021823a8;
  do {
    iVar10 = *piVar3;
    *(undefined2 *)((uint)*pbVar8 * 0x40 + iVar7 + *(int *)(iVar10 + DAT_021823a4) + 4) =
         *(undefined2 *)(iVar10 + iVar9 + 0x14);
    iVar10 = *piVar3;
    *(undefined2 *)((uint)*pbVar8 * 0x40 + iVar7 + *(int *)(iVar10 + DAT_021823a4) + 6) =
         *(undefined2 *)(iVar10 + iVar9 + 0x16);
    iVar10 = DAT_021823a4;
    piVar2 = DAT_02182394;
    iVar9 = iVar9 + 4;
    pbVar8 = pbVar8 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  iVar6 = 0;
  do {
    iVar9 = *piVar2;
    *(undefined2 *)(iVar7 + *(int *)(iVar9 + iVar10) + 0x44) = *(undefined2 *)(iVar9 + 0x18);
    iVar9 = *piVar2;
    *(undefined2 *)(iVar7 + *(int *)(iVar9 + iVar10) + 0x46) = *(undefined2 *)(iVar9 + 0x1a);
    piVar5 = DAT_02182394;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  iVar6 = 0;
  pbVar8 = DAT_021823ac;
  do {
    sVar4 = func_0x020adc64(6 - *(int *)(*piVar5 + 0x2c));
    iVar7 = *(int *)(*piVar5 + DAT_021823a4) + (uint)*pbVar8 * 0x40;
    *(short *)(iVar7 + 4) = *(short *)(iVar7 + 4) - sVar4;
    sVar4 = func_0x020adc64(6 - *(int *)(*piVar5 + 0x30));
    iVar7 = *(int *)(*piVar5 + DAT_021823a4) + (uint)pbVar8[1] * 0x40;
    *(short *)(iVar7 + 4) = *(short *)(iVar7 + 4) + sVar4;
    pbVar8 = pbVar8 + 2;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  return;
}

