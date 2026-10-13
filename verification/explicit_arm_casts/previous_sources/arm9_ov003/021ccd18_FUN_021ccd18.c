/* Decompiled C draft; module arm9_ov003; ROM address 021ccd18. No matching claim. */
#include "types.h"
#include "deps/021ccd18_FUN_021ccd18.h"

void FUN_021ccd18(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_021cce34;
  *(undefined1 *)(*DAT_021cce34 + 0x1d) = 0;
  switch(*(undefined1 *)(*piVar1 + 0x1c)) {
  case 0:
    if (*(char *)(*piVar1 + 0x1e) == '\0') {
      uVar2 = FUN_021ccb50();
      switch(uVar2) {
      case 1:
        if (*(char *)(*DAT_021cce34 + 0x1b) != '\0') {
          FUN_021cdc10(0x16);
          FUN_021cdbfc(0);
          piVar1 = DAT_021cce34;
          *(undefined1 *)(*DAT_021cce34 + 0x1d) = 1;
          FUN_021d2940(*piVar1 + 0x14);
          piVar1 = DAT_021cce34;
          *(undefined1 *)(*DAT_021cce34 + 0x18) = *(undefined1 *)(*DAT_021cce34 + 0x1a);
          *(undefined1 *)(*piVar1 + 0x1c) = 1;
          return;
        }
        break;
      case 2:
        FUN_021ccc08(2);
        return;
      case 3:
        FUN_021ccc08(3);
        return;
      case 4:
        FUN_021ccbbc();
        return;
      }
    }
    break;
  case 1:
    FUN_021ccc90();
    return;
  case 2:
    iVar3 = FUN_021ccb1c(2);
    piVar1 = DAT_021cce34;
    if (iVar3 != 2) {
      *(undefined1 *)(*DAT_021cce34 + 0x1d) = 5;
      *(undefined1 *)(*piVar1 + 0x1c) = 0;
      return;
    }
    iVar3 = FUN_021ccb50();
    if (iVar3 == 2) {
      FUN_021ccc08(2);
      return;
    }
    break;
  case 3:
    iVar3 = FUN_021ccb1c(3);
    piVar1 = DAT_021cce34;
    if (iVar3 != 3) {
      *(undefined1 *)(*DAT_021cce34 + 0x1d) = 7;
      *(undefined1 *)(*piVar1 + 0x1c) = 0;
      return;
    }
    iVar3 = FUN_021ccb50();
    if (iVar3 == 3) {
      FUN_021ccc08(3);
    }
  }
  return;
}

