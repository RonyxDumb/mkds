/* Decompiled C draft; module arm9_ov003; ROM address 021c9268. No matching claim. */
#include "types.h"
#include "deps/021c9268_FUN_021c9268.h"

void FUN_021c9268(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(int *)(*DAT_021c9430 + 0x38) == 0) && (*(char *)(*DAT_021c9430 + 0x45) == '\0')) &&
     (iVar1 = FUN_021c91fc(), iVar1 == 0)) {
    iVar1 = FUN_021d2b04(1);
    if (iVar1 != 0) {
      FUN_021c90dc(*DAT_021c9434);
      return;
    }
    iVar1 = FUN_021d2b04(2);
    if (iVar1 != 0) {
      FUN_021cdc10(7);
      *(undefined1 *)(*DAT_021c9430 + 0x40) = 0xd;
      FUN_021c212c(DAT_021c9438);
      return;
    }
    iVar1 = FUN_021d2ae8(DAT_021c943c);
    if (iVar1 == 0) {
      iVar1 = FUN_021d2acc(DAT_021c943c);
      if (iVar1 != 0) {
        *(undefined1 *)(*DAT_021c9430 + 0x47) = 0;
        return;
      }
      iVar1 = FUN_021d2ae8(DAT_021c9448);
      if (iVar1 == 0) {
        iVar1 = FUN_021d2acc(DAT_021c9448);
        if (iVar1 != 0) {
          *(undefined1 *)(*DAT_021c9430 + 0x47) = 0;
          return;
        }
        iVar1 = FUN_021d2ae8(0x40);
        if (iVar1 != 0) {
          FUN_021c7eec(1);
          return;
        }
        iVar1 = FUN_021d2acc(0x40);
        if (iVar1 != 0) {
          *(undefined1 *)(*DAT_021c9430 + 0x47) = 0;
          return;
        }
        iVar1 = FUN_021d2ae8(0x80);
        if (iVar1 != 0) {
          FUN_021c7eec(3);
          return;
        }
        iVar1 = FUN_021d2acc(0x80);
        if (iVar1 != 0) {
          *(undefined1 *)(*DAT_021c9430 + 0x47) = 0;
          return;
        }
        iVar1 = FUN_021d2ae8(0x20);
        if (iVar1 != 0) {
          FUN_021c7eec(0);
          return;
        }
        iVar1 = FUN_021d2ae8(0x10);
        if (iVar1 != 0) {
          FUN_021c7eec(2);
        }
      }
      else {
        if (*DAT_021c9440 != 0) {
          FUN_021cdc10(0x13);
          uVar2 = FUN_021d3544(0,DAT_021c944c,0,0x78);
          *(undefined4 *)(*DAT_021c9430 + 0x38) = uVar2;
          return;
        }
        if (*(char *)(*DAT_021c9430 + 0x47) == '\0') {
          FUN_021cdc10(9);
          *(undefined1 *)(*DAT_021c9430 + 0x47) = 1;
          return;
        }
      }
    }
    else {
      if (*DAT_021c9440 != 0x91) {
        FUN_021cdc10(0x13);
        uVar2 = FUN_021d3544(0,DAT_021c9444,0,0x78);
        *(undefined4 *)(*DAT_021c9430 + 0x38) = uVar2;
        return;
      }
      if (*(char *)(*DAT_021c9430 + 0x47) == '\0') {
        FUN_021cdc10(9);
        *(undefined1 *)(*DAT_021c9430 + 0x47) = 1;
        return;
      }
    }
  }
  return;
}

