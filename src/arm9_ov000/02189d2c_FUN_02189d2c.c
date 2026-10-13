/* Decompiled C draft; module arm9_ov000; ROM address 02189d2c. No matching claim. */
#include "types.h"
#include "deps/02189d2c_FUN_02189d2c.h"

void FUN_02189d2c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = FUN_02188584(0x10);
  if (param_1 == 3) {
    uVar3 = func_0x0200f5ac();
    *(int *)(iVar1 + DAT_02189dd0) = (int)uVar3;
    *(int *)(iVar1 + DAT_02189dd4) = (int)((ulonglong)uVar3 >> 0x20);
    FUN_02189868(DAT_02189dd8,DAT_02189ddc,(int)*(char *)(iVar1 + DAT_02189de0),DAT_02189de4);
    return;
  }
  if (param_1 != 4) {
    if (param_1 != 5) {
      return;
    }
    uVar3 = func_0x0200f5ac();
    *(int *)(iVar1 + DAT_02189dd0) = (int)uVar3;
    *(int *)(iVar1 + DAT_02189dd4) = (int)((ulonglong)uVar3 >> 0x20);
    FUN_02189868(DAT_02189dd8,iVar1 + DAT_02189dec + (uint)*(byte *)(iVar1 + DAT_02189de8) * 0x24,
                 (int)*(char *)(iVar1 + DAT_02189de0),DAT_02189df4);
    return;
  }
  uVar3 = func_0x0200f5ac();
  *(int *)(iVar1 + DAT_02189dd0) = (int)uVar3;
  *(int *)(iVar1 + DAT_02189dd4) = (int)((ulonglong)uVar3 >> 0x20);
  iVar2 = (uint)*(byte *)(iVar1 + DAT_02189de8) * 0x24;
  FUN_02189868(DAT_02189dd8,iVar1 + DAT_02189dec + iVar2,
               *(undefined1 *)(iVar1 + iVar2 + DAT_02189df0),DAT_02189df4);
  return;
}

