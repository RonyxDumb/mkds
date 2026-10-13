/* Decompiled C draft; module arm9_ov000; ROM address 0219fb48. No matching claim. */
#include "types.h"
#include "deps/0219fb48_FUN_0219fb48.h"

undefined4 FUN_0219fb48(void)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  piVar1 = DAT_0219fbcc;
  *(undefined4 *)(*DAT_0219fbcc + DAT_0219fbd0) = 0;
  *(undefined4 *)(*piVar1 + DAT_0219fbd4) = 0;
  *(undefined1 *)(*piVar1 + DAT_0219fbd8) = 0;
  iVar2 = *piVar1;
  uVar3 = func_0x0200f5ac();
  *(int *)(iVar2 + DAT_0219fbdc) = (int)uVar3;
  *(int *)(iVar2 + DAT_0219fbe0) = (int)((ulonglong)uVar3 >> 0x20);
  if (*(char *)(iVar2 + 0x15) == '\0') {
    *(undefined4 *)(iVar2 + DAT_0219fbe4) = 3;
    FUN_021a0f20(0);
    iVar2 = FUN_0219e594();
    if (iVar2 != 0) {
      return 0;
    }
  }
  else if (*(char *)(iVar2 + 0x15) == '\x01') {
    FUN_0219fbec(0,0);
    iVar2 = FUN_0219fee4();
    if (iVar2 != 0) {
      return 0;
    }
  }
  else if (*(char *)(iVar2 + 0x15) == '\x03') {
    FUN_021a1a38(6,DAT_0219fbe8);
    return 0;
  }
  return 1;
}

