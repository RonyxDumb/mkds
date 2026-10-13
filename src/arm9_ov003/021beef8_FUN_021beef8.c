/* Decompiled C draft; module arm9_ov003; ROM address 021beef8. No matching claim. */
#include "types.h"
#include "deps/021beef8_FUN_021beef8.h"

void FUN_021beef8(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  
  iVar3 = FUN_021d283c(0xc,4);
  *DAT_021bef80 = iVar3;
  *(char *)(iVar3 + 8) = (char)param_1;
  uVar4 = FUN_021d1c18(0,0x47);
  piVar1 = DAT_021bef80;
  *(undefined4 *)(*DAT_021bef80 + 4) = uVar4;
  uVar2 = DAT_021bef84;
  *(ushort *)(*(int *)(*piVar1 + 4) + 4) =
       *(ushort *)(*(int *)(*piVar1 + 4) + 4) & (ushort)DAT_021bef84 | (ushort)DAT_021bef88;
  puVar5 = *(uint **)(*piVar1 + 4);
  *puVar5 = *puVar5 & uVar2;
  *(ushort *)(puVar5 + 1) =
       (ushort)puVar5[1] & (ushort)DAT_021bef8c | (ushort)*(byte *)(DAT_021bef90 + param_1) << 0xc;
  **(uint **)(*piVar1 + 4) =
       (*DAT_021bef94 & DAT_021bef98) << 0x10 |
       **(uint **)(*piVar1 + 4) & DAT_021bef9c | DAT_021bef94[1] & 0xff;
  uVar4 = FUN_021d3544(1,DAT_021befa0,0,0x78);
  *(undefined4 *)*DAT_021bef80 = uVar4;
  return;
}

