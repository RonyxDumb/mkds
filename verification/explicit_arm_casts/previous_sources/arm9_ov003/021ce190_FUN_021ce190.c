/* Decompiled C draft; module arm9_ov003; ROM address 021ce190. No matching claim. */
#include "types.h"
#include "deps/021ce190_FUN_021ce190.h"

void FUN_021ce190(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_1c;
  undefined1 auStack_18 [4];
  
  FUN_021d1770(*(undefined4 *)(*DAT_021ce21c + 0xc),0,&local_1c,auStack_18);
  uVar1 = local_1c + 8;
  local_1c = (uint)*(ushort *)(DAT_021ce220 + 0xc);
  if (((int)local_1c <= (int)uVar1) && ((int)uVar1 <= DAT_021ce224)) {
    iVar4 = 3;
    iVar2 = 0xc;
    iVar3 = DAT_021ce228;
    do {
      FUN_021d17d4(*(undefined4 *)(*DAT_021ce21c + iVar2),0xffffffff,local_1c,
                   *(undefined2 *)(iVar3 + 2));
      iVar3 = iVar3 + 4;
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    FUN_021d34e0(param_1,DAT_021ce22c);
    return;
  }
  iVar4 = 3;
  iVar2 = 0xc;
  iVar3 = DAT_021ce228;
  local_1c = uVar1;
  do {
    FUN_021d17d4(*(undefined4 *)(*DAT_021ce21c + iVar2),0xffffffff,local_1c,
                 *(undefined2 *)(iVar3 + 2));
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  return;
}

