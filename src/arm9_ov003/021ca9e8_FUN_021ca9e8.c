/* Decompiled C draft; module arm9_ov003; ROM address 021ca9e8. No matching claim. */
#include "types.h"
#include "deps/021ca9e8_FUN_021ca9e8.h"

void FUN_021ca9e8(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  bVar1 = *DAT_021caac8;
  iVar4 = bVar1 - 4;
  iVar2 = FUN_021cef80();
  if (iVar2 == 0) {
    FUN_021cdc10(7);
    iVar4 = iVar4 * 4;
    uVar3 = FUN_021d1974(*(undefined4 *)(*DAT_021caacc + iVar4 + 0x10),0);
    FUN_021d1c3c(0,0x11,uVar3);
    iVar2 = (bVar1 - 1) * 4;
    FUN_021d17d4(*(undefined4 *)(*DAT_021caacc + iVar4 + 0x10),0xffffffff,
                 *(undefined2 *)(DAT_021caad4 + iVar2),*(undefined2 *)(DAT_021caad8 + iVar2));
    FUN_021d1790(*(undefined4 *)(*DAT_021caacc + iVar4 + 0x10),0xffffffff,3);
  }
  else {
    if (iVar2 != 1) {
      return;
    }
    FUN_021cdc10(0xe);
    FUN_021cd4ac(iVar4);
    iVar4 = iVar4 * 4;
    uVar3 = FUN_021d1974(*(undefined4 *)(*DAT_021caacc + iVar4 + 4),0);
    FUN_021d1c3c(0,*(undefined1 *)(DAT_021caad0 + 3),uVar3);
    FUN_021d17d4(*(undefined4 *)(*DAT_021caacc + iVar4 + 4),0xffffffff,
                 *(undefined2 *)(DAT_021caad4 + iVar4),*(undefined2 *)(DAT_021caad8 + iVar4));
    FUN_021d1790(*(undefined4 *)(*DAT_021caacc + iVar4 + 4),0xffffffff,3);
    FUN_021d197c(*(undefined4 *)(*DAT_021caacc + iVar4 + 0x10));
    *(undefined4 *)(*DAT_021caacc + iVar4 + 0x10) = 0;
  }
  FUN_021cef90();
  FUN_021c212c(DAT_021caadc);
  return;
}

