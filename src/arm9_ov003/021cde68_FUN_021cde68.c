/* Decompiled C draft; module arm9_ov003; ROM address 021cde68. No matching claim. */
#include "types.h"
#include "deps/021cde68_FUN_021cde68.h"

void FUN_021cde68(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_1c;
  undefined1 auStack_18 [4];
  
  FUN_021d1770(*(undefined4 *)(*DAT_021cdef0 + 8),0,&local_1c,(uint *)(void *)(auStack_18));
  local_1c = local_1c - 8;
  if ((int)(uint)*(ushort *)(DAT_021cdef4 + 4) < (int)local_1c) {
    iVar3 = 2;
    iVar1 = 8;
    iVar2 = DAT_021cdef8;
    do {
      FUN_021d17d4(*(undefined4 *)(*DAT_021cdef0 + iVar1),0xffffffff,local_1c,
                   *(undefined2 *)(iVar2 + 2));
      iVar2 = iVar2 + 4;
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
    return;
  }
  iVar3 = 2;
  iVar1 = 8;
  iVar2 = DAT_021cdef8;
  local_1c = (uint)*(ushort *)(DAT_021cdef4 + 4);
  do {
    FUN_021d17d4(*(undefined4 *)(*DAT_021cdef0 + iVar1),0xffffffff,local_1c,
                 *(undefined2 *)(iVar2 + 2));
    iVar2 = iVar2 + 4;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  FUN_021d34e0(param_1,DAT_021cdefc);
  return;
}

