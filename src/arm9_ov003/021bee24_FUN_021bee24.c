/* Decompiled C draft; module arm9_ov003; ROM address 021bee24. No matching claim. */
#include "types.h"
#include "deps/021bee24_FUN_021bee24.h"

void FUN_021bee24(void)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  uint *puVar6;
  
  uVar4 = func_0x02147cd8(*(byte *)(*DAT_021beeac + 9) + 1,0x28);
  piVar2 = DAT_021beeac;
  *(undefined1 *)(*DAT_021beeac + 9) = uVar4;
  iVar5 = func_0x02147d30(*(undefined1 *)(*piVar2 + 9),5);
  FUN_021d1c3c(0,iVar5 + 0x47,*(undefined4 *)(*DAT_021beeac + 4));
  uVar3 = DAT_021beeb0;
  piVar2 = DAT_021beeac;
  *(ushort *)(*(int *)(*DAT_021beeac + 4) + 4) =
       *(ushort *)(*(int *)(*DAT_021beeac + 4) + 4) & (ushort)DAT_021beeb0 | (ushort)DAT_021beeb4;
  iVar5 = *piVar2;
  bVar1 = *(byte *)(DAT_021beeb8 + (uint)*(byte *)(iVar5 + 8));
  puVar6 = *(uint **)(iVar5 + 4);
  *puVar6 = *puVar6 & uVar3;
  *(ushort *)(puVar6 + 1) = (ushort)puVar6[1] & (ushort)DAT_021beebc | (ushort)bVar1 << 0xc;
  puVar6 = *(uint **)(*piVar2 + 4);
  *puVar6 = (*DAT_021beec0 & DAT_021beec4) << 0x10 | *puVar6 & DAT_021beec8 | DAT_021beec0[1] & 0xff
  ;
  return;
}

