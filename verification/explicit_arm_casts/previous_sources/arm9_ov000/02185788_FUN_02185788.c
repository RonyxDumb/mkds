/* Decompiled C draft; module arm9_ov000; ROM address 02185788. No matching claim. */
#include "types.h"
#include "deps/02185788_FUN_02185788.h"

void FUN_02185788(void)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte local_20 [20];
  
  pbVar3 = local_20;
  func_0x02061220(local_20);
  piVar1 = DAT_021857b4;
  iVar4 = 0;
  iVar2 = 0;
  do {
    *(ushort *)(*piVar1 + iVar2 + 0xe) = (ushort)*pbVar3;
    pbVar3 = pbVar3 + 1;
    iVar2 = iVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  return;
}

