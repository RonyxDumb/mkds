/* Decompiled C draft; module arm9_ov000; ROM address 021854f8. No matching claim. */
#include "types.h"
#include "deps/021854f8_FUN_021854f8.h"

void FUN_021854f8(void)

{
  int *piVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_02185544;
  iVar4 = 0;
  pbVar3 = DAT_02185540;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x30) + (uint)*pbVar3 * 0x40 + 6) =
         *(undefined2 *)(*piVar1 + 0xc);
    piVar2 = DAT_02185544;
    pbVar3 = pbVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  iVar4 = 0;
  pbVar3 = DAT_02185548;
  do {
    iVar5 = *piVar2;
    *(undefined2 *)
     (*(int *)(iVar5 + 0x30) +
      ((uint)*pbVar3 + (uint)*(ushort *)(*(int *)(iVar5 + 0x40) + 6)) * 0x40 + 6) =
         *(undefined2 *)(iVar5 + 0xc);
    pbVar3 = pbVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  return;
}

