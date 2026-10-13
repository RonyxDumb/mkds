/* Decompiled C draft; module arm9_ov003; ROM address 021ceb80. No matching claim. */
#include "types.h"
#include "deps/021ceb80_FUN_021ceb80.h"

void FUN_021ceb80(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 * 4;
  uVar1 = FUN_021d1974(*(undefined4 *)(*DAT_021cebec + iVar4 + 8),0);
  FUN_021d1c3c(0,*(byte *)(param_1 + DAT_021cebf0 + (uint)*(byte *)(*DAT_021cebec + 0x1c) * 2) + 1,
               uVar1);
  uVar2 = (uint)*(byte *)(*DAT_021cebec + 0x1c);
  iVar5 = (uint)*(byte *)(param_1 + DAT_021cebf4 + uVar2 * 2) * 4;
  iVar3 = uVar2 * 8;
  FUN_021d17d4(*(undefined4 *)(*DAT_021cebec + iVar4 + 8),0xffffffff,
               *(undefined2 *)(iVar5 + DAT_021cebf8 + iVar3),
               *(undefined2 *)(iVar5 + DAT_021cebfc + iVar3));
  FUN_021d1790(*(undefined4 *)(*DAT_021cebec + iVar4 + 8),0xffffffff);
  return;
}

