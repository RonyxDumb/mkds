/* Decompiled C draft; module arm9_ov003; ROM address 021d0c84. No matching claim. */
#include "types.h"
#include "deps/021d0c84_FUN_021d0c84.h"

void FUN_021d0c84(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_021cf360();
  switch(uVar1) {
  case 0:
    iVar2 = FUN_021d010c();
    if (iVar2 == 0) {
      *(undefined1 *)(*DAT_021d0dc8 + DAT_021d0dd4) = 0x1f;
      return;
    }
    if (iVar2 == 1) {
      FUN_021cfa68();
      return;
    }
    if (iVar2 != 3) {
      *(undefined1 *)(*DAT_021d0dc8 + DAT_021d0dd4) = 0x1f;
    }
    break;
  case 1:
    FUN_021cf93c(*DAT_021d0dc8 + DAT_021d0dcc,*(undefined2 *)(*DAT_021d0dc8 + DAT_021d0dd0));
    return;
  case 2:
    iVar2 = FUN_021cf32c(2);
    if (iVar2 != 0) {
      *(undefined1 *)(*DAT_021d0dc8 + DAT_021d0dd4) = 5;
      return;
    }
    iVar2 = FUN_021cf32c(3);
    if ((iVar2 != 0) || (iVar2 = FUN_021cf32c(4), iVar2 != 0)) {
      *(undefined1 *)(*DAT_021d0dc8 + DAT_021d0dd4) = 6;
      return;
    }
    if ((*(char *)(*DAT_021d0dc8 + DAT_021d0dd4) == '\x05') && (iVar2 = FUN_021cf32c(2), iVar2 == 0)
       ) {
      *(undefined1 *)(*DAT_021d0dc8 + DAT_021d0dd4) = 0xd;
      return;
    }
    break;
  case 3:
    iVar2 = FUN_021cf64c();
    if (iVar2 != 0) {
      FUN_021cf5ac();
      return;
    }
    if (((byte)(*(char *)(*DAT_021d0dc8 + DAT_021d0dd4) - 6U) < 2) &&
       (iVar2 = FUN_021cf32c(3), iVar2 == 0)) {
      *(undefined1 *)(*DAT_021d0dc8 + DAT_021d0dd4) = 0x12;
      return;
    }
    break;
  case 5:
    *(undefined1 *)(*DAT_021d0dc8 + DAT_021d0dd4) = 7;
    return;
  case 7:
    FUN_021cf598();
    *(undefined1 *)(*DAT_021d0dc8 + DAT_021d0dd4) = 1;
    return;
  }
  return;
}

