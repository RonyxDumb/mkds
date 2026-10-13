/* Decompiled C draft; module arm9_ov001; ROM address 0219d858. No matching claim. */
#include "types.h"
#include "deps/0219d858_FUN_0219d858.h"

void FUN_0219d858(void)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  short sVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  int local_20;
  
  piVar2 = DAT_0219d924;
  uVar1 = *(ushort *)(*(int *)(*DAT_0219d924 + 0x44) + 6);
  iVar7 = 0;
  local_20 = 0;
  piVar5 = DAT_0219d92c;
  iVar6 = DAT_0219d928;
  do {
    iVar8 = 0;
    if (0 < *piVar5) {
      do {
        iVar9 = *piVar2;
        *(undefined2 *)(*(int *)(iVar9 + 0x34) + (uint)*(byte *)(iVar6 + iVar8) * 0x40 + 4) =
             *(undefined2 *)(iVar7 + iVar9 + 0x18);
        iVar9 = *piVar2;
        *(undefined2 *)(*(int *)(iVar9 + 0x34) + (uint)*(byte *)(iVar6 + iVar8) * 0x40 + 6) =
             *(undefined2 *)(iVar7 + iVar9 + 0x1a);
        iVar8 = iVar8 + 1;
      } while (iVar8 < *piVar5);
    }
    piVar3 = DAT_0219d924;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 0xb;
    piVar5 = piVar5 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 2);
  iVar6 = (uint)uVar1 * 0x40;
  *(undefined2 *)(*(int *)(*DAT_0219d924 + 0x34) + iVar6 + 4) =
       *(undefined2 *)(*DAT_0219d924 + 0x1c);
  *(undefined2 *)(*(int *)(*piVar3 + 0x34) + iVar6 + 6) = *(undefined2 *)(*piVar3 + 0x1e);
  iVar6 = 0;
  pbVar10 = DAT_0219d930;
  do {
    sVar4 = func_0x020adc64(6 - *(int *)(*piVar3 + 0x28));
    iVar7 = *(int *)(*piVar3 + 0x34) + (uint)*pbVar10 * 0x40;
    *(short *)(iVar7 + 4) = *(short *)(iVar7 + 4) - sVar4;
    sVar4 = func_0x020adc64(6 - *(int *)(*piVar3 + 0x2c));
    iVar7 = *(int *)(*piVar3 + 0x34) + (uint)pbVar10[1] * 0x40;
    *(short *)(iVar7 + 4) = *(short *)(iVar7 + 4) + sVar4;
    pbVar10 = pbVar10 + 2;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  return;
}

