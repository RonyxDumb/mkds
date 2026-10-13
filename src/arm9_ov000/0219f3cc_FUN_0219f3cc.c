/* Decompiled C draft; module arm9_ov000; ROM address 0219f3cc. No matching claim. */
#include "types.h"
#include "deps/0219f3cc_FUN_0219f3cc.h"

void FUN_0219f3cc(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_0219f4ac;
  *(undefined4 *)(*DAT_0219f4ac + DAT_0219f4b0) = 0;
  iVar2 = DAT_0219f4b8;
  iVar4 = DAT_0219f4b4;
  if (*(int *)(*piVar1 + DAT_0219f4b4) == 2) {
    FUN_0219f344();
    return;
  }
  *(undefined1 *)(*piVar1 + DAT_0219f4b8) = 1;
  iVar3 = *piVar1;
  if (*(char *)(iVar3 + 0x15) == '\x03') {
    *(undefined1 *)(iVar3 + iVar2) = 1;
    iVar4 = *piVar1;
    if (*(char *)(iVar4 + 0xd) == '\0') {
      FUN_0219fb14(*(undefined4 *)(iVar4 + 0xf4));
      iVar4 = FUN_0219fee4();
      if (iVar4 != 0) {
        return;
      }
    }
    else {
      FUN_021988e8(**(undefined4 **)(iVar4 + 4));
    }
    FUN_0219f344();
    return;
  }
  iVar4 = *(int *)(iVar3 + iVar4);
  if ((((iVar4 == 4) || (iVar4 == 5)) || (iVar4 == 6)) || ((iVar4 == 7 || (iVar4 - 0xbU < 2)))) {
    if (*(int *)(iVar3 + DAT_0219f4bc) != 0) {
      FUN_0219fb14(*(undefined4 *)(iVar3 + 0xf4));
      iVar4 = FUN_0219fee4();
      if (iVar4 != 0) {
        return;
      }
    }
    FUN_0219f2e4();
    iVar4 = FUN_0219fee4();
    if (iVar4 != 0) {
      return;
    }
  }
  if (*(int *)(*DAT_0219f4ac + DAT_0219f4c0) != 0) {
    FUN_0219ac50();
    *(undefined4 *)(*DAT_0219f4ac + DAT_0219f4c0) = 0;
  }
  piVar1 = DAT_0219f4ac;
  if (*(char *)(*DAT_0219f4ac + 0xd) != '\0') {
    *(undefined1 *)(*DAT_0219f4ac + DAT_0219f4b8) = 1;
    FUN_021988e8(**(undefined4 **)(*piVar1 + 4));
  }
  FUN_0219f344();
  return;
}

