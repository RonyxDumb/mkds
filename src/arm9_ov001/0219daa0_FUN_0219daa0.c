/* Decompiled C draft; module arm9_ov001; ROM address 0219daa0. No matching claim. */
#include "types.h"
#include "deps/0219daa0_FUN_0219daa0.h"

void FUN_0219daa0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0219dad8;
  *(int *)(*DAT_0219dad8 + 0x14) = *(int *)(*DAT_0219dad8 + 0x14) + 1;
  iVar2 = *piVar1;
  if (9 < *(int *)(iVar2 + 0x14)) {
    *(undefined4 *)(iVar2 + 4) = 5;
    *(undefined4 *)(*piVar1 + 0x14) = 0;
    func_0x021282c8();
    return;
  }
  if (4 < *(int *)(iVar2 + 0x14)) {
    *(undefined4 *)(iVar2 + 0x24) = 1;
  }
  return;
}

