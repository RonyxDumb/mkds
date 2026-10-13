/* Decompiled C draft; module arm9_ov003; ROM address 021ce2d0. No matching claim. */
#include "types.h"
#include "deps/021ce2d0_FUN_021ce2d0.h"

void FUN_021ce2d0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_1c;
  undefined1 auStack_18 [4];
  
  FUN_021d1770(*(undefined4 *)(*DAT_021ce35c + 4),0,&local_1c,auStack_18);
  uVar1 = local_1c + 8;
  local_1c = (uint)*(ushort *)(DAT_021ce360 + 4);
  if (((int)local_1c <= (int)uVar1) && ((int)uVar1 <= DAT_021ce364)) {
    iVar4 = 1;
    iVar2 = 4;
    iVar3 = DAT_021ce368;
    do {
      FUN_021d17d4(*(undefined4 *)(*DAT_021ce35c + iVar2),0xffffffff,local_1c,
                   *(undefined2 *)(iVar3 + 2));
      iVar3 = iVar3 + 4;
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    FUN_021d34e0(param_1,DAT_021ce36c);
    return;
  }
  iVar4 = 1;
  iVar2 = 4;
  iVar3 = DAT_021ce368;
  local_1c = uVar1;
  do {
    FUN_021d17d4(*(undefined4 *)(*DAT_021ce35c + iVar2),0xffffffff,local_1c,
                 *(undefined2 *)(iVar3 + 2));
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  return;
}

