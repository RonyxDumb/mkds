/* Decompiled C draft; module arm9_ov003; ROM address 021c590c. No matching claim. */
#include "types.h"
#include "deps/021c590c_FUN_021c590c.h"

void FUN_021c590c(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_021c5934 < 4) {
    uVar1 = 2;
  }
  else {
    uVar1 = 3;
  }
  iVar2 = (uint)*DAT_021c5934 * 8;
  FUN_021bf760(uVar1,*(undefined2 *)(DAT_021c5938 + iVar2),*(undefined2 *)(DAT_021c593c + iVar2),
               *(undefined2 *)(DAT_021c5940 + iVar2));
  return;
}

