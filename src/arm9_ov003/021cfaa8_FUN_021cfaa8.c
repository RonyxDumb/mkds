/* Decompiled C draft; module arm9_ov003; ROM address 021cfaa8. No matching claim. */
#include "types.h"
#include "deps/021cfaa8_FUN_021cfaa8.h"

void FUN_021cfaa8(void)

{
  int iVar1;
  
  if (*(int *)(*DAT_021cfb6c + 0x40) == 1) {
    if ((code *)*DAT_021cfb70 != (code *)0x0) {
      (*(code *)*DAT_021cfb70)(DAT_021cfb74,DAT_021cfb78);
      return;
    }
  }
  else {
    if ((code *)*DAT_021cfb70 != (code *)0x0) {
      (*(code *)*DAT_021cfb70)(DAT_021cfb74,DAT_021cfb7c);
    }
    iVar1 = *(int *)(*DAT_021cfb6c + 0x40);
    if (((iVar1 != 6) && (iVar1 != 5)) && (iVar1 != 4)) {
      FUN_021d07b0(3);
      FUN_021cfb80();
      return;
    }
    FUN_021d07b0(3);
    switch(*(undefined4 *)(*DAT_021cfb6c + 0x44)) {
    case 0:
    case 4:
      iVar1 = FUN_021d032c();
      if (iVar1 == 0) {
        FUN_021cfb80();
      }
      break;
    case 1:
    case 5:
      iVar1 = FUN_021d022c();
      if (iVar1 == 0) {
        FUN_021cfb80();
        return;
      }
      break;
    case 2:
      iVar1 = FUN_021d0358();
      if (iVar1 == 0) {
        FUN_021cfb80();
        return;
      }
      break;
    case 3:
      iVar1 = FUN_021d0258();
      if (iVar1 == 0) {
        FUN_021cfb80();
        return;
      }
    }
  }
  return;
}

