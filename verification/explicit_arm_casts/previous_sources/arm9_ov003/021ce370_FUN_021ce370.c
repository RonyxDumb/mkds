/* Decompiled C draft; module arm9_ov003; ROM address 021ce370. No matching claim. */
#include "types.h"
#include "deps/021ce370_FUN_021ce370.h"

void FUN_021ce370(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  uint local_1c;
  undefined1 auStack_18 [4];
  
  FUN_021d1770(*(undefined4 *)*DAT_021ce3f8,0,&local_1c,auStack_18);
  uVar1 = local_1c + 8;
  local_1c = (uint)*DAT_021ce3fc;
  if (((int)local_1c <= (int)uVar1) && ((int)uVar1 <= DAT_021ce400)) {
    iVar4 = 0;
    iVar2 = 0;
    puVar3 = DAT_021ce3fc;
    do {
      FUN_021d17d4(*(undefined4 *)(*DAT_021ce3f8 + iVar2),0xffffffff,local_1c,puVar3[1]);
      puVar3 = puVar3 + 2;
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    FUN_021d34e0(param_1,DAT_021ce404);
    return;
  }
  iVar4 = 0;
  iVar2 = 0;
  puVar3 = DAT_021ce3fc;
  local_1c = uVar1;
  do {
    FUN_021d17d4(*(undefined4 *)(*DAT_021ce3f8 + iVar2),0xffffffff,local_1c,puVar3[1]);
    puVar3 = puVar3 + 2;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  return;
}

