/* Decompiled C draft; module arm9_ov003; ROM address 021c0318. No matching claim. */
#include "types.h"
#include "deps/021c0318_FUN_021c0318.h"

void FUN_021c0318(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_021d2ae8(0x20);
  if (iVar2 != 0) {
    FUN_021bfce0(0);
  }
  iVar2 = FUN_021d2ae8(0x40);
  if (iVar2 != 0) {
    FUN_021bfce0(1);
  }
  iVar2 = FUN_021d2ae8(0x10);
  if (iVar2 != 0) {
    FUN_021bfce0(2);
  }
  iVar2 = FUN_021d2ae8(0x80);
  if (iVar2 != 0) {
    FUN_021bfce0(3);
  }
  iVar3 = FUN_021d2b04(1);
  iVar2 = DAT_021c04c8;
  piVar1 = DAT_021c04bc;
  if (iVar3 != 0) {
    iVar3 = *DAT_021c04bc;
    iVar4 = (int)*(char *)(iVar3 + DAT_021c04c0);
    if (iVar4 < 0x2f) {
      if (*(char *)(iVar3 + DAT_021c04c4) == '\0') {
        FUN_021cdc10(9);
        return;
      }
      *(undefined1 *)(iVar3 + DAT_021c04d0) =
           *(undefined1 *)
            (*(int *)(DAT_021c04cc + (uint)*(byte *)(iVar3 + DAT_021c04c8) * 4) + iVar4);
      if (*(char *)(*piVar1 + iVar2) != '\x01') {
        return;
      }
      FUN_021c00ec(0);
      return;
    }
    if (iVar4 + -0x2f < 4) {
      switch(iVar4) {
      case 0x2f:
        FUN_021c06b0();
        return;
      case 0x30:
        FUN_021c0680();
        return;
      case 0x31:
        if (*(char *)(iVar3 + DAT_021c04c4) == '\0') {
          FUN_021cdc10(9);
          return;
        }
        break;
      case 0x32:
        if (*(char *)(iVar3 + DAT_021c04d4) == '\0') {
          FUN_021cdc10(9);
          return;
        }
      }
      if (*(char *)(iVar3 + DAT_021c04c8) == '\x01') {
        FUN_021c00ec(0);
      }
      *(undefined1 *)(*DAT_021c04bc + DAT_021c04d0) = *(undefined1 *)(DAT_021c04d8 + iVar4 + -0x2f);
      return;
    }
    *(undefined1 *)(iVar3 + DAT_021c04d0) = *(undefined1 *)(DAT_021c04dc + iVar4 + -0x33);
  }
  iVar2 = FUN_021d2ae8(2);
  if (iVar2 == 0) {
    iVar2 = FUN_021d2acc(2);
    if (iVar2 != 0) {
      *(undefined1 *)(*DAT_021c04bc + DAT_021c04e0) = 0;
    }
  }
  else {
    iVar2 = *DAT_021c04bc;
    if (*(char *)(iVar2 + DAT_021c04d4) == '\0') {
      if (*(char *)(iVar2 + DAT_021c04e0) != '\0') {
        return;
      }
      FUN_021cdc10(9);
      *(undefined1 *)(*DAT_021c04bc + DAT_021c04e0) = 1;
      return;
    }
    *(undefined1 *)(iVar2 + DAT_021c04d0) = 0x80;
  }
  iVar2 = FUN_021d2b04(DAT_021c04e4);
  if (iVar2 != 0) {
    FUN_021c06b0();
  }
  iVar2 = FUN_021d2b04(DAT_021c04e8);
  if (iVar2 != 0) {
    FUN_021c0680();
  }
  return;
}

