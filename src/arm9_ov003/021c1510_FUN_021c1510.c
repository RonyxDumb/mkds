/* Decompiled C draft; module arm9_ov003; ROM address 021c1510. No matching claim. */
#include "types.h"
#include "deps/021c1510_FUN_021c1510.h"

void FUN_021c1510(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_021d2ae8(0x20);
  if (iVar1 != 0) {
    FUN_021c11dc(0);
  }
  iVar1 = FUN_021d2ae8(0x40);
  if (iVar1 != 0) {
    FUN_021c11dc(1);
  }
  iVar1 = FUN_021d2ae8(0x10);
  if (iVar1 != 0) {
    FUN_021c11dc(2);
  }
  iVar1 = FUN_021d2ae8(0x80);
  if (iVar1 != 0) {
    FUN_021c11dc(3);
  }
  iVar1 = FUN_021d2b04(1);
  if (iVar1 != 0) {
    iVar1 = *DAT_021c1638;
    iVar2 = (int)*(char *)(iVar1 + 99);
    if (iVar2 < 10) {
      if (*(char *)(iVar1 + 0x67) != '\0') {
        *(undefined1 *)(iVar1 + 0x60) = *(undefined1 *)(DAT_021c163c + iVar2);
        return;
      }
      FUN_021cdc10(9);
      return;
    }
    if (iVar2 + -10 < 2) {
      if (((iVar2 != 10) || (*(char *)(iVar1 + 0x66) != '\0')) &&
         ((iVar2 != 0xb || (*(char *)(iVar1 + 0x68) != '\0')))) {
        *(undefined1 *)(iVar1 + 0x60) = *(undefined1 *)(DAT_021c1640 + iVar2 + -10);
        return;
      }
      FUN_021cdc10(9);
      return;
    }
    *(undefined1 *)(iVar1 + 0x60) = *(undefined1 *)(DAT_021c1644 + iVar2 + -0xc);
  }
  iVar1 = FUN_021d2ae8(2);
  if (iVar1 == 0) {
    iVar1 = FUN_021d2acc(2);
    if (iVar1 != 0) {
      *(undefined1 *)(*DAT_021c1638 + 0x69) = 0;
    }
  }
  else {
    iVar1 = *DAT_021c1638;
    if (*(char *)(iVar1 + 0x66) != '\0') {
      *(undefined1 *)(iVar1 + 0x60) = 0x10;
      return;
    }
    if (*(char *)(iVar1 + 0x69) == '\0') {
      FUN_021cdc10(9);
      *(undefined1 *)(*DAT_021c1638 + 0x69) = 1;
      return;
    }
  }
  return;
}

