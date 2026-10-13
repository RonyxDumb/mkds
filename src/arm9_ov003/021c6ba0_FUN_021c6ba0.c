/* Decompiled C draft; module arm9_ov003; ROM address 021c6ba0. No matching claim. */
#include "types.h"
#include "deps/021c6ba0_FUN_021c6ba0.h"

void FUN_021c6ba0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_021c0ce4();
  if (iVar2 < 0x84) {
    if (iVar2 < 0x80) {
      if (iVar2 == 0) goto LAB_021c6cba;
    }
    else {
      if (iVar2 == 0x80) {
        if (*(char *)(*DAT_021c6ccc + 0x29) != '\0') {
          FUN_021cdc10(3);
          piVar1 = DAT_021c6ccc;
          *(char *)(*DAT_021c6ccc + 0x29) = *(char *)(*DAT_021c6ccc + 0x29) + -1;
          iVar2 = *piVar1;
          *(undefined1 *)(iVar2 + (uint)*(byte *)(iVar2 + 0x29) + 8) = 0;
          if (*(char *)(*piVar1 + 0x29) == '\0') {
            FUN_021c0cd0();
          }
          FUN_021c0cbc(1);
        }
        goto LAB_021c6cba;
      }
      if (iVar2 == 0x82) {
        FUN_021cdc10(7);
        *(undefined1 *)(*DAT_021c6ccc + 0x2a) = 0;
        FUN_021c212c(DAT_021c6cd0);
        return;
      }
      if (iVar2 == 0x83) {
        iVar2 = FUN_021c6764();
        if (iVar2 == 0) {
          *(undefined1 *)(*DAT_021c6ccc + 0x2a) = 2;
          FUN_021cdc10(9);
        }
        else {
          FUN_021cdc10(6);
          *(undefined1 *)(*DAT_021c6ccc + 0x2a) = 1;
        }
        **(uint **)(*DAT_021c6ccc + 4) =
             **(uint **)(*DAT_021c6ccc + 4) & DAT_021c6cd4 | DAT_021c6cd8;
        FUN_021c212c(DAT_021c6cd0);
        return;
      }
    }
  }
  if (*(char *)(*DAT_021c6ccc + 0x29) != ' ') {
    FUN_021cdc10(1);
    piVar1 = DAT_021c6ccc;
    *(char *)(*DAT_021c6ccc + (uint)*(byte *)(*DAT_021c6ccc + 0x29) + 8) = (char)iVar2;
    *(char *)(*piVar1 + 0x29) = *(char *)(*piVar1 + 0x29) + '\x01';
    FUN_021c0cd0(1);
    if (*(char *)(*DAT_021c6ccc + 0x29) == ' ') {
      FUN_021c0cbc(0);
    }
  }
LAB_021c6cba:
  FUN_021c696c();
  FUN_021c6914();
  return;
}

