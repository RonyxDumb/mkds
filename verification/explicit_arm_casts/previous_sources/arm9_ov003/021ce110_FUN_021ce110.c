/* Decompiled C draft; module arm9_ov003; ROM address 021ce110. No matching claim. */
#include "types.h"
#include "deps/021ce110_FUN_021ce110.h"

void FUN_021ce110(undefined4 param_1)

{
  uint uVar1;
  uint local_18;
  undefined1 auStack_14 [8];
  
  FUN_021d1770(*(undefined4 *)(*DAT_021ce17c + 0x10),0,&local_18,auStack_14);
  uVar1 = local_18 + 8;
  local_18 = (uint)*(ushort *)(DAT_021ce180 + 0x10);
  if (((int)local_18 <= (int)uVar1) && ((int)uVar1 <= DAT_021ce184)) {
    FUN_021d17d4(*(undefined4 *)(*DAT_021ce17c + 0x10),0xffffffff,local_18,
                 *(undefined2 *)(DAT_021ce188 + 2));
    FUN_021d34e0(param_1,DAT_021ce18c);
    return;
  }
  local_18 = uVar1;
  FUN_021d17d4(*(undefined4 *)(*DAT_021ce17c + 0x10),0xffffffff,uVar1,
               *(undefined2 *)(DAT_021ce188 + 2));
  return;
}

