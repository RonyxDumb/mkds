/* Decompiled C draft; module arm9_ov003; ROM address 021caca8. No matching claim. */
#include "types.h"
#include "deps/021caca8_FUN_021caca8.h"

void FUN_021caca8(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*DAT_021cace8;
  if (uVar1 < 4) {
    iVar2 = uVar1 * 8;
    FUN_021bf6c8(*(undefined2 *)(DAT_021cacec + iVar2),*(undefined2 *)(DAT_021cacf0 + iVar2),
                 *(undefined2 *)(DAT_021cacf4 + iVar2),*(undefined2 *)(DAT_021cacf8 + iVar2));
    return;
  }
  iVar2 = uVar1 * 8;
  FUN_021bf760(0,*(undefined2 *)(DAT_021cacec + iVar2),*(undefined2 *)(DAT_021cacf0 + iVar2),
               *(undefined2 *)(DAT_021cacf4 + iVar2));
  return;
}

