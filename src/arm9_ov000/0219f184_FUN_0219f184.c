/* Decompiled C draft; module arm9_ov000; ROM address 0219f184. No matching claim. */
#include "types.h"
#include "deps/0219f184_FUN_0219f184.h"

undefined4 FUN_0219f184(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_0219f204;
  *(undefined1 *)(*DAT_0219f204 + 0x17) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined1 *)(*piVar1 + DAT_0219f208) = 0;
  iVar4 = DAT_0219f20c;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + DAT_0219f20c) == 0) {
    FUN_0219f23c(1);
  }
  else if (*(char *)(iVar2 + 0x15) == '\0') {
    *(undefined4 *)(iVar2 + DAT_0219f210) = 3;
    uVar3 = FUN_021a0f20(0);
    iVar4 = FUN_0219e594();
    if (iVar4 != 0) {
      return uVar3;
    }
  }
  else if (*(char *)(iVar2 + 0x15) == '\x01') {
    *(undefined4 *)(iVar2 + DAT_0219f210) = 4;
    uVar3 = FUN_0219fdc8(*(undefined4 *)(*piVar1 + iVar4));
    iVar4 = FUN_0219fee4();
    if (iVar4 != 0) {
      return uVar3;
    }
  }
  return 0;
}

