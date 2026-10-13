/* Decompiled C draft; module arm9_ov003; ROM address 021caae0. No matching claim. */
#include "types.h"
#include "deps/021caae0_FUN_021caae0.h"

void FUN_021caae0(void)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = *DAT_021cab3c;
  iVar4 = (bVar1 - 4) * 4;
  uVar2 = FUN_021d1974(*(undefined4 *)(*DAT_021cab40 + iVar4 + 0x10),0);
  FUN_021d1c3c(0,0x32,uVar2);
  iVar3 = (bVar1 - 1) * 4;
  FUN_021d17d4(*(undefined4 *)(*DAT_021cab40 + iVar4 + 0x10),0xffffffff,
               *(undefined2 *)(DAT_021cab44 + iVar3),*(undefined2 *)(DAT_021cab48 + iVar3));
  FUN_021d1790(*(undefined4 *)(*DAT_021cab40 + iVar4 + 0x10),0xffffffff,3);
  return;
}

