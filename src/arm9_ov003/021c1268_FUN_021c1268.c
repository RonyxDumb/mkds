/* Decompiled C draft; module arm9_ov003; ROM address 021c1268. No matching claim. */
#include "types.h"
#include "deps/021c1268_FUN_021c1268.h"

void FUN_021c1268(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)(*DAT_021c12c0 + 99) < '\f') {
    uVar2 = 0x44;
  }
  else {
    uVar2 = 0x45;
  }
  uVar1 = FUN_021d1974(*(undefined4 *)(*DAT_021c12c0 + 0x58),0);
  FUN_021d1c3c(0,uVar2,uVar1);
  FUN_021d1790(*(undefined4 *)(*DAT_021c12c0 + 0x58),0xffffffff,2);
  iVar3 = *(char *)(*DAT_021c12c0 + 99) * 4;
  FUN_021d17d4(*(undefined4 *)(*DAT_021c12c0 + 0x58),0xffffffff,
               *(undefined2 *)(DAT_021c12c4 + iVar3),*(undefined2 *)(DAT_021c12c8 + iVar3));
  return;
}

